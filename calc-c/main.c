#include <stdio.h>
#include "fonctions.h"

int main() {
    long double a, b, resultat;
    char op;

    printf("Opérations possibles :addition +, soustraction -, multiplication *, division /, puissance ^, racine carré r.");
    printf("Entrez une opération (ex: 4.5 * 2 ou r 9) : ");
    scanf(" %c", &op);

// La racine carré se fait avec 1 seul chiffre, on le traite avant
    if (op == 'r') {
        scanf("%Lf", &a);
        resultat = racineCarree(a);
        printf("Résultat = %Lf\n", resultat);
        return 0;
    }

    scanf("%Lf %Lf", &a, &b);

    switch (op) {
        case '+': resultat = addition(a, b); break;
        case '-': resultat = soustraction(a, b); break;
        case '*': resultat = multiplication(a, b); break;
        case '/': resultat = division(a, b); break;
        case '^': resultat = puissance(a, b); break;
        default:
            printf("Opérateur inconnu.\n");
            return 1;
    }

    printf("Résultat = %Lf\n", resultat);
    return 0;
}
