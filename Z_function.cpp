#include <bits/stdc++.h>
using namespace std;

vector<int> z_function(string s)
{
    int n = (int) s.length();
    vector<int> z(n);
    for (int x = 0, y = 0, i = 1; i < n; i++)
    {
        z[i] = max(0, min(z[i - x], y - i + 1));
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            x = i, y = i + z[i], ++z[i];
    }
    return z;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    vector<int> z = z_function(s);
    for (auto e : z)
        cout << e << ' ';
    return 0;
}
