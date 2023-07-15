// we will create a adjacency list using vector
// eg. vector <int> adj[6] , here 6 is a size of the array ,with index starting from 0
// Space complesity will be ( N + 2E )

//for undirected graph
// vector <int> adj[6]
// adj[u].pushback(v)  , u please pushback v because  it is your adjacent node
// adj[v].pushback(u)  , v please pushback u because  it is your adjacent node

//for directed graph
// vector <int> adj[6]
// adj[u].pushback(v)  , u please pushback v because  it is your adjacent node

//for weighted  undirected graph
//  vector < pair< int , int>> adj[6]
// adj[u].pushback({v ,w})  , u please pushback v because  it is your adjacent node with weight w
// adj[v].pushback({u ,w})  , v please pushback u because  it is your adjacent node with weight w

#include <bits/stdc++.h>

using namespace std;

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

    return 0;
}