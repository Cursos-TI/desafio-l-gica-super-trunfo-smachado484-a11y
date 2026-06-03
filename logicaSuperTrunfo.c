#include <stdio.h>
#include <string.h> //biblioteca adicionada para poder usar o strcspn()

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Definição das variáveis para armazenar as propriedades das cidades
    // Você pode utilizar o código do primeiro desafio
    char estado1, estado2;
    // estado representado por uma letra de A a H
    char codigo1[10], codigo2[10];
    // código da carta representado pela letra do estado mais um número
    char nome_da_cidade1[50], nome_da_cidade2[50];
    // nome da cidade
    unsigned long int populacao1, populacao2;
    // População - o número de habitantes da cidade
    float area1, area2;
    // a área da cidade em km²
    float pib1, pib2;
    // O produto interno da cidade
    int pontos_turisticos1, pontos_turisticos2;
    // Número de pontos turísticos da cidade
    float densidade_populacional1, densidade_populacional2;
    // Variável para calcular a densidade populacional
    float pib_per_capita1, pib_per_capita2;
    // Variável para calcular o PIB per capita
    float superpoder1, superpoder2;
    // Variável para calcular o super poder da carta
    int opcao1, opcao2;
    //Variável para escolha do menu
 
    printf("*** SUPER TRUNFO ***\n");
    printf("\n");

    printf("Menu Principal\n");
    printf("1. Iniciar Jogo\n");
    printf("2. Ver Regras\n");
    printf("3. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao1);
    printf("\n");

switch (opcao1)
{
case 1:
    // Cadastro das Cartas:
    // Implemente a lógica para solicitar ao usuário que insira os dados das cidades
    // utilizando a função scanf para capturar as entradas.
    // utilize o código do primeiro desafio
    printf("*** Vamos começar cadastrando suas cartas! ***\n");
    printf("\n");

    //Cadastro Carta 1
    printf("Jogador 1\n");
    printf("Carta 1:\n");
    
    printf("Estado: ");
    scanf(" %c", &estado1); // estado representado por uma letra de A a H
    
    printf("Código da carta: ");
    scanf("%s", codigo1); // código da carta representado pela letra do estado mais um número

    getchar(); //remove o ENTER que ficou no buffer depois do scanf(), evitando que o nome da cidade saia errado

    printf("Nome da cidade: ");
    fgets(nome_da_cidade1, 50, stdin); // nome da cidade
    nome_da_cidade1[strcspn(nome_da_cidade1, "\n")] = 0; //strcspn usado para remover o ENTER que ficou dentro da string

    printf("População: ");
    scanf("%lu", &populacao1); // População - o número de habitantes da cidade

    printf("Área em Km2: ");
    scanf("%f", &area1); // a área da cidade em km²

    printf("PIB: ");
    scanf("%f", &pib1); // O produto interno da cidade

    printf("Número de Pontos Turisticos: \n");
    scanf("%d", &pontos_turisticos1); // Número de pontos turísticos da cidade
    
    // Cálculo de variáveis Carta 1
    densidade_populacional1 = populacao1 / area1;
    pib_per_capita1 = (pib1 * 1000000000.0f) / populacao1; //valor do pib convertido de bilhões de reais para reais
    superpoder1 = populacao1 + area1 + pib1 + (float) pontos_turisticos1 + pib_per_capita1 + (1.0f / densidade_populacional1);

    printf("\n");
    
    //Cadastro Carta 2
    printf("Jogador 2\n");
    printf("Carta 2:\n");
    printf("Estado: ");
    scanf(" %c", &estado2); // estado representado por uma letra de A a H

    printf("Código da carta: ");
    scanf("%s", codigo2); // código da carta representado pela letra do estado mais um número

    getchar(); //remove o ENTER que ficou no buffer depois do scanf(), evitando que o nome da cidade saia errado

    printf("Nome da cidade: ");
    fgets(nome_da_cidade2, 50, stdin); // nome da cidade
    nome_da_cidade2[strcspn(nome_da_cidade2, "\n")] = 0; //strcspn usado para remover o ENTER que ficou dentro da string

    printf("População: ");
    scanf("%lu", &populacao2); // População - o número de habitantes da cidade

    printf("Área em Km2: ");
    scanf("%f", &area2); // a área da cidade em km²

    printf("PIB: ");
    scanf("%f", &pib2); // O produto interno da cidade
    
    printf("Número de Pontos Turisticos: \n");
    scanf("%d", &pontos_turisticos2); // Número de pontos turísticos da cidade

    // Cálculo de variáveis Carta 2
    densidade_populacional2 = populacao2 / area2;
    pib_per_capita2 = (pib2 * 1000000000.0f) / populacao2; //valor do pib convertido de bilhões de reais para reais
    superpoder2 = populacao2 + area2 + pib2 + (float) pontos_turisticos2 + pib_per_capita2 + (1.0f / densidade_populacional2);

    // Área para exibição dos dados da cidade
    printf("\n");  
    printf("*** Essas foram as cartas cadastradas: ***\n");

    //Exibição Carta 1
    printf("Carta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código da carta: %4s\n", codigo1);
    printf("Nome da cidade: %s\n", nome_da_cidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km2\n", area1);
    printf("PIB: %.2f bilhões de reais\n",  pib1);
    printf("Número de Pontos Turisticos: %d\n", pontos_turisticos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_populacional1);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita1);
    printf("Super Poder: %.2f\n", superpoder1);
    printf("\n");

    //Exibição Carta 2
    printf("Carta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código da carta: %4s\n", codigo2);
    printf("Nome da cidade: %s\n", nome_da_cidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km2\n", area2) ;
    printf("PIB: %.2f bilhões de reais\n",  pib2);
    printf("Número de Pontos Turisticos: %d\n", pontos_turisticos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade_populacional2);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita2);
    printf("Super Poder: %.2f\n", superpoder2);
    printf("\n");

    //Área da Batalha de Cartas no Super Trunfo - comparação de variáveis
    printf("*** A batalha vai começar! Qual carta irá vencer? ***\n");
    printf("\n");

    // Comparação de Cartas:
    // Desenvolva a lógica de comparação entre duas cartas.
    // Utilize estruturas de decisão como if, if-else para comparar atributos como população, área, PIB, etc.
    
    printf("*** ATRIBUTOS PARA BATALHA ***\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Populacional\n");
    printf("6. PIB per Capita\n");
    printf("7. Super Poder\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao2);
    printf("\n");
    
    switch (opcao2) 
    {
    case 1:
        printf("Comparação da População\n");
        printf("Carta 1 - %s: %lu habitantes\n", nome_da_cidade1, populacao1);
        printf("Carta 2 - %s: %lu habitantes\n", nome_da_cidade2, populacao2);

        printf("\n*** RESULTADO DA BATALHA ***\n");
        if(populacao1 > populacao2){
        printf("Resultado: Carta 1 (%s) venceu!\n", nome_da_cidade1);
        } else if (populacao1 < populacao2) {
        printf("Resultado: Carta 2 (%s) venceu!\n", nome_da_cidade2);
        } else {
        printf("Resultado: Houve empate!\n");
        }
        printf("\n");
        break;

    case 2:
        printf("Comparação da Área\n");
        printf("Carta 1 - %s: %.2f km2\n", nome_da_cidade1, area1);
        printf("Carta 2 - %s: %.2f km2\n", nome_da_cidade2, area2);

        printf("\n*** RESULTADO DA BATALHA ***\n");
        if(area1 > area2){
        printf("Resultado: Carta 1 (%s) venceu!\n", nome_da_cidade1);
        } else if (area1 < area2) {
        printf("Resultado: Carta 2 (%s) venceu!\n", nome_da_cidade2);
        } else {
        printf("Resultado: Houve empate!\n");
        }
        printf("\n");
        break;

    case 3:
        printf("Comparação do PIB\n");
        printf("Carta 1 - %s: %.2f bilhões de reais\n", nome_da_cidade1, pib1);
        printf("Carta 2 - %s: %.2f bilhões de reais\n", nome_da_cidade2, pib2);

        printf("\n*** RESULTADO DA BATALHA ***\n");
        if(pib1 > pib2){
        printf("Resultado: Carta 1 (%s) venceu!\n", nome_da_cidade1);
        } else if (pib1 < pib2) {
        printf("Resultado: Carta 2 (%s) venceu!\n", nome_da_cidade2);
        } else {
        printf("Resultado: Houve empate!\n");
        }
        printf("\n");
        break;

    case 4:
        printf("Comparação de Pontos Turísticos\n");
        printf("Carta 1 - %s: %d pontos\n", nome_da_cidade1, pontos_turisticos1);
        printf("Carta 2 - %s: %d pontos\n", nome_da_cidade2, pontos_turisticos2);

        printf("\n*** RESULTADO DA BATALHA ***\n");
        if(pontos_turisticos1 > pontos_turisticos2){
        printf("Resultado: Carta 1 (%s) venceu!\n", nome_da_cidade1);
        } else if(pontos_turisticos1 < pontos_turisticos2) {
        printf("Resultado: Carta 2 (%s) venceu!\n", nome_da_cidade2);
        } else {
        printf("Resultado: Houve empate!\n");
        }
        printf("\n");  
        break;

    case 5:
        printf("Comparação da Densidade Populacional\n");
        printf("Carta 1 - %s: %.2f hab/km2\n", nome_da_cidade1, densidade_populacional1);
        printf("Carta 2 - %s: %.2f hab/km2\n", nome_da_cidade2, densidade_populacional2);

        printf("\n*** RESULTADO DA BATALHA ***\n");
        if(densidade_populacional1 < densidade_populacional2){
        printf("Resultado: Carta 1 (%s) venceu!\n", nome_da_cidade1);
        } else if (densidade_populacional1 > densidade_populacional2){
        printf("Resultado: Carta 2 (%s) venceu!\n", nome_da_cidade2);
        } else {
        printf("Resultado: Houve empate!\n");
        }
        printf("\n");
        break;

    case 6:
        printf("Comparação do PIB per Capita\n");
        printf("Carta 1 - %s: %.2f reais\n", nome_da_cidade1, pib_per_capita1);
        printf("Carta 2 - %s: %.2f reais\n", nome_da_cidade2, pib_per_capita2);

        printf("\n*** RESULTADO DA BATALHA ***\n");
        if(pib_per_capita1 > pib_per_capita2){
        printf("Resultado: Carta 1 (%s) venceu!\n", nome_da_cidade1);
        } else if (pib_per_capita1 < pib_per_capita2) {
        printf("Resultado: Carta 2 (%s) venceu!\n", nome_da_cidade2);
        } else {
        printf("Resultado: Houve empate!\n");
        }
        printf("\n");
        break;

    case 7:
        printf("Comparação do Super Poder\n");
        printf("Carta 1 - %s: %.2f pontos\n", nome_da_cidade1, superpoder1);
        printf("Carta 2 - %s: %.2f pontos\n", nome_da_cidade2, superpoder2);

        printf("\n*** RESULTADO DA BATALHA ***\n");
        if(superpoder1 > superpoder2){
        printf("Resultado: Carta 1 (%s) venceu!\n", nome_da_cidade1);
        } else if (superpoder1 < superpoder2) {
        printf("Resultado: Carta 2 (%s) venceu!\n", nome_da_cidade2);
        } else {
        printf("Resultado: Houve empate!\n");
        }
        printf("\n");
        break;
 
    default:
        printf("Opção inválida\n");
        break;
    }
    break;

case 2:
    printf("\n");
    printf("### REGRAS DO SUPER TRUNFO ###\n");
    printf("\n");
    printf("1. Cada jogador cadastra uma carta de cidade.\n");
    printf("2. Para cada cidade devem ser informados:\n");
    printf("   - Estado\n");
    printf("   - Código da carta\n");
    printf("   - Nome da cidade\n");
    printf("   - População\n");
    printf("   - Área\n");
    printf("   - PIB\n");
    printf("   - Número de pontos turísticos\n");
    printf("\n");
    printf("3. O sistema calcula automaticamente:\n");
    printf("   - Densidade Populacional\n");
    printf("   - PIB per Capita\n");
    printf("   - Super Poder\n");
    printf("\n");
    printf("4. Após o cadastro, o jogador escolhe um atributo para a batalha.\n");
    printf("\n");
    printf("5. Vence a carta com o maior valor no atributo escolhido.\n");
    printf("\n");
    printf("6. Exceção: na Densidade Populacional vence a carta com o MENOR valor.\n");
    printf("\n");
    printf("7. Se os valores forem iguais, ocorre empate.\n");
    printf("\n");
    printf("8. O Super Poder é calculado pela soma de:\n");
    printf("   População + Área + PIB + Pontos Turísticos + PIB per Capita + (1/Densidade Populacional)\n");
    printf("\n");
    break;

case 3:
printf("\n");
printf("*** Partida encerrada! Até a próxima! ***\n");
break;

default:
printf("\n");
printf("Opção inválida\n");
printf("*** Partida encerrada! Até a próxima! ***\n");
break;
}
    // Exemplo:
    // if (populacaoA > populacaoB) {
    //     printf("Cidade 1 tem maior população.\n");
    // } else {
    //     printf("Cidade 2 tem maior população.\n");
    // }

    // Exibição dos Resultados:
    // Após realizar as comparações, exiba os resultados para o usuário.
    // Certifique-se de que o sistema mostre claramente qual carta venceu e com base em qual atributo.

    // Exemplo:
    // printf("A cidade vencedora é: %s\n", cidadeVencedora);

    return 0;
}
