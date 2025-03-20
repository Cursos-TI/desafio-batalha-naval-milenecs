#include <stdio.h>
#define LINHAS 10
#define COLUNAS 10
#define AGUA 0
#define NAVIO 3

void tabuagua(int tabu[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            tabu[i][j] = AGUA;
        }
    }
}

void tabuleiro(int tabu[LINHAS][COLUNAS]) {
    printf("\n  "); // Espaço para alinhar com os números das linhas
    for (int j = 0; j < COLUNAS; j++) {
        printf("%d ", j);
    }
    printf("\n");
    for (int i = 0; i < LINHAS; i++) {
        printf("%d ", i); // Imprime os números ao lado do tabuleiro
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d ", tabu[i][j]);
        }
        printf("\n");
    }
}

void posicionar(int tabu[LINHAS][COLUNAS]) {
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
        printf("Escolha em que direçao deseja posicionar o navio:\n");
        printf("1. Horizontal\n");
        printf("2. Vertical\n");
        printf("3. diagonal Esquerda\n");
        printf("4. diagonal Direita\n");
        printf("5. Voltar\n");
        scanf("%d", &op);
        if (op == 5) {
            printf("** Hora do ataque**\n");
            break;
        }
        int linha_barco, coluna_barco;
        printf("Digite a linha para posicionar o navio (0 a 9):\n");
        if (scanf("%d", &linha_barco) != 1 || linha_barco < 0 || linha_barco >= LINHAS) {
            printf("Entrada inválida. Tente novamente.\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
            continue;
        }
        printf("Digite a coluna para posicionar o navio (0 a 9):\n");
        if (scanf("%d", &coluna_barco) != 1 || coluna_barco < 0 || coluna_barco >= COLUNAS) {
            printf("Entrada inválida. Tente novamente.\n");
            while (getchar() != '\n'); // Limpa o buffer de entrada
            continue;
        }
        int certinho = 1;
        switch (op) {
        case 1:
            if (linha_barco >= 0 && linha_barco < LINHAS && coluna_barco >= 0 && coluna_barco + 2 < COLUNAS) {
                for (int i = 0; i < 3; i++) {
                    if (tabu[linha_barco][coluna_barco + i] != AGUA) {
                        certinho = 0;
                        break;
                    }
                }
                if (certinho) {
                    for (int i = 0; i < 3; i++) {
                        tabu[linha_barco][coluna_barco + i] = navio_orizontal[i][0];
                    }
                } else {
                    printf("Coordenadas inválidas ou já tem um navio ai\n");
                }
            } else {
                printf("Coordenadas inválidas\n");
            }
            break;
        case 2:
            if (linha_barco >= 0 && linha_barco + 2 < LINHAS && coluna_barco >= 0 && coluna_barco < COLUNAS) {
                for (int i = 0; i < 3; i++) {
                    if (tabu[linha_barco + i][coluna_barco] != AGUA) {
                        certinho = 0;
                        break;
                    }
                }
                if (certinho) {
                    for (int i = 0; i < 3; i++) {
                        tabu[linha_barco + i][coluna_barco] = navio_vertical[0][i];
                    }
                } else {
                    printf("Coordenadas inválidas ou já tem um navio ai\n");
                }
            } else {
                printf("Coordenadas inválidas\n");
            }
            break;
        case 3:
            if (linha_barco >= 0 && linha_barco + 2 < LINHAS && coluna_barco >= 0 && coluna_barco + 2 < COLUNAS) {
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (navio_diagonal_E[i][j] == 3 && tabu[linha_barco + i][coluna_barco + j] != AGUA) {
                            certinho = 0;
                            break;
                        }
                    }
                    if (!certinho) break;
                }
                if (certinho) {
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            if (navio_diagonal_E[i][j] == 3) {
                                tabu[linha_barco + i][coluna_barco + j] = navio_diagonal_E[i][j];
                            }
                        }
                    }
                } else {
                    printf("Coordenadas inválidas ou já tem um navio ai\n");
                }
            } else {
                printf("Coordenadas inválidas\n");
            }
            break;
        case 4:
            if (linha_barco >= 0 && linha_barco + 2 < LINHAS && coluna_barco >= 0 && coluna_barco + 2 < COLUNAS) {
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (navio_diagonal_D[i][j] == 3 && tabu[linha_barco + i][coluna_barco + j] != AGUA) {
                            certinho = 0;
                            break;
                        }
                    }
                    if (!certinho) break;
                }
                if (certinho) {
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            if (navio_diagonal_D[i][j] == 3) {
                                tabu[linha_barco + i][coluna_barco + j] = navio_diagonal_D[i][j];
                            }
                        }
                    }
                } else {
                    printf("Coordenadas inválidas ou sobreposição detectada\n");
                }
            } else {
                printf("Coordenadas inválidas\n");
            }
            break;
        default:
            printf("Opção inválida\n");
            break;
        }
        tabuleiro(tabu); // Atualiza o tabuleiro após posicionar o navio
    } while (op != 5);
}
void especial(int tabu[LINHAS][COLUNAS], int tabu_navios[LINHAS][COLUNAS], int forma[5][5], int linhasForma, int colunasForma, int linhaInicio, int colunaInicio) {
    int centrol = linhasForma / 2;
    int centroc = colunasForma / 2;

    for (int i = 0; i < linhasForma; i++) {
        for (int j = 0; j < colunasForma; j++) {
            int linhaPos = linhaInicio + i - centrol;
            int colunaPos = colunaInicio + j - centroc;

            // Verifica se a posição está dentro dos limites do tabuleiro
            if (linhaPos >= 0 && linhaPos < LINHAS && colunaPos >= 0 && colunaPos < COLUNAS) {
                // Aplica o especial apenas se a posição na forma for 1 e não houver um navio
                if (forma[i][j] == 1 && tabu_navios[linhaPos][colunaPos] != NAVIO) {
                    tabu_navios[linhaPos][colunaPos] = 1; // Marca como atingido
                }
            }
        }
    }
}

int cruz[5][5] = {
    {0, 0, 1, 0, 0},
    {1, 1, 1, 1, 1},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0}
};

int cone[5][5] = {
    {0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0}
};

int octaedro[5][5] = {
    {0, 0, 1, 0, 0},
    {0, 1, 1, 1, 0},
    {1, 1, 1, 1, 1},
    {0, 1, 1, 1, 0},
    {0, 0, 1, 0, 0}
};

void jogar_especiais(int tabu[LINHAS][COLUNAS], int tabu_navios[LINHAS][COLUNAS]) {
    int linha_barco, coluna_barco, escolha;
    char continuar;

    do {
        printf("Escolha o especial:\n");
        printf("1. Cruz\n");
        printf("2. Cone\n");
        printf("3. Octaedro\n");
        printf("4. Voltar\n");
        scanf("%d", &escolha);

        if (escolha == 4) break; // Voltar ao menu anterior

        printf("Digite a linha que irá atacar (0 a 9):\n");
        scanf("%d", &linha_barco);
        printf("Digite a coluna que irá atacar (0 a 9):\n");
        scanf("%d", &coluna_barco);

        if (linha_barco >= 0 && linha_barco < LINHAS && coluna_barco >= 0 && coluna_barco < COLUNAS) {
            if (tabu_navios[linha_barco][coluna_barco] == NAVIO) {
                printf("Você acertou um navio com o especial!\n");
                tabu_navios[linha_barco][coluna_barco] = 3; // Marca a posição atingida com 3
            } else {
                printf("Água!\n");
                tabu_navios[linha_barco][coluna_barco] = 1; // Marca como água
            }

            switch (escolha) {
                case 1:
                    especial(tabu, tabu_navios, cruz, 5, 5, linha_barco, coluna_barco);
                    break;
                case 2:
                    especial(tabu, tabu_navios, cone, 5, 5, linha_barco, coluna_barco);
                    break;
                case 3:
                    especial(tabu, tabu_navios, octaedro, 5, 5, linha_barco, coluna_barco);
                    break;
                default:
                    printf("Opção inválida\n");
                    break;
            }
            printf("Especial aplicado!\n");
        } else {
            printf("Coordenadas inválidas :( \n");
        }
        tabuleiro(tabu); // Atualiza o tabuleiro principal
        tabuleiro(tabu_navios);
        printf("Gostaria de jogar outro especial? (s/n): ");
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');
}

void tabuagua_navios(int tabu_navios[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            tabu_navios[i][j] = AGUA; // Inicializa o tabuleiro de navios com água
        }
    }
}
int main() {
    printf("Bem vindo ao Batalha naval\n");
    int play;
    int op_atk;
    
    int linha_atk, coluna_atk;
    int tabu[LINHAS][COLUNAS];
    int tabu_navios[LINHAS][COLUNAS]; // Tabuleiro para posicionar os navios
    tabuagua(tabu);
    tabuagua(tabu_navios);
    do {
        printf("1. Posicionar os navios\n");
        printf("2. Atacar\n");
        printf("3. Sair\n");
        scanf("%d", &play);
        switch (play) {
            case 1:
                printf("Posicione seus navios no tabuleiro de navios.\n");
                posicionar(tabu);
                break;
            case 2:
            do
            {
            printf("1. Usar bomba\n");
            printf("2. Usar especiais\n");
            printf("3. Voltar\n");
            scanf(" %d", &op_atk);
            if (op_atk == 3) break;
             switch (op_atk)
             {
             case 1:
             printf("Digite a linha que deseja atacar (0 a 9):\n");
             scanf("%d", &linha_atk);
             printf("Digite a coluna que deseja atacar (0 a 9):\n");
             scanf("%d", &coluna_atk);
             if (linha_atk >= 0 && linha_atk < LINHAS && coluna_atk >= 0 && coluna_atk < COLUNAS) {
                 if (tabu_navios[linha_atk][coluna_atk] == NAVIO) {
                     printf("Acertou um barco!\n");
                     tabu_navios[linha_atk][coluna_atk] = 3; 
                 } else {
                     printf("Água!\n");
                     tabu_navios[linha_atk][coluna_atk] = 1;
                 }
                 tabuleiro(tabu_navios); // Atualiza o tabuleiro de navios
             } else {
                 printf("Coordenadas inválidas\n");
             }
                break;
                case 2:
                jogar_especiais(tabu, tabu_navios); // Passa os dois tabuleiros
                break;
             default:
                break;
             }
            } while (op_atk != 3);
                break;
            case 3:
                printf("Obrigado por jogar!\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (play != 3);
    return 0;
}
      