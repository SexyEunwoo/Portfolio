#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

int main(void)
{
    TreeNode* ndA = make_tree_node();
    TreeNode* ndB = make_tree_node();
    TreeNode* ndC = make_tree_node();
    TreeNode* ndD = make_tree_node();

    set_data(ndA, 1);
    set_data(ndB, 2);
    set_data(ndC, 3);
    set_data(ndD, 4);

    make_left_sub_tree(ndA, ndB);
    make_right_sub_tree(ndA, ndC);
    make_left_sub_tree(ndB, ndD);

    // 전위순회
    printf("preorder ");
    preorder_traverse(ndA, test_func);
    printf("\n");

    // 중위순회
    printf("inorder ");
    inorder_traverse(ndA);
    printf("\n");

    // 후위순회
    printf("postorder ");
    postorder_traverse(ndA);
    printf("\n");
    

    printf("\n");
    free_node(ndA);
}

TreeNode* make_tree_node(void)
{
    TreeNode* pNode = (TreeNode*)malloc(sizeof(struct _STreeNode));
    pNode->left = NULL;
    pNode->right = NULL;

    return pNode;
}

TreeData get_data(TreeNode* _pRootNode)
{
    return _pRootNode->data;
}

void set_data(TreeNode* _pRootNode, int _data)
{
    _pRootNode->data.num = _data;
}

// void set_data(TreeNode* _pRootNode, TreeData _treeData)
// {
//     _pRootNode->data = _treeData;
// }

TreeNode* get_left_sub_tree(TreeNode* _pRootNode)
{
    return _pRootNode->left;
}

TreeNode* get_right_sub_tree(TreeNode* _pRootNode)
{
    return _pRootNode->right;
}

void make_left_sub_tree(TreeNode* _pRootNode, TreeNode* _pLeftNode)
{
    if(_pRootNode->left != NULL)
    {
        free_node(_pRootNode->left);
    }
    _pRootNode->left = _pLeftNode;
}
void make_right_sub_tree(TreeNode* _pRootNode, TreeNode* _pRightNode)
{
    if(_pRootNode->right != NULL)
    {
        free_node(_pRootNode->right);
    }
    _pRootNode->right = _pRightNode;
}

void free_node(TreeNode* _pRootNode)
{
    if(_pRootNode->left != NULL)
    {
        free_node(_pRootNode->left);
    }
    if(_pRootNode->right != NULL)
    {
        free_node(_pRootNode->right);
    }

    printf("[%d] data freed \n", _pRootNode->data.num);

    free(_pRootNode);
}

void preorder_traverse(TreeNode* _pRootNode, visitFuncPtr action)
{
    // printf("[%d] ", _pRootNode->data.num);
    action(_pRootNode->data.num);
    if(_pRootNode->left != NULL)
    {
        preorder_traverse(_pRootNode->left, action);
    }
    if(_pRootNode->right != NULL)
    {
        preorder_traverse(_pRootNode->right, action);
    }
}

void inorder_traverse(TreeNode* _pRootNode)
{
    if(_pRootNode->left != NULL)
    {
        inorder_traverse(_pRootNode->left);
    }
    printf("[%d] ", _pRootNode->data.num);
    if(_pRootNode->right != NULL)
    {
        inorder_traverse(_pRootNode->right);
    }
}

void postorder_traverse(TreeNode* _pRootNode)
{
    if(_pRootNode->left != NULL)
    {
        postorder_traverse(_pRootNode->left);
    }
    if(_pRootNode->right != NULL)
    {
        postorder_traverse(_pRootNode->right);
    }
    printf("[%d] ", _pRootNode->data.num);
}

void test_func(int num)
{
    printf("test_func : %d ", num);
}