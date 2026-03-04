#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 1e18;

/*
    Problem 20C: Dijkstra
    Pattern: Dijkstra
    Rating : 1900
*/

/* Approach:
    it's straight out dijkstra implementation
    guess i don't have to explain this
*/

int32_t main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> dist(n, inf);
    vector<int> parent(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0}); //{weight,node}
    dist[0] = 0;

    bool found = false;
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();

        // skip processing outdated entries
        if (d > dist[u])
            continue;
        if (u == n - 1)
        {
            found = true;
            break;
        }
        for (auto [v, w] : adj[u])
        {
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (!found)
    {
        cout << -1 << endl;
        return 0;
    }
    stack<int> path;
    int u = n - 1;
    while (u != -1)
    {
        path.push(u + 1);
        u = parent[u];
    }
    while (!path.empty())
    {
        cout << path.top() << " ";
        path.pop();
    }
    cout << endl;
}