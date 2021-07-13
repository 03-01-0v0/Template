/*
 *  chuoi s da duoc + them " " o dau chuoi trong contructor
 *  N trong struct la so luong mod muon dung
 *  Chu y : them #define int long long
 *  mod cang nhieu, time cang cao
 */
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int base = 31;
const int mod[] = {(int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9 + 9277};

struct Hash
{
    int N;
    vector<vector<int>> P, T;
    string s;
    Hash() {}
    Hash(int N, string s)
    {
        this -> N = N;
        this -> s = " " + s;
        P.assign(N, vector<int>(s.size() + 5, 0));
        T.assign(N, vector<int>(s.size() + 5, 0));
        this -> cal();
    }

    void cal()
    {
        for (int i = 0; i < N; i++)
            P[i][0] = 1;
        for (int i = 0; i < N; i++)
        {
            for (int j = 1; j < s.size(); j++)
            {
                P[i][j] = P[i][j - 1] * base % mod[i];
                T[i][j] = (T[i][j - 1] * base + s[j] - 'a' + 1) % mod[i];
            }
        }
    }

    vector<int> get(int i, int j)
    {
        vector<int> res(N, 0);
        for (int id = 0; id < N; id++)
            res[id] = (T[id][j] - T[id][i - 1] * P[id][j - i + 1] + mod[id] * mod[id]) % mod[id];
        return res;
    }

};

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s = "abacaba";
    Hash h(3, s);
    cout << (h.get(1, 1) == h.get(6, 7)) << "\n";
    return 0;
}