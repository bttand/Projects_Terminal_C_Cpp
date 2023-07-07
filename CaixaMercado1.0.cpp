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
	int id;
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
		fflush(stdin);
		valido = false;
		while (!valido) {
			system("cls");
			printf("Quantidade: ");
			scanf("%d", &produtos[p].quantidade);
			fflush(stdin);
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
			fflush(stdin);
			if (produtos[p].precoUni > 0) {
				valido = true;
			} else {
				system("cls");
				printf("Preço inválido\n\n");
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
			fflush(stdin);
			if (sn == 's' or sn == 'S') {
				valido = true;
				confirma = true;
				p++;
			} else if (sn == 'n' or sn == 'N') {
				valido = true;
			} else {
				system("cls");
				printf("Entrada inválida\n\n");
				system("pause");
			}
		}
	}
}

void buscarProduto() {
	char buscar[30], sn;
	bool valido;

	while (true) {
		system("cls");
		printf("+-------------------------+\n");
		for (int i = 0; i < p; i++) {
			if (produtos[i].quantidade > 0) {
				printf(" Produto: %s\n", produtos[i].nome);
				printf("+-------------------------+\n");
			}
		}
		printf("\nDigite 0 para sair\n");
		printf("\nBuscar produto: ");
		scanf("%s", &buscar);
		fflush(stdin);
		if (strcmp(buscar, "0") == 0) {
			system("cls");
			return;
		} else {
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
					system("pause");
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
				if (produtos[i].quantidade > 0) {
					printf("+-------------------------+\n");
					printf(" Produto: %s\n", produtos[i].nome);
					printf("+-------------------------+\n");
					printf(" Quantidade: %d\n", produtos[i].quantidade);
					printf("+-------------------------+\n");
					printf(" Preço unitário: R$ %.2f\n", produtos[i].precoUni);
					printf("+-------------------------+\n");			
				}
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
				registros[r].id = r + 1;
				registros[r].qntVenda = v;
				r++;
				sair = true;
				valido = true;
			}
		}	
	}
}

void listarVenda() {
	int i, procura;
	bool sair;
	
	while (!sair) {
		system("cls");
		for (int y = 0; y < r; y++) {
			printf("ID: %d - Total: %.2f\n", registros[y].id, registros[y].total);
		}
		printf("\nDigite 0 para sair\n");
		printf("\nID da venda: ");
		scanf("%d", &procura);
		fflush(stdin);
		if (procura == 0) {
			system("cls");
			return;
		} else {
			i = 0;
			for (int y = 0; y < r; y++) {
				if (procura == registros[y].id) {
					for (i; i < registros[y].qntVenda; i++) {
						printf("+-------------------------+\n");
						printf(" Produto: %s\n", registros[y].vendas[i].nome);
						printf("+-------------------------+\n");
						printf(" Quantidade: %d\n", registros[y].vendas[i].quantidade);
						printf("+-------------------------+\n");
						printf(" Valor: R$ %.2f\n", registros[y].vendas[i].total);
					}
					printf("+-------------------------+\n");
					printf(" Total da compra: %.2f\n", registros[y].total);
					printf("+-------------------------+\n\n");
					system("pause");
				}
				i = registros[y].qntVenda;
			}
		}
	}
}

void fecharCaixa(float inicial) {
	int i = 0;
	float total = 0;
	
	system("cls");
	printf("Vendas realizadas\n\n");
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
	printf("Valor na abertura: R$ %.2f\n", inicial);
	printf("Valor no fechamento: R$ %.2f\n", total);
	printf("Total de ganho: R$ %.2f\n\n", total-inicial);
	system("pause");
}

void menuFechado() {
	printf("+---------------------------------+\n");
	printf(" 1 - Cadastrar produto             \n");
	printf("+---------------------------------+\n");
	printf(" 2 - Buscar produto                \n");
	printf("+---------------------------------+\n");
	printf(" 3 - Abrir caixa                   \n");
	printf("+---------------------------------+\n");
	printf(" 0 - Sair                          \n");
	printf("+---------------------------------+\n\n");
}

void menuAberto() {
	printf("+---------------------------------+\n");
	printf(" 1 - Realizar venda                \n");
	printf("+---------------------------------+\n");
	printf(" 2 - Listar venda                  \n");
	printf("+---------------------------------+\n");
	printf(" 3 - Fechar caixa                  \n");
	printf("+---------------------------------+\n\n");
}

void abrirCaixa() {
	int opcao;
	bool sair;
	float inicial;
	
	system("cls");
	printf("Valor inicial do caixa: ");
	scanf("%f", &inicial);
    while (!sair) {
		system("cls");
		menuAberto();
		printf("Escolha uma opção: ");
		scanf("%d", &opcao);
        fflush(stdin);
        switch (opcao) {
            case 1:
                realizarVenda();
                break;
            case 2:
                listarVenda();
                break;
            case 3:
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

int main () {
	setlocale(LC_ALL, "Portuguese");
    int opcao;
    bool sair = false;
    float inicial;
	
    while (!sair) {
        system("cls");
        menuFechado();
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
                abrirCaixa();
                break;
            case 0:
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