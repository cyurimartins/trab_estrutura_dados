#include <iostream>
#include <stdlib.h>

using namespace std;

struct Cliente{
    int cod;
    string nome;
    Cliente *prox;
};

struct Produto{
    int cod;
    string nome;
    Produto *prox;
};


int menu(){
    int opcao;

    cout<<"Escolha uma opcao do menu: \n\n";
    cout<<"\n 1 - Incluir";
    cout<<"\n 2 - Excluir";
    cout<<"\n 3 - Alterar";
    cout<<"\n 4 - Consultar";
    cout<<"\n 5 - Listar cadastros";
    cout<<"\n 6 - Voltar ao menu anterior\n\n";

    cin>>opcao;

    return opcao;
}

int menu_princ(){
    int opcao2;

    cout<<"Escolha uma opcao do menu: \n\n";
    cout<<"\n 1 - Cliente";
    cout<<"\n 2 - Produto";
    cout<<"\n 3 - Vender";
    cout<<"\n 4 - Calcular total de vendas";
    cout<<"\n 5 - Sair \n\n";

    cin>>opcao2;

    return opcao2;
}



int main(){

    Cliente *inicio=NULL, *tmp, *valor;
    int opcao, opcao2,teste;

    opcao2 = menu_princ();

    while (1){

    //CLIENTE
    if (opcao2 ==1){
    system("cls");
    opcao = menu();

    //INSERIR CLIENTE
    if (opcao == 1){
        system("cls");
        Cliente *novo;
        novo = new Cliente;
        cout<<"Digite o codigo: ";
        cin>>novo->cod;
        cout<<"Digite o nome: ";
        cin>>novo->nome;
        tmp = novo;
        tmp->prox = NULL;

        if (inicio == NULL){
            inicio = tmp;
            valor = inicio;
        }

        else {
            valor->prox = tmp;
            valor = tmp;
             }
    }//fim if

    //EXCLUIR CLIENTE
    if (opcao == 2){
        system("cls");
        Cliente *anterior, *atual;
        if (inicio == NULL){
            cout<<"Lista vazia"<<endl;
        }
        else{
            int num;
            cout<<"Digite o codigo que deseja excluir: ";
            cin>>num;
            anterior = inicio;
            atual = inicio;

        if(inicio->cod == num){
            atual = atual->prox;
            inicio = atual;
        } // fim if
        else {
        while (1){
            if (atual->cod == num){
                anterior->prox = atual->prox;
                break;
            } //fim if
            else {
                anterior = atual;
                atual = atual->prox;
            } //fim else

        } //fim while
        } // fim else

    } //fim else
    } //fim if

    // ALTERAR CLIENTE
    if (opcao == 3) {
        Cliente *atual;
        if (inicio == NULL){
            cout<<"Lista vazia"<<endl;
        }
        else{
            int num;
            cout<<"Digite o codigo que deseja alterar: ";
            cin>>num;
            atual = inicio;
            if(inicio->cod == num){
                cout<<"Digite o novo nome: ";
                cin>>atual->nome;
                inicio = atual;
            } // fim if
        else{
        while (1){
            if (atual->cod == num){
                cout<<"Digite o novo nome: ";
                cin>>atual->nome;
                break;
            } //fim if
            else{
                atual = atual->prox;
            } //fim else

        } //fim while
        } // fim else

        } //fim else
	} //fim if

	//CONSULTAR CLIENTE
	if (opcao == 4){
		Cliente *atual;
        if (inicio == NULL){
            cout<<"Lista vazia"<<endl;
        }
        else{
            int num;
            cout<<"Digite o codigo que deseja consultar: ";
            cin>>num;
            atual = inicio;
            if(inicio->cod == num){
                cout<<"\n"<<inicio->nome<<endl;
            } // fim if
        else {
        while (1){
            if (atual->cod == num){
                cout<<"\n"<<atual->nome<<endl;
                break;
            } //fim if
            else{
                atual = atual->prox;
            } //fim else

        } //fim while
        } // fim else

    } //fim else
	} // fim if
		if (opcao == 5){
            valor = inicio;
            while (valor != NULL) {
                cout<<"\nCodigo: "<<valor->cod<<endl;
                cout<<"\nNome: "<<valor->nome<<endl;
                valor = valor->prox;
            }
        } // fim if
        if (opcao == 6){
        	menu_princ();
		}
	} // fim if

	if (opcao2 == 2){
		// PRODUTO
	}

	if (opcao2 == 3){
		// VENDER
	}

	if (opcao2 == 4){
		//CALCULAR TOTAL
	}

	if (opcao2 == 5){
		break;
	}
} //fim while


    return 0;
} //fim main
