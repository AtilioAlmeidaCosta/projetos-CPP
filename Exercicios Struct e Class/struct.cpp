#include <iostream>
#include <string>
#define CONTATOS 5
using namespace std;

class Data {
private:
    int dia;
    int mes;
    int ano;

public:
    Data(int d, int m, int a) : dia(d), mes(m), ano(a) {}

    int getDia() { return dia; }
    void setDia(int d) { dia = d; }
    int getMes() { return mes; }
    void setMes(int m) { mes = m; }
    int getAno() { return ano; }
    void setAno(int a) { ano = a; }
};

class Contato {
private:
    string email;
    string nome;
    string telefone;
    Data dtnasc;

public:
    Contato(string e, string n, string t, Data dt) : email(e), nome(n), telefone(t), dtnasc(dt) {}

    string getEmail() { return email; }
    void setEmail(string e) { email = e; }

    string getNome() { return nome; }
    void setNome(string n) { nome = n; }

    string getTelefone() { return telefone; }
    void setTelefone(string t) { telefone = t; }

    Data getDataNasc() { return dtnasc; }

    int idade() {
        int anoAtual = 2024;
        return anoAtual - dtnasc.getAno();
    }
};
void exibirContato(string email, string nome, string telefone, Data dataNasc, int idade){
    string dia = to_string(dataNasc.getDia());
    string mes = to_string(dataNasc.getMes());
    string ano = to_string(dataNasc.getAno());
    cout << endl;
    cout <<"|-----------------------------"<< endl;
    cout <<"| - email: "<<email<< endl;
    cout <<"| - nome: "<<nome<< endl;
    cout <<"| - telefone: "<<telefone<< endl;
    cout <<"| - dtnasc: "<<dia<<"/"<<mes<<"/"<<ano<< endl;
    cout <<"|----------------------------|"<< endl;
    cout <<"| + idade "<<idade<<" anos"<< endl;
    cout <<"------------------------------"<< endl;
    cout << endl;

}
int main() {
    
    string emails[CONTATOS];
    string nomes[CONTATOS];
    string telefones[CONTATOS];
    int diasNasc[CONTATOS];
    int mesesNasc[CONTATOS];
    int anosNasc[CONTATOS];

    for (int i = 0; i < CONTATOS; ++i) {
        cout << "Digite o email da pessoa " << i + 1 << ": ";
        cin >> emails[i];

        cout << "Digite o nome da pessoa " << i + 1 << ": ";
        cin >> nomes[i];

        cout << "Digite o telefone da pessoa " << i + 1 << ": ";
        cin >> telefones[i];

        cout << "Digite o dia de nascimento da pessoa " << i + 1 << ": ";
        cin >> diasNasc[i];

        cout << "Digite o mês de nascimento da pessoa " << i + 1 << ": ";
        cin >> mesesNasc[i];

        cout << "Digite o ano de nascimento da pessoa " << i + 1 << ": ";
        cin >> anosNasc[i];
    }    
    Data data1(diasNasc[0], mesesNasc[0], anosNasc[0]);
    Data data2(diasNasc[1], mesesNasc[1], anosNasc[1]);
    Data data3(diasNasc[2], mesesNasc[2], anosNasc[2]);
    Data data4(diasNasc[3], mesesNasc[3], anosNasc[3]);
    Data data5(diasNasc[4], mesesNasc[4], anosNasc[4]);

    Contato contato1(emails[0], nomes[0], telefones[0], data1);
    Contato contato2(emails[1], nomes[1], telefones[1], data2);
    Contato contato3(emails[2], nomes[2], telefones[2], data3);
    Contato contato4(emails[3], nomes[3], telefones[3], data4);
    Contato contato5(emails[4], nomes[4], telefones[4], data5);
    
    cout <<"------------------------------"<< endl;
    cout <<"| Contatos"<< endl;
    exibirContato(contato1.getEmail(),contato1.getNome(),contato1.getTelefone(),contato1.getDataNasc(),contato1.idade());
    exibirContato(contato2.getEmail(),contato2.getNome(),contato2.getTelefone(),contato2.getDataNasc(),contato2.idade());
    exibirContato(contato3.getEmail(),contato3.getNome(),contato3.getTelefone(),contato3.getDataNasc(),contato3.idade());
    exibirContato(contato4.getEmail(),contato4.getNome(),contato4.getTelefone(),contato4.getDataNasc(),contato4.idade());
    exibirContato(contato5.getEmail(),contato5.getNome(),contato5.getTelefone(),contato5.getDataNasc(),contato5.idade());

    return 0;
}
