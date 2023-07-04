#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

int c = 0, v = 0, l = 0, diaT = 0, mesT = 0, anoT = 0;

struct cliente {
    int id;
    char nome[30];
} clientes[10];

struct veiculo {
	int id;
    char classe;
    char placa[10];
} veiculos[10];

struct classe {
	char tipo;
	float valor;
} classes[3];

struct locacao {
    int idLocacao;
    char cliente[30];
    char classeVeiculo;
    char placaVeiculo[10];
    int diaI;
    int mesI;
    int anoI;
    int diaF;
    int mesF;
    int anoF;
	int tempoLocacao;   
    float valorTotal;
} locacoes[10];

void criarClasses() {
	classes[0].tipo = 'A';
	classes[0].valor = 200.00;
	classes[1].tipo = 'B';
	classes[1].valor = 100.00;
	classes[2].tipo = 'C';
	classes[2].valor = 50.00;
}

void cadastrarCliente() {
	bool valido = false;
	int i = 0;
	
	if (c >= 10) {
    	system("cls");
    	printf("Número máximo de clientes atingido\n\n");
		system("pause");
		return;
	}
	while (!valido) {
	    system("cls");
	    printf("0 - voltar para o menu\n\n");
	    printf("Nome do cliente: ");
	    scanf("%s", &clientes[c].nome);
	    fflush(stdin);
	    if (strcmp(clientes[c].nome, "0") == 0) {
	    	system("cls");
	    	return;
		} else {
			i = 0;
		    for (i = 0; i < 30; i++) {
			    if (isdigit(clientes[c].nome[i]) > 0 or ispunct(clientes[c].nome[i]) > 0) {
			    	system("cls");
					printf("Nome inválido\n\n");
					system("pause");
					break;
				}
			    if (i == 29) {
					clientes[c].id = c + 1;
				    c++;
				    valido = true;
				}
			}
		}
	}
}

void cadastrarVeiculo() {
    int contador = 0;
    char classeTemp, placaTemp[10];
    bool valido = false;
	
	if (v >= 10) {
    	system("cls");
    	printf("Número máximo de veículos atingido\n\n");
		system("pause");
		return;
	}
    while (!valido) {
    	while (!valido) {
	    	contador = 0;
			system("cls");
			printf("0 - Voltar para o menu\n\n");
			printf("Digite a placa do veículo (AAA-0A00): ");
			scanf("%s", &placaTemp);
			fflush(stdin);
			if (strcmp(placaTemp, "0") == 0) {
		    	system("cls");
		    	return;
			}
			placaTemp[0] = toupper(placaTemp[0]);
			placaTemp[1] = toupper(placaTemp[1]);
			placaTemp[2] = toupper(placaTemp[2]);
			placaTemp[5] = toupper(placaTemp[5]);	
			if ((isdigit(placaTemp[4]) > 0 and isdigit(placaTemp[6]) > 0 and isdigit(placaTemp[7]) > 0) and placaTemp[3] == '-') {
				if (isalpha(placaTemp[0]) > 0 and isalpha(placaTemp[1]) > 0 and isalpha(placaTemp[2]) > 0 and isalpha(placaTemp[5]) > 0) {
					printf("PLACA: %s", placaTemp);
					valido = true;
				} else {
					system("cls");
					printf("Placa inválida\n\n");
					system("pause");
				}
			} else {
				system("cls");
				printf("Placa inválida\n\n");
				system("pause");	
			}
		}
		valido = false;
        for (int i = 0; i < v; i++) {
            if (strcmp(placaTemp, veiculos[i].placa) == 0) {
                system("cls");
                printf("Veículo já cadastrado\n\n");
                system("pause");
                contador--;
            }
            contador++;
        }
        if (contador == v) {
            strcpy(veiculos[v].placa, placaTemp);
            veiculos[v].id = v + 1;
            valido = true;
        }
	}
    valido = false;
    while (!valido) {
        system("cls");
        printf("PLACA: %s\n\n", placaTemp);
        printf("A - Luxuosos\n\nB - Intermediários\n\nC - Econômicos\n\n");
        printf("Classe do veículo: ");
        scanf("%c", &classeTemp);
        fflush(stdin);
        classeTemp = toupper(classeTemp);
        if (classeTemp == classes[0].tipo) {
            veiculos[v].classe = classes[0].tipo;
            valido = true;
        } else if (classeTemp == classes[1].tipo) {
            veiculos[v].classe = classes[1].tipo;
            valido = true;
        } else if (classeTemp == classes[2].tipo) {
            veiculos[v].classe = classes[2].tipo;
            valido = true;
        } else {
            system("cls");
            printf("Classe inválida\n\n");
            system("pause");
        }
    }
    v++;
}

void conferirData(int x) {
	int maxDias = 0, teste1 = 0, teste2 = 0, teste3 = 0, cont;
	bool valido = false, sair = false;
	char sn, texto[10];
	
	if(x == 1){
		strcpy(texto, "inicial");
	} else {
		strcpy(texto, "final");
	}	
	while (!sair) {
		valido = false;
		while (!valido) {
			diaT = 0;
			mesT = 0;
			anoT = 0;
			cont = 0;
			system("cls");
			printf ("Data %s do período\n", texto);
			printf("DATA: %d/%d/%d\n\n", diaT, mesT, anoT);
			printf("Digite a data %s no seguinte formato (d/m/ano): ", texto);
			scanf("%d/%d/%d", &teste1, &teste2, &teste3);
			fflush(stdin);
			if (teste3 >= 2023 and teste3 <= 2030){
				anoT = teste3;
				cont++;
			}
			if (teste2 >= 1 and teste2 <= 12) {
				mesT = teste2;
				cont++;
				if (mesT == 4 or mesT == 6 or mesT == 9 or mesT == 11) {
					maxDias = 30;
				} else if (mesT == 2) {
					maxDias = 28;
				} else {
					maxDias = 31;
				}
			}
			if (teste1 >= 1 and teste1 <= maxDias) {
				diaT = teste1;
				cont++;
			}
			if (cont == 3) {
				valido = true;
			} else {
				system("cls");
				printf("Data inválida ou superior ao máximo ofertado\n\n");
				system("pause");
			}
		}
		valido = false;
		while (!valido) {
			system("cls");
			printf("%d/%d/%d\n\nConfirmar data %s desejada (s/n): ", diaT, mesT, anoT, texto);
			scanf("%c", &sn);
			fflush(stdin);
			if (sn == 's' or sn == 'S'){
				sair = true;
				valido = true;
			} else if (sn == 'n' or sn == 'N'){
				valido = true;
			} else {
				system("cls");
				printf("Entrada inválida\n\n");
				system("pause");
			}
		}	
	}
}

int calcularDias(int a, int b, int c) {
	int totalDias = -738395;
		
	for (int i = 1; i <= c; i++) {
		totalDias += 365;
	}
	for (int i = 1; i <= b; i++) {
		if (i == 5 or i == 7 or i == 10 or i == 12) {
			totalDias += 30;			
		} else if (i == 3) {
			totalDias += 28;
		} else if (i == 1) {
			totalDias += 0;
		} else {
			totalDias += 31;
		}
	}
	totalDias += a - 1;
	return totalDias;
}

void efetuarLocacao() {
    int idCliente, idVeiculo, dataTempI, dataTempF, dataTesteI, dataTesteF, contar, validar;
    char sn, teste[10];
    bool valido = false, sair = false, voltar = true;
    
    if (c < 1 or v < 1) {
    	system("cls");
    	printf("É necessário que haja ao menos um cliente e um veículo cadastrado para\nrealizar uma locação\n\n");
    	system("pause");
    	return;
	} else if (l >= 10) {
    	system("cls");
    	printf("Número máximo de locações atingido\n\n");
		system("pause");
		return;
	}
    while (!sair) {
        while (!valido) {
            system("cls");
            printf("0 - Voltar para o menu\n\n");
            for (int i = 0; i < c; i++) {
                printf("ID: %d - Nome: %s\n", clientes[i].id, clientes[i].nome);
            }
            printf("\nDigite o ID do cliente: ");
            scanf("%d", &idCliente);
            fflush(stdin);
            if (idCliente == 0) {
		    	system("cls");
		    	return;
			}
            if (idCliente <= c && idCliente > 0) {
                for (int i = 0; i < c; i++) {
                    if (clientes[i].id == idCliente) {
                    	strcpy(locacoes[l].cliente, clientes[i].nome);
                        valido = true;
                        break;
                    }
                }
            }
            if (!valido) {
                system("cls");
                printf("ID inválido\n\n");
                system("pause");
            }
        }
        voltar = true;
        while (voltar) {	        		
        	valido = false;
        	while (!valido) {
	            system("cls");
	            printf("Classe A - Luxuosos\n\n");
	            for (int i = 0; i < v; i++) {
	            	if (veiculos[i].classe == classes[0].tipo) {
	              		printf("ID: %d - Placa: %s\n", veiculos[i].id, veiculos[i].placa);
					}
	            }
	            printf("\n\nClasse B - Intermediários\n\n");
	            for (int i = 0; i < v; i++) {
	            	if (veiculos[i].classe == classes[1].tipo) {
	              		printf("ID: %d - Placa: %s\n", veiculos[i].id, veiculos[i].placa);
					}
	            }
	            printf("\n\nClasse C - Econômicos\n\n");
	            for (int i = 0; i < v; i++) {
	            	if (veiculos[i].classe == classes[2].tipo) {
	              		printf("ID: %d - Placa: %s\n", veiculos[i].id, veiculos[i].placa);
					}
	            }
	            printf("\nDigite o ID do veículo: ");
	            scanf("%d", &idVeiculo);
	            fflush(stdin);
	            if (idVeiculo <= v && idVeiculo > 0) {
	                for (int i = 0; i < v; i++) {
	                	fflush(stdin);
	                    if (veiculos[i].id == idVeiculo) {
	                    	strcpy(teste, veiculos[i].placa);
	                        valido = true;
	                        break;
	                    }
	                }
	            }
				if (!valido) {
	            	system("cls");
	                printf("ID inválido\n\n");
	                system("pause");
				}
			}
			valido = false;
			while (!valido) {
		        system("cls");
		    	conferirData(1);
		    	locacoes[l].diaI = diaT;
		    	locacoes[l].mesI = mesT;
		    	locacoes[l].anoI = anoT;
		        dataTempI = calcularDias(locacoes[l].diaI, locacoes[l].mesI, locacoes[l].anoI);
		    	system("cls");
		    	conferirData(0);
		    	locacoes[l].diaF = diaT;
		    	locacoes[l].mesF = mesT;
		    	locacoes[l].anoF = anoT;
		    	dataTempF = calcularDias(locacoes[l].diaF, locacoes[l].mesF, locacoes[l].anoF);
		    	system("cls");
		    	if (dataTempF <= dataTempI) {
		    		system("cls");
	                printf("Data inválida\n\n");
	                system("pause");
	                break;
				}
	    		if (l == 0) {
	    			valido = true;
	    			voltar = false;
	    			break;
	    		}
	    		contar = 0;
	    		validar = 0;
				for (int i = 0; i < l; i++) {
			    	if (strcmp(teste, locacoes[i].placaVeiculo) == 0) {
			    		contar++;
		    			dataTesteI = calcularDias(locacoes[i].diaI, locacoes[i].mesI, locacoes[i].anoI);
		    			dataTesteF = calcularDias(locacoes[i].diaF, locacoes[i].mesF, locacoes[i].anoF);
						if (dataTempF < dataTesteI or dataTempI > dataTesteF) {
			    			validar++;
						}
					}
				}
				if (validar == contar) {
					valido = true;
					voltar = false;
					break;
				}
				if (!valido) {
					system("cls");
	                printf("Veículo indisponível\n\n");
	                printf("Deseja escolher outro veículo? (s/n): ");
	                scanf("%c", &sn);
			        fflush(stdin);
			        if (sn == 's' || sn == 's') {
			            valido = true;
			            voltar = true;
			            break;
			        } else if (sn == 'n' || sn == 'N') {
			        	voltar = false;
					} else {
						system("cls");
						printf("Entrada inválida\n\n");
			            system("pause");
					}
				}
			}
		}
		for (int i = 0; i < v; i++) {
			if (strcmp(teste, veiculos[i].placa) == 0) {	
            	locacoes[l].idLocacao = l+1;
            	strcpy(locacoes[l].placaVeiculo, teste);
            	locacoes[l].classeVeiculo = veiculos[i].classe;
            	locacoes[l].tempoLocacao = dataTempF - dataTempI;
            	if (locacoes[l].classeVeiculo == classes[0].tipo) {
                	locacoes[l].valorTotal = locacoes[l].tempoLocacao*classes[0].valor;
				} else if (locacoes[l].classeVeiculo == classes[1].tipo) {
					locacoes[l].valorTotal = locacoes[l].tempoLocacao*classes[1].valor;
				} else {
					locacoes[l].valorTotal = locacoes[l].tempoLocacao*classes[2].valor;
				}
			}
		}
		valido = false;
        while (!valido) {
	        system("cls");
	        printf("A locação do veículo %s por %d dias custará no total R$%.2f", locacoes[l].placaVeiculo, locacoes[l].tempoLocacao, locacoes[l].valorTotal);
	        printf("\n\nConfirmar operação? (s/n): ");
	        scanf("%c", &sn);
	        fflush(stdin);
	        if (sn == 's' || sn == 'S') {
	        	system("cls");
	        	printf("Locação realizada com sucesso\n\n");
	            system("pause");
	            sair = true;
	            valido = true;
	            l++;
	        } else if (sn == 'n' || sn == 'N') {
	        	valido = true;
	        	break;
			} else {
				system("cls");
				printf("Entrada inválida\n\n");
	            system("pause");
			}
		}
		sair = true;
    }
	valido = false;
}

void exibirlocacao(int i) {
	printf("+---------------------------------------+\n");
    printf("ID Locação: %d\n", locacoes[i].idLocacao);
    printf("-----------------------------------------\n");
    printf("Cliente: %s\n", locacoes[i].cliente);
    printf("-----------------------------------------\n");
    printf("Classe Veículo: %c\n", locacoes[i].classeVeiculo);
    printf("-----------------------------------------\n");
    printf("Placa Veículo: %s\n", locacoes[i].placaVeiculo);
    printf("-----------------------------------------\n");
    printf("Data inicial da locação: %d/%d/%d\n", locacoes[i].diaI, locacoes[i].mesI, locacoes[i].anoI);
    printf("-----------------------------------------\n");
   	printf("Data final da locação: %d/%d/%d\n", locacoes[i].diaF, locacoes[i].mesF, locacoes[i].anoF);
   	printf("-----------------------------------------\n");
   	printf("Total de dias locado: %d\n", locacoes[i].tempoLocacao);
   	printf("-----------------------------------------\n");
    printf("Valor Total: R$%.2f\n", locacoes[i].valorTotal);
    printf("+---------------------------------------+\n\n");
}

void listarLocacoes() {
	system("cls");
	if (l < 1) {
		system("cls");
		printf("É necessário que haja ao menos uma locação para realizar a listagem\n\n");
		system("pause");
		return;
	}
	for (int i = 0; i < l; i++) {
    	exibirlocacao(i);           		
	}
	system("pause");
}

void listarNome() {
	int idCliente;
	char nomeTemp[30];
	bool valido = false;
	
	if (l < 1) {
    	system("cls");
    	printf("É necessário que haja ao menos uma locação para realizar a listagem\n\n");
    	system("pause");
    	return;
	}
	while (!valido) {
        system("cls");
        printf("0 - Voltar para o menu\n\n");
        for (int i = 0; i < c; i++) {
          	printf("ID: %d - Cliente: %s\n", clientes[i].id, clientes[i].nome);
        } 
	    printf("\nDigite o ID do cliente: ");
	    scanf("%d", &idCliente);
	    fflush(stdin);
	    if (idCliente == 0){
	    	system("cls");
	    	break;
		}
	    if (idCliente <= c && idCliente > 0) {
	    	valido = true;
	    	system("cls");
	        for (int i = 0; i < l; i++) {
	            if (clientes[i].id == idCliente) {
	            	strcpy(nomeTemp, clientes[i].nome);
	            }
	        }
	    }
	    if (valido) {
	    	for (int i = 0; i < l; i++) {
	    		if (strcmp(nomeTemp, locacoes[i].cliente) == 0) {
	    			exibirlocacao(i);
				}
			}
			system("pause");
		} else if (!valido){
			system("cls");
			printf("Cliente não cadastrado\n\n");
			system("pause");		
		}
	}
}

void listarVeiculo() {
	int idVeiculo;
	char placaTemp[10];
	bool valido = false;
	
	if (l < 1) {
    	system("cls");
    	printf("É necessário que haja ao menos uma locação para realizar a listagem\n\n");
    	system("pause");
    	return;
	}
    while (!valido) {
        system("cls");
        printf("0 - Voltar para o menu\n\n");
        for (int i = 0; i < v; i++) {
          	printf("ID: %d - Placa: %s - Classe: %c\n", veiculos[i].id, veiculos[i].placa, veiculos[i].classe);
        } 
	    printf("\nDigite o ID do veículo: ");
	    scanf("%d", &idVeiculo);
	    fflush(stdin);
	    if (idVeiculo == 0){
	    	system("cls");
	    	break;
		}
	    if (idVeiculo <= v && idVeiculo > 0) {
			valido = true;
	    	system("cls");
	        for (int i = 0; i < l; i++) {
	            if (veiculos[i].id == idVeiculo) {
	            	strcpy(placaTemp, veiculos[i].placa);
	            }
	        }
	    }
	    if (valido) {
	    	for (int i = 0; i < l; i++) {
	    		if (strcmp(placaTemp, locacoes[i].placaVeiculo) == 0) {
	    			exibirlocacao(i);
				}
			}
			system("pause");
		} else if (!valido){
			system("cls");
			printf("Veículo não cadastrado\n\n");
			system("pause");		
		}
	}
}

void listarPeriodo() {
	int total, diaPi, mesPi, anoPi, diaPf, mesPf, anoPf, periodoI, periodoF, testeI, testeF;
	
	if (l < 1) {
    	system("cls");
    	printf("É necessário que haja ao menos uma locação para realizar a listagem\n\n");
    	system("pause");
    	return;
	}	
	conferirData(1);
	diaPi = diaT;
	mesPi = mesT;
	anoPi = anoT;
	periodoI = calcularDias(diaPi, mesPi, anoPi);
	conferirData(2);
	diaPf = diaT;
	mesPf = mesT;
	anoPf = anoT;
	periodoF = calcularDias(diaPf, mesPf, anoPf);
	system("cls");
	for (int i = 0; i < l; i++){
		testeI = calcularDias(locacoes[i].diaI, locacoes[i].mesI, locacoes[i].anoI);
		testeF = calcularDias(locacoes[i].diaF, locacoes[i].mesF, locacoes[i].anoF);
		if (testeI >= periodoI and testeF <= periodoF){
			exibirlocacao(i);
			total += locacoes[i].valorTotal;
		}		
	}
	printf("Total de ganhos nesse período: R$ %d.00\n\n", total);
	system("pause");
}

void menu() {
	printf("+---------------------------------+\n");
	printf(" 1 - Cadastrar cliente             \n");
	printf("+---------------------------------+\n");
	printf(" 2 - Cadastrar veículo             \n");
	printf("+---------------------------------+\n");
	printf(" 3 - Efetuar locação               \n");
	printf("+---------------------------------+\n");
	printf(" 4 - Listar locações               \n");
	printf("+---------------------------------+\n");
	printf(" 5 - Listar locações por cliente   \n");
	printf("+---------------------------------+\n");
	printf(" 6 - Listar locações por veículo   \n");
	printf("+---------------------------------+\n");
	printf(" 7 - Listar locações por período   \n");
	printf("+---------------------------------+\n");
	printf(" 0 - Sair                          \n");
	printf("+---------------------------------+\n\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao;
    bool sair = false;

	criarClasses();
    while (!sair) {
        system("cls");
        menu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        fflush(stdin);
        switch (opcao) {
            case 1:
                cadastrarCliente();
                break;
            case 2:
                cadastrarVeiculo();
                break;
            case 3:
                efetuarLocacao();
                break;
            case 4:
            	listarLocacoes();
                break;
            case 5:
	            listarNome();
            	break;
            case 6:
            	listarVeiculo();
            	break;
            case 7:
				listarPeriodo();
            	break;
            case 0:
            	system("cls");
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