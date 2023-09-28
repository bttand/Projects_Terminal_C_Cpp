#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<locale.h>

int valor = 0;

void deciBina(int num){
	int i = 0, j = 0, numBinario[20], binarioCerto[20];
	while(num>=1){
		numBinario[i] = num%2;
		if(num%2 == 1){
			num = (num-1)/2;
		}else{
			num = num/2;
		}	
		i++;
	}
	while(i > 0){
		binarioCerto[j] = numBinario[i-1];
		printf("%d", binarioCerto[j]);
		j++;
		i--;
	}
}

void deciHexa(int num){
	int i = 0, j = 0, numBinario[20], binarioCerto[20];
	while(num >= 16){
		numBinario[i] = num%16;
		num = num/16;
		i++;
	}
	numBinario[i] = num;
	while(i >= 0){
		binarioCerto[j] = numBinario[i];
		if(numBinario[i] == 10){
			binarioCerto[j] = 'A';
			printf("%c", (char)(binarioCerto[j]));
		}else if(numBinario[i] == 11){
			binarioCerto[j] = 'B';
			printf("%c", (char)(binarioCerto[j]));
		}else if(numBinario[i] == 12){
			binarioCerto[j] = 'C';
			printf("%c", (char)(binarioCerto[j]));
		}else if(numBinario[i] == 13){
			binarioCerto[j] = 'D';
			printf("%c", (char)(binarioCerto[j]));
		}else if(numBinario[i] == 14){
			binarioCerto[j] = 'E';
			printf("%c", (char)(binarioCerto[j]));
		}else if(numBinario[i] == 15){
			binarioCerto[j] = 'F';
			printf("%c", (char)(binarioCerto[j]));
		}else{
			binarioCerto[j] = numBinario[i];
			printf("%d", binarioCerto[j]);
		}	
		j++;
		i--;
	}
}

void binaDeci(char cadeia[]){
	int acrescimo = strlen(cadeia) - 1;
	for(int i=0; i<strlen(cadeia); i++){
		if(cadeia[i] == '1'){
			valor = valor + pow(2, acrescimo);
			acrescimo--;	
		}else{
			acrescimo--;
		}
	}	
	printf("%d", valor);
}

void hexaDeci(char cadeia[]){
	int acrescimo = strlen(cadeia) - 1;
	for(int i=0; i<strlen(cadeia); i++){
		if(cadeia[i] == 'A' or cadeia[i] == 'a'){
			valor = valor + 10 * pow(16, acrescimo);
			acrescimo--;
		}else if(cadeia[i] == 'B' or cadeia[i] == 'b'){
			valor = valor + 11 * pow(16, acrescimo);
			acrescimo--;	
		}else if(cadeia[i] == 'C' or cadeia[i] == 'c'){
			valor = valor + 12 * pow(16, acrescimo);
			acrescimo--;	
		}else if(cadeia[i] == 'D' or cadeia[i] == 'd'){
			valor = valor + 13 * pow(16, acrescimo);
			acrescimo--;	
		}else if(cadeia[i] == 'E' or cadeia[i] == 'e'){
			valor = valor + 14 * pow(16, acrescimo);
			acrescimo--;
		}else if(cadeia[i] == 'F' or cadeia[i] == 'f'){
			valor = valor + 15 * pow(16, acrescimo);
			acrescimo--;			
		}else{
			valor = valor + ((cadeia[i]) - '0') * pow(16, acrescimo);
			acrescimo--;
		}	
	}	
	printf("%d", valor);
}

void menu(){
	printf("+------------------------------+\n");
	printf("| 1 - Decimal para binário     |\n");
	printf("+------------------------------+\n");
	printf("| 2 - Decimal para hexadecimal |\n");
	printf("+------------------------------+\n");
	printf("| 3 - Binário para decimal     |\n");
	printf("+------------------------------+\n");
	printf("| 4 - Binário para hexadecimal |\n");
	printf("+------------------------------+\n");
	printf("| 5 - Hexadecimal para decimal |\n");
	printf("+------------------------------+\n");
	printf("| 6 - Hexadecimal para binário |\n");
	printf("+------------------------------+\n");
	printf("| 7 - Sair                     |\n");
	printf("+------------------------------+\n\n");
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	int op, num;
	bool sair = false, valido = false;
	char sn, cadeia[20];
	while(!sair){
		valido = false;
		menu();
		printf("Opção: ");
		scanf("%d", &op);
		fflush(stdin);
		switch(op){
			case 1:
				printf("\nValor: ");
				scanf("%d", &num);
				system("cls");
				deciBina(num);
				break;
			case 2:
				printf("\nValor: ");
				scanf("%d", &num);
				system("cls");
				deciHexa(num);
				break;
			case 3:
				printf("\nValor: ");
				scanf("%s", &cadeia);
				system("cls");
				binaDeci(cadeia);
				break;
			case 4:
				printf("\nValor: ");
				scanf("%s", &cadeia);
				binaDeci(cadeia);
				system("cls");
				deciHexa(valor);
				break;
			case 5:
				printf("\nValor: ");
				scanf("%s", &cadeia);
				system("cls");
				hexaDeci(cadeia);
				break;
			case 6:
				printf("\nValor: ");
				scanf("%s", &cadeia);
				hexaDeci(cadeia);
				system("cls");
				deciBina(valor);
				break;
			case 7:
				sair = true;
				system("cls");
				return 0;
			default:
				valido = true;
				system("cls");
				break;
		}
		while(!valido){
			printf("\n\nDeseja fazer outra conversão? (s/n): ");
			scanf("%s", &sn);
			fflush(stdin);
			if(sn == 's' or sn == 'S'){
				valor = 0;
				valido = true;
			}else if(sn == 'n' or sn == 'N'){
				valido = true;
				sair = true;
			}
			system("cls");				
		}
		valido = false;
	}
}
