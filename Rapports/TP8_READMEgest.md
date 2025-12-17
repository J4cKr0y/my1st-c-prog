# GestionnaireEtudiants_cpp

## Projet
---------
Implémentation d'un **Système de Gestion d'Étudiants** simple en C++, conçu comme une démonstration didactique de la maîtrise de la **mémoire** et des **pointeurs** C/C++. La logique du programme est entièrement articulée autour de l'**allocation dynamique** de la mémoire sur le **heap (tas)** et de la **libération manuelle** des ressources. 
Le projet sert à illustrer la distinction et l'usage pratique :

* Des opérateurs d'allocation `new` (C++) et `malloc` (C) (bien que seule l'approche `new`/`delete` soit implémentée dans les sources fournies).
* Des opérateurs de désallocation `delete` (C++) et `free` (C).
* De la manipulation des **pointeurs** (`*`) et de l'**opérateur d'accès aux membres** (`->`).

---

## C'est quoi ?
---------------
`GestionnaireEtudiants_cpp` est une application console interactive permettant de gérer une collection d'enregistrements d'étudiants (matricule, âge, nom).

Le programme utilise un conteneur C++ (`std::vector`) pour stocker des **pointeurs** (`etudiant*`) vers les structures, garantissant ainsi que les données des étudiants sont gérées sur le **heap (tas)** et que le programmeur est responsable de leur cycle de vie complet.

Le projet met en évidence les concepts suivants :

* **Allocation/Libération Manuelle** : Chaque étudiant créé est alloué dynamiquement (`new`) et doit être explicitement détruit (`delete`) pour éviter les **fuites mémoire (memory leaks)**.
* **Passage par Pointeur** : Les fonctions de la "librairie" (`initialiser_etudiant`, `afficher_etudiant`, `creer_etudiant`, `detruire_etudiant`) reçoivent et manipulent la structure uniquement via son adresse mémoire.
* **Démonstration Didactique** : Le programme exécute une fonction `demonstration_pointeur_int()` pour illustrer la manipulation basique d'un pointeur sur un type primitif (`int`).

---

## Technologies Utilisées
-------------------------
* **Langage**: C++11 (tel que spécifié dans `CMakeLists.txt`).
* **Build System**: CMake 3.10+
* **Compilateurs**: GCC, Clang

![C++](https://img.shields.io/badge/C++-11-blue)
![CMake](https://img.shields.io/badge/CMake-3.10+-green)
![Compiler-GCC](https://img.shields.io/badge/Compiler-GCC-orange)

---

## Fonctionnalités Clés
-----------------------
* **Gestion Manuelle de la Mémoire** : L'allocation (`creer_etudiant` utilise `new`) et la désallocation (`detruire_etudiant` utilise `delete`) sont gérées manuellement par le programmeur.
* **Fonctionnalités CRUD (Partial)** : Ajout, listage, suppression individuelle et suppression de masse des étudiants.
* **Nettoyage Garanti** : La fonction `main` garantit la libération (`detruire_etudiant`) des objets restants dans le vecteur lors de la fermeture du programme.
* **Séparation Modulaire** : Le code est organisé en modules logiques (étudiant, gestionnaire, démonstration, utilitaires) avec des fichiers d'en-tête (`.hpp`) et d'implémentation (`.cpp`) séparés.

---

## Architecture du Projet
`/GestionnaireEtudiants_cpp`
├── `CMakeLists.txt`        # Configuration CMake et définition de la cible (Gest_app).
├── `main.cpp`              # Point d'entrée, exécute la démonstration et lance le menu interactif.
├── `src/`
│   ├── `demonstration_pointeur.cpp`    # Implémentation de la fonction de démonstration simple des pointeurs sur `int`.
│   ├── `etudiant.cpp`                  # Implémentation des fonctions de la structure `etudiant` (création/destruction/affichage, utilisant `new`/`delete`).
│   ├── `gestion_etudiants.cpp`         # Implémentation du menu et des fonctions CRUD (ajouter, lister, supprimer).
│   └── `utils_io.cpp`                  # Fonctions utilitaires comme `nettoyer_buffer` pour la gestion des entrées utilisateur.
└── `include/`
    ├── `demonstration_pointeur.hpp`    # Déclaration de la fonction de démonstration.
    ├── `etudiant.hpp`                  # Définition de la structure `etudiant` et déclarations des fonctions liées.
    ├── `gestion_etudiants.hpp`         # Déclarations des fonctions du gestionnaire (menu et fonctions CRUD).
    └── `utils_io.hpp`                  # Déclaration des fonctions utilitaires.

Cette architecture sépare clairement la définition de la structure (dans `include/`) de son implémentation (`etudiant.cpp`) et de la logique d'utilisation par l'application (`main.cpp`, `gestion_etudiants.cpp`).

---

## Par quoi commencer ?
Pour explorer le code et exécuter le programme :

### Prérequis
* Un compilateur C++11 (ou plus récent) (GCC/Clang).
* CMake 3.10 ou supérieur.

### Compilation et exécution (avec GCC/CMake)
1.  Naviguez vers le répertoire racine du projet.
2.  Créez un dossier de build pour une compilation hors-source :
    ```bash
    mkdir build
    cd build
    ```
3.  Configurez le projet (génération des Makefiles) :
    ```bash
    cmake ..
    ```
4.  Compilez le projet :
    ```bash
    make
    ```
5.  Lancez l'exécutable :
    ```bash
    ./Gest_app
    ```
*(Note: Le nom de l'exécutable est défini comme `Gest_app` dans le `CMakeLists.txt`.)*

---

## Documentation Complète
Ce projet illustre concrètement les concepts abordés dans le rapport théorique d'accompagnement.

Consulter la documentation complète sur la gestion de la mémoire, les pointeurs, les références, le stack et le heap dans le fichier : `Rapport/TP8_Pointeurs.md`

---

## Roadmap et Améliorations Prévues
[ ] Ajout d'une fonctionnalité de Modification (Update) des données d'un étudiant par matricule.

[ ] Remplacement de `std::vector<etudiant*>` par une Liste Chaînée implémentée à la main pour une gestion 100% manuelle de la mémoire.

[ ] Intégration des **pointeurs intelligents** (`std::unique_ptr` ou `std::shared_ptr`) pour montrer la différence entre la gestion manuelle et la gestion automatique des ressources C++.

---

## Contribuer
Les contributions sont les bienvenues, en particulier celles qui améliorent la robustesse du code (vérification des entrées utilisateur, gestion des erreurs d'allocation).

Pour contribuer :

1.  Forkez le projet.
2.  Créez une branche de fonctionnalité (`git checkout -b feature/amelioration-suppression-securisee`).
3.  Committez vos changements.
4.  Pushez vers votre branche.
5.  Ouvrez une Pull Request.
