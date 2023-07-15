
// cycle detection in undirected graph using DFS
//store the graph in adjacency list
// create  a visited array
// calll a for loop for call dfs for each node of every component  of the graph

//if any of the component  of the graph has cycle we can say that the graph has cycle

// changes to be made in the dfs algorithm
// Since it is a depth for search, we will traverse the graph  , and if any node finds the next node as visited then we can say that it has a cycle
//we will carry the parent node, with the node , for which we are calling dfs
// parent node visited is  not considered to be cycle
// a node which is visited, and is not a parent of the current node then there is a cycle

#include <bits/stdc++.h>

using namespace std;

class Solution
{

public:
    bool checkForCycle(int node, int parent, vector<int> adj[], vector<int> &vis)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (vis[it] == 0)
            {
                if (checkForCycle(it, node, adj, vis))
                    return true;
            }

            else if (it != parent)
                return true;
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> g[])
    {
        vector<int> vis(V + 1, 0);
        for (int i = 1; i <= V; i++)
        {
            if (!vis[i])
            {
                if (checkForCycle(i, -1, g, vis))
                    return true;
            }
        }

        return false;
    }
};

int main()
{
    int v, e;
    cout << "Enter the value of nodes / vertices " << endl;
    cin >> v;

    cout << "Enter the value of edges" << endl;
    cin >> e;

    vector<int> g[v + 1]; //size of vector as v+1 initialized with 0

    cout << "Enter the edges\n";
    //Taking the graph as input and storing it in list form
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout << endl;
    cout << "The adjacency list is --> \n";
    for (int i = 1; i <= v; i++)
    {
        cout << i << " --> ";
        for (int j = 0; j < g[i].size(); j++)
        {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    Solution obj;
    bool ans = obj.isCycle(v, g);
    if (ans)
        cout << "It has cycle\n";
    else
        cout << "It does not have cycle\n";
    return 0;
}