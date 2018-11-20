/***************************************************
 * Program filename: list.c
 * Author: Junhyeok Jeong
 * Date:6/10/2018
 * Description: function definitions for linked list with c
 * Input: each function's parameter
 * Output: changed node
****************************************************/

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/***********************************
 * Function: swap
 * Description: swapping node a with b
 * Parameters: struct node
 * Pre-Conditions: take 2 arguments as pointers
 * Post-Conditions: swapped nodes
***********************************/ 

struct node * swap(struct node *a, struct node *b) {
	struct node *temp;
	if (a->next != NULL) {
		temp = a;
		a->next = b->next;
		b->next = temp;
	}
	return b;
}
/***********************************
 * Function: length
 * Description: return length of whole node
 * Parameters: struct node
 * Pre-Conditions: take 1 argument as pointers
 * Post-Conditions: return an integer value
***********************************/ 

int length(struct node *head) {
	int count = 0;
	while (head != NULL) {
		count++;
		head = head->next;
	}
	return count;
}

/***********************************
 * Function: print
 * Description: print whole nodes from head to tail
 * Parameters: struct node
 * Pre-Conditions: take 2 arguments as pointer and integer
 * Post-Conditions: print all nodes
***********************************/ 

void print(struct node *head, int length) {
	int i;
	struct node *cur = head;
	if (cur == NULL) {
		printf("Warning !! the list is empty !\n");
	}
	printf("Your linked list is: \n");
	if (cur != NULL) {
		while (cur != NULL) {
			printf("%d ", cur->val);
			cur = cur->next;
		}
	}
	printf("\n");
}

/***********************************
 * Function: push
 * Description: add a node at beginning of linked list
 * Parameters: struct node, int
 * Pre-Conditions: take 2 arguments as pointer and integer
 * Post-Conditions: added a node at front of head
***********************************/ 

struct node * push(struct node *head, int value) {
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	new_node->val = value;
	new_node->next = head;
	head = new_node;
	return head;
}

/***********************************
 * Function: append
 * Description: add a node at the end of linked list
 * Parameters: struct node, int
 * Pre-Conditions: take 2 arguments as pointer and integer
 * Post-Conditions: added a node at the end of linked list
***********************************/ 

struct node * append(struct node *head, int value) {
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	struct node *cur = NULL;
	if (head == NULL) {
		new_node->val = value;
		new_node->next = NULL;
		head = new_node;
		return head;
	}
		cur = head;
		while (cur->next != NULL) {
			cur = cur->next;
		}
		new_node->val = value;
		new_node->next = NULL;
		cur->next = new_node;
	return head;
	
}

/***********************************
 * Function: clear
 * Description: delete whole nodes in the linked list
 * Parameters: struct node
 * Pre-Conditions: take 1 argument as pointer 
 * Post-Conditions: no memeory leak
***********************************/ 

struct node * clear(struct node *head) {

	struct node *cur = NULL;
	while (head->next != NULL) {
		cur = head;
		head = head->next;
		free(cur);
		
	}
	if (head->next == NULL) {
		free(head);
		
	}
	printf("linked list clearing is completed! \n");
	return NULL;
	
}

/***********************************
 * Function: remove_node
 * Description: delete particular node by index
 * Parameters: struct node, int
 * Pre-Conditions: take 2 arguments as pointer and integer
 * Post-Conditions: changed linked list
***********************************/ 

struct node * remove_node(struct node *head, int place_value) {
	int i=1;
	struct node *cur = head;
	struct node *prev_node;
	if (place_value > length(head) || place_value < 1) {
		printf("Check your position number!! (1 ~ length of list)\n");
		return head;
	}

	if (cur != NULL && place_value == 1) {
		head = cur->next;
		free(cur);
		return head;
	}

	while (cur != NULL && place_value !=i ) {
		prev_node = cur;
		cur = cur->next;
		i = i + 1;
	}
	if (cur == NULL) {
		printf("There is no value same as your input value, check your input!\n");
		return head; }

	prev_node->next = cur->next;
	free(cur);
	return head;
}

/***********************************
 * Function: sort_ascending
 * Description: sorting a linked list with ascending order
 * Parameters: struct node
 * Pre-Conditions: take 1 argument as pointer
 * Post-Conditions: sorted linked list
***********************************/ 

struct node * sort_ascending(struct node *head) {
	if (head == NULL) {
		return NULL; }

	if (head->next != NULL) {
		if (head->val > head->next->val) {
			head = swap(head, head->next);
		}
	}

	head->next = sort_ascending(head->next);

	if (head->next != NULL) {
		if (head->val > head->next->val) {
			head = swap(head, head->next);
			head->next = sort_ascending(head->next);
		}
	}
	return head;
}

/***********************************
 * Function: sort_descending
 * Description: sorting a linked list with descending order
 * Parameters: struct node
 * Pre-Conditions: take 1 argument as pointer
 * Post-Conditions: sorted linked list
***********************************/ 

struct node * sort_descending(struct node *head) {
	if (head == NULL) {
		return NULL; }

	if (head->next != NULL) {
		if (head->val < head->next->val) {
			head = swap(head, head->next);
		}
	}

	head->next = sort_descending(head->next);

	if (head->next != NULL) {
		if (head->val < head->next->val) {
			head = swap(head, head->next);
			head->next = sort_descending(head->next);
		}
	}
	return head;

}
/***********************************
 * Function: insert_middle
 * Description: insert node with value in particular node
 * Parameters: struct node,int,int
 * Pre-Conditions: take 3 arguments as pointer and int
 * Post-Conditions: changed linked list
***********************************/ 

struct node * insert_middle(struct node *head, int val, int idx){
	int i;
	if (idx > length(head) || idx < 1) {
		printf("Check your position number!!(1 ~length of list)\n");
		return head;
	}
	
	struct node *new_node = (struct node*)malloc(sizeof(struct node));
	struct node *temp = head;
	new_node->val = val;

	if (idx == 1) {
		new_node->next = head;
		head = new_node;
		return new_node;
	}
	else {
		for (i = 0; i < length(head); i++)
		{
			if (i == idx - 2) {
				new_node->next = temp->next;
				temp->next = new_node;

			}
			if (temp->next != NULL) {
				temp = temp->next;
			}
		}
	}
	return head;
}

			
