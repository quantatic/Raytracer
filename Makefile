CC = gcc
CFLAGS = -std=c99 -Wall -Werror -g -O2
LDLIBS = -lm
OBJ_FILES = ray.o sphere.o raytrace.o hitable.o

raytrace: raytrace.o ray.o sphere.o hitable.o

raytrace.o: raytrace.c ray.h sphere.h

ray.o: ray.h ray.c

sphere.o: sphere.c sphere.h ray.h

hitable.o: hitable.c hitable.h sphere.h ray.h

clean:
	rm -rf $(OBJ_FILES)
