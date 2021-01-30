C++ Snake Game
Charles Wilson

This project is an example of the classic snake game implemented with a doubly linked list queue in MVC style. This runs on Linux and needs to be compiled with the ncurses and pthread libraries.

Compilation:
    make        ->  compile
    make run    ->  run game
    make clean  ->  remove executable

Files:
    Makefile        ->  Makefile to compile project
    run             ->  directory for executable
        snake       ->  executable
    source          ->  directory for source code
        main.cpp    ->  main() that sets up game
        controller  ->  directory for controller code
            snake_controller.cpp
            snake_controller.h
                    ->  code for controller component
        model       ->  directory for model code
            linked_queue.cpp
            linked_queue.h
                    ->  code queue data structure
            snake_model.cpp
            snake_model.h
                    ->  code for model component
        view        ->  directory for view code
            snake_view.cpp
            snake_view.h
                    ->  code for view component
                    
Notes:
This is classic MVC style where the model contains all of the structures and data, the view handles all of the display, and the controller coordinates everything together. Other than the initialization of the bitmap at the start, everything runs in constant time because of the way the queue works. The snake moves by dequeuing the tail and enqueuing it as the head.

These are the literal commands the Makefile runs:
compile ->  g++ -o run/snake source/main.cpp -lncurses -lpthread -Isource/controller -Isource/model -Isource/view
run     ->  ./run/snake
clean   ->  rm run/snake
