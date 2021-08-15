#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int V, E;
vector<int> g[maxn];

bool topologicalSort(vector<int> &res)
{
    vector<int> indegree(V + 5, 0);
    queue<int> zero_indegree;
    for (int u = 1; u <= V; u++)
    {
        for (auto v : g[u])
            ++indegree[v];
    }
    for (int i = 1; i <= V; i++)
        if (indegree[i] == 0)
            zero_indegree.push(i);
    while (!zero_indegree.empty())
    {
        int u = zero_indegree.front();
        zero_indegree.pop();
        res.push_back(u);
        for (auto v : g[u])
        {
            --indegree[v];
            if (indegree[v] == 0)
                zero_indegree.push(v);
        }
    }
    for (int i = 1; i <= V; i++)
        if (indegree[i] != 0)
            return false;
    return true;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> V >> E;
    for (int u, v, i = 0; i < E; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
    }
    cout << "Topological Sort of graph: " << "\n";
    vector<int> res;
    if (topologicalSort(res))
    {
        for (auto e : res)
            cout << e << " ";
    }
    else
        cout << "No result";

    return 0;
}