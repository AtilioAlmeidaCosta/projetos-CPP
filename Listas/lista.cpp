#include <iostream>
#include <locale.h>
#include <string>

using namespace std;

struct Funcionario {
    int prontuario;
    string nome;
    double salario;
};

struct Lista {
    Funcionario funcionario;
    Lista* prox;
};

Lista* init() {
    return NULL;
}

bool isEmpty(Lista* lista) {
    return (lista == NULL);
}

bool pesquisarFuncionario(Lista* lista, int prontuario) {
    Lista* aux = lista;
    while (aux != NULL && aux->funcionario.prontuario != prontuario) {
        aux = aux->prox;
    }
    if (aux != NULL) {
        cout << " " <<endl;
        cout << "---------------" << endl;
        cout << "O funcionário foi encontrado, aqui estão seus dados: " << endl;
        cout << "Prontuário: " << aux->funcionario.prontuario << endl;
        cout << "Nome: " << aux->funcionario.nome << endl;
        cout << "Salário: " << aux->funcionario.salario << endl;
        cout << "---------------" << endl;
        return true;
    }
    return false;
}

Lista* cadastrarFuncionario(Lista* lista) {
    int prontuario;
    cout << "Cadastrar um novo funcionário:" << endl;
    cout << "Digite o prontuário do novo funcionário: ";
    cin >> prontuario;

    if (pesquisarFuncionario(lista, prontuario)) {
        cout << "Já existe um funcionário com o mesmo prontuário cadastrado!" << endl;
        return lista;
    }

    string nome;
    double salario;
    cout << "Digite o nome do novo funcionário: ";
    cin.ignore();
    getline(cin, nome);
    cout << "Digite o salário do novo funcionário: ";
    cin >> salario;

    Funcionario f = { prontuario, nome, salario };
    Lista* novo = new Lista();
    novo->funcionario = f;
    novo->prox = lista;
    cout << "O novo funcionário foi cadastrado com sucesso!" << endl;
    return novo;
}

Lista* deletarFuncionario(Lista* lista, int prontuario) {
    Lista* aux = lista;
    Lista* ant = NULL;

    while (aux != NULL && aux->funcionario.prontuario != prontuario) {
        ant = aux;
        aux = aux->prox;
    }

    if (aux == NULL) {
        cout << "O funcionário desejado não foi localizado!" << endl;
        cout << "Tente novamente" << endl;
        return lista;
    }

    if (ant == NULL) {
        lista = aux->prox;
    } else {
        ant->prox = aux->prox;
    }
    delete aux;
    cout << "O funcionário "<< aux->funcionario.nome <<" foi deletado com sucesso!" << endl;

    return lista;
}

void listarFuncionarios(Lista* lista) {
    Lista* aux = lista;
    int qtd = 1;
    double totalSalarios = 0.0;

    cout << "Essa é a lista de todos os funcionários:" << endl;
    while (aux != NULL) {
        cout << qtd << " Funcionário:" << endl;
        cout << "Prontuário: " << aux->funcionario.prontuario << endl;
        cout << "Nome: " << aux->funcionario.nome << endl;
        cout << "Salário: " << aux->funcionario.salario << endl;
        cout << "--------------------------" << endl;
        totalSalarios += aux->funcionario.salario;
        aux = aux->prox;
        qtd++;
    }
    cout << "Soma total dos salários dos funcionários: " << totalSalarios << endl;
}

void limparLista(Lista* lista) {
    Lista* aux = lista;
    while (aux != NULL) {
        Lista* ant = aux->prox;
        delete aux;
        aux = ant;
    }
}

int main() {
    setlocale(LC_ALL, "");

    Lista* listaFuncionarios = init();
    int escolha=1;
    int prontuario;
     while (escolha != 0) {
        cout << " " << endl;
        cout << "0. Sair" << endl;
        cout << "1. Incluir Funcionário" << endl;
        cout << "2. Excluir Funcionário" << endl;
        cout << "3. Pesquisar Funcionário" << endl;
        cout << "4. Listar Funcionários" << endl;
        cout << "Escolha das opções acima: ";
        cin >> escolha;

        switch (escolha) {
            case 0:
                cout << "Finalizando o programa..." << endl;
                break;
            case 1:
                listaFuncionarios = cadastrarFuncionario(listaFuncionarios);
                break;
            case 2:
                cout << "Digite o prontuário do funcionário a ser excluído: ";
                cin >> prontuario;
                listaFuncionarios = deletarFuncionario(listaFuncionarios, prontuario);
                break;
            case 3:
                cout << "Digite o prontuário do funcionário a ser pesquisado: ";
                cin >> prontuario;
                if (!pesquisarFuncionario(listaFuncionarios, prontuario)) {
                    cout << "O funcionário não está cadastrado no sistema!" << endl;
                }
                break;
            case 4:
                listarFuncionarios(listaFuncionarios);
                break;
            default:
                cout << "ERRO!!! Escolha uma opção válida." << endl;
                break;
        }
    }

    limparLista(listaFuncionarios);
    return 0;
}
