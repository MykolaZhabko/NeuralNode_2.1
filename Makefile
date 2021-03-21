
output: main.o sw.o node.o teach.o analyse.o menu.o sigmoid.o bmp_generator.o image_analyse.o sdl_test.o
	gcc main.c sw.c node.c teach.c analyse.c menu.c sigmoid.c bmp_generator.c image_analyse.c sdl_test.c -lm -lSDL2 -o output

main.o: main.c
	gcc -c main.c

sw.o: sw.c sw.h
	gcc -c sw.c

node.o: node.c node.h
	gcc -c node.c

teach.o: teach.c teach.h
	gcc -c teach.c

analyse.o: analyse.c analyse.h
	gcc -c analyse.c

menu.o: menu.c menu.h
	gcc -c menu.c

sigmoid.o: sigmoid.c sigmoid.h
	gcc -c sigmoid.c

bmp_generator.o: bmp_generator.c bmp_generator.h
	gcc -c bmp_generator.c

image_analyse.o: image_analyse.c image_analyse.h
	gcc -c image_analyse.c

sdl_test.o: sdl_test.c sdl_test.h
	gcc -c sdl_test.c

clean:
	rm *.o output