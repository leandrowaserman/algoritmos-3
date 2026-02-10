#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int INF = 1e9;
int N;
vector<int> dijkInicio;
vector<int> dijkFinal;
vector<vector<pair<int,int>>> grafo;
vector<tuple<int, int, int>> aristas;

vector<int> dijkstra(int inicio) {
    vector<int> distancias(N,INF);
    vector<bool> visitados(N, false);
    distancias[inicio] = 0;
    for (int i = 0; i < N; ++i) {
        int u = -1;
        for (int j = 0; j < N; ++j) {
            if (!visitados[j] && (u == -1 || distancias[j] < distancias[u])) {
                u = j;
            }
        }
        if (distancias[u] == INF){
            break;
        }
        visitados[u] = true;
        for (auto& arista : grafo[u]) {
            int v = arista.first;
            int w = arista.second;
            if (distancias[u] + w < distancias[v]) {
                distancias[v] = distancias[u] + w;
            }
        }
    }
    return distancias;
}

int main() {
    int m;
    cin >> N >> m;
    int res = 0;
    grafo.resize(N);
    dijkInicio.resize(N);
    dijkFinal.resize(N);
    for (int i = 0; i < m; ++i) {
        int x, y, costo;
        cin >> x >> y >> costo;
        grafo[x].push_back({y, costo});
        grafo[y].push_back({x, costo});
        aristas.push_back({x, y, costo});
    }
    dijkInicio = dijkstra(0);
    dijkFinal = dijkstra(N-1);
    if(dijkFinal[0] != dijkInicio[N-1]){
        return 0;
    }
    int caminoMinimo = dijkFinal[0];
    for (auto [x, y, costo] : aristas) {
        if (dijkInicio[x] + costo + dijkFinal[y] == caminoMinimo ||
            dijkInicio[y] + costo + dijkFinal[x] == caminoMinimo) {
            res += 2 * costo;
        }
    }
    cout << res << endl;
    return 0;
}