#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;

int minPrime[maxn];

vector<int> factorize(int n)
{
    vector<int> res;
    while (n != 1)
    {
        res.push_back(minPrime[n]);
        n /= minPrime[n];
    }
    return res;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for (int i = 2; i * i < maxn; i++)
        if (minPrime[i] == 0)
            for (int j = i * i; j < maxn; j += i)
                if (minPrime[i] == 0)
                    minPrime[j] = i;
    for (int i = 2; i < maxn; i++)
        if (minPrime[i] == 0)
            minPrime[i] = i;

    return 0;
}
