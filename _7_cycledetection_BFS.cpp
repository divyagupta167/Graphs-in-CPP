// cycle detection in undirected graph using BFS
// if a component of a graph has a cycle then , we can say that the graph has a cycle
//Steps
// Create a adjacency list
// Create a visited array and mark it as  0
// run a for loop in the main function, to call bfs for every node (not visited)of a graph(the graph  may have multiple  components)
//call the function cycle bfs for that not visited node

//modification in the bfs algorithm to turn it in cycle detection
//If any of the adjacent nodes have been visited previously then there is a cycle
//we will modified the queue
// we will put the node along with its parent in the queue
//we wil take a starting node , it will never have a parent, then put node  in the queue, and mark it visited in the array
//now check for adjacent nodes, and put the adjacent nodes along with parent nodes in the queue, and mark them visited and before that pop the parent node out
// now check for  adjacent  nodes of the 2nd node entered, if not visited, repeat the same process of storing in queue, marking visited ,poping out, and again checking for adjacent nodes
//NOTE: If the adjacent node which is visted by some other node that is ,it is not the parent node of current node, then we can say that there is a cycle
//Time complexity will be O( N+E), approx O(N), and Space complexity will be(O( N+E)+O(N)+o(N))
//N is time taken for visiting N nodes, and E is for travelling through adjacent  nodes overall space for adj list, vis array and queue

#include<bits/stdc++.h>

using namespace std;

class Solution
{

public:
    bool checkForCycle(int s, int V, vector<int> adj[], vector<int> &visited)
    {
        vector<int> parent(V, -1);

        // Create a queue for BFS
        queue<pair<int, int>> q;

        visited[s] = true;
        q.push({s, -1});

        while (!q.empty())
        {

            int node = q.front().first;
            int par = q.front().second;
            q.pop();

            for (auto it : adj[node])
            {
                if (!visited[it])
                {
                    visited[it] = true;
                    q.push({it, node});
                }
                else if (par != it)
                    return true;
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> g[])
    {
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (checkForCycle(i, V, g, vis))
                    return true;
            }
        }

        return false;
    }
};

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
    Solution obj;
    bool ans = obj.isCycle(v, g);
    if (ans)
        cout << "It has cycle\n";
    else
        cout << "It does not have cycle\n";
    return 0;
}