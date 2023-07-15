// shortest path from source to nodes in weighted DAG
// here we have to store the edges along with their weights

// store the graph in adjacency list, along with their weights
// firstly, find the topological sort of the graph either using bfs or dfs
// we will use a for loop, to call dfs for each node of the graph
// now take a visted array(initialized with 0) and a stack data structure
// and then call dfs for a node(****which is not visited****)
// the node for which we are calling dfs mark it as visited
// look for adjacent nodes of the source, call for dfs and mark them visited, repeat the process untill the base case is observed and function returns
// whenever the dfs for a node is over we put it in the stack , so that we can find the topo sort

// after finding the topo sort, we will create a distance array, marked as infinity
// take out the top element from the stack and mark the distance to itself as 0 ( if dist[node] != infinity , here it means we have reached the node)

//TC -->O(N+E) x 2
//SC --> O(2N)
//ASC --> for dfs call

#include <bits/stdc++.h>

using namespace std;

void findTopoSort(int node, int vis[], stack<int> &st, vector<pair<int, int>> g[])
{
    vis[node] = 1;
    for (auto it : g[node])
    {
        if (!vis[it.first])
        {
            findTopoSort(it.first, vis, st, g);
        }
    }
    st.push(node);
}

void shortestPath(int src, int N, vector<pair<int, int>> g[])
{
    // generating topo sort
    int vis[N] = {0};
    stack<int> st;
    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
        {
            findTopoSort(i, vis, st, g);
        }
    }

    int dist[N];
    for (int i = 0; i < N; i++)
        dist[i] = 1e9;
    dist[src] = 0;

    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (dist[node] != 1e9)
        {
            for (auto it : g[node])
            {
                if (dist[node] + it.second < dist[it.first])
                {
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        // (dist[i]==1e9) ? cout << "Infinity" : cout <<dist[i] << " ";
        cout <<"The distance from source node to node "<< i <<" is " ;
        if (dist[i] == 1e9)
            cout << "Infinity(Not Reachable) ";
        else
            cout << dist[i] ;
        cout << endl;
    }
}

int main()
{
    int v, e;
    cout << "Enter the value of nodes / vertices " << endl;
    cin >> v;

    cout << "Enter the value of edges" << endl;
    cin >> e;

    vector<pair<int, int>> g[v]; //size of vector as v+1 initialized with 0

    cout << "Enter the edges\n";
    //Taking the graph as input and storing it in list form
    for (int i = 0; i < e; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        g[u].push_back({v, wt});
        // g[v].push_back(u);
    }
    cout << endl;
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

    cout << "The adjacency list is --> \n";
    int x, y;
    for (int i = 0; i < v; i++)
    {
        cout << "Node " << i << " makes an edge with \n";
        for (auto it : g[i])
        {
            x = it.first;
            y = it.second;
            cout << "\tnode " << x << " with edge weight = " << y << endl;
        }
        cout << endl;
    }

    shortestPath(0, v, g);

    return 0;
}