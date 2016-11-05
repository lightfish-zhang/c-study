/*
 * 线性结构
 * 离散存储[链表]
 * 算法：
    * 遍历
    * 查找
    * 清空
    * 销毁
    * 求长度
    * 排序
    * 删除节点
    * 插入节点
 * author lightfish.cn
 */

 typedef struct Node
 {
     int data; //数据域
     struct Node * pNext;  //指针域
 } NODE , * PNODE ;


PNODE list_node(); //创建节点
PNODE list_create(); //创建链表
void list_traverse(PNODE pHead); //遍历链表
int list_is_empty(PNODE pHead);
int list_count(PNODE pHead);
void list_sort_quick(PNODE pHead);
void list_sort_bubble(PNODE pHead);
void list_destory(PNODE pHead);
void list_insert(PNODE pHead , int index , int value);
PNODE list_get_node( PNODE pHead , int index);
void list_delete_node(PNODE * ppHead , int index);