//
// Created by HP on 6/28/2021.
//
/*
 * segment tree vs st[id].first = min st[id].second = max
 * upd don le, khong lazy
 */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;

int N;
int A[maxn];
pair<int, int> st[maxn << 2];

pair<int, int> combine(pair<int, int> X, pair<int,int> Y)
{
    pair<int, int> res;
    res.first = min(X.first, Y.first);
    res.second = max(X.second, Y.second);
    return res;
}

void build(int l, int r, int id)
{
    if (l == r)
    {
        st[id] = {A[l], A[l]};
        return;
    }
    int m = (l + r) >> 1;
    build(l, m, id << 1);
    build(m + 1, r, id << 1 | 1);
    st[id] = combine(st[id << 1], st[id << 1 | 1]);
}

void upd(int l, int r, int id, int pos, int v)
{
    if (l == r)
    {
        st[id] = {v, v};
        return;
    }
    int m = (l + r) >> 1;
    if (pos <= m)
        upd(l, m, id << 1, pos, v);
    else
        upd(m + 1, r, id << 1 | 1, pos, v);
    st[id] = combine(st[id << 1], st[id << 1 | 1]);
}

pair<int, int> get(int l, int r, int id, int f, int t)
{
    if (t < l || f > r)
        return {1e9, -1e9};
    if (f <= l && r <= t)
        return st[id];
    int m = (l + r) >> 1;
    return combine(get(l, m, id << 1, f, t), get(m + 1, r, id << 1 | 1, f, t));
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    build(0, N - 1, 1);
    pair<int, int> res = get(0, N - 1, 1, 0, N - 1);
    cout << res.first << " " << res.second << "\n";

    return 0;
}
