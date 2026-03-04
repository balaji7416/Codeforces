#include <bits/stdc++.h>
using namespace std;

#define int long long

void dfs(int u, vector<vector<int>> &adj, vector<bool> &visited, bool &isCycle)
{
    if (adj[u].size() != 2)
    {
        isCycle = false;
    }
    visited[u] = true;
    for (auto v : adj[u])
    {
        if (!visited[v])
        {
            dfs(v, adj, visited, isCycle);
        }
    }
}
bool bfs(int node, vector<vector<int>> &adj, vector<bool> &visited)
{
    queue<int> q;
    int n = adj.size();
    q.push(node);
    visited[node] = true;
    bool isCycle = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (adj[u].size() != 2)
        {
            isCycle = false;
        }
        for (auto v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return isCycle;
}
int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            /*bool isCycle = true;
            dfs(i, adj, visited, isCycle);
            if (isCycle)
            {
                ans++;
            }*/
            if (bfs(i, adj, visited))
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
/* why didn't it worked? failed at test case 18
int32_t main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    vector<int> cycles(n, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (cycles[dsu.find(u)])
        {
            cycles[dsu.find(u)] = -1;
        }
        if (cycles[dsu.find(v)])
        {
            cycles[dsu.find(v)] = -1;
        }
        if (!dsu.unite(u, v))
        {
            int p = dsu.find(u);
            if (cycles[p] == 0)
            {
                cycles[p] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (cycles[i] == 1)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
*/