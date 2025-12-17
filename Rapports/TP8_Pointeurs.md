# Gestion de la Mémoire et Pointeurs en C/C++

## Introduction

La gestion de la mémoire constitue l'un des piliers fondamentaux de la programmation informatique. Contrairement aux langages de haut niveau qui masquent ces mécanismes, le C et le C++ offrent un contrôle direct et précis sur la mémoire, permettant d'optimiser les performances au prix d'une responsabilité accrue pour le développeur. Ce rapport explore les concepts essentiels de la gestion mémoire, des pointeurs et des références, en présentant leurs applications pratiques et leurs implications.

---

## 1. La Mémoire Informatique

### 1.1 Concept

La mémoire informatique est un espace de stockage temporaire où le processeur accède aux données et instructions nécessaires à l'exécution d'un programme. On peut la concevoir comme un vaste tableau d'octets, chacun identifié par une adresse unique. Lorsqu'on déclare une variable, le système d'exploitation réserve un emplacement mémoire spécifique pour stocker sa valeur.

Chaque variable possède donc trois caractéristiques fondamentales :
- **Une valeur** : le contenu stocké
- **Une adresse** : sa localisation en mémoire (généralement exprimée en hexadécimal)
- **Un type** : qui détermine la taille occupée et l'interprétation des données

### 1.2 Application concrète

En pratique, la compréhension de la mémoire permet de :
- Optimiser l'utilisation des ressources limitées
- Éviter les fuites mémoire (memory leaks)
- Comprendre les performances d'un programme
- Déboguer efficacement les erreurs de segmentation

### 1.3 Exemple

```c
#include <stdio.h>

int main() {
    int nombre = 42;
    
    printf("Valeur de nombre : %d\n", nombre);
    printf("Adresse de nombre : %p\n", (void*)&nombre);
    printf("Taille occupée : %lu octets\n", sizeof(nombre));
    
    return 0;
}
```

**Sortie possible :**
```
Valeur de nombre : 42
Adresse de nombre : 0x7ffc8b3a5d4c
Taille occupée : 4 octets
```

---

## 2. Stack et Heap : Deux Zones Mémoire Distinctes

### 2.1 La Stack (Pile)

#### Concept

La stack est une zone mémoire organisée selon le principe LIFO (Last In, First Out). Elle gère automatiquement l'allocation et la désallocation des variables locales et des appels de fonctions. Chaque appel de fonction crée un "frame" sur la stack contenant ses variables locales et ses paramètres.

**Caractéristiques :**
- Gestion automatique (allocation/désallocation)
- Taille limitée (généralement 1-8 Mo)
- Accès très rapide
- Durée de vie : limitée au scope de la fonction

#### Application concrète

La stack est utilisée pour :
- Les variables locales des fonctions
- Les paramètres de fonctions
- Les adresses de retour
- Les variables temporaires

#### Exemple

```c
void fonction() {
    int local = 10;  // Allouée sur la stack
    // local est automatiquement détruite à la fin de la fonction
}

int main() {
    int x = 5;      // Sur la stack
    fonction();
    // Ici, 'local' n'existe plus
    return 0;
}
```

### 2.2 Le Heap (Tas)

#### Concept

Le heap est une zone mémoire beaucoup plus vaste, utilisée pour l'allocation dynamique. Contrairement à la stack, le programmeur contrôle explicitement l'allocation et la libération de la mémoire. Les données persistent tant qu'elles ne sont pas explicitement libérées.

**Caractéristiques :**
- Gestion manuelle (malloc/free en C, new/delete en C++)
- Taille importante (limitée par la RAM disponible)
- Accès plus lent que la stack
- Durée de vie : contrôlée par le programmeur
- Risques : fuites mémoire, fragmentation

#### Application concrète

Le heap est indispensable pour :
- Les structures de données dont la taille n'est pas connue à la compilation
- Les données devant persister au-delà du scope d'une fonction
- Les grandes structures qui dépasseraient la capacité de la stack
- L'allocation dynamique de tableaux

#### Exemple

```c
#include <stdlib.h>
#include <stdio.h>

int main() {
    // Allocation sur le heap
    int *tableau = (int*)malloc(100 * sizeof(int));
    
    if (tableau == NULL) {
        printf("Échec d'allocation\n");
        return 1;
    }
    
    // Utilisation
    for (int i = 0; i < 100; i++) {
        tableau[i] = i * i;
    }
    
    // Libération obligatoire
    free(tableau);
    
    return 0;
}
```

**En C++ :**

```cpp
int main() {
    // Allocation sur le heap
    int *nombre = new int(42);
    int *tableau = new int[100];
    
    // Utilisation
    *nombre = 50;
    tableau[0] = 10;
    
    // Libération obligatoire
    delete nombre;
    delete[] tableau;  // Note: delete[] pour les tableaux
    
    return 0;
}
```

#### Différence entre malloc/free et new/delete

| Fonction | Langage | Allocation | Initialisation | Libération | Sécurité |
|----------|---------|------------|----------------|------------|----------|
| malloc | C       | Manuelle   | Non (valeurs indéfinies) | free     | Moins sûre |
| new    | C++     | Manuelle   | Oui (constructeur appelé) | delete   | Plus sûre (type-checking) |


### 2.3 Comparaison Stack vs Heap

| Critère | Stack | Heap |
|---------|-------|------|
| Vitesse | Très rapide | Plus lent |
| Taille | Limitée (1-8 Mo) | Grande (limitée par RAM) |
| Gestion | Automatique | Manuelle |
| Fragmentation | Aucune | Possible |
| Durée de vie | Scope local | Contrôlée |
| Risques | Stack overflow | Memory leaks, fragmentation |

---

## 3. Les Pointeurs

### 3.1 Concept

Un pointeur est une variable spéciale qui stocke l'adresse mémoire d'une autre variable plutôt que sa valeur directe. C'est un concept fondamental qui permet la manipulation directe de la mémoire et constitue la base de nombreuses structures de données avancées.

**Déclaration :** `type *nom_pointeur;`

**Opérateurs essentiels :**
- `&` (adresse de) : obtient l'adresse d'une variable
- `*` (déréférencement) : accède à la valeur pointée

Déréférencer un pointeur signifie accéder à la valeur stockée à l’adresse mémoire qu’il contient, grâce à l’opérateur *.

### 3.2 Application concrète

Les pointeurs sont utilisés pour :
- Passer des données par référence aux fonctions (évite la copie)
- Créer des structures de données dynamiques (listes, arbres, graphes)
- Gérer la mémoire dynamique (heap)
- Manipuler des tableaux efficacement
- Implémenter le polymorphisme en C
- Créer des fonctions de rappel (callbacks)

### 3.3 Exemples

#### Exemple de base

```c
#include <stdio.h>

int main() {
    int variable = 100;
    int *pointeur;
    
    pointeur = &variable;  // pointeur stocke l'adresse de variable
    
    printf("Valeur de variable : %d\n", variable);
    printf("Adresse de variable : %p\n", (void*)&variable);
    printf("Valeur de pointeur (adresse) : %p\n", (void*)pointeur);
    printf("Valeur pointée (*pointeur) : %d\n", *pointeur);
    
    // Modification via le pointeur
    *pointeur = 200;
    printf("Nouvelle valeur de variable : %d\n", variable);
    
    return 0;
}
```

#### Pointeurs et tableaux

```c
int main() {
    int tableau[5] = {10, 20, 30, 40, 50};
    int *ptr = tableau;  // Le nom d'un tableau est un pointeur
    
    // Parcours avec pointeur
    for (int i = 0; i < 5; i++) {
        printf("tableau[%d] = %d (via *(ptr+%d))\n", i, *(ptr + i), i);
    }
    
    return 0;
}
```

#### Pointeurs et allocation dynamique

```c
#include <stdlib.h>

typedef struct {
    char nom[50];
    int age;
} Personne;

int main() {
    // Allocation dynamique d'une structure
    Personne *p = (Personne*)malloc(sizeof(Personne));
    
    if (p != NULL) {
        strcpy(p->nom, "Alice");  // Opérateur -> pour les pointeurs
        p->age = 25;
        
        printf("Nom: %s, Age: %d\n", p->nom, p->age);
        
        free(p);  // Libération
    }
    
    return 0;
}
```

### 3.4 Pièges courants

```c
// Pointeur non initialisé (dangereux !)
int *ptr;  // Contient une adresse aléatoire
*ptr = 10;  // ERREUR : segmentation fault probable

// Pointeur NULL sûr
int *ptr_safe = NULL;
if (ptr_safe != NULL) {
    *ptr_safe = 10;  // Ne s'exécute pas
}

// Fuite mémoire
int *p = (int*)malloc(sizeof(int));
p = NULL;  // Mémoire perdue, impossible de la libérer !

// Pointeur pendant (dangling pointer)
int *p = (int*)malloc(sizeof(int));
free(p);
*p = 10;  // ERREUR : la mémoire est libérée
```

---

## 4. Les Références (C++ uniquement)

### 4.1 Concept

Une référence est un alias, un nom alternatif pour une variable existante. Introduite en C++, elle offre une syntaxe plus simple et plus sûre que les pointeurs pour certaines opérations. Une référence doit être initialisée lors de sa déclaration et ne peut plus changer de cible par la suite.

**Déclaration :** `type &nom_reference = variable;`

### 4.2 Application concrète

Les références sont particulièrement utiles pour :
- Passer des paramètres aux fonctions sans copie
- Retourner des valeurs sans copie
- Créer des alias lisibles dans le code
- Implémenter des opérateurs surchargés
- Chaîner des opérations (comme avec `std::cout`)

### 4.3 Exemple

```cpp
#include <iostream>
using namespace std;

int main() {
    int original = 42;
    int &reference = original;  // reference est un alias de original
    
    cout << "original = " << original << endl;
    cout << "reference = " << reference << endl;
    
    // Modification via la référence
    reference = 100;
    cout << "Après modification via reference:" << endl;
    cout << "original = " << original << endl;
    cout << "reference = " << reference << endl;
    
    // Les deux partagent la même adresse
    cout << "Adresse de original: " << &original << endl;
    cout << "Adresse de reference: " << &reference << endl;
    
    return 0;
}
```

---

## 5. Pointeurs vs Références : Différences Fondamentales

### 5.1 Tableau comparatif

| Critère | Pointeur | Référence |
|---------|----------|-----------|
| **Initialisation** | Peut être non initialisé | Doit être initialisé à la déclaration |
| **Réassignation** | Peut pointer vers différentes variables | Ne peut pas changer de cible |
| **Valeur NULL** | Peut être NULL | Ne peut pas être nulle |
| **Syntaxe d'accès** | Nécessite `*` pour déréférencement | Accès direct comme variable normale |
| **Arithmétique** | Arithmétique de pointeur possible | Aucune arithmétique |
| **Niveau d'indirection** | Peut avoir plusieurs niveaux (`int**`) | Un seul niveau |
| **Mémoire** | Occupe de la mémoire (4 ou 8 octets) | Aucun surcoût mémoire (alias) |
| **Sécurité** | Moins sûr (erreurs possibles) | Plus sûr (garanties du compilateur) |
| **Disponibilité** | C et C++ | C++ uniquement |

### 5.2 Exemple comparatif

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 20;
    
    // POINTEUR
    int *ptr = &a;
    cout << "Pointeur pointe vers a: " << *ptr << endl;
    
    ptr = &b;  // Peut changer de cible
    cout << "Pointeur pointe maintenant vers b: " << *ptr << endl;
    
    ptr = nullptr;  // Peut être NULL
    
    // RÉFÉRENCE
    int &ref = a;
    cout << "Référence à a: " << ref << endl;
    
    // ref = b;  // Ceci copie la valeur de b dans a, ne change pas la cible !
    ref = 30;  // Modifie a
    cout << "a après modification via ref: " << a << endl;
    
    // int &ref2;  // ERREUR : doit être initialisée
    // int &ref3 = nullptr;  // ERREUR : ne peut pas être NULL
    
    return 0;
}
```

### 5.3 Quand utiliser quoi ?

**Utilisez des pointeurs quand :**
- Vous devez représenter l'absence de valeur (NULL/nullptr)
- Vous devez réassigner pour pointer vers différentes variables
- Vous travaillez avec de l'allocation dynamique
- Vous implémentez des structures de données complexes
- Vous avez besoin d'arithmétique de pointeur
- Vous programmez en C (pas de références disponibles)

**Utilisez des références quand :**
- Vous passez des paramètres aux fonctions
- Vous voulez éviter la copie de données volumineuses
- Vous créez des opérateurs surchargés
- Vous voulez une syntaxe plus claire et plus sûre
- Vous êtes certain qu'une valeur existera toujours

---

## 6. Passage de Paramètres : Trois Approches

Le passage de paramètres aux fonctions est un concept crucial qui influence directement les performances et le comportement du programme. Trois méthodes existent, chacune avec ses avantages et inconvénients.

### 6.1 Passage par Valeur

#### Concept

Lors d'un passage par valeur, la fonction reçoit une **copie** de la variable originale. Toute modification effectuée dans la fonction n'affecte pas la variable d'origine. C'est le comportement par défaut en C et C++.

#### Application concrète

À utiliser quand :
- Les données sont de petite taille (types primitifs)
- On ne veut pas modifier l'original
- On veut garantir l'immuabilité des données d'entrée

#### Exemple

```c
#include <stdio.h>

void incrementer(int x) {
    x = x + 10;
    printf("Dans la fonction: x = %d\n", x);
}

int main() {
    int nombre = 5;
    
    printf("Avant l'appel: nombre = %d\n", nombre);
    incrementer(nombre);
    printf("Après l'appel: nombre = %d\n", nombre);
    // nombre vaut toujours 5 !
    
    return 0;
}
```

**Sortie :**
```
Avant l'appel: nombre = 5
Dans la fonction: x = 15
Après l'appel: nombre = 5
```

**Avantages :** Sécurité (pas de modification accidentelle), simplicité
**Inconvénients :** Coût de la copie pour les grandes structures

### 6.2 Passage par Pointeur

#### Concept

La fonction reçoit l'adresse mémoire de la variable. Elle peut donc modifier directement la variable d'origine via le déréférencement. C'est la seule méthode disponible en C pour modifier une variable dans une fonction.

#### Application concrète

À utiliser quand :
- On veut modifier la variable d'origine
- On veut éviter la copie de grandes structures
- On peut avoir des valeurs NULL à gérer
- On travaille en C pur

#### Exemple

```c
#include <stdio.h>

void incrementer(int *ptr) {
    if (ptr != NULL) {
        *ptr = *ptr + 10;
        printf("Dans la fonction: *ptr = %d\n", *ptr);
    }
}

void echanger(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int nombre = 5;
    
    printf("Avant l'appel: nombre = %d\n", nombre);
    incrementer(&nombre);  // On passe l'adresse
    printf("Après l'appel: nombre = %d\n", nombre);
    
    int x = 10, y = 20;
    printf("\nAvant échange: x=%d, y=%d\n", x, y);
    echanger(&x, &y);
    printf("Après échange: x=%d, y=%d\n", x, y);
    
    return 0;
}
```

**Sortie :**
```
Avant l'appel: nombre = 5
Dans la fonction: *ptr = 15
Après l'appel: nombre = 15

Avant échange: x=10, y=20
Après échange: x=20, y=10
```

**Avantages :** Modification possible, efficacité, gestion de NULL
**Inconvénients :** Syntaxe plus lourde, risques de segmentation fault

### 6.3 Passage par Référence (C++ uniquement)

#### Concept

La fonction reçoit un alias de la variable originale. Syntaxiquement, cela ressemble à un passage par valeur, mais le comportement est celui d'un passage par pointeur, en plus sûr et plus lisible.

#### Application concrète

À utiliser quand :
- On veut modifier la variable d'origine
- On veut éviter la copie sans la lourdeur des pointeurs
- On est certain qu'une valeur existe (pas de NULL)
- On travaille en C++

#### Exemple

```cpp
#include <iostream>
using namespace std;

void incrementer(int &x) {
    x = x + 10;
    cout << "Dans la fonction: x = " << x << endl;
}

void echanger(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Référence constante pour éviter la copie sans modification
void afficher(const string &texte) {
    cout << "Texte: " << texte << endl;
    // texte = "modif";  // ERREUR : const interdit la modification
}

int main() {
    int nombre = 5;
    
    cout << "Avant l'appel: nombre = " << nombre << endl;
    incrementer(nombre);  // Syntaxe simple, pas besoin de &
    cout << "Après l'appel: nombre = " << nombre << endl;
    
    int x = 10, y = 20;
    cout << "\nAvant échange: x=" << x << ", y=" << y << endl;
    echanger(x, y);
    cout << "Après échange: x=" << x << ", y=" << y << endl;
    
    string message = "Bonjour le monde";
    afficher(message);  // Pas de copie grâce à la référence
    
    return 0;
}
```

**Sortie :**
```
Avant l'appel: nombre = 5
Dans la fonction: x = 15
Après l'appel: nombre = 15

Avant échange: x=10, y=20
Après échange: x=20, y=10
Texte: Bonjour le monde
```

**Avantages :** Syntaxe claire, sûreté, efficacité, pas de NULL à gérer
**Inconvénients :** Seulement en C++, ne peut pas représenter l'absence

### 6.4 Tableau récapitulatif

| Méthode | Syntaxe fonction | Appel | Modification | Copie | Langage |
|---------|------------------|-------|--------------|-------|---------|
| **Par valeur** | `void f(int x)` | `f(var)` | Non | Oui | C, C++ |
| **Par pointeur** | `void f(int *x)` | `f(&var)` | Oui | Non | C, C++ |
| **Par référence** | `void f(int &x)` | `f(var)` | Oui | Non | C++ |
| **Par référence const** | `void f(const int &x)` | `f(var)` | Non | Non | C++ |

### 6.5 Exemple comparatif complet

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Structure volumineuse
struct GrosObjet {
    int data[1000];
    GrosObjet() { 
        cout << "Construction de GrosObjet" << endl; 
    }
    GrosObjet(const GrosObjet &) { 
        cout << "Copie de GrosObjet (coûteux !)" << endl; 
    }
};

// Passage par valeur : COPIE
void parValeur(GrosObjet obj) {
    obj.data[0] = 999;
}

// Passage par pointeur : PAS DE COPIE, modification possible
void parPointeur(GrosObjet *obj) {
    if (obj != nullptr) {
        obj->data[0] = 999;
    }
}

// Passage par référence : PAS DE COPIE, modification possible
void parReference(GrosObjet &obj) {
    obj.data[0] = 999;
}

// Passage par référence constante : PAS DE COPIE, lecture seule (OPTIMAL)
void parReferenceConst(const GrosObjet &obj) {
    cout << "Lecture: " << obj.data[0] << endl;
    // obj.data[0] = 999;  // ERREUR : const
}

int main() {
    GrosObjet objet;
    objet.data[0] = 42;
    
    cout << "\n--- Par valeur ---" << endl;
    parValeur(objet);  // Copie coûteuse !
    cout << "Valeur: " << objet.data[0] << " (non modifié)" << endl;
    
    cout << "\n--- Par pointeur ---" << endl;
    parPointeur(&objet);
    cout << "Valeur: " << objet.data[0] << " (modifié)" << endl;
    
    objet.data[0] = 42;
    cout << "\n--- Par référence ---" << endl;
    parReference(objet);
    cout << "Valeur: " << objet.data[0] << " (modifié)" << endl;
    
    cout << "\n--- Par référence const ---" << endl;
    parReferenceConst(objet);
    
    return 0;
}
```

---

## 7. Concepts Avancés et Bonnes Pratiques

### 7.1 Pointeurs de pointeurs

Les pointeurs peuvent pointer vers d'autres pointeurs, créant plusieurs niveaux d'indirection.

```c
int main() {
    int valeur = 100;
    int *ptr1 = &valeur;
    int **ptr2 = &ptr1;  // Pointeur vers pointeur
    
    printf("valeur = %d\n", valeur);
    printf("*ptr1 = %d\n", *ptr1);
    printf("**ptr2 = %d\n", **ptr2);
    
    **ptr2 = 200;  // Modifie valeur via double indirection
    printf("valeur = %d\n", valeur);
    
    return 0;
}
```

**Utilisation :** Tableaux 2D dynamiques, modification de pointeurs dans les fonctions.

### 7.2 Pointeurs de fonction

Les fonctions ont aussi des adresses mémoire, permettant de créer des callbacks.

```c
#include <stdio.h>

int addition(int a, int b) { return a + b; }
int multiplication(int a, int b) { return a * b; }

void calculer(int x, int y, int (*operation)(int, int)) {
    printf("Résultat: %d\n", operation(x, y));
}

int main() {
    calculer(5, 3, addition);        // Résultat: 8
    calculer(5, 3, multiplication);  // Résultat: 15
    return 0;
}
```

### 7.3 Pointeurs intelligents (C++11 et plus)

Pour éviter les fuites mémoire, C++ moderne offre des pointeurs intelligents qui gèrent automatiquement la mémoire.

```cpp
#include <memory>
#include <iostream>
using namespace std;

class Ressource {
public:
    Ressource() { cout << "Ressource créée" << endl; }
    ~Ressource() { cout << "Ressource détruite" << endl; }
    void utiliser() { cout << "Ressource utilisée" << endl; }
};

int main() {
    // unique_ptr : propriété exclusive
    {
        unique_ptr<Ressource> ptr1(new Ressource());
        ptr1->utiliser();
        // Destruction automatique à la fin du scope
    }
    
    // shared_ptr : propriété partagée
    {
        shared_ptr<Ressource> ptr2 = make_shared<Ressource>();
        {
            shared_ptr<Ressource> ptr3 = ptr2;  // Partage
            cout << "Compteur de références: " << ptr2.use_count() << endl;
        }
        cout << "Compteur après scope: " << ptr2.use_count() << endl;
        // Destruction quand le dernier shared_ptr disparaît
    }
    
    return 0;
}
```

### 7.4 Règles de sécurité

**Règles d'or pour éviter les erreurs :**

1. **Toujours initialiser les pointeurs**
   ```c
   int *ptr = NULL;  // ou nullptr en C++
   ```

2. **Vérifier avant de déréférencer**
   ```c
   if (ptr != NULL) {
       *ptr = 10;
   }
   ```

3. **Libérer la mémoire allouée**
   ```c
   free(ptr);      // C
   delete ptr;     // C++
   ```

4. **Mettre à NULL après libération**
   ```c
   free(ptr);
   ptr = NULL;
   ```

5. **Éviter les pointeurs pendants**
   ```c
   int *creerEntier() {
       int local = 10;
       return &local;  // ERREUR : local est détruit
   }
   ```

6. **Préférer les références en C++ quand possible**

7. **Utiliser `const` pour protéger les données**
   ```cpp
   void lire(const int *ptr);  // Ne peut pas modifier
   ```

### 7.5 Outils de détection d'erreurs

Pour détecter les erreurs mémoire :

- **Valgrind** : détecte fuites mémoire, accès invalides
- **AddressSanitizer** : détection rapide d'erreurs mémoire
- **Static analyzers** : analyse du code avant compilation

```bash
# Compilation avec AddressSanitizer
g++ -fsanitize=address -g programme.cpp -o programme

# Analyse avec Valgrind
valgrind --leak-check=full ./programme
```

---

## 8. Cas d'Usage Pratiques

### 8.1 Listes chaînées

```c
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* creerNode(int valeur) {
    Node *nouveau = (Node*)malloc(sizeof(Node));
    nouveau->data = valeur;
    nouveau->next = NULL;
    return nouveau;
}

void afficherListe(Node *head) {
    Node *courant = head;
    while (courant != NULL) {
        printf("%d -> ", courant->data);
        courant = courant->next;
    }
    printf("NULL\n");
}
```

### 8.2 Tableaux dynamiques redimensionnables

```c
int* redimensionner(int *ancien, int ancienneTaille, int nouvelleTaille) {
    int *nouveau = (int*)malloc(nouvelleTaille * sizeof(int));
    
    // Copier les anciennes données
    int tailleCopie = (ancienneTaille < nouvelleTaille) ? ancienneTaille : nouvelleTaille;
    for (int i = 0; i < tailleCopie; i++) {
        nouveau[i] = ancien[i];
    }
    
    free(ancien);
    return nouveau;
}
```

### 8.3 Passage de tableau multidimensionnel

```cpp
// Mauvaise approche : perte d'information de taille
void mauvaisPassage(int **matrice) { }

// Bonne approche avec références
void bonPassage(int (&matrice)[3][4]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << matrice[i][j] << " ";
        }
        cout << endl;
    }
}

// Approche moderne C++ avec vector
void modernePassage(vector<vector<int>> &matrice) {
    for (const auto &ligne : matrice) {
        for (int val : ligne) {
            cout << val << " ";
        }
        cout << endl;
    }
}
```

---

## Conclusion

La gestion de la mémoire en C/C++ représente à la fois une puissance considérable et une responsabilité majeure pour le développeur. Comprendre la distinction entre stack et heap, maîtriser les pointeurs et les références, et choisir judicieusement le mode de passage de paramètres sont des compétences essentielles.


