#include <stdio.h>
#define linhas 10
#define colunas 10
#define agua 0
#define navio 3
void tabuleiro_inicial(int tabu[linhas][colunas]) {
    printf("\nNavio posicionado:\n");
    printf("  "); // Espaço para alinhar com os números das colunas
    for (int j = 0; j < colunas; j++) {
        printf("%d ", j);
    }
    printf("\n");
    for (int i = 0; i < linhas; i++) {
        printf("%d ", i);
        for (int j = 0; j < colunas; j++) {
            if (tabu[i][j] == agua) {
                printf("0 "); 
            } else if (tabu[i][j] == navio) {
                printf("3 "); 
            } else {
                printf("%d ", tabu[i][j]); 
            }
        }
        printf("\n");
    }
}
void posicionar(int tabu[linhas][colunas]) {
    int op;
    do {
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
        printf("Escolha em que direção deseja posicionar o navio:\n");
        printf("1. Horizontal\n");
        printf("2. Vertical\n");
        printf("3. Diagonal Esquerda\n");
        printf("4. Diagonal Direita\n");
        printf("5. Voltar\n");
        if (scanf("%d", &op) != 1 || op < 1 || op > 5) {
            printf("Entrada inválida. Tente novamente.\n");
            while (getchar() != '\n');          // limpa o buffer de entrada
            continue;
        }
        if (op == 5) {
            printf("** Hora do ataque **\n");
            break;
        }
        int linha_barco, coluna_barco;
        printf("Digite a linha para posicionar o navio (0 a 9):\n");
        if (scanf("%d", &linha_barco) != 1 || linha_barco < 0 || linha_barco >= linhas) {
            printf("Entrada inválida. Tente novamente.\n");
            while (getchar() != '\n');
            continue;
        }
        printf("Digite a coluna para posicionar o navio (0 a 9):\n");
        if (scanf("%d", &coluna_barco) != 1 || coluna_barco < 0 || coluna_barco >= colunas) {
            printf("Entrada inválida. Tente novamente.\n");
            while (getchar() != '\n'); 
            continue;
        }
        int certinho = 1;
        switch (op) {
            case 1: 
                if (linha_barco >= 0 && linha_barco < linhas && coluna_barco >= 0 && coluna_barco + 2 < colunas) {
                    for (int i = 0; i < 3; i++) {
                        if (tabu[linha_barco][coluna_barco + i] != agua) {
                            certinho = 0;
                            break;
                        }
                    }
                    if (certinho) {
                        for (int i = 0; i < 3; i++) {
                            tabu[linha_barco][coluna_barco + i] = navio;
                        }
                    } else {
                        printf("Coordenadas inválidas ou já tem um navio ai\n");
                    }
                } else {
                    printf("Coordenadas inválidas\n");
                }
                break;
            case 2: 
                if (linha_barco >= 0 && linha_barco + 2 < linhas && coluna_barco >= 0 && coluna_barco < colunas) {
                    for (int i = 0; i < 3; i++) {
                        if (tabu[linha_barco + i][coluna_barco] != agua) {
                            certinho = 0;
                            break;
                        }
                    }
                    if (certinho) {
                        for (int i = 0; i < 3; i++) {
                            tabu[linha_barco + i][coluna_barco] = navio;
                        }
                    } else {
                        printf("Coordenadas inválidas ou já tem um navio ai\n");
                    }
                } else {
                    printf("Coordenadas inválidas\n");
                }
                break;
            case 3: 
                if (linha_barco >= 0 && linha_barco + 2 < linhas && coluna_barco >= 0 && coluna_barco + 2 < colunas) {
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            if (navio_diagonal_E[i][j] == 3 && tabu[linha_barco + i][coluna_barco + j] != agua) {
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
                                    tabu[linha_barco + i][coluna_barco + j] = navio;
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
                if (linha_barco >= 0 && linha_barco + 2 < linhas && coluna_barco >= 0 && coluna_barco + 2 < colunas) {
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 3; j++) {
                            if (navio_diagonal_D[i][j] == 3 && tabu[linha_barco + i][coluna_barco + j] != agua) {
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
                                    tabu[linha_barco + i][coluna_barco + j] = navio;
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
        tabuleiro_inicial(tabu);
    } while (op != 5);
}
void tabuleiroatk(int tabuatk[linhas][colunas]) {
    printf("\nTabuleiro atualizado:\n");
    printf("  "); // Espaço para alinhar com os números das colunas
    for (int j = 0; j < colunas; j++) {
        printf("%d ", j);
    }
    printf("\n");
    for (int i = 0; i < linhas; i++) {
        printf("%d ", i); 
        for (int j = 0; j < colunas; j++) {
            if (tabuatk[i][j] == agua) {
                printf("0 ");
            } else if (tabuatk[i][j] == navio) {
                printf("3 "); 
            } else if (tabuatk[i][j] == 1) {
                printf("1 "); // Onde atacou e não acertou
            } else {
                printf("%d ", tabuatk[i][j]);
            }
        }
        printf("\n");
    }
}
void especial(int tabu[linhas][colunas], int tabuatk[linhas][colunas], int forma[5][5], int linhasForma, int colunasForma, int linhaInicio, int colunaInicio) {
    int centrol = linhasForma / 2;
    int centroc = colunasForma / 2;
    for (int i = 0; i < linhasForma; i++) {
        for (int j = 0; j < colunasForma; j++) {
            int linhaPos = linhaInicio + i - centrol;
            int colunaPos = colunaInicio + j - centroc;
            if (linhaPos >= 0 && linhaPos < linhas && colunaPos >= 0 && colunaPos < colunas) {
                if (forma[i][j] == 1) {
                    if (tabu[linhaPos][colunaPos] == navio) {
                        tabuatk[linhaPos][colunaPos] = navio; 
                    } else {
                        tabuatk[linhaPos][colunaPos] = 1;
                    }
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
void jogar_especiais(int tabu[linhas][colunas], int tabu_navios[linhas][colunas], int *pontos) {
    int linha_barco, coluna_barco, escolha;
    char continuar;
    do {
        printf("Escolha o especial:\n1. Cruz\n2. Cone\n3. Octaedro\n4. Voltar\n");
        if (scanf("%d", &escolha) != 1 || escolha < 1 || escolha > 4) {
            printf("Opção inválida. Tente novamente.\n");
            while (getchar() != '\n');
            continue;
        }
        if (escolha == 4) break;
        printf("Digite a linha e a coluna que irá atacar (0 a 9):\n");
        if (scanf("%d %d", &linha_barco, &coluna_barco) != 2 || linha_barco < 0 || linha_barco >= linhas || coluna_barco < 0 || coluna_barco >= colunas) {
            printf("Coordenadas inválidas. Tente novamente.\n");
            while (getchar() != '\n');
            continue;
        }
        int (*formas[3])[5][5] = {&cruz, &cone, &octaedro};
        if (escolha >= 1 && escolha <= 3) {
            especial(tabu, tabu_navios, *formas[escolha - 1], 5, 5, linha_barco, coluna_barco);
            printf("Especial aplicado!\n");
            (pontos)++;
        }
        tabuleiroatk(tabu_navios);
        printf("Gostaria de jogar outro especial? (s/n): ");
        while (getchar() != '\n'); 
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');
}
int main() {
    int tabu[linhas][colunas] = {0}; 
    int tabuatk[linhas][colunas] = {0};
    printf("Bem-vindo ao Batalha Naval!\n");
    posicionar(tabu);
    int op;
    char voltar;
    int pontos = 0;
    do{
    printf("\n\n\n\n\n\nVez do jogador 2!\n Como você gostaria de atacar? \n1. Bomba\n2. Ataque especial \n3. Ver pontos \n4. Sair do jogo\n");
    scanf("%d", &op);
    switch(op){
        case 1:{
        do{
            printf("Digite a linha e a coluna que deseja atacar ou 'S' para voltar: ");
            int linha, coluna;
            scanf("%d %d", &linha, &coluna);
            if (linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas) {
                if (tabu[linha][coluna] == navio){
                    tabu[linha][coluna] = 1; 
                    pontos++;
                    printf("Você acertou um navio!\n");
                    tabuleiroatk(tabu);
                } else {
                    printf("Água!\n");
                }
            } else {
                printf("Coordenadas inválidas. Tente novamente.\n");
            }
            break;
        } while (voltar != 's' && voltar != 'S');}
        case 2:
            jogar_especiais(tabu, tabuatk, &pontos);
            break;
        case 3:
        printf("Você derrubou %d navios\n", pontos);
            break;
        case 4:
            printf("Obrigado por jogar!\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
            break;   
    }
} while (op != 4);
return 0;}