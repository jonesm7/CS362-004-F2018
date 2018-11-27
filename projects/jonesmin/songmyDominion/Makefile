CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

unittestresults: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.o testhelpers.o
	
	echo "Running tests:" > unittestresults.out
	echo "unittest1.c:" >> unittestresults.out
	gcc -g -o unittest1 unittest1.c testhelpers.o dominion.o rngs.o $(CFLAGS)
	./unittest1 >> unittestresults.out
	gcov -b -c dominion.c >> unittestresults.out
	
	echo "unittest2.c:" >> unittestresults.out
	gcc -g -o unittest2 unittest2.c testhelpers.o dominion.o rngs.o $(CFLAGS)
	./unittest2 >> unittestresults.out
	gcov -b -c dominion.c >> unittestresults.out
	
	echo "unittest3.c:" >> unittestresults.out
	gcc -g -o unittest3 unittest3.c testhelpers.o dominion.o rngs.o $(CFLAGS)
	./unittest3 >> unittestresults.out
	gcov -b -c dominion.c >> unittestresults.out
	
	echo "unittest4.c:" >> unittestresults.out
	gcc -g -o unittest4 unittest4.c testhelpers.o dominion.o rngs.o $(CFLAGS)
	./unittest4 >> unittestresults.out
	gcov -b -c dominion.c >> unittestresults.out
	
	echo "cardtest1.c:" >> unittestresults.out
	gcc -g -o cardtest1 cardtest1.c testhelpers.o dominion.o rngs.o $(CFLAGS)
	./cardtest1 >> unittestresults.out
	gcov -b -c dominion.c >> unittestresults.out
	
	echo "cardtest2.c:" >> unittestresults.out
	gcc -g -o cardtest2 cardtest2.c testhelpers.o dominion.o rngs.o $(CFLAGS)
	./cardtest2 >> unittestresults.out
	gcov -b -c dominion.c >> unittestresults.out
	
	echo "cardtest3.c:" >> unittestresults.out
	gcc -g -o cardtest3 cardtest3.c testhelpers.o dominion.o rngs.o $(CFLAGS)
	./cardtest3 >> unittestresults.out
	gcov -b -c dominion.c >> unittestresults.out
	
	echo "cardtest4.c:" >> unittestresults.out
	gcc -g -o cardtest4 cardtest4.c testhelpers.o dominion.o rngs.o $(CFLAGS)
	./cardtest4 >> unittestresults.out
	gcov -b -c dominion.c >> unittestresults.out

randomtestadventurer.out: randomtestadventurer.c dominion.o testhelpers.o
	echo "Running tests:" > randomtestadventurer.out
	echo "randomtestadventurer.c:" >> randomtestadventurer.out
	gcc -g -o randomtestadventurer randomtestadventurer.c testhelpers.o dominion.o rngs.o $(CFLAGS)
	./randomtestadventurer >> randomtestadventurer.out
	gcov -b -c dominion.c >> randomtestadventurer.out

randomtestcard1.out: randomtestcard1.c dominion.o testhelpers.o
	echo "Running tests:" > randomtestcard1.out
	echo "randomtestcard1.c:" >> randomtestcard1.out
	gcc -g -o randomtestcard1 randomtestcard1.c testhelpers.o dominion.o rngs.o $(CFLAGS)
	./randomtestcard1 >> randomtestcard1.out
	gcov -b -c dominion.c >> randomtestcard1.out

randomtestcard2.out: randomtestcard2.c dominion.o testhelpers.o
	echo "Running tests:" > randomtestcard2.out
	echo "randomtestcard2.c:" >> randomtestcard2.out
	gcc -g -o randomtestcard2 randomtestcard2.c testhelpers.o dominion.o rngs.o $(CFLAGS)
	./randomtestcard2 >> randomtestcard2.out
	gcov -b -c dominion.c >> randomtestcard2.out

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
