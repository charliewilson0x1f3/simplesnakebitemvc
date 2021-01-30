CC=g++
CFLAGS=-lncurses -lpthread -Isource/controller -Isource/model -Isource/view

make: source/main.cpp source/controller/snake_controller.cpp source/controller/snake_controller.h source/model/linked_queue.cpp source/model/linked_queue.h source/model/snake_model.cpp source/model/snake_model.h source/view/snake_view.cpp source/view/snake_view.h
	$(CC) -o run/snake source/main.cpp $(CFLAGS)
	
run: run/snake
	./run/snake

clean: run/snake
	rm run/snake
	
