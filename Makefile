CC = gcc
CFLAGS = -std=c99 -Wall -g
LDLIBS = -lm
OBJ_FILES = ray.o sphere.o raytrace.o

raytrace: raytrace.o ray.o sphere.o

raytrace.o: raytrace.c ray.h sphere.h

ray.o: ray.h ray.c

sphere.o: sphere.c sphere.h ray.h

clean:
	rm -rf $(OBJ_FILES)
