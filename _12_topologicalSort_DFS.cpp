// Topological sort
// Linear ordering of vertices such that if there is an edge u-->v, u appears before v in that ordering.
//there can be multiple topo sort for a given graph
//DAG --> directed acyclic graph, only in DAG topo sort is possible

// here we will use dfs for topo sort
// store the  graph in adjacency list
// run a for loop to call dfs for each node
// we need a stack and a visited array
// start from a node 0, to call for a dfs, mark it as visited and also put it in the stack, then check for adjacent       nodes, if present then repeat the same process or else return
// now the for loop will call dfs for another node, and the process will repeat
// we will not call a dfs for a visited node
// at last when we pop out the elements from the stack, it will give us the respective topo sort

// Time complexity O(N+E)
// Space complexity O(N)+O(N)
// auxillary space complexity O(N)

#include <bits/stdc++.h>

using namespace std;

class solution
{
    void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> g[])
    {
        vis[node] = 1;
        for (auto it : g[node])
        {
            if (!vis[it])
            {
                findTopoSort(it, vis, st, g);
            }
        }
        st.push(node);
    }

public:
    vector<int> topoSort(int N, vector<int> g[])
    {
        stack<int> st;
        vector<int> vis(N, 0);
        for (int i = 0; i < N; i++)
        {
            if (vis[i] == 0)
            {
                findTopoSort(i, vis, st, g);
            }
        }
        vector<int> topo;
        while (!st.empty())
        {
            topo.push_back(st.top());
            st.pop();
        }

        return topo;
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

    cout << endl;
    cout << "The Topological sort is -->" << endl;
    solution obj;
    vector<int> ans = obj.topoSort(v, g);
    for (int i = 0; i < ans.size(); i++)
    {
        // char str = 64 + ans[i];
        cout << ans[i] << " ";
    }

    cout << endl;


    return 0;
}