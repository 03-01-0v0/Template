#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 5;

int N, Q;
int a[maxn], st[maxn << 2], lz[maxn << 2];

void build(int l, int r, int id)
{
    if (l == r)
    {
        st[id] = a[l];
        return;
    }
    int m = (l + r) >> 1;
    build(l, m, id << 1);
    build(m + 1, r, id << 1 | 1);
    st[id] = st[id << 1] + st[id << 1 | 1];
}

void down(int l, int r, int id)
{
    if (lz[id] != 0)
    {
        int m = (l + r) >> 1;
        st[id << 1] += (m - l + 1) * lz[id];
        lz[id << 1] += lz[id];
        st[id << 1 | 1] += (r - m) * lz[id];
        lz[id << 1 | 1] += lz[id];
        lz[id] = 0;
    }
}

void upd(int l, int r, int id, int f, int t, int v)
{
    if (t < l || f > r)
        return;
    if (f <= l && r <= t)
    {
        st[id] += (r - l + 1) * v;
        lz[id] += v;
        return;
    }
    down(l, r, id);
    int m = (l + r) >> 1;
    upd(l, m, id << 1, f, t, v);
    upd(m + 1, r , id << 1 | 1, f, t , v);
    st[id] = st[id << 1] + st[id << 1 | 1];
}

int get(int l, int r, int id, int f, int t)
{
    if (t < l || f > r)
        return 0;
    if (f <= l && r <= t)
        return st[id];
    down(l, r, id);
    int m = (l + r) >> 1;
    return get(l, m, id << 1, f, t) + get(m + 1, r, id << 1 | 1, f, t);
}

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    build(1, N, 1);
    while (Q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int a, b, v;
            cin >> a >> b >> v;
            upd(1, N, 1, a, b, v);
        }
        else
        {
            int k;
            cin >> k;
            cout << get(1, N, 1, k, k) << "\n";
        }
    }

    return 0;
}
