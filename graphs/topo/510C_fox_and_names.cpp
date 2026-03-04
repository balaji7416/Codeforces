#include <bits/stdc++.h>
using namespace std;

#define int long long

/*
    Problem 510C: Fox and Names
    Pattern: Topological Sort + edge case handling
    Rating : 1600
*/
/* Approach:

    We are given names sorted according to an unknown alphabet order.
    For every adjacent pair of names, we compare characters until the
    first differing character. That first mismatch gives a directed
    ordering constraint: name1[j] -> name2[j].

    Special Case:
    If one string is a strict prefix of the other and the longer string
    appears first (e.g., "abcd" before "abc"), the ordering is impossible.

    Using all derived constraints, we build a directed graph of 26 letters.
    Then we perform Kahn’s Algorithm (BFS-based Topological Sort).

    - If we process all 26 letters → valid ordering exists.
    - If a cycle exists (topo size < 26) → print "Impossible".

    Time Complexity: O(total_characters + 26 + edges)
*/

int32_t main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> name(n);
    for (int i = 0; i < n; i++)
    {
        cin >> name[i];
    }
    vector<vector<int>> adj(26);
    for (int i = 0; i < n - 1; i++)
    {
        string name1 = name[i], name2 = name[i + 1];
        char u = name1[0], v = name2[0];
        int j = 0, k = 0;
        while (u == v && j + 1 < name1.size() && k + 1 < name2.size())
        {
            u = name1[j + 1];
            v = name2[k + 1];
            j = j + 1;
            k = k + 1;
        }
        if (u == v && name1.size() > name2.size())
        {
            cout << "Impossible" << endl;
            return 0;
        }
        if (u != v)
            adj[u - 'a'].push_back(v - 'a');
    }
    vector<int> inDegree(26, 0);
    for (int i = 0; i < 26; i++)
    {
        for (auto v : adj[i])
        {
            inDegree[v]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < 26; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> topo;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            inDegree[v]--;
            if (inDegree[v] == 0)
            {
                q.push(v);
            }
        }
        topo.push_back(u);
    }
    if (topo.size() != 26)
    {
        cout << "Impossible" << endl;
        return 0;
    }
    for (int i = 0; i < topo.size(); i++)
    {
        cout << char(topo[i] + 'a');
    }
    cout << endl;
    return 0;
}