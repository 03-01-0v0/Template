//
// Created by HP on 5/12/2021.
//
#include <bits/stdc++.h>
using namespace std;

int phi(int n)
{
    int res = n;
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0)
        {
            while(n % i == 0)
                n /= i;
            res -= res / i;
        }
    if(n > 1)
        res -= res / n;
    return res;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cout << phi(9) << endl;

    return 0;
}
