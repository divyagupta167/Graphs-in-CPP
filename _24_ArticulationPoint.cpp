//Articulation Point :- It is the node, on removal of which the graph is broken into two or more components
//We will need two array time[],low[]
//here we will use --> if(low[it] >= time[node] && parent != -1), then it is a articulation point
// we will have one more check for the startting node -->  if(child > 1 && parent == -1)

#include <bits/stdc++.h>

using namespace std;

void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> g[], vector<int> &isArticulation)
{

    vis[node] = 1;
    tin[node] = low[node] = timer++;
    int child = 0;
    for (auto it : g[node])
    {
        if (it == parent)
        {
            continue;
        }

        if (!vis[it])
        {
            dfs(it, node, vis, tin, low, timer, g, isArticulation);
            low[node] = min(low[node], low[it]);
            child ++ ;
            if (low[it] >= tin[node] && parent != -1)
            {
                isArticulation[node] = 1;
            }
        }
        else
        {
            low[node] = min(low[node], tin[it]);
        }
    }

    if (parent == -1 && child > 1)
    {
        isArticulation[node] = 1;
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
    vector<int> isArticulation(v, 0);

    int timer = 0;

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, vis, tin, low, timer, g, isArticulation);
        }
    }

    for (int i = 0; i < v; i++)
    {
        if (isArticulation[i] == 1)
        {
            cout << i << endl;
        }
    }

    return 0;
}