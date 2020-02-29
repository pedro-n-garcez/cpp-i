#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

int currentFloor = 0;
int whereTo = 0;

typedef struct Node{
	struct Node *prev;
	int data;
	struct Node *next;
} node_t;

node_t *head;

void Append(int new_data){
	node_t *new_node = (struct Node*)malloc(sizeof(node_t));
	new_node->data = new_data;
	new_node->prev = NULL;
	new_node->next = NULL;
	
	node_t *last = head;
	if(head == NULL){
		head = new_node;
		return;
	}
	while (last->next != NULL){
		last = last->next;
	} last->next = new_node;
	new_node->prev = last;
}

bool search(int user_input){
	node_t *last = head;
	while(last != NULL){
		if(last->data == user_input){
			return true;
		}
		last = last->next;
	}
	return false;
}

node_t* get_node(int node_index) 
{
	int counter = 0;
    node_t* last = head;
    while (last != NULL) 
    { 
        if (counter == node_index)
            return last;
        counter++;
        last = last->next; 
    }      
}

void elevator()
{
    printf("We're on floor %d, the top floor is 15. Where to? ",currentFloor);
	scanf("%d",&whereTo);
	
	if (search(whereTo) == true){
		node_t* last = get_node(currentFloor);
		if(whereTo>currentFloor)
		{
	    	while(last->data != whereTo) {
		    	printf("%d\n",last->data);
		    	currentFloor++;
		    	last = last->next;
	    	} printf("DING! You're on floor %d.\n",currentFloor);
		} else if (whereTo<currentFloor)
		{
	    	while(last->data != currentFloor) {
		    	last = last->next;
	    	}
	    	while(last->data != whereTo) {
		    	printf("%d\n",last->data);
		    	currentFloor--;
		    	last = last->prev;
	    	} printf("DING! You're on floor %d.\n",currentFloor);
		} printf("Want to go to another floor? y/n ");
		char choice;
		scanf("%s",&choice);
		if (choice == 'y' || choice == 'Y'){
	    	elevator();
		}		
	} else {
		printf("That's not a valid floor, mate. Try again.\n");
		elevator();
	}
}

int main()
{
	for (int i = 0; i < 16; i++){
		Append(i);
	}
	printf("Evening. I'm the lift attendant and I'm here to take you where you want to go!\n");
	elevator();
	return 0;
}
