typedef int keyType;

typedef struct SplayTreeNode{
  keyType key;
  struct SplayTreeNode * left;
  struct SplayTreeNode * right;
} SplayTreeNode, * SplayTree;
