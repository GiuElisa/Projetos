#include<stdio.h>
#include<string.h>

int a, d;
int A, B, C, D, resultado, resto;
char mes[10];

main(){
	
	printf("Digite seu ano de nascimento:\n");
	scanf("%d", &a);
	
	 if((a%4==0)&& !(a%100==0) || (a%4==0)&&(a%100==0)&&(a%400==0)&&(d<=29)){
        B=a-1;
    }
	
    printf("Escreva seu mes de nascimento:\n");
	scanf("%s", &mes);
	
	if(strcmp(mes, "janeiro")==0){	
	    C=0;
	    
	}else{
		
		if(strcmp(mes, "fevereiro")==0){
		 C=3;	
		 
		}else{
			
			if(strcmp(mes, "março")==0){
			 C=3;
				
			}else{
				
			    if(strcmp(mes, "abril")==0){
			     C=6;
				 	
				}else{
					
					if(strcmp(mes, "maio")==0){
					  C=1;	
						
					}else{
						
						if(strcmp(mes, "junho")==0){
						  C=4;	
							
						}else{
							
							if(strcmp(mes, "julho")==0){
							  C=6;	
								
							}else{
								
								if(strcmp(mes, "agosto")==0){
								  C=2;		
									
								}else{
									
							    	if(strcmp(mes, "setembro")==0){
							    	  C=5;	
							    		
									}else{
										
										if(strcmp(mes, "outubro")==0){
										  C=0;
											
										}else{
											
											if(strcmp(mes, "novembro")==0){
											  C=3;	
												
											}else{
												
												if(strcmp(mes, "dezembro")==0){
												  C=5;	
													
												}
				
											}
											
										}
								
									}	
							    	
								}
								
							}	
							
						}
						
					}
				
				}
				
			}
			
		}
		
	}
	
	printf("Digite o dia do seu nascimento:\n");
    scanf("%d", &d);
    
    A=a-1900;
    B=A/4;
    D=d-1;
    
   
    resultado=A+B+C+D;
    resto=resultado%7;
    
	if(resto=0){
		printf("Você nasceu em uma Segunda-Feira!");
		
	}else{
		
		if(resto=1){
		  printf("Você nasceu em uma Terça-Feira!");
		
		}else{
			
			if(resto=2){
			  printf("Você nasceu em uma Quarta-Feira!");	
			
			}else{
				
				if(resto=3){
				  printf("Você nasceu em uma Quinta-Feira!");	
					
				}else{
					
					if(resto=4){
					  printf("Você nasceu em uma Sexta-Feira!");
						
					}else{
						
						if(resto=5){
						  printf("Você nasceu em um Sábado!");	
							
						}else{
							
							if(resto=6){
							  printf("Você nasceu em um Domingo!");
								
							}
							
						}
						
					}
				
				}
				
			}

		}
		
	}
	
  }  



