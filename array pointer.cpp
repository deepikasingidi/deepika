#include<stdio.h>
int main()
{
	int arr[5] = {10, 20, 30, 40, 50};
	int *ptr;
	for(ptr=arr; ptr<arr+5; ptr++){
		printf("%d ",*ptr);
	}
}
