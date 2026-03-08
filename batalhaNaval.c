#include <stdio.h>

// Represente o Tabuleiro: Utilize uma matriz 10x10.
// Inicialize todas as posições do tabuleiro com o valor 0, representando água.
// Posicione 1 navio veretical.
// Posicione 1 navio horizontal.
// Posicione 2 navios na diagonal.
// Cada navio ocupará um número fixo de 3 posições no tabuleiro.
// Você deverá escolher as coordenadas iniciais de cada navio e garantir que eles estejam completamente dentro dos limites do tabuleiro e não se sobreponham.
// Exiba o Tabuleiro: Utilize loops aninhados e o comando printf para exibir o tabuleiro no console.
// Mostre a matriz completa, com 0s representando água e 3s representando as partes dos navios.

int main()
{

    int tabuleiro[10][10] = {0};        // Tabuleiro com matriz 10x10
    int navioH[] = {0, 5, 0, 6, 0, 7};  // Navio horizontal
    int navioV[] = {5, 8, 6, 8, 7, 8};  // Navio veretical
    int navioD1[] = {1, 1, 2, 2, 3, 3}; // Navios na diagonal
    int navioD2[] = {2, 7, 3, 6, 4, 5}; // Navios na diagonal
    int total_elementos = 6;

    // Preenchendo o tabuleiro com o vetor
    for (int i = 0; i < total_elementos; i += 2)
    {
        int l = navioH[i];     // Linha
        int c = navioH[i + 1]; // Coluna
        tabuleiro[l][c] = 3;
    }
    for (int i = 0; i < total_elementos; i += 2)
    {
        int l = navioV[i];     // Linha
        int c = navioV[i + 1]; // Coluna
        tabuleiro[l][c] = 3;
    }
    for (int i = 0; i < total_elementos; i += 2)
    {
        int l = navioD1[i];     // Linha
        int c = navioD1[i + 1]; // Coluna
        tabuleiro[l][c] = 3;
    }

    for (int i = 0; i < total_elementos; i += 2)
    {
        int l = navioD2[i];     // Linha
        int c = navioD2[i + 1]; // Coluna
        tabuleiro[l][c] = 3;
    }

    printf("Batalha Naval:\n");

    // Impressão do Tabuleiro
    printf("   A B C D E F G H I J\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%2d ", i + 1);
        for (int j = 0; j < 10; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}