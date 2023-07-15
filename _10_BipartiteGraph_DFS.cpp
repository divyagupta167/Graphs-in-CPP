// Bipartite Graph using DFS.
// It is a type of graph that can be coloured using 2  colors such that no two adjacent nodes have same color.
// If the graph has odd length cycle, it cannot be bipartite graph.
// IF the graph does not have even lengh cycle, then also it can be bipartite
// If the graph does not have odd length cycle, it can be bipartite graph.

// store the graph in adjacent list
// take a array of color, initialized with -1, and its size is equal to number of ndes
// start dfs, starting with a node, colored with -1, color it with a color 1 or 0
// now check for the adjacent node of the source node
// now before calling for dfs, we should color it with opposite color
// again repeat the same process

//Time complexity is O(N+E) //since DFS
//Space complexity is O(N+E)+O(N)+O(N) (adjacency list+ queue+ color array)

#include <bits/stdc++.h>

using namespace std;

// the BFS bipartite function to check graph whether it is bipartite or not
bool bipartiteDFS(int node, vector<int> g[], int color[])
{
    if (color[node] == -1)
    {
        color[node] = 1;

        for (auto it : g[node])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[node];
                if (!bipartiteDFS(it, g, color))
                {
                    return false;
                }
                else if (color[it] == color[node])
                {
                    return false;
                }
            }
        }
    }
    return true;
}

//calling bipartite for each component of the graph
bool checkBipartite(vector<int> g[], int n)
{
    int color[n];
    memset(color, -1, sizeof color);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!bipartiteDFS(i, g, color))
            {
                return false;
            }
        }
    }
    return true;
}

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

    if (checkBipartite(g, v))
    {
        cout << "Yes the graph is Bipartite" << endl;
    }
    else
    {
        cout << "NO the graph is not Bipartite" << endl;
    }

    return 0;
}