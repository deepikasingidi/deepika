#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node *prev;
	int data;
	struct node *next;
};
typedef struct node Node;
Node *head = NULL;
Node *tail = NULL;

void insert_head(int val){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->prev = NULL;
	newNode->data = val;
	newNode->next = NULL;
	if(head==NULL && tail==NULL){
		head = newNode;
		tail = newNode;
	}
	else{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
}

void insert_tail(int val){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->prev = NULL;
	newNode->data = val;
	newNode->next = NULL;
	if(head==NULL && tail==NULL){
		head = newNode;
		tail = newNode;
	}
	else{
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
}

void delete_head(){
	if(head==NULL && tail==NULL){
		printf("No nodes to delete.\n");
	}
	else if(head==tail){
		Node *todelete = head;
		head = NULL;
		tail = NULL;
		free(todelete);
	}
	else{
		Node *todelete = head;
		head = head->next;
		head->prev = NULL;
		free(todelete);
	}
}

void delete_tail(){
	if(head==NULL && tail==NULL){
		printf("No nodes to delete.\n");
	}
	else if(head==tail){
		Node *todelete = head;
		head = NULL;
		tail = NULL;
		free(todelete);
	}
	else{
		Node *todelete = tail;
		tail = tail->prev;
		tail->next = NULL; 
		free(todelete);
	}
}
void display_forward(){
	if(head==NULL && tail==NULL){
		printf("There are no nodes to display.\n");
	}
	else{
		Node *temp = head;
		while(temp != NULL){
			printf("%d ",temp->data);
			temp = temp->next;
		}
		printf("\n");
	}
}

void display_backward(){
	if(head==NULL && tail==NULL){
		printf("There are no nodes to display.\n");
	}
	else{
		Node *temp = tail;
		while(temp != NULL){
			printf("%d ",temp->data);
			temp = temp->prev;
		}
		printf("\n");
	}
}
int main()
{
	int ch;
	while(1){
		printf("Enter\n1. insert at head\n2. Insert at tail\n3. delete at head\n4.delete at tail\n5. Display forward\n6. Display backward\nAny other to exit\n");
		scanf("%d",&ch);
		if(ch == 1){
			//implement insert at head
			int val;
			printf("Enter a value to insert at head: ");
			scanf("%d",&val);
			insert_head(val);
		}
		else if(ch == 2){
			//implement insert at tail
			int val;
			printf("Enter a value to insert at head: ");
			scanf("%d",&val);
			insert_tail(val);
		}
		else if(ch == 3){
			//implement delete at head
			delete_head();
		}
		else if(ch == 4){
			//implement delete at tail
			delete_tail();
		}
		else if(ch == 5){
			//implement
			display_forward();
		}
		else if(ch == 6){
			display_backward();
		}
		else{
			printf("Thank you!");
			break;
		}
	}
}
