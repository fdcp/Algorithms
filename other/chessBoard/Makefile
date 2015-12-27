chess.o: chess.c chess.h
	gcc -c chess.c

main.o: main.c
	gcc -c main.c

chessBoard: main.o chess.o
	gcc -o chessBoard main.o chess.o

clean:
	rm *.o chessBoard