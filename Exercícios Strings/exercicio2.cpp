#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void removeEspacos(string& str) {
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
}

bool verificaPalindromo(const string& str) {
    string strSemEspacos = str;
    removeEspacos(strSemEspacos);

    string strReversa = strSemEspacos;
    reverse(strReversa.begin(), strReversa.end()); 

    return strSemEspacos == strReversa;
}

int main() {
    string mensagem;
    cout << "Digite a mensagem: ";
    getline(cin, mensagem);

    if (verificaPalindromo(mensagem)) {
        cout << "A mensagem e um palindromo." << endl;
    } else {
        cout << "A mensagem nao e um palindromo." << endl;
    }

    return 0;
}
