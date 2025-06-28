# Ce que j'ai compris de cet exercice : 

- fonctions.h fonctionne un peu comme le typage dans un projet typeScript, pour annoncer le type des données qu'on va utiliser. 
- fonction.c décrit à proprement parlé les fonctions qui seront utilisées, un peu comme les composants dans un projet react, c'est la logique métier. 
- main.c appelle les fonctions en adéquation avec l'interaction utilisateur, et gère l'affichage, un peu comme les parties "vue" et "controller" d'un système MVC.

Lors de la compilation, on a fait : gcc main.c fonctions.c -o calc -lm 
- gcc est l'outil qui compile le programme C. 
- On y lie le programme main avec les fonctions utilisées par ce programme. fonctions.h n'apparrait pas, c'est inutile vu qu'il est en include dans les autres fichiers. 
- "o calc" signifie qu'on nomme l'executable créé calc. Sans cette partie, il se serait appelé a.out par défaut. 
- lm est necessaire parce qu'on a utilisé la lib math.c (pour schematiser on pourrait dire que lm=link math.c, même si c'est un peu plus compliqué que ça)

Une autre option interressante est -c
Il compile independamment le main ou/et les fonctions, c'est à dire qu'il ne vérifie pas si les fonctions utilisées dans main sont définies (dans fonctions). 
Il crée des fichiers .o non-executable comprenant les include et le contenu du fichier .h, c'est tout. 
C'est une étape intermédiaire, invisible sans cette option (ou -E ou -v)

L'option -E fait la même chose, mais sans créer de fichier .o, elle affiche juste ce que donne le programme après le prepocesseur.

Du coup, lorsqu'on a des fichiers .o, il peut-être utile d'utiliser l'option -M qui permet de voir les dépendances, car si l'une change, il faut recompiler. 

Il y a aussi -ftime-report qui peut être utile pour comprendre quelle élément de son programme met le plus de temps à compiler, 

et tout un tas d'option pour trouver des erreurs comme : 
   -fsanitize=address -g → détecte les erreurs mémoire (overflow, underflow)
   -fsanitize=undefined -g → comportement non défini (division par 0, etc…)
   -fsanitize=leak -g → détection de fuites de mémoire (écraser un pointeur)

La commande gcc --help permet d'avoir la (longue) liste des options possibles.

Autre option cool : -v
Elle affiche toutes les étapes internes de compilation.

Je l'ai utilisé (voir capture), et voici les étapes : 
- Prétraitement : Il commence par gérer les includes, comme le ferait l'option -E
- Compilation : Des fichiers temporaires .c sont créés (/tmp/ccPGKxWc.s). 
En fait, c'est cc1, un compilateur bas-niveau, qui est appelé par gcc.
Il transforme les fichiers .c en assembleur .s !
- Assemblage : Ensuite seulement as est appelé pour créer les .o en machine binaire. 
- Linkage : Alors, le linker (collect2) fait les liens entre les différents fichiers .o et les lib utilisées (lib math dans notre cas).
- Executable : Enfin, il produit l'executable calc.

Pour résumé, gcc, est un chef d’orchestre qui pilote ce process : prétraitement → compilation → assemblage → linkage → exécutable.
