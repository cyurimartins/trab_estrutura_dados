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
    int quant;
    float preco;
    Produto *prox;
};


int menu(){
    int opcao;

    cout<<"\n\nEscolha uma opcao do menu: \n\n";
    cout<<"\n 1 - Incluir";
    cout<<"\n 2 - Excluir";
    cout<<"\n 3 - Alterar";
    cout<<"\n 4 - Consultar cadastros";
    cout<<"\n 5 - Voltar ao menu anterior\n\n";

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

    Cliente *inicio=NULL, *tmp, *valor, *consulta;
    Produto *inicioPro=NULL, *tmpPro, *valorPro, *consultaprod;
    int codCli = 1, codProd = 1;
    int opcao, opcao2,teste;

    opcao2 = menu_princ();

    while (1){
    //CLIENTE
    if (opcao2 ==1){
    opcao = menu(); // CHAMANDO MENU 2

    //INSERIR CLIENTE
    if (opcao == 1){
        Cliente *novo;
        novo = new Cliente;

        novo->cod = codCli;
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

             codCli++;

    }//fim if

    //EXCLUIR CLIENTE
    if (opcao == 2){
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



        // CONSULTAR CADASTROS
		if (opcao == 4){
            consulta = inicio;
            while (consulta != NULL) {
                cout<<"\nCodigo: "<<consulta->cod;
                cout<<"\nNome: "<<consulta->nome<<endl;
                consulta = consulta->prox;
            }

        } // fim if

        if (opcao == 5){
        	menu_princ();
		}
	} // fim if

	if (opcao2 == 2){
		// PRODUTO
        opcao = menu();
        // incluir cadastro de produto
        if (opcao == 1){
            Produto *novo;
            novo = new Produto;

            novo->cod = codProd;
            cout<<"Digite o nome: ";
            cin>>novo->nome;
            cout<<"Digite quantidade: ";
            cin>>novo->quant;
            cout<<"Digite preco: ";
            cin>>novo->preco;

            tmpPro = novo;
            tmpPro->prox = NULL;

            if (inicioPro == NULL){
            inicioPro = tmpPro;
            valorPro = inicioPro;
        }
        else {
            valorPro->prox = tmpPro;
            valorPro = tmpPro;
             }

             codProd++;

    }//fim if

    // excluir cadastros de produtos

    if (opcao == 2){
        Produto *anterior, *atual;
        if (inicioPro == NULL){
            cout<<"Lista vazia"<<endl;
        }
        else{
            int num;
            cout<<"Digite o codigo que deseja excluir: ";
            cin>>num;
            anterior = inicioPro;
            atual = inicioPro;

        if(inicioPro->cod == num){
            atual = atual->prox;
            inicioPro = atual;
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

    // alterar cadastros de produto
    if (opcao == 3) {
    	Produto *atual;
        if (inicioPro == NULL){
            cout<<"Lista vazia"<<endl;
        }
        else{
        int num;
        cout<<"Digite o codigo que deseja alterar: ";
        cin>>num;
        atual = inicioPro;
        if(inicioPro->cod == num){
        				cout<<"\nDigite o novo nome: ";
        				cin>>atual->nome;
        				cout<<"\nDigite o preço: ";
        				cin>>atual->preco;
        				cout<<"\nDigite a quantidade: ";
        				cin>>atual->quant;
                    } // fim if
        else {
        while (1){
                if (atual->cod == num){
        				cout<<"\nDigite o novo nome: ";
        				cin>>atual->nome;
        				cout<<"\nDigite o preco: ";
        				cin>>atual->preco;
        				cout<<"\nDigite a quantidade: ";
        				cin>>atual->quant;
                        break;
                } //fim if
                else {
                    atual = atual->prox;
                    } //fim else

        } //fim while
        } // fim else

    } //fim else
	} //fim if

    // Consultar Cadastros
    if (opcao == 4){
            consultaprod = inicioPro;
            while (consultaprod != NULL){
                cout<<"\n\nCodigo: "<<consultaprod->cod;
                cout<<"\nNome: "<<consultaprod->nome;
                cout<<"\nQuantidade: "<<consultaprod->quant;
                cout<<"\nPreco: "<<consultaprod->preco;

                consultaprod = consultaprod->prox;
            }
    }

    if (opcao == 5){
            menu_princ();
		}

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
