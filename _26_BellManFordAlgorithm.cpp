// Shortest path algorithm for negative edges
// negative edges could not be applicable for dijkstras because when finding adjacent nodes, the negative edges will create a infinite loop, that is the edges will be reduced everytime,when looking for adjacent nodes
// But bellmanford algo works fine for negtive edges

// With the help of belllmanford, we can detect a negative cycle, as it does not work for  negative cycle

// But it has  conditons-->
// 1.The graph should be directed
// 2.And it should have negative/positive edges
// 3.It can never have a negative cycle

// It will work for undirected graph also, but we have to convert the undirected graph to directed graph
// Incase if we have a negative edge in undirected graph,when we turn it to directed, bellman ford will detect a negative cycle and it will not work for it

//Therefore we conclude, bellman ford works for
//1.Directed graph : for negative as well as positive edges
//2.Undirected : convert it to directed using bidirectional edges, if a negative cycle is formed, the algo fails

// Bellman ford algorithm :-
// It states that, whatever edges is given to you, be it in any order, and then relax all the edges N-1 times exactly,
// Relaxation formula :- if(dist[u] + wt < dist[v]){
//                             dist[v] = dist[u] + wt
//                                  }
// firstly create a distance array, equal to the number of nodes, initialize it with infinity, except for the 0th index
// eg if n=6, then we have to relax every edge exaclty 5 time

// whenever we get shorter edge, after relaxation, we will replace it in the distance array, after repeating for n-1 times, the distance array will give us the shortest path from the source to the node

// To detect a negative cycle, we will run the relaxation for 1 more time, and we will see that the shortest distance has reduced again and hence we see that there is a negative  cycle
// Because the bellman ford algo states that, whatever distance array, we have got after n-1 relaxation , it is the shortest possible path

// Intuition behind the Algorithm
// Why are we having only n-1 times relaxation not more than that or less than that ??
// It is for the reason that, eg. for 5 nodes, the longest possible distance from the source will be n-1 always that is 4 edges max
// a b c d e be the 5 nodes
// a-b, b-c, c-d, d-e, be the 4 edges  we will be requiring max 4 relaxation for each node to be relaxed

// Time Complexity :- O(N-1) x O(E) not good but works for negative edges
// Space Complexity :- O(N) distance array

#include <bits/stdc++.h>

using namespace std;

struct node
{
    int u;
    int v;
    int wt;
    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

int main()
{
    int v, e;
    cout << "Enter the value of nodes / vertices " << endl;
    cin >> v;

    cout << "Enter the value of edges" << endl;
    cin >> e;

    vector<node> edges;
    cout << "Enter the edges" << endl;
    for (int i = 0; i < e; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }

    cout << endl;
    cout << "Enter the source node \n";
    int src;
    cin >> src;

    int inf = 100000000;
    vector<int> dist(v, inf);

    dist[src] = 0;

    for (int i = 1; i < v - 1; i++)
    {
        for (auto it : edges)
        {
            if (dist[it.u] + it.wt < dist[it.v])
            {
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }

    int flag = 0;
    for (auto it : edges)
    {
        if (dist[it.u] + it.wt < dist[it.v])
        {
            cout << "Negative Cycle";
            flag = 1;
            break;
        }
    }
    // not 0=1 is true, and not 1=0 is false, here if true we wil print the edges
    if (!flag)
    {
        for (int i = 0; i < v; i++)
        {
            cout << "The shortest distance from the source " << src << " to node " << i << " is " << dist[i] << endl;
        }
    }

    return 0;
}
