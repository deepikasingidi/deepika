#include<stdio.h>
void insert(int *arr, int size, int key,int ind){
	for(int i=size-1; i>=ind; i--){
		arr[i+1]=arr[i];
		if(i==ind) arr[i]=key;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0; i<n-1; i++){
		scanf("%d",&arr[i]);
	}
	int ind , key;
	scanf("%d %d",&ind,&key);
	insert(arr, n, key, ind);
	for(int i=0; i<n; i++){
		printf("%d ",arr[i]);
	}
}
