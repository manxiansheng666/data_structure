#include <stdio.h>
#include "BTree.h"
#include "SeqQueue.h"

struct Node
{
    BTreeNode header;
    char v;
};

void printf_data(BTreeNode* node)
{
    if (node != NULL)
    {
        printf("%c", ((struct Node*)node)->v);
    }
}

void preorder_traversal(BTreeNode* root)
{
    if (root == NULL)
        return;
    struct Node* node = (struct Node*)root;
    printf("%c ",node->v);
    preorder_traversal(node->header.left);
    preorder_traversal(node->header.right);
}

void middleorder_traversal(BTreeNode* root)
{
    if (root == NULL)
        return;
    struct Node* node = (struct Node*)root;
    middleorder_traversal(node->header.left);
    printf("%c ", node->v);
    middleorder_traversal(node->header.right);
}

void postorder_traversal(BTreeNode* root)
{
    if (root == NULL)
        return;
    struct Node* node = (struct Node*)root;
    postorder_traversal(node->header.left);
    postorder_traversal(node->header.right);
    printf("%c ", node->v);
}

void level_traversal(BTreeNode* root)
{
    if (root == NULL)
        return;
    struct Node* node = NULL;
    SeqQueue* seq = SeqQueue_Create(20);
    SeqQueue_Append(seq,root);
    while (SeqQueue_Length(seq) != 0)
    {
        node = (struct Node*)SeqQueue_Retrieve(seq);
        printf("%c ",node->v);
        SeqQueue_Append(seq, node->header.left);
        SeqQueue_Append(seq, node->header.right);
    }
    SeqQueue_Destroy(seq);
}

void output_leaf_node(BTreeNode* root)
{
    if (root == NULL)
        return;
    struct Node* node = (struct Node*)root;
    if(node->header.left == NULL && node->header.right == NULL)
        printf("%c ", node->v);
    output_leaf_node(node->header.left);
    output_leaf_node(node->header.right);

}

int count_leaf_node(BTreeNode* root)
{
    int ret = 0;
    if (root == NULL)
        return ret;
    struct Node* node = (struct Node*)root;
    if (node->header.left == NULL && node->header.right == NULL)
        ret++;
    ret += count_leaf_node(node->header.left);
    ret += count_leaf_node(node->header.right);
    return ret;
}

int tree_height(BTreeNode* root)
{
    int ret = 0;
    if (root == NULL)
        return ret;
    int lh = tree_height(root->left);
    int rh = tree_height(root->right);
    ret = lh > rh ? lh : rh;
    ret++;
    return ret;
}

void myprint_tree(BTreeNode* root,int deep)
{
    if (root == NULL)
        return;
    struct Node* node = (struct Node*)root;
    for (int i = 0; i < deep; i++)
    {
        printf("-");
    }
    printf("%c\r\n",node->v);
    myprint_tree(root->left, deep + 1);
    myprint_tree(root->right, deep + 1);
}

void preorder_thread_tree(BTreeNode* root, BTreeNode** pre_node)
{
    if (root == NULL || pre_node == NULL)
        return;
    
    if (*pre_node != NULL)
    {
        (*pre_node)->left = root;
        *pre_node = NULL;
    }
    if (root->left == NULL)
    {
        *pre_node = root;
    }
    preorder_thread_tree(root->left, pre_node);
    preorder_thread_tree(root->right, pre_node);
}

void middleorder_thread_tree(BTreeNode* root, BTreeNode** pre_node)
{
    if (root == NULL || pre_node == NULL)
        return;
    middleorder_thread_tree(root->left, pre_node);
    root->left = *pre_node;
    if (*pre_node != NULL)
    {
        (*pre_node)->right = root;
    }
    *pre_node = root;
    middleorder_thread_tree(root->right, pre_node);
}

//删除度为1的节点
void delete_odd1(BTreeNode** root)
{
    if (root == NULL || *root == NULL)
        return;
    if (((*root)->left && (*root)->right) || (!(*root)->left) && (!(*root)->right))
    {
        delete_odd1(&(*root)->left);
        delete_odd1(&(*root)->right);
    }
    else
    {
        if ((*root)->left != NULL)
            (*root) = (*root)->left;
        else
            (*root) = (*root)->right;
        delete_odd1(root);
    }
}


int main()
{
    BTree* tree = BTree_Create();

    struct Node n1 = { {NULL, NULL}, 'A' };
    struct Node n2 = { {NULL, NULL}, 'B' };
    struct Node n3 = { {NULL, NULL}, 'C' };
    struct Node n4 = { {NULL, NULL}, 'D' };
    struct Node n5 = { {NULL, NULL}, 'E' };
    struct Node n6 = { {NULL, NULL}, 'F' };

    BTree_Insert(tree, (BTreeNode*)&n1, 0, 0, 0);
    BTree_Insert(tree, (BTreeNode*)&n2, 0x00, 1, 0);
    BTree_Insert(tree, (BTreeNode*)&n3, 0x01, 1, 0);
    BTree_Insert(tree, (BTreeNode*)&n4, 0x00, 2, 0);
    BTree_Insert(tree, (BTreeNode*)&n5, 0x02, 2, 0);
    BTree_Insert(tree, (BTreeNode*)&n6, 0x02, 3, 0);
    BTreeNode* node_buf = BTree_Root(tree);
    delete_odd1(&node_buf);

    //BTreeNode* pre_node = NULL;
    //preorder_thread_tree(BTree_Root(tree), &pre_node);
    //BTreeNode* current_node = BTree_Root(tree);
    //while (current_node != NULL)
    //{
    //    printf("%c ",((struct Node*)current_node)->v);
    //    current_node = current_node->left;
    //}

    //int height = 0;
    //height = tree_height(BTree_Root(tree));
    //printf("tree left node is %d\r\n", height);
    // myprint_tree(BTree_Root(tree),0);
 
    BTree_Display(tree, printf_data, 4, '-');
    BTree_Clear(tree);
    BTree_Destroy(tree);
	return 0;
}