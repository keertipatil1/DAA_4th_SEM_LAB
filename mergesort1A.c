#include<stdio.h>
#include<stdlib.h>

#define MAX 1000
int count;

void merge(int a[MAX], int low, int mid, int high){
    int b[MAX],i,j,k;
    i=low;
    j=mid+1;
    k=low;

    while(i<=mid && j<=high){
       if(a[i]< a[j]){
            b[k++]=a[i++];
       } 
       else{
        b[k++]=a[j++];
       }
       count++;
    }

    while(i<=mid){
        b[k++]=a[i++];
        count++;
    }

    while(j<=high){
        b[k++]=a[j++];
        count++;
    }

    for(i=low; i<=high; i++){
        a[i]=b[i];
    }

    
}

void mergesort(int a[MAX], int low, int high){
    if(low<high){
        int mid = (high + low)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }

}

int main(){
    int i,j,n,a[MAX], b[MAX], c[MAX], c1,c2,c3;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(i=0; i<n; i++){
        scanf("%d",&a[i]);

    }

    count =0;
    mergesort(a,0,n-1);

    printf("Sorted array: ");
    for(i=0; i<n; i++){
        printf("%d ",a[i]);
    }

    printf("Number of counts taken to execute: %d",count);

    for(i=16; i<550; i=i*2){
        for(j=0; j<i; j++){
            a[j]=j;
            b[j]=i-j;
            c[j]=rand()%i;
        }
    

    count =0;
    mergesort(a,0,i-1);
    c1 = count;

    count =0;
    mergesort(b,0,i-1);
    c2=count;

    count =0;
    mergesort(c,0,i-1);

    c3=count;
    printf("\n%d\t%d\t%d\t%d",i,c1,c2,c3);
    }
    printf("\n");
    return 0;
}