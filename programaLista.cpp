#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

using namespace std;

typedef struct Elemento{
    string nome;
    int cod;
    float preco;
    struct Elemento *prox;
}TElemento;

typedef struct Lista{
    TElemento *inicio;
    TElemento *fim;
    TElemento *prox;
}TLista;

typedef struct Lista2{
    TElemento *inicio;
    TElemento *fim;
}TLista2;

/* Prototipando funcoes */
int menu();
int menu2();

void inicializaLista(TLista *lista);
int inserirElemento(TLista *lista);
void excluirElemento(TLista *lista);
void consultarElementos(TLista *lista);

void inicializaProduto(TLista2 *lista2);
int inserirProduto(TLista2 *lista2);
void excluirProduto(TLista2 *lista2);
void consultarProduto(TLista2 *lista2);

int VenderProduto(TLista2 *lista2);

int main(){
    int opcao;
    int opc;
    TLista l1;
    TLista2 l2;

    inicializaLista(&l1);
    inicializaProduto(&l2);

    do {

    //chamando menu
    opcao = menu();

        switch (opcao){
            //cliente      
            
            case 1: 
				opc = menu2();            

                //inserir cliente
                if (opc == 1){
                    inserirElemento(&l1);                	
                	break;
                }
                //exluir cliente
                if (opc == 2){
                    excluirElemento(&l1);
                }
                //alterar cliente
                if (opc == 3){
                    //alterar elemento
                }
                //consultar cliente
                if (opc == 4){
                    consultarElementos(&l1);
                }
                //voltar ao menu anterior
                if (opc == 5){
                    menu();
                }
            break;

            //produto
            case 2: 
				opc = menu2();            

                //inserir produto
                if (opc == 1){
                    inserirProduto(&l2);
                }
                if (opc == 2){
                    excluirProduto(&l2);
                }
                if (opc == 3){
                    //alterar produto
                }
                if (opc == 4){
                    consultarProduto(&l2);
                }
                if (opc == 5){
                    menu();
                }
            break;

            //vender
            case 3:
            	VenderProduto(&l2);                
            //calcular total
            case 4:
                break;
        };
    }while(opcao!=0);

    return 0;
}

int menu(){
    int opcao;

    cout<<"Escolha uma opcao do menu: \n\n";
    cout<<"\n 1 - Cliente";
    cout<<"\n 2 - Produto";
    cout<<"\n 3 - Vender";
    cout<<"\n 4 - Calcular Total";
    cout<<"\n 0 - Fechar Programa\n\n";

    cin>>opcao;

    return opcao;
}

int menu2(){
    int opcao;

    cout<<"Escolha uma opcao do menu: \n\n";
    cout<<"\n 1 - Incluir";
    cout<<"\n 2 - Excluir";
    cout<<"\n 3 - Alterar";
    cout<<"\n 4 - Listar";
    cout<<"\n 5 - Voltar ao menu anterior\n\n";

    cin>>opcao;

    return opcao;
}

/* Inicializar Lista */

void inicializaLista(TLista *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
}

/* inserir Elemento na lista */

int inserirElemento(TLista *lista){
    system("cls");
    TElemento *novo;
    novo = new TElemento;

    cout << "Inserir codigo: ";
    cin >>novo->cod;
    cout << "Informe o nome: ";
    cin >>novo->nome;

    system("cls");
    novo->prox = NULL;

    if (lista->inicio == NULL){
        lista->inicio = novo;
        lista->fim = novo;
    }else{
        lista->fim->prox = novo; //encadeamento da lista
        lista->fim = novo;
    }
}

/* Excluir elemento da lista */

void excluirElemento(TLista *lista){
    system("cls");
    int valor;
    TElemento *anterior, *atual;

    cout << "Informe elemento a ser excluido: ";
    cin >> valor;

    if (lista->inicio == NULL){
        cout << "Lista Vazia!\n\n";
    }else{
        anterior = lista->inicio;
        atual = lista->inicio;
        while (atual!= NULL){
            if (atual->cod == valor){
                if (atual == lista->inicio){
                    lista->inicio = lista->inicio->prox;
                    free(atual);
                    break;
                }
                else{
                    if (atual == lista->prox){
                        lista->prox = anterior;
                    }

                    //refazendo o encadeamento
                    anterior->prox = atual->prox;
                    free(atual);
                    break;
                }
            }
            else{
                anterior = atual;
                atual = atual->prox;
            }
        }//fim while
    }
}

/* Consultar Lista */

void consultarElementos(TLista *lista){
    system("cls");
    TElemento *aux;
    aux = lista->inicio;

    if (aux == NULL){
        cout << "\n\nLista Vazia";
    }
    else{
        while (aux != NULL){
            cout <<"Cod: "<<aux->cod<<endl;
            cout <<"Nome: "<<aux->nome<<endl;

            aux = aux->prox;
        }
    }
}

/* LISTA 2 */ 

// iNICIALIZAR LISTA2

void inicializaProduto(TLista2 *lista2){
    lista2->inicio = NULL;
    lista2->fim = NULL;
}

/* inserir Elemento na lista2 */

int inserirProduto(TLista2 *lista2){
    system("cls");
    TElemento *novo;
    novo = new TElemento;

    cout << "Inserir codigo: ";
    cin >>novo->cod;
    cout << "Informe o nome: ";
    cin >>novo->nome;
    cout << "Informe o Preco: ";
    cin >>novo->preco;

    system("cls");
    novo->prox = NULL;
    
    if (lista2->inicio == NULL){
        lista2->inicio = novo;
        lista2->fim = novo;
    }else{
        lista2->fim->prox = novo; //encadeamento da lista
        lista2->fim = novo;
    }
}

/* Excluir elemento da lista2 */

void excluirProduto(TLista2 *lista2){
    system("cls");
    int valor;
    TElemento *anterior, *atual;

    cout << "Informe elemento a ser excluido: ";
    cin >> valor;

    if (lista2->inicio == NULL){
        cout << "Lista Vazia!\n\n";
    }else{
        anterior = lista2->inicio;
        atual = lista2->inicio;
        while (atual!= NULL){
            if (atual->cod == valor){
                if (atual == lista2->inicio){
                    lista2->inicio = lista2->inicio->prox;
                    free(atual);
                    break;
                }
                else{
                    if (atual == lista2->fim){
                        lista2->fim = anterior;
                    }

                    //refazendo o encadeamento
                    anterior->prox = atual->prox;
                    free(atual);
                    break;
                }
            }
            else{
                anterior = atual;
                atual = atual->prox;
            }
        }//fim while
    }
}

/* Consultar Lista2 */

void consultarProduto(TLista2 *lista2){
    system("cls");
    TElemento *aux;
    aux = lista2->inicio;

    if (aux == NULL){
        cout << "\n\nLista Vazia";
    }
    else{
        while (aux != NULL){
            cout <<"Cod: "<<aux->cod<<endl;
            cout <<"Nome: "<<aux->nome<<endl;

            aux = aux->prox;
        }
    }
}


/* VENDER */ 
int VenderProduto(TLista2 *lista2){
	int cod, quant, valorT;
	
	cout << "Informe o codigo do cliente: ";
	cin>>cod;
	
	cout << "O client e: X?";
	
	cout << "Informe o codigo do produto: ";
	cin>>cod;
	
	cout << "Nome do procuto: X"; 
	
	cout <<"Quantidade ?";
	cin >> quant;
	
	//valorT = quant * novo->preco;
	
	return valorT;
	
}
