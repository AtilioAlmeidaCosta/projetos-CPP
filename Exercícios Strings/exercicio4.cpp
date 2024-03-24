#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

string formatarCitação(const string& nomeCompleto) {
    stringstream ss(nomeCompleto);
    vector<string> palavras;
    string palavra;
    
    while (ss >> palavra) {
        palavras.push_back(palavra);
    }
    
    if (palavras.size() >= 2) {

        string ultimoNome = palavras.back();
        transform(ultimoNome.begin(), ultimoNome.end(), ultimoNome.begin(), ::toupper);
        
        stringstream citação;
        citação << ultimoNome << ", ";
        
        for (size_t i = 0; i < palavras.size() - 1; ++i) {
            citação << palavras[i][0] << ". ";
        }
        
        return citação.str();
    } else {
        return nomeCompleto;
    }
}

int main() {

    string arquivoEntrada = "nomes.txt";
    string arquivoSaida = "citações_bibliográficas.txt";

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

        string citaçãoFormatada = formatarCitação(linha);
        saida << citaçãoFormatada << endl;

    }

    arquivo.close();
    saida.close();

    cout << "Citações bibliográficas geradas com sucesso. Verifique o arquivo '" << arquivoSaida << "'." << endl;

    return 0;
}
