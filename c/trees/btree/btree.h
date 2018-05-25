#ifndef _BTREE_H_

#include <stdlib.h>

typedef struct btreenode BTreeNode;
typedef int (*BTreeForEach)(BTreeNode *node, const void *udata);

BTreeNode *BTree_NewNode(const void *data, size_t dataSize);
BTreeNode *BTree_InsertLeft(BTreeNode *root, const void *data, size_t dataSize);
BTreeNode *BTree_InsertRight(BTreeNode *root, const void *data, size_t dataSize);

void *BTree_GetData(BTreeNode *node);
int BTree_GetDataInt(BTreeNode *node);
void BTree_PrintPreorderInt(BTreeNode *root);
void BTree_PrintInorderInt(BTreeNode *root);
void BTree_PrintPostorderInt(BTreeNode *root);
int BTree_DFS_Preorder(BTreeNode *root, BTreeForEach cb, const void *udata);
int BTree_DFS_Inorder(BTreeNode *root, BTreeForEach cb, const void *udata);
int BTree_DFS_Postorder(BTreeNode *root, BTreeForEach cb, const void *udata);

#endif // !_BTREE_H_
