#include <stdio.h>

// Tabuleiro 10x10.
// Criar 3 matrizes de habilidade separadas, cone, cruz e octaedro.
// 

int main()
{
    // Declaração da matriz do tabuleiro principal
    int tabuleiro[10][10] = {0};

    // Declaração das matrizes de habilidade
    int cone[3][5] = {0};
    int cruz[3][5] = {0};
    int octaedro[3][5] = {0};
    int navioH[] = {0, 5, 0, 6, 0, 7};  // Navio horizontal
    int navioV[] = {5, 1, 6, 1, 7, 1};  // Navio veretical
    int total_elementos = 6;

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

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            // CONE
            if (j >= 2 - i && j <= 2 + i)
            {
                cone[i][j] = 1;
            }

            // CRUZ
            if (i == 1 || j == 2)
            {
                cruz[i][j] = 1;
            }

            // OCTAEDRO
            if ((i == 0 && j == 2) || (i == 1 && j >= 1 && j <= 3) || (i == 2 && j == 2))
            {
                octaedro[i][j] = 1;
            }
        }
    }

    // Integrando habilidades ao tabuleiro principal
    int coneL = 0, coneC = 2; // Ponto de origem: Topo do cone
    int cruzL = 5, cruzC = 5; // Ponto de origem: Centro da cruz
    int octL = 8, octC = 8;   // Ponto de origem: Centro do octaedro

    // Pintando tabuleiro principal com as matrizes de habilidade
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            // Aplicando CONE
            if (cone[i][j] == 1)
            {
                int linha = coneL + i;
                int coluna = coneC + (j - 2);

                if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10)
                {
                    tabuleiro[linha][coluna] = 1;
                }
            }

            // Aplicando CRUZ
            if (cruz[i][j] == 1)
            {
                int linha = cruzL + (i - 1);
                int coluna = cruzC + (j - 2);

                if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10)
                {
                    tabuleiro[linha][coluna] = 1;
                }
            }

            // Aplicando OCTAEDRO
            if (octaedro[i][j] == 1)
            {
                int linha = octL + (i - 1);
                int coluna = octC + (j - 2);

                if (linha >= 0 && linha < 10 && coluna >= 0 && coluna < 10)
                {
                    tabuleiro[linha][coluna] = 1;
                }
            }
        }
    }

    // Impressão do Tabuleiro
    printf("Batalha Naval:\n\n");
    printf("    A B C D E F G H I J\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%2d  ", i + 1);

        for (int j = 0; j < 10; j++)
        {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}