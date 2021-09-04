#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int N, Q;
int A[maxn], st[maxn][20];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        st[i][0] = A[i];
    for (int j = 1; (1 << j) <= N; j++)
        for (int i = 0; i + (1 << j) <= N; i++)
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);

    auto query = [&](int l, int r)
    {
        int len = r - l + 1;
        int j = 31 - __builtin_clz(len);
        return min(st[l][j], st[r - (1 << j) + 1][j]);
    };
    cin >> Q;
    while (Q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << "\n";
    }

    return 0;
}