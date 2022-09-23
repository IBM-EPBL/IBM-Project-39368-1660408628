/*This file ocntains the implementation of list ADT operations */
/* include header files */
#include "E:\DS\LIST\LList.h"
/********************************************************************/
/* Name	of the function		:	insertElement	                    */
/* Description		        :   inserts the new element at the end  */
/* Inputs			        :	int value               	        */
/* Outputs			        :	void                            	*/
/* Bugs / Limitations       :   This function do not handle         */
/*                             insertion at the beginning and middle*/
/********************************************************************/
void insertElement(int value)
{
	NODE *new_node ;  /* used for creating new node */
	NODE *temp ;      /* used for traversing the list */

	/* create a new node and update the data and next fields */
	new_node = (NODE *)malloc(sizeof(struct node)) ;
	new_node->data = value ;
	new_node->next = NULL ;

	/* temp is initialized to point to the first node in the list */
	temp = first ;

	/* if the list is empty, make the new node as the first node in the list */
	if (temp == NULL) /* insertion in an empty list */
	{
		first = new_node ;
    }
	else /* else insert at the end of the list */
	{    /* this function do not take care of insertion at the beginning and middle */
		/*traverse the list till the end is reached */
		while ( temp->next != NULL) /* traverse the list till the last node is reached*/
		{
			temp = temp->next ;
		}
		/* last node is reached, make the next field of last node (temp) point to the new_node, new_node is the last node now*/
		temp->next = new_node ;
	}
} /*end of function insert */


/***********************************************************************/
/* Name	of the function	:	deleteElement	                           */
/* Description		    :   Deletes the specified element in the list  */
/* Inputs			    :	int value                                  */
/* Outputs			    :	void    	                               */
/* Bugs / Limitations   :   none                                       */
/***********************************************************************/
void deleteElement(int value)
{
	NODE *temp;  /* used for traversing the list */
	NODE *prev ; /* used to remember the previous node while traversing the list */

    /* both temp and prev are pointing to the first node initially */
	temp = first ;
	prev = first ;

     /*traverse the list till the item to be deleted or end of the list is reached */
	while ( (temp!=NULL) && (temp->data != value) )
	{
		prev = temp ;       /* prev is assigned the current node (temp)*/
		temp = temp->next ; /* temp is moving to the next node */
	}

	/*if temp is NULL we reached the end of the list */
	/* the given item is not found in the list */
	if (temp == NULL)
	{
		printf ("The item to be deleted, %d,is not found in the list\n", value) ;
	}
	else /* temp  points to the item to be deleted */
	{
		if (temp == first) /* deletion at the beginning */
		{
		    if (temp->next == NULL) /* deletion in one-element list*/
            {
                /*after deleting the only node in the list, the list is empty, so make first as null */
                first = NULL ;
            }
            else  /* There are more than one element in the list */
            {
                 /* after deleting the first element in the list, first should point to the second element in the list */
                 first = first->next ;
            }
        } /* end of if (temp == first) */
		else /* deletion at the middle or end */
		{
			prev->next = temp->next ;
        }
        /* after deletion, it is essential to free the memory allotted to the deleted node, which is pointed by temp */
        free (temp) ;
	} /* end of else - temp  points to the item to be deleted */

} /* end of function delete */
/****************************************************************************/
/* Name	of the Function	:	isEmpty                     	                */
/* Description		    :   returns 1, if the list is empty else returns 0  */
/* Inputs			    :	none                                        	*/
/* Outputs			    :	int (1 or 0)                                   	*/
/****************************************************************************/
int isEmpty()
{
	if (first == NULL)
	{
		return TRUE ;
	}
	else
	{
		return FALSE ;
	}
} /* end of function isEmpty */


/**********************************************************************/
/* Name of the Function  :	displayList	                              */
/* Description		     :  prints the elements in the list           */
/* Inputs			     :	none                                      */
/* Outputs			     :	void                                      */
/**********************************************************************/
void displayList()
{
	NODE *temp ;
	temp = first ;

	printf ("\nThe list elements are printed below:\n") ;

	/*traverse the list and print the elements till the end*/
	while (temp->next != NULL)
	{
		printf ("%d->", temp->data) ;
		temp = temp->next ;
	}
	/* to print the last element */
	printf ("%d->NULL", temp->data) ;
    printf ("\n") ;
} /* end of displayList */

