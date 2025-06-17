#include <stdio.h>

#define ESTADOS 8
#define CIDADES_POR_ESTADO 4
#define TOTAL_CIDADES (ESTADOS * CIDADES_POR_ESTADO)

typedef struct {
    char codigo[4];
    int populacao;
    float area;
    float pib;
    int turismo;
    float densidade;
    float pib_per_capita;
    float poder_total;
} Cidade;

Cidade cidades[TOTAL_CIDADES] = {
    {"A01", 500000, 300.5, 15.2, 10},
    {"A02", 1200000, 450.2, 25.8, 15},
    {"B01", 800000, 350.0, 18.5, 12},
    {"B02", 950000, 400.3, 22.1, 14},
    {"C01", 600000, 280.7, 14.0, 9},
    {"C02", 1100000, 500.1, 30.0, 20},
    {"D01", 700000, 320.4, 17.3, 11},
    {"D02", 1050000, 470.6, 27.5, 18}
};

void calcularAtributos(Cidade *c) {
    c->densidade = (c->area > 0) ? (c->populacao / c->area) : 0.0;
    c->pib_per_capita = (c->populacao > 0) ? (c->pib / c->populacao) : 0.0;
    c->poder_total = c->populacao + c->area + c->pib + c->turismo;
}

void mostrarCidades() {
    for (int i = 0; i < TOTAL_CIDADES; i++) {
        calcularAtributos(&cidades[i]);
        printf("\n[%d] Cidade: %s\n", i, cidades[i].codigo);
        printf("População: %d\n", cidades[i].populacao);
        printf("Densidade: %.2f hab/km²\n", cidades[i].densidade);
        printf("Área: %.2f km²\n", cidades[i].area);
        printf("PIB: %.2f bilhões USD\n", cidades[i].pib);
        printf("PIB per capita: %.2f USD\n", cidades[i].pib_per_capita * 1e6);
        printf("Pontos turísticos: %d\n", cidades[i].turismo);
        printf("Poder Total: %.2f\n", cidades[i].poder_total);
    }
}

void editarCidade() {
    int indice;
    printf("\nInforme o índice da cidade (0 a %d): ", TOTAL_CIDADES - 1);
    scanf("%d", &indice);

    if (indice < 0 || indice >= TOTAL_CIDADES) {
        printf("Índice inválido!\n");
        return;
    }

    printf("Alterando cidade %s\n", cidades[indice].codigo);
    printf("Nova população: ");
    scanf("%d", &cidades[indice].populacao);
    printf("Nova área (km²): ");
    scanf("%f", &cidades[indice].area);
    printf("Novo PIB (bilhões USD): ");
    scanf("%f", &cidades[indice].pib);
    printf("Novos pontos turísticos: ");
    scanf("%d", &cidades[indice].turismo);

    calcularAtributos(&cidades[indice]);
    printf("Cidade atualizada com sucesso!\n");
}

float obterValor(Cidade c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.densidade;
        case 3: return c.area;
        case 4: return c.pib;
        case 5: return c.pib_per_capita;
        case 6: return c.turismo;
        case 7: return c.poder_total;
        default: return 0.0;
    }
}

void compararSimples() {
    int a, b, op;
    printf("\nDigite os índices das cidades (0 a %d): ", TOTAL_CIDADES - 1);
    scanf("%d %d", &a, &b);

    if (a < 0 || a >= TOTAL_CIDADES || b < 0 || b >= TOTAL_CIDADES) {
        printf("Índices inválidos!\n");
        return;
    }

    calcularAtributos(&cidades[a]);
    calcularAtributos(&cidades[b]);

    printf("\n*** Propriedade para comparar ***\n");
    printf("1. População\n2. Densidade (Menor vence)\n3. Área\n4. PIB\n5. PIB per capita\n6. Turismo\n7. Poder Total\n");
    printf("Escolha: ");
    scanf("%d", &op);

    char *vencedor = NULL;

    switch (op) {
        case 1:
            vencedor = (cidades[a].populacao > cidades[b].populacao) ? cidades[a].codigo : cidades[b].codigo;
            break;
        case 2:
            vencedor = (cidades[a].densidade < cidades[b].densidade) ? cidades[a].codigo : cidades[b].codigo;
            break;
        case 3:
            vencedor = (cidades[a].area > cidades[b].area) ? cidades[a].codigo : cidades[b].codigo;
            break;
        case 4:
            vencedor = (cidades[a].pib > cidades[b].pib) ? cidades[a].codigo : cidades[b].codigo;
            break;
        case 5:
            vencedor = (cidades[a].pib_per_capita > cidades[b].pib_per_capita) ? cidades[a].codigo : cidades[b].codigo;
            break;
        case 6:
            vencedor = (cidades[a].turismo > cidades[b].turismo) ? cidades[a].codigo : cidades[b].codigo;
            break;
        case 7:
            vencedor = (cidades[a].poder_total > cidades[b].poder_total) ? cidades[a].codigo : cidades[b].codigo;
            break;
        default:
            printf("Opção inválida!\n");
            return;
    }

    printf("Cidade vencedora: %s\n", vencedor);
}

void compararAvancado() {
    int a, b, atr1, atr2;

    printf("\nDigite os índices das cidades (0 a %d): ", TOTAL_CIDADES - 1);
    scanf("%d %d", &a, &b);

    if (a < 0 || a >= TOTAL_CIDADES || b < 0 || b >= TOTAL_CIDADES) {
        printf("Índices inválidos!\n");
        return;
    }

    calcularAtributos(&cidades[a]);
    calcularAtributos(&cidades[b]);

    printf("\nEscolha o primeiro atributo (1-7): ");
    scanf("%d", &atr1);

    do {
        printf("Escolha o segundo atributo (diferente do primeiro): ");
        scanf("%d", &atr2);
    } while (atr2 == atr1 || atr2 < 1 || atr2 > 7);

    float v1a = obterValor(cidades[a], atr1);
    float v1b = obterValor(cidades[b], atr1);
    float v2a = obterValor(cidades[a], atr2);
    float v2b = obterValor(cidades[b], atr2);

    float totalA = (atr1 == 2 ? -v1a : v1a) + (atr2 == 2 ? -v2a : v2a);
    float totalB = (atr1 == 2 ? -v1b : v1b) + (atr2 == 2 ? -v2b : v2b);

    printf("\nComparação entre %s e %s:\n", cidades[a].codigo, cidades[b].codigo);
    printf("%s: %.2f\n%s: %.2f\n", cidades[a].codigo, totalA, cidades[b].codigo, totalB);

    if (totalA > totalB)
        printf("Vencedora: %s\n", cidades[a].codigo);
    else if (totalB > totalA)
        printf("Vencedora: %s\n", cidades[b].codigo);
    else
        printf("Empate!\n");
}

void mostrarRegras() {
    printf("\nRegras do Jogo:\n");
    printf("1. Cada cidade possui atributos como população, PIB e turismo.\n");
    printf("2. Você pode comparar cidades usando esses atributos.\n");
    printf("3. A melhor cidade vence a rodada.\n");
}

void menu() {
    int op;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Mostrar Cidades\n");
        printf("2. Editar Cidade\n");
        printf("3. Comparar Cidades (Simples)\n");
        printf("4. Comparar Cidades (Avançado)\n");
        printf("5. Ver Regras\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &op);

        switch (op) {
            case 1: mostrarCidades(); break;
            case 2: editarCidade(); break;
            case 3: compararSimples(); break;
            case 4: compararAvancado(); break;
            case 5: mostrarRegras(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida!\n");
        }
    } while (op != 0);
}

int main() {
    menu();
    return 0;
}
