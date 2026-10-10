// there is many graph or component of a graph we fine the how many component

#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    void dfs(int start, vector<int> adj[], vector<int> &vis)
    {
        vis[start] = 1;

        for (auto it : adj[start])
        {
            if (!vis[it])
            {
                dfs(it, adj, vis);
            }
        }
    }

public:
    int coonnectedGraph(int v, vector<int> adj[])
    {
        vector<int> vis(v, 0);
        int cnt = 0;

        for (int i = 1; i <= v; i++)
        {
            if (!vis[i])
            {
                cnt++;
                dfs(i, adj, vis);
            }
        }
        return cnt;

        // TC->O(N) + O(N + 2E);
        // SC-> O(2N)
    }
};

int main()
{

    int v = 8;
    vector<int> adj[v + 1];

    vector<pair<int, int>> edges = {
        {1, 2},
        {2, 3},
        {4, 5},
        {6, 7}};

    for (const auto &edge : edges)
    {
        int u = edge.first;
        int x = edge.second;
        adj[u].push_back(x);
        adj[x].push_back(u);
    }

    Solution solution;
    cout << "Number of connected components: "
         << solution.coonnectedGraph(v, adj) << '\n';

    return 0;
}