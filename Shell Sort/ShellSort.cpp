#include <iostream>
#include <locale.h>

using namespace std;

struct Array {
    int* elementos;
    int tamanho;
};

Array initArray(int tamanho) {
    Array arr;
    arr.elementos = new int[tamanho];
    arr.tamanho = tamanho;
    return arr;
}

void freeArray(Array& arr) {
    delete[] arr.elementos;
}

void printArray(const Array& arr) {
    for (int i = 0; i < arr.tamanho; i++) {
        cout << arr.elementos[i] << " ";
    }
    cout << endl;
}

void mostraTroca(int a, int b) {
    cout << "Trocando " << a << " com " << b << endl;
}


void shellSort(Array& arr) {
    int h = 1;
    while (h <= arr.tamanho / 3) {
        h = 3 * h + 1; 
    }

   
    while (h > 0) {
        for (int i = h; i < arr.tamanho; i++) {
            int temp = arr.elementos[i];
            int j = i;
            while (j >= h && arr.elementos[j - h] > temp) {
                mostraTroca(arr.elementos[j], arr.elementos[j - h]);
                arr.elementos[j] = arr.elementos[j - h];
                j -= h;
            }
            arr.elementos[j] = temp;
        }

        printArray(arr);

        h /= 3;
    }
}

int main() {
    setlocale(LC_ALL, "");

    Array arr = initArray(10);
    arr.elementos[0] = 3;
    arr.elementos[1] = 0;
    arr.elementos[2] = 1;
    arr.elementos[3] = 8;
    arr.elementos[4] = 7;
    arr.elementos[5] = 2;
    arr.elementos[6] = 5;
    arr.elementos[7] = 4;
    arr.elementos[8] = 9;
    arr.elementos[9] = 6;

    cout << "Array original: ";
    printArray(arr);
    shellSort(arr);
    cout << "Array ordenado: ";
    printArray(arr);
    freeArray(arr);

    return 0;
}
