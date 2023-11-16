#include<stdio.h>
typedef struct job{
    int profit;
    int deadline;
}job;
void sort(job a[],int size){
    for(int i=0;i<size-1;i++){
        int flag=0;
        for(int j=0;j<size-i-1;j++){

            if(a[j].profit<a[j+1].profit){
                flag=1;
                int c=a[j].profit;
                a[j].profit=a[j+1].profit;
                a[j+1].profit=c;
            }
        }
        if(flag==0){
            break;
        }
    }
}
int max_deadline(job a[],int size){
    int max=-1;
    for(int i=0;i<size;i++){
        if(max<a[i].deadline){
            max=a[i].deadline;
        }
    }
    //printf("%d",max);
    return max;
}
int solution(job a[],int size){
    int max=max_deadline(a,size);
    job s[max];
    for(int i=0;i<max;i++){
        s[i].deadline=-1;
    }
    for(int i=0;i<size;i++){
        int j=a[i].deadline-1;
        while(j>-1){
            if(s[j].deadline==-1){
                s[j]=a[i];
                break;
            }
            j--;
        }
        
    }
    int sum=0;
    for(int i=0;i<max;i++){
        printf("%d\t",s[i].profit);
        
        sum=sum+s[i].profit;
    }
    return sum;
}
int main(){
    int size;
    printf("size : ");
    scanf("%d",& size);
    job a[size];
    for(int i=0;i<size;i++){
        printf("profit : ");
        scanf("%d",& a[i].profit);
        printf("deadline : ");
        scanf("%d",& a[i].deadline);
    }
    sort(a,size);
    printf("\nprofit : %d",solution(a,size));
    return 0;
}