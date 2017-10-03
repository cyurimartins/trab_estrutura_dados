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
}TLista;

/* Prototipando funcoes */
int menu();
int menu2();

void inicializaLista(TLista *lista);
int inserirElemento(TLista *lista);
void excluirElemento(TLista *lista);
void consultarElementos(TLista *lista);

int inserirProduto(TLista *lista);


int main(){
    int opcao;
    int opc;
    TLista l1;

    inicializaLista(&l1);

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

            //produto
            case 2:
                opc = menu2();

                //inserir produto
                if (opc == 1){
                    inserirProduto(&l1);
                }
                if (opc == 2){
                    excluirElemento(&l1);
                }
                if (opc == 3){
                    //alterar produto
                }
                if (opc == 4){
                    consultarElementos(&l1);
                }
                if (opc == 5){
                    menu();
                }

            //vender
            case 3:
                break;
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
    cout<<"\n 4 - Consultar";
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
                    if (atual == lista->fim){
                        lista->fim = anterior;
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

// inserir produto na lista

int inserirProduto(TLista *lista){
    system("cls");
    TElemento *novo;
    novo = new TElemento;

    cout << "Inserir codigo do produto: ";
    cin >> novo->cod;
    cout << "Informe o nome do produto: ";
    cin >> novo->nome;
    cout << "Preco do produto: ";
    cin >> novo->preco;

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
