//
// Created by 03_01_0v0 on 17/02/2022.
//
#include <bits/stdc++.h>
using namespace std;

const int maxn = 505;

int a[maxn][maxn], psum[maxn][maxn];

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> a[i][j];
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            psum[i][j] += psum[i][j - 1] + a[i][j];
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            psum[i][j] += psum[i - 1][j];
    int Q;
    cin >> Q;
    while(Q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        --x1; --y1;
        cout << psum[x2][y2] - psum[x1][y2] - psum[x2][y1] + psum[x1][y1] << "\n";
    }

    return 0;
}
