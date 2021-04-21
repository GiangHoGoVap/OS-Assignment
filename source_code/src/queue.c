#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */
	if (q->size == MAX_QUEUE_SIZE) return;
	q->proc[q->size++] = proc;	
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	if (q->size == 0) return NULL;
	int highestPriority = 0, pos;
	for (int i=0; i<q->size; i++){
		if (highestPriority < q->proc[i]->priority){
			highestPriority = q->proc[i]->priority;
			pos = i;
		}
	}
	struct pcb_t * res = q->proc[pos];
	for (int i=pos+1; i<q->size; i++){
		q->proc[i-1] = q->proc[i];
	}
	q->size--;
	return res;
}

