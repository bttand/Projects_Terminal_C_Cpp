#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

#define MAX_CLIENTES 10
#define MAX_VEICULOS 10
#define MAX_LOCACOES 10
#define MAX_CLASSES 3

int c = 0, v = 0, l = 0, diaT = 0, mesT = 0, anoT = 0;

struct cliente {
    int id;
    char nome[30];
} clientes[MAX_CLIENTES];

struct veiculo {
	int id;
    char classe;
    char placa[10];
} veiculos[MAX_VEICULOS];

struct classe {
	char tipo;
	float valor;
} classes[MAX_CLASSES];

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
} locacoes[MAX_LOCACOES];

void criarArquivo() {
	FILE *arquivo = fopen("arquivo.txt", "a");
	fclose(arquivo);
}

void salvarCadastro() {
	FILE *arquivo = fopen("arquivo.txt", "w");
	if (arquivo == NULL) {
		return;
	}
	fprintf(arquivo, "%d\n", c);
	for (int i = 0; i < c; i++) {
		fprintf(arquivo, "%d\n", clientes[i].id);
		fprintf(arquivo, "%s\n", clientes[i].nome);
	}
	fprintf(arquivo, "%d\n", v);
	for (int i = 0; i < v; i++) {
		fprintf(arquivo, "%d\n", veiculos[i].id);
		fprintf(arquivo, "%c\n", veiculos[i].classe);
		fprintf(arquivo, "%s\n", veiculos[i].placa);
	}
	fprintf(arquivo, "%d\n", l);
	for (int i = 0; i < l; i++) {
		fprintf(arquivo, "%d\n", locacoes[i].idLocacao);
		fprintf(arquivo, "%s\n", locacoes[i].cliente);
		fprintf(arquivo, "%c\n", locacoes[i].classeVeiculo);
		fprintf(arquivo, "%s\n", locacoes[i].placaVeiculo);
		fprintf(arquivo, "%d/%d/%d\n", locacoes[i].diaI, locacoes[i].mesI, locacoes[i].anoI);
		fprintf(arquivo, "%d/%d/%d\n", locacoes[i].diaF, locacoes[i].mesF, locacoes[i].anoF);
		fprintf(arquivo, "%d\n", locacoes[i].tempoLocacao);
		fprintf(arquivo, "%.2f\n", locacoes[i].valorTotal);
	}
	fclose(arquivo);
}

void lerCadastro() {
	FILE *arquivo = fopen("arquivo.txt", "r");
	if (arquivo == NULL) {
		return;
	}
	fscanf(arquivo, "%d\n", &c);
	for (int i = 0; i < c; i++) {
		fscanf(arquivo, "%d\n", &clientes[i].id);
		fscanf(arquivo, "%s\n", &clientes[i].nome);
	}
	fscanf(arquivo, "%d\n", &v);
	for (int i = 0; i < v; i++) {
		fscanf(arquivo, "%d\n", &veiculos[i].id);
		fscanf(arquivo, "%c\n", &veiculos[i].classe);
		fscanf(arquivo, "%s\n", &veiculos[i].placa);
	}
	fscanf(arquivo, "%d\n", &l);
	for (int i = 0; i < l; i++) {
		fscanf(arquivo, "%d\n", &locacoes[i].idLocacao);
		fscanf(arquivo, "%s\n", &locacoes[i].cliente);
		fscanf(arquivo, "%c\n", &locacoes[i].classeVeiculo);
		fscanf(arquivo, "%s\n", &locacoes[i].placaVeiculo);
		fscanf(arquivo, "%d/%d/%d\n", &locacoes[i].diaI, &locacoes[i].mesI, &locacoes[i].anoI);
		fscanf(arquivo, "%d/%d/%d\n", &locacoes[i].diaF, &locacoes[i].mesF, &locacoes[i].anoF);
		fscanf(arquivo, "%d\n", &locacoes[i].tempoLocacao);
		fscanf(arquivo, "%f\n", &locacoes[i].valorTotal);
	}
	fclose(arquivo);
}

void marca(int i) {
	char x[30];
	
	if (i == 0) {
		strcpy(x, "           MENU");
	} else if (i == 1) {
		strcpy(x, "   CADASTRO DE CLIENTES");
	} else if (i == 2) {
		strcpy(x, "   CADASTRO DE VEÍCULOS");
	} else if (i == 3) {
		strcpy(x, "     EFETUAR LOCAÇÕES");
	} else if (i == 4) {
		strcpy(x, " LISTAR TODAS AS LOCAÇÕES");
	} else if (i == 5) {
		strcpy(x, "LISTAR LOCAÇÕES POR CLIENTE");
	} else if (i == 6) {
		strcpy(x, "LISTAR LOCAÇÕES POR VEÍCULO");
	} else if (i == 7) {
		strcpy(x, "LISTAR LOCAÇÕES POR PERÍODO");
	}
	printf("\t\t\t+------------------------------------------------------------------------+\n");
	printf("\t\t\t                                B  A  D  D                                \n");
	printf("\t\t\t                         Sua locadora de veículos                         \n");
	printf("\t\t\t+------------------------------------------------------------------------+\n");
	printf("\t\t\t                        %s                                            \n", x);
	printf("\t\t\t+------------------------------------------------------------------------+\n\n");		
}

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
	
	if (c >= MAX_CLIENTES) {
    	system("cls");
    	marca(1);
    	printf("\t\t\tNúmero máximo de clientes atingido\n\n");
    	printf("\t\t\t");
		system("pause");
		return;
	}
	while (valido == false) {
	    system("cls");
	    marca(1);
	    printf("\t\t\t0 - voltar para o menu\n\n");
	    printf("\t\t\tNome do cliente: ");
	    scanf("%s", &clientes[c].nome);
	    fflush(stdin);
	    if (strcmp(clientes[c].nome, "0") == 0) {
	    	system("cls");
	    	marca(1);
	    	return;
		} else {
			i = 0;
		    for (i = 0; i < 30; i++) {
			    if (isdigit(clientes[c].nome[i]) > 0 or ispunct(clientes[c].nome[i]) > 0) {
			    	system("cls");
					marca(1);
					printf("\t\t\tNome inválido\n\n");
					printf("\t\t\t");
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
	
	if (v >= MAX_VEICULOS) {
    	system("cls");
    	marca(2);
    	printf("\t\t\tNúmero máximo de veículos atingido\n\n");
    	printf("\t\t\t");
		system("pause");
		return;
	}
    while (valido == false) {
    	while (valido == false) {
	    	contador = 0;
			system("cls");
			marca(2);
			printf("\t\t\t0 - Voltar para o menu\n\n");
			printf("\t\t\tDigite a placa do veículo (AAA-0A00): ");
			scanf("%s", &placaTemp);
			fflush(stdin);
			if (strcmp(placaTemp, "0") == 0) {
		    	system("cls");
		    	marca(2);
		    	return;
			}
			placaTemp[0] = toupper(placaTemp[0]);
			placaTemp[1] = toupper(placaTemp[1]);
			placaTemp[2] = toupper(placaTemp[2]);
			placaTemp[5] = toupper(placaTemp[5]);	
			if ((isdigit(placaTemp[4]) > 0 and isdigit(placaTemp[6]) > 0 and isdigit(placaTemp[7]) > 0) and placaTemp[3] == '-') {
				if (isalpha(placaTemp[0]) > 0 and isalpha(placaTemp[1]) > 0 and isalpha(placaTemp[2]) > 0 and isalpha(placaTemp[5]) > 0) {
					printf("\t\t\tPLACA: %s", placaTemp);
					valido = true;
				} else {
					system("cls");
					marca(2);
					printf("\t\t\tPlaca inválida\n\n");
					printf("\t\t\t");
					system("pause");
				}
			} else {
				system("cls");
				marca(2);
				printf("\t\t\tPlaca inválida\n\n");
				printf("\t\t\t");
				system("pause");	
			}
		}
		valido = false;
        for (int i = 0; i < v; i++) {
            if (strcmp(placaTemp, veiculos[i].placa) == 0) {
                system("cls");
                marca(2);
                printf("\t\t\tVeículo já cadastrado\n\n");
                printf("\t\t\t");
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
    while (valido == false) {
        system("cls");
        marca(2);
        printf("\t\t\tPLACA: %s\n\n", placaTemp);
        printf("\t\t\tA - Luxuosos\n\n\t\t\tB - Intermediários\n\n\t\t\tC - Econômicos\n\n");
        printf("\t\t\tClasse do veículo: ");
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
            marca(2);
            printf("\t\t\tClasse inválida\n\n");
            printf("\t\t\t");
            system("pause");
        }
    }
    v++;
}

void conferirData(int x, int y) {
	int maxDias = 0, teste1 = 0, teste2 = 0, teste3 = 0, cont;
	bool valido = false, sair = false;
	char sn, texto[10];
	
	if(x == 1){
		strcpy(texto, "inicial");
	} else {
		strcpy(texto, "final");
	}	
	while (sair == false) {
		valido = false;
		while (valido == false) {
			diaT = 0;
			mesT = 0;
			anoT = 0;
			cont = 0;
			system("cls");
			marca(y);
			printf ("\t\t\tData %s do período\n", texto);
			printf("\t\t\tDATA: %d/%d/%d\n\n", diaT, mesT, anoT);
			printf("\t\t\tDigite a data %s no seguinte formato (d/m/ano): ", texto);
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
				marca(y);
				printf("\t\t\tData inválida ou superior ao máximo ofertado\n\n");
				printf("\t\t\t");
				system("pause");
			}
		}
		valido = false;
		while (valido == false) {
			system("cls");
			marca(y);
			printf("\t\t\t%d/%d/%d\n\n\t\t\tConfirmar data %s desejada (s/n): ", diaT, mesT, anoT, texto);
			scanf("%c", &sn);
			fflush(stdin);
			if (sn == 's' or sn == 'S'){
				sair = true;
				valido = true;
			} else if (sn == 'n' or sn == 'N'){
				valido = true;
			} else {
				system("cls");
				marca(y);
				printf("\t\t\tEntrada inválida\n\n");
				printf("\t\t\t");
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
    	marca(3);
    	printf("\t\t\tÉ necessário que haja ao menos um cliente e um veículo cadastrado para\n\t\t\trealizar uma locação\n\n");
    	printf("\t\t\t");
    	system("pause");
    	return;
	} else if (l >= MAX_LOCACOES) {
    	system("cls");
    	marca(3);
    	printf("\t\t\tNúmero máximo de locações atingido\n\n");
    	printf("\t\t\t");
		system("pause");
		return;
	}
    while (sair == false) {
        while (valido == false) {
            system("cls");
            marca(3);
            printf("\t\t\t0 - Voltar para o menu\n\n");
            for (int i = 0; i < c; i++) {
                printf("\t\t\tID: %d - Nome: %s\n", clientes[i].id, clientes[i].nome);
            }
            printf("\n\t\t\tDigite o ID do cliente: ");
            scanf("%d", &idCliente);
            fflush(stdin);
            if (idCliente == 0) {
		    	system("cls");
		    	marca(3);
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
            if (valido == false) {
                system("cls");
                marca(3);
                printf("\t\t\tID inválido\n\n");
                printf("\t\t\t");
                system("pause");
            }
        }
        voltar = true;
        while (voltar == true) {	        		
        	valido = false;
        	while (valido == false) {
	            system("cls");
	            marca(3);
	            printf("\t\t\tClasse A - Luxuosos\n\n");
	            for (int i = 0; i < v; i++) {
	            	if (veiculos[i].classe == classes[0].tipo) {
	              		printf("\t\t\tID: %d - Placa: %s\n", veiculos[i].id, veiculos[i].placa);
					}
	            }
	            printf("\n\n\t\t\tClasse B - Intermediários\n\n");
	            for (int i = 0; i < v; i++) {
	            	if (veiculos[i].classe == classes[1].tipo) {
	              		printf("\t\t\tID: %d - Placa: %s\n", veiculos[i].id, veiculos[i].placa);
					}
	            }
	            printf("\n\n\t\t\tClasse C - Econômicos\n\n");
	            for (int i = 0; i < v; i++) {
	            	if (veiculos[i].classe == classes[2].tipo) {
	              		printf("\t\t\tID: %d - Placa: %s\n", veiculos[i].id, veiculos[i].placa);
					}
	            }
	            printf("\n\t\t\tDigite o ID do veículo: ");
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
				if (valido == false) {
	            	system("cls");
	            	marca(3);
	                printf("\t\t\tID inválido\n\n");
	                printf("\t\t\t");
	                system("pause");
				}
			}
			valido = false;
			while (valido == false) {
		        system("cls");
		    	conferirData(1, 3);
		    	locacoes[l].diaI = diaT;
		    	locacoes[l].mesI = mesT;
		    	locacoes[l].anoI = anoT;
		        dataTempI = calcularDias(locacoes[l].diaI, locacoes[l].mesI, locacoes[l].anoI);
		    	system("cls");
		    	conferirData(0, 3);
		    	locacoes[l].diaF = diaT;
		    	locacoes[l].mesF = mesT;
		    	locacoes[l].anoF = anoT;
		    	dataTempF = calcularDias(locacoes[l].diaF, locacoes[l].mesF, locacoes[l].anoF);
		    	system("cls");
		    	if (dataTempF <= dataTempI) {
		    		system("cls");
		    		marca(3);
	                printf("\t\t\tData inválida\n\n");
	                printf("\t\t\t");
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
				if (valido == false) {
					system("cls");
					marca(3);
	                printf("\t\t\tVeículo indisponível\n\n");
	                printf("\t\t\tDeseja escolher outro veículo? (s/n): ");
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
						marca(3);
						printf("\t\t\tEntrada inválida\n\n");
			        	printf("\t\t\t");
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
        while (valido == false) {
	        system("cls");
	        marca(3);
	        printf("\t\t\tA locação do veículo %s por %d dias custará no total R$%.2f", locacoes[l].placaVeiculo, locacoes[l].tempoLocacao, locacoes[l].valorTotal);
	        printf("\n\n\t\t\tConfirmar operação? (s/n): ");
	        scanf("%c", &sn);
	        fflush(stdin);
	        if (sn == 's' || sn == 'S') {
	        	system("cls");
	        	marca(3);
	        	printf("\t\t\tLocação realizada com sucesso\n\n");
	        	printf("\t\t\t");
	            system("pause");
	            sair = true;
	            valido = true;
	            l++;
	        } else if (sn == 'n' || sn == 'N') {
	        	valido = true;
	        	break;
			} else {
				system("cls");
				marca(3);
				printf("\t\t\tEntrada inválida\n\n");
	        	printf("\t\t\t");
	            system("pause");
			}
		}
		sair = true;
    }
	valido = false;
}

void exibirlocacao(int i) {
	printf("\t\t\t+---------------------------------------+\n");
    printf("\t\t\tID Locação: %d\n", locacoes[i].idLocacao);
    printf("\t\t\t-----------------------------------------\n");
    printf("\t\t\tCliente: %s\n", locacoes[i].cliente);
    printf("\t\t\t-----------------------------------------\n");
    printf("\t\t\tClasse Veículo: %c\n", locacoes[i].classeVeiculo);
    printf("\t\t\t-----------------------------------------\n");
    printf("\t\t\tPlaca Veículo: %s\n", locacoes[i].placaVeiculo);
    printf("\t\t\t-----------------------------------------\n");
    printf("\t\t\tData inicial da locação: %d/%d/%d\n", locacoes[i].diaI, locacoes[i].mesI, locacoes[i].anoI);
    printf("\t\t\t-----------------------------------------\n");
   	printf("\t\t\tData final da locação: %d/%d/%d\n", locacoes[i].diaF, locacoes[i].mesF, locacoes[i].anoF);
   	printf("\t\t\t-----------------------------------------\n");
   	printf("\t\t\tTotal de dias locado: %d\n", locacoes[i].tempoLocacao);
   	printf("\t\t\t-----------------------------------------\n");
    printf("\t\t\tValor Total: R$%.2f\n", locacoes[i].valorTotal);
    printf("\t\t\t+---------------------------------------+\n\n");
}

void listarLocacoes() {
	system("cls");
	if (l < 1) {
		system("cls");
		marca(4);
		printf("\t\t\tÉ necessário que haja ao menos uma locação para realizar a listagem\n\n");
		printf("\t\t\t");
		system("pause");
		return;
	}
	marca(4);
	for (int i = 0; i < l; i++) {
    	exibirlocacao(i);           		
	}
	printf("\t\t\t");
	system("pause");
}

void listarNome() {
	int idCliente;
	char nomeTemp[30];
	bool valido = false;
	
	if (l < 1) {
    	system("cls");
    	marca(5);
    	printf("\t\t\tÉ necessário que haja ao menos uma locação para realizar a listagem\n\n");
    	printf("\t\t\t");
    	system("pause");
    	return;
	}
	while (valido == false) {
        system("cls");
        marca(5);
        printf("\t\t\t0 - Voltar para o menu\n\n");
        for (int i = 0; i < c; i++) {
          	printf("\t\t\tID: %d - Cliente: %s\n", clientes[i].id, clientes[i].nome);
        } 
	    printf("\n\t\t\tDigite o ID do cliente: ");
	    scanf("%d", &idCliente);
	    fflush(stdin);
	    if (idCliente == 0){
	    	system("cls");
	    	marca(5);
	    	break;
		}
	    if (idCliente <= c && idCliente > 0) {
	    	valido = true;
	    	system("cls");
	    	marca(5);
	        for (int i = 0; i < l; i++) {
	            if (clientes[i].id == idCliente) {
	            	strcpy(nomeTemp, clientes[i].nome);
	            }
	        }
	    }
	    if (valido == true) {
	    	for (int i = 0; i < l; i++) {
	    		if (strcmp(nomeTemp, locacoes[i].cliente) == 0) {
	    			exibirlocacao(i);
				}
			}
			printf("\t\t\t");
			system("pause");
		} else if (valido == false){
			system("cls");
			marca(5);
			printf("\t\t\tCliente não cadastrado\n\n");
			printf("\t\t\t");
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
    	marca(6);
    	printf("\t\t\tÉ necessário que haja ao menos uma locação para realizar a listagem\n\n");
    	printf("\t\t\t");
    	system("pause");
    	return;
	}
    while (valido == false) {
        system("cls");
        marca(6);
        printf("\t\t\t0 - Voltar para o menu\n\n");
        for (int i = 0; i < v; i++) {
          	printf("\t\t\tID: %d - Placa: %s - Classe: %c\n", veiculos[i].id, veiculos[i].placa, veiculos[i].classe);
        } 
	    printf("\n\t\t\tDigite o ID do veículo: ");
	    scanf("%d", &idVeiculo);
	    fflush(stdin);
	    if (idVeiculo == 0){
	    	system("cls");
	    	marca(6);
	    	break;
		}
	    if (idVeiculo <= v && idVeiculo > 0) {
			valido = true;
	    	system("cls");
			marca(6);
	        for (int i = 0; i < l; i++) {
	            if (veiculos[i].id == idVeiculo) {
	            	strcpy(placaTemp, veiculos[i].placa);
	            }
	        }
	    }
	    if (valido == true) {
	    	for (int i = 0; i < l; i++) {
	    		if (strcmp(placaTemp, locacoes[i].placaVeiculo) == 0) {
	    			exibirlocacao(i);
				}
			}
			printf("\t\t\t");
			system("pause");
		} else if (valido == false){
			system("cls");
			marca(6);
			printf("\t\t\tVeículo não cadastrado\n\n");
			printf("\t\t\t");
			system("pause");		
		}
	}
}

void listarPeriodo() {
	int total, diaPi, mesPi, anoPi, diaPf, mesPf, anoPf, periodoI, periodoF, testeI, testeF;
	
	if (l < 1) {
    	system("cls");
    	marca(7);
    	printf("\t\t\tÉ necessário que haja ao menos uma locação para realizar a listagem\n\n");
    	printf("\t\t\t");
    	system("pause");
    	return;
	}	
	conferirData(1, 7);
	diaPi = diaT;
	mesPi = mesT;
	anoPi = anoT;
	periodoI = calcularDias(diaPi, mesPi, anoPi);
	conferirData(2, 7);
	diaPf = diaT;
	mesPf = mesT;
	anoPf = anoT;
	periodoF = calcularDias(diaPf, mesPf, anoPf);
	system("cls");
	marca(7);
	for (int i = 0; i < l; i++){
		testeI = calcularDias(locacoes[i].diaI, locacoes[i].mesI, locacoes[i].anoI);
		testeF = calcularDias(locacoes[i].diaF, locacoes[i].mesF, locacoes[i].anoF);
		if (testeI >= periodoI and testeF <= periodoF){
			exibirlocacao(i);
			total += locacoes[i].valorTotal;
		}		
	}
	printf("\t\t\tTotal de ganhos nesse período: R$ %d.00\n\n", total);
	printf("\t\t\t");
	system("pause");
}

void menu() {
	printf("\t\t\t+---------------------------------+\n");
	printf("\t\t\t 1 - Cadastrar cliente             \n");
	printf("\t\t\t+---------------------------------+\n");
	printf("\t\t\t 2 - Cadastrar veículo             \n");
	printf("\t\t\t+---------------------------------+\n");
	printf("\t\t\t 3 - Efetuar locação               \n");
	printf("\t\t\t+---------------------------------+\n");
	printf("\t\t\t 4 - Listar locações               \n");
	printf("\t\t\t+---------------------------------+\n");
	printf("\t\t\t 5 - Listar locações por cliente   \n");
	printf("\t\t\t+---------------------------------+\n");
	printf("\t\t\t 6 - Listar locações por veículo   \n");
	printf("\t\t\t+---------------------------------+\n");
	printf("\t\t\t 7 - Listar locações por período   \n");
	printf("\t\t\t+---------------------------------+\n");
	printf("\t\t\t 0 - Sair                          \n");
	printf("\t\t\t+---------------------------------+\n\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao;
    bool sair = false;

	criarArquivo();
	criarClasses();
    while (sair == false) {
    	lerCadastro();
        system("cls");
        marca(0);
        menu();
        printf("\t\t\tEscolha uma opção: ");
        scanf("%d", &opcao);
        fflush(stdin);
        switch (opcao) {
            case 1:
                cadastrarCliente();
                salvarCadastro();
                break;
            case 2:
                cadastrarVeiculo();
                salvarCadastro();
                break;
            case 3:
                efetuarLocacao();
                salvarCadastro();
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
			    marca(0);
			    printf("\t\t\tOpção inválida\n\n");
			    printf("\t\t\t");
			    system("pause");
                break;
        }
    }
}