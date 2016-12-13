#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b)    ((a)>(b)?(a):(b))
#define HEIGHT(p)   ( (int)( (NULL==p) ? 0 : ((pAVLTreeNode)p)->height) )


int avltree_height_by_child(pAVLTreeNode p)
{
  return MAX( HEIGHT(p->left), HEIGHT(p->right) ) + 1 ;
}

int avltree_height(pAVLTreeNode p)
{
  return HEIGHT(p);
}

static pAVLTreeNode avltree_create_node(keyType key, pAVLTreeNode left, pAVLTreeNode right)
{
  pAVLTreeNode p = (pAVLTreeNode)malloc(sizeof(AVLTreeNode));

  if(NULL == p){
      perror("malloc()");
      exit(-1);
  }

  p->key = key;
  p->left = left;
  p->right = right;
  p->height = avltree_height_by_child(p);
  return p;
}


static pAVLTreeNode left_left_rotation(pAVLTreeNode p)
{
  /* 根节点的左子树把它的右子树做替身，修改高度后，该左子树作为新的根节点返回 */
  pAVLTreeNode pLeft = p->left;
  p->left = pLeft->right;
  pLeft->right = p;

  /*子树改变，修正高度*/
  p->height = avltree_height_by_child(p);
  pLeft->height = avltree_height_by_child(pLeft);

  return pLeft;
}


static pAVLTreeNode right_right_rotation(pAVLTreeNode p)
{
  /*根节点的右子树把它的左子树作为替身，修改高度后，该右子树作为新的根节点返回 */
  pAVLTreeNode pRight = p->right;
  p->right = pRight->left;
  pRight->left = p;

  p->height = avltree_height_by_child(p);
  pRight->height = avltree_height_by_child(pRight);

  return pRight;
}

static pAVLTreeNode left_right_rotation(pAVLTreeNode p)
{
  p->left = right_right_rotation(p->left);
  return left_left_rotation(p);
}

static pAVLTreeNode right_left_rotation(pAVLTreeNode p)
{
  p->right = left_left_rotation(p->right);
  return right_right_rotation(p);
}

pAVLTreeNode avltree_insert(pAVLTreeNode tree, keyType key)
{
  if( NULL == tree ){
    return avltree_create_node(key, NULL, NULL);
  }else if(key == tree->key){
    //key is unique
    return tree;
  }else if( key < tree->key ){
    tree->left = avltree_insert(tree->left, key);

    //adjust height
    if( HEIGHT(tree->left) - HEIGHT(tree->right) == 2 ){
      if( key < tree->left->key )
        tree = left_left_rotation(tree);
      else
        tree = left_right_rotation(tree);
    }
  }else if( key > tree->key ){
      tree->right = avltree_insert(tree->right, key);

    if( HEIGHT(tree->right) - HEIGHT(tree->left) == 2 ){
      if( key > tree->right->key )
        tree = right_right_rotation(tree);
      else
        tree = right_left_rotation(tree);
    }
  }

  tree->height = avltree_height_by_child(tree);
  return tree;
}


/*
 * 查找最小结点：返回tree为根结点的AVL树的最小结点。
 */
pAVLTreeNode avltree_minimum(pAVLTreeNode tree)
{
    if (tree == NULL)
        return NULL;

    while(tree->left != NULL)
        tree = tree->left;
    return tree;
}

/*
 * 查找最大结点：返回tree为根结点的AVL树的最大结点。
 */
pAVLTreeNode avltree_maximum(pAVLTreeNode tree)
{
    if (tree == NULL)
        return NULL;

    while(tree->right != NULL)
        tree = tree->right;
    return tree;
}

pAVLTreeNode avltree_search(pAVLTreeNode x, keyType key)
{
    if (x==NULL || x->key==key)
        return x;

    if (key < x->key)
        return avltree_search(x->left, key);
    else
        return avltree_search(x->right, key);
}


static pAVLTreeNode avltree_node_delete(pAVLTreeNode root, pAVLTreeNode node)
{
  if( NULL == root || NULL == node )
    return NULL;

  //search the key position
  if( node->key == root->key ){
    //如果左右孩子都非空，选其中一个作为替身，否则看作链表删除
    if( root->left && root->right ){

      //避免avl失去平衡，找子树高的一边的节点作为替身，左子树选最大的，右子树选最小的
      if( HEIGHT(root->left) > HEIGHT(root->right) ){
        pAVLTreeNode max = avltree_maximum(root->left);
        root->key = max->key;
        root->left = avltree_node_delete(root->left, max);
      }else{
        pAVLTreeNode min = avltree_minimum(root->right);
        root->key = min->key;
        root->right = avltree_node_delete(root->right, min);
      }


    }else{
      //free the node
      pAVLTreeNode tmp = root;
      root = root->left ? root->left : root->right;
      free(tmp);
      return root;
    }


  }else  if( node->key < root->key ){
    root->left = avltree_node_delete(root->left, node);

    //adjust height
    if( HEIGHT(root->right) - HEIGHT(root->left) == 2 ){
      if( HEIGHT(root->right->left) > HEIGHT(root->right->right) )
        root = right_left_rotation(root);
      else
        root = right_right_rotation(root);
    }

  }else if( node->key > root->key ){
      root->right = avltree_node_delete(root->right, node);

      if( HEIGHT(root->left) - HEIGHT(root->right) == 2 ){
        if( HEIGHT(root->left->right) > HEIGHT(root->left->left) )
          root = left_right_rotation(root);
        else
          root = left_left_rotation(root);
      }
  }
  return root;
}

pAVLTreeNode avltree_delete( pAVLTreeNode tree, keyType key )
{
  pAVLTreeNode tmp = avltree_search( tree, key );
  if( NULL != tmp )
    tree = avltree_node_delete( tree, tmp );
  return tree;
}



/*
 * 前序遍历"AVL树"
 */
void preorder_avltree(pAVLTreeNode tree)
{
    if(tree != NULL)
    {
        printf("%d ", tree->key);
        preorder_avltree(tree->left);
        preorder_avltree(tree->right);
    }
}


/*
 * 中序遍历"AVL树"
 */
void inorder_avltree(pAVLTreeNode tree)
{
    if(tree != NULL)
    {
        inorder_avltree(tree->left);
        printf("%d ", tree->key);
        inorder_avltree(tree->right);
    }
}

/*
 * 后序遍历"AVL树"
 */
void postorder_avltree(pAVLTreeNode tree)
{
    if(tree != NULL)
    {
        postorder_avltree(tree->left);
        postorder_avltree(tree->right);
        printf("%d ", tree->key);
    }
}


/*
 * 销毁AVL树
 */
void destroy_avltree(pAVLTreeNode tree)
{
    if (tree==NULL)
        return ;

    if (tree->left != NULL)
        destroy_avltree(tree->left);
    if (tree->right != NULL)
        destroy_avltree(tree->right);

    free(tree);
}



/*
 * 打印"AVL树"
 *
 * tree       -- AVL树的节点
 * key        -- 节点的键值
 * direction  --  0，表示该节点是根节点;
 *               -1，表示该节点是它的父结点的左孩子;
 *                1，表示该节点是它的父结点的右孩子。
 */
void print_avltree(pAVLTreeNode tree, keyType key, int direction)
{
    if(tree != NULL)
    {
        if(direction==0)    // tree是根节点
            printf("%2d is root\n", tree->key);
        else                // tree是分支节点
            printf("%2d is %2d's %6s child\n", tree->key, key, direction==1?"right" : "left");

        print_avltree(tree->left, tree->key, -1);
        print_avltree(tree->right,tree->key,  1);
    }
}
