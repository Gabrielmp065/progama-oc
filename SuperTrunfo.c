#include <stdio.h>
#include <string.h>

#define NUM_ESTADOS 8
#define CIDADES_POR_ESTADO 4
#define CARTAS_TOTAL (NUM_ESTADOS * CIDADES_POR_ESTADO)

typedef struct {
    char codigo[4];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;

Carta cartas[CARTAS_TOTAL] = {
    {"A01", 500000, 300.5, 15.2, 10},
    {"A02", 1200000, 450.2, 25.8, 15},
    {"B01", 800000, 350.0, 18.5, 12},
    {"B02", 950000, 400.3, 22.1, 14},
    {"C01", 600000, 280.7, 14.0, 9},
    {"C02", 1100000, 500.1, 30.0, 20},
    {"D01", 700000, 320.4, 17.3, 11},
    {"D02", 1050000, 470.6, 27.5, 18}
};

void calcularPropriedades(Carta *carta) {
    carta->densidade_populacional = (carta->area > 0) ? (carta->populacao / carta->area) : 0.0;
    carta->pib_per_capita = (carta->populacao > 0) ? (carta->pib / carta->populacao) : 0.0;
    carta->super_poder = carta->populacao + carta->area + carta->pib + carta->pontos_turisticos;
}

void exibirCartas() {
    printf("\nCartas cadastradas:\n");
    for (int i = 0; i < CARTAS_TOTAL; i++) {
        calcularPropriedades(&cartas[i]);
        printf("\n[%d] Cidade: %s\n", i, cartas[i].codigo);
        printf("População: %d\n", cartas[i].populacao);
        printf("Densidade populacional: %.2f hab/km²\n", cartas[i].densidade_populacional);
        printf("Área: %.2f km²\n", cartas[i].area);
        printf("PIB: %.2f bilhões USD\n", cartas[i].pib);
        printf("PIB per capita: %.2f USD\n", cartas[i].pib_per_capita * 1e6);
        printf("Pontos turísticos: %d\n", cartas[i].pontos_turisticos);
        printf("Super Poder: %.2f\n", cartas[i].super_poder);
    }
}

void alterarCarta() {
    int idx;
    printf("\nDigite o índice da carta (0 a %d): ", CARTAS_TOTAL - 1);
    scanf("%d", &idx);
    if (idx < 0 || idx >= CARTAS_TOTAL) {
        printf("Índice inválido!\n");
        return;
    }

    printf("\nAlterando cidade %s\n", cartas[idx].codigo);
    printf("Nova população: ");
    scanf("%d", &cartas[idx].populacao);
    printf("Nova área (km²): ");
    scanf("%f", &cartas[idx].area);
    printf("Novo PIB (bilhões USD): ");
    scanf("%f", &cartas[idx].pib);
    printf("Novos pontos turísticos: ");
    scanf("%d", &cartas[idx].pontos_turisticos);

    calcularPropriedades(&cartas[idx]);
    printf("Carta atualizada com sucesso!\n");
}

void compararCartas() {
    int idx1, idx2;
    printf("\nDigite os índices das cartas para comparar (0 a %d): ", CARTAS_TOTAL - 1);
    scanf("%d %d", &idx1, &idx2);

    if (idx1 < 0 || idx1 >= CARTAS_TOTAL || idx2 < 0 || idx2 >= CARTAS_TOTAL) {
        printf("Índices inválidos!\n");
        return;
    }

    calcularPropriedades(&cartas[idx1]);
    calcularPropriedades(&cartas[idx2]);

    printf("\n *** Escolha a propriedade que deseja comparar: *** \n");
    printf("1. População (Maior vence)\n");
    printf("2. Densidade populacional (Menor vence)\n");
    printf("3. Área (Maior vence)\n");
    printf("4. PIB (Maior vence)\n");
    printf("5. PIB per capita (Maior vence)\n");
    printf("6. Pontos turísticos (Maior vence)\n");
    printf("7. Super Poder (Maior vence)\n");
    printf("Escolha uma opção: ");
    int opcao;
    scanf("%d", &opcao);

    char *vencedor = NULL;

    switch (opcao) {
        case 1:
            vencedor = (cartas[idx1].populacao > cartas[idx2].populacao) ? cartas[idx1].codigo : cartas[idx2].codigo;
            break;
        case 2:
            vencedor = (cartas[idx1].densidade_populacional < cartas[idx2].densidade_populacional) ? cartas[idx1].codigo : cartas[idx2].codigo;
            break;
        case 3:
            vencedor = (cartas[idx1].area > cartas[idx2].area) ? cartas[idx1].codigo : cartas[idx2].codigo;
            break;
        case 4:
            vencedor = (cartas[idx1].pib > cartas[idx2].pib) ? cartas[idx1].codigo : cartas[idx2].codigo;
            break;
        case 5:
            vencedor = (cartas[idx1].pib_per_capita > cartas[idx2].pib_per_capita) ? cartas[idx1].codigo : cartas[idx2].codigo;
            break;
        case 6:
            vencedor = (cartas[idx1].pontos_turisticos > cartas[idx2].pontos_turisticos) ? cartas[idx1].codigo : cartas[idx2].codigo;
            break;
        case 7:
            vencedor = (cartas[idx1].super_poder > cartas[idx2].super_poder) ? cartas[idx1].codigo : cartas[idx2].codigo;
            break;
        default:
            printf("Opção inválida!\n");
            return;
    }

    printf("Cidade vencedora: %s\n", vencedor);
}

float obterValorAtributo(Carta carta, int atributo) {
    switch (atributo) {
        case 1: return carta.populacao;
        case 2: return carta.densidade_populacional;
        case 3: return carta.area;
        case 4: return carta.pib;
        case 5: return carta.pib_per_capita;
        case 6: return carta.pontos_turisticos;
        case 7: return carta.super_poder;
        default: return 0;
    }
}

void compararCartasAvancado() {
    int idx1, idx2, atributo1, atributo2;

    printf("\nDigite os índices das cartas para comparar (0 a %d): ", CARTAS_TOTAL - 1);
    scanf("%d %d", &idx1, &idx2);

    if (idx1 < 0 || idx1 >= CARTAS_TOTAL || idx2 < 0 || idx2 >= CARTAS_TOTAL) {
        printf("Índices inválidos!\n");
        return;
    }

    calcularPropriedades(&cartas[idx1]);
    calcularPropriedades(&cartas[idx2]);

    printf("\n*** Escolha o primeiro atributo para comparação ***\n");
    printf("1. População\n2. Densidade populacional\n3. Área\n4. PIB\n5. PIB per capita\n6. Pontos turísticos\n7. Super Poder\n");
    scanf("%d", &atributo1);

    do {
        printf("\n*** Escolha o segundo atributo (diferente do primeiro) ***\n");
        for (int i = 1; i <= 7; i++) {
            if (i != atributo1) printf("%d. ", i);
        }
        scanf("%d", &atributo2);
        if (atributo2 == atributo1 || atributo2 < 1 || atributo2 > 7)
            printf("Atributo inválido ou repetido. Escolha novamente.\n");
    } while (atributo2 == atributo1 || atributo2 < 1 || atributo2 > 7);

    float val1_c1 = obterValorAtributo(cartas[idx1], atributo1);
    float val1_c2 = obterValorAtributo(cartas[idx2], atributo1);
    float val2_c1 = obterValorAtributo(cartas[idx1], atributo2);
    float val2_c2 = obterValorAtributo(cartas[idx2], atributo2);

    float total_c1 = (atributo1 == 2 ? -val1_c1 : val1_c1) + (atributo2 == 2 ? -val2_c1 : val2_c1);
    float total_c2 = (atributo1 == 2 ? -val1_c2 : val1_c2) + (atributo2 == 2 ? -val2_c2 : val2_c2);

    printf("\nComparação entre %s e %s:\n", cartas[idx1].codigo, cartas[idx2].codigo);
    printf("Soma ajustada dos atributos:\n%s: %.2f\n%s: %.2f\n", cartas[idx1].codigo, total_c1, cartas[idx2].codigo, total_c2);

    if (total_c1 > total_c2)
        printf("Vencedora: %s\n", cartas[idx1].codigo);
    else if (total_c2 > total_c1)
        printf("Vencedora: %s\n", cartas[idx2].codigo);
    else
        printf("Empate!\n");
}

void verRegras() {
    printf("\nRegras do Jogo:\n");
    printf("1. Cada carta representa uma cidade fictícia.\n");
    printf("2. Você pode editar e comparar as cartas.\n");
    printf("3. A carta com melhores atributos vence.\n");
}

void iniciaJogo() {
    int opcaoJogo;
    do {
        printf("\n--- Menu do Jogo ---\n");
        printf("1. Exibir Cartas\n");
        printf("2. Alterar Carta\n");
        printf("3. Comparar Cartas (Simples)\n");
        printf("4. Comparar Cartas (Avançado)\n");
        printf("5. Ver Regras\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcaoJogo);

        switch (opcaoJogo) {
            case 1: exibirCartas(); break;
            case 2: alterarCarta(); break;
            case 3: compararCartas(); break;
            case 4: compararCartasAvancado(); break;
            case 5: verRegras(); break;
            case 0: printf("Saindo do jogo...\n"); break;
            default: printf("Opção inválida!\n"); break;
        }
    } while (opcaoJogo != 0);
}

int main() {
    iniciaJogo();
    return 0;
}
