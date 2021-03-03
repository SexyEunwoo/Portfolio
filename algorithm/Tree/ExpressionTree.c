#include "ExpressionTree.h"

int main(void)
{
    TreeNode* ndA = make_tree_node();
    TreeNode* ndB = make_tree_node();
    TreeNode* ndC = make_tree_node();
    TreeNode* ndD = make_tree_node();
    TreeNode* ndE = make_tree_node();
    TreeNode* ndF = make_tree_node();
    TreeNode* ndG = make_tree_node();

    set_data(ndA, '-');
    set_data(ndB, '+');
    set_data(ndC, 1);
    set_data(ndD, 7);
    set_data(ndE, '*');
    set_data(ndF, 4);
    set_data(ndG, 2);

    make_left_sub_tree(ndA, ndB);
    make_right_sub_tree(ndA, ndC);
    make_left_sub_tree(ndB, ndD);
    make_right_sub_tree(ndB, ndE);
    make_left_sub_tree(ndE, ndF);
    make_right_sub_tree(ndE, ndG);

    printf("calc : %d \n", calc(ndA));

    return 0;
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

void preorder_traverse(TreeNode* _pRootNode)
{
    printf("[%d] ", _pRootNode->data.num);
    if(_pRootNode->left != NULL)
    {
        preorder_traverse(_pRootNode->left);
    }
    if(_pRootNode->right != NULL)
    {
        preorder_traverse(_pRootNode->right);
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

int calc(TreeNode* _pRootNode)
{
    int num1 = 0, num2 = 0;
    if(is_operator(_pRootNode->left->data.num))
    {
        num1 = calc(_pRootNode->left);
    }
    else
    {
        num1 = _pRootNode->left->data.num;
    }
    if(is_operator(_pRootNode->right->data.num))
    {
        num2 = calc(_pRootNode->right);
    }
    else
    {
        num2 = _pRootNode->right->data.num;
    }

    return operate(_pRootNode->data.num, num1, num2);
}

int is_operator(int ch)
{
    int ret = 0;
    switch(ch)
    {
        case '+':
        case '-':
        case '*':
        case '/':
            ret = 1;
            break;
        default:
            ret = 0;
            break;
    }

    return ret;
}

int operate(int _operator, int _num1, int _num2)
{
    int ret = 0;

    switch (_operator)
    {
        case '+':
            ret = _num1 + _num2;
            break;
        case '-':
            ret = _num1 - _num2;
            break;
        case '*':
            ret = _num1 * _num2;
            break;
        case '/':
            ret = _num1 / _num2;
            break;
    }

    return ret;
}