// we go every node last element

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls)
{
    vis[node] = 1;
    ls.push_back(node);

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis, ls);
        }
    }
}

vector<int> dfsOfgraph(int v, vector<int> adj[])
{
    int vis[v + 1] = {0};
    int start = 1;
    vector<int> ls;
    dfs(start, adj, vis, ls);
    return ls;
    // TC-> O(N + 2E);
    // SC-> O(3N)
}

int main()
{
    int v = 8;

    vector<int> adj[v + 1];

    vector<pair<int, int>> edges = {
        {1, 2},
        {1, 6},
        {2, 3},
        {2, 4},
        {4, 5},
        {5, 7},
        {6, 7},
        {6, 8}};

    for (const auto &edge : edges)
    {
        int u = edge.first;
        int x = edge.second;
        adj[u].push_back(x);
        adj[x].push_back(u);
    }

    vector<int> ans = dfsOfgraph(v, adj);

    cout << "DFS traversal is: ";
    for (int it : ans)
    {
        cout << it << " ";
    }

    return 0;
}