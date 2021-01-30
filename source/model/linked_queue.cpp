/*
    Charles Wilson
    
    linked_queue.cpp
    Implementation file for linked_queue
*/

#include "linked_queue.h"

linked_queue::node::node(int x, int y)
{
    this->x = x;
    this->y = y;
    this->prev = NULL;
    this->next = NULL;
}

linked_queue::node::node(int x, int y, node* prev, node* next)
{
    this->x = x;
    this->y = y;
    this->next = next;
    this->prev = prev;
}

linked_queue::linked_queue()
{
	head = NULL;
	tail = NULL;
}

linked_queue::~linked_queue()
{
    // free all node pointers
	node* prev = NULL;
	node* curr = head;
	if(head != NULL)
	{
		while(curr->next != NULL)
		{
			prev = curr;
			curr = curr->next;
			delete prev;
		}
		delete curr;
	}
}

linked_queue::node* linked_queue::get_head()
{
    return head;
}

linked_queue::node* linked_queue::get_tail()
{
    return tail;
}

void linked_queue::enqueue(int x, int y)
{
	node* new_node = new node(x, y, NULL, head);
	enqueue(new_node);
}

void linked_queue::enqueue(node* new_node)
{
    new_node->next = head;
    new_node->prev = NULL;
	head = new_node;
	if(new_node->next != NULL)
	{
	    new_node->next->prev = new_node;
	}
	else
	{
	    tail = new_node;
	}
}

linked_queue::node* linked_queue::dequeue()
{
    node* n = tail;
	if(head == NULL)
	{
		return NULL;
	}
	if(head == tail)
	{
		head = NULL;
		tail = NULL;
	}
	if(n->prev != NULL)
	{
		n->prev->next = NULL;
		tail = n->prev;
	}
	n->next = NULL;
	n->prev = NULL;
	return n;
}
