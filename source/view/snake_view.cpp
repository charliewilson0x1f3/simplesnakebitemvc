/*
    Charles Wilson
    
    linked_queue.cpp
    Implementation file for snake_view
*/

#include "snake_view.h"

snake_view::snake_view(int width, int height)
{
    this->width = width;
    this->height = height;
    
    // initialize window
	initscr();
    clear();
    noecho();
    cbreak();
    curs_set(0);
    window = newwin(height+2, width+2, 1, 0);
    keypad(window, TRUE);
    mvprintw(0, (width - 11) / 2, "SNAKE GAME!");
    mvprintw(height + 3, (width - 15) / 2, "press Q to quit");
    refresh();
    box(window, 0, 0);
    wrefresh(window);
}

snake_view::~snake_view()
{
    endwin();
}

void snake_view::print_link(int x, int y)
{
    mvwprintw(window, y, x, "O");
    wrefresh(window);
}

void snake_view::erase_link(int x, int y)
{
    mvwprintw(window, y, x, " ");
    wrefresh(window);
}

void snake_view::print_food(int x, int y)
{
    mvwprintw(window, y, x, "X");
    wrefresh(window);
}

int snake_view::get_input()
{
    return wgetch(window);
}

void snake_view::game_over()
{
    mvwprintw(window, 0, (width - 10) / 2, "GAME OVER!");
    wrefresh(window);
}
