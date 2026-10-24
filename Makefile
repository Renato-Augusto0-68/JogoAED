CC := gcc
RAYLIB_DIR := raylib/raylib/src
RAYLIB_LIB := $(RAYLIB_DIR)/libraylib.a

CPPFLAGS := -I$(RAYLIB_DIR)
LDLIBS := -L$(RAYLIB_DIR) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

game: main.o $(RAYLIB_LIB)
	$(CC) $^ -o $@ $(LDLIBS)

main.o: main.c 
	$(CC) $(CPPFLAGS) -c $< -o $@


run: game
	./game

clean:
	rm -f *.out *.o game

.PHONY: run clean
