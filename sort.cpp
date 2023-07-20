#include <iostream>
#include <vector>

using namespace std;

void Insert(vector<int>& data){
    int len=data.size();
    for(int i=1;i<len;i++){
        int temp=data[i];
        int j=i-1;
        while(j>=0&&data[j]>temp){
            data[j+1]=data[j];
            --j;
        }
        data[j+1]=temp;
    }
}

void PrintData(vector<int>& data){
    for(auto i:data){
        std::cout<<i<<std::endl;
    }
}


void QuickSort(vector<int>& data,int low,int high){
    if(low>=high)return;
    int left=low;
    int right=high;
    int base=data[low];
    while(left<right){
        while(left<right&&data[right]>base)right--;
        if(left<right){
            data[left++]=data[right];
        }
        while (left<right&&data[left]<base)left++;
        if(left<right){
            data[right--]=data[left];
        }
    }
    data[left]=base;
    QuickSort(data,low,left-1);
    QuickSort(data,left+1,high);
}

void ShellSort(vector<int>& data){
    int len=data.size();
    for(int gap=len/2;gap>0;gap/=2){
        for(int i=gap;i<len;i++){
            int temp=data[i];
            int j;
            for(j=i-gap;j>=0&&temp<data[j];j-=gap){
                data[j+gap]=data[j];
            }
            data[j+gap]=temp;
        }
    }

}

void MergeSort(vector<int>& data,vector<int> &copy,int low,int high){
    if(low>=high)return;
    int len=high-low;
    int mid=low+len/2;
    int start1=low,end1=mid,start2=mid+1,end2=high;
    MergeSort(data,copy,start1,end1);
    MergeSort(data,copy,start2,end2);
    int index=low;
    while (start1<=end1&&start2<=end2)
    {
        copy[index++]=data[start1]<data[start2]?data[start1++]:data[start2++];
    }
    while(start1<=end1)
        copy[index++]=data[start1++];
    while (start2<=end2)
        copy[index++]=data[start2++];
    for(index=low;index<=high;index++){
        data[index]=copy[index];
    }
        
}


void max_heapify(int arr[], int start, int end) 
{
    //建立父节点指标和子节点指标
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end)  //若子节点指标在范围内才做比较
    {    
        if (son + 1 <= end && arr[son] < arr[son + 1]) //先比较两个子节点大小，选择最大的
            son++;
        if (arr[dad] > arr[son]) //如果父节点大於子节点代表调整完毕，直接跳出函数
            return;
        else  //否则交换父子内容再继续子节点和孙节点比较
        {
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void heap_sort(int arr[], int len) 
{
    //初始化，i从最後一个父节点开始调整
    for (int i = len / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, len - 1);
    //先将第一个元素和已经排好的元素前一位做交换，再从新调整(刚调整的元素之前的元素)，直到排序完毕
    for (int i = len - 1; i > 0; i--) 
    {
        swap(arr[0], arr[i]);
        max_heapify(arr, 0, i - 1);
    }
}

void HeapModify(vector<int> &data,int low,int high){
    int dad=low;
    int son=dad*2+1;
    while(son<=high){
        if(son+1<=high&&data[son]<data[son+1])
            son++;
        if(data[dad]>data[son])return;
        else{
            swap(data[dad],data[son]);
            dad=son;
            son=dad*2+1;
        }
    }
}

void heap_sort(vector<int> &data){
    int len=data.size();
    for(int i=len/2-1;i>=0;i--){
        HeapModify(data,i,len-1);
    }
    for(int i=len-1;i>0;i--){
        swap(data[0],data[i]);
        HeapModify(data,0,i-1);
    }

}


void Adjust(vector<int>& data,int low,int high){
    int dad=low;
    int son=2*dad+1;
    while(son<=high)
    {
        if (son+1<=high&&data[son]<data[son+1])
        {
            son++;
        }
        if(data[son]>data[dad])
        {
            swap(data[son],data[dad]);
            dad=son;
            son=2*dad+1;
        }
        else
            return;
    }
}

void HeapS(vector<int>& data){
    int len=data.size();
    for(int i=len/2-1;i>=0;i--)
    {
        Adjust(data,i,len-1);
    }
    for(int i=len-1;i>0;i--)
    {
        swap(data[0],data[i]);
        Adjust(data,0,i-1);
    }
}


int main(){
    vector<int> data={1,5,62,4,5,11,58,96,20};
    // Insert(data);
    // QuickSort(data,0,data.size()-1);
    // ShellSort(data);
    // vector<int> copy(data.size(),0);
    // MergeSort(data,copy,0,data.size()-1);
    // heap_sort(data);
    PrintData(data);
    return 0;
}
