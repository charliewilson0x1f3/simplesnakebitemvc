/*
    Charles Wilson
    
    linked_queue.cpp
    Implementation file for snake_model
*/

#include "snake_model.h"

snake_model::command::command(bool bit, int x, int y)
{
    this->bit = bit;
    this->is_food = false;
    this->x = x;
    this->y = y;
}

snake_model::command::command(bool bit, bool is_food, int x, int y)
{
    this->bit = bit;
    this->is_food = bit;
    this->x = x;
    this->y = y;
}

snake_model::snake_model(int width, int height)
{
    queue = linked_queue();
	// initialize head of list
	queue.enqueue(width/2, height/2);
	direction = UP;
    quit = false;
    this->width = width;
    this->height = height;
	
	// initialize bitmap
	for(int w = 0; w <= width; w++)
	{
	    vector<bool> v;
	    for(int h = 0; h <= height; h++)
	    {
	        v.push_back(false);
	    }
	    bitmap.push_back(v);
	}
	
	// seed rand
	srand(time(NULL));
}

snake_model::~snake_model()
{

}

void snake_model::set_bit(bool bit, int x, int y)
{
    bitmap[x - 1][y - 1] = bit;
}

snake_model::command snake_model::set_food()
{
    food_x = (rand() % width) + 1;
    food_y = (rand() % height) + 1;
    if(bitmap[food_x - 1][food_y - 1])
    {
        return set_food();
    }
    return command(PLACE, true, food_x, food_y);
}

vector<snake_model::command> snake_model::move()
{
    vector<snake_model::command> commands;
    int x = queue.get_head()->x;
    int y = queue.get_head()->y;
    int temp;

    switch(direction)
    { 
        case UP:
            temp = y;
            y--;
            if(y == 0)
            {
                y = height;
            }
            commands = set_move(x, y, x, temp); 
            break;
        case DOWN:
            temp = y;
            y++;
            if(y == height+1)
            {
                y = 1;
            }
            commands = set_move(x, y, x, temp);  
            break;
        case LEFT:
            temp = x;
            x--;
            if(x == 0)
            {
                x = width;
            }
            commands = set_move(x, y, temp, y); 
            break;
        case RIGHT:
            temp = x;
            x++;
            if(x == width+1)
            {
                x = 1;
            }
            commands = set_move(x, y, temp, y);
            break;
        default:
            break;
    }
    return commands;
}

vector<snake_model::command> snake_model::set_move(int x, int y, int temp_x, int temp_y)
{
    vector<snake_model::command> commands;
    linked_queue::node* new_node;
    bool eats_food = (x == food_x && y == food_y);
    
    if(eats_food)
    {
        new_node = new linked_queue::node(temp_x, temp_y);
    }
    else
    {
        new_node = queue.dequeue();
        commands.push_back(command(ERASE, new_node->x, new_node->y));
        set_bit(false, new_node->x, new_node->y);
    }                   
    if(bitmap[x - 1][y - 1])
    {
        quit = true;
    }
    new_node->x = x;
    new_node->y = y;
    queue.enqueue(new_node);
    commands.push_back(command(PLACE, new_node->x, new_node->y));
    if(eats_food)
    {
        commands.push_back(set_food());
    }
    set_bit(true, new_node->x, new_node->y);
    
    return commands;
}

int snake_model::get_direction()
{
    return direction;
}

void snake_model::set_direction(int direction)
{
    this->direction = direction;
}

bool snake_model::get_quit()
{
    return quit;
}

void snake_model::set_quit(bool quit)
{
    mtx.lock();
    this->quit = quit;
    mtx.unlock();
}
