#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct AristaStruct {
    int x, y, valor, id;
    AristaStruct(int _x, int _y, int _valor, int _id) {
        x = _x;
        y = _y;
        valor = _valor;
        id = _id;
    }
};

// Sacada del Campus
struct DSU {
    vector<int> rank, parent;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    DSU(){}
    int findSet(int node) {
        if (parent[node] != node) {
            parent[node] = findSet(parent[node]);
        }
        return parent[node];
    }
    
	void unionByRank(int u, int v) {
		int uRepresentative = findSet(u);
		int vRepresentative = findSet(v);
		if (uRepresentative == vRepresentative) return;
		if (rank[uRepresentative] < rank[vRepresentative]) {
			parent[uRepresentative] = vRepresentative;
		} else if(rank[uRepresentative] > rank[vRepresentative]) {
			parent[vRepresentative] = uRepresentative;
		} else {
			parent[vRepresentative] = uRepresentative;
			rank[uRepresentative]++;
		}
	}
};


int n;
int m;
vector<AristaStruct> aristas;
vector<string> respuestas;
vector<vector<int>> grafo;
vector<int> visitados;
vector<int> discovery;
vector<int> low;
int contador;
DSU dsu;
int tiempo;

bool sortArista (const AristaStruct &a, const AristaStruct &b){
    return (a.valor < b.valor);
}


void dfs(int x, int y = -1) {
    low[x] = discovery[x] = tiempo++;
    visitados[x] = contador + 1;
    for (int id : grafo[x]) {
        if (id != y){
            int h = dsu.findSet(aristas[id].x);
            int j = dsu.findSet(aristas[id].y);
            int to;
            if (h == x){
                to = j;
            }
            else{
                to = h;
            }
            if (visitados[to] <= contador) {
                dfs(to, id);
                low[x] = min(low[x], low[to]);
                
                if (low[to] > discovery[x]) {
                    respuestas[aristas[id].id] = "any";
                }
            } 
            else {
                low[x] = min(low[x], low[to]);
            }
        }
    }
}


int mismoValor (int i){
    int num = i;
    while (num < aristas.size() && aristas[num].valor == aristas[i].valor){
        num++;
    }
    return num;
}

void etiquetarAristas() {
    int i = 0;
    while (i < m) {
        int num = mismoValor(i);
        vector<int> componentes;
        for (int h = i; h < num; h++) {
            int x = dsu.findSet(aristas[h].x);
            int y = dsu.findSet(aristas[h].y);

            if (x == y) {
                respuestas[aristas[h].id] = "none";
            } else {
                grafo[x].push_back(h);
                grafo[y].push_back(h);
                componentes.push_back(x);
                componentes.push_back(y);
            }
        }
        for (int componente : componentes) {
            if (visitados[componente] <= contador) {
                dfs(componente);
            }
        }

        for (int h = i; h < num; h++) {
            int xComp = dsu.findSet(aristas[h].x);
            int yComp = dsu.findSet(aristas[h].y);
            dsu.unionByRank(xComp, yComp);
        }

        for (int componente : componentes) {
            grafo[componente].clear();
        }
        i = num;
        contador++;
    }
}



int main() {
    cin >> n >> m;
    respuestas.resize(m, "at least one");
    grafo.resize(n);
    visitados.resize(n);
    discovery.resize(n);
    low.resize(n);
    dsu = DSU(n);
    tiempo = 0;
    for (int id = 0; id < m; id++) {
        int x, y, valor;
        cin >> x >> y >> valor;
        aristas.push_back(AristaStruct(x-1, y-1, valor, id));
    }
    sort(aristas.begin(), aristas.end(), sortArista);
    etiquetarAristas();
    for (string respuesta : respuestas) {
        cout << respuesta << endl;
    }

    return 0;
}