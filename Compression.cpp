//
// Created by HP on 5/19/2021.
//
#include <bits/stdc++.h>
using namespace std;

// Nen so thanh cac phan tu co gia tri tu 0 -> N voi N < size cua mang

void compression(vector<int> &a)
{
    vector<int> s = a;
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());

    for(auto &i : a)
    {
        i = lower_bound(s.begin(), s.end(), i) - s.begin();
    }
}


signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    vector<int> a = {-3, 1, 4, 6, 9};
    compression(a);
    for(auto e : a)
        cout << e << " ";

    return 0;
}
