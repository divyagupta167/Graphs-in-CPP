//Bidges:- It is an edge on removal of which, the graph will be broken into two two or more components
//We will use two array --> time of insertion [](found during dfs) and lowest time of insertion[](found around all its adjacent nodes)
//start from a node, TOI and LTOI will will 1/1, for next node 2/2 similary proceed till the last node
//when reaching the last node,returning occurs
//now for the last node look for adjacent nodes, is its adjacent has lower LTOI then take that for last node
//similarly move back taking the loer LTOI, from adjacent nodes
//To know if the edge is a bridge we use a formula --> if(low[it] > time[node]) then it is a bridge [ "it" is adjacent node and "node" is current ndoe for whom we are looking for adjacent nodes]

//Time Complexity :- O(N+E)
//Space Complexity :- O(2N) Approx O(N)

#include <bits/stdc++.h>

using namespace std;

void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> g[])
{
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    for (auto it : g[node])
    {
        if (it == parent)
        {
            continue;
        }

        if (!vis[it])
        {
            dfs(it, node, vis, tin, low, timer, g);
            low[node] = min(low[node], low[it]);
            if (low[it] > tin[node])
            {
                cout << "The edge " << node << "-" << it << " is a bridge" << endl;
            }
        }
        else
        {
            low[node] = min(low[node], tin[it]);
        }
    }
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

    vector<int> tin(v, -1);
    vector<int> low(v, -1);
    vector<int> vis(v, 0);

    int timer = 0;

   
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, vis, tin, low, timer, g);
        }
    }

    return 0;
}
