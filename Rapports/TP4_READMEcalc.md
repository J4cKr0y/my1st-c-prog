# Rapport sur la compilation d'un projet en langage C

## Structure du projet

### fonctions.h (fichier d'en-tête)
Le fichier `fonctions.h` est un **fichier d'en-tête** (header file) qui contient les **déclarations** des fonctions. Il ne définit pas le code des fonctions, mais indique au compilateur :
- Le nom des fonctions disponibles
- Les types de paramètres qu'elles acceptent
- Le type de valeur qu'elles retournent

C'est une interface qui permet au compilateur de vérifier que les appels de fonctions sont corrects lors de la compilation, même si la définition complète de ces fonctions se trouve dans un autre fichier.

### fonctions.c (implémentation)
Ce fichier contient les **définitions** complètes des fonctions déclarées dans `fonctions.h`. C'est ici que se trouve la logique métier, le code qui sera réellement exécuté.

### main.c (programme principal)
Contient la fonction `main()` qui est le point d'entrée du programme. Il gère les interactions avec l'utilisateur et appelle les fonctions définies dans `fonctions.c`.

## Le préprocesseur

Le **préprocesseur** est la première étape de la compilation. Il traite les directives qui commencent par `#` avant que le code ne soit compilé :

- `#include` : inclut le contenu d'autres fichiers
- `#define` : définit des macros
- `#ifndef`, `#endif` : directives de compilation conditionnelle

### Les guards d'inclusion (#ifndef)

Dans `fonctions.h`, on trouve :
```c
#ifndef FONCTIONS_H
#define FONCTIONS_H
// ... contenu du fichier
#endif
```

Ces **guards d'inclusion** (include guards) évitent l'inclusion multiple du même fichier d'en-tête. Si `FONCTIONS_H` n'est pas encore défini (`#ifndef` = "if not defined"), alors on le définit et on inclut le contenu. 
Si le fichier est inclus une seconde fois, `FONCTIONS_H` est déjà défini, donc le contenu est ignoré. Cela évite les erreurs de redéfinition.

## Compilation avec GCC

### Commande de base
```bash
gcc main.c fonctions.c -o calc -lm
```

- `gcc` : le compilateur GNU pour C
- `main.c fonctions.c` : les fichiers source à compiler
- `-o calc` : nomme l'exécutable "calc" (sinon "a.out" par défaut)
- `-lm` : lie la bibliothèque mathématique (nécessaire pour `powl`, `sqrtl`)

### Options utiles

#### Compilation séparée
- `-c` : compile sans lier, produit des fichiers objets `.o`
```bash
gcc -c main.c      # produit main.o
gcc -c fonctions.c # produit fonctions.o
gcc main.o fonctions.o -o calc -lm  # lie les objets
```

#### Analyse et débogage
- `-E` : arrête après le préprocesseur, affiche le code préprocessé
- `-M` : affiche les dépendances
- `-v` : mode verbeux, montre toutes les étapes
- `-ftime-report` : temps de compilation par étape

#### Détection d'erreurs
- `-fsanitize=address -g` : détecte les erreurs mémoire (overflow, underflow)
- `-fsanitize=undefined -g` : détecte les comportements indéfinis (division par 0, etc…)
- `-fsanitize=leak -g` : détecte les fuites mémoire (écraser un pointeur)

## Étapes de compilation (avec -v)

1. **Préprocesseur** : traite les `#include`, `#define`, etc.
2. **Compilation** : `cc1` transforme le C en assembleur (.s)
3. **Assemblage** : `as` transforme l'assembleur en code machine (.o) 
4. **Édition de liens** : `collect2` lie les fichiers objets et bibliothèques
5. **Exécutable** : produit le fichier final

GCC est un **chef d'orchestre** qui coordonne ces outils spécialisés.

## Compilation avec Make

Make est un outil qui automatise la compilation en définissant des règles et des dépendances dans un fichier `Makefile` :

```makefile
# Variables
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g -v
LDFLAGS = -lm

# Règle par défaut
all: calc

# Règle pour l'exécutable
calc: main.o fonctions.o
	$(CC) main.o fonctions.o -o calc $(LDFLAGS)

# Règles pour les fichiers objets
main.o: main.c fonctions.h
	$(CC) $(CFLAGS) -c main.c

fonctions.o: fonctions.c fonctions.h
	$(CC) $(CFLAGS) -c fonctions.c

# Nettoyage
clean:
	rm -f *.o calc

.PHONY: all clean
```

### Explication des options de compilation

#### -Wall (Warning all)
Active **la plupart** des avertissements courants du compilateur pour détecter les erreurs potentielles :
- Variables déclarées mais non utilisées
- Fonctions appelées sans déclaration préalable
- Comparaisons entre types différents
- Code mort (après un `return`)

**Note :** Malgré son nom "all", `-Wall` n'active pas TOUS les avertissements possibles.

#### -Wextra (Warning extra)
Active des avertissements **supplémentaires** non inclus dans `-Wall` :
- Paramètres de fonction non utilisés
- Comparaisons entre signés et non-signés
- Initialisation manquante de variables
- Ordre suspect dans les expressions

#### -std=c99 (Standard C99)
Force le compilateur à respecter exactement la **norme C99** (1999) :
- Garantit la **portabilité** du code vers d'autres compilateurs
- Sans cette option, GCC utilise des extensions GNU non-standard
- C99 a introduit : variables déclarables partout, commentaires `//`, type `long long`, etc.

### -g (Debug information)
Demande au compilateur d'inclure des informations de débogage dans l'exécutable.
ce peut être les noms des variables originales, les numéros de lignes, les noms des fonctions, etc.
Ça permet d'utiliser un débogueur comme gdb.
Ça n'a aucun impact sur les performances d'exécution, mais l'exécutable est plus volumineux, 
donc on retire généralement -g pour les versions finales.

### -v (Verbose)
Active le mode verbeux qui affiche toutes les étapes internes de compilation.
Je l'ai utilisé à des fins pédagogiques pour comprendre les étapes d'une compilation. 
En entreprise, ça peut aussi être utilisé ponctuellement quand la compilation bug.

### Explication de .PHONY
En temps normal, Make fonctionne avec des **fichiers réels** :
```makefile
calc: main.o fonctions.o    # "calc" est un fichier à créer
```

Mais `all` et `clean` ne sont **pas des fichiers** à créer, ce sont des **actions** :
- `all` : "compile tout le projet"
- `clean` : "supprime les fichiers temporaires"

Donc si un fichier nommé `clean` existe dans le répertoire, Make verrait que le fichier `clean` existe et dirait : 
"pas besoin de reconstruire clean, il est à jour" → **la commande ne s'exécute pas !**
La ligne `.PHONY: all clean` indique donc à Make que `all` et `clean` sont des **cibles factices** 
qui doivent **toujours être exécutées**, même s'il existe des fichiers avec ces noms.

### Avantages de Make :
- **Compilation incrémentale** : ne recompile que les fichiers modifiés
- **Gestion des dépendances** : si `fonctions.h` change, recompile automatiquement `main.o` et `fonctions.o`
- **Automatisation** : une seule commande `make` suffit
- **Optimisation** : évite les recompilations inutiles


## Autres compilateurs C/C++

### Pour C et C++ :
- **Clang** : compilateur moderne avec d'excellents messages d'erreur
- **Intel C++ Compiler (icc/icx)** : optimisé pour processeurs Intel
- **PGI/NVIDIA HPC Compiler** : pour la programmation d'applications qui utilisent les GPU.

### Spécifiques Windows :
- **Microsoft Visual C++ (MSVC)** : compilateur intégré à Visual Studio
- **MinGW** : port de GCC pour Windows
- **TinyCC (tcc)** : compilateur très rapide et léger

### Compilateurs embarqués :
- **ARM GCC** : pour processeurs ARM
- **AVR-GCC** : pour microcontrôleurs AVR (Arduino)

Chaque compilateur a ses spécificités en termes d'optimisation, de support de standards C/C++, et de plateformes cibles.

## Conclusion
De la même manière que l'apprentissage du modèle OSI nous a permis de mieux comprendre la structure menant de la machine au site web, 
l'étude de la compilation nous à permis de découvrir comment on passe d'un langage informatique, pour repasser au langage machine, afin d'obtenir un exécutable. 
C'est essentiel pour comprendre où on se situe, et vers où chercher en cas de bug. 
Que ce soit en mettant les options -g -v au compilateur, ou en branchant un câble éthernet au lieu d'utiliser le wifi :)

### Remerciement
Merci à M. Aymard Djasrabe de m'avoir poussé à rédiger ce rapport, et m'avoir aiguillé pour l'améliorer/le compléter.

---

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

---

# Rapport d'expérience : De la calculatrice monolithique aux bibliothèques réutilisables

## 1. Objectif de l'expérience
L'objectif principal de cette expérience était de transformer une simple calculatrice en C en une application modulaire. 
Nous avions la logique de calcul intégrée directement dans le projet (dans des fichiers functions.c et functions.h liés à main.c). 
Nous avons extrait ces fonctionnalités pour les organiser en deux bibliothèques distinctes : une bibliothèque statique (.a) et une bibliothèque dynamique (.so). 
L'application principale (main.c) a ensuite été modifiée pour utiliser les fonctions de ces deux bibliothèques et comparer leurs résultats.

## 2. Architecture du projet
Pour atteindre cet objectif, nous avons mis en place une structure de répertoires claire et standardisée :
```
- nomprojet/
  - Makefile               (Automatisation de la compilation)
  - src/
    - app/
      - main.c              (L'application cliente)
    - lib/
      - dynamicCalc/
        - dynamic_calc.h      (En-tête de la lib dynamique)
        - dynamic_calc.c      (Source de la lib dynamique)
      - staticCalc/
        - static_calc.h       (En-tête de la lib statique)
        - static_calc.c       (Source de la lib statique)
  - bin/                    (Contient l'exécutable et la lib dynamique)
  - build/                  (Contient la lib statique et les fichiers objets)
```
Cette architecture permet de séparer le code de l'application cliente du code des bibliothèques, améliorant la clarté et la maintenabilité du projet.

## 3. Étapes de construction du projet
Le processus de construction a été réalisé en trois étapes principales, utilisant le compilateur gcc :

Compilation de la bibliothèque statique (.a) :
```
gcc -c src/lib/staticCalc/static_calc.c -o build/static_calc.o
```
Le fichier static_calc.c a été compilé en un fichier objet (.o).
```
ar rcs build/libstaticCalc.a build/static_calc.o
```
Ce fichier objet a été archivé à l'aide de la commande ar pour créer la bibliothèque libstaticCalc.a.

Compilation de la bibliothèque dynamique (.so) :
```
gcc -c -fPIC src/lib/dynamicCalc/dynamic_calc.c -o build/dynamic_calc.o
```
Le fichier dynamic_calc.c a été compilé en un fichier objet en utilisant l'option -fPIC (Position-Independent Code). 
Cela est essentiel pour permettre au système de charger la bibliothèque à n'importe quelle adresse en mémoire.
```
gcc -shared -o bin/libdynamicCalc.so build/dynamic_calc.o
```
Le fichier objet a ensuite été lié avec l'option -shared pour créer le fichier libdynamicCalc.so.

Compilation et liaison de l'application principale :
- -o: nom de l'exécutable final
- -I: chemins pour trouver les en-têtes (.h)
- -L: chemins pour trouver les bibliothèques (.a et .so)
- -l: nom des bibliothèques à lier (sans 'lib' et l'extension)
- -lm: lie la bibliothèque mathématique
```
gcc -o bin/lib_calc-c src/app/main.c \
    -I src/lib/staticCalc -I src/lib/dynamicCalc \
    -L build -lstaticCalc \
    -L bin -ldynamicCalc \
    -lm
```

## 4. Construction du projet avec Makefile
Au lieu de compiler manuellement chaque fichier avec gcc, nous avons mis en place un Makefile pour automatiser l’ensemble du processus. 
Ce fichier décrit les règles de compilation, les dépendances entre fichiers, et les commandes à exécuter.
 ### Étapes automatisées par le Makefile :
 - Compilation de la bibliothèque statique
 ```
gcc -Wall -O2 -c src/lib/staticCalc/static_calc.c -o build/static_calc.o
 ar rcs build/libstaticCalc.a build/static_calc.o
```
 Le fichier source est compilé en objet, puis archivé avec ar pour produire libstaticCalc.a.
 - Compilation de la bibliothèque dynamique
 ```
gcc -Wall -O2 -fPIC -c src/lib/dynamicCalc/dynamic_calc.c -o build/dynamic_calc.o
 gcc -shared -o bin/libdynamicCalc.so build/dynamic_calc.o
```
 L’option -fPIC permet de générer du code indépendant de la position mémoire, nécessaire pour les bibliothèques partagées. 
 L’option -shared crée le fichier .so.
 - Compilation et liaison de l’application principale
 ```
gcc -Wall -O2 -o bin/lib_calc-c build/main.o \
    -I src/lib/staticCalc -I src/lib/dynamicCalc \
    -L build -lstaticCalc \
    -L bin -ldynamicCalc \
    -lm
```
 Le fichier main.c est compilé et lié avec les deux bibliothèques. 
 Les options -I, -L, -l et -lm permettent de spécifier les chemins et les bibliothèques à inclure.
 - Gestion automatique des dépendances .h
 Une amélioration importante apportée par le Makefile est la gestion automatique des dépendances. 
 Grâce à l’option -MMD, le compilateur génère un fichier .d pour chaque .c, listant les fichiers .h inclus.
 Par exemple :
 ```
gcc -MMD -c src/app/main.c -o build/main.o
```
 Le fichier build/main.d contiendra :
 ```
build/main.o: src/app/main.c src/lib/staticCalc/static_calc.h src/lib/dynamicCalc/dynamic_calc.h
```
 Ces fichiers .d sont ensuite inclus dans le Makefile :
 ```
-include $(DEPS)
```
 Avantage : Si un fichier .h est modifié, make sait automatiquement quels fichiers .c doivent être recompilés. 
 Cela évite les recompilations inutiles et garantit que l’exécutable est toujours à jour.


## 5. Lancement et exécution du programme
Pour exécuter le programme, une étape cruciale a été nécessaire pour que l'exécutable puisse trouver la bibliothèque dynamique. 
Deux méthodes s'offraient à nous :

A/ Définir le LD_LIBRARY_PATH : C'est une variable d'environnement qui indique au système où chercher des bibliothèques dynamiques en plus des chemins standards.

B/ Déplacer le fichier .so : La méthode la plus simple pour la distribution a été de placer le fichier libdynamicCalc.so dans /usr/local/lib/ où linux irait chercher automatiquement.
On pourrait envisager un script qui automatise ça en cas de changement de la lib. Une autre possibilité aurait été de le mettre dans le même répertoire que l'exécutable.

Un petit ./ suivie du chemin vers l'exécutable et c'était bon. 

## 6. Intérêt de cette approche modulaire
Cette expérience a mis en lumière les avantages de l'utilisation des bibliothèques :
- Réutilisabilité : Les fonctions de calcul sont maintenant des composants indépendants qui peuvent être utilisés par d'autres applications sans avoir à réécrire le code.
- Modularité et Maintenance : Le code est organisé de manière plus claire. 
Les modifications apportées aux fonctions de calcul n'affectent pas le programme principal tant que l'interface (.h) reste la même.

Différence entre statique et dynamique :
- Statique : Le code de la bibliothèque est intégré directement dans l'exécutable. Cela rend le programme autonome mais plus volumineux. 
Les appels de fonctions sont un peu plus rapides, car la liaison est faite au moment de la compilation, ce qui évite les étapes de résolution d'adresse à l'exécution.
Par contre, les mises à jour de la bibliothèque nécessitent une recompilation du programme. Sur un programme complexe, c'est loin d'être anodin.

- Dynamique : Le code est chargé à l'exécution. 
Cela permet de réduire la taille des exécutables et facilite les mises à jour des bibliothèques, 
car tous les programmes qui l'utilisent bénéficient automatiquement de la nouvelle version. 
C'est le principe qui sous-tend la plupart des systèmes d'exploitation modernes.
Par contre, l'exécutable a besoin que la bibliothèque dynamique soit présente sur la machine pour pouvoir fonctionner. 
Si le fichier .so est manquant ou n'est pas à la bonne version, le programme ne démarrera pas, ce qui peut créer un problème de "DLL hell" sur d'autres systèmes.

- L’utilisation d’un Makefile apporte plusieurs bénéfices :
Automatisation : Une seule commande make suffit pour compiler tout le projet.
Modularité : Chaque composant est compilé indépendamment.
Maintenance : Les dépendances sont gérées automatiquement.
Clarté : Le processus de compilation est documenté et reproductible.

## 7. Comparaison entre bibliothèques statiques et dynamiques

|	Type de bibliothèque	|		Avantages		|		Inconvénients			|
|:-----------------------------:|:-------------------------------------:|:---------------------------------------------:|
|	Statique (.a)		|Autonome, rapide à l’exécution		|Taille plus grande, recompilation nécessaire	|
|	Dynamique (.so)		|Mise à jour facile, mémoire partagée	|Dépendance externe, risque de version manquante|

## Conclusion
L'intérêt principal des bibliothèques est donc de séparer le développement en composants réutilisables.

- Pour les projets simples ou les outils autonomes, la bibliothèque statique est souvent un bon choix car elle simplifie le déploiement.

- Pour les grands projets ou les frameworks, où de nombreux programmes partagent des fonctionnalités, 
la bibliothèque dynamique est indispensable pour la modularité, la gestion des mises à jour et l'économie de ressources.

- L’intégration d’un Makefile dans le projet a permis de professionnaliser le processus de compilation, tout en renforçant la modularité et la maintenabilité du code. 
Cette approche est particulièrement adaptée aux projets évolutifs, où les bibliothèques peuvent être réutilisées, mises à jour ou remplacées sans impacter l’ensemble du système.
