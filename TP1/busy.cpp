#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int f (vector<pair<int,int>> lista){
    int n = lista.size();
    int res = 0;
    int ult = 0;
    for (int i=0; i < n; i++){
        if (lista[i].first >= ult){
            ult = lista[i].second;
            res++;
        }
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;

        vector<pair<int, int>> actividadesTotales;

        for (int j = 0; j < N; j++) {
            int inicio;
            int finalizacion;
            cin >> inicio;
            cin >> finalizacion;
            actividadesTotales.push_back(make_pair(inicio, finalizacion));
        }
        sort(actividadesTotales.begin(), actividadesTotales.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });

        cout << f(actividadesTotales) << endl;
    }

    return 0;
}