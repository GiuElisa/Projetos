#include<stdio.h>

int n, resto;

main(){
	
	printf("Digite um numero:\n");
	scanf("%d", &n);
	
	if(n==0){
		printf("Numero Neutro");
    }else{
        resto = n%2;
        if(resto==0){
        	printf("Numero Par");	
		}else{
		    printf("Numero Impar");
	    }	
	}		
}

