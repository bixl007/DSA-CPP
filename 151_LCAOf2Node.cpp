/************************************************************
    Following is the Binary Search Tree node structure

    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

***********************************************************



TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    if(root == NULL) 
        return NULL;
    
    if(root -> data < P -> data && root -> data < Q -> data)
        return LCAinaBST(root -> right, P, Q);
    if(root -> data > P -> data && root -> data > Q -> data)
        return LCAinaBST(root -> left, P, Q);

    return root;

}*/