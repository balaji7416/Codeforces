#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
    Problem 2195E: Idiot First Search
    Pattern: DFS / Tree
    Rating : ??
*/
/*
    It took a whole lot,lot time to understand this problem.
    guess i really have a long way to go
*/
/* Approach:
   1. first build the tree with three vectors: leftC, rightC, parent
   2. then dfs on tree to fill the pathLen vector(which is dfs len of each node)
   3. then build the answer vector with dfs by cummulative sum of pathLen, ans[u] = ans[parent[u]] + pathLen[u]
        note you can't build it with bottom up approach since it assumes the parent is already built which might not be case
*/
int mod = 1e9 + 7;
vector<int> leftC, rightC, parent;
vector<int> pathLen;
int dfs(int u)
{
    if (leftC[u] == -1 && rightC[u] == -1)
    {
        return pathLen[u] = 1;
    }
    if (pathLen[u] != -1)
    {
        return pathLen[u];
    }
    int leftEdges = leftC[u] == -1 ? 0 : dfs(leftC[u]);
    int rightEdges = rightC[u] == -1 ? 0 : dfs(rightC[u]);
    int extra = (leftEdges ? 1 : 0) + (rightEdges ? 1 : 0) + 1;
    return pathLen[u] = (extra + leftEdges + rightEdges) % mod;
}
void fill(int u, vector<int> &pathLen, vector<int> &ans)
{
    if (u == -1)
        return;
    if (u != 1)
        ans[u] = (ans[parent[u]] + pathLen[u]) % mod;
    fill(leftC[u], pathLen, ans);
    fill(rightC[u], pathLen, ans);
}
void solve()
{
    int n;
    cin >> n;
    leftC.assign(n + 1, -1);
    rightC.assign(n + 1, -1);
    parent.assign(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u != 0)
        {
            leftC[i] = u;
            parent[u] = i;
        }

        if (v != 0)
        {
            rightC[i] = v;
            parent[v] = i;
        }
    }

    pathLen.assign(n + 1, -1);
    dfs(1);
    vector<int> ans(n + 1, -1);
    ans[1] = pathLen[1];

    fill(1, pathLen, ans);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int32_t main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}