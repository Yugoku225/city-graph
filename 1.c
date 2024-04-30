#include<stdio.h>
#include<stdlib.h>

struct node {
    char *vertex;
    int weight ;
    struct node *next; 
};

struct graph {
    int numV;
    struct node ** adlist;
};

struct node *create_adj_node(char *city, int distance)
{
    struct node *adj_node = (struct node*)malloc(sizeof(struct node));
    if(adj_node == NULL)
    {
        printf("memory allocation failed");
    }
    adj_node->vertex = city;
    adj_node->weight = distance;
    adj_node->next = NULL;
    return adj_node;
}

struct graph *create_graph(int v)
{
    struct graph *Graph = (struct graph*)malloc(sizeof(struct graph));
    Graph->numV = v;
    Graph->adlist = (struct node**)malloc(sizeof(struct node)*v);
    for(int i = 0; i<v ; i++)
    {
        Graph->adlist[i] = NULL;
    }

    return Graph;
}

 int add_edge( struct graph *Graph ,char * vertex, int distance, int src , int dst)
 {
    struct node *n = malloc(sizeof(struct node));
    n->vertex = vertex;
    n->weight = distance;
    n->next = Graph->adlist[src];
    Graph->adlist[src] = n;

    struct node *n = malloc(sizeof(struct node));
    n->vertex = vertex;
    n->weight = distance;
    n->next = Graph->adlist[dst];
    Graph->adlist[dst] = n;
 } 

 void print_graph(struct graph *Graph)
 {
    for(int i = 0; i < Graph->numV; i++)
    {
        struct node* temp = Graph->adlist[i];
        printf("\n Adjacency list of vertex %d\n head", i);
        while(temp)
        {
            printf("-> %c", temp->vertex);
            printf("%d",temp->weight );
            temp = temp->next;
        }
    }
 }

 int main()
 {
    struct graph *Graph = create_graph(5);
    add_edge(Graph , "delhi" , 100 ,0 , 1);
    add_edge(Graph, "mumbai",150, 0 , 2);
    add_edge(Graph, "dehradoon", 340, 0 , 3);
    add_edge(Graph, "kanpur",210,1 , 2);
    add_edge(Graph, "lucknow",530,2 , 3);
    add_edge(Graph, "patna",670,3 , 4);

    print_graph(Graph);
    
 }