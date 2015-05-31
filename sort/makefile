main.o: main.c
	gcc -c main.c

selectionsort.o: selectionsort.c sortcommon.h
	gcc -c selectionsort.c
selectionsort: main.o selectionsort.o
	gcc -o selectionsort main.o selectionsort.o

insertionsort.o: insertionsort.c sortcommon.h
	gcc -c insertionsort.c
insertionsort: main.o insertionsort.o
	gcc -o insertionsort main.o insertionsort.o

bubblesort.o: bubblesort.c sortcommon.h
	gcc -c bubblesort.c
bubblesort: main.o bubblesort.o
	gcc -o bubblesort main.o bubblesort.o

shellsort.o: shellsort.c sortcommon.h
	gcc -c shellsort.c
shellsort: main.o shellsort.o
	gcc -o shellsort main.o shellsort.o

quicksort.o: quicksort.c sortcommon.h
	gcc -c quicksort.c
quicksort: main.o quicksort.o
	gcc -o quicksort main.o quicksort.o

mergesort.o: mergesort.c sortcommon.h
	gcc -c mergesort.c
mergesort: main.o mergesort.o
	gcc -o mergesort main.o mergesort.o

clean:
	rm *.o
	rm *~
	rm *sort
