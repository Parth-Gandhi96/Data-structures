#include <stdio.h>
#include <stdlib.h>

struct queueNode{
	int data;
	struct queueNode *next;	
	struct queueNode *tail;
};

typedef struct queueNode queueNode;
#define new_queueNode (queueNode *)malloc(sizeof(queueNode))

int isEmpty(queueNode **head){
	if(*head==NULL)
		return 1;
	return 0;
}

void enQueue(int key,queueNode **head){
	if(*head==NULL){
		*head = new_queueNode;
		(*head)->tail = *head;
		(*head)->data = key;
		(*head)->next = NULL;
		return;
	}
	queueNode *temp = (*head)->tail;
	temp->next = new_queueNode;
	temp = temp->next;
	temp->data = key;
	temp->next = NULL;
	(*head)->tail = temp;
}

queueNode* deQueue(queueNode **head){
	if(isEmpty(head))
		return NULL;
	queueNode *temp = *head;
	*head = (*head)->next;
	if(*head!=NULL){
		(*head)->tail = temp->tail;
	}
	return temp;
}

void printQueue(queueNode **head){
	queueNode *temp = *head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
int main(){
	queueNode *head = NULL;
	
	printf("Enqueue 1:-\n");
	enQueue(1,&head);
	printQueue(&head);
	printf("Enqueue 2:-\n");
	enQueue(2,&head);
	printQueue(&head);
	printf("Enqueue 3:-\n");
	enQueue(3,&head);
	printQueue(&head);
	printQueue(&head);
	

	printf("DeQueue:-\n");
	queueNode *temp =  deQueue(&head);
	if(temp!=NULL)
		printQueue(&head);
	else
		printf("No element in Queue\n");
	printf("DeQueue:-\n");
	temp = deQueue(&head);
	if(temp!=NULL)
		printQueue(&head);
	else
		printf("No element in Queue\n");
	printf("DeQueue:-\n");
	temp = deQueue(&head);
	if(temp!=NULL)
		printQueue(&head);
	else
		printf("No element in Queue\n");
	printf("DeQueue:-\n");
	temp = deQueue(&head);
	if(temp!=NULL)
		printQueue(&head);
	else
		printf("No element in Queue\n");
	return 0;
}