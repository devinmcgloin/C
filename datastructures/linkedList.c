
#include <stdlib.h>
#include <stdio.h>

typedef struct{
	char * data;
	struct node * next;
} node;

void add_front(char* n, node ** head);
void remove_front(node ** head);
void pprint(node ** head);

int main(){

	node ** head = 0;
	add_front("hello", head);
	pprint(head);

}

void add_front(char * string, node ** head){
	node * n = (node *) malloc(sizeof(char));
	if(n == NULL){
		return;
	}
	n->data = string;
	n->next = *head;
	*head = n;
}

void pprint(node ** head){
	node * ptr = *(head);
	while(ptr->next != NULL){
		printf("%s",ptr->data);
		ptr++;
	}
}
