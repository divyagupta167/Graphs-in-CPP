//Kosaraju algorithm for strongly connected component(SCC) in a directed graph
// SCC :- If we start from any node in the component, we will be able to reach every other element
// a single node can also be considered as a SCC

//The intuition for this algo is, if we find dfs from the reverse order, each dfs call returning  will give us a SCC


// We need three steps to solve the problem using Kosaraju
// 1.Sort all the nodes in the order of finishing time(Topological Sort)
// 2.Transpose the graph(all the edges will get reversed)
// 3.DFS according to the finishing time(poping element from the stack filled during topo sort and calling for dfs), when dfs returns we will print that value

// TC:-O(N+E)
// sC:-O(N+E) + O(N) +O(N)[ transpose + visited + stack for topo]


#include <bits/stdc++.h>

using namespace std;

void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> g[]){
    vis[node] = 1;
    for(auto it:g[node]){
        if(!vis[it]){
            dfs(it, st, vis, g);
        }
    }
    st.push(node);
}

void revDfs(int node, vector<int> &vis, vector<int> transpose[]){
    cout << node << " ";
    vis[node] = 1;
    for(auto it: transpose[node]){
        if(!vis[it]){
            revDfs( it, vis, transpose);
        }

    }
}

int main() {
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

    //topo sort
    stack<int> st;
    vector<int> vis(v,0);
    for(int i=0; i<v; i++){
        if(!vis[i]){
            dfs(i, st, vis,g);
        }
    }

    //graph transpose
    vector<int> transpose[v];
    for(int i=0; i<v; i++){
        vis[i] = 0;
        for(auto it:g[i]){
            transpose[it].push_back(i);
        }
    }

    //call dfs for rev graph
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!vis[node]){
            cout << "SCC is --> ";
            revDfs(node,vis,transpose);
            cout << endl;
        }
    }

     return 0;
}

