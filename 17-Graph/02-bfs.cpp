// BFS traversal is 1 node and every same distance node traval

#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int v, vector<int> adj[])
{
    int vis[v] = {0};

    vis[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto it : adj[node])
        {
            if (vis[it] == 0)
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;

    //TC->O(N) + O(2E);
    //SC->O(3N);
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

    /*
    int v, e;
    cin >> v >> e;

    vector<vector<int>> adj(v + 1);

    for(int i = 0; i < e; i++) {
    int u, x;
    cin >> u >> x;

    adj[u].push_back(x);
    adj[x].push_back(u);
    */

    vector<int> ans = bfs(v, adj);

    cout << "BFS traversal is: ";
    for (int it : ans)
    {
        cout << it << " ";
    }

    return 0;
}