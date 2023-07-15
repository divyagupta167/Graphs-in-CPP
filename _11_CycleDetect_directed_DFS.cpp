// we have to modify the algorithm of cycle detection in undirected graph

// store the graph in adjacency list
// call the dfs funtion for each component of the graph using a for loop
// create two arrays --> 1.visited array and 2. dfs visited array
// start from a node
// call for dfs function,then mark visited array and mark dfs visited array
// check for adjacent node, mark as visited in both the array
// repeat the process for all the nodes
// after returning the recursive call, we will mark unvisited for the dfs array only, and not for the visited array
// now again if we find the adjacent node , which is visited(only in visited array), we will not call dfs for it because it is already visited
// during traversal if we find adjacent node of curent node(during current traversal), which is marked  visited in both the arrays, then we can say that there is a cycle in the directed graph
// Eg. vis[node] = 1 and also dfsvis[node] = 1 ,(for same node), it will return true

//Time Complexity O(N+E) [visiting all nodes and edges]
//space Complexity O(2N) [two types of array]
//Auxilliary space complexity O(N) [ memory during recursive class]

#include <bits/stdc++.h>

using namespace std;

class solution
{
private:
    // the dfs algorithm to check , cycle in directed graph
    bool checkCycle(int node, vector<int> g[], int vis[], int dfsVis[])
    {
        vis[node] = 1; // initiallizing vis and dfsVis as 0
        dfsVis[node] = 1;
        for (auto it : g[node]) // checking for adjacent nodes
        {
            if (!vis[it])
            {
                if (checkCycle(it, g, vis, dfsVis))
                {
                    return true;
                }
                else if (dfsVis[it]) // if node is visited in vis as well as dfsVis then return true
                {
                    return true;
                }
            }
        }
        dfsVis[node] = 0; // returning the recursive call
        return false;
    }

public:
    // callling for dfs for each node in the range of N
    bool isCyclic(int N, vector<int> g[])
    {
        int vis[N], dfsVis[N];
        memset(vis, 0, sizeof vis);
        memset(dfsVis, 0, sizeof dfsVis);

        for (int i = 0; i <N; i++)
        {
            if (!vis[i])
            {
                cout << i << endl;
                if (checkCycle(i, g, vis, dfsVis))
                {
                    return true;
                }
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
        // g[v].push_back(u);
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

      solution obj;
    bool ans = obj.isCyclic(v, g);
    if (ans)
        cout << "It has cycle\n";
    else
        cout << "It does not have cycle\n";

    return 0;
}
