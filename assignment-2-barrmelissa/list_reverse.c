/*
 * This is the file in which you'll write a function to reverse a linked list.
 * Make sure to add your name and @oregonstate.edu email address below:
 *
 * Name: Melissa Barr
 * Email: barrm@oregonstate.edu
 */

#include <stdio.h>

#include "list_reverse.h"


//Returns 1 if there is a next link, returns 0 if the next link is the last link and returns -1 if iter is NULL
//int iterator_has_next(struct link* iter);
//int iterator_has_next(struct link* iter){
  //      if(iter != NULL){
    //            if(iter->next == NULL){
      //                  return 0;
        //        }
          //      return 1;
       // }

       // return -1;
//}
//int append_to_head(struct link* head, struct link* iter);
/*int append_to_head(struct link* head, struct link* iter){
        struct link* iter2 = head;
        if(iterator_has_next(iter2) == -1) {
                head = iter;
                return 0;
        }
        while(iterator_has_next(iter2) != 0){
                iter2 = iter2->next;
        }
        iter2->next = iter;

        return 0;
}


 * In this function, you will be passed the head of a singly-linked list, and
 * you should reverse the linked list and return the new head.  The reversal
 * must be done in place, and you may not allocate any new memory in this
 * function.
 *
 * Params:
 *   head - the head of a singly-linked list to be reversed
 *
 * Return:
 *   Should return the new head of the reversed list.  If head is NULL, this
 *   function should return NULL.
 */
struct link* list_reverse(struct link* head) {

//	//Initilizing the values

	struct link* previous_link = NULL;
	struct link* current_link = head;
	struct link* next_link;

	while(current_link != NULL){
		next_link = current_link->next;
		current_link->next = previous_link;
		previous_link = current_link;
		current_link = next_link;

	}
		head = previous_link;	
		return head;
}
	


