#include <bits/stdc++.h>

using namespace std;

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
    { char a = 64 +i;
        cout << a << " --> ";
        for (int j = 0; j < g[i].size(); j++)
        { char b = 64 + g[i][j] ;
            cout << b << " ";
        }
        cout << endl;
    }

    return 0;
}