#include "list.h"
#include <stdio.h>
#include <stdlib.h>
/******************************************************************************
 ** Program: Assignment5: Linked list
 ** Author: Zach Bishop
 ** Date: 6/9/2018
 ** Description: Provides functions needed to modify and create a linked list
 ** Input: Depend on function used
 ** Output: Depends on function used
*****************************************************************************/


/******************************************************************************
 ** Function: length
 ** Description: Gets the number of nodes in a linked list
 ** Parameters: struct node* head
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
int length(struct node* head) {
	struct node* current = head;
	int length = 0;

	while (current != NULL) {
		current = current->next;
		length++;
	}

	return length;
}

/******************************************************************************
 ** Function: print
 ** Description: prints values in a linked list dependent on how many are wanted
 ** Parameters: struct node* head, int num
 ** Pre-Conditions: None
 ** Post-Conditions: None
*****************************************************************************/
void print(struct node* head, int numNodes) {
	struct node* current = head;

	//Only print stuff if there is a linked list
	if (head != NULL) {
		int i;
		for (i = 0; i < numNodes; i++) {
			if (current != NULL) {
				printf("Node %d value: %d \n", (i+1), current->val);
				current = current->next;
			}
		}
	}
}

/******************************************************************************
 ** Function: push
 ** Description: Puts a new node at the front of a linked list
 ** Parameters: struct node* head, int num
 ** Pre-Conditions: None
 ** Post-Conditions: New node at front
*****************************************************************************/
struct node* push(struct node* head, int num) {
  //Make the new node to be added
	struct node* newNode = malloc(sizeof(struct node));
  newNode->val = num;
  //Point the node to the current "first" node
	newNode->next = head;

	//Point the head to the new node which is now the first node
	head = newNode;
	return head;
}

/******************************************************************************
 ** Function: append
 ** Description: Puts a node at the end of a linked list
 ** Parameters: struct node* head, int num
 ** Pre-Conditions: None
 ** Post-Conditions: New node at the end
*****************************************************************************/
struct node* append(struct node* head, int num) {
	//Point to the head with a pointer that will traverse the list
  struct node* current = head;
	//Make the new node
  struct node* newNode = malloc(sizeof(struct node));
  newNode->val = num;
  newNode->next = NULL;

	if (head != NULL) {
  	//Get to the end of the list
  	while (current->next != NULL) {
  	  current = current->next;
  	}
		//Push the newNode to the end
  	current->next = newNode;
	}
	else {
		//If there is no linked list, make the start
		head = newNode;
	}


  return head;
}

/******************************************************************************
 ** Function: clear
 ** Description: Deletes all nodes
 ** Parameters: struct node* head
 ** Pre-Conditions: None
 ** Post-Conditions: All nodes deleted
*****************************************************************************/
struct node* clear(struct node* head) {
	int i;
	struct node* current = head;

	//Go through entire list
	while (head != NULL){
		//Move head to the next one in the list
		head = head->next;

		//Delete the first node
		free(current);

		//Move current to where head is
		current = head;
	}

	return head;
}

/******************************************************************************
 ** Function: sort_ascending
 ** Description: Sorts the nodes in ascending order
 ** Parameters: struct node* head
 ** Pre-Conditions: None
 ** Post-Conditions: Sorted
*****************************************************************************/
struct node* sort_ascending(struct node* head) {
	struct node* current = head;
	int i = 0;

	//Keep sorting till the end of the list is reached
	while (current->next != NULL) {
		//If the two nodes next to each other are out of order, swap them
		if (current->val > current->next->val) {
			struct node* c = head;
			struct node* temp = head;

			//Swap is different if the first two are being swapped
			if (i == 0) {
				//Rearrange pointers as needed
				c = head;
				head = c->next;
				c->next = head->next;
				head->next = c;
			}
			//Swap if its not the first two
			else {
				//point current to the node before the first one to be swapped
				int j;
				for (j = 0; j < i-1; j++) {
					c = c->next;
				}

				//point temp to the first node you want to swap
				for (j = 0; j < i; j++) {
					temp = temp->next;
				}

				//Rearrange pointers as needed
				c->next = temp->next;
				temp->next = c->next->next;
				c->next->next = temp;
			}

			//Set current back to the beginning of the list and go through it again
			current = head;
			i=0;
		}
		else {
			//If nothing needs to be switched, advance through the list
			current = current->next;
			i++;
		}
	}

	return head;
}

/******************************************************************************
 ** Function: sort_descending
 ** Description: sorts nodes in descending order
 ** Parameters: struct node* head
 ** Pre-Conditions: None
 ** Post-Conditions: Sorted
*****************************************************************************/
struct node* sort_descending(struct node* head) {
	struct node* current = head;
	int i = 0;

	//Keep sorting till the end of the list is reached
	while (current->next != NULL) {
		//If the two nodes next to each other are out of order, swap them
		if (current->val < current->next->val) {
			struct node* c = head;
			struct node* temp = head;

			//Swap is different if the first two are being swapped
			if (i == 0) {
				//Rearrange pointers as needed
				c = head;
				head = c->next;
				c->next = head->next;
				head->next = c;
			}
			//Swap if its not the first two
			else {
				//point current to the node before the first one to be swapped
				int j;
				for (j = 0; j < i-1; j++) {
					c = c->next;
				}

				//point temp to the first node you want to swap
				for (j = 0; j < i; j++) {
					temp = temp->next;
				}

				//Rearrange pointers as needed
				c->next = temp->next;
				temp->next = c->next->next;
				c->next->next = temp;
			}

			//Set current back to the beginning of the list and go through it again
			current = head;
			i=0;
		}
		else {
			//If nothing needs to be switched, advance through the list
			current = current->next;
			i++;
		}
	}

	return head;
}

/******************************************************************************
 ** Function: insert_middle
 ** Description: inserts a new node in the middle of a list
 ** Parameters: struct node* head, int val, int idx
 ** Pre-Conditions: None
 ** Post-Conditions: New node in the middle
*****************************************************************************/
struct node* insert_middle(struct node* head, int val, int idx) {
	struct node* current = head;
	struct node* temp;
	struct node* newNode = malloc(sizeof(struct node));
	newNode->val = val;

	int i;
	//point current to the spot right before where you want to insert the new node
	for (i = 0; i < idx-1; i++) {
		current = current->next;
	}

	//Point temp to the node after current, the new node will be inserted between current and temp
	temp = current->next;

	//Point the node current is pointing to to the new node
	current->next = newNode;

	//Point the new node to the node temp is pointing to
	newNode->next = temp;

	return head;
}
