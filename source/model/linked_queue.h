/*
    Charles Wilson
    
    snake_controller.h
    Header file for linked_queue
*/

#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

using namespace std;

//  Class implementing doubly linked list queue
class linked_queue
{
    // Class implementing linked list node
    public : class node
    {
        public:
            // coordinates of node
	        int x, y;
	        // pointers to previous and next nodes
	        node *next, *prev;
	        
	        /*
	            Constructor
	            
	            x   ->  x coordinate of node
	            y   ->  y coordinate of node
	        */
	        node(int x, int y);
	        
	        /*
	            Constructor
	            
	            x       ->  x coordinate of node
	            y       ->  y coordinate of node
	            prev    ->  node* to prev node
	            next    ->  node* to next node
	        */
	        node(int x, int y, node* prev, node* next);
    };

	private:
	    
	    // pointers to head and tail nodes
		node* head;
		node* tail;
	
	public:
	
	    linked_queue();
		
		~linked_queue();
		
		// returns head
		node* get_head();
		
		// returns tail
		node* get_tail();
		
		/*
		    enqueue new node at coordinats
		    
            x   ->  x coordinate of new node
	        y   ->  y coordinate of new node
		*/ 
		void enqueue(int x, int y);
		
		/*
		    enqueue node
		    
            new_node    ->  node to enqueue
		*/ 
		void enqueue(node* new_node);
		
		// dequeue and and return tail
		node* dequeue();
};

#endif
