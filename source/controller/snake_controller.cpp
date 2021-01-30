/*
    Charles Wilson
    
    snake_controller.cpp
    Implementation file for snake_controller
*/

#include "snake_controller.h"

snake_controller::snake_controller(int width, int height, int difficulty)
{
    // initialize model and view
    model = new snake_model(width, height);
    view = new snake_view(width, height);
    
    // set difficulty level
    this->difficulty = difficulty;

	// show head
	show_link(width/2, height/2);

	// start reading keystrokes
	input_thread = thread(&snake_controller::input, this);
	
	// set food
	snake_model::command command = model->set_food();
	view->print_food(command.x, command.y);
	
	// start moving snake
	this->motion();
}
	
snake_controller::~snake_controller()
{
    // wait for thread to end
    input_thread.join();
    // free objects
    delete model;
    delete view;
}
	
void snake_controller::motion()
{
    // loop until quit signal
    while(!model->get_quit())
    {
        // sleep for amount specified in difficulty
        this_thread::sleep_for(chrono::milliseconds(difficulty));
        
        // move snake data and get display commands
        vector<snake_model::command> commands = model->move();
        
        // hand display commands to view
        for(snake_model::command c : commands)
        {
            // PLACE command
            if(c.bit)
            {
                // show food
                if(c.is_food)
                {
                    view->print_food(c.x, c.y);
                }
                // show snake link
                else
                {
                    show_link(c.x, c.y);
                }
            }
            // REMOVE command (snake link)
            else
            {
                remove_link(c.x, c.y);
            }
        }
    }
    
    // display game over text
    view->game_over();
}
	
void snake_controller::show_link(int x, int y)
{
    // display link
    view->print_link(x, y);
    
    // set bitmap to represent link
	model->set_bit(true, x, y);
}

void snake_controller::remove_link(int x, int y)
{
    // erase link
    view->erase_link(x, y);
    
    // set bitmap to remove link
	model->set_bit(false, x, y);
}
	
void snake_controller::input()
{
    // loop until quit signal
    while(!model->get_quit())
    {
        // get keystroke
        int c = view->get_input();
        switch(c)
        {    
            case KEY_UP:
                if(model->get_direction() != DOWN)
                {
                    model->set_direction(UP);
                }
                break;
            case KEY_DOWN:
                if(model->get_direction() != UP)
                {
                    model->set_direction(DOWN);
                }
                break;
            case KEY_LEFT:
                if(model->get_direction() != RIGHT)
                {
                    model->set_direction(LEFT);
                }
                break;
            case KEY_RIGHT:
                if(model->get_direction() != LEFT)
                {
                    model->set_direction(RIGHT);
                }
                break;
            // quit if Q pressed
            case 'q': 
            case 'Q':
                model->set_quit(true);
                break;
            default:
                break;
        }
    }
}
