#include <stdio.h>

void inicializarTabuleiro(int tab[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tab[i][j] = 0;
        }
    }
}

void exibirTabuleiro(int tab[10][10]) {
    printf("\nTABULEIRO BATALHA NAVAL\n");

    printf("  "); 
    for (int j = 0; j < 10; j++) {
        printf("%d ", j);
    }
    printf("\n");

    for (int i = 0; i < 10; i++) {
        printf("%d ", i); 
        for (int j = 0; j < 10; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n"); 
    }
}

int posicionarNavio(int tab[10][10], int lin, int col, int tamanho, int orientacao) {
    
    if (orientacao == 1) {
        if (col + tamanho > 10) {
            printf("Erro: Navio horizontal (tam %d) em (%d, %d) sai dos limites do tabuleiro.\n", tamanho, lin, col);
            return 0; 
        }
    } else {
        if (lin + tamanho > 10) {
            printf("Erro: Navio vertical (tam %d) em (%d, %d) sai dos limites do tabuleiro.\n", tamanho, lin, col);
            return 0; 
        }
    }

    for (int i = 0; i < tamanho; i++) {
        if (orientacao == 1) {
            if (tab[lin][col + i] == 3) {
                printf("Erro: Sobreposicao detectada em (%d, %d) ao tentar por navio horizontal.\n", lin, col + i);
                return 0; 
            }
        } else { 
            if (tab[lin + i][col] == 3) {
                printf("Erro: Sobreposicao detectada em (%d, %d) ao tentar por navio vertical.\n", lin + i, col);
                return 0; 
            }
        }
    }

    for (int i = 0; i < tamanho; i++) {
        if (orientacao == 1) {
            tab[lin][col + i] = 3;
        } else { 
            tab[lin + i][col] = 3;
        }
    }

    printf("Navio (tam %d) posicionado com sucesso em (%d, %d).\n", tamanho, lin, col);
    return 1; 
}

int main() {
    int tabuleiro[10][10];

    inicializarTabuleiro(tabuleiro);

    int lin1 = 2, col1 = 3;
    int sucessoNavio1 = posicionarNavio(tabuleiro, lin1, col1, 3, 1);

    int lin2 = 5, col2 = 7;
    int sucessoNavio2 = posicionarNavio(tabuleiro, lin2, col2, 3, 0);

    if (sucessoNavio1 && sucessoNavio2) {
        exibirTabuleiro(tabuleiro);
    } else {
        printf("\nUm ou mais navios falharam ao ser posicionados. Tabuleiro final nao sera exibido.\n");
    }
    
    return 0;
}