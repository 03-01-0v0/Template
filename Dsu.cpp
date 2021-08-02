#include <bits/stdc++.h>
using namespace std;

struct Dsu
{
    int n;
    vector<int> p;

    Dsu(int n) : n(n)
    {
        p.resize(n + 5);
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
            p[x] = y;
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