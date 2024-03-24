#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

string formatarNome(const string& nomeCompleto) {
    stringstream ss(nomeCompleto);
    vector<string> palavras;
    string palavra;
    
    while (ss >> palavra) {
        palavras.push_back(palavra);
    }
    
    if (palavras.size() >= 2) {
        string ultimoNome = palavras.back();
        palavras.pop_back();
        string primeiroNome = palavras.front();
        
        stringstream nomeFormatado;
        nomeFormatado << ultimoNome << ", ";
        for (size_t i = 0; i < palavras.size(); ++i) {
            nomeFormatado << palavras[i] << " ";
        }
        nomeFormatado << primeiroNome;
        
        return nomeFormatado.str();
    } else {
        return nomeCompleto;
    }
}

int main() {
    string arquivoEntrada = "nomes.txt";
    string arquivoSaida = "nomes_formatados.txt";

    ifstream arquivo(arquivoEntrada);
    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo de entrada." << endl;
        return 1;
    }

    ofstream saida(arquivoSaida);
    if (!saida) {
        cerr << "Erro ao criar o arquivo de saída." << endl;
        return 1;
    }

    string linha;
    while (getline(arquivo, linha)) {
        string nomeFormatado = formatarNome(linha);
        saida << nomeFormatado << endl;
    }

    arquivo.close();
    saida.close();

    cout << "Nomes formatados com sucesso. Verifique o arquivo '" << arquivoSaida << "'." << endl;

    return 0;
}
