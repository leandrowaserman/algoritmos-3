#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int INF = 1e9;
int n;
vector<vector<int>> distancias;
vector<int> orden;
vector<long long> result;


void floydWarshall() {
    vector<bool> activo(n, false);
    for (int i = 0; i < n; i++) {
        int k = orden[i] - 1;
        activo[k] = true;
        long long suma = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                distancias[i][j] = min(distancias[i][j], distancias[i][k] + distancias[k][j]);
                if (activo[i] && activo[j]) {
                    suma += distancias[i][j];
                }
            }
        }
        result[i] = suma;
    }

}

int main() {
    cin >> n;
    distancias.resize(n,vector<int>(n,INF));
    orden.resize(n);
    result.resize(n,0);

    for (int i = 0; i < n; i++) {
        distancias[i][i] = 0;
        for (int j = 0; j < n; j++) {
            int val;
            cin >> val;
            distancias[i][j] = val;
        }
    }
    for (int i = n-1; i >= 0; i--) {
        cin >> orden[i];
    }
    floydWarshall();
    for (int i = n-1; i>=0; i--) {
        cout << result[i] << " ";
    }
    return 0;
}
