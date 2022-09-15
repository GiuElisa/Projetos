#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int cpf[11],x; 
int verifp1[2][9],y,auxp1[9],total,resto; 
int verifp2[2][10],auxp2[10],d10,d11;
int resp;
float qtdteste,qtdvalido,qtdinvalido,por100valido,por100invalido;


main(){
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Deseja come�ar testes de verifica��o de CPF?\nDigite 1 (sim) / 2 (n�o):");
	scanf("%d",&resp);
	system("cls");
	
	while (resp == 1){
	
		qtdteste++;
		//Atribuindo os 11 valores do cpf
		printf("Digite cada d�gito de seu cpf (d�gito + enter):\n");
		for (x=0;x<=10;x++){
			scanf("%d",&cpf[x]);
		}
	
		d10 = cpf[9];
		d11 = cpf[10];
			
		//PARTE 1: Gerando o 1 d�gito verificador
		y=10;
		for (x=0;x<=8;x++){
			verifp1[0][x]=cpf[x];
			verifp1[1][x]=y;
			y--;
			auxp1[x]=verifp1[0][x]*verifp1[1][x];
			total+=auxp1[x];
		}
	
		resto = total %11;

		if (total%11<2){
			cpf[9] = 0;
		}else{
			cpf[9] = 11 - resto;
		}
	
		total = 0;
	
		//PARTE 2: Gerando 2 d�gito verificador
		y=11;
		for (x=0;x<=9;x++){
			verifp2[0][x]=cpf[x];
			verifp2[1][x]=y;
			y--;
			auxp2[x]=verifp2[0][x]*verifp2[1][x];
			total+=auxp2[x];
		}
	
		resto = total %11;

		if (total%11<2){
			cpf[10] = 0;
		}else{
			cpf[10] = 11 - resto;
		}
	
		system("cls");
	
		if( (d10 == cpf[9]) && (d11 == cpf[10]) ){
			printf("CPF v�lido.");
			qtdvalido++;
		}else{
			printf("CPF inv�lido.");
			qtdinvalido++;
		}
		
		total = 0;
		resto = 0;
		
		printf("\nPara continuar, digite 1 (sim) / 2 (n�o):");
		scanf("%d",&resp);
		system("cls");
	}
	por100valido = (qtdvalido / qtdteste) *100;
	por100invalido = 100 - por100valido;
	
	//PARTE 3: Sa�da de dados
	printf ("ESTAT�STICAS\n");	
	printf("Quantidade de CPF�s testados: %.0f\n",qtdteste);
	printf("%.0f foram v�lidos\n",qtdvalido);
	printf("%.0f foram inv�lidos\n",qtdinvalido);
	printf("Taxa de aprova��o de %.2f%%\n",por100valido);
	printf("Taxa de reprova��o de %.2f%%", por100invalido);
}
