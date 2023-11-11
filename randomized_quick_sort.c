#include<stdio.h>
#include<time.h>
void swap(int *a,int *b){
    int c;
    c=*a;
    *a=*b;
    *b=c;
}
int random_value(int low,int high){
    srand(time(0));
    return low+rand()%(high-low);
}
int partition(int a[],int low,int high){
    int x=random_value(low,high);
    swap(&a[x],&a[low]);
    int pivot=a[low];
    int i=low,j=high;
    while(i<j){
        while(pivot>=a[i] && i<= high){
            i++;
        }
        while(pivot<a[j] && j>low){
            j--;
        }
        if(i<j){
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[j],&a[low]);
    
    return j;
}
void quick_sort(int a[],int low,int high){
    if(low<high){
        int p=partition(a,low,high);
        quick_sort(a,low,p-1);
        quick_sort(a,p+1,high);
    }
}
int main(){
    int size;
    printf("size : ");
    scanf("%d",& size);
    int arr[size];
    for(int i=0;i<size;i++){
        printf("element : ");
        scanf("%d",& arr[i]);
    }
    quick_sort(arr,0,size-1);
    for(int i=0;i<size;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}
