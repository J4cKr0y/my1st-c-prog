# C++ …en passant par C - Partie 1 : C

## Le langage C : Définition

### Les origines

Le langage C a été créé entre 1969 et 1973 par Dennis Ritchie aux Bell Labs (AT&T). 
Il était initialement destiné à réécrire le système d'exploitation UNIX, qui était alors écrit en assembleur. 
L'objectif était de créer un langage suffisamment proche du matériel pour être efficace, mais suffisamment abstrait pour être portable entre différentes machines.
Le nom "C" vient du fait qu'il succède au langage B (créé par Ken Thompson), lui-même inspiré du langage BCPL.

### Les concepts fondamentaux

C est un langage de programmation impératif et procédural qui se distingue par plusieurs caractéristiques : 
- il offre un contrôle direct sur la mémoire via les pointeurs 
- il permet une manipulation de bas niveau du matériel
- il compile vers du code machine très efficace
- il possède une syntaxe relativement simple et concise. 
C'est un langage typé statiquement mais faiblement, ce qui signifie que les types sont vérifiés à la compilation mais les conversions sont permissives.

### L'évolution du langage

Le C a connu plusieurs standardisations importantes. 
- K&R C (1978) correspond à la publication du livre de référence par Kernighan et Ritchie. 
- ANSI C ou C89 (1989) est la première standardisation officielle. 
- C99 (1999) a introduit les commentaires //, les déclarations de variables n'importe où dans le code, et le type _Bool. 
- C11 (2011) a ajouté le support du multithreading et les assertions statiques. 
- C17 et C23 (2018, 2023) ont apporté des corrections et quelques nouvelles fonctionnalités.

### Cas d'usage actuels

Le C reste omniprésent dans plusieurs domaines critiques. 
Les systèmes d'exploitation comme Linux, Windows (en partie), macOS et les systèmes embarqués sont largement écrits en C. 
Les systèmes embarqués et l'IoT l'utilisent massivement pour les microcontrôleurs, l'automobile, l'aérospatiale et les équipements médicaux. 
Les bases de données et serveurs tels que PostgreSQL, Redis, Nginx utilisent C pour les performances. 
La programmation système pour les pilotes, les firmware et les bootloaders repose sur ce langage. 
Enfin, les langages de haut niveau comme Python, Ruby et PHP ont leurs interpréteurs écrits en C.

### La demande en développeurs C
La demande en développeurs C a connu une évolution contrastée ces dernières années. 
Globalement, elle a légèrement diminué en pourcentage relatif face à la montée de langages comme Python, JavaScript ou Rust. 
Cependant, elle reste forte et stable dans des niches spécialisées, notamment : 
- l'embarqué et l'IoT où la demande est soutenue par la croissance des objets connectés, 
- la cybersécurité et les systèmes critiques où C reste incontournable pour l'analyse de bas niveau, 
- l'industrie automobile et aérospatiale avec l'électrification et les systèmes autonomes, 
- les infrastructures cloud où les composants de performance sont souvent en C.
Le profil recherché évolue : on demande de plus en plus une connaissance combinée de C et de langages modernes comme Rust, ainsi qu'une expertise en sécurité et en optimisation.

### Pourquoi C persiste
Malgré son âge, C reste pertinent pour plusieurs raisons fondamentales : 
- ses performances sont inégalées pour le code critique, 
- il offre un contrôle total sur les ressources matérielles, 
- il possède une portabilité exceptionnelle, 
- il bénéficie d'un écosystème mature et stable, 
- il constitue la base de nombreuses technologies actuelles.
Le C n'est pas le langage le plus demandé en volume, mais il reste essentiel dans des domaines où peu d'alternatives existent. 
C'est un langage de niche hautement valorisé, particulièrement pour les développeurs capables de travailler au niveau système.

## La bibliothèque standard du C (Standard Library)

### Définition

La bibliothèque standard du C est un ensemble de fichiers d'en-tête (headers) et de fonctions qui accompagnent tout compilateur C conforme aux standards. Elle fournit des fonctionnalités essentielles pour les opérations courantes sans avoir à tout réécrire depuis zéro. Ces fonctions sont portables et garanties par le standard C, ce qui signifie qu'elles fonctionnent sur toutes les plateformes disposant d'un compilateur C conforme.

La bibliothèque standard est liée automatiquement lors de la compilation (via la libc sur les systèmes Unix/Linux, ou msvcrt sur Windows).

### Les grandes sections de la bibliothèque standard

#### 1. Entrées/Sorties (I/O)
Cette section gère toutes les opérations de lecture et écriture, que ce soit sur la console, dans des fichiers, ou en mémoire. Elle comprend les fonctions pour ouvrir/fermer des fichiers, lire/écrire des données formatées ou binaires, et gérer les flux.

#### 2. Manipulation des chaînes de caractères
Fonctions pour copier, comparer, concaténer, rechercher dans des chaînes de caractères. Le C traite les chaînes comme des tableaux de caractères terminés par '\0'.

#### 3. Gestion de la mémoire
Allocation dynamique de mémoire sur le tas (heap), libération de mémoire, réallocation. Ces fonctions sont cruciales pour créer des structures de données dynamiques.

#### 4. Utilitaires généraux
Conversion de types, génération de nombres aléatoires, gestion de l'environnement, tri et recherche, contrôle du programme (exit, abort).

#### 5. Mathématiques
Fonctions trigonométriques, exponentielles, logarithmiques, puissances, arrondis, et autres opérations mathématiques.

#### 6. Gestion du temps et des dates
Mesure du temps, formatage de dates, conversions entre différents formats temporels.

#### 7. Gestion des caractères
Classification et conversion de caractères individuels (majuscules/minuscules, alphabétique, numérique, etc.).

#### 8. Traitement des signaux
Gestion des interruptions et signaux système (SIGINT, SIGTERM, etc.).

#### 9. Gestion des erreurs
Codes d'erreur standard et messages d'erreur associés.

#### 10. Support des mathématiques complexes
Opérations sur les nombres complexes (ajouté en C99).

#### 11. Support de la localisation
Adaptation du programme aux conventions locales (format de dates, séparateurs décimaux, etc.).

#### 12. Fonctions à nombre variable d'arguments
Macros pour créer des fonctions acceptant un nombre variable de paramètres (comme printf).

### Tableau complet des fichiers d'en-tête de la bibliothèque standard C

| En-tête | Description | Exemples de fonctions |
|---------|-------------|----------------------|
| `<stdio.h>` | Entrées/sorties standard | `printf()` - affichage formaté<br>`scanf()` - lecture formatée<br>`fopen()` - ouverture de fichier |
| `<stdlib.h>` | Utilitaires généraux | `malloc()` - allocation mémoire<br>`free()` - libération mémoire<br>`atoi()` - conversion chaîne vers entier |
| `<string.h>` | Manipulation de chaînes | `strlen()` - longueur d'une chaîne<br>`strcpy()` - copie de chaîne<br>`strcmp()` - comparaison de chaînes |
| `<math.h>` | Fonctions mathématiques | `sqrt()` - racine carrée<br>`sin()` - sinus<br>`pow()` - puissance |
| `<time.h>` | Gestion du temps | `time()` - temps actuel<br>`clock()` - temps CPU<br>`strftime()` - formatage de date |
| `<ctype.h>` | Classification de caractères | `isalpha()` - test alphabétique<br>`toupper()` - conversion majuscule<br>`isdigit()` - test numérique |
| `<assert.h>` | Diagnostic de programmes | `assert()` - assertion de débogage |
| `<errno.h>` | Codes d'erreur | Variable `errno` - dernier code d'erreur<br>`perror()` - affichage d'erreur (via stdio.h) |
| `<signal.h>` | Gestion des signaux | `signal()` - définir un gestionnaire<br>`raise()` - lever un signal |
| `<setjmp.h>` | Sauts non-locaux | `setjmp()` - sauvegarder le contexte<br>`longjmp()` - restaurer le contexte |
| `<stdarg.h>` | Arguments variables | `va_start()` - initialiser la liste<br>`va_arg()` - accéder à l'argument<br>`va_end()` - terminer |
| `<stddef.h>` | Définitions standard | `NULL` - pointeur nul<br>`size_t` - type pour les tailles<br>`offsetof()` - décalage dans structure |
| `<limits.h>` | Limites des types entiers | `INT_MAX` - valeur max d'un int<br>`CHAR_BIT` - bits dans un char |
| `<float.h>` | Limites des types flottants | `FLT_MAX` - max d'un float<br>`DBL_EPSILON` - précision d'un double |
| `<locale.h>` | Localisation | `setlocale()` - définir la locale<br>`localeconv()` - conventions locales |

#### En-têtes ajoutés en C99

| En-tête | Description | Exemples de fonctions |
|---------|-------------|----------------------|
| `<stdbool.h>` | Type booléen | `bool` - type booléen<br>`true` et `false` - constantes |
| `<stdint.h>` | Types entiers de taille fixe | `int32_t` - entier 32 bits<br>`uint64_t` - entier non signé 64 bits<br>`intptr_t` - entier de taille pointeur |
| `<inttypes.h>` | Format pour types entiers | `PRId64` - macro pour printf int64<br>`SCNu32` - macro pour scanf uint32 |
| `<complex.h>` | Nombres complexes | `creal()` - partie réelle<br>`cimag()` - partie imaginaire<br>`cabs()` - module |
| `<fenv.h>` | Environnement flottant | `fegetround()` - mode d'arrondi<br>`feclearexcept()` - effacer exceptions |
| `<tgmath.h>` | Mathématiques génériques | Macros génériques qui choisissent automatiquement la bonne fonction selon le type |
| `<iso646.h>` | Macros pour opérateurs | `and` pour `&&`<br>`or` pour `||`<br>`not` pour `!` |
| `<wchar.h>` | Caractères larges | `wprintf()` - printf pour wide char<br>`wcslen()` - longueur chaîne large<br>`wcscpy()` - copie chaîne large |
| `<wctype.h>` | Classification caractères larges | `iswalpha()` - test alphabétique large<br>`towupper()` - conversion majuscule large |

#### En-têtes ajoutés en C11

| En-tête | Description | Exemples de fonctions |
|---------|-------------|----------------------|
| `<threads.h>` | Support multi-threading | `thrd_create()` - créer un thread<br>`mtx_lock()` - verrouiller un mutex<br>`cnd_wait()` - attendre condition |
| `<stdnoreturn.h>` | Fonctions sans retour | `noreturn` - spécificateur de fonction |
| `<stdalign.h>` | Alignement mémoire | `alignas()` - spécifier alignement<br>`alignof()` - obtenir alignement |
| `<stdatomic.h>` | Opérations atomiques | `atomic_load()` - lecture atomique<br>`atomic_store()` - écriture atomique<br>`atomic_fetch_add()` - addition atomique |
| `<uchar.h>` | Caractères Unicode | `mbrtoc16()` - conversion vers UTF-16<br>`c16rtomb()` - conversion depuis UTF-16 |

#### En-têtes optionnels (Annexes)

| En-tête | Description | Exemples de fonctions |
|---------|-------------|----------------------|
| `<stdckdint.h>` | Arithmétique vérifiée (C23) | `ckd_add()` - addition avec vérification overflow<br>`ckd_mul()` - multiplication vérifiée |

### Notes importantes

- **Portabilité** : Tous ces en-têtes sont standard, mais certains (comme `<threads.h>`) sont optionnels selon l'implémentation.
- **Sécurité** : Certaines fonctions comme `strcpy()` sont considérées dangereuses. C11 a introduit des versions "sécurisées" (Annexe K) comme `strcpy_s()`, mais elles ne sont pas universellement supportées.
- **Performance** : La bibliothèque standard est généralement optimisée, mais pour des cas très spécifiques, des implémentations personnalisées peuvent être nécessaires.
- **Compilation** : Pour utiliser certaines fonctions mathématiques sur Unix/Linux, il faut lier avec `-lm` (library math).

### Exemple d'utilisation

```
#include <stdio.h>   // Pour printf
#include <stdlib.h>  // Pour malloc/free
#include <string.h>  // Pour strlen, strcpy
#include <math.h>    // Pour sqrt

int main(void) {
    // Allocation dynamique
    char *message = malloc(50 * sizeof(char));
    
    // Manipulation de chaîne
    strcpy(message, "Hello, World!");
    printf("Message: %s (longueur: %zu)\n", message, strlen(message));
    
    // Mathématiques
    double racine = sqrt(16.0);
    printf("Racine de 16: %.2f\n", racine);
    
    // Libération mémoire
    free(message);
    
    return 0;
}
```

La maîtrise de la bibliothèque standard est essentielle pour tout programmeur C, car elle fournit les outils de base pour pratiquement toutes les opérations courantes.

