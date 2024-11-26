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