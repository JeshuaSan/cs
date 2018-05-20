#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "btree/btree.h"
#include "graph/graph.h"

static void btree__test();
static void graph__test1();
static int testgraph__find_conection(const char *label, void *data, void *udata);

int main()
{
    btree__test();
    graph__test1();
    getchar();
    return 0;
}

static void btree__test()
{
    int i = 0;
    int val[] = { 50, 30, 20, 10, 40, 80, 70, 60, 90, 85, 100 };
    BTreeNode *btree = BTree_NewNode(&val[0], sizeof(int));
    BTreeNode *n1 = BTree_InsertLeft(btree, &val[1], sizeof(int));
    BTreeNode *n2 = BTree_InsertLeft(n1, &val[2], sizeof(int));
    BTreeNode *n3 = BTree_InsertLeft(n2, &val[3], sizeof(int));
    BTreeNode *n4 = BTree_InsertRight(n1, &val[4], sizeof(int));
    BTreeNode *n5 = BTree_InsertLeft(n4, &val[5], sizeof(int));
    BTreeNode *n6 = BTree_InsertLeft(n5, &val[6], sizeof(int));
    BTreeNode *n7 = BTree_InsertLeft(n6, &val[7], sizeof(int));
    BTreeNode *n8 = BTree_InsertRight(n5, &val[8], sizeof(int));
    BTreeNode *n9 = BTree_InsertLeft(n8, &val[9], sizeof(int));
    BTreeNode *n10 = BTree_InsertRight(n8, &val[10], sizeof(int));
    BTree_PrintPreorderInt(btree);
}

static void graph__test1()
{
    GraphNode *a = GraphNode_New("a", NULL);
    GraphNode *b = GraphNode_New("b", NULL);
    GraphNode *c = GraphNode_New("c", NULL);
    GraphNode *d = GraphNode_New("d", NULL);
    GraphNode *e = GraphNode_New("e", NULL);
    GraphNode *f = GraphNode_New("f", NULL);
    GraphNode *g = GraphNode_New("g", NULL);
    GraphNode *h = GraphNode_New("h", NULL);
    GraphNode *start = b;
    GraphNode *end = c;

    GraphNode_AddNeighbor(a, b);
    GraphNode_AddNeighbor(b, a);
    GraphNode_AddNeighbor(b, c);
    GraphNode_AddNeighbor(c, d);
    GraphNode_AddNeighbor(c, e);
    GraphNode_AddNeighbor(c, f);
    GraphNode_AddNeighbor(e, g);
    GraphNode_AddNeighbor(g, h);

    Graph *graph = Graph_New();
    Graph_InsertNode(graph, a);
    Graph_InsertNode(graph, b);
    Graph_InsertNode(graph, c);
    Graph_InsertNode(graph, d);
    Graph_InsertNode(graph, e);
    Graph_InsertNode(graph, f);
    Graph_InsertNode(graph, g);
    Graph_InsertNode(graph, h);

    printf("Graph test ... \n");
    printf("Print adjacency list ... \n");
    Graph_PrintAdjList(graph);
    printf("\n");
    printf("Print BFS from %s... \n", GraphNode_GetLabel(start));
    Graph_BFS(graph, start, Graph_Print, NULL);
    printf("\n");
    printf("Print DFS from %s... \n", GraphNode_GetLabel(start));
    Graph_DFS(graph, start, Graph_Print, NULL);
    printf("\n");
    int completed = Graph_BFS(graph, start, testgraph__find_conection, end);
    if (completed)
    {
        printf("No connection found  between %s and %s", GraphNode_GetLabel(start), GraphNode_GetLabel(end));
    }

}

static int testgraph__find_conection(GraphNode *node, void *udata)
{
    char *l1 = GraphNode_GetLabel(node);
    char *l2 = GraphNode_GetLabel((GraphNode *)udata);
    if(0 == strcmp(l1, l2))
    {
        printf("%s <---> %s", l1, l2);
        return 1;
    }
    return 0;
}