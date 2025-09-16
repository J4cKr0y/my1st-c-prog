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
