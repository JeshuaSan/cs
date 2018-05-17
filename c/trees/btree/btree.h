#ifndef _BTREE_H_

#include <stdlib.h>

typedef struct btreenode BTreeNode;
typedef int *(BTreeForEach)(const void *data, const void *userData);

BTreeNode *BTree_NewNode(const void *data, size_t dataSize);
BTreeNode *BTree_InsertLeft(BTreeNode *root, const void *data, size_t dataSize);
BTreeNode *BTree_InsertRight(BTreeNode *root, const void *data, size_t dataSize);

void *BTree_GetData(BTreeNode *node);
int BTree_GetDataInt(BTreeNode *node);
void BTree_PrintInt(BTreeNode *root);
int BTree_DFS(BTreeNode *root, BTreeForEach cb, const void *userData);

#endif // !_BTREE_H_
