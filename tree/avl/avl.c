#include "avl.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b)    ((a)>(b)?(a):(b))
#define HEIGHT(p)   ( (int)( (NULL==p) ? 0 : (p)->height) )


static int avltree_height_by_child(pAVLTreeNode p)
{
  return MAX( HEIGHT(p->left), HEIGHT(p->right) ) + 1 ;
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

static pAVLTreeNode avltree_node_delete(pAVLTreeNode root, pAVLTreeNode node)
{
  if( NULL == root || NULL == node )
    return NULL;

  if( node->key < root->key ){
    root->left = avltree_node_delete(root->left, node);

    //adjust height


  }

  return root;
}
