CFLAGS= -Wall -fpic -lm -std=c99
#  -coverage

testresults: testme.c
	echo "Running tests:" > testresults.out
	echo "testme.c:" >> testresults.out
	gcc -o testme testme.c $(CFLAGS)
	./testme >> testresults.out
	#gcov testme.c >> testresults.out

clean:
	rm -f *.o testme
