#include <iostream>
#include <locale.h>

using namespace std;

#define QTD 30

struct No
{   
    float dado;
    struct No *prox;
};

struct Pilha
{
    No *topo;
};

Pilha* init()
{
    Pilha* p = new Pilha;
    p->topo = NULL;
    return p;
}

int isEmpty(Pilha* p)
{
    return (p->topo == NULL);
}

int count(Pilha *p)
{
    int i = 0;
    No *no;
    no = p->topo;
    while (no != NULL)
    {
        i++;
        no = no->prox;
    }
    return i;
}

void print(Pilha* p)
{
    No* no;
    no = p->topo;
    cout << "Qtde de elementos: " << count(p) << endl;
    while (no != NULL) 
    {
        cout << no->dado << endl;
        no = no->prox;
    }
    cout << "--------------------" << endl;
}

void freePilha(Pilha* p) 
{
    No* no;
    no = p->topo;
    while (no != NULL) 
    {
        No* aux = no->prox;
        free(no);
        no = aux;
    }
    free(p);
}

void push(Pilha* p, float v)
{
    No *no = new No;
    no->dado = v;
    no->prox = p->topo;
    p->topo = no;
}

float pop(Pilha* p)
{
    float v;
    int podeDesempilhar = (p->topo != NULL);
    if (podeDesempilhar)
    {
        No *no = p->topo;
        v = no->dado; 
        p->topo = no->prox;
        free(no);
    }
    else
    {
        v = -1;
    }

    return v;
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "");

    Pilha *pilhaFloat = new Pilha();
    pilhaFloat = init();

    Pilha *pilhaPar = new Pilha();
    pilhaPar = init();

    Pilha *pilhaImpar = new Pilha();
    pilhaImpar = init();

    cout << "Pilha vazia: " << (isEmpty(pilhaFloat) ? "SIM" : "NÃO") << endl;
    
    cout << "\n";

    cout << "Digite 30 valores para preencher a lista"<<endl;
    cout << "O novo valor deve ser maior que o anterior." << endl;
    int aux, valor = 0;
    
    for (int i = 0; i < QTD; i++)
    {
        cin >> valor;
        while (valor < aux)
        {
            cout << "O valor digitado é menor que o anterior. Digite novamente" << endl;
            cin >> valor;
        }

        push(pilhaFloat, valor);
        aux = valor;
        valor = 0;
    }
    
    cout << "" << endl;
    cout << "Pilha preenchida: " << endl;
    print(pilhaFloat);

    for (int j = 0; j < QTD; j++)
    {
        float aux2 = pop(pilhaFloat);
        if ((int)aux2 % 2 == 0)
            push(pilhaPar, aux2);
        else
            push(pilhaImpar, aux2);
    }

   cout << "" << endl;

    cout << "Pilha par: " << endl;
    print(pilhaPar);
    cout << "" endl;
    cout << "Pilha ímpar: " << endl;
    print(pilhaImpar);
    freePilha(pilhaFloat);
    freePilha(pilhaPar);
    freePilha(pilhaImpar);
    return 0;
}
