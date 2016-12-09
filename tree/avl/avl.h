typedef int keyType;

typedef struct AVLTreeNode{
  keyType key;
  int height;
  struct AVLTreeNode * left;
  struct AVLTreeNode * right;
} AVLTreeNode, * pAVLTreeNode;
