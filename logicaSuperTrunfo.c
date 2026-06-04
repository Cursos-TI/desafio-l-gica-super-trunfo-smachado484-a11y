#include <stdio.h>
#include <string.h> //biblioteca adicionada para poder usar o strcspn()
#include <stdlib.h> //biblioteca adicionada para criar modo vs computador (escolha randomica)
#include <time.h> //biblioteca adicionada para criar modo vs computador (escolha randomica)


// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas


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
    int opcao1, atributo1, atributo2, carta_computador;
    //Variável para escolha do menu
    int resultado1, resultado2;
    //Variável para o resultado das batalhas
    float soma_carta1 = 0, soma_carta2 = 0; 
    //Variável para somar os atributos
    char nome_atributo1[30], nome_atributo2[30]; 
    //Variável para mostrar os atributos escolhidos
    float atributo1_valor1, atributo1_valor2, atributo2_valor1, atributo2_valor2;
    //Variáveis para guardar o valor dos atributos para poder imprimi-los no placar

		srand(time(0)); 
 
    printf("*** SUPER TRUNFO ***\n");
    printf("\n");
    printf("*** Bem-vindo ao jogo! ***\n");
    printf("\n");

    printf("Menu Principal\n");
    printf("1. Iniciar Jogo - Contra outro Jogador\n");
    printf("2. Iniciar Jogo - Contra o Computador\n");
    printf("3. Ver Regras\n");
    printf("4. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao1);
    printf("\n");

	switch (opcao1)
	{
	case 1:
    	// Cadastro das Cartas:
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
		
		if (populacao1 == 0)
			{
			printf("Erro: a população deve ser maior que zero.\n");
			printf("Jogo encerrado.\n");
			return 0;
			} //Função inserida com o objetivo de evitar que o jogo continue caso o jogador coloque 0 nessa opção, evitando zerar cálculos mais a frente

   		printf("Área em Km2: ");
    	scanf("%f", &area1); // a área da cidade em km²
		
		if (area1 <= 0)
			{
			printf("Erro: a área deve ser maior que zero.\n");
			printf("Jogo encerrado.\n");
			return 0;
			} //Função inserida com o objetivo de evitar que o jogo continue caso o jogador coloque 0 nessa opção, evitando zerar cálculos mais a frente

    	printf("PIB: ");
    	scanf("%f", &pib1); // O produto interno da cidade

	    printf("Número de Pontos Turisticos: ");
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
		if (populacao2 == 0)
			{
			printf("Erro: a população deve ser maior que zero.\n");
			printf("Jogo encerrado.\n");
			return 0;
			} //Função inserida com o objetivo de evitar que o jogo continue caso o jogador coloque 0 nessa opção, evitando zerar cálculos mais a frente

   		printf("Área em Km2: ");
  		scanf("%f", &area2); // a área da cidade em km²
		if (area2 <= 0)
			{
			printf("Erro: a área deve ser maior que zero.\n");
			printf("Jogo encerrado.\n");
			return 0;
			} //Função inserida com o objetivo de evitar que o jogo continue caso o jogador coloque 0 nessa opção, evitando zerar cálculos mais a frente

   		printf("PIB: ");
   		scanf("%f", &pib2); // O produto interno da cidade
   
  		printf("Número de Pontos Turisticos: ");
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

	    //Área das Batalhas de Cartas no Super Trunfo - comparação de variáveis
   		printf("*** A batalha vai começar! Qual carta irá vencer? ***\n");
   		printf("\n");
		
    	// Comparação de Cartas:
    	printf("*** ATRIBUTOS PARA 1ª BATALHA ***\n");
    	printf("1. População\n");
    	printf("2. Área\n");
    	printf("3. PIB\n");
    	printf("4. Pontos Turísticos\n");
    	printf("5. Densidade Populacional\n");
    	printf("6. PIB per Capita\n");
    	printf("7. Super Poder\n");
        printf("\n");
    	printf("Escolha o primeiro atributo: ");
    	scanf("%d", &atributo1);
    	printf("\n");
   
    		switch (atributo1)
    		{
   			case 1:
        	printf("Comparação da População\n");
        	printf("Carta 1 - %s: %lu habitantes\n", nome_da_cidade1, populacao1);
        	printf("Carta 2 - %s: %lu habitantes\n", nome_da_cidade2, populacao2);

	        printf("\n*** RESULTADO DA 1ª BATALHA ***\n");
			resultado1 = (populacao1 > populacao2) ? 1 : (populacao1 < populacao2) ? -1 : 0;

			//Informações que irão compor o resultado final da batalha
			strcpy(nome_atributo1, "População");
			atributo1_valor1 = populacao1;
			atributo1_valor2 = populacao2;

			soma_carta1 += populacao1;
			soma_carta2 += populacao2; 
            printf("\n");
        	break;

		    case 2:
        	printf("Comparação da Área\n");
        	printf("Carta 1 - %s: %.2f km2\n", nome_da_cidade1, area1);
        	printf("Carta 2 - %s: %.2f km2\n", nome_da_cidade2, area2);

	        printf("\n*** RESULTADO DA 1º BATALHA ***\n");
			resultado1 = (area1 > area2) ? 1 : (area1 < area2) ? -1 : 0;

			//Informações que irão compor o resultado final da batalha
			strcpy(nome_atributo1, "Área em Km2");
			atributo1_valor1 = area1;
			atributo1_valor2 = area2;

			soma_carta1 += area1;
			soma_carta2 += area2; 
        	printf("\n");
        	break;

			case 3:
        	printf("Comparação do PIB\n");
        	printf("Carta 1 - %s: %.2f bilhões de reais\n", nome_da_cidade1, pib1);
        	printf("Carta 2 - %s: %.2f bilhões de reais\n", nome_da_cidade2, pib2);

	        printf("\n*** RESULTADO DA 1ª BATALHA ***\n");
			resultado1 = (pib1 > pib2) ? 1 : (pib1 < pib2) ? -1 : 0;

			//Informações que irão compor o resultado final da batalha
			strcpy(nome_atributo1, "PIB");
			atributo1_valor1 = pib1;
			atributo1_valor2 = pib2;

			soma_carta1 += pib1;
			soma_carta2 += pib2; 
        	printf("\n");
        	break;

	    	case 4:
    	    printf("Comparação de Pontos Turísticos\n");
        	printf("Carta 1 - %s: %d pontos\n", nome_da_cidade1, pontos_turisticos1);
        	printf("Carta 2 - %s: %d pontos\n", nome_da_cidade2, pontos_turisticos2);

	        printf("\n*** RESULTADO DA 1ª BATALHA ***\n");
			resultado1 = (pontos_turisticos1 > pontos_turisticos2) ? 1 : (pontos_turisticos1 < pontos_turisticos2) ? -1 : 0;

			//Informações que irão compor o resultado final da batalha
			strcpy(nome_atributo1, "Pontos Turísticos");
			atributo1_valor1 = pontos_turisticos1;
			atributo1_valor2 = pontos_turisticos2;

			soma_carta1 += pontos_turisticos1;
			soma_carta2 += pontos_turisticos2; 
        	printf("\n");  
        	break;

		    case 5:
        	printf("Comparação da Densidade Populacional\n");
        	printf("Carta 1 - %s: %.2f hab/km2\n", nome_da_cidade1, densidade_populacional1);
        	printf("Carta 2 - %s: %.2f hab/km2\n", nome_da_cidade2, densidade_populacional2);

	        printf("\n*** RESULTADO DA 1º BATALHA ***\n");
			resultado1 = (densidade_populacional1 < densidade_populacional2) ? 1 : (densidade_populacional1 > densidade_populacional2) ? -1 : 0;

			//Informações que irão compor o resultado final da batalha
			strcpy(nome_atributo1, "Densidade Populacional");
			atributo1_valor1 = densidade_populacional1;
			atributo1_valor2 = densidade_populacional2;

			soma_carta1 += (1.0 / densidade_populacional1);
			soma_carta2 += (1.0 / densidade_populacional2);
        	printf("\n");
      		break;

		    case 6:
	        printf("Comparação do PIB per Capita\n");
    	    printf("Carta 1 - %s: %.2f reais\n", nome_da_cidade1, pib_per_capita1);
        	printf("Carta 2 - %s: %.2f reais\n", nome_da_cidade2, pib_per_capita2);

	        printf("\n*** RESULTADO DA 1ª BATALHA ***\n");
			resultado1 = (pib_per_capita1 > pib_per_capita2) ? 1 : (pib_per_capita1 < pib_per_capita2) ? -1 : 0;

			//Informações que irão compor o resultado final da batalha
			strcpy(nome_atributo1, "PIB per Capita");
			atributo1_valor1 = pib_per_capita1;
			atributo1_valor2 = pib_per_capita2;

			soma_carta1 += pib_per_capita1;
			soma_carta2 += pib_per_capita2; 
        	printf("\n");
        	break;

		    case 7:
	        printf("Comparação do Super Poder\n");
    	    printf("Carta 1 - %s: %.2f pontos\n", nome_da_cidade1, superpoder1);
        	printf("Carta 2 - %s: %.2f pontos\n", nome_da_cidade2, superpoder2);

	        printf("\n*** RESULTADO DA 1ª BATALHA ***\n");
			resultado1 = (superpoder1 > superpoder2) ? 1 : (superpoder1 < superpoder2) ? -1 : 0;

			//Informações que irão compor o resultado final da batalha
			strcpy(nome_atributo1, "Super Poder");
			atributo1_valor1 = superpoder1;
			atributo1_valor2 = superpoder2;

			soma_carta1 += superpoder1;
			soma_carta2 += superpoder2; 
        	printf("\n");
        	break;
 
    		default:
        	printf("Opção inválida\n");
        	break;
			}

		if (resultado1 == 1) {
    	printf("Resultado Parcial:: Carta 1 (%s) venceu!\n", nome_da_cidade1);
		} else if (resultado1 == -1) {
    	printf("Resultado Parcial:: Carta 2 (%s) venceu!\n", nome_da_cidade2);
		} else {
		printf("Resultado Parcial:: Houve empate!\n");
		}
    
    	printf("*** ATRIBUTOS PARA 2ª BATALHA ***\n");
    	printf("1. População\n");
    	printf("2. Área\n");
    	printf("3. PIB\n");
    	printf("4. Pontos Turísticos\n");
    	printf("5. Densidade Populacional\n");
    	printf("6. PIB per Capita\n");
    	printf("7. Super Poder\n");
        printf("\n");
    	printf("Escolha o segundo atributo: ");
    	scanf("%d", &atributo2);
    	printf("\n");
   
		if (atributo1 == atributo2)
		{
    	printf("Você escolheu o mesmo atributo!\n");
    	return 0;
		}

		switch (atributo2)
    	{
		    case 1:
        	printf("Comparação da População\n");
        	printf("Carta 1 - %s: %lu habitantes\n", nome_da_cidade1, populacao1);
        	printf("Carta 2 - %s: %lu habitantes\n", nome_da_cidade2, populacao2);

	        printf("\n*** RESULTADO DA 2ª BATALHA ***\n");
			resultado2 = (populacao1 > populacao2) ? 1 : (populacao1 < populacao2) ? -1 : 0;

			//Informações que irão compor o resultado final da batalha
			strcpy(nome_atributo2, "População");
			atributo2_valor1 = populacao1;
			atributo2_valor2 = populacao2;

			soma_carta1 += populacao1;
			soma_carta2 += populacao2; 
        	printf("\n");
        	break;

		    case 2:
        	printf("Comparação da Área\n");
        	printf("Carta 1 - %s: %.2f km2\n", nome_da_cidade1, area1);
        	printf("Carta 2 - %s: %.2f km2\n", nome_da_cidade2, area2);

	        printf("\n*** RESULTADO DA 2ª BATALHA ***\n");
			resultado2 = (area1 > area2) ? 1 : (area1 < area2) ? -1 : 0;

			//Informações que irão compor o resultado final da batalha
			strcpy(nome_atributo2, "Área em Km2");
			atributo2_valor1 = area1;
			atributo2_valor2 = area2;

			soma_carta1 += area1;
			soma_carta2 += area2; 
        	printf("\n");
        	break;

		    case 3:
        	printf("Comparação do PIB\n");
        	printf("Carta 1 - %s: %.2f bilhões de reais\n", nome_da_cidade1, pib1);
        	printf("Carta 2 - %s: %.2f bilhões de reais\n", nome_da_cidade2, pib2);

	        printf("\n*** RESULTADO DA 2ª BATALHA ***\n");
			resultado2 = (pib1 > pib2) ? 1 : (pib1 < pib2) ? -1 : 0;

			//Informações que irão compor o resultado final da batalha
			strcpy(nome_atributo2, "PIB");
			atributo2_valor1 = pib1;
			atributo2_valor2 = pib2;

			soma_carta1 += pib1;
			soma_carta2 += pib2; 
        	printf("\n");
        	break;

		    case 4:
        	printf("Comparação de Pontos Turísticos\n");
        	printf("Carta 1 - %s: %d pontos\n", nome_da_cidade1, pontos_turisticos1);
        	printf("Carta 2 - %s: %d pontos\n", nome_da_cidade2, pontos_turisticos2);

        	printf("\n*** RESULTADO DA 2ª BATALHA ***\n");
			resultado2 = (pontos_turisticos1 > pontos_turisticos2) ? 1 : (pontos_turisticos1 < pontos_turisticos2) ? -1 : 0;

			//Informações que irão compor o resultado final da batalha
			strcpy(nome_atributo2, "Pontos Turísticos");
			atributo2_valor1 = pontos_turisticos1;
			atributo2_valor2 = pontos_turisticos2;

			soma_carta1 += pontos_turisticos1;
			soma_carta2 += pontos_turisticos2; 
        	printf("\n");  
        	break;

			case 5:
        	printf("Comparação da Densidade Populacional\n");
        	printf("Carta 1 - %s: %.2f hab/km2\n", nome_da_cidade1, densidade_populacional1);
        	printf("Carta 2 - %s: %.2f hab/km2\n", nome_da_cidade2, densidade_populacional2);

	        printf("\n*** RESULTADO DA 2ª BATALHA ***\n");
			resultado2 = (densidade_populacional1 < densidade_populacional2) ? 1 : (densidade_populacional1 > densidade_populacional2) ? -1 : 0;

			//Informações que irão compor o resultado final da batalha
			strcpy(nome_atributo2, "Densidade Populacional");
			atributo2_valor1 = densidade_populacional1;
			atributo2_valor2 = densidade_populacional2;

			soma_carta1 += (1.0 / densidade_populacional1);
			soma_carta2 += (1.0 / densidade_populacional2); 
        	printf("\n");
        	break;

			case 6:
        	printf("Comparação do PIB per Capita\n");
        	printf("Carta 1 - %s: %.2f reais\n", nome_da_cidade1, pib_per_capita1);
        	printf("Carta 2 - %s: %.2f reais\n", nome_da_cidade2, pib_per_capita2);

	        printf("\n*** RESULTADO DA 2ª BATALHA ***\n");
			resultado2 = (pib_per_capita1 > pib_per_capita2) ? 1 : (pib_per_capita1 < pib_per_capita2) ? -1 : 0;

			//Informações que irão compor o resultado final da batalha
			strcpy(nome_atributo2, "PIB per Capita");
			atributo2_valor1 = pib_per_capita1;
			atributo2_valor2 = pib_per_capita2;
			
			soma_carta1 += pib_per_capita1;
			soma_carta2 += pib_per_capita2; 
        	printf("\n");
        	break;

		    case 7:
        	printf("Comparação do Super Poder\n");
        	printf("Carta 1 - %s: %.2f pontos\n", nome_da_cidade1, superpoder1);
        	printf("Carta 2 - %s: %.2f pontos\n", nome_da_cidade2, superpoder2);

	        printf("\n*** RESULTADO DA 2ª BATALHA ***\n");
			resultado2 = (superpoder1 > superpoder2) ? 1 : (superpoder1 < superpoder2) ? -1 : 0;

			//Informações que irão compor o resultado final da batalha
			strcpy(nome_atributo2, "Super Poder");
			atributo2_valor1 = superpoder1;
			atributo2_valor2 = superpoder2;

			soma_carta1 += superpoder1;
			soma_carta2 += superpoder2; 
        	printf("\n");
        	break;
 
    		default:
        	printf("Opção inválida\n");
        	break;
    		}

		printf("\n");

		if (resultado2 == 1) {
    	printf("Resultado Parcial: Carta 1 (%s) venceu!\n", nome_da_cidade1);
		} else if (resultado2 == -1) {
    	printf("Resultado Parcial: Carta 2 (%s) venceu!\n", nome_da_cidade2);
		} else {
    	printf("Resultado Parcial: Houve empate!\n");
		}

		printf("\n");
        printf("*** FIM DA BATALHA ***\n");
		printf("*** PLACAR FINAL ***\n");
		printf("\n");

		printf("Carta do Jogador 1: (%s)\n", nome_da_cidade1);
		printf("Carta do Jogador 2: (%s)\n", nome_da_cidade2);
		printf("\n");

		printf("Atributos Escolhidos\n");
		printf("Atributo 1: %s\n", nome_atributo1);
		printf("Atributo 2: %s\n", nome_atributo2);
		printf("\n");

		printf("Valores do Atributo 1 (%s)\n", nome_atributo1);
		printf("%s: %.2f\n", nome_da_cidade1, atributo1_valor1);
		printf("%s: %.2f\n", nome_da_cidade2, atributo1_valor2);
		printf("\n");

		printf("Valores do Atributo 2 (%s)\n", nome_atributo2);
		printf("%s: %.2f\n", nome_da_cidade1, atributo2_valor1);
		printf("%s: %.2f\n", nome_da_cidade2, atributo2_valor2);
		printf("\n");

		printf("*** Soma dos Atributos ***\n");
		printf("Carta 1 (%s): %.2f\n", nome_da_cidade1, soma_carta1);
		printf("Carta 2 (%s): %.2f\n", nome_da_cidade2, soma_carta2);
		printf("\n");

		if (soma_carta1 > soma_carta2) {
		printf("*** Parabéns, o Jogador 1 venceu! ***\n");
		} else if (soma_carta1 < soma_carta2) {
		printf("*** Parabéns, o Jogador 2 venceu! ***\n");
		} else {
		printf("*** Houve empate! ***\n");
		} 
        
        printf("\n");
        printf("*** Partida encerrada! Até a próxima! ***\n");
	break;
	 	
	case 2:
        // Cadastro das Cartas:
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
        if (populacao1 == 0)
            {
            printf("Erro: a população deve ser maior que zero.\n");
            printf("Jogo encerrado.\n");
            return 0;  
            } //Função inserida com o objetivo de evitar que o jogo continue caso o jogador coloque 0 nessa opção, evitando zerar cálculos mais a frente

        printf("Área em Km2: ");
        scanf("%f", &area1); // a área da cidade em km²
        if (area1 <= 0)
            {
            printf("Erro: a área deve ser maior que zero.\n");
            printf("Jogo encerrado.\n");
            return 0;
            }

        printf("PIB: ");
        scanf("%f", &pib1); // O produto interno da cidade
        
        printf("Número de Pontos Turisticos: ");
        scanf("%d", &pontos_turisticos1); // Número de pontos turísticos da cidade
   
        // Cálculo de variáveis Carta 1
        densidade_populacional1 = populacao1 / area1;
        pib_per_capita1 = (pib1 * 1000000000.0f) / populacao1; //valor do pib convertido de bilhões de reais para reais
        superpoder1 = populacao1 + area1 + pib1 + (float) pontos_turisticos1 + pib_per_capita1 + (1.0f / densidade_populacional1);

        printf("\n");
   
        //Carta 2
        carta_computador = rand() % 6 + 1; // Variável para sortear a carta do computador
    
        switch (carta_computador)
            {
            case 1:
            printf("Computador sorteou Curitiba\n");
            printf("\n");
            printf("Carta 3\n");

            estado2 = 'C';
            strcpy(codigo2, "C03");
            strcpy(nome_da_cidade2, "Curitiba");
            populacao2 = 2000000;
            area2 = 450.00;
            pib2 = 120.00;
            pontos_turisticos2 = 25;
            break;

            case 2:
            printf("Computador sorteou Belo Horizonte\n");
            printf("\n");
            printf("Carta 4\n");

            estado2 = 'D';
            strcpy(codigo2, "D04");
            strcpy(nome_da_cidade2, "Belo Horizonte");
            populacao2 = 2800000;
            area2 = 650.00;
            pib2 = 145.80;
            pontos_turisticos2 = 28;
            break;

            case 3:
            printf("Computador sorteou Brasília\n");
            printf("\n");
            printf("Carta 5\n");

            estado2 = 'E';
            strcpy(codigo2, "E05");
            strcpy(nome_da_cidade2, "Brasília");
            populacao2 = 3200000;
            area2 = 5802.00;
            pib2 = 320.50;
            pontos_turisticos2 = 40;
            break;

            case 4:
            printf("Computador sorteou Cuiabá\n");
            printf("\n");
            printf("Carta 6\n");

            estado2 = 'F';
            strcpy(codigo2, "F06");
            strcpy(nome_da_cidade2, "Cuiabá");
            populacao2 = 750000;
            area2 = 3300.00;
            pib2 = 45.70;
            pontos_turisticos2 = 18;
            break;

            case 5:
            printf("Computador sorteou Salvador\n");
            printf("\n");
            printf("Carta 7\n");

            estado2 = 'G';
            strcpy(codigo2, "G07");
            strcpy(nome_da_cidade2, "Salvador");
            populacao2 = 3100000;
            area2 = 700.00;
            pib2 = 95.30;
            pontos_turisticos2 = 45;
            break;

            case 6:
            printf("Computador sorteou Fortaleza\n");
            printf("\n");
            printf("Carta 8\n");

            estado2 = 'H';
            strcpy(codigo2, "H08");
            strcpy(nome_da_cidade2, "Fortaleza");
            populacao2 = 2700000;
            area2 = 620.00;
            pib2 = 85.40;
            pontos_turisticos2 = 42;
            break;

            default:
            printf("Erro ao sortear carta.\n");
            break; 
            }

        // Cálculo de variáveis Carta 2
        densidade_populacional2 = populacao2 / area2;
        pib_per_capita2 = (pib2 * 1000000000.0f) / populacao2; //valor do pib convertido de bilhões de reais para reais
        superpoder2 = populacao2 + area2 + pib2 + (float) pontos_turisticos2 + pib_per_capita2 + (1.0f / densidade_populacional2);

        // Área para exibição dos dados da cidade

        //Exibição Carta do Jogador
        printf("\n");  
        printf("*** Essa foi a carta cadastrada: ***\n");
        printf("Carta do Jogador:\n");
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

        //Exibição Carta do Computador
        printf("*** Essa foi a carta sorteada pelo computador: ***\n");
        printf("Carta do Computador:\n");
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

        //Área daS BatalhaS de Cartas no Super Trunfo - comparação de variáveis
        printf("*** A batalha vai começar! Qual carta irá vencer? ***\n");
        printf("\n");

        // Comparação de Cartas:
        printf("*** ATRIBUTOS PARA 1ª BATALHA ***\n");
        printf("1. População\n");
        printf("2. Área\n");
        printf("3. PIB\n");
        printf("4. Pontos Turísticos\n");
        printf("5. Densidade Populacional\n");
        printf("6. PIB per Capita\n");
        printf("7. Super Poder\n");
        printf("\n");
        printf("Escolha o primeiro atributo: ");
        scanf("%d", &atributo1);
        printf("\n");
   
        switch (atributo1)
        {
            case 1:
            printf("Comparação da População\n");
            printf("Carta 1 - %s: %lu habitantes\n", nome_da_cidade1, populacao1);
            printf("Carta 2 - %s: %lu habitantes\n", nome_da_cidade2, populacao2);

            printf("\n*** RESULTADO DA 1ª BATALHA ***\n");
            resultado1 = (populacao1 > populacao2) ? 1 : (populacao1 < populacao2) ? -1 : 0;

            //Informações que irão compor o resultado final da batalha
            strcpy(nome_atributo1, "População");
            atributo1_valor1 = populacao1;
            atributo1_valor2 = populacao2;

            soma_carta1 += populacao1;
            soma_carta2 += populacao2; 
            printf("\n");
            break;

            case 2:
            printf("Comparação da Área\n");
            printf("Carta 1 - %s: %.2f km2\n", nome_da_cidade1, area1);
            printf("Carta 2 - %s: %.2f km2\n", nome_da_cidade2, area2);

            printf("\n*** RESULTADO DA 1ª BATALHA ***\n");
            resultado1 = (area1 > area2) ? 1 : (area1 < area2) ? -1 : 0;

            //Informações que irão compor o resultado final da batalha
            strcpy(nome_atributo1, "Área em Km2");
            atributo1_valor1 = area1;
            atributo1_valor2 = area2;

            soma_carta1 += area1;
            soma_carta2 += area2; 
            printf("\n");
            break;

            case 3:
            printf("Comparação do PIB\n");
            printf("Carta 1 - %s: %.2f bilhões de reais\n", nome_da_cidade1, pib1);
            printf("Carta 2 - %s: %.2f bilhões de reais\n", nome_da_cidade2, pib2);

            printf("\n*** RESULTADO DA 1ª BATALHA ***\n");
            resultado1 = (pib1 > pib2) ? 1 : (pib1 < pib2) ? -1 : 0;

            //Informações que irão compor o resultado final da batalha
            strcpy(nome_atributo1, "PIB");
            atributo1_valor1 = pib1;
            atributo1_valor2 = pib2;

            soma_carta1 += pib1;
            soma_carta2 += pib2; 
            printf("\n");
            break;

            case 4:
            printf("Comparação de Pontos Turísticos\n");
            printf("Carta 1 - %s: %d pontos\n", nome_da_cidade1, pontos_turisticos1);
            printf("Carta 2 - %s: %d pontos\n", nome_da_cidade2, pontos_turisticos2);

            printf("\n*** RESULTADO DA 1ª BATALHA ***\n");
            resultado1 = (pontos_turisticos1 > pontos_turisticos2) ? 1 : (pontos_turisticos1 < pontos_turisticos2) ? -1 : 0;

            //Informações que irão compor o resultado final da batalha
            strcpy(nome_atributo1, "Pontos Turísticos");
            atributo1_valor1 = pontos_turisticos1;
            atributo1_valor2 = pontos_turisticos2;

            soma_carta1 += pontos_turisticos1;
            soma_carta2 += pontos_turisticos2; 
            printf("\n");  
            break;

            case 5:
            printf("Comparação da Densidade Populacional\n");
            printf("Carta 1 - %s: %.2f hab/km2\n", nome_da_cidade1, densidade_populacional1);
            printf("Carta 2 - %s: %.2f hab/km2\n", nome_da_cidade2, densidade_populacional2);

            printf("\n*** RESULTADO DA 1ª BATALHA ***\n");
            resultado1 = (densidade_populacional1 < densidade_populacional2) ? 1 : (densidade_populacional1 > densidade_populacional2) ? -1 : 0;

            //Informações que irão compor o resultado final da batalha
            strcpy(nome_atributo1, "Densidade Populacional");
            atributo1_valor1 = densidade_populacional1;
            atributo1_valor2 = densidade_populacional2;

            soma_carta1 += (1.0 / densidade_populacional1);
            soma_carta2 += (1.0 / densidade_populacional2);
            printf("\n");
            break;

            case 6:
            printf("Comparação do PIB per Capita\n");
            printf("Carta 1 - %s: %.2f reais\n", nome_da_cidade1, pib_per_capita1);
            printf("Carta 2 - %s: %.2f reais\n", nome_da_cidade2, pib_per_capita2);

            printf("\n*** RESULTADO DA 1ª BATALHA ***\n");
            resultado1 = (pib_per_capita1 > pib_per_capita2) ? 1 : (pib_per_capita1 < pib_per_capita2) ? -1 : 0;

            //Informações que irão compor o resultado final da batalha
            strcpy(nome_atributo1, "PIB per Capita");
            atributo1_valor1 = pib_per_capita1;
            atributo1_valor2 = pib_per_capita2;

            soma_carta1 += pib_per_capita1;
            soma_carta2 += pib_per_capita2; 
            printf("\n");
            break;

            case 7:
            printf("Comparação do Super Poder\n");
            printf("Carta 1 - %s: %.2f pontos\n", nome_da_cidade1, superpoder1);
            printf("Carta 2 - %s: %.2f pontos\n", nome_da_cidade2, superpoder2);

            printf("\n*** RESULTADO DA 1ª BATALHA ***\n");
            resultado1 = (superpoder1 > superpoder2) ? 1 : (superpoder1 < superpoder2) ? -1 : 0;

            //Informações que irão compor o resultado final da batalha
            strcpy(nome_atributo1, "Super Poder");
            atributo1_valor1 = superpoder1;
            atributo1_valor2 = superpoder2;

            soma_carta1 += superpoder1;
            soma_carta2 += superpoder2; 
            printf("\n");
            break;
 
            default:
            printf("Opção inválida\n");
            break;
            }

        printf("\n");

        if (resultado1 == 1) {
            printf("Resultado Parcial: Carta do jogador (%s) venceu!\n", nome_da_cidade1);
            } else if (resultado1 == -1) {
            printf("Resultado Parcial: Carta do computador (%s) venceu!\n", nome_da_cidade2);
            } else { 
            printf("Resultado Parcial: Houve empate!\n");
            }
        printf("\n");
        
        printf("*** ATRIBUTOS PARA 2ª BATALHA ***\n");
        printf("1. População\n");
        printf("2. Área\n");
        printf("3. PIB\n");
        printf("4. Pontos Turísticos\n");
        printf("5. Densidade Populacional\n");
        printf("6. PIB per Capita\n");
        printf("7. Super Poder\n");
        printf("\n");
        printf("Escolha o segundo atributo: ");
        scanf("%d", &atributo2);
        printf("\n");
   
        if (atributo1 == atributo2)
            {
            printf("Você escolheu o mesmo atributo!\n");
            return 0;
            }

        switch (atributo2)
        {
            case 1:
            printf("Comparação da População\n");
            printf("Carta 1 - %s: %lu habitantes\n", nome_da_cidade1, populacao1);
            printf("Carta 2 - %s: %lu habitantes\n", nome_da_cidade2, populacao2);

            printf("\n*** RESULTADO DA 2ª BATALHA ***\n");
            resultado2 = (populacao1 > populacao2) ? 1 : (populacao1 < populacao2) ? -1 : 0;

            //Informações que irão compor o resultado final da batalha
            strcpy(nome_atributo2, "População");
            atributo2_valor1 = populacao1;
            atributo2_valor2 = populacao2;

            soma_carta1 += populacao1;
            soma_carta2 += populacao2; 
            printf("\n");
            break;

            case 2:
            printf("Comparação da Área\n");
            printf("Carta 1 - %s: %.2f km2\n", nome_da_cidade1, area1);
            printf("Carta 2 - %s: %.2f km2\n", nome_da_cidade2, area2);

            printf("\n*** RESULTADO DA 2ª BATALHA ***\n");
            resultado2 = (area1 > area2) ? 1 : (area1 < area2) ? -1 : 0;

            //Informações que irão compor o resultado final da batalha
            strcpy(nome_atributo2, "Área em Km2");
            atributo2_valor1 = area1;
            atributo2_valor2 = area2;

            soma_carta1 += area1;
            soma_carta2 += area2; 
            printf("\n");
            break;

            case 3:
            printf("Comparação do PIB\n");
            printf("Carta 1 - %s: %.2f bilhões de reais\n", nome_da_cidade1, pib1);
            printf("Carta 2 - %s: %.2f bilhões de reais\n", nome_da_cidade2, pib2);

            printf("*** RESULTADO DA 2ª BATALHA ***\n");
            resultado2 = (pib1 > pib2) ? 1 : (pib1 < pib2) ? -1 : 0;

            //Informações que irão compor o resultado final da batalha
            strcpy(nome_atributo2, "PIB");
            atributo2_valor1 = pib1;
            atributo2_valor2 = pib2;

            soma_carta1 += pib1;
            soma_carta2 += pib2; 
            printf("\n");
            break;

            case 4:
            printf("Comparação de Pontos Turísticos\n");
            printf("Carta 1 - %s: %d pontos\n", nome_da_cidade1, pontos_turisticos1);
            printf("Carta 2 - %s: %d pontos\n", nome_da_cidade2, pontos_turisticos2);

            printf("\n*** RESULTADO DA 2ª BATALHA ***\n");
            resultado2 = (pontos_turisticos1 > pontos_turisticos2) ? 1 : (pontos_turisticos1 < pontos_turisticos2) ? -1 : 0;

            //Informações que irão compor o resultado final da batalha
            strcpy(nome_atributo2, "Pontos Turísticos");
            atributo2_valor1 = pontos_turisticos1;
            atributo2_valor2 = pontos_turisticos2;

            soma_carta1 += pontos_turisticos1;
            soma_carta2 += pontos_turisticos2; 
            printf("\n");  
            break;

            case 5:
            printf("Comparação da Densidade Populacional\n");
            printf("Carta 1 - %s: %.2f hab/km2\n", nome_da_cidade1, densidade_populacional1);
            printf("Carta 2 - %s: %.2f hab/km2\n", nome_da_cidade2, densidade_populacional2);

            printf("\n*** RESULTADO DA 2ª BATALHA ***\n");
            resultado2 = (densidade_populacional1 < densidade_populacional2) ? 1 : (densidade_populacional1 > densidade_populacional2) ? -1 : 0;

            //Informações que irão compor o resultado final da batalha
            strcpy(nome_atributo2, "Densidade Populacional");
            atributo2_valor1 = densidade_populacional1;
            atributo2_valor2 = densidade_populacional2;

            soma_carta1 += (1.0 / densidade_populacional1);
            soma_carta2 += (1.0 / densidade_populacional2);
            printf("\n");
            break;

            case 6:
            printf("Comparação do PIB per Capita\n");
            printf("Carta 1 - %s: %.2f reais\n", nome_da_cidade1, pib_per_capita1);
            printf("Carta 2 - %s: %.2f reais\n", nome_da_cidade2, pib_per_capita2);

            printf("\n*** RESULTADO DA 2ª BATALHA ***\n");
            resultado2 = (pib_per_capita1 > pib_per_capita2) ? 1 : (pib_per_capita1 < pib_per_capita2) ? -1 : 0;

            //Informações que irão compor o resultado final da batalha
            strcpy(nome_atributo2, "PIB per Capita");
            atributo2_valor1 = pib_per_capita1;
            atributo2_valor2 = pib_per_capita2;

            soma_carta1 += pib_per_capita1;
            soma_carta2 += pib_per_capita2; 
            printf("\n");
            break;

            case 7:
            printf("Comparação do Super Poder\n");
            printf("Carta 1 - %s: %.2f pontos\n", nome_da_cidade1, superpoder1);
            printf("Carta 2 - %s: %.2f pontos\n", nome_da_cidade2, superpoder2);

            printf("\n*** RESULTADO DA 2ª BATALHA ***\n");
            resultado2 = (superpoder1 > superpoder2) ? 1 : (superpoder1 < superpoder2) ? -1 : 0;

            //Informações que irão compor o resultado final da batalha
            strcpy(nome_atributo2, "Super Poder");
            atributo2_valor1 = superpoder1;
            atributo2_valor2 = superpoder2;

            soma_carta1 += superpoder1;
            soma_carta2 += superpoder2; 
            printf("\n");
            break;
 
            default:
            printf("Opção inválida\n");
            break;
        }
  
        printf("\n");

        if (resultado2 == 1) {
            printf("Resultado Parcial: Carta do Jogador (%s) venceu!\n", nome_da_cidade1);
            } else if (resultado2 == -1) {
            printf("Resultado Parcial: Carta do Computador (%s) venceu!\n", nome_da_cidade2);
            } else {
            printf("Resultado Parcial: Houve empate!\n");
            }
        
        printf("\n");
        printf("*** FIM DA BATALHA ***\n");
        printf("*** PLACAR FINAL ***\n");
        printf("\n");

        printf("Carta do Jogador: (%s)\n", nome_da_cidade1);
        printf("Carta do Computador: (%s)\n", nome_da_cidade2);
        printf("\n");

        printf("Atributos Escolhidos\n");
        printf("Atributo 1: %s\n", nome_atributo1);
        printf("Atributo 2: %s\n", nome_atributo2);
        printf("\n");

        printf("Valores do Atributo 1 (%s)\n", nome_atributo1);
        printf("%s: %.2f\n", nome_da_cidade1, atributo1_valor1);
        printf("%s: %.2f\n", nome_da_cidade2, atributo1_valor2);    
        printf("\n");

        printf("Valores do Atributo 2 (%s)\n", nome_atributo2);
        printf("%s: %.2f\n", nome_da_cidade1, atributo2_valor1);
        printf("%s: %.2f\n", nome_da_cidade2, atributo2_valor2);
        printf("\n");

        printf("*** Soma dos Atributos ***\n");
        printf("Carta 1 (%s): %.2f\n", nome_da_cidade1, soma_carta1);
        printf("Carta 2 (%s): %.2f\n", nome_da_cidade2, soma_carta2);
        printf("\n");

        if (soma_carta1 > soma_carta2) {
            printf("*** Parabéns, você venceu! ***\n");
            } else if (soma_carta1 < soma_carta2) {
            printf("*** Que pena, o computador venceu! ***\n");
            } else {
            printf("*** Houve empate! ***\n");
            }
        
        printf("\n");
        printf("*** Partida encerrada! Até a próxima! ***\n");
    break;

    case 3:
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

    case 4:
        printf("\n");
        printf("*** Partida encerrada! Até a próxima! ***\n");
    break;

    default:
        printf("\n");
        printf("Opção inválida\n");
        printf("*** Partida encerrada! Até a próxima! ***\n");
    break;
    }
    
    return 0;
}