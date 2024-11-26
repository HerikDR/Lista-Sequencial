#include <iostream>
#include <cstdlib>
using namespace std;

struct listadinamica{
    int* elementos;
    int tamanho;
    int capacidade;
};
void imprimir(const listadinamica& lista);
void iniciar(listadinamica& lista, int capacidadeinicial){
    lista.elementos = (int*)malloc(capacidadeinicial * sizeof(int));
    lista.tamanho = 0;
    lista.capacidade = capacidadeinicial;
}
void deletarlista(listadinamica& lista){
    free(lista.elementos);
    lista.tamanho = 0;
    lista.capacidade = 0;
}
void alterartamanho(listadinamica& lista, int novacapacidade){
    lista.elementos = (int*)realloc(lista.elementos, novacapacidade * sizeof(int));
    if (!lista.elementos){
        cout << "Não foi possível alterar o tamanho da lista, tente novamente!" << endl;
    }
}
void inserir(listadinamica& lista, int valor){
    if(lista.tamanho == lista.capacidade){
        cout << "A lista foi totalmente preenchida, duplicando seu tamanho..." << endl;
        alterartamanho(lista, lista.capacidade * 2);
    }
    int posicao = 0;
    while (posicao < lista.tamanho && lista.elementos[posicao] < valor){
        posicao++;
    }
    for (int i = lista.tamanho; i > posicao; i--){
        lista.elementos[i] = lista.elementos[i-1];
    }
    lista.elementos[posicao] = valor;
    lista.tamanho++;
    imprimir(lista);
    cout << "Tamanho utilizado: " << lista.tamanho << "/" << lista.capacidade << endl;
}
void remover(listadinamica& lista, int index){
    if (index < 0 || index >= lista.tamanho){
        cout << "Índice fora de alcance!" << endl;
        return;
    }
    for (int i = index; i < lista.tamanho - 1; i++){
        lista.elementos[i] = lista.elementos[i+1];
    }
    lista.tamanho--;
    if (lista.tamanho < lista.capacidade / 4 && lista.capacidade > 50){
        cout << "25% da capacidade da lista está ocupada. Reduzindo seu tamanho pela metade..." << endl;
        alterartamanho(lista, lista.capacidade / 2);
    }
    imprimir(lista);
    cout << "Tamanho utilizado: " << lista.tamanho << "/" << lista.capacidade << endl;
}

void imprimir(const listadinamica& lista){
    cout << "Lista: ";
    for (int i = 0; i < lista.tamanho; i++){
        cout << lista.elementos[i] << " ";
    }
    cout << endl;
}
int main(){
    listadinamica lista;
    iniciar(lista, 50);
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
        
    } while (opcao != 3);
    deletarlista(lista);
    return 0;
}