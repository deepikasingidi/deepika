// BST - insertion , search and In-order traversal
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node TreeNode;
TreeNode *construct_BST(TreeNode *root, int val){
	//creat a treenode
	TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
	//populate the node
	newNode->data = val;
	newNode->left = NULL;
	newNode->right = NULL;
	//when root is NULL (tree is empty)
	if(root == NULL){
		return newNode;
	}
	TreeNode *curr = root, *parent = NULL;
	while(curr != NULL){
		parent = curr;
		if(val < curr->data){
			curr = curr->left;
		}
		else{
			curr = curr->right;
		}
	}
	if(parent->data > val){
		parent->left = newNode;
	}
	else{
		parent->right = newNode;
	}
}
void inOrder(TreeNode *root){
	if(root != NULL){
		inOrder(root->left);
		printf("%d ",root->data);
		inOrder(root->right);
	}
}
int search(TreeNode *root, int key){
	if(root == NULL){
		return 0;
	}
	TreeNode *curr = root;
	while(curr != NULL){
		if(key == curr->data){
			return 1;
		}else if (key < curr->data){
			curr = curr->left;
		}else{
			curr = curr->right;
		}
	}
	return 1;
}
int main(){
	TreeNode *root = NULL;
	int n;
	printf("Enter number of nodes: ");
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		int val;
		printf("Enter a value to node %d: ",i+1);
		scanf("%d",&val);
		root = construct_BST(root, val);
	}
	printf("InOrder is\n");
	inOrder(root);
	int key;
	printf("Enter a value to look: ");
	scanf("%d",&key);
	int result = search(root, key);
	if(result == 1) printf("Found");
	else printf("Not Found");
	return 0;
}
