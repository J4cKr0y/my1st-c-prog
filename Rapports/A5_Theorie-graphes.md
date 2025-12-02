# La Théorie des Graphes : Du Concept à l'Implémentation
## 1. Introduction : Qu'est-ce qu'un graphe ?
Un graphe est une façon de représenter des relations entre des objets. Imagine ton réseau d'amis : chaque personne est un point, et les amitiés sont des traits qui relient ces points.
C'est exactement ce principe qui permet à Facebook de te suggérer des amis, à Google Maps de calculer ton itinéraire, ou à Netflix de te recommander des séries.
Définition formelle
Un graphe G est une structure mathématique définie par G = (V, E) où :
- V est un ensemble fini de sommets (ou nœuds)
- E est un ensemble de paires d'éléments de V, appelées arêtes
Par exemple, si V = {Jacky, Aymard, Faris} et E = {(Jacky, Aymard), (Aymard, Faris)}, alors le graphe représente trois personnes dont deux paires sont en relation.

## 2. L'histoire fondatrice : Les ponts de Königsberg
### Le contexte historique
En 1736, la ville de Königsberg en Prusse (aujourd'hui Kaliningrad en Russie) était traversée par la rivière Pregel qui formait deux îles. Ces îles et les rives étaient reliées par sept ponts.
### Le problème
Les habitants se posaient une question : est-il possible de faire une promenade en passant par chaque pont exactement une seule fois et de revenir au point de départ ?
### La solution d'Euler
Le mathématicien Leonhard Euler a résolu ce problème en l'abstrayant :
- Il a représenté chaque zone de terre comme un point (sommet)
- Chaque pont comme une ligne (arête) reliant deux points
Il a démontré qu'une telle promenade n'est possible que si chaque sommet a un nombre pair d'arêtes qui y sont connectées. À Königsberg, tous les sommets avaient un nombre impair de connexions, rendant le parcours impossible.
### Importance historique
Cette découverte a créé un nouveau domaine mathématique : la théorie des graphes. Euler a montré qu'on pouvait résoudre des problèmes géographiques complexes en les transformant en structures abstraites.
Le concept de "chemin eulérien" (un chemin passant par chaque arête exactement une fois) découle directement de ce travail.

## 3. Applications en informatique moderne
**Réseaux sociaux**
Chaque utilisateur est un nœud, chaque relation d'amitié ou de suivi est une arête. Les algorithmes de graphes permettent :
- La suggestion d'amis (recherche de triangles : "Jacky connaît Aymard qui connaît Faris")
- La détection de communautés
- La mesure d'influence
- L'analyse de propagation d'information

**Navigation et cartographie**
Les systèmes GPS modélisent les routes comme des graphes :
- Les intersections sont des nœuds
- Les routes sont des arêtes
- Les poids représentent la distance, le temps, ou le trafic
L'algorithme de Dijkstra trouve le chemin le plus court entre deux points.

**Infrastructure Internet**
Internet est un gigantesque graphe distribué :
- Les routeurs et serveurs sont des nœuds
- Les connexions réseau sont des arêtes
Les protocoles de routage utilisent des algorithmes de graphes pour acheminer les paquets

**Intelligence artificielle**
Les réseaux de neurones sont des graphes orientés où :
- Chaque neurone est un nœud
- Les connexions synaptiques sont des arêtes pondérées
- L'apprentissage ajuste les poids

**Autres applications**
- Moteurs de recherche : Le PageRank de Google modélise le web comme un graphe
- Bases de données : Les bases de données orientées graphes (Neo4j)
- Biologie : Modélisation de réseaux métaboliques et de chaînes alimentaires
- Compilation : Graphes de dépendances entre modules
- Jeux vidéo : Pathfinding pour les IA des ennemis


## 4. Concepts fondamentaux
### 4.1 Le nœud (ou sommet)
**Définition simple**
Un nœud représente une entité dans le graphe. C'est un point.

**Définition formelle**
Un sommet v appartient à l'ensemble V des sommets du graphe G = (V, E). 
Dans une implémentation, un sommet peut être :
- Un identifiant numérique (0, 1, 2, ...)
- Une structure de données contenant des attributs
-  référence vers un objet

**Propriétés d'un nœud**
Un nœud peut posséder des attributs arbitraires :
- Identifiant unique
- Label ou nom
- Métadonnées (couleur, poids, type)
- Pointeurs vers des structures externes

### 4.2 L'arête (ou arc)
**Définition**
Une arête est une connexion entre deux nœuds. Elle représente une relation.
**Types d'arêtes**
- Arêtes non-orientées (graphe non-orienté)
Une arête non-orientée entre u et v est notée (u, v) ou {u, v}. 
Elle est symétrique : si (u, v) existe, alors (v, u) existe aussi.
Exemple : l'amitié sur Facebook. Si Jacky est ami avec Aymard, alors Aymard est ami avec Jacky.
- Arêtes orientées (graphe orienté ou digraphe)
Une arête orientée de u vers v est notée (u, v). 
Elle n'est pas symétrique : (u, v) peut exister sans que (v, u) existe.
Exemple : le suivi sur Twitter. Jacky peut suivre Aymard sans qu'Aymard suive Jacky.
Notation : u -> v
**Boucles et arêtes multiples**
- Boucle : Une arête reliant un nœud à lui-même, notée (v, v).
- Arêtes multiples : Plusieurs arêtes entre la même paire de nœuds. Un graphe permettant cela est appelé multigraphe.
- Graphe simple : Graphe sans boucles ni arêtes multiples.

### 4.3 Le poids
**Définition**
Un poids est une valeur numérique associée à une arête. 
Il représente un coût, une distance, une capacité, ou toute mesure quantitative.
**Graphe pondéré vs non-pondéré**
- Graphe non-pondéré : Toutes les arêtes ont le même coût implicite (généralement 1).
- Graphe pondéré : Chaque arête e possède une fonction de poids w : E ? R.
**Exemples de poids**
- Distance géographique (km)
- Temps de trajet (minutes)
- Coût financier (euros)
- Bande passante (Mbps)
- Capacité (unités)
- Probabilité (valeur entre 0 et 1)
**Poids multiples**
Une arête peut posséder plusieurs poids simultanément. 
Dans ce cas, on parle de graphe multi-attributs ou de graphe avec tuple de poids.
Exemple : Une route entre deux villes peut avoir :
- Distance : 150 km
- Temps : 90 minutes
- Péage : 8 euros
- Trafic : 0.7 (intensité normalisée)

### 4.4 La connexité
**Graphes non-orientés**
Un graphe non-orienté est connexe si pour toute paire de sommets (u, v), il existe un chemin de u à v.
- Composante connexe : Sous-ensemble maximal de sommets tel que tous les sommets sont connectés entre eux. Un graphe connexe a exactement une composante connexe.
**Graphes orientés**
- Fortement connexe : Pour toute paire de sommets (u, v), il existe un chemin de u à v ET un chemin de v à u.
- Faiblement connexe : Le graphe serait connexe si on ignorait les orientations des arêtes.
- Composante fortement connexe : Sous-graphe maximal fortement connexe.
**Importance**
La connexité détermine :
- La navigabilité du graphe
- L'existence de chemins entre nœuds
- La robustesse du réseau
- Les algorithmes applicables

### 4.5 Le degré
**Graphes non-orientés**
Le degré d'un sommet v, noté deg(v) ou d(v), est le nombre d'arêtes incidentes à v.
Propriété fondamentale : La somme des degrés de tous les sommets est égale à deux fois le nombre d'arêtes.
Formule : €deg(v) = 2|E|
Cette propriété, appelée *Lemme des poignées de main*, implique que le nombre de sommets de degré impair est toujours pair.
**Graphes orientés**
Pour un sommet v dans un graphe orienté :
- Degré entrant (in-degree) : deg-(v) = nombre d'arêtes arrivant à v
- Degré sortant (out-degree) : deg+(v) = nombre d'arêtes partant de v
- Degré total : deg(v) = deg-(v) + deg+(v)
**Classification des sommets par degré**
- Sommet isolé : deg(v) = 0
- Sommet pendant (feuille) : deg(v) = 1
- Sommet de degré élevé (hub) : deg(v) >> moyenne

Dans les réseaux réels, la distribution des degrés suit souvent une loi de puissance (réseaux scale-free).

### 4.6 Autres notions fondamentales
**Chemin**
Une séquence de sommets v0, v1, ..., vk telle que (vi, vi+1) est une arête pour tout i.
- Longueur du chemin : Nombre d'arêtes (k dans l'exemple ci-dessus).
- Chemin simple : Aucun sommet n'est visité plus d'une fois.
**Cycle**
Un chemin qui commence et se termine au même sommet.
- Cycle simple : Aucun sommet (sauf le premier/dernier) n'est visité plus d'une fois.
- Graphe acyclique : Graphe sans cycles.
- DAG (Directed Acyclic Graph) : Graphe orienté acyclique, fondamental en ordonnancement de tâches.
**Distance**
La distance entre deux sommets u et v, notée d(u, v), est la longueur du plus court chemin entre u et v.
- Si aucun chemin n'existe : d(u, v) = infini
- Diamètre du graphe : max{d(u, v) | u, v € V}
- Rayon du graphe : min{max{d(u, v) | v € V} | u € V}
**Arbre**
Un arbre est un graphe connexe acyclique. Propriétés équivalentes :
- Graphe connexe avec |V| - 1 arêtes
- Graphe acyclique avec |V| - 1 arêtes
Entre toute paire de sommets, il existe exactement un chemin
Forêt : Union disjointe d'arbres.
Arbre enraciné : Arbre avec un sommet distingué (racine).
**Graphe complet**
Un graphe où chaque paire de sommets distincts est reliée par une arête.
Noté Kn pour n sommets.
Nombre d'arêtes : |E| = n(n-1)/2
**Graphe biparti**
Graphe dont les sommets peuvent être divisés en deux ensembles disjoints U et V tels que chaque arête connecte un sommet de U à un sommet de V.
Propriété : Un graphe est biparti si et seulement si il ne contient pas de cycle de longueur impaire.
Applications : Matching (affectation), problèmes d'allocation de ressources.
**Clique**
Un sous-ensemble de sommets tous adjacents entre eux (sous-graphe complet).
Le problème de la clique maximum est NP-complet.
**Ensemble indépendant**
Un sous-ensemble de sommets sans arêtes entre eux.
Relation : Un ensemble indépendant dans G correspond à une clique dans le graphe complément de G.

## 5. Modélisation des systèmes de communication
### 5.1 Problématique
Considérons trois personnes : Jacky, Aymard et Faris. 
Nous voulons modéliser leurs échanges de messages. 
Quelles sont les informations pertinentes à capturer ?
- Qui communique avec qui
- Le nombre de messages échangés
- Le volume de texte (nombre de caractères)
- La nature des messages (texte, photos, vocaux)
- La temporalité des échanges

### 5.2 Approches de modélisation
#### Approche 1 : Graphe de relations avec poids agrégés
- Nœuds : Les trois personnes {Jacky, Aymard, Faris}
- Arêtes : Relations de communication (orientées car A->B différent de B->A)
- Poids : Métriques agrégées sur la relation
Cette approche capture la relation globale entre deux personnes, pas les messages individuels.
#### Approche 2 : Graphe de messages
- Nœuds : Chaque message individuel
- Arêtes : Relations de réponse entre messages
- Attributs des nœuds : Expéditeur, destinataire, contenu, timestamp
Cette approche capture la structure conversationnelle mais est plus complexe.

### 5.3 Choix de modélisation : Graphe de relations
Pour notre cas, nous adoptons l'approche 1 avec un graphe orienté pondéré.
Pourquoi?
- 3 nœuds seulement : structure simple
- Maximum 6 arêtes (3 × 2 pour un graphe orienté complet)
- Intérêt pour les statistiques agrégées
- Efficacité de calcul

### 5.4 Poids multiples sur les arêtes
Contrairement à un graphe classique avec un seul poids par arête, nous assignons un tuple de valeurs à chaque arête :
```
Arête (Jacky -> Aymard) = {
nbMessages : entier
nbCaracteres : entier
nbPhotos : entier
nbEmojis : entier
tempsReponseMoyen : réel
dernierMessage : timestamp
}
```
Cette approche multi-attributs permet une analyse riche des patterns de communication.

### 5.5 Métriques dérivées
À partir des poids bruts, on peut calculer :
- Moyenne de caractères par message : nbCaracteres / nbMessages
- Intensité de communication : nbMessages / durée_relation
- Réciprocité : min(messages(A->B), messages(B->A)) / max(messages(A->B), messages(B->A))
- Centralité : Somme des messages envoyés et reçus par une personne

## 6. Représentations en mémoire
### 6.1 Problématique de la représentation
Un graphe est une structure mathématique abstraite. 
Pour l'implémenter sur ordinateur, il faut choisir une structure de données concrète. 
Ce choix impacte :
- L'utilisation de la mémoire
- La vitesse des opérations
- La complexité du code

### 6.2 Matrice d'adjacence
#### Principe
Pour un graphe avec n sommets, on crée une matrice carrée M de taille n × n.
**Graphe non-pondéré :**
M[i][j] = 1 si l'arête (i, j) existe
M[i][j] = 0 sinon
**Graphe pondéré :**
M[i][j] = poids de l'arête (i, j) si elle existe
M[i][j] = infini (ou 0, ou valeur sentinelle) sinon
**Graphe non-orienté : **
Matrice symétrique (M[i][j] = M[j][i])
**Graphe orienté : **
Matrice quelconque

#### Implémentation en C
```
#define N 3  // Nombre de nœuds
#define INF 999999  // Valeur pour "pas d'arête"

// Graphe non-pondéré
int graphe[N][N] = {
    {0, 1, 0},  // Nœud 0 (Jacky)
    {1, 0, 1},  // Nœud 1 (Aymard)
    {0, 1, 0}   // Nœud 2 (Faris)
};

// Graphe pondéré (distances en km)
int distances[N][N] = {
    {0,   150, INF},
    {150, 0,   200},
    {INF, 200, 0}
};

// Vérifier l'existence d'une arête
int existe_arete(int graphe[N][N], int u, int v) {
    return graphe[u][v] != 0 && graphe[u][v] != INF;
}

// Obtenir le poids d'une arête
int poids_arete(int graphe[N][N], int u, int v) {
    return graphe[u][v];
}

// Parcourir tous les voisins d'un nœud
void parcourir_voisins(int graphe[N][N], int u) {
    for (int v = 0; v < N; v++) {
        if (existe_arete(graphe, u, v)) {
            printf("Arête de %d vers %d avec poids %d\n", 
                   u, v, graphe[u][v]);
        }
    }
}
```
#### Complexité
**Espace : **
O(n²) où n = |V|
**Opérations :**
- Vérifier si (u, v) existe : O(1)
- Obtenir le poids de (u, v) : O(1)
- Parcourir tous les voisins de u : O(n)
- Ajouter/supprimer une arête : O(1)
- Parcourir toutes les arêtes : O(n²)
**Avantages :**
- Accès direct en temps constant
- Simple à implémenter
- Efficace pour les graphes denses (|E| ~= n²)
- Bien adapté pour certains algorithmes matriciels
**Inconvénients :**
- Gaspillage de mémoire pour les graphes creux (|E| << n²)
- Impossible pour les très grands graphes (n > 10^6)
- Parcours des voisins inefficace si le degré est faible
**Quand utiliser :**
- Graphes denses (|E| > n²/2)
- Petits graphes (n < 1000)
- Besoin de vérifications d'adjacence fréquentes
- Algorithmes matriciels (multiplication de matrices, etc.)

### 6.3 Liste d'adjacence
#### Principe
Pour chaque sommet, on maintient une liste de ses voisins. 
C'est un tableau de listes.
**Structure : **
Adj[u] = liste des sommets v tels que (u, v) € E
Pour un graphe pondéré, chaque élément de la liste contient aussi le poids.
**Implémentation avec listes chaînées**
```
#include <stdio.h>
#include <stdlib.h>

// Structure pour un nœud de la liste chaînée
typedef struct Voisin {
    int destination;
    int poids;
    struct Voisin* suivant;
} Voisin;

// Structure du graphe
typedef struct {
    int nbNoeuds;
    Voisin** adjacence;  // Tableau de pointeurs vers listes
} Graphe;

// Créer un graphe vide
Graphe* creer_graphe(int n) {
    Graphe* g = malloc(sizeof(Graphe));
    g->nbNoeuds = n;
    g->adjacence = malloc(n * sizeof(Voisin*));
    
    for (int i = 0; i < n; i++) {
        g->adjacence[i] = NULL;
    }
    
    return g;
}

// Ajouter une arête orientée
void ajouter_arete(Graphe* g, int u, int v, int poids) {
    Voisin* nouveau = malloc(sizeof(Voisin));
    nouveau->destination = v;
    nouveau->poids = poids;
    nouveau->suivant = g->adjacence[u];
    g->adjacence[u] = nouveau;
}

// Ajouter une arête non-orientée
void ajouter_arete_non_orientee(Graphe* g, int u, int v, int poids) {
    ajouter_arete(g, u, v, poids);
    ajouter_arete(g, v, u, poids);
}

// Vérifier si une arête existe
int existe_arete_liste(Graphe* g, int u, int v) {
    Voisin* courant = g->adjacence[u];
    while (courant != NULL) {
        if (courant->destination == v) {
            return 1;
        }
        courant = courant->suivant;
    }
    return 0;
}

// Obtenir le poids d'une arête
int obtenir_poids(Graphe* g, int u, int v) {
    Voisin* courant = g->adjacence[u];
    while (courant != NULL) {
        if (courant->destination == v) {
            return courant->poids;
        }
        courant = courant->suivant;
    }
    return -1;  // Arête inexistante
}

// Parcourir les voisins
void parcourir_voisins_liste(Graphe* g, int u) {
    Voisin* courant = g->adjacence[u];
    while (courant != NULL) {
        printf("Arête de %d vers %d avec poids %d\n", 
               u, courant->destination, courant->poids);
        courant = courant->suivant;
    }
}

// Afficher le graphe complet
void afficher_graphe(Graphe* g) {
    for (int u = 0; u < g->nbNoeuds; u++) {
        printf("Nœud %d: ", u);
        Voisin* courant = g->adjacence[u];
        while (courant != NULL) {
            printf("-> %d (poids %d) ", 
                   courant->destination, courant->poids);
            courant = courant->suivant;
        }
        printf("\n");
    }
}

// Calculer le degré sortant
int degre_sortant(Graphe* g, int u) {
    int degre = 0;
    Voisin* courant = g->adjacence[u];
    while (courant != NULL) {
        degre++;
        courant = courant->suivant;
    }
    return degre;
}

// Libérer la mémoire
void liberer_graphe(Graphe* g) {
    for (int i = 0; i < g->nbNoeuds; i++) {
        Voisin* courant = g->adjacence[i];
        while (courant != NULL) {
            Voisin* temp = courant;
            courant = courant->suivant;
            free(temp);
        }
    }
    free(g->adjacence);
    free(g);
}
Implémentation avec tableaux dynamiques
ctypedef struct {
    int* voisins;
    int* poids;
    int taille;      // Nombre actuel de voisins
    int capacite;    // Capacité allouée
} ListeVoisinsArray;

typedef struct {
    int nbNoeuds;
    ListeVoisinsArray* adjacence;
} GrapheArray;

GrapheArray* creer_graphe_array(int n) {
    GrapheArray* g = malloc(sizeof(GrapheArray));
    g->nbNoeuds = n;
    g->adjacence = malloc(n * sizeof(ListeVoisinsArray));
    
    for (int i = 0; i < n; i++) {
        g->adjacence[i].capacite = 4;
        g->adjacence[i].taille = 0;
        g->adjacence[i].voisins = malloc(4 * sizeof(int));
        g->adjacence[i].poids = malloc(4 * sizeof(int));
    }
    
    return g;
}

void ajouter_voisin_array(GrapheArray* g, int u, int v, int poids) {
    ListeVoisinsArray* liste = &g->adjacence[u];
    
    // Vérifier si on doit agrandir
    if (liste->taille == liste->capacite) {
        liste->capacite *= 2;
        liste->voisins = realloc(liste->voisins, 
                                 liste->capacite * sizeof(int));
        liste->poids = realloc(liste->poids, 
                              liste->capacite * sizeof(int));
    }
    
    liste->voisins[liste->taille] = v;
    liste->poids[liste->taille] = poids;
    liste->taille++;
}

void parcourir_voisins_array(GrapheArray* g, int u) {
    ListeVoisinsArray* liste = &g->adjacence[u];
    for (int i = 0; i < liste->taille; i++) {
        printf("Arête de %d vers %d avec poids %d\n", 
               u, liste->voisins[i], liste->poids[i]);
    }
}
```
**Complexité :**
Espace : O(n + m) où n = |V| et m = |E|
**Opérations :**
- Vérifier si (u, v) existe : O(deg(u))
- Obtenir le poids de (u, v) : O(deg(u))
- Parcourir tous les voisins de u : O(deg(u))
- Ajouter une arête : O(1) amorti
- Supprimer une arête : O(deg(u))
- Parcourir toutes les arêtes : O(n + m)
**Avantages :**
- Économie de mémoire pour les graphes creux
- Efficace pour parcourir les voisins
- Adapté aux graphes de grande taille
- Représentation naturelle pour les algorithmes de parcours
**Inconvénients :**
- Vérification d'adjacence plus lente que la matrice
- Gestion de la mémoire plus complexe
- Suppression d'arêtes moins efficace
**Quand utiliser :**
- Graphes creux (|E| << n²)
- Grands graphes (n > 1000)
- Algorithmes de parcours (BFS, DFS)
- Économie de mémoire prioritaire
- Applications réelles (réseaux sociaux, web, etc.)

### 6.4 Comparaison et choix
#### Densité du graphe
La densité d'un graphe est le ratio : d = |E| / (n(n-1)/2) pour un graphe non-orienté.
- d ~= 1 : graphe dense -> matrice d'adjacence
- d << 1 : graphe creux -> liste d'adjacence

#### Tableau comparatif
| Critère 			| Matrice| Liste chaînée | Liste array  | 
|-------------------|--------|---------------|--------------|
| Espace 			| O(n²)  | O(n + m) 	 | O(n + m)		| 
| Existence arête 	| O(1) 	 | O(deg) 		 | O(deg) 		| 
| Parcourir voisins | O(n) 	 | O(deg) 		 | O(deg) 		| 
| Ajouter arête 	| O(1) 	 | O(1) 		 | O(1) amorti 	| 
| Supprimer arête 	| O(1) 	 | O(deg) 		 | O(deg) 		| 
| Cache-friendly 	| Non 	 | Faible 		 | Oui 			| 
| Complexité code 	| Simple | Moyenne 		 | Moyenne 		| 

#### Recommandations pratiques
**Matrice d'adjacence :**
- n < 1000 et graphe dense
- Vérifications d'adjacence fréquentes
- Algorithmes matriciels (Floyd-Warshall, etc.)
**Liste d'adjacence avec tableaux :**
- Cas général, surtout si n > 1000
- Performance moderne (cache CPU)
- Compromis équilibré
**Liste d'adjacence chaînée :**
- Insertions/suppressions très fréquentes
- Cas académique ou pédagogique

### 6.5 Application au système de messagerie
Pour notre système de messagerie entre Jacky, Aymard et Faris :
**Choix :** 
- Matrice d'adjacence avec structure multi-attributs
**Justification :**
- 3 nœuds seulement : 3 × 3 = 9 cases
- Graphe probablement dense (communication entre tous)
- Accès direct pour statistiques
- Simplicité d'implémentation

**Implémentation complète :**
```
#include <stdio.h>
#include <string.h>
#include <time.h>

#define JACKY 0
#define AYMARD 1
#define FARIS 2
#define NB_USERS 3

// Structure pour les statistiques d'une relation
typedef struct {
    int nbMessages;
    int nbCaracteres;
    int nbPhotos;
    int nbEmojis;
    float moyenneCaracteres;
    time_t dernierMessage;
} StatistiquesRelation;

// Structure du réseau
typedef struct {
    StatistiquesRelation stats[NB_USERS][NB_USERS];
} ReseauMessaging;

// Initialiser le réseau
void initialiser_reseau(ReseauMessaging* r) {
    for (int i = 0; i < NB_USERS; i++) {
        for (int j = 0; j < NB_USERS; j++) {
            r->stats[i][j].nbMessages = 0;
            r->stats[i][j].nbCaracteres = 0;
            r->stats[i][j].nbPhotos = 0;
            r->stats[i][j].nbEmojis = 0;
            r->stats[i][j].moyenneCaracteres = 0.0;
r->stats[i][j].dernierMessage = 0;
}
}
}
// Envoyer un message
void envoyer_message(ReseauMessaging* r, int expediteur, int destinataire,
int longueur, int nbEmojis, int estPhoto) {
StatistiquesRelation* stat = &r->stats[expediteur][destinataire];
stat->nbMessages++;
stat->nbCaracteres += longueur;
stat->nbEmojis += nbEmojis;
if (estPhoto) stat->nbPhotos++;
stat->dernierMessage = time(NULL);

// Recalculer la moyenne
stat->moyenneCaracteres = (float)stat->nbCaracteres / stat->nbMessages;
}
// Afficher les statistiques d'une relation
void afficher_relation(ReseauMessaging* r, int u, int v) {
char* noms[] = {"Jacky", "Aymard", "Faris"};
StatistiquesRelation* s = &r->stats[u][v];
if (s->nbMessages > 0) {
    printf("\n%s -> %s\n", noms[u], noms[v]);
    printf("  Messages : %d\n", s->nbMessages);
    printf("  Caracteres : %d (moy. %.1f/msg)\n", 
           s->nbCaracteres, s->moyenneCaracteres);
    printf("  Photos : %d\n", s->nbPhotos);
    printf("  Emojis : %d\n", s->nbEmojis);
}
}
// Calculer le degré sortant (messages envoyés)
int degre_sortant_messages(ReseauMessaging* r, int u) {
int total = 0;
for (int v = 0; v < NB_USERS; v++) {
total += r->stats[u][v].nbMessages;
}
return total;
}
// Calculer le degré entrant (messages reçus)
int degre_entrant_messages(ReseauMessaging* r, int u) {
int total = 0;
for (int v = 0; v < NB_USERS; v++) {
total += r->stats[v][u].nbMessages;
}
return total;
}
// Calculer la réciprocité entre deux utilisateurs
float reciprocite(ReseauMessaging* r, int u, int v) {
int uv = r->stats[u][v].nbMessages;
int vu = r->stats[v][u].nbMessages;
if (uv == 0 && vu == 0) return 0.0;

int min = (uv < vu) ? uv : vu;
int max = (uv > vu) ? uv : vu;

return (float)min / max;
}
// Trouver l'utilisateur le plus actif
int utilisateur_plus_actif(ReseauMessaging* r) {
int maxMessages = 0;
int plusActif = 0;
for (int i = 0; i < NB_USERS; i++) {
    int messages = degre_sortant_messages(r, i);
    if (messages > maxMessages) {
        maxMessages = messages;
        plusActif = i;
    }
}

return plusActif;
}
// Afficher le rapport complet
void generer_rapport(ReseauMessaging* r) {
char* noms[] = {"Jacky", "Aymard", "Faris"};
printf("\n========================================\n");
printf("RAPPORT DU RESEAU DE MESSAGERIE\n");
printf("========================================\n");

printf("\nRELATIONS:\n");
for (int i = 0; i < NB_USERS; i++) {
    for (int j = 0; j < NB_USERS; j++) {
        if (i != j) {
            afficher_relation(r, i, j);
        }
    }
}

printf("\nACTIVITE PAR UTILISATEUR:\n");
for (int i = 0; i < NB_USERS; i++) {
    printf("%s:\n", noms[i]);
    printf("  Messages envoyes: %d\n", degre_sortant_messages(r, i));
    printf("  Messages recus: %d\n", degre_entrant_messages(r, i));
}

printf("\nRECIPROCITE:\n");
for (int i = 0; i < NB_USERS; i++) {
    for (int j = i + 1; j < NB_USERS; j++) {
        float rec = reciprocite(r, i, j);
        printf("%s <-> %s: %.2f\n", noms[i], noms[j], rec);
    }
}

int plusActif = utilisateur_plus_actif(r);
printf("\nUtilisateur le plus actif: %s\n", noms[plusActif]);
}
// Programme principal
int main() {
ReseauMessaging reseau;
initialiser_reseau(&reseau);
// Simulation de conversations
envoyer_message(&reseau, JACKY, AYMARD, 25, 2, 0);
envoyer_message(&reseau, JACKY, AYMARD, 150, 5, 0);
envoyer_message(&reseau, JACKY, AYMARD, 0, 0, 1);

envoyer_message(&reseau, AYMARD, JACKY, 18, 1, 0);
envoyer_message(&reseau, AYMARD, JACKY, 200, 8, 0);

envoyer_message(&reseau, FARIS, AYMARD, 30, 3, 0);
envoyer_message(&reseau, AYMARD, FARIS, 45, 2, 0);
envoyer_message(&reseau, FARIS, JACKY, 0, 0, 1);

generer_rapport(&reseau);

return 0;
}
```
---

## 7. Propriétés avancées des arêtes

### 7.1 Poids multiples : théorie et pratique

#### Motivation

Dans les applications réelles, une relation entre deux entités possède rarement une seule dimension. Un poids unique est une simplification souvent insuffisante.

Exemples :
- Une route : distance, temps, péage, trafic, qualité
- Une connexion réseau : latence, bande passante, fiabilité, coût
- Une relation sociale : nombre d'interactions, durée, intensité, type

#### Formalisation

Soit G = (V, E) un graphe. Au lieu d'une fonction de poids w : E -> R, on définit :

w : E -> R^k

où k est le nombre de dimensions de poids.

Pour une arête e, w(e) = (w1(e), w2(e), ..., wk(e))

#### Agrégation de poids

Lorsqu'on cherche le "meilleur" chemin, il faut définir une fonction d'agrégation :

**Somme pondérée** : f(w) = a1w1 + a2w2 + ... + akwk

**Optimisation multi-objectifs** : Trouver les solutions Pareto-optimales

**Approche lexicographique** : Ordonner les critères par priorité

### 7.2 Implémentation des poids multiples

#### Approche 1 : Matrices multiples
```
#define N 100

typedef struct {
    int distance[N][N];
    float temps[N][N];
    float cout[N][N];
    float trafic[N][N];
} GrapheRoutier;

// Initialiser
void init_graphe_routier(GrapheRoutier* g) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            g->distance[i][j] = INF;
            g->temps[i][j] = INF;
            g->cout[i][j] = INF;
            g->trafic[i][j] = 0;
        }
    }
}

// Ajouter une route
void ajouter_route(GrapheRoutier* g, int u, int v,
                   int dist, float temps, float cout, float trafic) {
    g->distance[u][v] = dist;
    g->temps[u][v] = temps;
    g->cout[u][v] = cout;
    g->trafic[u][v] = trafic;
}

// Calculer le coût composite
float cout_composite(GrapheRoutier* g, int u, int v,
                     float alpha_dist, float alpha_temps, float alpha_cout) {
    float dist_norm = g->distance[u][v] / 1000.0;  // Normaliser
    float temps_norm = g->temps[u][v] / 60.0;
    float cout_norm = g->cout[u][v] / 100.0;
    
    return alpha_dist * dist_norm + 
           alpha_temps * temps_norm + 
           alpha_cout * cout_norm;
}
```

#### Approche 2 : Structure dans la matrice
```
#define N 100

typedef struct {
    int distance;      // km
    float temps;       // minutes
    float cout;        // euros
    float trafic;      // 0-1 (intensité)
    int peage;         // booléen
    char type[20];     // "autoroute", "nationale", etc.
} InfosRoute;

typedef struct {
    InfosRoute routes[N][N];
    int existe[N][N];  // Matrice booléenne d'existence
} GrapheRoutierStruct;

void init_graphe_struct(GrapheRoutierStruct* g) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            g->existe[i][j] = 0;
        }
    }
}

void ajouter_route_struct(GrapheRoutierStruct* g, int u, int v,
                          InfosRoute infos) {
    g->routes[u][v] = infos;
    g->existe[u][v] = 1;
}

// Obtenir les infos complètes
InfosRoute* obtenir_route(GrapheRoutierStruct* g, int u, int v) {
    if (g->existe[u][v]) {
        return &g->routes[u][v];
    }
    return NULL;
}
```

#### Approche 3 : Liste d'adjacence avec structure
```
typedef struct {
    int distance;
    float temps;
    float cout;
    float trafic;
} PoidsMultiples;

typedef struct Arete {
    int destination;
    PoidsMultiples poids;
    struct Arete* suivante;
} Arete;

typedef struct {
    int nbNoeuds;
    Arete** adjacence;
} GrapheMultiPoids;

GrapheMultiPoids* creer_graphe_multi(int n) {
    GrapheMultiPoids* g = malloc(sizeof(GrapheMultiPoids));
    g->nbNoeuds = n;
    g->adjacence = calloc(n, sizeof(Arete*));
    return g;
}

void ajouter_arete_multi(GrapheMultiPoids* g, int u, int v,
                         PoidsMultiples poids) {
    Arete* nouvelle = malloc(sizeof(Arete));
    nouvelle->destination = v;
    nouvelle->poids = poids;
    nouvelle->suivante = g->adjacence[u];
    g->adjacence[u] = nouvelle;
}

// Rechercher une arête avec tous ses poids
PoidsMultiples* obtenir_poids_multi(GrapheMultiPoids* g, int u, int v) {
    Arete* courant = g->adjacence[u];
    while (courant != NULL) {
        if (courant->destination == v) {
            return &courant->poids;
        }
        courant = courant->suivante;
    }
    return NULL;
}
```

### 7.3 Algorithmes avec poids multiples

#### Plus court chemin avec contraintes

Trouver le chemin le plus court en distance, mais avec temps < T_max et coût < C_max.
```
typedef struct {
    int distance;
    float temps;
    float cout;
} Chemin;

// Structure pour Dijkstra modifié
typedef struct {
    int noeud;
    Chemin chemin;
} ElementFile;

int chemin_valide(Chemin c, float temps_max, float cout_max) {
    return c.temps <= temps_max && c.cout <= cout_max;
}

Chemin combiner_chemins(Chemin c, PoidsMultiples p) {
    Chemin nouveau;
    nouveau.distance = c.distance + p.distance;
    nouveau.temps = c.temps + p.temps;
    nouveau.cout = c.cout + p.cout;
    return nouveau;
}
```

#### Optimisation Pareto

Un chemin est Pareto-optimal s'il n'existe pas d'autre chemin meilleur sur tous les critères simultanément.
```
int domine(Chemin a, Chemin b) {
    // a domine b si a est meilleur ou égal sur tous les critères
    // et strictement meilleur sur au moins un
    int meilleur_distance = a.distance <= b.distance;
    int meilleur_temps = a.temps <= b.temps;
    int meilleur_cout = a.cout <= b.cout;
    
    int strictement_meilleur = (a.distance < b.distance) ||
                               (a.temps < b.temps) ||
                               (a.cout < b.cout);
    
    return meilleur_distance && meilleur_temps && 
           meilleur_cout && strictement_meilleur;
}

// Maintenir un ensemble de solutions Pareto-optimales
typedef struct {
    Chemin* chemins;
    int taille;
    int capacite;
} EnsemblePareto;

void ajouter_si_non_domine(EnsemblePareto* ensemble, Chemin nouveau) {
    // Vérifier si le nouveau chemin est dominé
    for (int i = 0; i < ensemble->taille; i++) {
        if (domine(ensemble->chemins[i], nouveau)) {
            return;  // Dominé, ne pas ajouter
        }
    }
    
    // Supprimer les chemins dominés par le nouveau
    int j = 0;
    for (int i = 0; i < ensemble->taille; i++) {
        if (!domine(nouveau, ensemble->chemins[i])) {
            ensemble->chemins[j++] = ensemble->chemins[i];
        }
    }
    ensemble->taille = j;
    
    // Ajouter le nouveau chemin
    if (ensemble->taille == ensemble->capacite) {
        ensemble->capacite *= 2;
        ensemble->chemins = realloc(ensemble->chemins,
                                   ensemble->capacite * sizeof(Chemin));
    }
    ensemble->chemins[ensemble->taille++] = nouveau;
}
```

---

## 8. Algorithmes et complexité

### 8.1 Parcours de graphes

#### Parcours en largeur (BFS - Breadth-First Search)

**Principe** : Explorer tous les voisins d'un nœud avant d'explorer leurs voisins.

**Analogie** : Comme des ondes qui se propagent dans l'eau.

**Applications** :
- Trouver le plus court chemin (graphe non-pondéré)
- Vérifier la connexité
- Trouver la distance minimale entre deux nœuds

**Implémentation** :
```
#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef struct {
    int elements[N];
    int debut;
    int fin;
} File;

void init_file(File* f) {
    f->debut = 0;
    f->fin = 0;
}

int file_vide(File* f) {
    return f->debut == f->fin;
}

void enfiler(File* f, int valeur) {
    f->elements[f->fin++] = valeur;
}

int defiler(File* f) {
    return f->elements[f->debut++];
}

void BFS(int graphe[N][N], int n, int depart) {
    int visite[N] = {0};
    int distance[N];
    int parent[N];
    
    for (int i = 0; i < n; i++) {
        distance[i] = -1;
        parent[i] = -1;
    }
    
    File f;
    init_file(&f);
    
    visite[depart] = 1;
    distance[depart] = 0;
    enfiler(&f, depart);
    
    while (!file_vide(&f)) {
        int u = defiler(&f);
        printf("Visite du noeud %d\n", u);
        
        for (int v = 0; v < n; v++) {
            if (graphe[u][v] && !visite[v]) {
                visite[v] = 1;
                distance[v] = distance[u] + 1;
                parent[v] = u;
                enfiler(&f, v);
            }
        }
    }
    
    printf("\nDistances depuis %d:\n", depart);
    for (int i = 0; i < n; i++) {
        if (distance[i] != -1) {
            printf("Noeud %d: distance %d\n", i, distance[i]);
        }
    }
}
```

**Complexité** :
- Temps : O(|V| + |E|) avec liste d'adjacence, O(|V|²) avec matrice
- Espace : O(|V|) pour la file et les tableaux auxiliaires

#### Parcours en profondeur (DFS - Depth-First Search)

**Principe** : Explorer le plus profondément possible avant de revenir en arrière.

**Analogie** : Comme explorer un labyrinthe en allant toujours tout droit jusqu'au bout.

**Applications** :
- Détecter les cycles
- Tri topologique (DAG)
- Trouver les composantes fortement connexes
- Résoudre des labyrinthes

**Implémentation récursive** :
```
void DFS_recursif(int graphe[N][N], int n, int u, int visite[N]) {
    visite[u] = 1;
    printf("Visite du noeud %d\n", u);
    
    for (int v = 0; v < n; v++) {
        if (graphe[u][v] && !visite[v]) {
            DFS_recursif(graphe, n, v, visite);
        }
    }
}

void DFS(int graphe[N][N], int n, int depart) {
    int visite[N] = {0};
    DFS_recursif(graphe, n, depart, visite);
}
```

**Implémentation itérative** :
```
typedef struct {
    int elements[N];
    int sommet;
} Pile;

void init_pile(Pile* p) {
    p->sommet = -1;
}

int pile_vide(Pile* p) {
    return p->sommet == -1;
}

void empiler(Pile* p, int valeur) {
    p->elements[++p->sommet] = valeur;
}

int depiler(Pile* p) {
    return p->elements[p->sommet--];
}

void DFS_iteratif(int graphe[N][N], int n, int depart) {
    int visite[N] = {0};
    Pile p;
    init_pile(&p);
    
    empiler(&p, depart);
    
    while (!pile_vide(&p)) {
        int u = depiler(&p);
        
        if (!visite[u]) {
            visite[u] = 1;
            printf("Visite du noeud %d\n", u);
            
            for (int v = n - 1; v >= 0; v--) {
                if (graphe[u][v] && !visite[v]) {
                    empiler(&p, v);
                }
            }
        }
    }
}
```

**Complexité** : Identique à BFS : O(|V| + |E|)

### 8.2 Plus courts chemins

#### Algorithme de Dijkstra

**Problème** : Trouver le plus court chemin depuis une source vers tous les autres nœuds dans un graphe avec poids positifs.

**Principe** : Exploration gloutonne en sélectionnant toujours le nœud non visité le plus proche.

**Implémentation** :
```
#define INF 999999

void dijkstra(int graphe[N][N], int n, int source, 
              int distance[], int parent[]) {
    int visite[N] = {0};
    
    for (int i = 0; i < n; i++) {
        distance[i] = INF;
        parent[i] = -1;
    }
    
    distance[source] = 0;
    
    for (int count = 0; count < n - 1; count++) {
        // Trouver le nœud non visité avec la plus petite distance
        int min = INF;
        int u = -1;
        
        for (int v = 0; v < n; v++) {
            if (!visite[v] && distance[v] < min) {
                min = distance[v];
                u = v;
            }
        }
        
        if (u == -1) break;  // Plus de nœuds accessibles
        
        visite[u] = 1;
        
        // Mettre à jour les distances des voisins
        for (int v = 0; v < n; v++) {
            if (!visite[v] && graphe[u][v] && 
                distance[u] != INF &&
                distance[u] + graphe[u][v] < distance[v]) {
                distance[v] = distance[u] + graphe[u][v];
                parent[v] = u;
            }
        }
    }
}

void afficher_chemin(int parent[], int destination) {
    if (parent[destination] == -1) {
        printf("%d ", destination);
        return;
    }
    
    afficher_chemin(parent, parent[destination]);
    printf("-> %d ", destination);
}
```

**Complexité** :
- Version naïve : O(|V|²)
- Avec tas binaire : O((|V| + |E|) log |V|)
- Avec tas de Fibonacci : O(|E| + |V| log |V|)

**Limitation** : Ne fonctionne pas avec des poids négatifs.

#### Algorithme de Bellman-Ford

**Avantage** : Fonctionne même avec des poids négatifs et détecte les cycles de poids négatif.

**Principe** : Relaxation itérative de toutes les arêtes.
```
int bellman_ford(int graphe[N][N], int n, int source, 
                 int distance[], int parent[]) {
    for (int i = 0; i < n; i++) {
        distance[i] = INF;
        parent[i] = -1;
    }
    
    distance[source] = 0;
    
    // Relaxer toutes les arêtes |V| - 1 fois
    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (graphe[u][v] && distance[u] != INF &&
                    distance[u] + graphe[u][v] < distance[v]) {
                    distance[v] = distance[u] + graphe[u][v];
                    parent[v] = u;
                }
            }
        }
    }
    
    // Vérifier les cycles de poids négatif
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (graphe[u][v] && distance[u] != INF &&
                distance[u] + graphe[u][v] < distance[v]) {
                return 0;  // Cycle négatif détecté
            }
        }
    }
    
    return 1;  // Pas de cycle négatif
}
```

**Complexité** : O(|V| × |E|)

#### Algorithme de Floyd-Warshall

**Problème** : Trouver les plus courts chemins entre toutes les paires de nœuds.

**Principe** : Programmation dynamique avec tous les nœuds comme intermédiaires potentiels.
```c
void floyd_warshall(int graphe[N][N], int n, 
                    int distance[N][N], int suivant[N][N]) {
    // Initialisation
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            distance[i][j] = graphe[i][j];
            if (graphe[i][j] != INF && i != j) {
                suivant[i][j] = j;
            } else {
                suivant[i][j] = -1;
            }
        }
    }
    
    // Algorithme principal
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (distance[i][k] != INF && 
                    distance[k][j] != INF &&
                    distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                    suivant[i][j] = suivant[i][k];
                }
            }
        }
    }
}

void reconstruire_chemin(int suivant[N][N], int u, int v) {
    if (suivant[u][v] == -1) {
        printf("Pas de chemin\n");
        return;
    }
    
    printf("%d ", u);
    while (u != v) {
        u = suivant[u][v];
        printf("-> %d ", u);
    }
    printf("\n");
}
```

**Complexité** : O(|V|³)

**Avantage** : Simple et trouve tous les chemins. Fonctionne avec poids négatifs.

### 8.3 Arbres couvrants minimaux

#### Problème

Étant donné un graphe connexe pondéré, trouver un sous-ensemble d'arêtes qui :
- Connecte tous les sommets
- A un poids total minimal
- Forme un arbre (pas de cycles)

**Applications** : Conception de réseaux (télécommunications, routes, câblage).

#### Algorithme de Kruskal

**Principe** : Trier les arêtes par poids croissant et les ajouter si elles ne créent pas de cycle.
```
typedef struct {
    int u, v;
    int poids;
} Arete;

// Structure Union-Find pour détection de cycles
typedef struct {
    int parent[N];
    int rang[N];
} UnionFind;

void init_union_find(UnionFind* uf, int n) {
    for (int i = 0; i < n; i++) {
        uf->parent[i] = i;
        uf->rang[i] = 0;
    }
}

int find(UnionFind* uf, int x) {
    if (uf->parent[x] != x) {
        uf->parent[x] = find(uf, uf->parent[x]);  // Compression
    }
    return uf->parent[x];
}

void union_sets(UnionFind* uf, int x, int y) {
    int rx = find(uf, x);
    int ry = find(uf, y);
    
    if (rx == ry) return;
    
    if (uf->rang[rx] < uf->rang[ry]) {
        uf->parent[rx] = ry;
    } else if (uf->rang[rx] > uf->rang[ry]) {
        uf->parent[ry] = rx;
    } else {
        uf->parent[ry] = rx;
        uf->rang[rx]++;
    }
}

int comparer_aretes(const void* a, const void* b) {
    return ((Arete*)a)->poids - ((Arete*)b)->poids;
}

int kruskal(Arete aretes[], int m, int n, Arete resultat[]) {
    qsort(aretes, m, sizeof(Arete), comparer_aretes);
    
    UnionFind uf;
    init_union_find(&uf, n);
    
    int nb_aretes = 0;
    int poids_total = 0;
    
    for (int i = 0; i < m && nb_aretes < n - 1; i++) {
        int u = aretes[i].u;
        int v = aretes[i].v;
        
        if (find(&uf, u) != find(&uf, v)) {
            resultat[nb_aretes++] = aretes[i];
            poids_total += aretes[i].poids;
            union_sets(&uf, u, v);
        }
    }
    
    return poids_total;
}
```

**Complexité** : O(|E| log |E|) dominé par le tri

#### Algorithme de Prim

**Principe** : Construire l'arbre en ajoutant à chaque étape l'arête de poids minimal connectant l'arbre à un nouveau sommet.
```
int prim(int graphe[N][N], int n, Arete resultat[]) {
    int dans_arbre[N] = {0};
    int cle[N];
    int parent[N];
    
    for (int i = 0; i < n; i++) {
        cle[i] = INF;
        parent[i] = -1;
    }
    
    cle[0] = 0;
    int poids_total = 0;
    int nb_aretes = 0;
    
    for (int count = 0; count < n; count++) {
        int u = -1;
        int min = INF;
        
        for (int v = 0; v < n; v++) {
            if (!dans_arbre[v] && cle[v] < min) {
                min = cle[v];
u = v;
}
}
    if (u == -1) break;
    
    dans_arbre[u] = 1;
    
    if (parent[u] != -1) {
        resultat[nb_aretes].u = parent[u];
        resultat[nb_aretes].v = u;
        resultat[nb_aretes].poids = cle[u];
        nb_aretes++;
        poids_total += cle[u];
    }
    
    for (int v = 0; v < n; v++) {
        if (graphe[u][v] && !dans_arbre[v] && 
            graphe[u][v] < cle[v]) {
            parent[v] = u;
            cle[v] = graphe[u][v];
        }
    }
}

return poids_total;
}
```
**Complexité** : O(|V|²) ou O(|E| log |V|) avec tas

### 8.4 Détection de cycles

#### Graphe non-orienté (DFS)
```
int detecter_cycle_non_oriente_util(int graphe[N][N], int n, 
                                     int u, int visite[], int parent) {
    visite[u] = 1;
    
    for (int v = 0; v < n; v++) {
        if (graphe[u][v]) {
            if (!visite[v]) {
                if (detecter_cycle_non_oriente_util(graphe, n, v, visite, u)) {
                    return 1;
                }
            } else if (v != parent) {
                return 1;  // Cycle détecté
            }
        }
    }
    
    return 0;
}

int detecter_cycle_non_oriente(int graphe[N][N], int n) {
    int visite[N] = {0};
    
    for (int i = 0; i < n; i++) {
        if (!visite[i]) {
            if (detecter_cycle_non_oriente_util(graphe, n, i, visite, -1)) {
                return 1;
            }
        }
    }
    
    return 0;
}
```

#### Graphe orienté (DFS avec pile de récursion)
```
int detecter_cycle_oriente_util(int graphe[N][N], int n,
                                int u, int visite[], int pile_rec[]) {
    visite[u] = 1;
    pile_rec[u] = 1;
    
    for (int v = 0; v < n; v++) {
        if (graphe[u][v]) {
            if (!visite[v]) {
                if (detecter_cycle_oriente_util(graphe, n, v, visite, pile_rec)) {
                    return 1;
                }
            } else if (pile_rec[v]) {
                return 1;  // Cycle détecté
            }
        }
    }
    
    pile_rec[u] = 0;
    return 0;
}

int detecter_cycle_oriente(int graphe[N][N], int n) {
    int visite[N] = {0};
    int pile_rec[N] = {0};
    
    for (int i = 0; i < n; i++) {
        if (!visite[i]) {
            if (detecter_cycle_oriente_util(graphe, n, i, visite, pile_rec)) {
                return 1;
            }
        }
    }
    
    return 0;
}
```

### 8.5 Tri topologique

**Problème** : Ordonner les sommets d'un DAG tel que pour chaque arête u -> v, u apparaît avant v.

**Applications** : Ordonnancement de tâches, résolution de dépendances, compilation.
```
void tri_topologique_util(int graphe[N][N], int n, 
                          int u, int visite[], int pile[], int* sommet) {
    visite[u] = 1;
    
    for (int v = 0; v < n; v++) {
        if (graphe[u][v] && !visite[v]) {
            tri_topologique_util(graphe, n, v, visite, pile, sommet);
        }
    }
    
    pile[(*sommet)++] = u;
}

void tri_topologique(int graphe[N][N], int n) {
    int visite[N] = {0};
    int pile[N];
    int sommet = 0;
    
    for (int i = 0; i < n; i++) {
        if (!visite[i]) {
            tri_topologique_util(graphe, n, i, visite, pile, &sommet);
        }
    }
    
    printf("Ordre topologique: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", pile[i]);
    }
    printf("\n");
}
```

**Complexité** : O(|V| + |E|)

### 8.6 Composantes fortement connexes (Kosaraju)

**Définition** : Dans un graphe orienté, une composante fortement connexe est un sous-ensemble maximal de sommets tel que chaque sommet est accessible depuis tous les autres.
```
void remplir_ordre(int graphe[N][N], int n, int u, 
                   int visite[], int pile[], int* sommet) {
    visite[u] = 1;
    
    for (int v = 0; v < n; v++) {
        if (graphe[u][v] && !visite[v]) {
            remplir_ordre(graphe, n, v, visite, pile, sommet);
        }
    }
    
    pile[(*sommet)++] = u;
}

void DFS_composante(int graphe_transpose[N][N], int n, 
                    int u, int visite[]) {
    visite[u] = 1;
    printf("%d ", u);
    
    for (int v = 0; v < n; v++) {
        if (graphe_transpose[u][v] && !visite[v]) {
            DFS_composante(graphe_transpose, n, v, visite);
        }
    }
}

void kosaraju(int graphe[N][N], int n) {
    int pile[N];
    int sommet = 0;
    int visite[N] = {0};
    
    // Première passe: remplir la pile
    for (int i = 0; i < n; i++) {
        if (!visite[i]) {
            remplir_ordre(graphe, n, i, visite, pile, &sommet);
        }
    }
    
    // Créer le graphe transposé
    int graphe_transpose[N][N] = {0};
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (graphe[u][v]) {
                graphe_transpose[v][u] = 1;
            }
        }
    }
    
    // Deuxième passe: trouver les composantes
    for (int i = 0; i < n; i++) {
        visite[i] = 0;
    }
    
    printf("Composantes fortement connexes:\n");
    while (sommet > 0) {
        int u = pile[--sommet];
        if (!visite[u]) {
            DFS_composante(graphe_transpose, n, u, visite);
            printf("\n");
        }
    }
}
```

**Complexité** : O(|V| + |E|)

---

## Conclusion

La théorie des graphes est un domaine fondamental des mathématiques et de l'informatique qui modélise les relations entre entités. De l'histoire des ponts de Königsberg aux réseaux sociaux modernes, les graphes sont omniprésents.

Les concepts clés incluent les nœuds, arêtes, poids, connexité et degré. Les deux principales représentations en mémoire sont la matrice d'adjacence (pour les graphes denses et petits) et la liste d'adjacence (pour les graphes creux et grands).

Les algorithmes de graphes résolvent des problèmes pratiques : trouver le plus court chemin (Dijkstra, Bellman-Ford, Floyd-Warshall), construire des réseaux optimaux (Kruskal, Prim), ordonnancer des tâches (tri topologique), et analyser la structure de réseaux (composantes connexes).

La richesse de la théorie des graphes réside dans sa capacité à abstraire et résoudre des problèmes complexes du monde réel par des modèles mathématiques élégants et des algorithmes efficaces.