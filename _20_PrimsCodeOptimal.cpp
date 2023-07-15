// Time complexity will be here O(logN) by the use of priority queue instead of O(N^2)(Like in the previous case)
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

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    key[0] = 0;
    parent[0] = -1;
    pq.push({0, 0});

    while(pq.size()!=0)
    {
        //checking for the minimal key value
        int u = pq.top().second;
        pq.pop();

        mst[u] = true;

        for (auto it : g[u])
        {
            int m = it.first;
            int weight = it.second;
            if (mst[m] == false && weight < key[m])
            {
                parent[m] = u;
                 key[m] = weight;
                 pq.push({key[m],m});
            }
        }
    }
    cout << endl;
    cout << "The minimum spanning tree is -->" << endl;
    for (int i = 1; i < v; i++)
    {

        cout << parent[i] << "-" << i << endl;
    }
    cout << endl;
    cout << "The minimum cost of the spanning tree is --> ";
    int sum = 0;
    for (int i = 1; i < v; i++)
    {
        sum = sum + key[i];
    }
    cout << sum;

    return 0;
}
