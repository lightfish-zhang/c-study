typedef int Type;

typedef struct SplayTreeNode {
    Type key;
    struct SplayTreeNode *left;
    struct SplayTreeNode *right;
} Node, *SplayTree;
