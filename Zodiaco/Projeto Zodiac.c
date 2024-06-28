#include <stdio.h>
#include <locale.h>

int main()
{

	setlocale(LC_ALL, "Portuguese"); // permite acessar caracteres especiais

	int opcao, dia, mes, ano; // declaracao das variaveis

	// Menu
	/*
	 * O comando "do" serve para criar uma estrutura de repeticao
	 * que executa um bloco de codigo enquanto uma determinada condicao for verdadeira
	 * Neste caso, o programa vai exibir o menu enquanto a opcao escolhida pelo
	 * usuario nao for a opcao 4 (sair)
	 * Isso e importante porque a opcao 1 e 2 usam a funcao scanf() nao limpa o buffer(registo de memoria alocado para armazenar dados temporariamente antes de serem enviados ou processados.)
	 * e vamos precisar usar o while para garantir que o buffer esteja limpo antes de
	 * pedir novamente as opcoes
	 */
	do
	{
		/*
			Menu com as opcoes:
				- Tradicional
				- Egipicio
				- Chines
				- Sair

			A variavel "opcao" recebe o numero da opcao escolhida pelo usuario
		*/
		printf("\n================== MENU ===============");
		printf("\n===== ESCOLHA O CALENDARIO ZODIACO =====\n");
		printf("[1] Tradicional\n");
		printf("[2] Egipicio\n");
		printf("[3] Chines\n");
		printf("[4] Sair\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &opcao); // le a opcao escolhida

		// avalia a opcao escolhida pelo usuario
		// o switch é usado para escolher qual bloco de codigo executar
		// de acordo com a opcao escolhida pelo usuario
		// a variavel "opcao" recebe um numero que representa a opcao escolhida
		// e o switch verifica qual caso correspondente a opcao escolhida e executa
		// o codigo dentro desse caso
		switch (opcao)
		{
		case 1: // caso o usuario escolha a opcao 1

			/*
				Opcao 1: Tradicional

				Pede ao usuario para digitar a data de nascimento
				e exibe o zodiac correspondente
			*/
			printf("\n====== ZODIACO TRADICIONAL ======\n");
			printf("Digite o dia em que nasceu: ");			   // pede o dia
			scanf("%d", &dia);								   // le o dia
			printf("Agora em que mes nasceu (EM NUMEROS!): "); // pede o mes
			scanf("%d", &mes);								   // le o mes

			//* Explicação do IF Else:

			/*
				O if/else é uma estrutura de controle que serve para escolher
				qual bloco de codigo executar de acordo com uma condicao

				O if eh usado para verificar se uma condicao eh verdadeira ou nao
				e se for, executa o bloco de codigo dentro do if
				O else eh usado para executar um bloco de codigo caso a condicao
				do if seja FALSA

				O else é OPCIONAL e pode ser usado junto com o if para executar
				dois blocos de codigo diferentes de acordo com a condicao
				Essa estrutura eh usada para escolher qual bloco de codigo executar
				de acordo com a condicao verdadeira ou falsa

				No nosso programa, usamos if e else para escolher qual zodiaco exibir
				de acordo com a data de nascimento do usuario
			*/

			/*
				Calcula o zodiaco tradicional de acordo com o mes e o dia
				Cada if/else verifica a data e compara com o mes e dia
				e exibe o zodiac correspondente

				Ou seja, se o mes for Maio e o dia for maior ou igual a 21
				e menor ou igual a 31, exibe "Seu signo e Aries"
			*/
			if ((mes == 3 && dia >= 21) || (mes == 4 && dia <= 19))
			{
				printf("Seu signo e Aries.\n");
			}
			else if ((mes == 4 && dia >= 20) || (mes == 5 && dia <= 20))
			{
				printf("Seu signo e Touro.\n");
			}
			else if ((mes == 5 && dia >= 21) || (mes == 6 && dia <= 20))
			{
				printf("Seu signo e Gemeos.\n");
			}
			else if ((mes == 6 && dia >= 21) || (mes == 7 && dia <= 22))
			{
				printf("Seu signo e Cancer.\n");
			}
			else if ((mes == 7 && dia >= 23) || (mes == 8 && dia <= 22))
			{
				printf("Seu signo e Leao.\n");
			}
			else if ((mes == 8 && dia >= 23) || (mes == 9 && dia <= 22))
			{
				printf("Seu signo e Virgem.\n");
			}
			else if ((mes == 9 && dia >= 23) || (mes == 10 && dia <= 22))
			{
				printf("Seu signo e Libra.\n");
			}
			else if ((mes == 10 && dia >= 23) || (mes == 11 && dia <= 21))
			{
				printf("Seu signo e Escorpiao.\n");
			}
			else if ((mes == 11 && dia >= 22) || (mes == 12 && dia <= 21))
			{
				printf("Seu signo e Sagitario.\n");
			}
			else if ((mes == 12 && dia >= 22) || (mes == 1 && dia <= 19))
			{
				printf("Seu signo e Capricornio.\n");
			}
			else if ((mes == 1 && dia >= 20) || (mes == 2 && dia <= 18))
			{
				printf("Seu signo e Aquario.\n");
			}
			else if ((mes == 2 && dia >= 19) || (mes == 3 && dia <= 20))
			{
				printf("Seu signo e Peixes.\n");
			}
			else
			{
				printf("Data de nascimento inv?lida.\n");
			}
			break; // fim do caso 1 do switch

		case 2:
			printf("\n====== ZODIACO EGIPICIO ======\n"); // imprime mensagem de opcao escolhida

			printf("Digite o dia em que nasceu: "); // pede dia de nascimento
			scanf("%d", &dia);						// lê dia de nascimento

			printf("Agora em que mes nasceu (EM NUMEROS!): "); // pede mes de nascimento
			scanf("%d", &mes);								   // lê mes de nascimento

			// verifica o signo do usuario de acordo com o mes e o dia

			if ((mes == 3 && dia >= 16) || (mes == 4 && dia <= 15))
			{
				printf("Seu signo e Sekhmet.\n");
			}
			else if ((mes == 4 && dia >= 16) || (mes == 5 && dia <= 15))
			{
				printf("Seu signo e Ptah.\n");
			}
			else if ((mes == 5 && dia >= 16) || (mes == 6 && dia <= 15))
			{
				printf("Seu signo e Toth.\n");
			}
			else if ((mes == 6 && dia >= 16) || (mes == 7 && dia <= 15))
			{
				printf("Seu signo e Isis.\n");
			}
			else if ((mes == 7 && dia >= 16) || (mes == 8 && dia <= 15))
			{
				printf("Seu signo e Ra\n"); // \n para pular linha
			}
			else if ((mes == 8 && dia >= 16) || (mes == 9 && dia <= 15))
			{
				printf("Seu signo e Neit.\n");
			}
			else if ((mes == 9 && dia >= 16) || (mes == 10 && dia <= 15))
			{
				printf("Seu signo e Maat.\n");
			}
			else if ((mes == 10 && dia >= 16) || (mes == 11 && dia <= 15))
			{
				printf("Seu signo e Osiris.\n");
			}
			else if ((mes == 11 && dia >= 16) || (mes == 12 && dia <= 15))
			{
				printf("Seu signo e Hator.\n");
			}
			else if ((mes == 12 && dia >= 16) || (mes == 1 && dia <= 15))
			{
				printf("Seu signo e An?bis.\n");
			}
			else if ((mes == 1 && dia >= 16) || (mes == 2 && dia <= 15))
			{
				printf("Seu signo e Bastet.\n");
			}
			else if ((mes == 2 && dia >= 16) || (mes == 3 && dia <= 15))
			{
				printf("Seu signo e Tauret.\n");
			}
			else // data de nascimento invalida caso o usuario digite um dia ou mes invalido
			{
				printf("Data de nascimento inv?lida.\n");
			}
			break; // fim do caso 2 do switch

		case 3:
			printf("\n====== ZODIACO CHINES ======\n");
			printf("Digite o ano do seu nascimento: ");
			scanf("%d", &ano);
			// verifica o signo do usuario de acordo apenas com o ano nascido
			// usa operador logico para ser possivel escolher varios anos
			if ((ano == 1936 || ano == 1948 || ano == 1960 || ano == 1972 || ano == 1984 || ano == 1996 || ano == 2008 || ano == 2020))
			//* anos do rato: 1936, 1948, 1960, 1972, 1984, 1996, 2008, 2020
			{
				printf("Seu zodiaco chines eh o Rato");
			}
			else if ((ano == 1937 || ano == 1949 || ano == 1961 || ano == 1973 || ano == 1985 || ano == 1997 || ano == 2009 || ano == 2021))
			//* anos do bufalo: 1937, 1949, 1961, 1973, 1985, 1997, 2009, 2021
			{
				printf("Seu zodiaco chines eh o bufalo");
			}
			else if ((ano == 1938 || ano == 1950 || ano == 1962 || ano == 1974 || ano == 1986 || ano == 1998 || ano == 2010 || ano == 2022))
			//* anos do tigre 1938, 1950, 1962, 1974, 1986, 1998, 2010, 2022
			{
				printf("Seu zodiaco chines eh o tigre");
			}
			else if ((ano == 1939 || ano == 1951 || ano == 1963 || ano == 1975 || ano == 1987 || ano == 1999 || ano == 2011 || ano == 2023))
			//* anos do coelho 1939, 1951, 1963, 1975, 1987, 1999, 2011, 2023
			{
				printf("Seu zodiaco chines eh o coelho");
			}
			else if ((ano == 1940 || ano == 1952 || ano == 1964 || ano == 1976 || ano == 1988 || ano == 2000 || ano == 2012 || ano == 2024))
			//* anos do dragao 1940, 1952, 1964, 1976, 1988, 2000, 2012
			{
				printf("Seu zodiaco chines eh o dragao");
			}
			else if ((ano == 2001 || ano == 1941 || ano == 1953 || ano == 1965 || ano == 1977 || ano == 1989 || ano == 2013))
			//* anos da serpente 1941, 1953, 1965, 1977, 1989, 2001, 2013
			{
				printf("Seu zodiaco chines eh a serpente");
			}
			else if ((ano == 2002 || ano == 1942 || ano == 1954 || ano == 1966 || ano == 1978 || ano == 1990 || ano == 2014))
			//* anos do cavalo 1942, 1954, 1966, 1978, 1990, 2002, 2014
			{
				printf("Seu zodiaco chines eh o cavalo");
			}
			else if ((ano == 2003 || ano == 1943 || ano == 1955 || ano == 1967 || ano == 1979 || ano == 1991 || ano == 2015))
			//* anos da cabra 1943, 1955, 1967, 1979, 1991, 2003, 2015
			{
				printf("Seu zodiaco chines eh a cabra");
			}
			else if ((ano == 2004 || ano == 1944 || ano == 1956 || ano == 1968 || ano == 1980 || ano == 1992 || ano == 2016))
			//* anos do macaco 1944, 1956, 1968, 1980, 1992, 2004, 2016
			{
				printf("Seu zodiaco chines eh o macaco");
			}
			else if ((ano == 2005 || ano == 1945 || ano == 1957 || ano == 1969 || ano == 1981 || ano == 1993 || ano == 2017))
			//* anos do galo 1945, 1957, 1969, 1981, 1993, 2005, 2017
			{
				printf("Seu zodiaco chines eh o galo");
			}
			else if ((ano == 2006 || ano == 1946 || ano == 1958 || ano == 1970 || ano == 1982 || ano == 1994 || ano == 2018))
			//* anos do cachorro 1946, 1958, 1970, 1982, 1994, 2006, 2018
			{
				printf("Seu zodiaco chines eh o cachorro");
			}
			else if ((ano == 1947 || ano == 1959 || ano == 1971 || ano == 1983 || ano == 1995 || ano == 2007 || ano == 2019))
			//* anos do porco 1947, 1959, 1971, 1983, 1995, 2007, 2019
			{
				printf("Seu zodiaco chines eh o porco");
			}
			else
			{
				printf("Ano invalido.\n");
			}
			break; // fim do caso 3 do switch

		case 4:
			// Mensagem final ao usuario
			printf("Muito Obrigado, Volte sempre!\n");
			printf("E que o Cosmos esteja com voce!");
			break; // fim do caso 4 do switch
		default:   // caso opcao escolhida seja invalida
			printf("Opcao invalida! Tente denovo.\n");
		}
	} while (opcao != 4); // continua exibindo o menu ate sair
						  // Exibe o menu enquanto a opcao escolhida pelo usuario nao for a opcao 4 (sair)
						  // Essa estrutura de repeticao serve para que o programa continue rodando enquanto o usuario nao escolher a opcao 4
						  // Isso e importante porque a opcao 1 e 2 usam a funcao scanf() que nao limpa o buffer(registo de memoria alocado para armazenar dados temporariamente antes de serem enviados ou processados) e vamos precisar usar o while
						  // para garantir que o buffer esteja limpo antes de pedir novamente as opcoes

	return 0; // encerra o programa
}

//! OBS:
//? buffer" se refere a uma região de memória alocada para armazenar dados temporariamente antes de serem enviados ou processados. É comumente usado em operações de E/S (entrada/saída) para armazenar dados antes de serem gravados em um arquivo ou lidos de um arquivo.
