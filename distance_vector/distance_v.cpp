#include <stdio.h>
#include <stdlib.h>

struct node {
    unsigned dist[20];
    unsigned from[20];
} rt[10];

int main() {
    int costmat[20][20];
    int nodes, i, j, k;
    
    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);
    
    printf("Enter the cost matrix:\n");
    for(i = 0; i < nodes; i++) {
        for(j = 0; j < nodes; j++) {
            scanf("%d", &costmat[i][j]);
            costmat[i][i] = 0; // Distance to self is zero
            rt[i].dist[j] = costmat[i][j];
            rt[i].from[j] = j;
        }
    }
    
    for(i = 0; i < nodes; i++) {
        for(j = 0; j < nodes; j++) {
            for(k = 0; k < nodes; k++) {
                if (rt[i].dist[j] > costmat[i][k] + rt[k].dist[j]) {
                    rt[i].dist[j] = costmat[i][k] + rt[k].dist[j];
                    rt[i].from[j] = k;
                }
            }
        }
    }
    
    for(i = 0; i < nodes; i++) {
        printf("\n\nFor router %d\n", i + 1);
        for(j = 0; j < nodes; j++) {
            printf("node %d via %d distance %d\n", j + 1, rt[i].from[j] + 1, rt[i].dist[j]);
        }
    }
    
    return 0;
}
