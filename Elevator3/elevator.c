#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

int currentFloor = 0;
int chosenAmount = 0;
bool swap = true;
int temp = 0;

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
    printf("We're on floor %d, the top floor is 15. How many floors do you want to visit?\n",currentFloor);
    scanf("%d",&chosenAmount);
   
    int whereTo[chosenAmount];
    size_t wt_len = sizeof(whereTo)/sizeof(whereTo[0]);
   
    for (int i = 0; i < wt_len; i++)
    {
        printf("Floor number: ");
        scanf("%d",&whereTo[i]);
    }
    
    //FIND IF IN LIST
    bool invalid_element;
    bool invalid_input = false;
    for(int i = 0; i<wt_len;i++){
    		invalid_element = true;
    		node_t *last = head;
    		while(last != NULL){
				if(last->data == whereTo[i]){
					invalid_element = false;
				}
			last = last->next;
		}
		if (invalid_element == true){
			invalid_input = true;
		}		
	}
    
	if (invalid_input == false)
	{
		//sorting
        while (swap == true)
        {
            swap = false;
            for (int i = 0; i < wt_len - 1; i++)
            {
                if (whereTo[i] > whereTo[i+1])
                {
                    temp = whereTo[i];
                    whereTo[i] = whereTo[i+1];
                    whereTo[i+1] = temp;
                    swap = true;
                }
            }
        }
        
        printf("Mind the gate...");
		node_t* last = get_node(currentFloor);
		for (int i = 0; i < wt_len; i++)
		{
			if(currentFloor <= whereTo[i])
			{
	    	while(last->data != whereTo[i]) {
	    		printf("%d\n",last->data);	    			
		    	currentFloor++;
		    	last = last->next;
	    	} printf("DING! You're on floor %d.\n",currentFloor);
			} else if (currentFloor >= whereTo[i])
			{
	    		while(last->data != currentFloor) {
		    		last = last->next;
	    		}
	    		while(last->data != whereTo[i]) {
	    			printf("%d\n",last->data);	    			
		    		currentFloor--;
		    		last = last->prev;
	    		} printf("DING! You're on floor %d.\n",currentFloor);
			}
		}
		printf("Want to go to another floor? y/n ");
		char choice;
		scanf("%s",&choice);
		if (choice == 'y' || choice == 'Y'){
	    	elevator();
		}		
	} else if (invalid_input == true) {
		printf("You input an invalid floor, mate. Try again.\n");
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
