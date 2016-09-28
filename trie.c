#include <stdio.h>
#include <stdlib.h>

struct trieNodeList{
	struct characterNode *head;
};
struct trieNode{
	int endOfWord;
	struct trieNodeList *list;
}; 
struct characterNode{
	char value;
	struct characterNode *nextChar;
	struct trieNode *nextTrie;
};

typedef struct trieNodeList trieNodeList;
typedef struct trieNode trieNode;
typedef struct characterNode characterNode;

#define new_trieNodeList (trieNodeList *)malloc(sizeof(trieNodeList))
#define new_trieNode (trieNode *)malloc(sizeof(trieNode))
#define new_characterNode (characterNode *)malloc(sizeof(characterNode))

void insertInTrie(char word[],int length,trieNode **root){
	if(*root==NULL){
		(*root) = new_trieNode;
		(*root)->endOfWord = 0;
		(*root)->list = new_trieNodeList;
		(*root)->list->head = NULL;
	}
	trieNode *curr = *root;
	characterNode *temp = curr->list->head;
	int i=0;
	for(i=0;i<length;i++){
		temp = curr->list->head;
		while(temp!=NULL){
			if(temp->value ==  word[i])
				break;
			temp = temp->nextChar;
		}
		if(temp==NULL){
			temp = new_characterNode;
			temp->value = word[i];
			temp->nextChar = curr->list->head;
			curr->list->head = temp;
			temp->nextTrie = new_trieNode;
			temp->nextTrie->endOfWord = 0;
			temp->nextTrie->list = new_trieNodeList;
			curr = temp->nextTrie;
		}
		else
			curr = temp->nextTrie;
	}
	curr->endOfWord = 1;
}

int isEmpty(trieNode **root){
	if(*root==NULL)
		return 1;
	return 0;
}

int search(char word[],int length,trieNode **root){
	if(isEmpty(root))
		return 0;
	trieNode *curr = *root;
	characterNode *temp = curr->list->head;
	int i=0;
	for(i=0;i<length;i++){
		temp = curr->list->head;
		while(temp!=NULL){
			if(temp->value ==  word[i])
				break;
			temp = temp->nextChar;
		}
		if(temp==NULL){
			return 0;
		}
		else
			curr = temp->nextTrie;
	}
	return 1;
}

void printTrie(trieNode **root,int level){
	trieNode *curr = *root;
	characterNode *temp = curr->list->head;
	while(temp!=NULL){
		printf("%c At %d\n",temp->value,level);
		if(temp->nextTrie->endOfWord)
			printf("End of the Word\n");
		printTrie(&(temp->nextTrie),level+1);
		temp = temp->nextChar;
	}

}
int main(){
	trieNode *root = NULL;
	insertInTrie("abs",3,&root);
	insertInTrie("absd",4,&root);
	insertInTrie("abfg",4,&root);
	insertInTrie("abwer",5,&root);
	insertInTrie("rtyu",4,&root);
	printTrie(&root,0);	

	int temp = search("abs",3,&root); 
	if(temp)
		printf("Yes abs is in Trie\n");
	else
		printf("No abs is not in Trie\n");
	temp = search("abr",3,&root); 
	if(temp)
		printf("Yes abr is in Trie\n");
	else
		printf("No abr is not in Trie\n");
	temp = search("rt",2,&root); 
	if(temp)
		printf("Yes rt is in Trie\n");
	else
		printf("No rt is not in Trie\n");
	return 0;
}