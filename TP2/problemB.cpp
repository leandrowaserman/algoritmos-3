#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> grafo;
int N;

vector<int> bfs (int vertInicial){
    vector<int> distancia;
    distancia.assign(N+1, -1);
    queue<int> fila;
    distancia[vertInicial] = 0;
    fila.push(vertInicial);
    while (!fila.empty()){
        int u = fila.front();
        fila.pop();
        for (int v : grafo[u]){
            if(distancia[v] == -1){
                distancia[v] = distancia[u] + 1;
                fila.push(v);
            }
        }
    }
    return distancia;
}

long long verticesPosibles (int verInicial) {
    vector<int> distancias = bfs(verInicial);
    int pares = 0;
    int impares = 0;
    for (int i = 1; i <= N; i++){
        if (distancias[i] % 2 == 0){
            pares++;
        }
        else{
            impares++;
        }
    }
    long long posibles = (long long) pares * impares;
    return posibles;
}

int main() {
    cin >> N;
    grafo.resize(N + 1);

    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }
    
    long long posibles = verticesPosibles(1);
    long long result = posibles - (N - 1);
    
    cout << result << endl;

    return 0;
}
