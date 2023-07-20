#include <stdio.h>

void Print(int data[],int size)
{
    for(int i = 0;i < size; i++)
    {
        printf("%d ",data[i]);
    }
    printf("\n");
}

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 插入排序，将当前指向的元素插入到之前的有序序列中
void Insert(int arr[],int low,int high)
{
    for(int i = low + 1; i <= high; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while(j >= 0&&temp < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp; 
    }
}

// 冒泡排序
void BubbleSort(int arr[],int low,int high)
{
    int flag = 0;
    int size = high - low + 1;
    for(int i = 0; i < size; i++)
    {
        flag = 0;
        for(int j = size - 1; j > i; j--)
        {
            if(arr[j] < arr[j - 1])
            {
                Swap(&arr[j], &arr[j-1]);
                flag = 1;
            }
        }
        if(flag == 0)
            break;
    }
}

// 选择排序，每次从乱序列表中选择一个最小的出来
void SelectSort(int arr[],int low, int high)
{
    int min = low;
    int size = high - low + 1;
    for(int i = low; i < high; i++)
    {
        for(int j = i + 1; j < high; j++)
        {
            min = arr[min] > arr[j]? j: min;
        }
        Swap(&arr[min],&arr[i]);
    }
}

// 快速排序
void QuickSort(int arr[], int low, int high)
{
    if(low >= high)return;
    int base = arr[low];
    int left = low;
    int right = high;
    while(left < right)
    {
        while(left < right && arr[right] > base) right--;
        if(left < right)
        {
            arr[left++] = arr[right];
        }
        while(left < right && arr[left] < base) left++;
        if(left < right)
        {
            arr[right--] = arr[left]; 
        }
    }
    arr[left] = base;
    QuickSort(arr, low, left - 1);
    QuickSort(arr, left + 1, right);
}

// 快速排序，再来一遍
void QuickSort2(int arr[], int low, int high)
{
    if(low >= high) return;
    int base = arr[low];
    int left = low;
    int right = high;
    while(left < right)
    {
        while(left < right && base < arr[right]) right--;
        if(left < right)
            arr[left++] = arr[right];
        while(left < right && base > arr[left]) left++;
        if(left < right)
            arr[right--] = arr[left]; 
    }
    arr[left] = base;
    QuickSort(arr,low, left - 1);
    QuickSort(arr, left + 1, high);
}


// 希尔排序
void ShellSort(int arr[], int low, int high)
{
    int size = high - low + 1;
    for(int gap = size/2; gap > low; gap/=2)
    {
        for(int i = gap; i < size; i++)
        {
            int temp = arr[i];
            int j;
            for( j = i - gap; j >= 0 && temp < arr[j]; j -= gap)
            {
                arr[j + gap] = arr[j];
            }
            arr[j + gap] = temp;
        }
    }
}

void ShellSort2(int arr[], int size)
{
    for(int gap = size/2; gap > 0; gap/=2)
    {
        for(int i = gap; i < size; i++)
        {
            int temp = arr[i];
            int j;
            for(j = i - gap; j >= 0 && temp < arr[j]; j = j - gap)
            {
                arr[j + gap] = arr[j];
            }
            arr[j + gap] = temp;
        }
    }
}

// 归并排序
void MergeSort(int arr[], int copy[], int low, int high)
{
    if(low >= high) return;
    int len = high - low;
    int mid = low + len/2;
    int start1 = low, end1 = mid, start2 = mid + 1, end2 = high;
    MergeSort(arr,copy,start1,end1);
    MergeSort(arr,copy,start2,end2);
    int index = low;
    while(start1 <= end1 && start2 <= end2)
    {
        copy[index++] = arr[start1] < arr[start2]? arr[start1++] : arr[start2++];
    }
    while(start1 <= end1)
        copy[index++] = arr[start1++];
    while(start2 <= end2)
        copy[index++] = arr[start2++];
    for(index = low; index <= high; index++)
        arr[index] = copy[index];
}

// 堆排序
void Adjust(int arr[],int low,int high)
{
    int dad = low;
    int son = 2 * dad + 1;
    while(son <= high)
    {
        if(son + 1 <= high && arr[son] < arr[son + 1])
        {
            son++;
        }
        if(arr[dad] > arr[son])
        {
            return;
        }
        else
        {
            Swap(&arr[dad],&arr[son]);
            dad = son;
            son = 2 * dad + 1;
        }
    }
}

void HeapSort(int arr[],int size)
{
    int len = size;
    // 初始化，从最后一个父节点开始调整堆
    for(int i = len/2 - 1; i >= 0; i--)
    {
        Adjust(arr,i,len - 1);
    }

    for(int i = len -1; i > 0; i--)
    {
        Swap(&arr[i],&arr[0]);
        Adjust(arr,0,i - 1);
    }
}

//  堆排序练习
void heap_adjust(int arr[],int low,int high)
{
    int dad = low;
    int son = 2 *dad + 1;
    while (son <= high)
    {
        if(son + 1 <= high && arr[son] < arr[son + 1])
            son++;
        if(arr[dad] > arr[son])
            return;
        else
        {
            Swap(&arr[dad],&arr[son]);
            dad = son;
            son = 2 * dad + 1;
        }
    }
}

void heapsort(int arr[],int size)
{
    for(int i = size/2 - 1; i >= 0; i--)
    {
        heap_adjust(arr,i,size - 1);
    }
    for(int i = size - 1; i > 0; i--)
    {
        Swap(&arr[0],&arr[i]);
        heap_adjust(arr,0,i - 1);
    }
}