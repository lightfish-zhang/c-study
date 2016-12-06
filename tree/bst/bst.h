typedef int dataType;

typedef struct BSTreeNode{
  dataType data;
  struct BSTreeNode * left;
  struct BSTreeNode * right;
  struct BSTreeNode * parent;
} BSTreeNode , * pBSTreeNode;

static pBSTreeNode create_bstree_node(dataType data, pBSTreeNode parent, pBSTreeNode left, pBSTreeNode right);

void preorder_bstree(pBSTreeNode tree);

void inorder_bstree(pBSTreeNode tree);

void postorder_bstree(pBSTreeNode tree);

pBSTreeNode bstree_search(pBSTreeNode x, dataType data);

pBSTreeNode bstree_maximum(pBSTreeNode tree);

pBSTreeNode bstree_minimum(pBSTreeNode tree);

pBSTreeNode bstree_predecessor(pBSTreeNode x);

pBSTreeNode bstree_successor(pBSTreeNode x);

static pBSTreeNode bstree_insert(pBSTreeNode tree, pBSTreeNode z );

pBSTreeNode insert_bstree(pBSTreeNode tree, dataType data);

static pBSTreeNode bstree_delete(pBSTreeNode tree, pBSTreeNode z);

pBSTreeNode delete_bstree(pBSTreeNode tree, dataType data);

void print_bstree(pBSTreeNode tree, dataType data, int direction);

void destroy_bstree(pBSTreeNode tree);
