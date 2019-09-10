/*
 * In this file, you will write the structures and functions needed to
 * implement a priority queue.  Feel free to implement any helper functions
 * you need in this file to implement a priority queue.  Make sure to add your
 * name and @oregonstate.edu email address below:
 *
 * Name: Melissa Barr 
 * Email: barrm@oregonstate.edu
 */

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "pq.h"
#include "dynarray.h"


#define PARENT(i) ((i-1)/2)
#define LEFT(i) ((2*i)+1)
#define RIGHT(i) ((2*i)+2)

//struct process {
//	int pid;
//};

//Looks good, goes with insert function
//struct element{
//	void* value;
//	int priority;
//};


/*
 * This is the structure that represents a priority queue.  You must define
 * this struct to contain the data needed to implement a priority queue.
 */

//Looks good
struct pq{
	struct dynarray* heap;
};

struct element{
        void* value;
        int priority;
};

/*
 * This function should allocate and initialize an empty priority queue and
 * return a pointer to it.
 */

//Looks good
struct pq* pq_create() {
	struct pq* pq = malloc(sizeof(struct pq));
	pq->heap = dynarray_create();
	return pq;
}


/*
 * This function should free the memory allocated to a given priority queue.
 * Note that this function SHOULD NOT free the individual elements stored in
 * the priority queue.  That is the responsibility of the caller.
 *
 * Params:
 *   pq - the priority queue to be destroyed.  May not be NULL.
 */

//Looks good
void pq_free(struct pq* pq) {
	assert(pq);
	//Loop through
/*	for(int i=0; i<dynarray_size(pq); i++)
	{
		struct element* e = dynarray_get(pq,i);
		if(e != NULL){
			free(e);
		}
	}*/
	dynarray_free(pq->heap);
	free(pq);
}


/*
 * This function should return 1 if the specified priority queue is empty and
 * 0 otherwise.
 *
 * Params:
 *   pq - the priority queue whose emptiness is to be checked.  May not be
 *     NULL.
 *
 * Return:
 *   Should return 1 if pq is empty and 0 otherwise.
 */
//Looks good
int pq_isempty(struct pq* pq) {
	if(dynarray_size(pq->heap) > 0){
		//return false which is 0
		return 0;
	}
	//Otherwise return true meaning 1 because then if it is not greater than 0 it is empty
	else{
		return 1;
	}
}


/*
 * This function should insert a given element into a priority queue with a
 * specified priority value.  Note that in this implementation, LOWER priority
 * values are assigned to elements with HIGHER priority.  In other words, the
 * element in the priority queue with the LOWEST priority value should be the
 * FIRST one returned.
 *
 * Params:
 *   pq - the priority queue into which to insert an element.  May not be
 *     NULL.
 *   value - the value to be inserted into pq.
 *   priority - the priority value to be assigned to the newly-inserted
 *     element.  Note that in this implementation, LOWER priority values
 *     should correspond to elements with HIGHER priority.  In other words,
 *     the element in the priority queue with the LOWEST priority value should
 *     be the FIRST one returned.
 */

//Begainning looks good, now use dynarray_insert
void pq_insert(struct pq* pq, void* value, int priority) {
//	struct process* proc = value;
	
	struct element* new_element = malloc(sizeof(struct element));
	new_element->value = value;
	new_element->priority = priority;

	int i = dynarray_size(pq->heap);
	
//	printf("My value BEFORE is: %5d with priority: %d\n", proc->pid, priority);
//	dynarray_insert(pq->heap, -1, new_element);
	dynarray_insert(pq->heap, i, new_element);
	
//	printf("Values are:%d\n", (*(int*)new_element->value));

	struct element* parent = dynarray_get(pq->heap, PARENT(i));
//	proc = dynarray_get(pq->heap, parent(i));
//	printf("My value AFTER is: %5d with priority: %d\n", proc->pid, priority);

/*
	while(parent->priority > new_element->priority && i>0){
		dynarray_set(pq->heap, PARENT(i), new_element);
		dynarray_set(pq->heap, i, parent);	
		i = PARENT(i);
		parent = dynarray_get(pq->heap, PARENT(i));
	}
*/

  	while(i>0){
	/*struct element**/ parent = dynarray_get(pq->heap, PARENT(i));
		if(parent->priority > new_element->priority){
			dynarray_set(pq->heap, PARENT(i), new_element);
			dynarray_set(pq->heap, i, parent);
			i = PARENT(i);
		}
		else{
			return;
		}
	
	}


	/*
	while((dynarray_get(pq->heap, PARENT(i))->priority) > new_element->priority && i != 0){
		dynarray_set(pq->heap, PARENT(i), new_element);
		dynarray_set(pq->heap, i, dynarray_get(pq->heap, PARENT(i)));
		i = PARENT(i);
	}*/

}


/*
 * This function should return the value of the first item in a priority
 * queue, i.e. the item with LOWEST priority value.
 *
 * Params:
 *   pq - the priority queue from which to fetch a value.  May not be NULL or
 *     empty.
 *
 * Return:
 *   Should return the value of the first item in pq, i.e. the item with
 *   LOWEST priority value.
 */
//Looks good
void* pq_first(struct pq* pq) {

//	assert(pq && !pq_isempty(pq));
	assert(pq);
	struct element* first_element = dynarray_get(pq->heap, 0);
	return first_element->value;


}


/*
 * This function should return the priority value of the first item in a
 * priority queue, i.e. the item with LOWEST priority value.
 *
 * Params:
 *   pq - the priority queue from which to fetch a priority value.  May not be
 *     NULL or empty.
 *
 * Return:
 *   Should return the priority value of the first item in pq, i.e. the item
 *   with LOWEST priority value.
 */
//Looks good
int pq_first_priority(struct pq* pq) {

	assert(pq);

	struct element* first_priority = dynarray_get(pq->heap, 0);
	return first_priority->priority;
}


/*
 * This function should return the value of the first item in a priority
 * queue, i.e. the item with LOWEST priority value, and then remove that item
 * from the queue.
 *
 * Params:
 *   pq - the priority queue from which to remove a value.  May not be NULL or
 *     empty.
 *
 * Return:
 *   Should return the value of the first item in pq, i.e. the item with
 *   LOWEST priority value.
 */
//Begainning looks good, needs a little more work
void* pq_remove_first(struct pq* pq) {
	assert(pq);
	struct element* first_element = dynarray_get(pq->heap, 0);
	struct element* temp_el = NULL;

	int size = dynarray_size(pq->heap); //this is the last element in the heap
	int i = size - 1;

	int left_priority = 0;
	int right_priority = 0;
	int current_priority = 0;

	//switch the first and last elements
	dynarray_set(pq->heap, 0, dynarray_get(pq->heap, i));//put the last element at the root
	dynarray_set(pq->heap, i, first_element);

	//remove last element which is now the old root
	dynarray_remove(pq->heap, i);

	i = 0;

	size = size -1;

	//percolate new root value down to its position
	//look at the left and right child priorities
	//	take smallest priority of the two
	//	check against your current priority
	//	if current value is greater than your smallest child priority value
	//		swap current and smallest child elements
	//		save child index as new current index
	//		repeat
	
	struct element* left_child = NULL;
	struct element* right_child = NULL;
	struct element* current_element = NULL;

	while(LEFT(i) < size || RIGHT(i) < size){

		if(LEFT(i) < size){
			left_child = dynarray_get(pq->heap, LEFT(i));
			left_priority = left_child->priority;
			right_child = NULL;
		}
		if(RIGHT(i) < size){
			right_child = dynarray_get(pq->heap, RIGHT(i));
			right_priority = right_child->priority;
			left_child = NULL;
		}

		current_element = dynarray_get(pq->heap, i);
		current_priority = current_element->priority;

		if(right_child == NULL || left_priority < right_priority){
			if(left_priority < current_priority) {
				temp_el = dynarray_get(pq->heap, LEFT(i));
				dynarray_set(pq->heap, LEFT(i), dynarray_get(pq->heap, i));
				dynarray_set(pq->heap, i, temp_el);
				i = LEFT(i);
			}else{
				break;
			}
		}else if(right_child != NULL){
			if(right_priority < current_priority){
				temp_el = dynarray_get(pq->heap, RIGHT(i));
				dynarray_set(pq->heap, RIGHT(i), dynarray_get(pq->heap, i));
				dynarray_set(pq->heap, i, temp_el);
				i = RIGHT(i);
			}
			else{
				break;
			}
		}
		else if(left_child == NULL && right_child == NULL){
			break;
		}

		else if(left_child != NULL && right_child != NULL){
			if(left_priority < right_priority){				
				if(left_priority < current_priority) {
                                	temp_el = dynarray_get(pq->heap, LEFT(i));
                               		 dynarray_set(pq->heap, LEFT(i), dynarray_get(pq->heap, i));
                               		 dynarray_set(pq->heap, i, temp_el);
                               		 i = LEFT(i);
				}
				else{
					break;
				}
			
			}
			else if(right_priority < left_priority){
				if(right_priority < current_priority){
                               		temp_el = dynarray_get(pq->heap, RIGHT(i));
                                       	dynarray_set(pq->heap, RIGHT(i), dynarray_get(pq->heap, i));
                               		dynarray_set(pq->heap, i, temp_el);
                              		i = RIGHT(i);
				}
				else{
					break;
				}
			}

		}
		left_priority = left_priority * 2;
		right_priority = right_priority * 2;
		temp_el = NULL;
//		right_child = NULL;
//		left_child = NULL;
		size = dynarray_size(pq->heap);
	}

	void* val = first_element->value;
	free(first_element);
	return val;
//	return first_element->value;

	/*
	   while(dynarray_size(pq->heap) != 0){
	   if(LEFT(i) >= dynarray_size(pq->heap) && RIGHT(i) >= dynarray_size(pq->heap))
	   break;


	   if(RIGHT(i) < dynarray_size(pq->heap) && LEFT(i) < dynarray_size(pq->heap))
	   if(LEFT(i) < RIGHT(i))
	   dynarray_set(pq->heap, LEFT(i), PARENT(i));
	   dynarray_set(pq->heap, i, dynarray_get(pq->heap, PARENT(i)));
	   i = PARENT(i);
	   dynarray_get((pq->heap, PARENT(i))->priority) > (LEFT(i)->priority);

	   if((dynarray_get(pq->heap, PARENT(i))->priority) >  new_element->priority);

	   if((dynarray_get(pq->heap, PARENT(i))->priority) <  new_element->priority);	
	   }

*/

}
