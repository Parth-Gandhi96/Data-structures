#include <stdio.h>
#include <stdlib.h>
int sizeOfLinkedList=0;
struct node{
	int data;
	struct node *next;
	struct node *pre;		
}*head=NULL;
#define newNode (struct node *)malloc(sizeof(struct node))
void setAfter(int key,struct node *a){
	struct node *temp = newNode;
	temp->data = key;
	temp->pre = a;
	if(a->next!=NULL){
		temp->next = a->next;
		temp->next->pre = temp;
	}
	else
		temp->next==NULL;
	a->next = temp;
}
void reverseLinkedList(int from,int to){
	from = from<to?from:to;
	to = from<to?to:from;
	if(to > sizeOfLinkedList){
		printf("index must be less than the size of linkedList - %d\n",sizeOfLinkedList);
		return;
	}
	if(from==to)					// Revering one element willnot affect the linked
		return;
	struct node *a = head;
	while(from-- > 1)
		a = a->next;
	struct node *b = head;
	while(to-- > 1)
		b = b->next;
	while()

}
void insertAt(int key,int index){
	if(index > sizeOfLinkedList+1){
		printf("index must be less than the size of linkedList - %d +1 \n",sizeOfLinkedList);
		return;
	}
	struct node *curr = head;
	if(head==NULL || index==1){
		head = newNode;
		head->data = key;
		head->next = curr;
		head->pre = NULL;
		if(curr!=NULL){
			curr->pre = head;
		}
	}
	else{
		while(index > 2){
			curr = curr->next;
			index--;
		}
		setAfter(key,curr);
	}
	sizeOfLinkedList++;
}
struct node* deletAt(int index){
	if(index > sizeOfLinkedList){
		printf("index must be less than the size of linkedList - %d\n",sizeOfLinkedList);
		return NULL;
	}
	struct node *curr = head; 
	while(index-- > 1)
		curr = curr->next;
	if(curr->pre!=NULL)
		curr->pre->next = curr->next;
	else
		head = curr->next;
	if(curr->next!=NULL)
		curr->next->pre = curr->pre;
	curr->next = NULL;
	curr->pre = NULL;
	sizeOfLinkedList--;
	return curr;
}
void displayLinkedList(){
	struct node *curr = head;
	while(curr!=NULL){
		printf("%d ",curr->data);
		curr = curr->next;
	}
	printf("\n");
}
int main(){
	insertAt(6,1);
	displayLinkedList();
	insertAt(5,1);
	displayLinkedList();
	insertAt(4,1);
	displayLinkedList();
	insertAt(3,1);
	displayLinkedList();
	insertAt(2,1);
	displayLinkedList();
	insertAt(1,1);
	displayLinkedList();

	reverseLinkedList(1,6);


	struct node *temp;
	temp = deletAt(1);
	displayLinkedList();
	temp = deletAt(1);
	displayLinkedList();
	temp = deletAt(1);
	displayLinkedList();
	return 0;
}
/*

Indexing is 1-indexed & INTEGER data is stored in linked list

*/