//Shortest distance in  Undirected graph uisng BFS
//store the graph  in an adjacency list
//our problem  is to find single source shortest path to all other nodes
//take a distance array of size = number of nodes and initialize it with infinity(INT_MAX,1e9,etc)
//take a queue data structure, and it will always store the nodes
// firstly take the source node and push it in the queue, and mark the distance from source to itself in the visited array(it will be 0)
// take out the  source node, and we know that the distance from source node to itself will be zero
// check for adjacent nodes, and the distance to them will be +1 from the source node,
// and since we know value 0+1 is <<< than infinity, we will modify the node distance value  in the array
// and push the adjacent nodes into the queue
// now we take the front element from the queue, and them repeat the earlier process  again

#include <bits/stdc++.h>

using namespace std;


void BFS(vector<int> g[],int N , int src){
    int dist[N];
    for(int i=0; i<N; i++){
        dist[i] = INT_MAX;
    }

    queue<int> q;
    dist[src] =0;
    q.push(src);

    while(q.empty()==false){
        int node = q.front();
        q.pop();

        for(auto it:g[node]){
            if(dist[node] + 1 < dist[it]){
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }

    for(int i=0; i<N; i++)
    {
        cout << "The distance from source to node  "<< i << "  is --> "<< dist[i]<<" "<<endl;
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

    cout << "Enter the source " << endl; // considering 0 based indexing
    int src;
    cin >> src;
    BFS(g, v, src);

    return 0;
}