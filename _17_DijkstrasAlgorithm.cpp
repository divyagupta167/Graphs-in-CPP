// Finding shortest distance from the source node to all other nodes, in undirected weighted graph
// Store the graph in an adjacency list , along with their weights
// Here we cannot use, queue data structure, because the edge weight is not equal
// we will use a priority queue(min heap), to store(dist,node) as pair
// we are using min priority queue, so the guy with min weight is always at the top
// also define a distance array, size equal to no. of nodes + 1, initialize it with infinity
// take the source node as 1; mark it as 0, in the visted array, put it in the priority queue as its distance equal to 0
// now start iterating in the queue, take the element with min dist(at first we have only one element), pop it out
// iterate for the adjacent nodes, and add the edge weights, if it less than infinity, update in the distance array
// add the adjacent nodes along with their weights in the priority queue
// whenever we get a better distance for any node, we will always update it in the distance array
// when adjacent nodes are over for a node(the one which we took from priority queue), we will look for another elements in the priority queue
// repeat the process untill the priority queue is not empty

#include <bits/stdc++.h>

using namespace std;
int main()
{
    int v, e;
    cout << "Enter the value of nodes / vertices " << endl;
    cin >> v;

    cout << "Enter the value of edges" << endl;
    cin >> e;

    vector<pair<int, int>> g[v + 1]; //size of vector as v+1 initialized with 0(1 indexed graph)

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

    int source;
    cout << "Enter the source  ";
    cin >> source;

    //Dijkstra's Algorithm begins from here
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //min heap
    vector<int> distTo(v + 1, INT_MAX);                                                 // 1 indexed array for calculating shortest path

    distTo[source] = 0;
    pq.push({0, source}); //(dist,node)

    while (!pq.empty())
    {
        int dist = pq.top().first; // pointing the top element of the queue
        int prev = pq.top().second;
        pq.pop();

        // traversing for the adjacent nodes,and updating the distance in the distance array
        vector<pair<int, int>>::iterator it;
        for (auto it : g[prev])
        {
            // storing the node and weight of the adjacent node
            int node = it.first;
            int distance = it.second;

            // updation in th distance array if required
            if (distTo[node] > distTo[prev] + distance)
            {
                distTo[node] = distTo[prev] + distance;

                //pushing adjacent node in the queue
                pq.push({distTo[node], node});
            }
        }
    }

    for (int i = 0; i < v; i++)
    {
        cout << "The distance from " << source << " to node " << i << " is " << distTo[i];

        cout << endl;
    }

    return 0;
}