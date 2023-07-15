//Breadth for Search
//Steps:-
//Firstly create a adjacency list of the list and store it
//Now take a  visited array(size equal to the number of nodes of the graph)and mark it as 0 for each index
//The graph may be  disconnected , so we will take a for loop to check for the visited and non visited index elements
// We then take a queue  and insert the starting node in queue, and mark it visited in the array
//We have to iterate untill the queue is not empty
//Store the top element of the queue in a variable node, and pop it out from the queue
//now check for the adjacent nodes of the variable node from the adjacent list, and push it in the stack
//now mark visited for the next node int the array, store it in a variable node, pop it out, and again check for adjacent nodes in the adjacency list and repeat the process
//Time complexity will be O( N+E), approx O(N), and Space complexity will be(O( N+E)+O(N)+o(N))
//N is time taken for visiting N nodes, and E is for travelling through adjacent  nodes overall space for adj list, vis array and queue

#include <bits/stdc++.h>

using namespace std;
class solution
{
public:
    vector<int> bfsOfGraph(int V, vector<int> g[])
    {
        vector<int> bfs;
        vector<int> vis(V + 1, 0);

        for (int i = 1; i <= V; i++)
        {
            if (!vis[i])
            {
                queue<int> q;
                q.push(i);
                vis[i] = 1;
                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    bfs.push_back(node);

                    for (auto it : g[node])
                    {
                        if (!vis[it])
                        {
                            q.push(it);
                            vis[it] = 1;
                        }
                    }
                }
            }
        }

        return bfs;
    }
};

int main()
{
    cout << endl;
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

    cout << endl;
    cout << "The adjacency list is --> \n";
    for (int i = 1; i <= v; i++)
    {
        // char a = 64 + i;
        cout << i << " --> ";
        for (int j = 0; j < g[i].size(); j++)
        {
            // char b = 64 + g[i][j];
            cout <<  g[i][j]<< " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "The bfs is -->" << endl;
    solution obj;
    vector<int> ans = obj.bfsOfGraph(v, g);
    for (int i = 0; i < ans.size(); i++)
    {
        // char str = 64 + ans[i];
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}