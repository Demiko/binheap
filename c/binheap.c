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
    int i;
    for(i=iparent(n-1);i>=0;i--){
        siftDown(a,i,n-1);
    }
}

void siftDown(int a[],int start,int end){
    while(ileft(start)<=end){
        int child=ileft(start);
        int swap=start;
        if(a[swap]<a[child]){
            swap=child;
        }
        if(child+1<=end && a[swap]<a[child+1]){
            swap=child+1;
        }
        if(swap==start){
            return;
        }
        else{
            int tmp=a[swap];
            a[swap]=a[start];
            a[start]=tmp;
            start=swap;
        }
    }
}

int iparent(int i){
    return floor((i-1)/2);
}

int ileft(int i){
    return 2*i+1;
}