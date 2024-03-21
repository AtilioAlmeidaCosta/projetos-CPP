#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <random>
using namespace std;

#define BARALHO 2
#define NAIPE 4
#define CARTA_NAIPE 13
#define CARTA_MAO_JOGADOR 11
#define JOGADOR 4

// Indices para a exibição das cartas
const string nomes_cartas[] = {"Ás", "Dois", "Três", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove", "Dez", "Valete", "Dama", "Rei"};
const string nomes_naipes[] = {"Copas", "Paus", "Ouro", "Espada"};

using cartas = string[BARALHO][NAIPE][CARTA_NAIPE];
using maoJogador = string[JOGADOR][CARTA_MAO_JOGADOR];

// Função para embaralhar o baralho
void embaralhar(cartas &baralho) {
    vector<string> todas_cartas;
    for (int b = 0; b < BARALHO; ++b) {
        for (int n = 0; n < NAIPE; ++n) {
            for (int c = 0; c < CARTA_NAIPE; ++c) {
                string bar = to_string(b + 1);
                string naipe = to_string(n + 1); 
                string carta = to_string(c + 1);
                todas_cartas.push_back(bar + "-" + naipe + "-" + carta);
            }
        }
    }

    // Embaralha as cartas vetor de cartas e distribui as cartas embaralhadas para o baralho
    random_device rd;
    mt19937 g(rd());
    shuffle(todas_cartas.begin(), todas_cartas.end(), g);
    int carta_atual = 0;
    for (int b = 0; b < BARALHO; ++b) {
        for (int n = 0; n < NAIPE; ++n) {
            for (int c = 0; c < CARTA_NAIPE; ++c) {
                baralho[b][n][c] = todas_cartas[carta_atual];
                carta_atual++;
            }
        }
    }
}

// traduz o código da carta para o nome da carta
string traduzir_carta(const string& codigo_carta) {
    int b = stoi(codigo_carta.substr(0, 1)) - 1; 
    int n = stoi(codigo_carta.substr(2, 1)) - 1;
    int c = stoi(codigo_carta.substr(4)) - 1;

    string nome_carta = nomes_cartas[c];
    string nome_naipe = nomes_naipes[n];

    return nome_carta + " de " + nome_naipe + " do baralho " + to_string(b + 1);
}

int main(int argc, char** argv) {
    cartas baralho{};
    maoJogador jogador{};

    // Embaralha o baralho
    embaralhar(baralho);

    // Distribui as cartas para os jogadores
    int carta_atual = 0;
    for (int j = 0; j < JOGADOR; ++j) {
        for (int c = 0; c < CARTA_MAO_JOGADOR; ++c) {
            jogador[j][c] = baralho[carta_atual / (NAIPE * CARTA_NAIPE)][(carta_atual / CARTA_NAIPE) % NAIPE][carta_atual % CARTA_NAIPE];
            carta_atual++;
        }
    }

    // Apresenta as mãos de cada jogador
    for (int j = 0; j < JOGADOR; ++j) {
        cout << "Mão do jogador " << j + 1 << ":" << endl;
        for (int c = 0; c < CARTA_MAO_JOGADOR; ++c) {
            cout << traduzir_carta(jogador[j][c]) << endl;
        }
        cout << endl;
    }

    return 0;
}
