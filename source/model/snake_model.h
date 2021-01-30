/*
    Charles Wilson
    
    snake_controller.h
    Header file for snake_model
*/

#ifndef SNAKE_MODEL_H
#define SNAKE_MODEL_H

#include <atomic>
#include <chrono>
#include <cstdlib>
#include <mutex>
#include <vector>

#include "linked_queue.cpp"

// define directions
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

// define bool marker for commands
#define PLACE true
#define ERASE false

// Class to implement model
class snake_model
{
    // class to send commands for display
    public : class command
    {
        public:
        
            // marks to PLACE or ERASE
            bool bit;
            // marks whether it is food or a link
            bool is_food;
            // coordinates to adjust
            int x, y;
            
            /*
                Constructor
                
                bool bit    ->  PLACE or ERASE
                int x, y    ->  coordinates
            */
            command(bool bit, int x, int y);
            
            /*
                Constructor
                
                bit     ->  PLACE or ERASE
                is_food ->  food or link
                x, y    ->  coordinates
            */
            command(bool bit, bool is_food, int x, int y);
    };

    private:
    
        // queue to represent snake
        linked_queue queue;
        // bitmap to mark snake location
        vector<vector<bool>> bitmap;
        // direction snake is moving
        int direction;
        // signal to quit game
        bool quit;
        // mutex for thread safety
        mutex mtx;
        // dimensions of world
        int width;
        int height;
        // coordinates of food
        int food_x;
	    int food_y;
    
    public:
    
        /*
            Constructor
            
            width, height   ->  world dimensions
        */
        snake_model(int width, int height);
        
        ~snake_model();
        
        /*
            sets bit true or false
            
            bit     ->  true/false
            x, y    ->  coordinates
        */
        void set_bit(bool bit, int x, int y);
        
        // spawn food randomly
        command set_food();
        
        // move snake and return display commands
        vector<command> move();
		
		// move specifically and return display commands
		vector<command> set_move(int x, int y, int temp_x, int temp_y);
		
		// return direction of snake
		int get_direction();
		
		// set direction of snake
		void set_direction(int direction);
		
		// get quit signal
		bool get_quit();
		
		// set quit signal - thread safe
		void set_quit(bool quit);
};

#endif
