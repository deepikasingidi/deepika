/* Application of stack
 * Infix to Postfix Conversion
*/
#include<stdio.h>
#include<string.h>
int priority(char ch){
	if(ch=='*' || ch=='/') return 3;
	else if(ch=='+' || ch=='-') return 2;
	else return 1;
}
void in_to_postfix(char *infix){
	char postfix[101];
	char st[50];
	int top = -1,i,j=0;
	for(int i=0; i<strlen(infix); i++){
		int prio = priority(infix[i]);
		if(prio == 1){
			postfix[j] = infix[i];
			j++;
		}
		else{
			while(top!=-1 && prio <= priority(st[top])){
				postfix[j] = st[top];
				top--;
				j++;
			}
			top++;
			st[top] = infix[i];
		}
	}
	while(top != -1){
		postfix[j] = st[top];
		top--;
		j++;
	}
	for(int j=0; j<=strlen(infix); j++){
		printf("%c",postfix[j]);
	}
}
int main()
{
	char infix[101]; //the stirng will be given in infix form
	scanf("%s",infix);
	in_to_postfix(infix);
	return 0;
}
