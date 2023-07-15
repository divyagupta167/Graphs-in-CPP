//Depth first search
//we need to go the depth of a node then backtrack to the  unvisited nodes to completely traverse the graph
//A graph can have multiple components so we have to call dfs for each node of the component
//Steps:-
//Store the  graph in adjacency list
//Create a visited array
//If not visited call dfs,
//then mark visited for that node
// dfs is a recursive function, it will recursively call dfs for one of the nodes (which is not visited) for the starting node and the process is repeated
//Time complexity will be O( N+E), approx O(N), and Space complexity will be(O( N+E)+O(N)+o(N))
//N is time taken for visiting N nodes, and E is for travelling through adjacent  nodes overall space for adj list, vis array and auxillary space ( auxillary space  is the space which is occupied in the memory during a recursive function call, this is not the memory we manually allocate)

#include <bits/stdc++.h>
using namespace std;

class solution
{
    void dfs(int node, vector<int> &vis, vector<int> g[], vector<int> &storeDfs)
    {
        storeDfs.push_back(node);
        vis[node] = 1;
        for (auto it : g[node])
        {
            if (!vis[it])
            {
                dfs(it, vis, g, storeDfs);
            }
        }
    }

public:
    vector<int> dfsOfGraph(int V, vector<int> g[])
    {
        vector<int> storeDfs;
        vector<int> vis(V + 1, 0);
        for (int i = 1; i <= V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, g, storeDfs);
            }
        }
        return storeDfs;
    }
};

int main()
{

    cout << endl;
    int v, e;
    cout << "Enter the value of nodes / vertices " << endl;
    cin >> v;

    cout << "Enter the value of edges" << endl;
    cin >> e;

    vector<int> g[v + 1];

    cout << "Enter the edges\n";

    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        // g[v].push_back(u);
    }
    // cout << endl;
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
    // cout << endl;
    cout << endl;
    cout << "The adjacency list is --> \n";
    for (int i = 1; i <= v; i++)
    { char a = 64 +i;
        cout << a << " --> ";
        for (int j = 0; j < g[i].size(); j++)
        { char b = 64 + g[i][j] ;
            cout << b << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "The dfs is -->" << endl;
    solution obj;
    vector<int> ans = obj.dfsOfGraph(v, g);
    for (int i = 0; i < ans.size(); i++)
    {
        char str = 64 + ans[i];
        cout << str << " ";
    }

    cout << endl;

    return 0;
}