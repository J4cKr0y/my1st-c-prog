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
