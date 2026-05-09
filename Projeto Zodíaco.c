#include <stdio.h>
#include <locale.h>
int main()
{

	setlocale(LC_ALL, "Portuguese");

	int opcao, dia, mes, ano;

	do
	{

		printf("\n================== MENU ===============");
		printf("\n===== ESCOLHA O CALENDARIO ZODIACO =====\n");
		printf("[1] Tradicional\n");
		printf("[2] Egipicio\n");
		printf("[3] Chines\n");
		printf("[4] Sair\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &opcao);

		switch (opcao)
		{
		case 1:

			printf("\n====== ZODIACO TRADICIONAL ======\n");
			printf("Digite o dia em que nasceu: ");
			scanf("%d", &dia);
			printf("Agora em que mes nasceu: ");
			scanf("%d", &mes);

			//* Explicação do IF Else:

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
				printf("Data de nascimento invalida.\n");
			}
			break;

		case 2:
			printf("\n====== ZODIACO EGIPICIO ======\n");

			printf("Digite o dia em que nasceu: ");
			scanf("%d", &dia);

			printf("Agora em que mes nasceu: ");
			scanf("%d", &mes);

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
				printf("Seu signo e Anubis.\n");
			}
			else if ((mes == 1 && dia >= 16) || (mes == 2 && dia <= 15))
			{
				printf("Seu signo e Bastet.\n");
			}
			else if ((mes == 2 && dia >= 16) || (mes == 3 && dia <= 15))
			{
				printf("Seu signo e Tauret.\n");
			}
			else
			{
				printf("Data de nascimento invalida.\n");
			}
			break;

		case 3:
			printf("\n====== ZODIACO CHINES ======\n");
			printf("Digite o ano do seu nascimento: ");
			scanf("%d", &ano);

			if ((ano == 1936 || ano == 1948 || ano == 1960 || ano == 1972 || ano == 1984 || ano == 1996 || ano == 2008 || ano == 2020))

			{
				printf("Seu zodiaco chines eh o Rato");
			}
			else if ((ano == 1937 || ano == 1949 || ano == 1961 || ano == 1973 || ano == 1985 || ano == 1997 || ano == 2009 || ano == 2021))

			{
				printf("Seu zodiaco chines eh o bufalo");
			}
			else if ((ano == 1938 || ano == 1950 || ano == 1962 || ano == 1974 || ano == 1986 || ano == 1998 || ano == 2010 || ano == 2022))

			{
				printf("Seu zodiaco chines eh o tigre");
			}
			else if ((ano == 1939 || ano == 1951 || ano == 1963 || ano == 1975 || ano == 1987 || ano == 1999 || ano == 2011 || ano == 2023))

			{
				printf("Seu zodiaco chines eh o coelho");
			}
			else if ((ano == 1940 || ano == 1952 || ano == 1964 || ano == 1976 || ano == 1988 || ano == 2000 || ano == 2012 || ano == 2024))

			{
				printf("Seu zodiaco chines eh o dragao");
			}
			else if ((ano == 2001 || ano == 1941 || ano == 1953 || ano == 1965 || ano == 1977 || ano == 1989 || ano == 2013))

			{
				printf("Seu zodiaco chines eh a serpente");
			}
			else if ((ano == 2002 || ano == 1942 || ano == 1954 || ano == 1966 || ano == 1978 || ano == 1990 || ano == 2014))

			{
				printf("Seu zodiaco chines eh o cavalo");
			}
			else if ((ano == 2003 || ano == 1943 || ano == 1955 || ano == 1967 || ano == 1979 || ano == 1991 || ano == 2015))

			{
				printf("Seu zodiaco chines eh a cabra");
			}
			else if ((ano == 2004 || ano == 1944 || ano == 1956 || ano == 1968 || ano == 1980 || ano == 1992 || ano == 2016))

			{
				printf("Seu zodiaco chines eh o macaco");
			}
			else if ((ano == 2005 || ano == 1945 || ano == 1957 || ano == 1969 || ano == 1981 || ano == 1993 || ano == 2017))

			{
				printf("Seu zodiaco chines eh o galo");
			}
			else if ((ano == 2006 || ano == 1946 || ano == 1958 || ano == 1970 || ano == 1982 || ano == 1994 || ano == 2018))

			{
				printf("Seu zodiaco chines eh o cachorro");
			}
			else if ((ano == 1947 || ano == 1959 || ano == 1971 || ano == 1983 || ano == 1995 || ano == 2007 || ano == 2019))

			{
				printf("Seu zodiaco chines eh o porco");
			}
			else
			{
				printf("Ano invalido.\n");
			}
			break;

		case 4:

			printf("Muito Obrigado, Volte sempre!\n");
			printf("E que o Cosmos esteja com voce!");
			break;
		default:
			printf("Opcao invalida! Tente denovo.\n");
		}
	} while (opcao != 4);

	return 0;
}
