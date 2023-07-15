// It is used to find minimum  spanning Tree
// Start from a source node, and now check for adjacent nodes with minimum weight, go for that node which has min weight
// Next look for min weight  adjacent nodes for that whole component(source node along with the next node/nodes**)

//To implement Prims algo we need three different array(size will be same as the number of nodes)
// Key array :- initialized with infinity except the 0th index
// MST array :- all marked as false
// Parent array :- all marked with -1

// figure out the index with min value from the key array, and also which is not a part of the  MST array
// now mark it as true in the MSt
// next check for  adjacent nodes, then check if the adjacent node is part of the MST or not
// If not then ,
// go to the key array, and put the edge weight in the respective index no. (the index no. equal to adjacent node value)
// and also go to parent  array, and update the parent value for the respective node.
// Do not include it in the MST array

// again find the index with min value from the key array, and also which is not a part of the  MST array, and repeat the above process, untill the whole process achieves the base case.

// The sum of key array will give us the minimum value of the spanning tree
// The parent array will give us the respective parents for the respective index values

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int v, e;
    cout << "Enter the value of nodes / vertices " << endl;
    cin >> v;

    cout << "Enter the value of edges" << endl;
    cin >> e;

    vector<pair<int, int>> g[v]; //size of vector as v+1 initialized with 0(1 indexed graph)

    cout << "Enter the edges\n";
    //Taking the graph as input and storing it in list form
    for (int i = 0; i < e; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        g[u].push_back({v, wt});
        g[v].push_back({u, wt});
    }
    cout << endl;

    // printing normal graph without weights
    // cout << "The adjacency list is --> \n";
    // for (int i = 1; i <= v; i++)
    // {
    //     cout << i << " --> ";
    //     for (int j = 0; j < g[i].size(); j++)
    //     {
    //         cout << g[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // printing  graph with weights
    cout << "The adjacency list with (nodes,edge-weight) is --> \n";
    int x, y;
    for (int i = 0; i < v; i++)
    {
        cout << i << " --> ";
        for (auto it : g[i])
        {
            x = it.first;
            y = it.second;
            cout << "(" << x << "," << y << ")"
                 << " ";
        }
        cout << endl;
    }

    int parent[v];
    int key[v];
    bool mst[v];

    for (int i = 0; i < v; i++)
    {
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < v - 1; i++)
    {
        //checking for the minimal key value
        int mini = INT_MAX, u;

        for (int m = 0; m < v; m++)
        {
            if (mst[m] == false && key[m] < mini)
            {
                mini = key[m], u = m;
            }
        }

        mst[u] = true;

        for (auto it : g[u])
        {
            int m = it.first;
            int weight = it.second;
            if (mst[m] == false && weight < key[m])
            {
                parent[m] = u, key[m] = weight;
            }
        }
    }
    cout << endl;
    cout << "The minimum spanning tree is -->" << endl;
    for (int i = 1; i < v; i++)
    {

        cout <<"The edge "<< parent[i] << "-" << i << " with weight --> "<<key[i]<< endl;
    }
    cout << endl;
    cout << "The minimum cost of the spanning tree is --> " ;
    int sum = 0;
    for (int i = 1; i < v; i++)
    {
        sum = sum + key[i];
    }
    cout << sum ;
     cout << endl;

    return 0;
}
