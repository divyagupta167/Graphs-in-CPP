// Kruskal's Algorithm for finding minimum spanning tree
// Here we will not store the graph in an adjacency list
// Rather than we will store the graph in a simple linear data structure called disjoint set because the first step of the kruskal algo says that we have to sort the edges according to the weights in the ascending order(wt,u,v)
// Then next step is to greedily pick up the edge with lowest weight
// then check u and v belong to the same component or not(by finding the parent), if not then we will take the edge with its weight
// repeat the process for all the edges
// We are not taking the edge of the same component to avoid a cycle, as spanning tree cannot have cycle
// Since we have sorted the edges in ascending order, the minimum spanning tree concept still remains and we are avoiding cycle  using the same component  concept

// Time complexity :- O(NlogN)[sorting] + O(N x O(4a))[edges x  disjoint set ]  
// Space  Complexity :- O(N) [storing disjoint set + O(N)[parent array]+ O(N)[Rank array] approx O(N)

#include <bits/stdc++.h>

using namespace std;


// creating the data type for graph
struct node{
    int u;
    int v;
    int wt;
    node( int first, int second, int weight){
        u = first;
        v = second;
        wt = weight;
    }
};

//self comparator
bool comp( node a, node b){
    return a.wt < b.wt;
}

//finding parent function
int findPar(int u, vector<int> &parent){
    if (u==parent[u]){
        return u;
    }
    return findPar(parent[u],parent);
}

//unionn creating function
void unionn(int u,int v, vector<int> &parent,vector<int> &rank){
     u = findPar(u,parent);
     v = findPar(v,parent);

     if (rank[u] < rank[v]){
         parent[u] =v;
     }
     else if(rank[u] > rank[v]){
           parent[v] =u;
     }
     else{
         parent[v] = u;
         rank[u] ++;
     }
}

int main() {
    int v, e;
    cout << "Enter the value of nodes / vertices " << endl;
    cin >> v;
  
    cout << "Enter the value of edges" << endl;
    cin >> e;
   
    vector<node> edges;
    cout << "Enter the edges"<<endl;
    for(int i = 0; i<e; i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u,v,wt));
    }

    // sorting the edges graph using a self comparator
    sort(edges.begin(),edges.end(),comp);

    //declaring the parent array and the rank array
    // declaring the nodes itself as parent
    vector <int> parent(v);
    for(int i=0; i<v; i++){
        parent[i] = i;
    }
    vector <int> rank(v,0);

    int cost = 0;
    vector<pair<int,int>> mst;
    for(auto it:edges){
        if(findPar(it.v,parent) != findPar(it.u,parent)){
            cost += it.wt;
            mst.push_back({it.u,it.v});
            unionn(it.u, it.v, parent,rank);
        }
    }
    
    cout <<"The  minimum spanning tree is --> " <<endl;
    for(auto it: mst){
        cout <<"The edge "<<it.first<<"-"<<it.second<<endl;
    }
    cout <<"The cost of the minimum spanning tree is --> "<<cost <<endl;


     return 0;
}

