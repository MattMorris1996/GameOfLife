CC = g++
LINK_TARGET = robot-maze

SDL_CFLAGS = `sdl2-config --cflags`
SDL_LDFLAGS = `sdl2-config --libs` -lSDL2_image -lm
OBJS = main.o cell.o display_sdl.o life.o
DEPS = cell.h display_sdl.h life.h

REBUILDABLES = $(OBJS) $(LINK_TARGET)

clean:
	rm -f $(REBUILDABLES)
	echo Clean done

all: $(LINK_TARGET)
	echo All done
	mkdir -p objects
	mv $(OBJS) objects

$(LINK_TARGET): $(OBJS)
		$(CC) -o $@ $^ $(SDL_LDFLAGS)

%.o: %.c $(DEPS)
		$(CC) -g -c $< $(SDL_CFLAGS)