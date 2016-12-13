typedef int keyType;

typedef struct AVLTreeNode{
  keyType key;
  int height;
  struct AVLTreeNode * left;
  struct AVLTreeNode * right;
} AVLTreeNode, * pAVLTreeNode;



int avltree_height_by_child(pAVLTreeNode p);
int avltree_height(pAVLTreeNode p);
pAVLTreeNode avltree_insert(pAVLTreeNode tree, keyType key);


/*
 * 查找最小结点：返回tree为根结点的AVL树的最小结点。
 */
pAVLTreeNode avltree_minimum(pAVLTreeNode tree);

/*
 * 查找最大结点：返回tree为根结点的AVL树的最大结点。
 */
pAVLTreeNode avltree_maximum(pAVLTreeNode tree);

pAVLTreeNode avltree_search(pAVLTreeNode x, keyType key);


pAVLTreeNode avltree_delete( pAVLTreeNode tree, keyType key );



/*
 * 前序遍历"AVL树"
 */
void preorder_avltree(pAVLTreeNode tree);

/*
 * 中序遍历"AVL树"
 */
void inorder_avltree(pAVLTreeNode tree);

/*
 * 后序遍历"AVL树"
 */
void postorder_avltree(pAVLTreeNode tree);

/*
 * 销毁AVL树
 */
void destroy_avltree(pAVLTreeNode tree);


/*
 * 打印"AVL树"
 *
 * tree       -- AVL树的节点
 * key        -- 节点的键值
 * direction  --  0，表示该节点是根节点;
 *               -1，表示该节点是它的父结点的左孩子;
 *                1，表示该节点是它的父结点的右孩子。
 */
void print_avltree(pAVLTreeNode tree, keyType key, int direction);
