# C++ …en passant par C - Partie 2 : C++

## Le C++ : Histoire et Réalités Actuelles

### Origines et Concepts Fondamentaux

Le C++ a été créé par Bjarne Stroustrup chez Bell Labs au début des années 1980. 
Initialement appelé "C with Classes" (1979), il est devenu C++ en 1983. 
L'objectif était d'étendre le langage C en y ajoutant la programmation orientée objet, tout en conservant sa performance et sa proximité avec le matériel.
Le concept central était d'offrir l'abstraction et la modularité de la POO sans sacrifier l'efficacité du C. 
Stroustrup voulait un langage permettant d'écrire des programmes complexes de manière structurée, tout en gardant un contrôle précis sur les ressources matérielles.

### Évolution Majeure

Le C++ a connu plusieurs révolutions :
- Les premières années (1985-1998) ont vu la standardisation avec C++98, introduisant la STL (Standard Template Library), les templates, et les exceptions.
- L'ère moderne a débuté avec C++11 en 2011, une refonte majeure ajoutant les lambdas, les pointeurs intelligents, le multithreading natif, et move semantics. 
- Depuis, le rythme s'est accéléré avec C++14, C++17, C++20 (modules, concepts, coroutines) et C++23, avec un cycle de release tous les trois ans.

### Utilisations Pratiques Actuelles

Le C++ reste incontournable dans plusieurs domaines :

- Jeux vidéo : moteurs comme Unreal Engine, Unity (parties natives)
- Systèmes embarqués : automobile, aéronautique, IoT
- Finance : trading haute fréquence où chaque microseconde compte
- Navigateurs web : Chrome, Firefox utilisent massivement du C++
- Systèmes d'exploitation : Windows, macOS, Linux
- Intelligence artificielle : TensorFlow, PyTorch ont des backends en C++
- Infographie et effets visuels : logiciels comme Adobe, Autodesk

### Demande en Développeurs C++ 
La demande en développeurs C++ a connu une évolution nuancée ces dernières années. 
Contrairement aux langages web, le C++ maintient une demande stable et soutenue dans des niches spécialisées.
Les tendances observées montrent que si le nombre absolu de postes C++ a légèrement décru face à l'explosion de langages comme Python ou JavaScript, 
la demande reste forte dans les secteurs nécessitant des performances maximales. 
Les postes C++ tendent aussi à offrir des rémunérations supérieures en raison de la complexité du langage et de la rareté des experts.
La transition vers C++ moderne (C++11 et au-delà) est devenue un standard industriel, et les entreprises recherchent activement des développeurs maîtrisant ces versions récentes plutôt que le "vieux" C++.
Le C++ reste donc un choix de carrière solide pour qui s'intéresse aux systèmes, à la performance, ou aux domaines techniques pointus, même s'il n'a eu pas la croissance explosive des langages d'application web ou de data science.

## C++ : Évolution, Comparaison avec C et STL

### Points Communs et Différences avec le C

#### Points Communs

- **Syntaxe de base** : Le C++ hérite de la syntaxe du C (boucles, conditions, opérateurs)
- **Compilation** : Les deux sont des langages compilés produisant du code machine natif
- **Performance** : Accès direct à la mémoire, pas de garbage collector, contrôle bas niveau
- **Compatibilité** : Le code C valide peut généralement être compilé en C++ (avec quelques exceptions)
- **Utilisation des pointeurs** : Manipulation directe de la mémoire
- **Préprocesseur** : Utilisation de `#include`, `#define`, etc.

#### Différences et Apports du C++

**Programmation Orientée Objet (POO)**
Le C++ introduit les classes, l'encapsulation, l'héritage et le polymorphisme, permettant une organisation du code bien plus structurée que la programmation procédurale du C.

**Gestion de la mémoire améliorée**
Ajout des opérateurs `new`/`delete` (plus sûrs que `malloc`/`free`), et surtout des pointeurs intelligents qui automatisent la gestion mémoire tout en évitant un garbage collector.

**Templates (Généricité)**
Possibilité de créer des fonctions et classes génériques, réutilisables pour différents types de données, impossible en C pur.

**STL (Standard Template Library)**
Une bibliothèque complète de conteneurs, algorithmes et itérateurs prêts à l'emploi, inexistante en C.

**Gestion des exceptions**
Mécanisme `try`/`catch`/`throw` pour une gestion d'erreurs plus élégante que les codes de retour du C.

**Surcharge (Overloading)**
Possibilité d'avoir plusieurs fonctions/opérateurs avec le même nom mais des signatures différentes.

**Références**
Alternative aux pointeurs, plus sûre et syntaxiquement plus claire.

**Namespaces**
Organisation du code pour éviter les conflits de noms, absent en C.

**Type safety renforcée**
Le C++ est plus strict sur les types que le C, réduisant les erreurs subtiles.

---

### Versions de C++ et Leurs Apports Majeurs

| Version | Année | Apports Majeurs |
|---------|-------|-----------------|
| **C++98** | 1998 | Premier standard ISO officiel |
| **C++03** | 2003 | Corrections de bugs du C++98 |
| **C++11** | 2011 | Révolution majeure du langage |
| **C++14** | 2014 | Améliorations et simplifications |
| **C++17** | 2017 | Nouvelles fonctionnalités pratiques |
| **C++20** | 2020 | Modernisation profonde |
| **C++23** | 2023 | Raffinements et nouvelles capacités |

#### C++98 (Premier Standard)

- **STL** : Introduction de la Standard Template Library avec conteneurs, algorithmes et itérateurs
- **Templates** : Programmation générique pour créer du code réutilisable indépendant du type
- **Exceptions** : Mécanisme `try`/`catch`/`throw` pour gérer les erreurs
- **RTTI** : Runtime Type Information permettant d'identifier les types à l'exécution
- **Namespaces** : Organisation du code en espaces de noms pour éviter les collisions
- **Opérateurs new/delete** : Allocation/désallocation mémoire type-safe
- **Casts explicites** : `static_cast`, `dynamic_cast`, `const_cast`, `reinterpret_cast`
- **bool** : Type booléen natif (au lieu de int)
- **Références** : Alternative aux pointeurs avec syntaxe plus claire

#### C++03

- **Corrections de bugs** : Résolution de problèmes et ambiguïtés du standard C++98
- **Clarifications** : Précisions sur le comportement attendu dans certains cas limites
- Pas de nouvelles fonctionnalités majeures, essentiellement une version de maintenance

#### C++11 (Révolution Moderne)

- **auto** : Déduction automatique du type d'une variable
- **Lambda expressions** : Fonctions anonymes pour des callbacks ou algorithmes inline
- **Smart pointers** : `unique_ptr`, `shared_ptr`, `weak_ptr` pour gestion mémoire automatique
- **Move semantics** : Transfert de ressources sans copie via `std::move` et rvalue references `&&`
- **nullptr** : Remplacement type-safe du pointeur NULL
- **Range-based for** : Boucle simplifiée `for (auto& x : container)`
- **constexpr** : Calculs à la compilation pour optimisation
- **Threading** : Support natif du multithreading avec `std::thread`, mutex, etc.
- **Initializer lists** : Initialisation uniforme avec `{}`
- **decltype** : Déduction du type d'une expression
- **Variadic templates** : Templates acceptant un nombre variable d'arguments
- **static_assert** : Assertions vérifiées à la compilation
- **Strongly-typed enums** : `enum class` pour éviter les collisions de noms
- **Deleted/defaulted functions** : Contrôle explicite de génération de fonctions spéciales

#### C++14

- **Generic lambdas** : Lambdas avec `auto` dans les paramètres
- **Return type deduction** : Déduction automatique du type de retour des fonctions
- **Binary literals** : Notation binaire `0b1010`
- **Digit separators** : Séparateurs dans les nombres `1'000'000`
- **std::make_unique** : Création sécurisée de `unique_ptr`
- **Variable templates** : Templates de variables (pas seulement fonctions/classes)
- **Relaxed constexpr** : Assouplissement des restrictions sur constexpr

#### C++17

- **Structured bindings** : Décomposition de tuples/pairs `auto [x, y] = point;`
- **if/switch with initializer** : `if (auto it = map.find(key); it != map.end())`
- **std::optional** : Type pour représenter une valeur potentiellement absente
- **std::variant** : Union type-safe pouvant contenir l'un de plusieurs types
- **std::any** : Conteneur type-safe pour n'importe quel type
- **std::string_view** : Vue non-propriétaire sur une chaîne, sans copie
- **Filesystem library** : Manipulation portable des fichiers et répertoires
- **Parallel algorithms** : Versions parallèles des algorithmes STL
- **fold expressions** : Simplification des opérations sur variadic templates
- **constexpr if** : Branchements conditionnels à la compilation
- **inline variables** : Variables inline comme les fonctions

#### C++20

- **Concepts** : Contraintes sur les templates pour meilleurs messages d'erreur
- **Ranges** : Nouvelle façon de travailler avec les séquences, plus composable
- **Coroutines** : Support natif de la programmation asynchrone avec `co_await`, `co_yield`
- **Modules** : Alternative à `#include` évitant la recompilation complète
- **std::span** : Vue non-propriétaire sur une séquence contiguë
- **Three-way comparison** : Opérateur `<=>` (spaceship operator) pour comparaisons
- **Designated initializers** : Initialisation de structs par nom de membre
- **consteval** : Fonctions devant être évaluées à la compilation
- **constinit** : Garantie d'initialisation à la compilation
- **std::format** : Formatage de chaînes type-safe à la printf
- **Calendar and timezone** : Support étendu des dates/heures

#### C++23

- **std::expected** : Gestion d'erreurs alternative aux exceptions
- **std::mdspan** : Vue multidimensionnelle sur des données
- **Deducing this** : Simplification des CRTP et méthodes template
- **if consteval** : Détection du contexte d'évaluation constante
- **std::print** : Sortie formatée simplifiée
- **Multidimensional subscript** : `operator[]` avec plusieurs indices
- **static operator()** : Opérateurs d'appel statiques pour lambdas
- **Monadic operations** : `and_then`, `or_else`, `transform` pour optional/expected
- **Ranges improvements** : Extensions et améliorations de la bibliothèque ranges
- **Stack trace library** : Introspection de la pile d'appel

---

### La STL (Standard Template Library)

#### Définition

La **Standard Template Library** est une bibliothèque logicielle puissante faisant partie intégrante du C++ standard depuis C++98. Elle fournit un ensemble de classes template génériques et de fonctions pour les structures de données courantes (conteneurs), les algorithmes de manipulation de ces structures, et les itérateurs qui permettent de parcourir les conteneurs de manière abstraite. 

La STL repose sur trois piliers :
1. **Conteneurs** : Structures de données prêtes à l'emploi
2. **Algorithmes** : Fonctions génériques (tri, recherche, transformation, etc.)
3. **Itérateurs** : Abstractions pour parcourir les conteneurs

La force de la STL réside dans sa généricité (grâce aux templates) et dans le découplage entre conteneurs et algorithmes via les itérateurs, permettant d'appliquer n'importe quel algorithme à n'importe quel conteneur compatible.

---

#### Conteneurs de la STL

##### Conteneurs Séquentiels

| Conteneur STL | Structure Correspondante (TP9) | Description |
|---------------|--------------------------------|-------------|
| **std::vector** | Tableau (Array) dynamique | Tableau redimensionnable automatiquement, stockage contigu, accès O(1) |
| **std::array** | Tableau (Array) | Tableau de taille fixe, plus sûr que les tableaux C classiques |
| **std::deque** | Double-ended queue | File à double entrée, insertion/suppression efficace aux deux extrémités O(1) |
| **std::list** | Liste doublement chaînée | Liste doublement chaînée permettant insertion/suppression O(1) partout |
| **std::forward_list** | Liste chaînée simple | Liste simplement chaînée, plus légère que `std::list` |

##### Conteneurs Associatifs (Ordonnés)

| Conteneur STL | Structure Correspondante (TP9) | Description |
|---------------|--------------------------------|-------------|
| **std::set** | Set (Ensemble) + Arbre Équilibré | Ensemble ordonné d'éléments uniques, implémenté avec un arbre rouge-noir |
| **std::multiset** | Set avec doublons + Arbre Équilibré | Comme `set` mais autorise les doublons |
| **std::map** | Table de Hachage + Arbre Équilibré | Paires clé-valeur ordonnées par clé, implémenté avec un arbre rouge-noir |
| **std::multimap** | Map avec clés dupliquées + Arbre Équilibré | Comme `map` mais autorise plusieurs valeurs par clé |

##### Conteneurs Associatifs Non-Ordonnés (Hash-based)

| Conteneur STL | Structure Correspondante (TP9) | Description |
|---------------|--------------------------------|-------------|
| **std::unordered_set** | Set + Table de Hachage | Ensemble non ordonné d'éléments uniques, accès O(1) moyen |
| **std::unordered_multiset** | Set avec doublons + Table de Hachage | Comme `unordered_set` mais autorise les doublons |
| **std::unordered_map** | Table de Hachage / Map / Dictionary | Paires clé-valeur non ordonnées, accès O(1) moyen, le plus utilisé |
| **std::unordered_multimap** | Map avec clés dupliquées + Table de Hachage | Comme `unordered_map` mais autorise plusieurs valeurs par clé |

##### Adaptateurs de Conteneurs

| Conteneur STL | Structure Correspondante (TP9) | Description |
|---------------|--------------------------------|-------------|
| **std::stack** | Pile (Stack) - LIFO | Adaptateur fournissant une interface LIFO (dernier entré, premier sorti) |
| **std::queue** | File (Queue) - FIFO | Adaptateur fournissant une interface FIFO (premier entré, premier sorti) |
| **std::priority_queue** | Queue de priorité + Tas | File où les éléments sont ordonnés par priorité, implémentée avec un heap |

##### Conteneurs Spéciaux

| Conteneur STL | Structure Correspondante (TP9) | Description |
|---------------|--------------------------------|-------------|
| **std::string** | Tableau dynamique de caractères | Chaîne de caractères avec opérations dédiées |
| **std::bitset** | Tableau de bits | Collection de bits de taille fixe avec opérations binaires |
| **std::valarray** | Tableau pour calculs numériques | Tableau optimisé pour opérations mathématiques vectorielles |

##### Conteneurs Post-C++11

| Conteneur STL | Lien avec Structures | Description |
|---------------|----------------------|-------------|
| **std::span** (C++20) | Vue sur tableau contigu | Vue non-propriétaire sur une séquence contiguë en mémoire |
| **std::mdspan** (C++23) | Vue multidimensionnelle | Vue sur des tableaux multidimensionnels |

---

#### Correspondances Détaillées avec le TP9

##### Structures Linéaires
- **Tableau** → `std::array` (fixe), `std::vector` (dynamique)
- **Liste chaînée** → `std::forward_list`
- **Liste doublement chaînée** → `std::list`
- **Pile (Stack)** → `std::stack`
- **File (Queue)** → `std::queue`
- **Queue de priorité** → `std::priority_queue`

##### Structures Arborescentes
- **Arbre Binaire de Recherche** → `std::set`, `std::map` (implémentés via arbres rouge-noir)
- **Arbre Équilibré** → Tous les conteneurs associatifs ordonnés (`set`, `map`, etc.)
- **Tas (Heap)** → `std::priority_queue` (utilise un heap en interne)
- **Arbre de Préfixes (Trie)** → Pas d'implémentation native, doit être créé manuellement

##### Structures Associatives
- **Table de Hachage / Map** → `std::unordered_map` (le plus direct), `std::map` (ordonné)
- **Set (Ensemble)** → `std::unordered_set` (hash-based), `std::set` (ordonné)

##### Structures Non Directement Couvertes
- **Graphe** → Pas d'implémentation native en STL, généralement créé avec `std::vector<std::vector<int>>` pour matrice d'adjacence ou `std::unordered_map<int, std::vector<int>>` pour liste d'adjacence

---

#### Points Clés de la STL

**Avantages**
- Code générique et réutilisable grâce aux templates
- Performance optimisée (souvent aussi rapide qu'une implémentation manuelle)
- Sûreté accrue (gestion des limites, itérateurs valides)
- Interopérabilité entre conteneurs via les itérateurs
- Maintenance facilitée avec du code standard bien testé

**Philosophie**
La STL encourage la séparation entre les données (conteneurs), les algorithmes (fonctions génériques comme `std::sort`, `std::find`) et le parcours (itérateurs), permettant une grande flexibilité et réutilisabilité du code.