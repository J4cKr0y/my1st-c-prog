# Le Debug

Vous trouverez dans le dossier hello-debug un petit programme en langage C. 
Le code source est composé de : 
- main.c : le point de départ, appelant une fonction collectName
- io.c : fonctions d'entrée, collectName et collectFirstName, qui appelle storeInfo
- logic.c : traitement des données, storeInfo et mergeWelcomeMessage qui appelle valitateMessage
- validation.c qui contient validateMessage
- des différents fichiers .h et le makeFile

Je vous invite à lancer l'executable hello-debug pour voir son fonctionnement. 
Si vous regardez le code, vous verrez comment une fonction en appelle une autre qui en appelle... etc.

Il y a ensuite le dossier buggy-version avec exactement les même fichiers... Ou presque! Quelques surprises nous attendent. Venez avec moi :)


## Étape 1 : Compiler avec debug activé (capture 1)
On lance:
```
make
```
qui exécute en coulisses :
```
gcc -g -Wall main.c io.c logic.c validation.c -o hello-debug
```
-g : ajoute les symboles de debug 
-Wall : active tous les warnings utiles pour voir les problèmes potentiels avant même de déboguer

Résultat : un exécutable nommé hello-debug, prêt à être examiné ligne par ligne

Ce que nous dit la console : 
```
main.c: In function ‘main’:
main.c:4:5: warning: implicit declaration of function ‘collectName’ [-Wimplicit-function-declaration]
    4 |     collectName();
      |     ^~~~~~~~~~~
io.c: In function ‘collectFirstName’:
io.c:14:5: warning: ‘firstname’ is used uninitialized [-Wuninitialized]
   14 |     scanf("%49s", firstname);
      |     ^~~~~~~~~~~~~~~~~~~~~~~~
logic.c: In function ‘mergeWelcomeMessage’:
logic.c:12:39: warning: ‘, bienvenue !’ directive writing 13 bytes into a region of size 3 [-Wformat-overflow=]
   12 |     sprintf(message, "Bonjour %s %s, bienvenue !", firstname, name);
      |                                    ~~~^~~~~~~~~~
logic.c:12:5: note: ‘sprintf’ output 23 or more bytes into a destination of size 12
   12 |     sprintf(message, "Bonjour %s %s, bienvenue !", firstname, name);
      |     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
```

## Étape 2 : Lire les warnings comme des indices
Le compilateur donne plusieurs signaux d'alerte, qui ne bloquent pas la compilation mais méritent notre attention :

### /!\ implicit declaration of function 'collectName'

Cela signifie que main.c appelle collectName() sans l'avoir déclarée ni incluse via un header (.h)

C'est une erreur qui peut entraîner des crashs ou des incohérences

Solution : ajouter #include "io.h" dans main.c

### /!\ 'firstname' is used uninitialized
On utilise firstname dans scanf sans l'avoir initialisé ni alloué : donc le programme écrit dans une zone non définie en mémoire

C'est un bug mémoire subtil, mais très traçable avec GDB :
- On met un breakpoint sur collectFirstName
- On inspecte firstname avec print
- Et on voit qu'il n'a pas d'adresse valide

### (_)-~* sprintf writing into a region of size 3
Là, c'est un classique : on a déclaré char message[12]; mais on essaie d'y écrire une phrase de 23 caractères ou plus ->
boum!
Ce warning indique un dépassement de tampon (buffer overflow) : c'est un bug mémoire dangereux.

Avec gdb, on peut :
- Voir le contenu de message
- Observer le plantage ou les effets secondaires invisibles
- Confirmer que la corruption vient de cette ligne

## Étape 3 : On lance gdb ! (capture 2)
```
gdb ./hello-debug
```
Là, y a un gros pavé de bla bla licence puis : 
```
Reading symbols from ./hello-debug...
(gdb) 
```
Là, on va mettre un breakpoint sur collectFirstName : 
```
(gdb) break collectFirstName
```
et ça affiche : 
```
Breakpoint 1 at 0x123f: file io.c, line 13.
```
Ok, on l'a posé. On lance le programme avec run pour voir ce qui ce passe à ce point précis, ça donne : 
```
(gdb) run
Starting program (...)
Entrez votre nom : Royer
Breakpoint 1, collectFirstName (name=0x7fffffffe570 "Royer") at io.c:13
13		printf("Entrez votre prénom : ");
```

Ok, c'est ici que se trouve le problème. Alors on inspecte le pointeur firstname : 
```
(gdb) print firstname
```
et bim! Le résultat : 
```
$1 = 0x1 <error: Cannot access memory at adress 0x1>
```
Et si on continue le programme avec la commande :
```
(gdb) next
```
On exécute la ligne printf(...) et reste dans collectFirstName.
- On enchaine avec step (concept de step in) : pour entrer dans la prochaine fonction appelée (scanf)
- finish (step out): pour exécuter toute la fonction actuelle et revenir à l'appelant
on obtient alors le bug en lui-même : 
```
Program received signal SIGSEGV, Segmentation fault.
```
Cela signifie que le programme a tenté d'accéder à une zone de mémoire qu'il n'avait pas le droit d'utiliser ou d'écrire.
Le plantage se produit précisément quand scanf essaie d'écrire le prénom "Jacky" dans la variable firstname. 
Cela confirme notre diagnostic précédent sur l'avertissement [-Wuninitialized] pour firstname dans io.c. 
Puisque firstname est un pointeur non initialisé, il pointe vers une adresse mémoire invalide. 
scanf tente d'y écrire, et le système d'exploitation arrête le programme pour violation d'accès mémoire.
Ce qu'il faut faire : Corriger la déclaration et l'initialisation de firstname dans collectFirstName.

## Étape 4 : On regarde la trace de la pile (backtrace) avec la commande bt (capture 3)
```
 #0 elf_machine_fixup_plt...
 #1 _dl_fixup...
 #2 _dl_runtime_resolve_xsave...
 #3 0x00005555555552db in mergeWelcomeMessage (name=0x7fffffffde70 "ROYER", firstname=0x7fffffff2e0 "Jacky") at logic.c:10
 #4 0x0000555555555228 in storeInfo (name=0x7fffffffde70 "ROYER", firstname=0x7fffffff2e0 "Jacky") at logic.c:6
 #5 0x0000555555555282 in collectFirstName (name=0x7fffffffde70 "ROYER") at io.c:15
 #6 0x00005555555551b1 in collectName () at io.c:9
 #7 0x0000555555555107 in main () at main.c:4
```
La pile d'appels nous montre le chemin que le programme a emprunté jusqu'au plantage.
L'erreur initiale (SIGSEGV) s'est produite "bas dans la pile" (frames #0, #1, #2), 
souvent lié à des chargements de librairies dynamiques ou la gestion de la mémoire.
Cependant, le contexte intéressant commence à la frame #3 : 
mergeWelcomeMessage (appelé depuis logic.c:10).
- Cette fonction a été appelée par storeInfo (depuis logic.c:6).
- storeInfo a été appelée par collectFirstName (depuis io.c:15).
- collectFirstName a été appelée par collectName (depuis io.c:9).
- Et enfin, collectName a été appelée par main (depuis main.c:4).

Conclusion : 
Le plantage initial est bien lié à l'écriture dans firstname dans collectFirstName, car collectFirstName est bien dans la trace de pile.
Le fait que mergeWelcomeMessage apparaisse dans la trace à logic.c:10 et qu'il y ait eu un SIGSEGV qui a interrompu son exécution 
suggère fortement que le débordement de tampon dans sprintf (l'avertissement [-Wformat-overflow=]) est la deuxième cause majeure de problème, 
voire la cause directe de cette SIGSEGV particulière (même si l'initialisation de firstname est la première chose à corriger). 
Une fois que sprintf écrit au-delà de la mémoire allouée pour message, il corrompt la pile, et cela peut entraîner un SIGSEGV plus tard, 
ou même la corruption des arguments des fonctions appelantes ou l'adresse de retour.

Ce qu'il faut faire : 
1/ Corriger l'initialisation de firstname dans collectFirstName 
2/ Corriger le débordement de tampon dans mergeWelcomeMessage en augmentant la taille de message.

## Conclusion :  
La compilation avec -g donne une carte détaillée du programme pour que GDB puisse nous guider dans ses entrailles. 
Les warnings sont comme des panneaux "attention danger", et chaque message aide à prévenir ou traquer un bug mémoire, un pointeur sauvage ou une variable mal utilisée.

GDB permet de suspendre le temps au moment où le programme va faire une bêtise, et de vérifier si une variable est prête à recevoir des données. 
Si elle est vide ou corrompue, on le voit avant que ça explose.
Grâce au debug :
- On peut suivre le programme étape par étape (next, step, finish)
- voir les valeurs des variables (print)
- afficher la pile d'appel (backtrace)
- confirmer qu'un pointeur est null, invalide, ou non initialisé
- identifier précisément quelle ligne provoque l'erreur

Y'a plus qu'à corriger tout ça, et vérifier si ça fonctionne ;)
