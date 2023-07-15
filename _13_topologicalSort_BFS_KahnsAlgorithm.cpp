// Topological sort uisng BFS Kanh's Algorithm
// Linear ordering of vertices such that if there is an edge u-->v, u appears before v in that ordering.
// There can be multiple topo sort for a given graph
// DAG --> directed acyclic graph, only in DAG topo sort is possible

// here we will use bfs algorithm to get topo sort
// store the graph in adjacency list
// create a  array with value of indegree, for each node(indegree = no. of nodes coming to it)
// we need a queue data structure FIFO
// insert the nodes with indegree as 0 (zero) into the queue
// now simply apply the bfs algorithm on the front element of the queue
// this front element will also be a part of our topo sort
// check for its adjacent nodes, and reduce the indegree of the adjacent by 1 in the array
// now check in the array if any of the nodes has indegree as 0, if not present go for next element of the queue, before that we can pop the front element from the queue
// repeat the same process
// we wil get the next 0 nodes and put it in the stack, repeat the process

// The logic behind kanh's algorithm is , if an element which has indegree as 0 means that no edge is coming before it.
// and  we are putting it in the queue, checking for the adjacent nodes, reducing the indegree, if 0 indegree and putting it in the queue. Once the nodes will have no adjacent nodes, We will move on to the next front element of the queue

//Time Complexity O(N+E)
//Space Complexity O(N)+O(N)

#include <bits/stdc++.h>

using namespace std;
class solution
{
public:
    vector<int> topoSort(int N, vector<int> g[])
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

        vector<int> topo; // creating a vector topo to store the elements
        while (!q.empty()) // the loop will run untill the queue is empty
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for (auto it : g[node]) //traversing through all the adjacent nodes and decreasing their indegree value
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it); // inserting the element with indegree 0 in the queue
                }
            }
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
