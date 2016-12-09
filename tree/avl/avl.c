#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b)    ((a)>(b)?(a):(b))
#define HEIGHT(p)   ((NULL==p)?0:(pAVLTreeNode)(p)->height)

static pAVLTreeNode avltree_create_node(keyType key, pAVLTreeNode left, pAVLTreeNode right)
{
  pAVLTreeNode p = (pAVLTreeNode)malloc(sizeof(AVLTreeNode));

  if(NULL == p)
    return NULL;

  p->key = key;
  p->left = left;
  p->right = right;
  p->height = 0;
  return p;
}

static int avltree_height_by_child(pAVLTreeNode p)
{
  return MAX( HEIGHT(p->left), HEIGHT(p->right) ) + 1 ;
}

static pAVLTreeNode left_left_rotation(pAVLTreeNode p)
{
  /* 根节点的左子树把它的右子树做替身，它的右子树指向旧的根节点，修改高度后，作为新的根节点返回 */
  pAVLTreeNode p2 = p->left;
  p->left = p2->right;
  p2->right = p;

  /*子树改变，修正高度*/
  p->height = avltree_height_by_child(p);
  p2->height = avltree_height_by_child(p2);
  return p2;
}
