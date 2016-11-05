/*
 * 线性结构、
 * 连续存储[数组]：元素类型相同，大小相等
 * author lightfish.cn
 */
typedef struct Arr{
    int * pBase;
    int length;
    int max;
} * PSA , SA ; //使用typedef , SA代表了struct Arr , PSA 代表了 struct Arr *

//void arr_init(struct Arr * pArr , int max);
void arr_init(PSA pArr , int max);
void arr_print(struct Arr * pArr);
int arr_append(struct Arr * pArr , int value);
int arr_insert(struct Arr * pArr , int index , int value);
int arr_delete(struct Arr * pArr , int index , int * pValue);
int arr_get();
int arr_is_empty(struct Arr * pArr);
int arr_is_full(struct Arr * pArr);
void arr_sort(struct Arr * pArr);
void arr_inversion(struct Arr * pArr);
void arr_destory(struct Arr * pArr);