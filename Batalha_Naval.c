#include <stdio.h>
#define linhas 10
#define colunas 10
#define agua 0
#define navio 3

void tabuleiro_inicaial(int tabu[linhas][colunas]) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            tabu[i][j] = agua;
        }
    }
    printf("\n  "); // Espaço para alinhar com os números das linhas
    for (int j = 0; j < colunas; j++) {
        printf("%d ", j); // Imprime os números das colunas
    }
    printf("\n");
    for (int i = 0; i < linhas; i++) {
        printf("%d ", i); // Imprime os números das linhas
        for (int j = 0; j < colunas; j++) {
            if (tabu[i][j] == agua) {
                printf("0 "); 
            } else if (tabu[i][j] == navio) {
                printf("N "); // Representa navio com N
            } else {
                printf("%d ", tabu[i][j]); // Imprime outros valores diretamente
            }
        }
        printf("\n");
    }
}

int verificar_posicionamento(int tabu[linhas][colunas], int linha, int coluna, int navios[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (navios[i][j] == navio && 
                (linha + i >= linhas || coluna + j >= colunas || tabu[linha + i][coluna + j] != agua)) {
                return 0; // Posição inválida
            }
        }
    }
    return 1; // Posição válida
}

void aplicar_navio(int tabu[linhas][colunas], int linha, int coluna, int navios[3][3], int tamanho) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (navios[i][j] == navio) {
                tabu[linha + i][coluna + j] = navios[i][j];
            }
        }
    }
}
void posicionar(int tabu[linhas][colunas]) {
    int op;
    do {
        int navio_orizontal[3][1] = {{3}, {3}, {3}};
        int navio_vertical[1][3] = {{3, 3, 3}};
        int navio_diagonal_E[3][3] = {
            {3, 0, 0},
            {0, 3, 0},
            {0, 0, 3}
        };
        int navio_diagonal_D[3][3] = {
            {0, 0, 3},
            {0, 3, 0},
            {3, 0, 0}
        };

        // Menu de opções
        printf("Escolha em que direção deseja posicionar o navio:\n");
        printf("1. Horizontal\n");
        printf("2. Vertical\n");
        printf("3. Diagonal Esquerda\n");
        printf("4. Diagonal Direita\n");
        printf("5. Voltar\n");
        if (scanf("%d", &op) != 1 || op < 1 || op > 5) {
            printf("Entrada inválida. Tente novamente.\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
            continue;
        }

        if (op == 5) {
            printf("** Hora do ataque **\n");
            break;
        }

        int linha_barco, coluna_barco;

        // Entrada da linha
        printf("Digite a linha para posicionar o navio (0 a 9):\n");
        if (scanf("%d", &linha_barco) != 1 || linha_barco < 0 || linha_barco >= linhas) {
            printf("Entrada inválida. Tente novamente.\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
            continue;
        }

        // Entrada da coluna
        printf("Digite a coluna para posicionar o navio (0 a 9):\n");
        if (scanf("%d", &coluna_barco) != 1 || coluna_barco < 0 || coluna_barco >= colunas) {
            printf("Entrada inválida. Tente novamente.\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
            continue;
        }

        int valido = 0;

        // Verifica e aplica o navio com base na opção escolhida
        switch (op) {
            case 1: // Horizontal
                valido = verificar_posicionamento(tabu, linha_barco, coluna_barco, navio_orizontal, 3);
                if (valido) {
                    aplicar_navio(tabu, linha_barco, coluna_barco, navio_orizontal, 3);
                } else {
                    printf("Coordenadas inválidas ou sobreposição detectada\n");
                }
                break;

            case 2: // Vertical
                valido = verificar_posicionamento(tabu, linha_barco, coluna_barco, navio_vertical, 3);
                if (valido) {
                    aplicar_navio(tabu, linha_barco, coluna_barco, navio_vertical, 3);
                } else {
                    printf("Coordenadas inválidas ou sobreposição detectada\n");
                }
                break;

            case 3: // Diagonal Esquerda
                valido = verificar_posicionamento(tabu, linha_barco, coluna_barco, navio_diagonal_E, 3);
                if (valido) {
                    aplicar_navio(tabu, linha_barco, coluna_barco, navio_diagonal_E, 3);
                } else {
                    printf("Coordenadas inválidas ou sobreposição detectada\n");
                }
                break;

            case 4: // Diagonal Direita
                valido = verificar_posicionamento(tabu, linha_barco, coluna_barco, navio_diagonal_D, 3);
                if (valido) {
                    aplicar_navio(tabu, linha_barco, coluna_barco, navio_diagonal_D, 3);
                } else {
                    printf("Coordenadas inválidas ou sobreposição detectada\n");
                }
                break;

            default:
                printf("Opção inválida\n");
                break;
        }

        // Exibe mensagem de erro se a posição for inválida
        if (!valido) {
            printf("Coordenadas inválidas ou sobreposição detectada\n");
        } else {
            // Exibe o tabuleiro atualizado
            printf("\nTabuleiro atualizado:\n");
            tabuleiro_inicaial(tabu); // Exibe o tabuleiro com o navio posicionado
        }

    } while (op != 5);
}
void tabuleiro_ataque(int tabuatk[linhas][colunas]) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            tabuatk[i][j] = agua;
        }
    }
    printf("\n  "); // Espaço para alinhar com os números das linhas
    for (int j = 0; j < colunas; j++) {
        printf("%d ", j); // Imprime os números das colunas
    }
    printf("\n");
    for (int i = 0; i < linhas; i++) {
        printf("%d ", i); // Imprime os números das linhas
        for (int j = 0; j < colunas; j++) {
            if (tabuatk[i][j] == agua) {
                printf("0 "); 
            } else if (tabuatk[i][j] == navio) {
                printf("N "); // Representa navio com N
            } else {
                printf("%d ", tabuatk[i][j]); // Imprime outros valores diretamente
            }
        }
        printf("\n");
    }
}

int main() {
    int tabu[linhas][colunas];
    tabuleiro_inicaial(tabu); // Exibe o tabuleiro inicial
    posicionar(tabu); 
    return 0;
}
