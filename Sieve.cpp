//
// Created by HP on 5/12/2021.
//
#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> Sieve(int n)
{
    vector<bool> mark(n + 5, true);
    vector<int> primes;
    mark[0] = mark[1] = false;
    for(int i = 2; i * i <= n; i++)
        if(mark[i])
            for(int j = i * i; j <= n; j += i)
                mark[j] = false;
    for(int i = 2; i < n; i++)
        if(mark[i])
            primes.push_back(i);
    return primes;
}

vector<int> SegmentedSieve(int l, int r, vector<int> primes)
{
    if(l == 1)
        ++l;
    vector<bool> mark(r - l + 5, true);
    vector<int> res;
    for(int i = 0; primes.size() && primes[i] * primes[i] <= r; i++)
    {
        int base = (l / primes[i]) * primes[i];
        if(base < l)
            base += primes[i];
        for(int j = base; j <= r; j += primes[i])
        {
            if(j != primes[i])
                mark[j - l] = false;
        }
    }
    for(int i = l; i <= r; i++)
        if(mark[i - l])
            res.push_back(i);
    return res;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    vector<int> primes = Sieve(1e6);
    vector<int> res = SegmentedSieve(1e9, 1e9 + 20, primes);
    for(auto e : res)
        cout << e << " ";

    return 0;
}