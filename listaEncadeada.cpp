#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


/*

Software: Programa de lista encadeada
Author: Yuri Martins 

*/ 

typedef struct No{
	int conteudo;
	struct No *prox;
	struct No *inicio;
}*Lista;

int tam;
Lista lista = NULL;
Lista *inicio = NULL;

void inicia (No *list){
	list->prox = NULL;
	tam = 0;
}

int vazia (No *list){
	if (list->prox == NULL)
		return 1;
	else
		return 0;		
}

No *aloca(){
	No *novo;
	novo = new No;
	if (!novo){
		cout << "Sem memória disponivel\n";		
	}else {
		cout << "Novo elemento: ";
		cin >> novo->conteudo;
		return novo;
	}
}

void inserirFim(No *list){
	No *novo = aloca();
	novo->prox = NULL;
	
	if (vazia(list)){
		list->prox = novo;
	} else{
		No *tmp = list->prox;
		
		while(tmp->prox != NULL)
			tmp = tmp->prox;
			tmp->prox = novo;
		
	}
	tam++;
}

void exibirLista(No *list){
	if(vazia(list)){
		cout<<"Lista vazia!\n";
		return;
	}
	
	No *tmp;
	tmp = list->prox;
	cout<<"\n\nLista: \n\n";
	while(tmp != NULL){
		cout<<tmp->conteudo;
		tmp = tmp->prox;
	}
}



void inserirInicio(No *list){
	No *novo = aloca();
	No *oldHead = list->prox;
	
	list->prox = novo;
	novo->prox = oldHead;
	
	tam++;
}

void imprimir(Lista listaTemp){
	while (listaTemp != NULL){
		cout <<listaTemp->conteudo<<endl;
		listaTemp = listaTemp->prox;
	}
}



int menu(void){
	int opt;
	cout << "\n\n***************************\n"<<endl;
	cout << "PROGRAMA DE LISTA ENCADEADA"<<endl;
	cout << "Escolha uma opcao abaixo: \n"<<endl;
	cout << "[1] - INCLUIR CLIENTE"<<endl;
	cout << "[2] - LISTAR  CLIENTE"<<endl;
	cout << "[0] - SAIR DO PROGRAMA"<<endl;
	cin >> opt;
	
	return opt;	
}

void opcao(No *list, int op){
	No *tmp;
	
	switch(op){
		case 0:
			break;
		
		case 1:
			inserirFim(list);
			break;
			
		case 2:
			exibirLista(list);
			break;
	}
}

int main() {
	
	No *list;
	list = new No;
	
	if(!list){
		cout << "Sem memoria disponivel!\n";		
	}else{
		inicia(list);
		int opt;
	do{		
		opt = menu();
		opcao(list, opt);
	}while(opt);
	}	
	

	return 0;
}
