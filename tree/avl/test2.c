#include <stdio.h>
#include "avl.c"

int main()
{
  int i,ilen;
  pAVLTreeNode root=NULL;

  printf("== 高度: %d\n", avltree_height(root));
  return 0;
}
