#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<vector<int>> grafo;
int INF = 1e9;

vector<int> dijkstra() {
    vector<int> energias(N + 1, INF);
    energias[1] = 0;
    queue<int> fila;
    fila.push(1);
    while (!fila.empty()){
        int actual = fila.front();
        fila.pop();
        for (int v : grafo[actual]){
            if (energias[v] > energias[actual] + 1) {
                energias[v] = energias[actual] + 1;
                fila.push(v);
            }
        }
    }
    return energias;
}

int main() {
    cin >> N;
    grafo.resize(N+1);
    for (int i = 1; i <= N; i++) {
        int atajo;
        cin >> atajo;
        if (i < N){
            grafo[i].push_back(i+1);
        }
        if (i>1){
            grafo[i].push_back(i-1);
        }
        grafo[i].push_back(atajo);
    }
    vector<int> listaEnergias = dijkstra();
    for (int i = 1; i <= N; ++i) {
        cout << listaEnergias[i] << " ";
    }
    cout << endl;
    return 0;
}
