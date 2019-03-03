#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void ler_aposta(int *aposta, int n)
{
	int i,j;
	printf("Insira os valores entre 0 e 100.\n");
	for (i=0;i<n;i++)
		do {
			scanf("%d",& *(aposta+i));
			if (aposta[i]<0 || *(aposta+i)>100) {
				printf("Valor inválido!\nInsira outro novamente.\n");
			}
			else 
			for (j=0;j<i;j++) {
				if (aposta[j]==aposta[i]) {
					system("Color 4");
					printf("Número repetido!\nInsira outro valor.\n");
					i--;
				}
			}
		} while (aposta[i] < 0 || *(aposta+i) > 100);
}

void sorteia_valores(int *sorteio, int n)
{
	int i,j;
	int aux;
	printf("\nNúmeros sorteados:\n");
	for (i=0;i<n;i++) {
		do {
			srand(time(NULL));
			sorteio[i]=rand()%100;
			aux=0;
			for (j=0;j<i;j++) {
				if (sorteio[j]==sorteio[i])
					aux=1;
			}
		} while (aux==1);
		printf("%d  ",sorteio[i]);
	}
}

int *compara_aposta(int *aposta, int *sorteio, int *qtdacertos, int na, int ns)
{
	int i,j,k=0;
	int *acertos;
	for (i=0;i<ns;i++) {
		for (j=0;j<na;j++) {
			if (aposta[j]==sorteio[i])
				(*qtdacertos)++;
		}
	}
	acertos = malloc (*qtdacertos*sizeof(int));
	for (i=0;i<ns;i++) {
		for (j=0;j<na;j++) {
			if (aposta[j]==sorteio[i]) {
				acertos[k]=aposta[j];
				k++;
			}
		}
	}
	return acertos;
}


void main ()
{
	int na,*aposta,ns,*sorteio,qtde=0,*acertou,i;
	printf ("Insira o valor da quantidade de números entre 0 e 20 que irá apostar:\n");
	do {
		scanf ("%d",&na);
		if (na<1 || na>20)
			printf ("Quantidade inválida!\nInsira novamente.\n");
	} while (na<1 || na>20);
	aposta = malloc (na*sizeof(int));
	ler_aposta (aposta,na);
	ns=20;
	sorteio = malloc (ns*sizeof(int));
	sorteia_valores (sorteio,ns);
	acertou = compara_aposta (aposta,sorteio,&qtde,na,ns);
	if (qtde==0)
		printf ("\n\nNão acertou nenhum número.\n");
	else {
		printf("\n\nQuantidade de acertos: %d\n",qtde);
		printf("\nNúmeros que acertou: ");
		for (i=0;i<qtde;i++) {
			printf("%d  ",acertou[i]);
		}
	}
	free (aposta);
	free (sorteio);
	free (acertou);
}
