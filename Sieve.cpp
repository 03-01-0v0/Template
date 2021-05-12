//
// Created by HP on 5/12/2021.
//
#include <bits/stdc++.h>
using namespace std;

vector<int> Sive(int n)
{
    vector<bool> c(n + 5, true);
    vector<int> primes;
    c[0] = c[1] = false;
    for(int i = 2; i * i <= n; i++)
        if(c[i])
            for(int j = i * i; j <= n; j += i)
                c[j] = false;
    for(int i = 2; i < n; i++)
        if(c[i])
            primes.push_back(i);
    return primes;
}


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);


    return 0;
}
