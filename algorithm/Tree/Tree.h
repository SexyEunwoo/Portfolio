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

typedef void visitFuncPtr(int);

TreeNode* make_tree_node(void);
TreeData get_data(TreeNode*);
void set_data(TreeNode*, int);
// void set_data(TreeNode*, TreeData);

TreeNode* get_left_sub_tree(TreeNode*);
TreeNode* get_right_sub_tree(TreeNode*);

void make_left_sub_tree(TreeNode*, TreeNode*);
void make_right_sub_tree(TreeNode*, TreeNode*);
void free_node(TreeNode*);

void inorder_traverse(TreeNode*);
void preorder_traverse(TreeNode*, visitFuncPtr);
void postorder_traverse(TreeNode*);

void test_func(int);