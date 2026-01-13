# Rapport : La Programmation Orientée Objet en C++

## I. Introduction à la Programmation Orientée Objet (POO)

### 1. Contexte et motivations

La programmation orientée objet (POO) est née pour résoudre les limites de la programmation procédurale. Avec les langages comme C, le programme repose souvent sur une séquence d'instructions et de fonctions qui manipulent directement les données. Cette approche devient complexe à maintenir à mesure que les systèmes grossissent.

La POO, introduite dans les années 1980 avec Smalltalk et popularisée par C++, propose un modèle plus intuitif : elle structure un programme en objets représentant les entités du monde réel, avec leurs données (attributs) et leurs comportements (méthodes).

### 2. Objectifs fondamentaux

Les principaux atouts de la POO sont :

- **Modularité** : le code est organisé en modules autonomes (classes).
- **Réutilisabilité** : une classe peut être réutilisée dans différents projets.
- **Maintenance facilitée** : modifier un module n'affecte pas les autres.
- **Abstraction** : on simplifie la complexité en cachant les détails d'implémentation.

Ces principes reposent sur quatre piliers majeurs :

1. Encapsulation
2. Abstraction
3. Héritage
4. Polymorphisme

## II. Les bases : Classe, Objet et Encapsulation

### 1. Classe et objet

Une **classe** est une sorte de "plan" pour construire des objets. Elle définit les attributs et les méthodes qu'un objet de ce type possédera. Un **objet** est alors une instance concrète d'une classe.

**Exemple simplifié :**

- La classe `Etudiant` définit ce qu'est un étudiant.
- L'objet `Aymard`, instance de `Etudiant`, représente un étudiant particulier.

### 2. Structure d'une classe en C++

```cpp
class Etudiant {
private:
    string nom;
    int age;
public:
    Etudiant(string n, int a) : nom(n), age(a) {}  // constructeur
    string getNom() { return nom; }
    void setNom(string n) { nom = n; }
    void afficherInfos() { 
        cout << "Nom : " << nom << ", Age : " << age << endl; 
    }
};
```

### 3. Constructeurs et destructeurs

Les constructeurs permettent d'initialiser les objets, tandis que les destructeurs libèrent les ressources à la fin du cycle de vie de l'objet.

```cpp
Etudiant(string n, int a) : nom(n), age(a) {}   // constructeur
~Etudiant() { cout << nom << " supprimé." << endl; } // destructeur
```

### 4. Encapsulation et rôle des getters/setters

L'encapsulation consiste à protéger les données internes d'une classe en les rendant privées (`private`) et en y accédant via des méthodes d'accès :

- `getNom()` pour lire la valeur
- `setNom()` pour la modifier

Ce principe évite des erreurs logiques telles que la modification directe d'un attribut sensible.

## III. Abstraction, Héritage et Polymorphisme

### 1. Abstraction

L'abstraction consiste à cacher les détails inutiles à l'utilisateur d'une classe, en ne montrant que les fonctionnalités pertinentes. C++ permet cela via les classes abstraites et les méthodes virtuelles pures.

**Exemple :** une classe abstraite `Personne` peut définir une interface commune à toutes les personnes sans préciser les détails.

```cpp
class Personne {
public:
    virtual void afficherInfos() = 0; // méthode virtuelle pure
};
```

### 2. Héritage

L'héritage permet à une classe dite dérivée de réutiliser les membres d'une classe mère. Cela favorise la spécialisation progressive.

**Exemple :**

```cpp
class Etudiant : public Personne {
protected:
    string nom;
    int age;
public:
    Etudiant(string n, int a) : nom(n), age(a) {}
    void afficherInfos() override {
        cout << "Etudiant : " << nom << ", Age : " << age << endl;
    }
};

class EtudiantIngenieur : public Etudiant {
private:
    string specialite;
public:
    EtudiantIngenieur(string n, int a, string s) : Etudiant(n, a), specialite(s) {}
    void afficherInfos() override {
        cout << "Etudiant ingénieur : " << nom << ", spécialité " << specialite << endl;
    }
};
```

### 3. Polymorphisme

Le polymorphisme permet d'utiliser une même interface pour des objets de types différents. Ainsi, le code suivant appellera automatiquement la bonne méthode selon le type réel de l'objet :

```cpp
Personne* p1 = new Etudiant("Jacky", 23);
Personne* p2 = new EtudiantIngenieur("Faris", 22, "Cybersécurité");

p1->afficherInfos();  // Étudiant : Jacky, Age : 23
p2->afficherInfos();  // Étudiant ingénieur : Faris, spécialité Cybersécurité
```

Ce comportement est possible grâce aux méthodes virtuelles et à la liaison dynamique.

## IV. Relations entre classes

### 1. Association

L'association représente une simple relation fonctionnelle entre deux classes :

```cpp
// Un professeur enseigne à un étudiant (association)
class Professeur {
private:
    string nom;
public:
    Professeur(string n) : nom(n) {}
    void enseigner(Etudiant& e) {
        cout << nom << " enseigne à " << e.getNom() << endl;
    }
};
```

### 2. Agrégation

L'agrégation représente une relation "a un" où les objets peuvent exister indépendamment.

```cpp
class Cours {
private:
    string titre;
    Professeur* responsable;
    vector<Etudiant*> inscrits;
public:
    Cours(string t, Professeur* p) : titre(t), responsable(p) {}
    void ajouterEtudiant(Etudiant* e) { inscrits.push_back(e); }
};
```

### 3. Composition

La composition est une relation plus forte : l'objet contenu dépend entièrement de l'objet englobant.

```cpp
class ClasseEcole {
private:
    Etudiant responsable; // créé à l'intérieur → cycle de vie dépendant
public:
    ClasseEcole(string nomResp, int ageResp) : responsable(nomResp, ageResp) {}
};
```

### 4. Héritage

L'héritage exprime une relation "est un" (is-a) et produit le plus fort couplage entre les classes.

### 5. Comparaison du niveau de couplage

| Type de relation | Exemple | Couplage |
|-----------------|---------|----------|
| Association | Professeur – Étudiant | Faible |
| Agrégation | Cours – Etudiants | Moyen |
| Composition | ClasseEcole – Étudiant | Fort |
| Héritage | Personne – Étudiant | Très fort |

## V. Étude de cas : mini-système de gestion

### Description du scénario

Aymard gère un petit logiciel qui suit les étudiants de son école : chaque `Professeur` enseigne un `Cours`, et chaque `Cours` regroupe plusieurs `Etudiants` comme Jacky, Faris et Amadou.

### Illustration simplifiée du code

```cpp
int main() {
    Professeur prof("Aymard");
    Etudiant e1("Jacky", 23);
    EtudiantIngenieur e2("Faris", 22, "Cybersécurité");
    Etudiant e3("Amadou", 21);

    Cours cpp("Programmation C++", &prof);
    cpp.ajouterEtudiant(&e1);
    cpp.ajouterEtudiant(&e2);

    prof.enseigner(e3);
}
```

Cette simulation illustre plusieurs concepts :

- L'**encapsulation** (accès via getters/setters)
- L'**héritage** (spécialisation avec `EtudiantIngenieur`)
- Le **polymorphisme** (affichage dynamique d'infos)
- L'**agrégation** (cours contenant des étudiants)

## VI. Conclusion

La programmation orientée objet offre une manière élégante et structurée de concevoir des applications complexes. En C++, elle combine la puissance du langage bas niveau avec la modularité des concepts objets.

Les notions d'encapsulation, abstraction, héritage et polymorphisme garantissent un code plus propre, réutilisable et robuste. Quant aux relations entre classes — association, agrégation, composition et héritage — elles permettent de modéliser finement les liens entre les éléments du programme tout en maîtrisant le degré de couplage.

Ce rapport fournit ainsi une base solide pour l'ingénieur informatique souhaitant concevoir des logiciels bien architecturés, évolutifs et durables.