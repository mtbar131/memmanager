main: main.c memmanager.o best_fit.o first_fit.o
	gcc main.c memmanager.o best_fit.o first_fit.o -o main
memmanager.o: memmanager.c memmanager.h
	gcc -c memmanager.c -o memmanager.o
best_fit.o: best_fit/best_fit.h best_fit/best_fit.c memmanager.h
	gcc -c best_fit/best_fit.c -o best_fit.o
first_fit.o: first_fit/first_fit.h first_fit/first_fit.c memmanager.h
	gcc -c first_fit/first_fit.c -o first_fit.o
clean:
	rm *.o
