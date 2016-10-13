#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void heapify(int[],int);
int iparent(int);
int ileft(int);
void siftDown(int[],int,int);
void printarr(int[],int);

void main(){
    int n = 0;
    scanf("%i",&n);
    int i;
    int a[n];
    for(i=0;i<n;++i){
        scanf("%i",&a[i]);
    }
    heapify(a,n);
    int end=n-1;
    int tmp;
    while(end>0){
        tmp=a[0];
        a[0]=a[end];
        a[end]=tmp;
        heapify(a,end);
        --end;
    }
    for(i=0;i<n;++i){
        printf("%i\n",a[i]);
    }
}

void heapify(int a[],int n){
    int i,start,end,swap,tmp,child;
    end=n-1;
    for(i=iparent(end);i>=0;i--){
        start=i;
        while(ileft(start)<=end){
            child=ileft(start);
            swap=start;
            if(a[swap]<a[child]){
                swap=child;
            }
            if(child+1<=end && a[swap]<a[child+1]){
                swap=child+1;
            }
            if(swap==start){
                break;
            }
            else{
                tmp=a[swap];
                a[swap]=a[start];
                a[start]=tmp;
                start=swap;
            }
        }
    }
}

int iparent(int i){
    return (i-1)/2;
}

int ileft(int i){
    return 2*i+1;
}