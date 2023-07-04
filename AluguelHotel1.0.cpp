#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

int c = 0, q = 0, r = 0, diaT = 0, mesT = 0, anoT = 0;

struct cliente {
    int id;
    int alugado;
    char nome[50];
    char cpf[15];
} clientes[10];

struct quarto {
    int id;
    int alugado;
    char cama[10];
    char classe[15];
    float preco;
} quartos[10];

struct reserva {
    int id;
    int idQuarto;
    char nome[50];
    char cpf[15];
    char classe[15];
    char cama[10];
    int diaI;
    int mesI;
    int anoI;
    int diaF;
    int mesF;
    int anoF;
	int tempo;
    float total; 
} reservas[10];

void cadastrarCliente() {
    bool valido;
    int cont;
    char cpf[15], cpfT[15];
    char n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11;

    while (!valido) {
        valido = false;
        while (!valido) {
            system("cls");
            fflush(stdin);
            printf("Nome do cliente: ");
            scanf("%s", &clientes[c].nome);
            fflush(stdin);
            for (int i = 0; i < 50; i++) {
                if (isdigit(clientes[c].nome[i]) > 0) {
                    system("cls");
                    printf("Nome inválido\n\n");
                    system("pause");
                    break;
                }
                if (i == 49) {
                    valido = true;
                }
            }
        }
        valido = false;
        while (!valido) {
            system("cls");
            fflush(stdin);
            printf("CPF do cliente (xxx.xxx.xxx-xx): ");
            scanf("%c%c%c.%c%c%c.%c%c%c-%c%c", &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9, &n10, &n11);
            fflush(stdin);
            cpfT[0] = n1, cpfT[1] = n2, cpfT[2] = n3, cpfT[3] = n4, cpfT[4] = n5, cpfT[5] = n6, cpfT[6] = n7, cpfT[7] = n8, cpfT[8] = n9, cpfT[9] = n10, cpfT[10] = n11;
            for (int i = 0; i < 11; i++) {
                if (isdigit(cpfT[i]) == 0) {
                    system("cls");
                    printf("CPF inváldo\n\n");
                    system("Pause");
                    break;
                }
                if (i == 10) {
                    cpf[0] = n1, cpf[1] = n2, cpf[2] = n3, cpf[4] = n4, cpf[5] = n5, cpf[6] = n6, cpf[8] = n7, cpf[9] = n8, cpf[10] = n9, cpf[12] = n10, cpf[13] = n11;
                    cpf[3] = '.', cpf[7] = '.', cpf[11] = '-';
                    cont = 0;
                    if (c > 0) {
                        for (int i = 0; i < c; i++) {
                            if (strcmp(cpf, clientes[i].cpf) == 0) {
                                system("cls");
                                printf("CPF já cadastrado\n\n");
                                system("pause");
                                break;
                            } else {
                                cont++;
                            }
                        } 
                    }
                    if (cont == c) {
                        clientes[c].id = c + 1;
                        strcpy(clientes[c].cpf, cpf);
                        c++;
                        valido = true;
                    }
                }
            }
        }
    }
}

void cadastrarQuarto() {
    int categ, tipo;
    bool valido = false;

    quartos[q].id = q + 1;
    while (!valido) {
        system("cls");
        printf("Quarto nº %d\n\n", quartos[q].id);
        printf("1 - Categoria econômico\nCama\nTelevisão\n\n");
        printf("2 - Categoria intermediário\nCama\nTelevisão\nFrigobar\n\n");
        printf("3 - Categoria luxuoso\nCama\nTelevisão\nBanheiro\nFrigobar\n\n");
        printf("Defina a categoria do novo quarto: ");
        scanf("%d", &categ);
        fflush(stdin);
        if (categ == 1) {
            strcpy(quartos[q].classe, "Econômico");
            quartos[q].preco = 100.00;
            valido = true;
        } else if (categ == 2){
            strcpy(quartos[q].classe, "Intermediário");
            quartos[q].preco = 200.00;
            valido = true;
        } else if (categ == 3){
            strcpy(quartos[q].classe, "Luxuoso");
            quartos[q].preco = 300.00;
            valido = true;
        } else {
            system("cls");
            printf("Entrada inválida\n\n");
            system("pause");
        }
    }
    valido = false;
    while (!valido) {
        system("cls");
        printf("1- Cama Simples\n2- Cama Casal\n\n");
        printf("Tipo de cama: ");
        scanf("%d", &tipo);
        fflush(stdin);
        if (tipo == 1) {
        	strcpy(quartos[q].cama, "Simples");
        	q++;
        	valido = true;
		} else if (tipo == 2) {
			strcpy(quartos[q].cama, "Casal");
        	quartos[q].preco += 50.00;
        	q++;
        	valido = true;
		} else {
			system("cls");
            printf("Entrada inválida\n\n");
            system("pause");
		}
    }
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

void reservarQuarto() {
	int idCliente, idQuarto, dataTempI, dataTempF, dataTesteI, dataTesteF, contar, validar;
    char sn;
    bool valido = false, sair = false, voltar = true;
    
    system("cls");
	if (c < 1 or q < 1) {
		system("cls");
		printf("É necessário que haja ao menos um cliente e um quarto para realizar a reserva\n\n");
		system("pause");
		return;
	}
	while (!sair) {
		valido = false;
        while (!valido) {
            system("cls");
            for (int i = 0; i < c; i++) {
                printf("ID: %d - Nome: %s\nCPF: %s\n\n", clientes[i].id, clientes[i].nome, clientes[i].cpf);
            }
            printf("\nDigite o ID do cliente: ");
            scanf("%d", &idCliente);
            fflush(stdin);
            if (idCliente <= c && idCliente > 0) {
                for (int i = 0; i < c; i++) {
                    if (clientes[i].id == idCliente) {
                    	clientes[i].alugado++;
                    	strcpy(reservas[r].nome, clientes[i].nome);
                    	strcpy(reservas[r].cpf, clientes[i].cpf);
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
	            printf("Quartos Econômicos\n\n");
	            for (int i = 0; i < q; i++) {
	            	if (strcmp(quartos[i].classe, "Econômico") == 0) {
	              		printf("ID: %d - Quarto %s\n", quartos[i].id, quartos[i].cama);
					}
	            }
	            printf("\n\nQuartos Intermediários\n\n");
	            for (int i = 0; i < q; i++) {
	            	if (strcmp(quartos[i].classe, "Intermediário") == 0) {
	              		printf("ID: %d - Quarto %s\n", quartos[i].id, quartos[i].cama);
					}
	            }
	            printf("\n\nQuartos Luxuosos\n\n");
	            for (int i = 0; i < q; i++) {
	            	if (strcmp(quartos[i].classe, "Luxuoso") == 0) {
	              		printf("ID: %d - Suíte %s\n", quartos[i].id, quartos[i].cama);
					}
	            }
	            printf("\n\nDigite o ID do quarto: ");
	            scanf("%d", &idQuarto);
	            fflush(stdin);
	            if (idQuarto <= q && idQuarto > 0) {
	                for (int i = 0; i < q; i++) {
	                	fflush(stdin);
	                    if (quartos[i].id == idQuarto) {
	                    	reservas[r].idQuarto = idQuarto;
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
		    	reservas[r].diaI = diaT;
		    	reservas[r].mesI = mesT;
		    	reservas[r].anoI = anoT;
		        dataTempI = calcularDias(reservas[r].diaI, reservas[r].mesI, reservas[r].anoI);
		    	system("cls");
		    	conferirData(0);
		    	reservas[r].diaF = diaT;
		    	reservas[r].mesF = mesT;
		    	reservas[r].anoF = anoT;
		    	dataTempF = calcularDias(reservas[r].diaF, reservas[r].mesF, reservas[r].anoF);
		    	system("cls");
		    	if (dataTempF <= dataTempI) {
		    		system("cls");
	                printf("Data inválida\n\n");
	                system("pause");
	                break;
				}
	    		if (r == 0) {
	    			valido = true;
	    			voltar = false;
	    			break;
	    		}
	    		contar = 0;
	    		validar = 0;
				for (int i = 0; i < r; i++) {
			    	if (idQuarto == reservas[i].idQuarto) {
			    		contar++;
		    			dataTesteI = calcularDias(reservas[i].diaI, reservas[i].mesI, reservas[i].anoI);
		    			dataTesteF = calcularDias(reservas[i].diaF, reservas[i].mesF, reservas[i].anoF);
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
				valido = false;
				if (!valido) {
					system("cls");
	                printf("Quarto indisponível\n\n");
	                printf("Deseja escolher outro quarto? (s/n): ");
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
		for (int i = 0; i < q; i++) {
			if (idQuarto == quartos[i].id) {
				quartos[i].alugado++;	
            	reservas[r].id = r+1;
            	strcpy(reservas[r].classe, quartos[i].classe);
            	strcpy(reservas[r].cama, quartos[i].cama);
            	reservas[r].tempo = dataTempF - dataTempI;
            	if (strcmp(reservas[r].classe, "Ecomômico") == 0) {
                	reservas[r].total = reservas[r].tempo*quartos[i].preco;
				} else if (strcmp(reservas[r].classe, "Intermediário") == 0) {
					reservas[r].total = reservas[r].tempo*quartos[i].preco;
				} else {
					reservas[r].total = reservas[r].tempo*quartos[i].preco;
				}
			}
		}
		valido = false;
        while (!valido) {
	        system("cls");
	        printf("A reserva do quarto nº%d - %s (%s) - por %d dias custará no total R$%.2f", idQuarto, reservas[r].classe, reservas[r].cama, reservas[r].tempo, reservas[r].total);
	        printf("\n\nConfirmar operação? (s/n): ");
	        scanf("%c", &sn);
	        fflush(stdin);
	        if (sn == 's' || sn == 'S') {
	        	system("cls");
	        	printf("Reserva realizada com sucesso\n\n");
	            system("pause");
	            sair = true;
	            valido = true;
	            r++;
	        } else if (sn == 'n' || sn == 'N') {
	        	valido = true;
	        	break;
			} else {
				system("cls");
				printf("Entrada inválida\n\n");
	            system("pause");
			}
		}
    }
}

void listarClientes() {
	system("cls");
	if (c < 1) {
		system("cls");
		printf("É necessário que haja ao menos um cliente para realizar a listagem\n\n");
		system("pause");
		return;
	}
	for (int i = 0; i < c; i++) {
        printf("ID: %d - Nome: %s\nCPF: %s\nReservas em Aberto: %d\n\n", clientes[i].id, clientes[i].nome, clientes[i].cpf, clientes[i].alugado);
    }
    system("pause");
}

void listarQuartos() {
	system("cls");
	if (q < 1) {
		system("cls");
		printf("É necessário que haja ao menos um quarto para realizar a listagem\n\n");
		system("pause");
		return;
	}
    printf("Quartos Econômicos\n\n");
    for (int i = 0; i < q; i++) {
    	if (strcmp(quartos[i].classe, "Econômico") == 0) {
      		printf("ID: %d - Quarto %s\nReservas em Aberto: %d\n", quartos[i].id, quartos[i].cama, quartos[i].alugado);
		}
    }
    printf("\nQuartos Intermediários\n\n");
    for (int i = 0; i < q; i++) {
    	if (strcmp(quartos[i].classe, "Intermediário") == 0) {
      		printf("ID: %d - Quarto %s\nReservas em Aberto: %d\n", quartos[i].id, quartos[i].cama, quartos[i].alugado);
		}
    }
    printf("\nQuartos Luxuosos\n\n");
    for (int i = 0; i < q; i++) {
    	if (strcmp(quartos[i].classe, "Luxuoso") == 0) {
      		printf("ID: %d - Quarto %s\nReservas em Aberto: %d\n", quartos[i].id, quartos[i].cama, quartos[i].alugado);
		}
    }
    printf("\n\n");
    system("pause");
}

void exibirReservas(int i) {
	printf("+---------------------------------------+\n");
    printf("ID Reserva: %d\n", reservas[i].id);
    printf("-----------------------------------------\n");
    printf("Cliente: %s\n", reservas[i].nome);
    printf("-----------------------------------------\n");
    printf("CPF: %s\n", reservas[i].cpf);
    printf("-----------------------------------------\n");
    printf("Classe: %s\n", reservas[i].classe);
    printf("-----------------------------------------\n");
    printf("Quarto Nº %d - Tipo: %s\n", reservas[i].idQuarto, reservas[i].cama);
    printf("-----------------------------------------\n");
    printf("Data inicial da reserva: %d/%d/%d\n", reservas[i].diaI, reservas[i].mesI, reservas[i].anoI);
    printf("-----------------------------------------\n");
   	printf("Data final da reserva: %d/%d/%d\n", reservas[i].diaF, reservas[i].mesF, reservas[i].anoF);
   	printf("-----------------------------------------\n");
   	printf("Total de dias reservado: %d\n", reservas[i].tempo);
   	printf("-----------------------------------------\n");
    printf("Valor Total: R$%.2f\n", reservas[i].total);
    printf("+---------------------------------------+\n\n");
}

void listarReservas() {
	system("cls");
	if (r < 1) {
		system("cls");
		printf("É necessário que haja ao menos uma reserva para realizar a listagem\n\n");
		system("pause");
		return;
	}
	for (int i = 0; i < r; i++) {
    	exibirReservas(i);           		
	}
	system("pause");
}

void listarPeriodo() {
	int diaPi, mesPi, anoPi, diaPf, mesPf, anoPf, periodoI, periodoF, testeI, testeF;
	float total;
	
	if (r < 1) {
    	system("cls");
    	printf("É necessário que haja ao menos uma reserva para realizar a listagem\n\n");
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
	for (int i = 0; i < r; i++){
		testeI = calcularDias(reservas[i].diaI, reservas[i].mesI, reservas[i].anoI);
		testeF = calcularDias(reservas[i].diaF, reservas[i].mesF, reservas[i].anoF);
		if (testeI >= periodoI and testeF <= periodoF){
			exibirReservas(i);
			total += reservas[i].total;
		}		
	}
	printf("Total de ganhos nesse período: R$ %.2f\n\n", total);
	system("pause");
}

void menu() {
	printf("+---------------------------------+\n");
	printf(" 1 - Cadastrar cliente             \n");
	printf("+---------------------------------+\n");
	printf(" 2 - Adiconar quarto               \n");
	printf("+---------------------------------+\n");
	printf(" 3 - Efetuar reserva               \n");
	printf("+---------------------------------+\n");
	printf(" 4 - Listar clientes               \n");
	printf("+---------------------------------+\n");
	printf(" 5 - Listar quartos                \n");
	printf("+---------------------------------+\n");
	printf(" 6 - Listar todas as reservas      \n");
	printf("+---------------------------------+\n");
	printf(" 7 - Listar reservas por período   \n");
	printf("+---------------------------------+\n");
	printf(" 0 - Sair                          \n");
	printf("+---------------------------------+\n\n");
}

int main () {
    setlocale(LC_ALL, "Portuguese");
    int op;
    bool sair;

    while (!sair) {
        system("cls");
        menu();
        fflush(stdin);
        printf("Escolha uma opção: ");
        scanf("%d", &op);
        switch (op) {
        case 1:
            cadastrarCliente();
            break;
        case 2:
            cadastrarQuarto();
            break;
        case 3:
            reservarQuarto();
            break;
        case 4:
            listarClientes();
            break;
        case 5:
            listarQuartos();
            break;
        case 6:
            listarReservas();
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