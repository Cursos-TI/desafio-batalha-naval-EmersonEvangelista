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
            printf("Erro: Navio horizontal (tam %d) em (%d, %d) sai dos limites.\n", tamanho, lin, col);
            return 0; 
        }
    } else if (orientacao == 0) { 
        if (lin + tamanho > 10) {
            printf("Erro: Navio vertical (tam %d) em (%d, %d) sai dos limites.\n", tamanho, lin, col);
            return 0; 
        }
    } else if (orientacao == 2) { 
        if (lin + tamanho > 10 || col + tamanho > 10) {
            printf("Erro: Navio diag-principal (tam %d) em (%d, %d) sai dos limites.\n", tamanho, lin, col);
            return 0; 
        }
    } else if (orientacao == 3) { 
        if (lin + tamanho > 10 || col - tamanho + 1 < 0) {
            printf("Erro: Navio diag-secundaria (tam %d) em (%d, %d) sai dos limites.\n", tamanho, lin, col);
            return 0; 
        }
    } else {
        printf("Erro: Orientacao %d desconhecida.\n", orientacao);
        return 0;
    }

    for (int i = 0; i < tamanho; i++) {
        int L = lin, C = col; 
        if (orientacao == 1) { C = col + i; }
        else if (orientacao == 0) { L = lin + i; }
        else if (orientacao == 2) { L = lin + i; C = col + i; }
        else if (orientacao == 3) { L = lin + i; C = col - i; }
        
        if (tab[L][C] == 3) {
            printf("Erro: Sobreposicao detectada em (%d, %d).\n", L, C);
            return 0; 
        }
    }

    for (int i = 0; i < tamanho; i++) {
        if (orientacao == 1) {
            tab[lin][col + i] = 3;
        } else if (orientacao == 0) {
            tab[lin + i][col] = 3;
        } else if (orientacao == 2) {
            tab[lin + i][col + i] = 3;
        } else if (orientacao == 3) {
            tab[lin + i][col - i] = 3;
        }
    }

    printf("Navio (tam %d, ori %d) posicionado com sucesso em (%d, %d).\n", tamanho, orientacao, lin, col);
    return 1; 
}

int main() {
    int tabuleiro[10][10];
    int navio_tam = 3; 

    inicializarTabuleiro(tabuleiro);

    int s1 = posicionarNavio(tabuleiro, 1, 1, navio_tam, 1);
    int s2 = posicionarNavio(tabuleiro, 3, 8, navio_tam, 0);
    int s3 = posicionarNavio(tabuleiro, 3, 1, navio_tam, 2);
    int s4 = posicionarNavio(tabuleiro, 1, 8, navio_tam, 3);

    if (s1 && s2 && s3 && s4) {
        printf("\nTodos os 4 navios foram posicionados.\n");
        exibirTabuleiro(tabuleiro);
    } else {
        printf("\nUm ou mais navios falharam ao ser posicionados.\n");
        printf("Exibindo tabuleiro parcial:\n");
        exibirTabuleiro(tabuleiro); 
    }
    
    return 0;
}