#include <stdio.h>
#include <stdlib.h>

#define LENGTH(a) ( (sizeof(a) / sizeof(a[0])) )

static int m_heap[30];
static int m_capacity=30;
static int m_size=0;

/*
return index of data
*/
int get_index(int data)
{
  int i=0;
  for(i=0; i<m_size; i++)
    if(data == m_heap[i])
      return i;

  return -1;
}

/*
max heap , adjust from top to down
usage: run it after deleting node
note: index of left child is 2n+1, right is 2n+2
*/
static void maxheap_filterdown(int start, int end)
{
  int current   = start;        // index of current node
  int child     = 2*current + 1;   // index of current node's left child
  int startData = m_heap[start];  // data of start node

  while(child <= end){
    if( child < end && m_heap[child] < m_heap[child + 1] )
      child ++;  //choose max node of children, note: index of right child equal left +1

    if( startData < m_heap[child] ){
      m_heap[current] = m_heap[child];
      current = child;
      child = 2*child + 1;
    }else
      break;  //find out current node whose children node smaller than startData,
              //then set data of current node with startData
  }
  m_heap[current] = startData;
}

/*
usage: delete node
*/
int maxheap_remove(int data)
{
  int index;

  if(0 == m_size)
    return -1;

  index = get_index(data);
  if(-1 == index)
    return -1;

  m_heap[index] = m_heap[--m_size]; // --m_size, then replace node removed with the lastest node
  maxheap_filterdown(index, m_size-1);
  return 0;
}

/*
max heap , adjust from down to top
usage: run it after inserting node
*/
static void maxheap_filterup(int start)
{
  int current   = start;
  int parent    = (current-1) / 2;
  int startData = m_heap[start];

  while( current > 0 ){
    if( m_heap[parent] < startData ){
      m_heap[current] = m_heap[parent];
      current = parent;
      parent  = (current -1) /2;
    }else
      break;  // find out current node whose parent bigger than startData
              // then set data of current node with startData
  }
  m_heap[current] = startData;
}

int maxheap_insert( int data )
{
  if( m_size == m_capacity )
    return -1;

  m_heap[m_size] = data;
  maxheap_filterup( m_size );
  m_size ++;
  return 0;
}


void maxheap_print()
{
    int i;
    for (i=0; i<m_size; i++)
        printf("%d ", m_heap[i]);
}

int main()
{
    int a[] = {10, 40, 30, 60, 90, 70, 20, 50, 80};
    int i, len=LENGTH(a);

    printf("== 依次添加: ");
    for(i=0; i<len; i++)
    {
        printf("%d ", a[i]);
        maxheap_insert(a[i]);
    }

    printf("\n== 最 大 堆: ");
    maxheap_print();

    i=85;
    maxheap_insert(i);
    printf("\n== 添加元素: %d", i);
    printf("\n== 最 大 堆: ");
    maxheap_print();

    i=90;
    maxheap_remove(i);
    printf("\n== 删除元素: %d", i);
    printf("\n== 最 大 堆: ");
    maxheap_print();
    printf("\n");
}
