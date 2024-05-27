
# Distance Vector Algorithm for Routing

## Aim

To find a suitable path for transmission using the distance vector algorithm.

## Theory

The distance vector algorithm, also known as the Bellman-Ford algorithm, is used in network routing to find the shortest path from a source node to all other nodes in a weighted graph. Each router maintains a routing table that contains the best known distance to each destination and the next hop to reach that destination. These tables are updated by exchanging information with neighboring routers.

### Types of Routing Algorithms

- **Adaptive Algorithms:** Change their routing decisions based on changes in network topology and traffic.
- **Non-Adaptive Algorithms:** Do not change routing decisions based on current network conditions. Routes are computed in advance and downloaded to routers.

### Distance Vector Routing

- Each router maintains a table indexed by, and containing one entry for, each router in the subnet.
- The entry contains two parts: the preferred outgoing line and an estimate of the distance to the destination.
- The algorithm updates these tables by exchanging information with neighboring routers.

## Implementation

1. **Struct Definition:**

   ```c
   struct node {
       unsigned dist[20];
       unsigned from[20];
   } rt[10];
   ```

   Each router has a structure containing the distance to each destination and the next hop to reach that destination.

2. **Cost Matrix Input:**

   ```c
   int costmat[20][20];
   int nodes, i, j, k, count=0;
   printf("\n Enter the no of nodes:");
   scanf("%d", &nodes);
   printf("\n Enter the cost matrix:\n");
   for(i=0;i<nodes;i++) {
       for(j=0;j<nodes;j++) {
           scanf("%d",&costmat[i][j]);
           costmat[i][i]=0; // Distance to itself is always 0
           rt[i].dist[j]=costmat[i][j];
           rt[i].from[j]=j;
       }
   }
   ```

   The cost matrix represents the direct link costs between each pair of nodes. The distance from a node to itself is set to zero.

3. **Distance Vector Algorithm:**

   ```c
   for(i=0;i<nodes;i++) {
       for(j=0;j<nodes;j++) {
           for(k=0;k<nodes;k++) {
               if (rt[i].dist[j] > costmat[i][k] + rt[k].dist[j]) {
                   rt[i].dist[j] = costmat[i][k] + rt[k].dist[j];
                   rt[i].from[j] = k;
               }
           }
       }
   }
   ```

   This nested loop checks if a shorter path exists via an intermediate node `k` and updates the distance and next hop accordingly.

4. **Output the Routing Tables:**

   ```c
   for(i=0;i<nodes;i++) {
       printf("\n\n For router %d \n",i+1);
       for(j=0;j<nodes;j++) {
           printf("\t \n node %d via %d distance %d",j+1,rt[i].from[j]+1,rt[i].dist[j]);
       }
   }
   printf("\n\n");
   ```

   This loop prints the routing table for each router.

### Explanation

1. **Struct Definition:**

   - `struct node` stores the distance to each destination and the next hop for each router.
   - `rt` is an array of such structures, one for each router.

2. **Main Function:**
   - **Input Handling:**
     - The user inputs the number of nodes.
     - The cost matrix, representing direct link costs between nodes, is entered by the user.
     - Distance to the same node is set to zero.
     - Each node's distance vector is initialized to the direct costs from the cost matrix, and the next hop is set to the destination itself.

   - **Distance Vector Algorithm:**
     - Iteratively updates the distance vector. For each node pair `(i, j)`, it checks if a shorter path exists via an intermediate node `k`. If a shorter path is found, the distance and next hop are updated accordingly.

   - **Output:**
     - Prints the routing table for each node, showing the shortest path to every other node and the next hop to reach that path.

## Usage

1. **Compile the Program:**
   - Use any compatible C++ compiler to compile the code.

2. **Run the Program:**
   - Execute the compiled program.
   - Input the number of nodes and the cost matrix when prompted.

3. **View Output:**
   - The program will output the routing tables for each router, showing the shortest paths and next hops.

## FAQ

1. **What is a routing algorithm?**
   - A routing algorithm is used in the network layer to decide which path data packets should take to reach their destination.

2. **Explain the distance vector algorithm.**
   - The distance vector algorithm maintains a table of the best known distances to each destination and updates this table by exchanging information with neighboring routers.

3. **What are the differences between adaptive and non-adaptive routing algorithms?**
   - Non-adaptive (static) routing algorithms do not change routing decisions based on current network conditions. Adaptive (dynamic) routing algorithms adjust their decisions based on changes in the network's topology and traffic.

4. **What is the purpose of the cost matrix?**
   - The cost matrix represents the direct link costs between nodes in a network, used as the initial setup for the distance vector algorithm.

5. **Why do we set the distance to the same node to zero in the cost matrix?**
   - Because the distance from a node to itself is always zero.

## Conclusion

This implementation of the distance vector algorithm provides a simple and efficient way to determine the shortest paths in a network. By understanding and experimenting with this code, one can gain a deeper insight into network routing algorithms and their practical applications.

---

Feel free to use and modify this code for your academic and learning purposes. Contributions and suggestions are welcome!
