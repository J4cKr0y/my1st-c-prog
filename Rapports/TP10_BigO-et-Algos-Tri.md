# Complexité Temporelle et Spatiale
=================================

Imagine que Jacky et Aymard doivent ranger leur chambre :

**Complexité temporelle** = le temps que ça prend

*   Jacky range ses 10 jeux vidéo en 5 minutes
*   Si demain il a 20 jeux, ça lui prendra 10 minutes
*   Plus il a de trucs, plus ça prend de temps !

**Complexité spatiale** = la place dont on a besoin

*   Faris range ses livres : il les met directement sur l'étagère → peu d'espace nécessaire
*   Magaly range les siens : elle les étale TOUS par terre d'abord, puis les remet → beaucoup d'espace !

En informatique, c'est pareil : certains algorithmes sont rapides mais gourmands en mémoire, d'autres sont lents mais économes.

Pour les matheux : 

**Complexité temporelle** : Mesure quantitative du nombre d'opérations élémentaires exécutées par un algorithme en fonction de la taille de l'entrée _n_. 
Elle caractérise l'évolution du temps d'exécution. On distingue :

*   Cas optimal (best case)
*   Cas moyen (average case)
*   Cas pessimal (worst case)

**Complexité spatiale** : Quantité de mémoire requise par l'algorithme, exprimée en fonction de _n_. Elle inclut :

*   L'espace pour les variables
*   La pile d'appels récursifs éventuelle
*   Les structures de données temporaires

On exclut généralement l'espace occupé par les données d'entrée elles-mêmes.

* * *

# Notation Big O
==============

## Version simple : 

Big O, c'est comme une étiquette qui dit "à quelle vitesse ça ralentit quand on a plus de travail".

Imagine Aymard qui compte des bonbons :

*   **O(1)** : Peu importe combien il y a de bonbons, il en prend juste un du haut -> super rapide, toujours pareil
*   **O(n)** : Il doit tous les compter un par un -> 10 bonbons = 10 secondes, 100 bonbons = 100 secondes
*   **O(n²)** : Il doit comparer chaque bonbon avec tous les autres -> 10 bonbons = 100 comparaisons, 100 bonbons = 10 000 comparaisons ! 😱

Plus le chiffre est gros dans le O(), plus c'est lent quand on a beaucoup de données.

## Version pro : 

La notation Big O (notation de Landau) exprime la borne supérieure de la complexité d'un algorithme. Formellement :

**f(n) = O(g(n))** ssi ∃c > 0, ∃n₀ > 0 : ∀n ≥ n₀, f(n) ≤ c·g(n)

*Oulala, je vois des oreilles qui fument! X-D*

### Explication en détail 

Imagine que tu fais la course avec Jacky :

La formule dit juste : "À partir d'un certain moment, ton temps sera toujours inférieur ou égal au temps de Jacky multiplié par un nombre fixe"


- Exemple concret :
Toi : tu mets 2n + 10 secondes pour ranger n livres
Jacky : il met n secondes par livre

La formule dit : "À partir d'un certain nombre de livres (disons 20 livres), ton temps sera toujours moins de 3 fois le temps de Jacky"
On dit alors que tu es en O(n) - tu es aussi rapide que Jacky (aux détails près).


- Décortiquons la Formule Pas à Pas :

**f(n) = O(g(n))** ssi ∃c > 0, ∃n₀ > 0 : ∀n ≥ n₀, f(n) ≤ c·g(n)

Traduisons chaque symbole :
| Symbole 	| Signifie 					| En français 							| 
|-----------|---------------------------|---------------------------------------|
| f(n) 		| Ton algorithme 			| Le temps que TU prends 				| 
| g(n) 		| La référence 				| Le temps de référence (n, n², etc.) 	|
| ssi 		| Si et seulement si 		| C'est vrai dans les deux sens 		| 
| ∃ 		| Il existe 				| On peut trouver 						| 
| c > 0 	| Un nombre positif 		| Un multiplicateur (2, 3, 100...) 		| 
| n₀ 		| Un point de départ 		| À partir de combien d'éléments 		| 
| ∀ 		| Pour tout 				| Peu importe la taille 				| 
| n ≥ n₀ 	| Pour les grandes tailles 	| Quand on a beaucoup de données 		|


- Exemple Visuel : 

Prenons un algorithme qui prend f(n) = 5n + 100 secondes.
Question : Est-ce que f(n) = O(n) ?
Réponse : OUI ! Voici pourquoi :
```
f(n) = 5n + 100
g(n) = n

On cherche : f(n) ≤ c·g(n)
Soit : 5n + 100 ≤ c·n
```
Choisissons c = 10 et n₀ = 20 :
| n 		| f(n) = 5n + 100 	| c·g(n) = 10n 	| f(n) ≤ 10n ? 		| 
|-----------|-------------------|---------------|-------------------|
| 5 		| 125 				| 50 			| ❌ (pas encore) 	|
| 10 		| 150 				| 100 			| ❌ (pas encore) 	| 
| 20 		| 200 				| 200 			| ✅ (égal) 		| 
| 50 		| 350 				| 500 			| ✅ 				| 
| 100 		| 600 				| 1000 			| ✅ 				| 
| 1000 		| 5100 				| 10000 		| ✅ 				|

Après n₀ = 20, f(n) reste toujours sous 10·n !


- Pourquoi C'est Important ? 

La formule dit 3 choses :

∃c > 0 : "On a le droit de tricher un peu avec un multiplicateur"

Peu importe si ton algorithme est 2x, 5x ou 100x plus lent.
Ce qui compte c'est la forme de la croissance.

∃n₀ > 0 : "On ignore les petits tableaux"

Les 10, 20 premiers éléments ? On s'en fiche !
Ce qui compte c'est les grandes quantités

∀n ≥ n₀ : "Après un certain point, ça reste vrai pour toujours"

Ton algorithme ne va pas soudainement devenir super lent.
On a une garantie sur le comportement.


- Exemples Concrets : 

Exemple 1 : f(n) = 3n + 50
Est-ce O(n) ?

Oui ! Avec c = 4 et n₀ = 50
Quand n = 100 : 3(100) + 50 = 350 ≤ 4(100) = 400 ✅

Exemple 2 : f(n) = n²
Est-ce O(n) ?

Non ! Aucun c ne marche pour toujours.
Quand n = 1000 : n² = 1,000,000 mais c·n = c·1000
Même avec c = 1000, ça explose ! ❌

Exemple 3 : f(n) = 100n
Est-ce O(n²) ?

Oui ! Avec c = 1 et n₀ = 100
100n ≤ 1·n² quand n ≥ 100 ✅
Mais attention : O(n²) est une borne supérieure, pas précise !


### Hiérarchie des complexités courantes (du meilleur au pire) :

*   **O(1)** : Constant - accès direct à un élément
*   **O(log n)** : Logarithmique - recherche dichotomique
*   **O(n)** : Linéaire - parcours simple
*   **O(n log n)** : Linéarithmique - algorithmes de tri efficaces
*   **O(n²)** : Quadratique - boucles imbriquées
*   **O(n³)** : Cubique - trois boucles imbriquées
*   **O(2ⁿ)** : Exponentielle - problèmes combinatoires
*   **O(n!)** : Factorielle - permutations complètes

Propriétés importantes :

*   On ignore les constantes multiplicatives : O(5n) = O(n)
*   On conserve uniquement le terme dominant : O(n² + n) = O(n²)
*   Notations complémentaires : Ω (borne inférieure), Θ (encadrement exact)

* * *

# Algorithmes de Tri
====================

## Liste Exhaustive

1\. Bubble Sort (Tri à Bulles)
------------------------------

**Principe** : Compare les éléments adjacents et les échange s'ils sont dans le mauvais ordre. Les plus grands éléments "remontent" comme des bulles.

**Fonctionnement** :

*   Parcourt le tableau en comparant chaque paire d'éléments adjacents
*   Si l'élément de gauche est plus grand, on échange
*   Répète jusqu'à ce qu'aucun échange ne soit nécessaire

**Complexité temporelle** :

*   Meilleur cas : O(n) - tableau déjà trié
*   Cas moyen : O(n²)
*   Pire cas : O(n²)

**Complexité spatiale** : O(1) - en place

```
    void bubbleSort(int arr[], int n) {
        for (int i = 0; i < n-1; i++) {
            bool swapped = false;
            for (int j = 0; j < n-i-1; j++) {
                if (arr[j] > arr[j+1]) {
                    std::swap(arr[j], arr[j+1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
        }
    }
```
* * *

2\. Selection Sort (Tri par Sélection)
--------------------------------------

**Principe** : Trouve le minimum dans la partie non triée et le place au début.

**Fonctionnement** :

*   Trouve l'élément minimum du tableau
*   L'échange avec le premier élément
*   Répète pour la partie restante

**Complexité temporelle** : O(n²) dans tous les cas

**Complexité spatiale** : O(1) - en place

```
    void selectionSort(int arr[], int n) {
        for (int i = 0; i < n-1; i++) {
            int minIdx = i;
            for (int j = i+1; j < n; j++) {
                if (arr[j] < arr[minIdx]) 
                    minIdx = j;
            }
            std::swap(arr[i], arr[minIdx]);
        }
    }
```
* * *

3\. Insertion Sort (Tri par Insertion)
--------------------------------------

**Principe** : Construit progressivement un tableau trié en insérant chaque élément à sa position correcte.

**Fonctionnement** :

*   Considère le premier élément comme trié
*   Pour chaque élément suivant, l'insère à la bonne position dans la partie triée
*   Décale les éléments plus grands vers la droite

**Complexité temporelle** :

*   Meilleur cas : O(n) - tableau déjà trié
*   Cas moyen : O(n²)
*   Pire cas : O(n²)

**Complexité spatiale** : O(1) - en place

```
    void insertionSort(int arr[], int n) {
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    }
```
* * *

4\. Merge Sort (Tri Fusion)
---------------------------

**Principe** : Divise le tableau en deux moitiés, trie récursivement chaque moitié, puis fusionne les deux parties triées.

**Fonctionnement** :

*   Divise le tableau en deux sous-tableaux
*   Trie récursivement chaque sous-tableau
*   Fusionne les deux sous-tableaux triés en un seul

**Complexité temporelle** : O(n log n) dans tous les cas

**Complexité spatiale** : O(n) - nécessite un tableau auxiliaire

```
    void merge(int arr[], int l, int m, int r) {
        int n1 = m-l+1, n2 = r-m;
        int L[n1], R[n2];
        for (int i = 0; i < n1; i++) L[i] = arr[l+i];
        for (int i = 0; i < n2; i++) R[i] = arr[m+1+i];
        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2)
            arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];
    }
    
    void mergeSort(int arr[], int l, int r) {
        if (l < r) {
            int m = l + (r-l)/2;
            mergeSort(arr, l, m);
            mergeSort(arr, m+1, r);
            merge(arr, l, m, r);
        }
    }
```
* * *

5\. Quick Sort (Tri Rapide)
---------------------------

**Principe** : Choisit un pivot, partitionne le tableau autour du pivot, puis trie récursivement les partitions.

**Fonctionnement** :

*   Sélectionne un élément pivot (souvent le dernier)
*   Réorganise le tableau : éléments < pivot à gauche, éléments > pivot à droite
*   Applique récursivement sur les deux partitions

**Complexité temporelle** :

*   Meilleur cas : O(n log n)
*   Cas moyen : O(n log n)
*   Pire cas : O(n²) - si le pivot est toujours le min/max

**Complexité spatiale** : O(log n) - pile récursive

```
    int partition(int arr[], int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i+1], arr[high]);
        return i + 1;
    }
    
    void quickSort(int arr[], int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi-1);
            quickSort(arr, pi+1, high);
        }
    }
```
* * *

6\. Heap Sort (Tri par Tas)
---------------------------

**Principe** : Construit un tas (heap) max, puis extrait répétitivement le maximum.

**Fonctionnement** :

*   Construit un tas max à partir du tableau
*   Échange la racine (maximum) avec le dernier élément
*   Réduit la taille du tas et réajuste
*   Répète jusqu'à épuisement

**Complexité temporelle** : O(n log n) dans tous les cas

**Complexité spatiale** : O(1) - en place

```
    void heapify(int arr[], int n, int i) {
        int largest = i, l = 2*i+1, r = 2*i+2;
        if (l < n && arr[l] > arr[largest]) largest = l;
        if (r < n && arr[r] > arr[largest]) largest = r;
        if (largest != i) {
            std::swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }
    
    void heapSort(int arr[], int n) {
        for (int i = n/2-1; i >= 0; i--)
            heapify(arr, n, i);
        for (int i = n-1; i > 0; i--) {
            std::swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
```
* * *

7\. Counting Sort (Tri par Comptage)
------------------------------------

**Principe** : Compte le nombre d'occurrences de chaque valeur, puis reconstruit le tableau trié.

**Fonctionnement** :

*   Trouve la valeur maximale
*   Crée un tableau de compteurs
*   Compte les occurrences de chaque valeur
*   Reconstruit le tableau en ordre

**Complexité temporelle** : O(n + k) où k est la plage des valeurs

**Complexité spatiale** : O(k)

```
    void countingSort(int arr[], int n) {
        int max = *std::max_element(arr, arr+n);
        int count[max+1] = {0};
        for (int i = 0; i < n; i++) count[arr[i]]++;
        int idx = 0;
        for (int i = 0; i <= max; i++) {
            while (count[i]-- > 0) 
                arr[idx++] = i;
        }
    }
```
* * *

8\. Radix Sort (Tri par Base)
-----------------------------

**Principe** : Trie les nombres chiffre par chiffre, en commençant par le chiffre le moins significatif.

**Fonctionnement** :

*   Trie selon le dernier chiffre (unités)
*   Puis selon l'avant-dernier (dizaines)
*   Continue jusqu'au chiffre le plus significatif

**Complexité temporelle** : O(d·(n + k)) où d est le nombre de chiffres

**Complexité spatiale** : O(n + k)

```
    void countingSortForRadix(int arr[], int n, int exp) {
        int output[n], count[10] = {0};
        for (int i = 0; i < n; i++) count[(arr[i]/exp)%10]++;
        for (int i = 1; i < 10; i++) count[i] += count[i-1];
        for (int i = n-1; i >= 0; i--) {
            output[count[(arr[i]/exp)%10]-1] = arr[i];
            count[(arr[i]/exp)%10]--;
        }
        for (int i = 0; i < n; i++) arr[i] = output[i];
    }
    
    void radixSort(int arr[], int n) {
        int max = *std::max_element(arr, arr+n);
        for (int exp = 1; max/exp > 0; exp *= 10)
            countingSortForRadix(arr, n, exp);
    }
```
* * *

9\. Bucket Sort (Tri par Seaux)
-------------------------------

**Principe** : Distribue les éléments dans des seaux, trie chaque seau, puis concatène.

**Fonctionnement** :

*   Crée des seaux pour différentes plages de valeurs
*   Distribue les éléments dans les seaux appropriés
*   Trie chaque seau individuellement
*   Concatène tous les seaux

**Complexité temporelle** :

*   Meilleur/moyen cas : O(n + k)
*   Pire cas : O(n²) si tous les éléments vont dans un seau

**Complexité spatiale** : O(n + k)

```
    void bucketSort(float arr[], int n) {
        std::vector<float> buckets[n];
        for (int i = 0; i < n; i++) {
            int idx = n * arr[i];
            buckets[idx].push_back(arr[i]);
        }
        for (int i = 0; i < n; i++)
            std::sort(buckets[i].begin(), buckets[i].end());
        int idx = 0;
        for (int i = 0; i < n; i++)
            for (float x : buckets[i])
                arr[idx++] = x;
    }
```
* * *

10\. Shell Sort (Tri de Shell)
------------------------------

**Principe** : Généralisation du tri par insertion qui compare des éléments distants, puis réduit progressivement l'écart.

**Fonctionnement** :

*   Commence avec un grand écart h
*   Effectue un tri par insertion avec cet écart
*   Réduit l'écart selon une séquence (ex: h = h/2)
*   Termine avec h = 1 (tri par insertion classique)

**Complexité temporelle** : Dépend de la séquence d'écarts

*   Meilleur cas : O(n log n)
*   Pire cas : O(n²) ou O(n^(3/2)) selon la séquence

**Complexité spatiale** : O(1) - en place

```
    void shellSort(int arr[], int n) {
        for (int gap = n/2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                int temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j-gap] > temp; j -= gap)
                    arr[j] = arr[j-gap];
                arr[j] = temp;
            }
        }
    }
```
* * *

11\. Comb Sort (Tri à Peigne)
-----------------------------

**Principe** : Amélioration du tri à bulles utilisant un écart qui diminue.

**Fonctionnement** :

*   Utilise un facteur de réduction (shrink factor ≈ 1.3)
*   Compare et échange des éléments séparés par l'écart
*   Réduit l'écart jusqu'à 1
*   Termine avec un tri à bulles classique

**Complexité temporelle** :

*   Meilleur cas : O(n log n)
*   Cas moyen: O(n²/2^p) où p est le nombre de passes
*   Pire cas : O(n²)

**Complexité spatiale** : O(1) - en place

```
    void combSort(int arr[], int n) {
        int gap = n;
        bool swapped = true;
        while (gap != 1 || swapped) {
            gap = (gap * 10) / 13;
            if (gap < 1) gap = 1;
            swapped = false;
            for (int i = 0; i < n-gap; i++) {
                if (arr[i] > arr[i+gap]) {
                    std::swap(arr[i], arr[i+gap]);
                    swapped = true;
                }
            }
        }
    }
```
* * *

12\. Gnome Sort (Tri du Gnome)
------------------------------

**Principe** : Similaire au tri par insertion mais remonte l'élément jusqu'à sa place en échangeant.

**Fonctionnement** :

*   Parcourt le tableau
*   Si l'élément est plus petit que le précédent, échange et recule
*   Sinon, avance

**Complexité temporelle** :

*   Meilleur cas : O(n)
*   Pire cas : O(n²)

**Complexité spatiale** : O(1) - en place

```
    void gnomeSort(int arr[], int n) {
        int i = 0;
        while (i < n) {
            if (i == 0 || arr[i] >= arr[i-1])
                i++;
            else {
                std::swap(arr[i], arr[i-1]);
                i--;
            }
        }
    }
```
* * *

13\. Cocktail Sort (Tri Cocktail/Shaker)
----------------------------------------

**Principe** : Variante bidirectionnelle du tri à bulles.

**Fonctionnement** :

*   Parcourt de gauche à droite (fait remonter le max)
*   Puis de droite à gauche (fait descendre le min)
*   Alterne jusqu'à ce que le tableau soit trié

**Complexité temporelle** :

*   Meilleur cas : O(n)
*   Pire cas : O(n²)

**Complexité spatiale** : O(1) - en place

```
    void cocktailSort(int arr[], int n) {
        bool swapped = true;
        int start = 0, end = n - 1;
        while (swapped) {
            swapped = false;
            for (int i = start; i < end; i++) {
                if (arr[i] > arr[i+1]) {
                    std::swap(arr[i], arr[i+1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
            swapped = false;
            end--;
            for (int i = end-1; i >= start; i--) {
                if (arr[i] > arr[i+1]) {
                    std::swap(arr[i], arr[i+1]);
                    swapped = true;
                }
            }
            start++;
        }
    }
```
* * *

14\. Cycle Sort (Tri par Cycle)
-------------------------------

**Principe** : Minimise le nombre d'écritures en plaçant directement chaque élément à sa position finale.

**Fonctionnement** :

*   Pour chaque position, compte combien d'éléments sont plus petits
*   Place l'élément à sa position correcte
*   Continue le cycle jusqu'à revenir à la position de départ

**Complexité temporelle** : O(n²) dans tous les cas

**Complexité spatiale** : O(1) - en place, optimal en nombre d'écritures

```
    void cycleSort(int arr[], int n) {
        for (int start = 0; start < n-1; start++) {
            int item = arr[start], pos = start;
            for (int i = start+1; i < n; i++)
                if (arr[i] < item) pos++;
            if (pos == start) continue;
            while (item == arr[pos]) pos++;
            std::swap(item, arr[pos]);
            while (pos != start) {
                pos = start;
                for (int i = start+1; i < n; i++)
                    if (arr[i] < item) pos++;
                while (item == arr[pos]) pos++;
                std::swap(item, arr[pos]);
            }
        }
    }
```
* * *

15\. Pancake Sort (Tri de Crêpes)
---------------------------------

**Principe** : Utilise uniquement des retournements de préfixes pour trier.

**Fonctionnement** :

*   Trouve le maximum dans la partie non triée
*   Le retourne vers le début
*   Le retourne vers sa position finale
*   Répète pour le reste

**Complexité temporelle** : O(n²)

**Complexité spatiale** : O(1) - en place

```
    void flip(int arr[], int i) {
        int start = 0;
        while (start < i) {
            std::swap(arr[start], arr[i]);
            start++;
            i--;
        }
    }
    
    void pancakeSort(int arr[], int n) {
        for (int size = n; size > 1; size--) {
            int maxIdx = 0;
            for (int i = 0; i < size; i++)
                if (arr[i] > arr[maxIdx]) maxIdx = i;
            if (maxIdx != size-1) {
                flip(arr, maxIdx);
                flip(arr, size-1);
            }
        }
    }
```
* * *

16\. Bogo Sort (Tri Stupide)
----------------------------

**Principe** : Mélange aléatoirement jusqu'à obtenir un tableau trié (à éviter en pratique !).

**Fonctionnement** :

*   Vérifie si le tableau est trié
*   Sinon, mélange aléatoirement
*   Répète jusqu'à réussite

**Complexité temporelle** :

*   Meilleur cas : O(n)
*   Cas moyen : O((n+1)!)
*   Pire cas : Infini (non borné)

**Complexité spatiale** : O(1)

```
    bool isSorted(int arr[], int n) {
        for (int i = 0; i < n-1; i++)
            if (arr[i] > arr[i+1]) return false;
        return true;
    }
    
    void bogoSort(int arr[], int n) {
        while (!isSorted(arr, n)) {
            for (int i = 0; i < n; i++)
                std::swap(arr[i], arr[rand()%n]);
        }
    }
```
* * *

17\. Stooge Sort
----------------

**Principe** : Algorithme récursif inefficace qui trie les deux tiers du tableau à plusieurs reprises.

**Fonctionnement** :

*   Si le premier élément > dernier, les échange
*   Trie récursivement les premiers 2/3
*   Trie récursivement les derniers 2/3
*   Trie à nouveau les premiers 2/3

**Complexité temporelle** : O(n^(log 3/log 1.5)) ≈ O(n^2.7)

**Complexité spatiale** : O(n) - pile récursive

```
    void stoogeSort(int arr[], int l, int h) {
        if (arr[l] > arr[h])
            std::swap(arr[l], arr[h]);
        if (h - l + 1 > 2) {
            int t = (h - l + 1) / 3;
            stoogeSort(arr, l, h-t);
            stoogeSort(arr, l+t, h);
            stoogeSort(arr, l, h-t);
        }
    }
```
* * *

18\. Tim Sort
-------------

**Principe** : Hybride de merge sort et insertion sort, optimisé pour les données réelles (utilisé par Python et Java).

**Fonctionnement** :

*   Divise le tableau en petits blocs (runs)
*   Trie chaque run avec insertion sort
*   Fusionne les runs avec un merge sort optimisé
*   Exploite les séquences déjà triées

**Complexité temporelle** :

*   Meilleur cas : O(n)
*   Cas moyen et pire : O(n log n)

**Complexité spatiale** : O(n)

```
    const int RUN = 32;
    
    void insertionSortForTim(int arr[], int left, int right) {
        for (int i = left+1; i <= right; i++) {
            int key = arr[i];
            int j = i-1;
            while (j >= left && arr[j] > key) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    }
    
    void timSort(int arr[], int n) {
        for (int i = 0; i < n; i += RUN)
            insertionSortForTim(arr, i, std::min(i+RUN-1, n-1));
        for (int size = RUN; size < n; size = 2*size) {
            for (int left = 0; left < n; left += 2*size) {
                int mid = left + size - 1;
                int right = std::min(left+2*size-1, n-1);
                if (mid < right)
                    merge(arr, left, mid, right);
            }
        }
    }
```
* * *

19\. Intro Sort (Introspective Sort)
------------------------------------

**Principe** : Hybride de quicksort, heapsort et insertion sort (utilisé par la STL C++).

**Fonctionnement** :

*   Commence avec quicksort
*   Si la profondeur de récursion dépasse un seuil (2\*log n), bascule vers heapsort
*   Pour les petites partitions, utilise insertion sort

**Complexité temporelle** : O(n log n) dans tous les cas

**Complexité spatiale** : O(log n)

```
    void introSort(int arr[], int low, int high, int depth) {
        if (high - low < 16) {
            insertionSort(arr + low, high - low + 1);
            return;
        }
        if (depth == 0) {
            heapSort(arr + low, high - low + 1);
            return;
        }
        int pi = partition(arr, low, high);
        introSort(arr, low, pi-1, depth-1);
        introSort(arr, pi+1, high, depth-1);
    }
    
    void sort(int arr[], int n) {
        int depth = 2 * log2(n);
        introSort(arr, 0, n-1, depth);
    }
```
* * *

20\. Bitonic Sort (Tri Bitonique)
---------------------------------

**Principe** : Algorithme parallélisable basé sur les réseaux de tri, crée une séquence bitonique puis la trie.

**Fonctionnement** :

*   Construit récursivement une séquence bitonique
*   Compare et échange des paires d'éléments à distances fixes
*   Fusionne les séquences bitoniques

**Complexité temporelle** : O(n log² n)

**Complexité spatiale** : O(log² n) - récursif

```
    void bitonicMerge(int arr[], int low, int cnt, bool dir) {
        if (cnt > 1) {
            int k = cnt / 2;
            for (int i = low; i < low+k; i++)
                if ((arr[i] > arr[i+k]) == dir)
                    std::swap(arr[i], arr[i+k]);
            bitonicMerge(arr, low, k, dir);
            bitonicMerge(arr, low+k, k, dir);
        }
    }
    
    void bitonicSort(int arr[], int low, int cnt, bool dir) {
        if (cnt > 1) {
            int k = cnt / 2;
            bitonicSort(arr, low, k, true);
            bitonicSort(arr, low+k, k, false);
            bitonicMerge(arr, low, cnt, dir);
        }
    }
```
* * *

21\. Odd-Even Sort (Tri Pair-Impair)
------------------------------------

**Principe** : Variante parallélisable du tri à bulles qui alterne entre comparaisons de paires paires et impaires.

**Fonctionnement** :

*   Phase impaire : compare (0,1), (2,3), (4,5)...
*   Phase paire : compare (1,2), (3,4), (5,6)...
*   Alterne jusqu'à ce que le tableau soit trié

**Complexité temporelle** : O(n²)

**Complexité spatiale** : O(1) - en place

```
    void oddEvenSort(int arr[], int n) {
        bool sorted = false;
        while (!sorted) {
            sorted = true;
            for (int i = 1; i < n-1; i += 2) {
                if (arr[i] > arr[i+1]) {
                    std::swap(arr[i], arr[i+1]);
                    sorted = false;
                }
            }
            for (int i = 0; i < n-1; i += 2) {
                if (arr[i] > arr[i+1]) {
                    std::swap(arr[i], arr[i+1]);
                    sorted = false;
                }
            }
        }
    }
```
* * *


22\. Brick Sort (Odd-Even Transposition Sort) - Suite
-----------------------------------------------------

```
    void brickSort(int arr[], int n) {
        bool sorted = false;
        while (!sorted) {
            sorted = true;
            // Phase impaire
            for (int i = 1; i <= n-2; i += 2) {
                if (arr[i] > arr[i+1]) {
                    std::swap(arr[i], arr[i+1]);
                    sorted = false;
                }
            }
            // Phase paire
            for (int i = 0; i <= n-2; i += 2) {
                if (arr[i] > arr[i+1]) {
                    std::swap(arr[i], arr[i+1]);
                    sorted = false;
                }
            }
        }
    }
```
* * *

23\. 3-Way Merge Sort (Tri Fusion à 3 Voies)
--------------------------------------------

**Principe** : Variante du merge sort qui divise le tableau en 3 parties au lieu de 2.

**Fonctionnement** :

*   Divise le tableau en 3 sous-tableaux égaux
*   Trie récursivement chaque partie
*   Fusionne les 3 parties triées

**Complexité temporelle** : O(n log₃ n) ≈ O(n log n)

**Complexité spatiale** : O(n)

```
    void merge3Way(int arr[], int l, int m1, int m2, int r) {
        int n1 = m1-l+1, n2 = m2-m1, n3 = r-m2;
        int L[n1], M[n2], R[n3];
        for (int i = 0; i < n1; i++) L[i] = arr[l+i];
        for (int i = 0; i < n2; i++) M[i] = arr[m1+1+i];
        for (int i = 0; i < n3; i++) R[i] = arr[m2+1+i];
        int i = 0, j = 0, k = 0, idx = l;
        while (i < n1 && j < n2 && k < n3) {
            if (L[i] <= M[j] && L[i] <= R[k]) arr[idx++] = L[i++];
            else if (M[j] <= R[k]) arr[idx++] = M[j++];
            else arr[idx++] = R[k++];
        }
        while (i < n1 && j < n2)
            arr[idx++] = (L[i] <= M[j]) ? L[i++] : M[j++];
        while (j < n2 && k < n3)
            arr[idx++] = (M[j] <= R[k]) ? M[j++] : R[k++];
        while (i < n1 && k < n3)
            arr[idx++] = (L[i] <= R[k]) ? L[i++] : R[k++];
        while (i < n1) arr[idx++] = L[i++];
        while (j < n2) arr[idx++] = M[j++];
        while (k < n3) arr[idx++] = R[k++];
    }
    
    void mergeSort3Way(int arr[], int l, int r) {
        if (l < r) {
            int m1 = l + (r-l)/3;
            int m2 = l + 2*(r-l)/3;
            mergeSort3Way(arr, l, m1);
            mergeSort3Way(arr, m1+1, m2);
            mergeSort3Way(arr, m2+1, r);
            merge3Way(arr, l, m1, m2, r);
        }
    }
```
* * *

24\. Tree Sort (Tri par Arbre)
------------------------------

**Principe** : Insère les éléments dans un arbre binaire de recherche (BST), puis parcourt en inordre.

**Fonctionnement** :

*   Crée un BST vide
*   Insère tous les éléments dans l'arbre
*   Parcourt l'arbre en inordre (gauche-racine-droite) pour obtenir l'ordre trié

**Complexité temporelle** :

*   Meilleur/moyen cas : O(n log n)
*   Pire cas : O(n²) - arbre dégénéré

**Complexité spatiale** : O(n) - pour l'arbre

```
    struct Node {
        int data;
        Node *left, *right;
        Node(int val) : data(val), left(nullptr), right(nullptr) {}
    };
    
    Node* insert(Node* root, int key) {
        if (!root) return new Node(key);
        if (key < root->data)
            root->left = insert(root->left, key);
        else
            root->right = insert(root->right, key);
        return root;
    }
    
    void inorder(Node* root, int arr[], int& i) {
        if (root) {
            inorder(root->left, arr, i);
            arr[i++] = root->data;
            inorder(root->right, arr, i);
        }
    }
    
    void treeSort(int arr[], int n) {
        Node* root = nullptr;
        for (int i = 0; i < n; i++)
            root = insert(root, arr[i]);
        int i = 0;
        inorder(root, arr, i);
    }
```
* * *

25\. Cartesian Tree Sort
------------------------

**Principe** : Construit un arbre cartésien puis effectue un parcours inordre.

**Fonctionnement** :

*   Construit un arbre cartésien (min-heap par valeur, BST par position)
*   Parcourt en inordre pour obtenir l'ordre trié

**Complexité temporelle** : O(n log n) en moyenne

**Complexité spatiale** : O(n)

Implémentation similaire au Tree Sort mais avec propriété de tas

* * *

26\. Tournament Sort (Tri par Tournoi)
--------------------------------------

**Principe** : Construit un arbre de tournoi pour trouver répétitivement le minimum.

**Fonctionnement** :

*   Construit un arbre binaire complet avec les éléments aux feuilles
*   Chaque nœud contient le minimum de ses enfants
*   Extrait le minimum (racine), le remplace par ∞, puis reconstruit
*   Répète n fois

**Complexité temporelle** : O(n log n)

**Complexité spatiale** : O(n)

```
    void tournamentSort(int arr[], int n) {
        int tree[2*n];
        for (int i = 0; i < n; i++)
            tree[n+i] = arr[i];
        for (int i = n-1; i > 0; i--)
            tree[i] = std::min(tree[2*i], tree[2*i+1]);
        
        for (int i = 0; i < n; i++) {
            arr[i] = tree[1];
            int idx = 1;
            while (idx < n) {
                int left = 2*idx, right = 2*idx+1;
                if (tree[left] == tree[idx]) idx = left;
                else idx = right;
            }
            tree[idx] = INT_MAX;
            while (idx > 1) {
                idx /= 2;
                tree[idx] = std::min(tree[2*idx], tree[2*idx+1]);
            }
        }
    }
```
* * *

27\. Smooth Sort
----------------

**Principe** : Variante optimisée du heapsort utilisant les nombres de Leonardo.

**Fonctionnement** :

*   Utilise une forêt de tas de Leonardo (suite similaire à Fibonacci)
*   Plus adaptatif que le heapsort classique
*   Complexité optimale pour les données partiellement triées

**Complexité temporelle** :

*   Meilleur cas : O(n)
*   Pire cas : O(n log n)

**Complexité spatiale** : O(1)

Implémentation complexe utilisant les nombres de Leonardo

* * *

28\. Library Sort (Gapped Insertion Sort)
-----------------------------------------

**Principe** : Insertion sort avec des espaces vides pour réduire les décalages.

**Fonctionnement** :

*   Crée un tableau avec des espaces vides (gaps)
*   Insère les éléments dans les gaps
*   Si nécessaire, réorganise pour créer de nouveaux gaps

**Complexité temporelle** : O(n log n) en moyenne

**Complexité spatiale** : O(n)

```
    void librarySort(int arr[], int n) {
        int size = 2 * n;
        int lib[size];
        std::fill(lib, lib+size, INT_MAX);
        
        lib[size/2] = arr[0];
        for (int i = 1; i < n; i++) {
            int pos = 0;
            while (lib[pos] < arr[i]) pos++;
            if (lib[pos] == INT_MAX) {
                lib[pos] = arr[i];
            } else {
                // Décalage et insertion avec gestion des gaps
                int j = size-1;
                while (lib[j] != INT_MAX) j--;
                while (j > pos) {
                    lib[j] = lib[j-1];
                    j--;
                }
                lib[pos] = arr[i];
            }
        }
        int idx = 0;
        for (int i = 0; i < size && idx < n; i++)
            if (lib[i] != INT_MAX)
                arr[idx++] = lib[i];
    }
```
* * *

29\. Patience Sort
------------------

**Principe** : Inspiré du jeu de cartes "patience", crée des piles croissantes.

**Fonctionnement** :

*   Pour chaque élément, trouve la pile dont le sommet est le plus petit mais >= élément
*   Si aucune pile ne convient, crée une nouvelle pile
*   Fusionne toutes les piles à la fin

**Complexité temporelle** : O(n log n)

**Complexité spatiale** : O(n)

```
    void patienceSort(int arr[], int n) {
        std::vector<std::vector<int>> piles;
        
        for (int i = 0; i < n; i++) {
            auto it = std::lower_bound(piles.begin(), piles.end(), 
                std::vector<int>{arr[i]}, 
                [](const std::vector<int>& a, const std::vector<int>& b) {
                    return a.back() < b.back();
                });
            
            if (it == piles.end())
                piles.push_back({arr[i]});
            else
                it->push_back(arr[i]);
        }
        
        // Fusion des piles (min-heap)
        std::priority_queue<std::pair<int,int>, 
            std::vector<std::pair<int,int>>, 
            std::greater<>> pq;
        
        for (int i = 0; i < piles.size(); i++)
            pq.push({piles[i].back(), i});
        
        int idx = 0;
        while (!pq.empty()) {
            auto [val, pile] = pq.top();
            pq.pop();
            arr[idx++] = val;
            piles[pile].pop_back();
            if (!piles[pile].empty())
                pq.push({piles[pile].back(), pile});
        }
    }
```
* * *

30\. Strand Sort
----------------

**Principe** : Extrait des sous-séquences triées et les fusionne.

**Fonctionnement** :

*   Extrait une sous-séquence croissante maximale
*   Fusionne avec le résultat précédent
*   Répète jusqu'à épuiser l'entrée

**Complexité temporelle** :

*   Meilleur cas : O(n)
*   Pire cas : O(n²)

**Complexité spatiale** : O(n)

```
    void strandSort(int arr[], int n) {
        std::list<int> input(arr, arr+n);
        std::list<int> result;
        
        while (!input.empty()) {
            std::list<int> sublist;
            sublist.push_back(input.front());
            input.pop_front();
            
            for (auto it = input.begin(); it != input.end(); ) {
                if (*it > sublist.back()) {
                    sublist.push_back(*it);
                    it = input.erase(it);
                } else {
                    ++it;
                }
            }
            
            result.merge(sublist);
        }
        
        std::copy(result.begin(), result.end(), arr);
    }
```
* * *

31\. Block Sort (Block Merge Sort)
----------------------------------

**Principe** : Tri fusion optimisé qui travaille par blocs pour réduire l'utilisation mémoire.

**Fonctionnement** :

*   Divise en blocs de taille fixe
*   Trie chaque bloc
*   Fusionne les blocs en place avec O(1) mémoire auxiliaire

**Complexité temporelle** : O(n log n)

**Complexité spatiale** : O(1) - presque en place

```
    // Implémentation complexe nécessitant plusieurs fonctions auxiliaires
    void blockSort(int arr[], int n) {
        // Version simplifiée utilisant insertion sort pour petits blocs
        const int BLOCK = 32;
        for (int i = 0; i < n; i += BLOCK)
            insertionSort(arr+i, std::min(BLOCK, n-i));
        
        // Fusion des blocs
        for (int size = BLOCK; size < n; size *= 2) {
            for (int start = 0; start < n; start += 2*size) {
                int mid = std::min(start+size, n);
                int end = std::min(start+2*size, n);
                std::inplace_merge(arr+start, arr+mid, arr+end);
            }
        }
    }
```
* * *

32\. Flash Sort
---------------

**Principe** : Tri par distribution qui calcule directement les positions approximatives.

**Fonctionnement** :

*   Calcule la distribution des valeurs
*   Place chaque élément près de sa position finale
*   Effectue un insertion sort final

**Complexité temporelle** : O(n) en moyenne, O(n²) pire cas

**Complexité spatiale** : O(n)

```
    void flashSort(int arr[], int n) {
        int minVal = *std::min_element(arr, arr+n);
        int maxVal = *std::max_element(arr, arr+n);
        if (minVal == maxVal) return;
        
        int m = 0.43 * n;
        int L[m+1] = {0};
        
        double c = (m - 1.0) / (maxVal - minVal);
        for (int i = 0; i < n; i++)
            L[int(c * (arr[i] - minVal))]++;
        
        for (int i = 1; i <= m; i++)
            L[i] += L[i-1];
        
        // Permutation
        int move = 0, j = 0, k, flash;
        while (move < n-1) {
            while (j > L[int(c * (arr[j] - minVal))]-1)
                j++;
            flash = arr[j];
            while (j != L[int(c * (flash - minVal))]) {
                k = int(c * (flash - minVal));
                std::swap(flash, arr[L[k]-1]);
                L[k]--;
                move++;
            }
        }
        
        insertionSort(arr, n);
    }
```
* * *

33\. Batcher Sort (Batcher's Odd-Even Merge Sort)
-------------------------------------------------

**Principe** : Réseau de tri parallélisable avec structure régulière.

**Fonctionnement** :

*   Utilise un réseau de comparateurs prédéfini
*   Effectue des comparaisons en parallèle
*   Garantit le tri après un nombre fixe d'étapes

**Complexité temporelle** : O(log² n) en parallèle, O(n log² n) séquentiel

**Complexité spatiale** : O(1)

```
    void compareAndSwap(int arr[], int i, int j, bool dir) {
        if ((arr[i] > arr[j]) == dir)
            std::swap(arr[i], arr[j]);
    }
    
    void batcherMerge(int arr[], int low, int cnt, bool dir) {
        if (cnt > 1) {
            int m = cnt / 2;
            for (int i = low; i < low+cnt-m; i++)
                compareAndSwap(arr, i, i+m, dir);
            batcherMerge(arr, low, m, dir);
            batcherMerge(arr, low+m, cnt-m, dir);
        }
    }
    
    void batcherSort(int arr[], int low, int cnt, bool dir) {
        if (cnt > 1) {
            int m = cnt / 2;
            batcherSort(arr, low, m, !dir);
            batcherSort(arr, low+m, cnt-m, dir);
            batcherMerge(arr, low, cnt, dir);
        }
    }
```
* * *

34\. Sample Sort
----------------

**Principe** : Généralisation du quicksort utilisant plusieurs pivots.

**Fonctionnement** :

*   Sélectionne un échantillon d'éléments
*   Trie l'échantillon et choisit des pivots régulièrement espacés
*   Partitionne en k buckets selon les pivots
*   Trie récursivement chaque bucket

**Complexité temporelle** : O(n log n) en moyenne

**Complexité spatiale** : O(n)

```
    void sampleSort(int arr[], int n) {
        if (n < 10) {
            insertionSort(arr, n);
            return;
        }
        
        const int numPivots = 3;
        int pivots[numPivots];
        for (int i = 0; i < numPivots; i++)
            pivots[i] = arr[rand() % n];
        std::sort(pivots, pivots+numPivots);
        
        std::vector<int> buckets[numPivots+1];
        for (int i = 0; i < n; i++) {
            int bucket = 0;
            while (bucket < numPivots && arr[i] > pivots[bucket])
                bucket++;
            buckets[bucket].push_back(arr[i]);
        }
        
        int idx = 0;
        for (int i = 0; i <= numPivots; i++) {
            if (!buckets[i].empty()) {
                sampleSort(buckets[i].data(), buckets[i].size());
                for (int val : buckets[i])
                    arr[idx++] = val;
            }
        }
    }
```
* * *

35\. Spreadsort (Hybrid Distribution Sort)
------------------------------------------

**Principe** : Algorithme hybride qui adapte sa stratégie selon les données.

**Fonctionnement** :

*   Analyse la distribution des données
*   Choisit entre radix sort, comparison sort, ou autre selon les caractéristiques
*   Optimise pour les entiers, flottants et strings

**Complexité temporelle** : O(n log n) garantie, O(n) meilleur cas

**Complexité spatiale** : O(n)

Implémentation complexe de Boost.Sort

* * *

## 📊 Tableau Comparatif des Algorithmes de Tri
===============================================

| Algorithme 			| Meilleur Cas	| Cas Moyen	 | Pire Cas   | Espace 	 | Stable   | En Place  |
|-----------------------|---------------|------------|------------|----------|----------|-----------|
| **Bubble Sort** 		| O(n) 			| O(n²) 	 | O(n²) 	  | O(1) 	 | ✅ 		| ✅ 		|
| **Selection Sort** 	| O(n²) 		| O(n²) 	 | O(n²) 	  | O(1) 	 | ❌ 		| ✅ 		|
| **Insertion Sort** 	| O(n) 			| O(n²) 	 | O(n²) 	  | O(1) 	 | ✅ 		| ✅		|
| **Merge Sort** 		| O(n log n) 	| O(n log n) | O(n log n) | O(n) 	 | ✅ 		| ❌ 		|
| **Quick Sort** 		| O(n log n) 	| O(n log n) | O(n²) 	  | O(log n) | ❌ 		| ✅ 		|
| **Heap Sort** 		| O(n log n) 	| O(n log n) | O(n log n) | O(1) 	 | ❌ 		| ✅ 		|
| **Counting Sort** 	| O(n+k) 		| O(n+k) 	 | O(n+k) 	  | O(k) 	 | ✅ 		| ❌ 		|
| **Radix Sort** 		| O(d·n) 		| O(d·n) 	 | O(d·n) 	  | O(n+k) 	 | ✅ 		| ❌ 		|
| **Bucket Sort** 		| O(n+k) 		| O(n+k) 	 | O(n²) 	  | O(n+k) 	 | ✅ 		| ❌ 		|
| **Shell Sort** 		| O(n log n) 	| O(n^1.3) 	 | O(n²) 	  | O(1) 	 | ❌ 		| ✅ 		|
| **Comb Sort** 		| O(n log n) 	| O(n²/2^p)  | O(n²) 	  | O(1) 	 | ❌ 		| ✅ 		|
| **Gnome Sort** 		| O(n) 			| O(n²) 	 | O(n²) 	  | O(1) 	 | ✅ 		| ✅ 		|
| **Cocktail Sort** 	| O(n) 			| O(n²) 	 | O(n²) 	  | O(1) 	 | ✅ 		| ✅ 		|
| **Cycle Sort** 		| O(n²) 		| O(n²) 	 | O(n²) 	  | O(1) 	 | ❌ 		| ✅ 		|
| **Pancake Sort** 		| O(n²) 		| O(n²) 	 | O(n²) 	  | O(1) 	 | ❌ 		| ✅ 		|
| **Bogo Sort** 		| O(n) 			| O((n+1)!)  | ∞ 		  | O(1) 	 | ❌ 		| ✅ 		|
| **Stooge Sort** 		| O(n^2.7) 		| O(n^2.7) 	 | O(n^2.7)   | O(n) 	 | ❌ 		| ✅ 		|
| **Tim Sort** 			| O(n) 			| O(n log n) | O(n log n) | O(n) 	 | ✅ 		| ❌ 		|
| **Intro Sort** 		| O(n log n) 	| O(n log n) | O(n log n) | O(log n) | ❌ 		| ✅ 		|
| **Bitonic Sort** 		| O(n log² n) 	| O(n log² n)| O(n log² n)| O(log² n)| ❌ 		| ❌ 		|
| **Odd-Even Sort** 	| O(n) 			| O(n²) 	 | O(n²) 	  | O(1) 	 | ✅ 		| ✅ 		|
| **Brick Sort** 		| O(n) 			| O(n²) 	 | O(n²) 	  | O(1) 	 | ✅ 		| ✅ 		|
| **3-Way Merge Sort** 	| O(n log n)	| O(n log n) | O(n log n) | O(n) 	 | ✅ 		| ❌ 		|
| **Tree Sort** 		| O(n log n) 	| O(n log n) | O(n²) 	  | O(n) 	 | ✅ 		| ❌ 		|
| **Tournament Sort** 	| O(n log n) 	| O(n log n) | O(n log n) | O(n) 	 | ❌ 		| ❌ 		|
| **Smooth Sort** 		| O(n) 			| O(n log n) | O(n log n) | O(1) 	 | ❌ 		| ✅ 		|
| **Library Sort** 		| O(n) 			| O(n log n) | O(n²) 	  | O(n) 	 | ❌ 		| ❌ 		|
| **Patience Sort** 	| O(n log n) 	| O(n log n) | O(n log n) | O(n) 	 | ❌ 		| ❌ 		|
| **Strand Sort** 		| O(n) 			| O(n²) 	 | O(n²) 	  | O(n) 	 | ✅ 		| ❌ 		|
| **Block Sort** 		| O(n) 			| O(n log n) | O(n log n) | O(1) 	 | ✅ 		| ✅ 		|
| **Flash Sort** 		| O(n) 			| O(n) 		 | O(n²) 	  | O(n) 	 | ❌ 		| ❌ 		|
| **Batcher Sort** 		| O(n log² n) 	| O(n log² n)| O(n log² n)| O(1) 	 | ❌ 		| ✅ 		|
| **Sample Sort** 		| O(n) 			| O(n log n) | O(n²) 	  | O(n) 	 | ❌ 		| ❌ 		|

* * *

## 🎯 Recommandations d'Utilisation
------------------------------------

### Pour la pratique générale :

*   **Intro Sort** (C++ std::sort) - Le meilleur choix général
*   **Tim Sort** (Python sorted()) - Excellent pour données réelles
*   **Merge Sort** - Quand la stabilité est requise

### Pour des cas spécifiques :

*   **Petits tableaux (n < 50)** : Insertion Sort
*   **Données presque triées** : Insertion Sort, Tim Sort
*   **Entiers dans une plage limitée** : Counting Sort, Radix Sort
*   **Contrainte mémoire stricte** : Heap Sort, Shell Sort
*   **Algorithmes parallèles** : Bitonic Sort, Odd-Even Sort

### À éviter en production :

*   Bogo Sort, Stooge Sort (éducatifs uniquement)
*   Bubble Sort (sauf pour l'enseignement)

* * *

## Conclusion 
-------------
Big O a deux objectifs : Trier le plus rapidement possible (complexité temporelle), et ne pas planter la machine (spatiale). 

Nous avons parcouru une liste exhaustive avec 35 algorithmes de tri ! Chacun a ses avantages et inconvénients. 

Si on regarde et compare attentivement le tableau, Le meilleur compromis temps/espace est Heap Sort : 
Temps : O(n log n) garanti - excellent
Espace : O(1) - parfait

Mais dans la pratique, on l'utilise rarement.

Pourquoi? Parce que Big O mesure le nombre d'opérations, mais pas leur coût réel !

Les processeurs modernes ont une hiérarchie mémoire :
| L1 Cache | 1 cycle  		|  (32 Ko) 	| Rapide comme l'éclair |
| L2 Cache | 4 cycles   	|(256 Ko) 	| La vitesse du son		|
| L3 Cache | 12 cycles  	|(8 Mo)     | Une ferrari			|
| RAM      | 200 cycles 	|(16 Go)    | Tortue				|
|Disque SSD| 100 000 cycles |        	| Escargot				|

Or dans son fonctionnement, Heap Sort saute partout en mémoire, tandis que Quick Sort compare des données proches en mémoire.
On dit que Heap Sort a un CACHE MISS constant, alors que Quick Sort un CACHE HIT fréquent. 
Alors sur un test de 1 millions d'entiers, Heap Sort ne fera que 20 millions d'opérations, mais mettra 180ms à le faire avec 40% de Cache Miss.
Quick Sort fera 22 millions d'opérations, donc un peu plus... Mais ne mettra que 90ms pour 5% de Cache Miss!

C'est pour ça qu'en fait, on utilise principalement Intro Sort, Tim Sort, et Merge Sort selon les besoins, Insertion Sort pour les petits tableaux (n < 50).