/*
    Charles Wilson
    
    main.cpp
    This file takes input for dimensions and
    difficulty of the game, then starts the game
*/

#include <iostream>

#include "snake_controller.cpp"

using namespace std;

/*
    Gets width dimension from player
    restricted to <=15 and <=1000
    
    width   ->  int* that points to the
                width int in main()
*/
void get_width(int* width)
{
    cout << "Enter screen width (15 - 1000): ";
    cin >> *width;
    if(*width < 15 || *width > 1000)
    {
        get_width(width);
    }
}

/*
    Gets height dimension from player
    restricted to <=10 and <=1000
    
    width   ->  int* that points to the
                height int in main()
*/
void get_height(int* height)
{
    cout << "Enter screen height (10 - 1000): ";
    cin >> *height;
    if(*height < 10 || *height > 1000)
    {
        get_height(height);
    }
}

/*
    Gets difficulty level from player
    Easy=1, Medium=2, or Hard=3
    
    difficulty  ->  int* that points to the
                    difficulty int in main()
*/
void get_difficulty(int* difficulty)
{
    cout << "Difficulty (Easy=1, Medium=2, Hard=3): ";
    cin >> *difficulty;
    switch(*difficulty)
    {
        case 1:
            *difficulty = EASY;
            break;
        case 2:
            *difficulty = MEDIUM;
            break;
        case 3:
            *difficulty = HARD;
            break;
        default:
            get_difficulty(difficulty);
            break;
    }
}

/*
    Takes input for dimensions/difficulty,
    then starts the game
*/
int main()
{
    int width, height, difficulty;
    
    get_width(&width);
    get_height(&height);
    get_difficulty(&difficulty);
    
    snake_controller s(width, height, difficulty);
   
    return 0;
}
