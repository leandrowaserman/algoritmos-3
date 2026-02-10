#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define MAXN 201

int dp[MAXN][MAXN];
int N;
vector<int> lista;


int f(int i, int b, int w) {
    if (i >= N) {
        return 0;
    }
    if (dp[b][w] != -1) {
        return dp[b][w];
    }

    int num = lista[i];
    int res = 1 + f(i + 1, b, w);

    if (b == N || num > lista[b]) {
        res = min(f(i + 1, i, w), res);
    } 
    if (w == N || num < lista[w]) {
        res = min(f(i + 1, b, i), res);
    }

    dp[b][w] = res;
    return res;
}

int main() {
    while (cin >> N && N != -1) {
      vector<int> nuevaLista(N);
      for (int i = 0; i < N; i++) {
            cin >> nuevaLista[i];
        }
        lista = nuevaLista;
        memset(dp,-1,sizeof(dp));
        cout << f(0, N, N) << endl;
    }

    return 0;
}
