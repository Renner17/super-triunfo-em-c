#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "");

    // Variáveis da carta 1
    char estado1, codigo_carta1[10], cidade1[25];
    int populacao1, pontosTuristicos1;
    float area1, pib1;

    // Variáveis da carta 2
    char estado2, codigo_carta2[10], cidade2[25];
    int populacao2, pontosTuristicos2;
    float area2, pib2;

    // --- Entrada dos dados da Carta 1 ---
    printf("Cadastro da Carta 1\n");
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Digite o Codigo da Carta (ex: A01): ");
    scanf(" %s", codigo_carta1);

    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", cidade1);

    printf("Digite a População: ");
    scanf("%d", &populacao1);

    printf("Digite a Área (em km²): ");
    scanf("%f", &area1);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib1);

    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // --- Entrada dos dados da Carta 2 ---
    printf("\nCadastro da Carta 2\n");
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Digite o Codigo da Carta (ex: A01): ");
    scanf(" %s", codigo_carta2);

    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", cidade2);

    printf("Digite a População: ");
    scanf("%d", &populacao2);

    printf("Digite a Área (em km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib2);

    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // --- Exibição resumida das cartas ---
    printf("\n--- Carta 1 ---\n");
    printf("Cidade: %s | População: %d | Área: %.2f | PIB: %.2f | Pontos Turísticos: %d\n", 
            cidade1, populacao1, area1, pib1, pontosTuristicos1);

    printf("\n--- Carta 2 ---\n");
    printf("Cidade: %s | População: %d | Área: %.2f | PIB: %.2f | Pontos Turísticos: %d\n", 
            cidade2, populacao2, area2, pib2, pontosTuristicos2);

    // --- Cálculo de densidade demográfica ---
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;

    // --- Escolha dos atributos ---
    int escolha1, escolha2;

    printf("\nEscolha o primeiro atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &escolha1);

    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    // Menu dinâmico: não mostra a opção já escolhida
    for (int i = 1; i <= 5; i++) {
        if (i != escolha1) {
            switch (i) {
                case 1: printf("1 - População\n"); break;
                case 2: printf("2 - Área\n"); break;
                case 3: printf("3 - PIB\n"); break;
                case 4: printf("4 - Pontos Turísticos\n"); break;
                case 5: printf("5 - Densidade Demográfica\n"); break;
            }
        }
    }
    printf("Opção: ");
    scanf("%d", &escolha2);

    // --- Função auxiliar de comparação ---
    float valor1A = 0, valor2A = 0, valor1B = 0, valor2B = 0;

    // Atributo 1
    switch (escolha1) {
        case 1: valor1A = populacao1; valor2A = populacao2; break;
        case 2: valor1A = area1; valor2A = area2; break;
        case 3: valor1A = pib1; valor2A = pib2; break;
        case 4: valor1A = pontosTuristicos1; valor2A = pontosTuristicos2; break;
        case 5: valor1A = densidade1; valor2A = densidade2; break;
        default: printf("Opção inválida!\n"); return 0;
    }

    // Atributo 2
    switch (escolha2) {
        case 1: valor1B = populacao1; valor2B = populacao2; break;
        case 2: valor1B = area1; valor2B = area2; break;
        case 3: valor1B = pib1; valor2B = pib2; break;
        case 4: valor1B = pontosTuristicos1; valor2B = pontosTuristicos2; break;
        case 5: valor1B = densidade1; valor2B = densidade2; break;
        default: printf("Opção inválida!\n"); return 0;
    }

    // --- Comparações individuais ---
    int pontos1 = 0, pontos2 = 0;

    // Primeiro atributo
    if (escolha1 == 5) { // densidade (menor vence)
        (valor1A < valor2A) ? pontos1++ : (valor2A < valor1A ? pontos2++ : 0);
    } else {
        (valor1A > valor2A) ? pontos1++ : (valor2A > valor1A ? pontos2++ : 0);
    }

    // Segundo atributo
    if (escolha2 == 5) { // densidade (menor vence)
        (valor1B < valor2B) ? pontos1++ : (valor2B < valor1B ? pontos2++ : 0);
    } else {
        (valor1B > valor2B) ? pontos1++ : (valor2B > valor1B ? pontos2++ : 0);
    }

    // --- Soma dos valores escolhidos ---
    float soma1 = valor1A + valor1B;
    float soma2 = valor2A + valor2B;

    printf("\n--- Resultado Final ---\n");
    printf("%s -> %.2f + %.2f = %.2f\n", cidade1, valor1A, valor1B, soma1);
    printf("%s -> %.2f + %.2f = %.2f\n", cidade2, valor2A, valor2B, soma2);

    if (soma1 > soma2) {
        printf("Vencedor: %s\n", cidade1);
    } else if (soma2 > soma1) {
        printf("Vencedor: %s\n", cidade2);
    } else {
        printf("Empate!\n");
    }

    return 0;
}
