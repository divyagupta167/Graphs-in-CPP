//Graph representation
//It is representated using edges and nodes
//Two types- Adjacency amtrix and Adjacency  list

// Adjacency matrix
// Firstly count the number of nodes and edges
// Create a list of all the edges  with nodes name(node1(u) and node2(v))
// Check if the graph is 1 based indexing or 0 based indexing
// If it is 1 based with 5 nodes then we create 6x6 (m1 x m2) matrix or 2D array
// m1 is row and m2 is column
// if  a edge is present betweeen the nodes then fill in the matrix with 1 and if not then 0, using (node1 as row number and node2 as column number)
//eg. adjacency [u][v]=1
//eg. adjacency [v][u]=1

//Disadvantages
// we can only use matrix representation  in case of smaller values of vertices or nodes
// Space complesity will be ( N ^ 2,N square)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v, e;
    cout << "Enter the value of nodes / vertices " << endl;
    cin >> v;
  
    cout << "Enter the value of edges" << endl;
    cin >> e;
   

    //declare the adjacent amtrix
    int adj[v + 1][v + 1];

    //declaring every element as 0
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            adj[i][j] = 0;
        }
    }

    //taking edge as input and marking adjacency as 1
    cout << "Enter the edges" << endl;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    cout << "The adjacency matrix is --> \n";
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            cout << adj[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;
}