#include<stdio.h>

int n, a, r, p, contador;

main(){
	
	printf("Programa para determinar os valores de uma progressao aritmetica.\n");
	
	printf("Digite a quantidade de numeros desejada na progressao:\n");
	scanf("%d", &n);
	
	printf("Digite o primeiro numero da progressao:\n");
	scanf("%d", &a);
	
	printf("Digite a razao:\n");
	scanf("%d", &r);
	
	printf ("Resultado:\n");
	printf("%d\n", a);
	
	for(contador=1; contador<=n; contador++){
		p = a + r;
		a = p;
		printf("%d\n", p);	
	}
}
