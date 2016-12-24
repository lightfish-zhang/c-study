#include "splay.h"
#include <stdio.h>
#include <stdlib.h>


SplayTree splaytree_splay( SplayTree tree, keyType key ){

  SplayTreeNode Node, * left, * right, * current;

  if( NULL == tree )
    return tree;

  Node.left = NULL;
  Node.right = NULL;
  left = &Node;
  right = &Node;

  while(1){

    if( key < tree->key ){

      if( NULL == tree->left )
        break;

      if( key < tree->left->key ){
        current = tree->left;
        tree->left = tree->left->right;
        current->right = tree;
        tree = current;
          if( NULL == tree->left )
            break;
      }

      right->left = tree;
      right = tree;
      tree = tree->left;

    }else if( key > tree->right ){

      if( NULL == tree->right )
        break;

      if( key > tree->right->key ){
        current = tree->right;
        tree->right = current->left;
        current->left = tree;
        tree = current;

        if( NULL == tree->right )
          break;
      }

      left->right = tree;
      left = tree;
      tree = tree->right;

    }else
      break;
  }

  left->right = tree->left;
  right->left = tree->right;
  tree->left = Node.right;
  tree->right = Node.left;

  return tree;
}
