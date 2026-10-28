// detect cycle of an undirected graph

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    class Bfs
    {
    private:
        bool bfs(int src, vector<int> adj[], int vis[])
        {
            vis[src] = 1;

            queue<pair<int, int>> q;
            q.push({src, -1});

            while (!q.empty())
            {
                int node = q.front().first;
                int parent = q.front().second;

                for (auto it : adj[node])
                {
                    if (!vis[it])
                    {
                        vis[it] = 1;
                        q.push({it, node});
                    }
                    else if (parent != it)
                    {
                        return true;
                    }
                }
            }
            return false;
        }

    public:
        bool isCycle(int v, vector<int> adj[])
        {
            int vis[] = {0};
            for (int i = 0; i < v; i++)
            {
                if (vis[i] == 0)
                {
                    if (bfs(i, adj, vis) == true)
                        return true;
                }
            }
            return false;
            // TC-> O(v + 2E)
            // SC-> O(N);
        }
    };

    class Dfs
    {
    private:
        bool dfs(int src, int parent, vector<int> adj[], int vis[])
        {
            vis[src] = 1;
            for (auto it : adj[src])
            {
                if (!vis[it])
                {
                    if (dfs(it, src, adj, vis))
                        return true;
                }
                else if (it != parent)
                    return true;
            }
            return false;
        }

    public:
        bool isCycle(int v, vector<int> adj[])
        {
            int vis[] = {0};
            for (int i = 0; i < v; i++)
            {
                if (vis[i] == 0)
                {
                    if (dfs(i, -1, adj, vis) == true)
                        return true;
                }
            }
            return false;
            // TC-> O(v + 2E)
            // SC-> O(N);
        }
    };
};

int main()
{
    int v = 5;
    vector<int> adj[v];

    auto addEdge = [&](int u, int w)
    {
        adj[u].push_back(w);
        adj[w].push_back(u);
    };

    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(3, 4);
    addEdge(4, 1);

    Solution::Dfs solver;
    cout << (solver.isCycle(v, adj) ? "Cycle detected" : "No cycle detected") << '\n';

    return 0;
}