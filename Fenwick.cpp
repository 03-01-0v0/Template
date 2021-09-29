//
// Created by HP on 5/18/2021.
//
/*
 * Query :
 * 1 : update [l, r] them v
 * 2 : return A[i]
 * 3 : return sum(l, r)
 */
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 5;

int N, Q;
int A[maxn], Diff[maxn];
vector<int> bit1, bit2;

struct fenwick
{
    int N;
    vector<int> Bit;
    fenwick() {}
    fenwick(int N)
    {
        this -> N = N;
        this -> Bit.resize(N + 5, 0);
    }
    void upd(int idx, int v)
    {
        while (idx <= N)
        {
            Bit[idx] += v;
            idx += (idx & -idx);
        }
    }
    int get(int idx)
    {
        int sum = 0;
        while (idx)
        {
            sum += Bit[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }
    int rangeSum(int l, int r)
    {
        return get(r) - get(l - 1);
    }
};

void upd(vector<int> &Bit, int idx, int v)
{
    while(idx <= N)
    {
        Bit[idx] += v;
        idx += (idx & -idx);
    }
}

int get(vector<int> Bit, int idx)
{
    int sum = 0;
    while(idx)
    {
        sum += Bit[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void updRange(int l, int r, int v)
{
    upd(bit1, l, (N - l + 1) * v);
    upd(bit1, r + 1, -(N - r) * v);
    upd(bit2, l, v);
    upd(bit2, r + 1, -v);
}

int PrefixSum(int u)
{
    return get(bit1, u) - get(bit2, u) * (N - u);
}

int RangeSum(int l, int r)
{
    return PrefixSum(r) - PrefixSum(l - 1);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> N >> Q;
    for(int i = 1; i <= N; i++)
        cin >> A[i];
    bit1.resize(maxn, 0);
    bit2.resize(maxn, 0);
    for(int i = 1; i <= N; i++)
    {
        Diff[i] = A[i] - A[i - 1];
        upd(bit2, i, Diff[i]);
        upd(bit1, i, (N - i + 1) * Diff[i]);
    }
    while(Q--)
    {
        int op, l, r, v;
        cin >> op;
        if(op == 1)
        {
            cin >> l >> r >> v;
            updRange(l, r, v);
        }
        else
        {
            cin >> l >> r;
            cout << RangeSum(l, r) << "\n";
        }
    }

    return 0;
}
