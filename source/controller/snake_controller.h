/*
    Charles Wilson
    
    snake_controller.h
    Header file for snake_controller
*/

#ifndef SNAKE_CONTROLLER_H
#define SNAKE_CONTROLLER_H

#include <thread>

#include "snake_model.cpp"
#include "snake_view.cpp"

// define difficulties (represents ms)
#define EASY 200
#define MEDIUM 110
#define HARD 80


/*
    Controller class for the snake game
*/
class snake_controller
{
    private:
    
        // instances of model and view
        snake_model* model;
        snake_view* view;
        // thread to read keystrokes
        thread input_thread;
        // difficulty level (speed in ms)
        int difficulty;
        
    public:
    
        /*
            constructor
            
            width       ->  width of screen
            height      ->  height of screen
            difficulty  ->  difficulty level
        */
        snake_controller(int width, int height, int difficulty);
		
		~snake_controller();
		
		// handles moving the snake
		void motion();
		
		// tells display and bitmap to show link
		void show_link(int x, int y);
		
		// tells display and bitmap to remove link
		void remove_link(int x, int y);
		
		// reads/handles keystrokes
		void input();
};

#endif
