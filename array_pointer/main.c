#include <stdio.h>

int main(int argc, char **argv){
	char ***p0 = &argv;
	char **p1 = argv;
	char *p2 = *argv;
	char p3 = **argv;

	printf("p0, value:%x, point to argv's value:%x\n", p0, *p0);
	printf("p1, value:%x, point to address(%x) where argv point to\n", p1, *p1);
	printf("p2, value:%x, point to char:%c, and point to string:%s\n", p2, *p2, p2);
	printf("p3, value:%c\n", p3);

	char arr[] = "abc";
	char * parr = arr;
	printf("arr means address to the first element, value:%x, point to char:%c\n", arr, *arr);
	printf("parr means address to the first element, value:%x, point to char:%c\n", parr, *parr);
	printf("arr is array without own memory, &arr:%x\n", &arr);
	printf("parr is pointer with own memory, &parr:%x\n", &parr);
	return 0;
}
