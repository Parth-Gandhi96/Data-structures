#include <stdio.h>
#include <stdlib.h>

void swapInHeap(long long int *a,long long int *b){
	int dummy = *a;
	*a = *b;
	*b = dummy;
}

void goUp(long long int at,long long int arr[]){
	if((at-1)/2 < 0)
		return;
	if(arr[(at-1)/2] > arr[at]){
		swapInHeap(&arr[(at-1)/2],&arr[at]);
		goUp((at-1)/2,arr);
	}
	return;
}
void insertInHeap(long long int key,long long int arr[],long long int index,long long int max){
	if(index>=max)
		return;
	arr[index] = key;
	goUp(index,arr);
}

void goDown(long long int at,long long int upto,long long int arr[]){
	if(at>=upto)
		return;
	goDown((2*at)+1,upto,arr);
	goDown((2*at)+2,upto,arr);
	if((2*at)+2 < upto){
		if(arr[(2*at)+1]>arr[(2*at)+2])
			swapInHeap(&arr[(2*at)+1],&arr[(2*at)+2]);
		if(arr[(2*at)+1]<arr[at]){
			swapInHeap(&arr[(2*at)+1],&arr[at]);
			if(arr[(2*at)+1]>arr[(2*at)+2])
				swapInHeap(&arr[(2*at)+1],&arr[(2*at)+2]);
		}
	}
	else if((2*at)+1 < upto){
		if(arr[(2*at)+1]<arr[at])
			swapInHeap(&arr[(2*at)+1],&arr[at]);
	}
}

void rootDown(long long int arr[],long long int upto){
	for(long long int i=0;i<(upto/2);i++)
		goDown(i,upto,arr);
}

int main(){
	long long int arr[1000000];
	long long int n=0,temp;
	scanf("%lld",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&temp);
		insertInHeap(temp,arr,i,1000000);
		//arr[i] = temp;
	}
	//rootDown(arr,n);
	for(int i=0;i<n;i++)
		printf("%lld ",arr[i]);
	printf("\n");
	return 0;

}
/*

16
7 4 3 1 5 8 6 9 2 15 12 14 13 10 11 16

*/