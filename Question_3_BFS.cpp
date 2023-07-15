#include <bits/stdc++.h>

using namespace std;
class solution
{
public:
    vector<int> bfsOfGraph(int V, vector<int> g[])
    {
        vector<int> bfs;
        vector<int> vis(V + 1, 0);

        for (int i = 0; i < V; i++)
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
       
    }

    cout << endl;
    cout << "The adjacency list is --> \n";
    for (int i = 1; i <= v; i++)
    {
        
        cout << i << " --> ";
        for (int j = 0; j < g[i].size(); j++)
        {
            
            cout <<  g[i][j]<< " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "The required BFS is -->" << endl;
    solution obj;
    vector<int> ans = obj.bfsOfGraph(v, g);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}