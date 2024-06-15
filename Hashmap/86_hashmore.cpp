// LL -> O(n)
// BST / map -> O(logn)
// thus we introduce hashmap

// bucket array -> <Key, value>

// hash function -> hash code (accepts any data type, converts to int) 
//                  also responsible for uniform distribution
//               -> compression function (whatever int we recieved, 
//                  bringing that in the particular range of 0, size-1)

// collision -> when "babbar" and "bbabar" give same output index, we encounter collision
// handling  -> open hashing and closed addressing

// open hashing -> at point of collision, there is a head present in block, and all entries get stored
//              -> also called separate chaining, works pretty nice cuz of advanced algo

// closed addressing -> if collision, finds the next position using a function [H(a) = h(a) + f(a)]
//                   -> some types are - Linear Probing [f(i)=i]
//                                     - Quadratic Probing [f(i)=i^2]

// load factor (no of entires available) = no of entries(n) / no of boxes available(b)
// always ensure for good hashing, load factor <0.7, ie we have O(1) TC.

// if n is inc, to keep tc O(1), we also need to increase b
// thus we do rehashing, ie we increase b then we hash all the entires once again

// all of the above of insertion also implies for deletion and sorting
// thus we have understood hashmap which given insert, delete, and sort in O(1)
