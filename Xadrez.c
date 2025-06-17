#include <stdio.h>

// Número máximo de casas para cada peça
const int NUM_CASAS = 3;

// ==============================
// TORRE: Movimento Recursivo
// ==============================
void moverTorreCima(int casas) {
    if (casas == 0) return;
    printf("Cima\n");
    moverTorreCima(casas - 1);
}

void moverTorreDireita(int casas) {
    if (casas == 0) return;
    printf("Direita\n");
    moverTorreDireita(casas - 1);
}

// ==============================
// BISPO: Recursivo + Loops Aninhados
// ==============================
void moverBispo(int vertical, int horizontal) {
    if (vertical == 0 || horizontal == 0) return;
    printf("Diagonal Superior Direita\n");
    moverBispo(vertical - 1, horizontal - 1);
}

void bispoComLoopsAninhados(int limite) {
    for (int v = 1; v <= limite; v++) {
        for (int h = 1; h <= limite; h++) {
            if (v == h) {
                printf("Diagonal (%d,%d)\n", v, h);
            }
        }
    }
}

// ==============================
// RAINHA: Movimento Recursivo (combina Torre + Bispo)
// ==============================
void moverRainhaVertical(int casas) {
    if (casas == 0) return;
    printf("Baixo\n");
    moverRainhaVertical(casas - 1);
}

void moverRainhaDiagonal(int casas) {
    if (casas == 0) return;
    printf("Diagonal Inferior Esquerda\n");
    moverRainhaDiagonal(casas - 1);
}

// ==============================
// CAVALO: Movimento em L com loops aninhados e controle de fluxo
// ==============================
void moverCavalo() {
    const int maxY = 8; // tabuleiro 8x8
    const int maxX = 8;
    int posX = 4, posY = 4; // posição inicial no centro

    printf("Movimentos do Cavalo (duas casas para cima e uma para a direita):\n");
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            if (i == -2 && j == 1) {
                int novoY = posY + i;
                int novoX = posX + j;
                if (novoY >= 0 && novoY < maxY && novoX >= 0 && novoX < maxX) {
                    printf("Cavalo vai para (%d,%d): Duas casas para cima e uma para a direita\n", novoY, novoX);
                    break; // interrompe após encontrar o movimento certo
                }
            } else {
                continue; // ignora os outros movimentos
            }
        }
    }
}

// ==============================
// FUNÇÃO PRINCIPAL
// ==============================
int main() {
    printf("Movimento da Torre:\n");
    moverTorreCima(NUM_CASAS);
    moverTorreDireita(NUM_CASAS);
    printf("\n");

    printf("Movimento do Bispo com recursão:\n");
    moverBispo(NUM_CASAS, NUM_CASAS);
    printf("\n");

    printf("Movimento do Bispo com loops aninhados:\n");
    bispoComLoopsAninhados(NUM_CASAS);
    printf("\n");

    printf("Movimento da Rainha:\n");
    moverRainhaVertical(NUM_CASAS);
    moverRainhaDiagonal(NUM_CASAS);
    printf("\n");

    moverCavalo();
    return 0;
}
