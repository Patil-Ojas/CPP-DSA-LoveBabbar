
// graphs has nodes and edges
// node ->entity to storre
// edge -> connects nodes

// two types - cyclic and acyclic
//           - directed and undirected(or bidirected)

// degree -> no of connected egdes to the node (undirected)
// indegree -> edges coming inside (directed)
// outdegree -> opposite (directed)

// weighted graph 
// when unweighted graph, we assume all weights to be one

// path - nodes travelled from source to destination

// cyclic graph - nodes form a cycle yes
// type can be as crazy as weighted cyclic directed graph

// acyclic - nodes form a acycle

// to implement a graph we have options -> Adjacency matrix SC , - O(n^2) , (we create a matrix)
//                                      -> Adjacency list , O() , (each node has its own list, we can use map<int, list<int>> or vectors                                                            also can be used)