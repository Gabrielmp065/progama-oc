#include <stdio.h>

typedef struct {
    char nome[20];
    int populacao;      // Em milhões
    float area;         // Em mil km²
    float pib;          // Em trilhões
    float densidade;    // Habitantes por km²
} Carta;

// Função para exibir menu e escolher atributo
int escolherAtributo(int bloqueado) {
    int opcao;
    printf("\nEscolha um atributo:\n");

    if (bloqueado != 1) printf("1 - População\n");
    if (bloqueado != 2) printf("2 - Área\n");
    if (bloqueado != 3) printf("3 - PIB\n");
    if (bloqueado != 4) printf("4 - Densidade Demográfica\n");

    do {
        printf("Opção: ");
        scanf("%d", &opcao);
        if (opcao == bloqueado || opcao < 1 || opcao > 4) {
            printf("Atributo inválido ou já escolhido. Tente novamente.\n");
        }
    } while (opcao == bloqueado || opcao < 1 || opcao > 4);

    return opcao;
}

// Função para retornar o valor de um atributo qualquer
float obterValor(Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.densidade;
        default: return 0;
    }
}

// Função para imprimir nome do atributo
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

int main() {
    // Duas cartas fixas
    Carta pais1 = {"Brasil", 213, 8516.0, 2.0, 25.0};
    Carta pais2 = {"Canadá", 38, 9985.0, 1.8, 4.0};

    int atr1, atr2;

    printf("Comparação entre dois países!\n");
    printf("Cartas: %s vs %s\n", pais1.nome, pais2.nome);

    // Escolha dos dois atributos
    atr1 = escolherAtributo(0);
    atr2 = escolherAtributo(atr1);

    // Valores dos atributos
    float v1_a = obterValor(pais1, atr1);
    float v2_a = obterValor(pais2, atr1);

    float v1_b = obterValor(pais1, atr2);
    float v2_b = obterValor(pais2, atr2);

    // Comparação individual
    int pontos1 = 0, pontos2 = 0;

    // Comparação do primeiro atributo
    if (atr1 == 4) {
        if (v1_a < v2_a) pontos1++;
        else if (v2_a < v1_a) pontos2++;
    } else {
        if (v1_a > v2_a) pontos1++;
        else if (v2_a > v1_a) pontos2++;
    }

    // Comparação do segundo atributo
    if (atr2 == 4) {
        if (v1_b < v2_b) pontos1++;
        else if (v2_b < v1_b) pontos2++;
    } else {
        if (v1_b > v2_b) pontos1++;
        else if (v2_b > v1_b) pontos2++;
    }

    // Soma dos atributos
    float soma1 = v1_a + v1_b;
    float soma2 = v2_a + v2_b;

    printf("\n================ RESULTADO ================\n");
    printf("País 1: %s\n", pais1.nome);
    printf("%s: %.2f\n", nomeAtributo(atr1), v1_a);
    printf("%s: %.2f\n", nomeAtributo(atr2), v1_b);
    printf("Soma total: %.2f\n", soma1);

    printf("\nPaís 2: %s\n", pais2.nome);
    printf("%s: %.2f\n", nomeAtributo(atr1), v2_a);
    printf("%s: %.2f\n", nomeAtributo(atr2), v2_b);
    printf("Soma total: %.2f\n", soma2);

    printf("\nVencedor: ");
    if (soma1 > soma2) {
        printf("%s\n", pais1.nome);
    } else if (soma2 > soma1) {
        printf("%s\n", pais2.nome);
    } else {
        printf("Empate!\n");
    }

    return 0;
}
