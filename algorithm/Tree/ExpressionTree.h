#include <stdio.h>
#include <stdlib.h>

typedef struct _STreeData
{
    int num;
} TreeData;

typedef struct _STreeNode
{
    struct _STreeData data;
    struct _STreeNode* left;
    struct _STreeNode* right;
} TreeNode;

TreeNode* make_tree_node(void);
TreeData get_data(TreeNode*);
void set_data(TreeNode*, int);

TreeNode* get_left_sub_tree(TreeNode*);
TreeNode* get_right_sub_tree(TreeNode*);

void make_left_sub_tree(TreeNode*, TreeNode*);
void make_right_sub_tree(TreeNode*, TreeNode*);
void free_node(TreeNode*);

void inorder_traverse(TreeNode*);
void preorder_traverse(TreeNode*);
void postorder_traverse(TreeNode*);

int calc(TreeNode* _pRootNode);
int is_operator(int ch);
int operate(int _operator, int _num1, int _num2);