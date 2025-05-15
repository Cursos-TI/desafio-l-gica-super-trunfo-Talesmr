#include <stdio.h>
#include <string.h>

int limpaBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    return 0;
}

int main() {
    int repetirMenu = 1;

    while (repetirMenu) {
        int opcao;

        // Declaração das variáveis da carta 1
        char estado1;
        char codigo1[20];
        char nomedacidade1[50];
        int populacao1;
        float area1, pib1;
        int pontosturisticos1;
        float densidade1, pibPerCapita1;

        // Declaração das variáveis da carta 2
        char estado2;
        char codigo2[20];
        char nomedacidade2[50];
        int populacao2;
        float area2, pib2;
        int pontosturisticos2;
        float densidade2, pibPerCapita2;

        
        //menu interativo
        printf("Menu Principal\n");
        printf("1. Iniciar Jogo\n");
        printf("2. Ver Regras\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limpaBuffer();

        switch (opcao) {
            case 1:
                // Entrada de dados - Carta 1
                printf("\nCarta 1:\n");
                printf("Estado: ");
                scanf(" %c", &estado1);
                limpaBuffer();

                printf("Codigo da carta: ");
                fgets(codigo1, 20, stdin);
                strtok(codigo1, "\n");

                printf("Nome da cidade: ");
                fgets(nomedacidade1, 50, stdin);
                strtok(nomedacidade1, "\n");

                printf("População: ");
                scanf("%d", &populacao1);

                printf("area (em km2): ");
                scanf("%f", &area1);

                printf("PIB (em bilhoes de reais): ");
                scanf("%f", &pib1);

                printf("Numero de pontos turisticos: ");
                scanf("%d", &pontosturisticos1);
                limpaBuffer();

                // Entrada de dados - Carta 2
                printf("\nCarta 2:\n");
                printf("Estado: ");
                scanf(" %c", &estado2);
                limpaBuffer();

                printf("Codigo da carta: ");
                fgets(codigo2, 20, stdin);
                strtok(codigo2, "\n");

                printf("Nome da cidade: ");
                fgets(nomedacidade2, 50, stdin);
                strtok(nomedacidade2, "\n");

                printf("População: ");
                scanf("%d", &populacao2);

                printf("area (em km2): ");
                scanf("%f", &area2);

                printf("PIB (em bilhoes de reais): ");
                scanf("%f", &pib2);

                printf("Numero de pontos turisticos: ");
                scanf("%d", &pontosturisticos2);

                // Calculos de densidade
                densidade1 = populacao1 / area1;
                pibPerCapita1 = (pib1 * 1000000000) / populacao1;

                densidade2 = populacao2 / area2;
                pibPerCapita2 = (pib2 * 1000000000) / populacao2;

                // Exibição dos resultados
                printf("\n=== RESULTADOS ===\n");
                printf("\nCarta 1:\n");
                printf("Estado: %c\n", estado1);
                printf("Codigo: %s\n", codigo1);
                printf("Nome da Cidade: %s\n", nomedacidade1);
                printf("População: %d\n", populacao1);
                printf("area: %.2f km\n", area1);
                printf("PIB: %.2f bilhoes de reais\n", pib1);
                printf("Pontos Turisticos: %d\n", pontosturisticos1);
                printf("Densidade Populacional: %.2f hab/km2\n", densidade1);
                printf("PIB per Capita: %.2f reais\n", pibPerCapita1);

                printf("\nCarta 2:\n");
                printf("Estado: %c\n", estado2);
                printf("Codigo: %s\n", codigo2);
                printf("Nome da Cidade: %s\n", nomedacidade2);
                printf("População: %d\n", populacao2);
                printf("area: %.2f km\n", area2);
                printf("PIB: %.2f bilhoes de reais\n", pib2);
                printf("Pontos Turisticos: %d\n", pontosturisticos2);
                printf("Densidade Populacional: %.2f hab/km2\n", densidade2);
                printf("PIB per Capita: %.2f reais\n", pibPerCapita2);
                //comparaçao de resultados
                int compararOutro = 1;
                while (compararOutro) {
                    int atributo;
                    printf("\nEscolha um atributo para comparar:\n");
                    printf("1. População\n");
                    printf("2. area\n");
                    printf("3. PIB\n");
                    printf("4. Densidade Populacional\n");
                    printf("5. PIB per Capita\n");
                    printf("Digite o numero do atributo: ");
                    scanf("%d", &atributo);

                    printf("\n=== RESULTADO DA COMPARAÇÃO ===\n");
                    printf("Atributo escolhido: ");
                    atributo == 1 ? printf("População\n") :
                    atributo == 2 ? printf("area\n") :
                    atributo == 3 ? printf("PIB\n") :
                    atributo == 4 ? printf("Densidade Populacional\n") :
                    atributo == 5 ? printf("PIB per Capita\n") : printf("Invalido\n");

                    float valor1 = atributo == 1 ? populacao1 :
                                   atributo == 2 ? area1 :
                                   atributo == 3 ? pib1 :
                                   atributo == 4 ? densidade1 :
                                   atributo == 5 ? pibPerCapita1 : 0;

                    float valor2 = atributo == 1 ? populacao2 :
                                   atributo == 2 ? area2 :
                                   atributo == 3 ? pib2 :
                                   atributo == 4 ? densidade2 :
                                   atributo == 5 ? pibPerCapita2 : 0;
                    //resultado da comparaçao
                    printf("\nCidade vencedora: ");
                    valor1 > valor2 ? printf("%s\n", nomedacidade1) :
                    valor2 > valor1 ? printf("%s\n", nomedacidade2) :
                    printf("Empate\n");

                    printf("\nDeseja comparar outro atributo?\n");
                    printf("1. Sim\n");
                    printf("2. Não (voltar ao menu principal)\n");
                    printf("Opçao: ");
                    scanf("%d", &compararOutro);
                }
                break;

            case 2:
                printf("\nRegras do Jogo:\n");
                printf("- Cada jogador insere uma carta de cidade.\n");
                printf("- O jogo calcula densidade populacional e PIB per capita.\n");
                printf("- Escolha um atributo para comparar e veja qual cidade vence.\n");
                printf("\nPressione ENTER para voltar ao menu...\n");
                limpaBuffer();
                getchar();
                break;

            case 3:
                printf("\nSaindo... Obrigado por jogar!\n");
                repetirMenu = 0;
                break;

            default:
                printf("\nOpção invalida. Tente novamente.\n");
        }
    }
    return 0;
}
