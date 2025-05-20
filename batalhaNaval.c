#include <stdio.h>
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    int navio1_linha = 2;
    int navio1_coluna = 3;
    if (navio1_linha >= 0 && navio1_linha < TAMANHO_TABULEIRO &&
        navio1_coluna >= 0 && (navio1_coluna + TAMANHO_NAVIO) <= TAMANHO_TABULEIRO) {
        // Posiciona o Navio 1 no tabuleiro (valor 3)
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[navio1_linha][navio1_coluna + i] = 3;
        }
    } else {
        printf("Erro: Coordenadas do Navio 1 (horizontal) fora dos limites do tabuleiro ou inválidas.\n");
    }

    int navio2_linha = 5;
    int navio2_coluna = 1;
    if (navio2_linha >= 0 && (navio2_linha + TAMANHO_NAVIO) <= TAMANHO_TABULEIRO &&
        navio2_coluna >= 0 && navio2_coluna < TAMANHO_TABULEIRO) {

        int sobreposto = 0;

        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[navio2_linha + i][navio2_coluna] == 3) {
                sobreposto = 1;
                break;
            }
        }

        if (!sobreposto) {
            
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[navio2_linha + i][navio2_coluna] = 3;
            }
        } else {
            printf("Erro: Navio 2 (vertical) se sobrepõe ao Navio 1. Não foi possível posicionar.\n");
        }
    } else {
        printf("Erro: Coordenadas do Navio 2 (vertical) fora dos limites do tabuleiro ou inválidas.\n");
    }

    // --- Exibição do Tabuleiro ---
    printf("\n--- Tabuleiro de Batalha Naval ---\n");
    printf("   ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%2d ", j);
    }
    printf("\n");
    printf("   ------------------------------\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d |", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("----------------------------------\n");

    return 0;
}