//implementation of circular linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node Node;
Node *head = NULL;
void insert_head(int val){
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = val;
	newNode->next = NULL;
	if(head == NULL){
		head = newNode;
		newNode->next = head;
	}
	else{
		Node *temp = head;
		while(temp->next != head){
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->next = head;
		head = newNode;
	}
	printf("\n");
}
void insert_tail(int val){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = val;
	newNode->next = NULL;
	if(head == NULL){
		newNode->next = head;
		head = newNode;
	}
	else{
		Node *temp = head;
		while(temp->next != head){
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->next = head;
	}
	printf("\n");
}
void delete_head(){
	if(head == NULL){
		printf("There are no nodes to delete.");
	}
	if(head->next == head){
		head = NULL;
	}
	else{
		Node *temp = head;
		while(temp->next!=head){
			temp = temp->next;
		}
		head = head->next;
		temp->next = head;
	}
	printf("\n");
}
void delete_tail(){
	if(head == NULL){
		printf("There are no nodes to delete.");
	}
	if(head->next == head){
		head = NULL;
	}
	else{
		Node *temp = head;
		while(temp->next->next != head){
			temp = temp->next;
		}
		temp->next = head;
	}
	printf("\n");
}
void display(){
	if(head == NULL){
		printf("No nodes to display.");
	}
	else{
		Node *temp= head;
		do {
			printf("%d ",temp->data);
			temp = temp->next;
		}while(temp != head);
	}
	printf("\n");
}
void display_n_nodes(){
	int n;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	Node *temp = head;
	if(head == NULL){
		printf("No nodes to display.");
		return;
	}
	for(int i=0; i<n; i++){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
int main()
{
	int ch;
	while(1){
		printf("1.Insert at head\n2.Insert at tail\n3.Delete at head\n4.Delete at tail\n5.Display\n6.Display n nodes\nAny other to exit\n");
		scanf("%d",&ch);
		if(ch==1){
			int val;
			printf("Enter value to insert: ");
			scanf("%d",&val);
			insert_head(val);
		}
		else if(ch==2){
			int val;
			printf("Enter value to insert: ");
			scanf("%d",&val);
			insert_tail(val);
		}
		else if(ch==3){
			delete_head();
		}
		else if(ch==4){
			delete_tail();
		}
		else if(ch==5){
			display();
		}
		else if(ch==6){
			display_n_nodes();
		}
		else{
			printf("Thank you!\n");
			break;
		}
	}
}
