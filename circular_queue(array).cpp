#include<stdio.h>
#include<stdlib.h>
int *q;
int size=0;
int front=0;
int cap;
int rear=cap-1;
void Enqueue(int val){
	if(size==cap){
		printf("Queue is full.");
	}
	else{
		rear = (rear+1)%cap;
		q[rear] = val;
		size++;
	}
	printf("\n");
}
void Dequeue(){
	if(size==0){
		printf("Queue is empty");
	}
	else{
		printf("%d is dequeued.",q[front]);
		front = (front+1)%cap;
		size--;
	}
	printf("\n");
}
void Display(){
	if(size==0){
		printf("Queue is empty.");
	}
	else{
		int i=front;
		while(i<){
			printf("%d ",q[i]);
			i = (i+1)%cap;
		}
	}
	printf("\n");
}
int main(){
	printf("Enter capacity of the queue:");
	scanf("%d",&cap);
	q = (int *)malloc(sizeof(int)*cap);
	int ch;
	while(1){
		printf("Enter\n1.Enqueue\n2.Dequeue\n3.Display\nAny other to exit\n");
		scanf("%d",&ch);
		if(ch==1){
			int val;
			printf("Enter a val to insert: ");
			scanf("%d",&val);
			Enqueue(val);
		}
		else if(ch==2){
			Dequeue();
		}
		else if(ch==3){
			Display();
		}
	}
}
