#include <bits/stdc++.h>
using namespace std;

struct Dsu
{
    int n;
    vector<int> p, sz;

    Dsu(int n) : n(n)
    {
        p.resize(n + 5);
        sz.resize(n + 5, 1);
        iota(p.begin(), p.end(), 0);
    }

    int get(int x)
    {
        return (x == p[x] ? x : (p[x] = get(p[x])));
    }

    bool unite(int x, int y)
    {
        x = get(x);
        y = get(y);
        if (x != y)
        {
            if (sz[x] > sz[y]) swap(x, y);
            p[x] = y;
            sz[y] += sz[x];
            return true;
        }
        return false;
    }
};

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);


    return 0;
}
