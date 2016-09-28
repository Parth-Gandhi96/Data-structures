#include <stdio.h>
#include <stdlib.h>

struct stackNode{
	int data;
	struct stackNode *next;
};

typedef struct stackNode stackNode;
#define new_stackNode (stackNode *)malloc(sizeof(stackNode))


void push(int key,stackNode **top){
	stackNode *temp = new_stackNode;
	temp->data = key;
	temp->next = *top;
	*top = temp;
}

stackNode* pop(stackNode **top){
	if((*top)==NULL)
		return NULL;
	stackNode *temp = *top;
	*top = temp->next;
	temp->next = NULL;
	return temp;
}

stackNode* peek(stackNode **top){
	return *top;
}

int isEmpty(stackNode **top){
	if(*top == NULL)
		return 1;
	return 0;
}

void printStack(stackNode **top){
	stackNode *curr = *top;
	while(curr!=NULL){
		printf("%d ",curr->data);
		curr = curr->next;
	}
	printf("\n");
}

int main(){
	stackNode *top = NULL;

	printf("Pushing 1:-\n");
	push(1,&top);
	printStack(&top);
	printf("Pushing 2:-\n");
	push(2,&top);
	printStack(&top);
	printf("Pushing 3:-\n");
	push(3,&top);
	printStack(&top);
	printf("Pushing 4:-\n");
	push(4,&top);
	printStack(&top);


	printf("Poping:-\n");
	stackNode *temp = pop(&top);
	if(temp!=NULL)
		printf("poped element is %d\n",temp->data);
	else
		printf("No Element in stack\n");
	printStack(&top);
	printf("Poping:-\n");
	temp = pop(&top);
	if(temp!=NULL)
		printf("poped element is %d\n",temp->data);
	else
		printf("No Element in stack\n");
	printStack(&top);
	printf("Poping:-\n");
	temp = pop(&top);
	if(temp!=NULL)
		printf("poped element is %d\n",temp->data);
	else
		printf("No Element in stack\n");
	printStack(&top);
	printf("Poping:-\n");
	temp = pop(&top);
	if(temp!=NULL)
		printf("poped element is %d\n",temp->data);
	else
		printf("No Element in stack\n");
	printStack(&top);
	printf("Poping:-\n");
	temp =pop(&top);
	if(temp!=NULL)
		printf("poped element is %d\n",temp->data);
	else
		printf("No Element in stack\n");
	printStack(&top);
	

	
	
	
	return 0;
}
