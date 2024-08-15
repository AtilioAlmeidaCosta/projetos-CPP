#include <iostream>
#include <locale.h>
#include <string>

using namespace std;

struct No
{
    int dado;
    No *prox;
};

struct Fila
{
    No *ini;
    No *fim;
};

Fila* init()
{
    Fila *f = new Fila;
    f->ini = NULL;
    f->fim = NULL;

    return f;
}

int isEmpty(Fila *f)
{
    return (f->ini == NULL);
}

void geraSenha(Fila* f, int v)
{
    No *no = new No;
    no->dado = v;
    no->prox = NULL;
    if (isEmpty(f))
    {
        f->ini = no;
    }
    else
    {
        f->fim->prox = no;
    }

    f->fim = no;
}

float alteraSenha(Fila* f)
{
    float ret;
    if (isEmpty(f))
    {
        ret = -1;
    }
    else
    {
        No *no = f->ini;
        ret = no->dado;
        f->ini = no->prox;

        if (f->ini == NULL)
        {
            f->fim = NULL;
        }
        free(no);
    }
    return ret;
}

int count(Fila* f)
{
    int qtde = 0;
    No *no;
    no = f->ini;
    while (no != NULL)
    {
        qtde++;
        no = no->prox;
    }
    return qtde;
}

void print(Fila* f)
{
    No *no;
    no = f->ini;
    cout << "-- Qtde de elementos: " << count(f) << endl;

    while (no != NULL)
    {
        cout << no->dado << endl;
        no = no->prox;
    }
}

void freeFila(Fila* f) 
{
    No* no = f->ini;
    
    while (no != NULL) {
        No* temp = no->prox;
        free(no);
        no = temp;
    }
    free(f);
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "");

    Fila* senhasGeradas;
    Fila* senhasAtendidas;

    senhasGeradas = init();
    senhasAtendidas = init();

    int opcao;
    int senha = 0;

    do
    {

        if (senha > 0)
            cout << "Existem: " << count(senhasGeradas) << " senhas para serem atendidas" << endl;

        cout << "Escolha uma das opcões abaixo: " << endl;
        cout << "0. Sair." << endl;
        cout << "1. Gerar senha." << endl;
        cout << "2. Realizar atendimento." << endl;
        cin >> opcao;

        if (opcao == 0 && !isEmpty(senhasGeradas))
        {
            cout << "Existem senhas para serem atendidas. Finalize elas para sair" << endl;
            opcao = -1;
        }

        switch (opcao)
        {        
            case 0:
                break;

            case 1:
                senha++;
                geraSenha(senhasGeradas, senha);
                cout << "Sua senha: " << senha << endl;
                break;

            case 2:
                int senhaAtendida;
                senhaAtendida = alteraSenha(senhasGeradas);

                if (senhaAtendida <= 0)
                    cout << "Não existem senhas para atender." << endl;
                else
                {
                    geraSenha(senhasAtendidas, senhaAtendida);
                    cout << "Senha atendida: " << senhaAtendida << "\n" << endl;
                }
                break;

            default:
                cout << "ERRO!!! Tente novamente." << endl;
                break;
        }

    } while (opcao != 0);

    freeFila(senhasGeradas);
    freeFila(senhasAtendidas);

    return 0;
}