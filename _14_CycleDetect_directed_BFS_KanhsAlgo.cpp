//Kahns Algorithm is possible for only , DAG, hence we can use reverse logic to check for cycle in a graph
// we just have to use a count variable to check for , if every element has been pushed into the queue or not

#include <bits/stdc++.h>

using namespace std;


class solution
{
public:
    bool isCyclic(int N, vector<int> g[])
    {
        queue<int> q;
        vector<int> indegree(N, 0);

        // finding out the indegree
        for (int i = 0; i < N; i++)
        {
            for (auto it : g[i])
            {
                indegree[it]++;
            }
        }

        // putting the elements with indegree with 0 in the queue
        for (int i = 0; i < N; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // while the queue is not empty,the process of taking the front element,poping out from the queue,and pushing it in topo vector
        // next checking for its adjacent nodes, decreasing the indegree and if it is 0, pushing it in the queue

        int count = 0;    // creating a vector topo to store the elements
        while (!q.empty()) // the loop will run untill the queue is empty
        {
            int node = q.front();
            q.pop();
            count++;
            for (auto it : g[node]) //traversing through all the adjacent nodes and decreasing their indegree value
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it); // inserting the element with indegree 0 in the queue
                }
            }
        }

        // if topo sort posssible,graph is acyclic, return false, or else return true
        if (count == N)
            return false;
        return true;
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
    solution obj;
    bool ans = obj.isCyclic(v, g);
    if (ans)
        cout << "It has cycle\n";
    else
        cout << "It does not have cycle\n";

    return 0;
}
