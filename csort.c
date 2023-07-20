#include <stdio.h>
#include <stdlib.h>
#include "csort.h"

int main() {
    int *array = NULL;  // 初始化指向数组的指针为 NULL
    int size = 0;      // 数组大小计数器
    int num;           // 输入的整数

    // printf("连续输入整数到数组（以换行结束）:\n");

    // // 循环读取整数，直到遇到换行符
    // while (scanf("%d", &num) == 1) {
    //     // 动态分配内存并存储整数
    //     array = (int*)realloc(array, (size + 1) * sizeof(int));
    //     array[size] = num;
    //     size++;
    // }

    int data[7] = {99,21,32,4455,1,225,66};
    int copy[7] = {0};
    size = 7;
    // Insert(array, 0, size-1);
    // BubbleSort(array,0,size - 1);
    // SelectSort(array, 0, size - 1);
    // QuickSort(data, 0, size - 1);
    // ShellSort(data,0,size - 1);
    // ShellSort2(data, size);
    // MergeSort(data,copy,0,size-1);
    // HeapSort(data, size);
    heapsort(data,size);

    Print(data,size);

    // // 打印输入的整数数组
    // Print(array,size);
    // // 释放动态分配的内存
    // free(array);
    return 0;
}
