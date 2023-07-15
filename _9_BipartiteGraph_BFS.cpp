// Bipartite Graph using BFS.
// It is a type of graph that can be coloured using 2  colors such that no two adjacent nodes have same color.
// If the graph has odd length cycle, it cannot be bipartite graph.
// IF the graph does not have even lengh cycle, then also it can be bipartite
// If the graph does not have odd length cycle, it can be bipartite graph.

//Here we are usning BFS algorithm to check if the graph is bipartite
// we need queue data structure, and a colour array initialized with -1
// we are starting with node 1,put it in the queue and color it with color 0
// now start bfs traversal
// now color next node(adjacent node) with  with color 1
// now again check for next adjacent node, colour it with exact opposite color

//Time complexity is O(N+E) //since BFS
//Space complexity is O(N+E)+O(N)+O(N) (adjacency list+ queue+ color array)

#include <bits/stdc++.h>

using namespace std;


// the BFS bipartite function to check graph whether it is bipartite or not
bool bipartiteBFS(int src, vector<int> g[],int color[]){
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it : g[node]){
            if(color[it] == -1){
                color[it] = 1 - color[node];
                q.push(it);
            }
            else if(color[node] == color[it]){
                return false;
            }
        }
    }
    return true;
}

//calling bipartite for each component of the graph
bool checkBipartite(vector<int> g[],int n){
    int color[n];
    memset(color, -1 , sizeof color);
    for(int i=0; i<n; i++){
        if (color[i] == -1){
            if(!bipartiteBFS( i, g , color)){
                return false;
            }
        }
    }
    return true;
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
     
  if(checkBipartite(g,v)){
      cout << "Yes the graph is Bipartite" << endl;
  }else{
       cout << "NO the graph is not Bipartite" << endl;
  }
    

     return 0;
}

