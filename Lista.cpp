#include <iostream>
using namespace std;

struct listafixa{
    int elementos[50];
    int tamanho;
};
void criarlista(listafixa& lista){
    lista.tamanho = 0;
}
void printar(const listafixa& lista){
    cout << "Lista: ";
    for (int i = 0; i < lista.tamanho; i++){
        cout << lista.elementos[i] << " ";
    }
    cout << endl;
}
void inserir(listafixa& lista, int valor){
    if (lista.tamanho >=50){
        cout << "Lista cheia!" << endl;
        return;
    }
    int posicao = 0;
    while (posicao < lista.tamanho && lista.elementos[posicao] < valor){
        posicao++;
    }

    for (int i = lista.tamanho; i > posicao; i--){
        lista.elementos[i] = lista.elementos[i - 1];
    }

    lista.elementos[posicao] = valor;
    lista.tamanho++;

    printar(lista);
    cout << "Espaço preenchido:" << lista.tamanho << "/50" << endl;
}

void remover(listafixa& lista, int index){
    if (index < 0 || index >= lista.tamanho){
        cout << "indice fora de alcance!" << endl;
        return;
    }
    for (int i = index; i < lista.tamanho - 1; i++){
        lista.elementos[i] = lista.elementos[i+1];
    }
    lista.tamanho--;
    printar(lista);
    cout << "Espaço utilizado: " << lista.tamanho << "/50" << endl;
}

int main(){
    listafixa lista;
    criarlista(lista);

    int opcao, valor, index;
    do{
        cout << "\nMenu:\n";
        cout << "1 - Inserir elemento\n";
        cout << "2 - Remover elemento por índice\n";
        cout << "3 - Encerrar\n";
        cin >> opcao;

        switch(opcao){
            case 1:
                cout << "Digite um valor a ser inserido: ";
                cin >> valor;
                inserir(lista, valor);
                break;

            case 2:
                cout << "Digite o índice do elemento: ";
                cin >> index;
                remover(lista, index);
                break;
            case 3:
                cout << "Encerrando...\n";
                break;
              
        }
    }while (opcao != 3);
    return 0;
}