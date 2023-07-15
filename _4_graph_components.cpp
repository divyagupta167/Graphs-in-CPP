//Connected components in a graph
//Graph can be disconnected, but all the components combine  to form a single graph
//Graph may have multiple component
// A single node may also be called a component of the graph

// There are two types of traversal techniques  of  graph
// BFS(Breadth for Search) and DFS(Depth for Search) 

//We have to write BFS and DFS for multiple components of graph, and this can be achieved using a visited array
//The size  of the visited array will be equal to number of the nodes of the graph, and it will be initialized with 0
//int visited_arrray [];
//for (int i=1; i<=n; i++)
//  {
//      if( !visited[i])
//          {
//           bfs()
//           dfs()
//          }
//  }