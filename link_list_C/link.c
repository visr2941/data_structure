#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
//#include <link.h>


typedef struct node
{
	int16_t data;
	struct node * nxtptr;
} Node;

/* we use double pointer to avoid the change of head pointer in middle of the code when we are trying to delete the node 0 *
*  (good coding). If we have a double pointer, we will not change the head pointer even if we are deleting node 0.         */

void insert_node(Node **head, uint8_t pos, uint16_t data)
{
	uint8_t i=0;
	Node * temp=*head;
	Node * temp1=NULL;
	Node * node = (Node *) malloc(sizeof(Node));
	if(node==NULL)
		printf("Memory Error!");
	node->data = data;

	while(i<pos-1 && temp!=NULL)
	{
		temp1 = temp;
		temp = temp->nxtptr;
		i++;
	}
	node->nxtptr = temp;
	if(temp1==NULL)
	{
		*head = node;
	}
	else
		temp1->nxtptr = node;
	printf("Node inserted at location i=%d, position input %d\n", ++i, pos);
}

void print_list(Node ** head)
{
	Node * temp = *head;	
	while(temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->nxtptr;
	}
	printf("\n");
}

int8_t delete_node(Node ** head, uint8_t pos)
{
	uint8_t i=1;
	Node * temp1 = *head;
	Node * temp = NULL;
	printf("(trying to delete node no:%d)\n", pos);
	while(i!=pos)
	{
		if(temp1==NULL)
			{
				printf("error: node not in the list!\n\n");
				return -1;
			}
		temp = temp1;
		temp1 = temp1->nxtptr;
		i++;
	}
	if(pos==1)
		*head=temp1->nxtptr;
	else
		temp->nxtptr=temp1->nxtptr;
	free(temp1);
	printf("deleted node no:%d!\n", pos);
	return 0;
}

void reverse_list(Node ** head)
{
	Node * prev = NULL;
	Node * curr = *head;
	Node * fut = curr->nxtptr;
	
	while(fut!=NULL)
	{
		curr->nxtptr = prev;
		prev = curr;
		curr = fut;
		fut = curr->nxtptr;
	}
	curr->nxtptr = prev;
	*head = curr;
}

void reverse_recursive(Node ** head)
{
    if((*head)->nxtptr == NULL)
        return;
    
    Node * prev = *head;
    Node * curr = (*head)->nxtptr;
    
    reverse_recursive(&curr);
    
    prev->nxtptr->nxtptr = prev;
    prev->nxtptr = NULL;
	
    *head = curr;

    return;
}

/* list pointed by a and b are already sorted - merging the two 
** list in a single sorted list */
struct Node* SortedMerge(struct Node* a, struct Node* b) 
{ 
    struct Node * returnNode; 
    struct Node ** refNode = &returnNode; 

    while (1) 
    { 
        if (a == NULL) 
        { 
            /* if either list runs out, use the 
            other list */
            *refNode = b; 
            break; 
        } 
        else if (b == NULL) 
        { 
            *refNode = a; 
            break; 
        } 
        if (a->data <= b->data) 
        {
            *refNode = a;
            a = a->nxtptr;
        } 
        else
        {
		    *refNode = b;
            b = b->nxtptr; 
        }

        refNode = &((*refNode)->nxtptr);
    } 
    
    return returnNode; 
}

void reverse_recursive(listnode ** B)
{
    if((*B)->next == NULL)
        return;
    listnode * B_temp1 = *B;
    listnode * B_temp2 = (*B)->next;
    
    reverse_recursive(&B_temp2);
    
    B_temp1->next->next = B_temp1;
    B_temp1->next = NULL;
    
    *B = B_temp2;
    
    return;
}
 
int lPalin(listnode* A) {
    listnode * temp1 = A;
    listnode * temp2 = A;
    listnode * temp3 = A;
    
    while(temp2->next != NULL)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
        if(temp2->next != NULL)
            temp2 = temp2->next;
        else
            break;
    }
    
    reverse_recursive(&temp1);

    while(temp1 != NULL)
    {
        if(temp3->val != temp1->val)
            return 0;
        else
        {
            temp3 = temp3->next;
            temp1 = temp1->next;
        }
    }
    return 1;
}


main()
{
    	Node ** head = (Node **)malloc(sizeof(*head));
    	*head = NULL;
	insert_node(head, 1, -34);
	insert_node(head, 3, -7);
	insert_node(head, 4, 8);
	insert_node(head, 5, 100);
	insert_node(head, 6, -800);
	print_list(head);
	delete_node(head, 9);
	//delete_node(head, 2);
	//delete_node(head, 4);
	delete_node(head, 10);
	print_list(head);
	reverse_list(head);
	print_list(head);
	reverse_recursive(head);
	print_list(head);
}
