// 2 type of graph directed and undirected
// a non linear ds made up of a collction of vertices with edge

// total degree =[ 2 * E]
// graph represent by adjacency matrix or list

#include <bits/stdc++.h>
using namespace std;

class unWighted
{
public:
    void adjMatrix(int n, int m)
    {
        vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0)); // int adj[n+1][n+1]

        cout << "Enter the edge between 2 vertices: " << endl;

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u][v] = 1;
            adj[v][u] = 1; // in directed graph this line not exits bcoz directed is one directional
        }

        cout << "The adjacency matrix is " << endl;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << adj[i][j] << (j == n ? '\n' : ' ');
            }
        }

        // SC-> O(v * v)
    }

    void adjacencyList(int n, int m)
    {
        vector<vector<int>> adjL(n + 1);

        cout << "Enter the edge between 2 vertices: " << endl;

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;

            adjL[u].push_back(v);
            adjL[v].push_back(u); // in directed graph this line not exits bcoz directed is one directional
        }

        cout << "The adjacency list is " << endl;

        for (int vertex = 1; vertex <= n; vertex++)
        {
            cout << vertex << ": ";
            for (int neighbour : adjL[vertex])
            {
                cout << neighbour << ' ';
            }
            cout << '\n';
        }

        // SC -> O(v + 2 * e)
    }
};

class weighted
{
public:
    void adjMatrix(int n, int m)
    {
        vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0)); // int adj[n+1][n+1]

        cout << "Enter the edge between 2 vertices and weight: " << endl;

        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v;
            adj[u][v] = w;
            adj[v][u] = w; // in directed graph this line not exits bcoz directed is one directional
        }

        cout << "The adjacency matrix is " << endl;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << adj[i][j] << (j == n ? '\n' : ' ');
            }
        }

        // SC-> O(v * v)
    }

    void adjacencyList(int n, int m)
    {
        vector<vector<pair<int, int>>> adjL(n + 1);

        cout << "Enter the edge between 2 vertices and weight: " << endl;

        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;

            adjL[u].push_back({v, w});
            adjL[v].push_back({u, w}); // remove for directed graph
        }

        cout << "The adjacency list is " << endl;

        for (int vertex = 1; vertex <= n; vertex++)
        {
            cout << vertex << ": ";

            for (auto neighbour : adjL[vertex])
            {
                cout << "(" << neighbour.first << ", "
                     << neighbour.second << ") ";
            }

            cout << '\n';
        }

        // SC -> O(V + 2 * E)
    }
};

int main()
{

    int v, e;
    cout << "Enter the vertices and edges of the graph: ";
    cin >> v >> e;

    unWighted g1;
    g1.adjMatrix(v, e);

    weighted g2;
    g2.adjMatrix(v, e);

    /*     weight
    2 1      3
    1 3      2
    2 4      5
    3 4      7
    2 5      1
    4 5      4
    */

    return 0;
}