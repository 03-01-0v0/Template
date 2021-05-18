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
using namespace std;

const int maxn = 2e5 + 5;

int N;
int A[maxn];
vector<int> bit1, bit2;

void upd(vector<int> &Bit, int idx, int v)
{
    while(idx <= N)
    {
        Bit[idx] += v;
        idx += (idx & (-idx));
    }
}

int get(vector<int> Bit, int idx)
{
    int sum = 0;
    while(idx)
    {
        sum += Bit[idx];
        idx -= (idx & (-idx));
    }
    return sum;
}

void updRange(int l, int r, int v)
{
    upd(bit1, l, (N - l + 1) * v);
    upd(bit1, r + 1, -(N - r) * v);
    upd(bit2, l, v);
    upd(bit2, r + 1, v);
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

    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> A[i];

    return 0;
}
