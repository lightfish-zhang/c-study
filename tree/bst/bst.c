#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

static pBSTreeNode create_bstree_node(dataType data, pBSTreeNode parent, pBSTreeNode left, pBSTreeNode right)
{
  pBSTreeNode p = (pBSTreeNode)malloc(sizeof(BSTreeNode));
  if(NULL == p)
    return p;

  p->data = data;
  p->left = left;
  p->right = right;
  p->parent = parent;

  return p;
}

void preorder_bstree(pBSTreeNode tree)
{
  if(NULL != tree){
    printf("%d ",tree->data);
    preorder_bstree(tree->left);
    preorder_bstree(tree->right);
  }
}


void inorder_bstree(pBSTreeNode tree)
{
  if(NULL != tree){
    inorder_bstree(tree->left);
    printf("%d ",tree->data);
    inorder_bstree(tree->right);
  }
}

void postorder_bstree(pBSTreeNode tree)
{
  if(NULL != tree){
    postorder_bstree(tree->left);
    postorder_bstree(tree->right);
    printf("%d ",tree->data);
  }
}

pBSTreeNode bstree_search(pBSTreeNode x, dataType data)
{
  if(NULL == x || x->data == data)
    return x;

  if(data < x->data)
    return bstree_search(x->left,data);
  else
    return bstree_search(x->right,data);
}

pBSTreeNode bstree_maximum(pBSTreeNode tree)
{
  if(NULL == tree)
    return tree;

  while(NULL != tree->right)
    tree = tree->right;
  return tree;
}

pBSTreeNode bstree_minimum(pBSTreeNode tree)
{
  if(NULL == tree)
    return tree;

  while(NULL != tree->left)
    tree = tree->left;
  return tree;
}

pBSTreeNode bstree_predecessor(pBSTreeNode x)
{
  if(NULL != x->left)
    return bstree_maximum(x->left);

  pBSTreeNode y = x->parent;

  //code 1
  if(NULL == y)
    return NULL;

  if(y->right == x )
    return y;

  do{
    x = y;
    y = y->parent;
  }while(NULL != y && x != y->right);

  return y;

  /* code 2
  while(NULL != y && x == y->left){
    x = y;
    y = y->parent;
  }
  return y;
  */
}

pBSTreeNode bstree_successor(pBSTreeNode x)
{
  if(NULL != x->right)
    return bstree_minimum(x->right);

  pBSTreeNode y = x->parent;

  if(NULL == y)
    return NULL;

  if(x == y->left)
    return y;

  do{
    x = y;
    y = y->parent;
  }while(NULL != y && x != y->left);
  return y;

  /* code 2
  while(NULL != y && x == y->right){
    x = y;
    y = y->parent;
  }
  return y;
  */
}

static pBSTreeNode bstree_insert(pBSTreeNode tree, pBSTreeNode z )
{
  if(NULL == tree)
    return z;

  pBSTreeNode y = NULL;
  pBSTreeNode x = tree;

  do{
    y = x;
    if(z->data < x->data)
      x = x->left;
    else
      x = x->right;
  }while(NULL != x);

  z->parent = y;

  if(z->data < y->data)
    y->left = z;
  else
    y->right = z;

  return tree;
}

pBSTreeNode insert_bstree(pBSTreeNode tree, dataType data)
{
  pBSTreeNode z = create_bstree_node(data,NULL,NULL,NULL);

  if(NULL == z)
    return tree;
  return bstree_insert(tree,z);
}

static pBSTreeNode bstree_delete(pBSTreeNode tree, pBSTreeNode z)
{
  pBSTreeNode x = NULL;//x是y的子树
  pBSTreeNode y = NULL;//y是被释放的指针

  /*
   * 如果z只有一个子树或者没有子树，直接把z地址回收，上下父子拼接
   * 如果z有两个子树，找到z的继任者y，继任者y必定只有一个右子树或者没有子树，y的数据赋值给z，回收y的地址，y的上下父子拼接
   */
  if( NULL == z->left || NULL == z->right )
    y = z;
  else{
    y = bstree_successor(z);
    z->data = y->data;
  }

  //修改y的子树的父节点
  if(NULL != y->left)
    x = y->left;
  else
    x = y->right;

  if(NULL != x)
    x->parent = y->parent;


  //修改y的父节点
  if(NULL == y->parent)
    tree = x;
  else if(y == y->parent->left)
    y->parent->left = x;
  else
    y->parent->right = x;

  if(NULL != y)
    free(y);

  return tree;
}

pBSTreeNode delete_bstree(pBSTreeNode tree, dataType data)
{
  pBSTreeNode z, node;
  if( NULL != (z = bstree_search(tree,data)))
    tree = bstree_delete(tree, z);

  return tree;
}

void print_bstree(pBSTreeNode tree, dataType data, int direction)
{
  if(NULL != tree){
    if(0 == direction)
      printf("%2d is root\n", tree->data);
    else
      printf("%2d is %2d's %6s child\n", tree->data, data, direction ==1 ? "right" : "left" );

    print_bstree(tree->left, tree->data, -1);
    print_bstree(tree->right, tree->data, 1);
  }
}

void destroy_bstree(pBSTreeNode tree)
{
  if(NULL == tree)
    return ;

  if(NULL != tree->left)
    destroy_bstree(tree->left);
  if(NULL != tree->right)
    destroy_bstree(tree->right);

  free(tree);
}
