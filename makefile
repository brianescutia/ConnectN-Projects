connectn.out: connectn.o gameboard.o gameplay.o
	gcc connectn.o gameboard.o gameplay.o -o connectn.out

connectn.o: connectn.c gameplay.h gameboard.h 
	gcc -c connectn.c -Wall -Werror -o connectn.o 

gameboard.o: gameboard.c gameboard.h
	gcc -c gameboard.c -Wall -Werror -o gameboard.o

gameplay.o: gameplay.c gameplay.h gameboard.h
	gcc -c gameplay.c -Wall -Werror -o gameplay.o

clean:
	rm -f *.o connectn.out