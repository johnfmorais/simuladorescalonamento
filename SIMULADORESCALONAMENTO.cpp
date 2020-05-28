/*
� Esta fila pode ser uma fila preferencial, na qual o processo ser� executado assim que o processador for liberado,
ou uma fila comum, que � avaliada apenas quando a preferencial est� vazia.
� Para entrar em uma fila devem ser fornecidos o ID do processo (PID) e o seu nome, assim como a fila em que
ser� posicionado (preferencial ou comum).
� A execu��o de um processo causar� o envio do processo para o final da fila comum, independente da sua fila
de origem (uma simula��o de escalonamento)
� A finaliza��o de um processo excluir� o mesmo da fila ap�s a execu��o
� Uma listagem dos processos em cada fila deve ser impressa.



*/



#include<string.h>
#include<conio.h>
#include<windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct lista{
	int id;

	struct lista *prox;
};

struct lista_pref{
	int id;
	struct lista_pref *prox_p;
};

typedef struct lista Fila;
typedef struct lista_pref Fila_pref;

int main(){
	setlocale (LC_ALL, "Portuguese");
	Fila *novo, *inicio, *aux;
	Fila_pref *novo_p, *inicio_p, *aux_p;
	aux = inicio = NULL;
	aux_p = inicio_p = NULL;
	int cont=0;
	int op=0;
	while (op != 4){
		printf("ESCOLHA A PRIORIDADE DA FILA:\n [1] PREFERENCIAL\n [2] COMUM\n [3] LIBERAR PROCESSADOR\n [4] FINALIZAR\n");
		scanf("%i", &op);
	switch(op) {
       case 1: {
	   novo_p = (Fila_pref*)malloc(sizeof(Fila_pref));
	   printf("Digite o id: ");
	   scanf("%d", &novo_p->id);
	   novo_p->prox_p = NULL;
	   if (aux_p == NULL){
	   		inicio_p = novo_p;
			aux_p = novo_p;
		}
		else{
			while (aux_p->prox_p!=NULL){
				aux_p=aux_p->prox_p;
			}
				aux_p->prox_p = novo_p;
		}
		
			break;
		}
		case 2:{
		novo = (Fila*)malloc(sizeof(Fila));
		printf("Digite o id: ");
		scanf("%d", &novo->id);
		novo->prox = NULL;
			if (aux == NULL){
				inicio = novo;
				aux = novo;
			}
			else{
				while (aux->prox!=NULL){
					aux=aux->prox;
				}
				aux->prox = novo;
			}
			break;
		}
		case 3:{
			printf("-------------------------------PROCESSADOR LIBERADO!-------------------------------\n");
			printf("Avaliando lista preferencial...\n");
			
			if(inicio_p == NULL){
				printf("LISTA VAZIA!\n");
				printf("Avaliando lista comum...\n");
			}else {
				while (inicio_p != NULL){
					printf("***********************************************************************************\n");
					printf("PRIORIDADE = PREFERENCIAL\n");	
					printf("PROCESSO EM EXECU��O = %d\n", inicio_p);
					printf("ID DO PROCESSO = %d\n", inicio_p->id);
					printf("PR�XIMO REGISTRO = %d\n", inicio_p->prox_p);
					printf("----------------------------PROCESSO %d FINALIZADO!----------------------------\n\n", inicio_p);
					inicio_p = inicio_p->prox_p;
					
				}
			}
			
			printf("Avaliando lista comum...\n");
			
			if(inicio == NULL){
				printf("LISTA VAZIA!\n");
				printf("-----------------N�O EXISTEM PROCESSOS PARA SEREM EXECUTADOS-------------------\n");
				}else{
					while (inicio != NULL){
						
						printf("***********************************************************************************\n");
						printf("PRIORIDADE = COMUM\n");
						printf("PROCESSO EM EXECU��O = %d\n", inicio);
						printf("ID DO PROCESSO = %d\n", inicio->id);
						printf("PR�XIMO REGISTRO = %d\n", inicio->prox);
						printf("----------------------------PROCESSO %d FINALIZADO!----------------------------\n\n", inicio);
						printf("-----------------TODOS OS PROCESSOS FORAM FINALIZADOS COM SUCESSO!-------------------\n");
						
						inicio = inicio->prox;	

				}
			}
				break;	
				}

		case 4:{
			printf("Fim da execu��o!");
			break;
		}
	}
}
}



