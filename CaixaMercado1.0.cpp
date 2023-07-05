#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

int p = 0, v = 0, r = 0;

struct produto {
	int quantidade;
	char nome[30];
	float precoUni;
} produtos[10];

struct venda {
	int quantidade;
	char nome[30];
	float total;
} vendas[10];

struct registro {
	venda vendas[10];
	int qntVenda;
	float total;	
} registros[10];

void cadastrarProduto() {
	bool confirma, valido;
	char sn;
	
	while (!confirma) {
		system("cls");
		printf("Nome do produto: ");
		scanf("%s", &produtos[p].nome);
		valido = false;
		while (!valido) {
			system("cls");
			printf("Quantidade: ");
			scanf("%d", &produtos[p].quantidade);
			if (produtos[p].quantidade > 0) {
				valido = true;
			} else {
				system("cls");
				printf("Quantidade inválida\n\n");
				system("pause");
			}	
		}
		valido = false;
		while (!valido) {
			system("cls");
			printf("Preço unitário: ");
			scanf("%f", &produtos[p].precoUni);
			if (produtos[p].precoUni > 0) {
				valido = true;
			} else {
				system("cls");
				printf("Quantidade inválida\n\n");
				system("pause");
			}
		}
		valido = false;
		while (!valido) {
			system("cls");
			printf("+-------------------------+\n");
			printf(" Produto: %s\n", produtos[p].nome);
			printf("+-------------------------+\n");
			printf(" Quantidade: %d\n", produtos[p].quantidade);
			printf("+-------------------------+\n");
			printf(" Preço unitário: R$ %.2f\n", produtos[p].precoUni);
			printf("+-------------------------+\n\n");
			printf("Confirmar cadastro? (s/n): ");
			scanf("%c", &sn);
			if (sn == 's' or sn == 'S') {
				valido = true;
				confirma = true;
				p++;
			} else if (sn == 'n' or sn == 'N') {
				valido = true;
			}		
		}
	}
}

void buscarProduto() {
	char buscar[30], sn;

	while (true) {
		system("cls");
		for (int i = 0; i < p; i++) {
			printf("+-------------------------+\n");
			printf("Produto: %s\n", produtos[i].nome);
			printf("+-------------------------+\n\n");
		}
		printf("\nBuscar produto: ");
		scanf("%s", &buscar);
		fflush(stdin);
		system("cls");
		for (int i = 0; i < p; i++) {
			if (strcmp(buscar, produtos[i].nome) == 0) {
				printf("+-------------------------+\n");
				printf(" Produto: %s\n", produtos[i].nome);
				printf("+-------------------------+\n");
				printf(" Quantidade: %d\n", produtos[i].quantidade);
				printf("+-------------------------+\n");
				printf(" Preço unitário: R$ %.2f\n", produtos[i].precoUni);
				printf("+-------------------------+\n\n");
				printf("Buscar outro produto (s/n): ");
				scanf("%c", &sn);
				if (sn == 's' or sn == 'S') {
					break;
				} else if (sn == 'n' or sn == 'N') {
					system("cls");
					return;
				} else {
					system("cls");
					printf("Entrada inválida\n\n");
					system("pause");
					break;
				}
			}
		}
	}
}

void realizarVenda() {
	bool valido, sair;
	char entrada[10];
	
	while(!sair) {
		valido = false;
		while (!valido) {
			system("cls");
			for (int i = 0; i < p; i++) {
				printf("+-------------------------+\n");
				printf(" Produto: %s\n", produtos[i].nome);
				printf("+-------------------------+\n");
				printf(" Quantidade: %d\n", produtos[i].quantidade);
				printf("+-------------------------+\n");
				printf(" Preço unitário: R$ %.2f\n", produtos[i].precoUni);
				printf("+-------------------------+\n");
			}
			printf("\nTOTAL: %.2f\n", registros[r].total);
			printf("\nDigite 0 para finalizar a compra\n");
			printf("\nEntrada: ");
			scanf("%s", &entrada);
			fflush(stdin);
			if (strcmp(entrada, "0") > 0) {
				strcpy(registros[r].vendas[v].nome, entrada);
				for (int i = 0; i < p; i++) {
					if (strcmp(registros[r].vendas[v].nome, produtos[i].nome) == 0) {
						printf("Quantidade: ");
						scanf("%d", &registros[r].vendas[v].quantidade);
						fflush(stdin);
						if (registros[r].vendas[v].quantidade <= produtos[i].quantidade) {
							registros[r].vendas[v].total += registros[r].vendas[v].quantidade*produtos[i].precoUni;
							produtos[i].quantidade -= registros[r].vendas[v].quantidade;
							registros[r].total += registros[r].vendas[v].total;
							valido = true;
							v++;
						} else {
							printf("\nQuantidade indisponível\n\n");
							system("pause");
							break;
						}
					} 
				}			
			} else {
				registros[r].qntVenda = v;
				r++;
				sair = true;
				valido = true;
			}
		}	
	}
}

float abrirCaixa() {
	float valorInicial;
	
	printf("Valor inicial do caixa: ");
	scanf("%f", &valorInicial);
	return valorInicial;
}

void fecharCaixa(float inicial) {
	int i = 0;
	float total = 0;
	
	system("cls");
	printf("**Vendas realizadas**\n\n");
	for (int y = 0; y < r; y++) {
		for (i; i < registros[y].qntVenda; i++) {
			printf("+-------------------------+\n");
			printf(" Produto: %s\n", registros[y].vendas[i].nome);
			printf("+-------------------------+\n");
			printf(" Quantidade: %d\n", registros[y].vendas[i].quantidade);
			printf("+-------------------------+\n");
			printf(" Valor: R$ %.2f\n", registros[y].vendas[i].total);
		}
		i = registros[y].qntVenda;
		printf("+-------------------------+\n");
		printf(" Total da compra: %.2f\n", registros[y].total);
		printf("+-------------------------+\n\n");
		total += registros[y].total;
	}
	total += inicial;
	printf("Abrimento do Caixa: R$ %.2f\n", inicial);
	printf("Total no fechamento: R$ %.2f\n\n", total);
	system("pause");
}

void menu() {
	printf("+---------------------------------+\n");
	printf(" 1 - Cadastrar produto             \n");
	printf("+---------------------------------+\n");
	printf(" 2 - Buscar produto                \n");
	printf("+---------------------------------+\n");
	printf(" 3 - Realizar venda                \n");
	printf("+---------------------------------+\n");
	printf(" 4 - Fechar caixa                  \n");
	printf("+---------------------------------+\n\n");
}

int main () {
	setlocale(LC_ALL, "Portuguese");
    int opcao;
    bool sair = false;
    float inicial;
	
	inicial = abrirCaixa();
    while (!sair) {
        system("cls");
        menu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        fflush(stdin);
        switch (opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                buscarProduto();
                break;
            case 3:
                realizarVenda();
                break;
            case 4:
            	fecharCaixa(inicial);
            	sair = true;
                break;
            default:
                system("cls");
			    printf("Opção inválida\n\n");
			    system("pause");
                break;
        }
    }
}