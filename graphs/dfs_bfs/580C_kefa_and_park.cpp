#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
    Problem 580C: Kefa and Park
    Pattern: DFS / Tree + implementation
    Rating : 1500
*/

int dfs(int u, int k, int m, vector<vector<int>> &adj, vector<int> &cats, vector<bool> &visited)
{
    visited[u] = true;
    if (k > m)
    {
        return 0;
    }
    // leaf node reached
    if (u != 0 && adj[u].size() == 1)
    {
        return 1;
    }
    int ans = 0;
    for (auto v : adj[u])
    {
        if (visited[v])
            continue;
        int k_;
        if (!cats[v])
            k_ = 0;
        else if (cats[v])
            k_ = k + 1;
        ans += dfs(v, k_, m, adj, cats, visited);
    }
    return ans;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n); // cats, arr[i]=1 => cat, arr[i]=0 means no cat
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> visited(n, false);
    cout
        << dfs(0, 0 + arr[0], m, adj, arr, visited) << endl;
    return 0;
}