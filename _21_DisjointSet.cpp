// Disjoint set data structures
// It is used in  kruskal algorithm, to find the minimum spanning tree
// It is used to tell, whether two nodes of a graph belong to the same component or not.
// It will provide us with two different operations --> findPar() and Union() operations
// Union() combine two nodes into a single component,(we can declare one of them as parent)
// We can declare a parent node for a particular component
// To know if two node belong to the same component, we can find the parent, if their parent is same,we can say that,they belong to the same component, and vice-versa

// The efficient implementation of disjoint set data structure is done by union by rank and path compression method
// Union by rank :-
// Path Compresssion :-

// Union by rank :-lower rank guy gets attached to the higher rank guy, and if they are similar rank we will increase the rank of parent by 1
// We will maintain a rank array, Initially each node will be its own parent, before union, therefore the array will be initialized with 0; 
// in this case we can attach 1st node to 2nd or 2nd to 1st and make one of them parent; 
// If we are attaching nodes with same rank, the node to whom we make as the parent ,we will increase its rank by 1
// whenever connecting the 3rd to our component, we will always try to attach it to the parent node directly and not to the other node
// in other words, the node with smaller rank will be attached to the node with higher rank(we are doing this because the tree would get elongated)
// we will increase the rank value, only when we are attaching two nodes of similar rank, because the height of the tree is being increased

// Path Compresssion :-when the height of the tree is more than 1, and we have to attach a node to the leaf node, firstly we will find the parent of the leaf node and then directly attach that element  to the parent , it is path compression to not increase the height of the tree
// It allows us to minimize the number of movements,while finding the findPar() for a node

// Time complexity :- O(1) constant time for any operatons
// Space Complexity :- O(N) , for rank array



//program or syntax of disjoint set
// I have commented the below program, as it is just for the purpose of syntax writing and understanding the disjoint set(the below program may show errors)

// #include <bits/stdc++.h>

// using namespace std;

// int parent[100000];
// int rank[100000];

// //making each component its own parent
// void makeSet(){
//     for(int i=1; i<=n; i++){
//         parent[i] = i;
//         rank[i] = 0;
//     }
// }


// // 7 --> 6 --> 4 --> 3
// //how to find the node of the parent
// int findPar(int node){
//     if (node == parent[node]){
//         return node;
//     }
//     // return findPar(parent[node]); wihtout path compression
//     return parent[node]=findPar(parent[node]); // with path compression
// }

//  //union of the ndoes
//  void union( int u, int v){
//      u = findPar(u);
//      v = findPar(v);

//      if (rank[u] < rank[v]){
//          parent[u] =v;
//      }
//      else if(rank[u] > rank[v]){
//            parent[v] =u;
//      }
//      else{
//          parent[v] = u;
//          rank[u] ++;
//      }

//  }


// void  main() {
//     makeSet();
//     int n;
//     cin >> n;
//     while(n--){
//         int u, v;
//         union(u,v);
//     }
//     // if 2 and 3 belong to the same component or not
//     if(findPar(2) != findPar(3)){
//         cout << "They belong to the different component";
//     }
//     else{
//         cout <<"They belong to the same component";
//     }


//      return 0;
// }

