#include "splay.h"
#include <stdio.h>
#include <stdlib.h>

Node * splaytree_splay(SplayTree tree, Type key)
{
  Node N, *l, *r, *c;

  if(NULL == tree)
    return tree;

  N.left = N.right = NULL;
  l = r = &N;

  while(1){
    if(key < tree->key)
    {
      if(NULL == tree->left)
        break;

      if(key < tree->left->key)
      {
        c = tree->left;
        tree->left = c->right;
        c->right = tree;
        tree = c;
        if(NULL == tree->left)
          break;
      }

      r->left = tree;
      r = tree;
      tree = tree->left;

    }
    else if(key > tree->key)
    {
      if(NULL == tree->right)
        break;

      if(key > tree->right->key)
      {
        c = tree->right;
        tree->right = c->tree;
        c->left = tree;
        tree = c;
        if(NULL == tree->right)
          break;
      }

      l->right = tree;
      l = tree;
      tree = tree->right;
    }
    else
      break;
  }

  l->right = tree->left;
  r->left = tree->right;
  tree->left = N.right;
  tree->right = N.left;

  return tree;
}
