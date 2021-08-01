//
// Created by HP on 5/12/2021.
//
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;

int extend_euclid(int a, int b, int &x, int &y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int g = extend_euclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return g;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int x, y;
    int g = extend_euclid(6, mod, x, y);
    x = (x % mod + mod) % mod;
    cout << g << " " << x << " " << y << endl;

    return 0;
}
