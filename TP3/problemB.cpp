#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 1e9;

struct Arista {
    int x, y, capacidad, flujo;
};

vector<Arista> aristas;
vector<vector<int>> grafo;
vector<vector<int>> capacidad;
vector<int> a;
vector<int> b;
vector<int> nivel;
vector<int> ptr;
int n;
int m;
int totalA;
int totalB;
vector<vector<int>> resultado;



bool bfs(int s, int t) {
    fill(nivel.begin(), nivel.end(), -1);
    nivel[s] = 0;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int nodo = q.front();
        q.pop();

        for (int id : grafo[nodo]) {
            const auto& arista = aristas[id];
            if (arista.flujo < arista.capacidad && nivel[arista.y] == -1) {
                nivel[arista.y] = nivel[nodo] + 1;
                q.push(arista.y);
            }
        }
    }
    return nivel[t] != -1;
}

int dfs(int nodo, int t, int flujo) {
    if (flujo == 0){
        return 0;
    }
    if (nodo == t){
        return flujo;
    }
    for (int& cid = ptr[nodo]; cid < grafo[nodo].size(); ++cid) {
        int id = grafo[nodo][cid];
        auto& arista = aristas[id];
        if (nivel[arista.y] != nivel[nodo] + 1){
            continue;
        } 
        int flujoEmpujado = dfs(arista.y, t, min(flujo, arista.capacidad - arista.flujo));
        if (flujoEmpujado > 0) {
            arista.flujo += flujoEmpujado;
            aristas[id ^ 1].flujo -= flujoEmpujado;
            return flujoEmpujado;
        }
    }

    return 0;
}


int flujoMaximo(int fuente, int sumidero) {
    int flujoTotal = 0;
    while (bfs(fuente, sumidero)) {
        fill(ptr.begin(), ptr.end(), 0);
        while (int flujoEmpujado = dfs(fuente, sumidero, INF)) {
            flujoTotal += flujoEmpujado;
        }
    }

    return flujoTotal;
}

int main() {
    while (cin >> n >> m) {
        totalA = totalB = 0;
        aristas.clear();
        grafo.assign(2 * n + 2, vector<int>());
        nivel.assign(2 * n + 2, -1);
        ptr.assign(2 * n + 2, 0);
        a.resize(n + 1, 0);
        b.resize(n + 1, 0);
        capacidad.assign(2 * n + 2, vector<int>(2 * n + 2, 0));
        resultado.assign(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            totalA += a[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
            totalB += b[i];
        }

        for (int i = 1; i <= n; ++i) {
            capacidad[i][i] = INF;
        }

        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            capacidad[u][v] = capacidad[v][u] = INF;
        }

        if (totalA != totalB) {
            cout << "NO" << endl;
            continue;
        }

        int s = 0;
        int t = 2 * n + 1;

        for (int i = 1; i <= n; ++i) {
            aristas.push_back({s, i, a[i], 0});
            aristas.push_back({i, s, 0, 0});
            grafo[s].push_back(aristas.size() - 2);
            grafo[i].push_back(aristas.size() - 1);
            aristas.push_back({n+i, t, b[i] , 0});
            aristas.push_back({t, n+i, 0, 0});
            grafo[n+i].push_back(aristas.size() - 2);
            grafo[t].push_back(aristas.size() - 1);
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                aristas.push_back({i, n+j, capacidad[i][j], 0});
                aristas.push_back({n+j, i, 0, 0});
                grafo[i].push_back(aristas.size() - 2);
                grafo[n+j].push_back(aristas.size() - 1);
            }
        }
        if (flujoMaximo(s, t) == totalA) {
            cout << "YES" << endl;
            for (int i = 1; i <= n; ++i) {
                for (int id : grafo[i]) {
                    const auto& arista = aristas[id];
                    if (arista.x == i && arista.y > n && arista.y <= 2 * n) {
                        resultado[i][arista.y - n] = arista.flujo;
                    }
                }
            }
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    cout << resultado[i][j];
                    if (j == n) {
                        cout << endl;
                    } else {
                        cout << " ";
                    }
                }
            }
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
