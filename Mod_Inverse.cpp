//
// Created by HP on 5/14/2021.
//
/*
 *  (a / b) % m != (a % m) / (b % m)
 *  (a / b) % m = [(a % m) * (1 / b) % m] % m
 *  Dat (1 / b) % m = X <=> 1 % m = (b * X) % m => Bai toan dua ve tim module inverse (X) de tinh 1 / b
 *  Cac canh tinh X (mod_inverse)
 *  Neu gcd(b, m) = 1
 *      Th 1 : Neu b va m nguyen to cung nhau tinh theo dinh ly Euler
 *          b^phi(m) % m = 1 % m
 *          chia ca 2 ve cho b^-1 => b^[phi(m) - 1] = b^-1 = X
 *      Th 2: Neu m la so nguyen to tinh theo Fermat little theorem :
 *          b^(m - 1) % m = 1 % m
 *          chia ca 2 ve cho b^-1 => b^(m - 2) = b^-1 = X
 *      Th 3: Tinh theo dinh ly extend_euclid : (b * X) % m = 1 % m
 *          Tinh X theo dinh ly
 *  Neu gcd(b, m) != 1 => khong co mod_inverse
    Ket qua: (a / b) % m = ((a % m) * (X % m)) % m
 */
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

long long fpow(long long a, long long b, long long mod)
{
    a %= mod;
    long long res = 1;
    while(b)
    {
        if(b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

long long extend_euclid(long long A, long long B, long long &x, long long &y)
{
    if(B == 0)
    {
        x = 1;
        y = 0;
        return A;
    }
    long long x1, y1;
    long long g = extend_euclid(B, A % B, x1, y1);
    x = y1;
    y = x1 - y1 * (A / B);
    return g;
}


long long inverse(long long A, long long M)
{
    long long x, y;
       int g = extend_euclid(A, M, x, y);
    assert(g == 1);
    return (x % M + M) % M;
//    M is primes = true
//    return fpow(A, M - 2, M);
}

vector<int> mod_inverse_array(int m)// Tinh tat ca mod inverse cua toan bo [1, m - 1] voi O(m) neu m la so nguyen to
{
    vector<int> r(m + 5);
    r[1] = 1;
    for(int i = 2; i < m; i++)
        r[i] = (m - (m / i) * r[m % i] % m) % m;
    return r;
}

long long add(long long A, long long B, long long mod)
{
    return (A % mod + B % mod) % mod;
}

long long sub(long long A, long long B, long long mod)
{
    A -= B;
    return (A < 0 ? A + mod : A);
}

long long mul(long long A, long long B, long long mod)
{
    return ((A % mod) * (B % mod)) % mod;
}

long long div(long long A, long long B, long long mod)
{
    return mul(A, inverse(B, mod), mod);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cout << div(18, 6, MOD);

    return 0;
}
