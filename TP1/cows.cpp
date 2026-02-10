#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int vacas;

bool entran(vector<int> posiciones, int minimaDist){
    int ultimaPosicion = posiciones[0];
    int contador = 1;
    for (int i = 1; i < N; i++){
        if (posiciones[i] - ultimaPosicion >= minimaDist){
            contador++;
            ultimaPosicion = posiciones[i];
            if (contador == vacas){
                return true;
            }
        }
    }
    return false;
}


int f (vector<int> posiciones){
    int res;
    int menor = posiciones[0];
    int mayor = posiciones[N-1];
    while (menor <= mayor){
        int mitad = (menor + mayor) / 2;
        if (entran(posiciones,mitad)){
            menor = mitad + 1;
            res = mitad;
        }
        else{
            mayor = mitad - 1;
        }
    }
    return res;
}


int main (){
    int T;
    cin >> T;
    for (int i=0; i<T; i++){
        cin >> N;
        cin >> vacas;
        vector<int> listaPosiciones(N);
        for (int j = 0; j < N; j++){
            cin >> listaPosiciones[j];
        }
        sort(listaPosiciones.begin(),listaPosiciones.end());
        int result = f (listaPosiciones);
        cout << result << endl;
    }
    return 0;
}