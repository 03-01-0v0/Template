/*
 * Cho ham fx la mot parabol tim cuc tieu hoac cu dai
 * Chat tam phan chia lam 3 doan
 * Vi du tim cuc dai : l, r
 * Xet 2 diem m1, m2
 * Neu f(m1) < f(m2) -> m1, r
 * Neu f(m1) > f(m2) -> (l, m2)
 * Neu f(m1) = f(m2) -> (m1, m2)
*/
#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    double res;
    return res;
}

double ternary_search(double l, double r)
{
    for(int i = 0; i < 100; i++)
    {
        double m1 = (l + l + r) / 3;
        double m2 = (r + r + l) / 3;
        if(f(m1) < f(m2))
            l = m1;
        else
            r = m2;
    }
    return f(l);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);



    return 0;
}