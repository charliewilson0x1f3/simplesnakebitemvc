/*
    Charles Wilson
    
    snake_controller.h
    Header file for snake_view
*/

#ifndef SNAKE_VIEW_H
#define SNAKE_VIEW_H

#include <ncurses.h>

/*
    Class to handle display of
    snake game in terminal window
*/
class snake_view
{
    private:
    
        // ncurses window
        WINDOW* window;
        // window dimensions
        int height;
	    int width;
        
    public:
    
        /*
            Constructor
            
            width, height   ->  window dimensions
        */
        snake_view(int width, int height);
        
        ~snake_view();
        
        // display link in window at coordinates
        void print_link(int x, int y);
        
        // erase link in window at coordinates
        void erase_link(int x, int y);
        
        // display food in window at coordinates
        void print_food(int x, int y);
        
        // get and return keystroke
        int get_input();
        
        // display game over message
        void game_over();
};

#endif
