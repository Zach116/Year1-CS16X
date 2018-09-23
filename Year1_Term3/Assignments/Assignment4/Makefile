CC = g++ -g
EXE = run_game

$(EXE): driver.o player.o insect.o ant.o bee.o tools.o
	$(CC) driver.o player.o insect.o ant.o bee.o tools.o -o $(EXE)
driver.o: driver.cpp
	$(CC) -c driver.cpp
player.o: player.cpp
	$(CC) -c player.cpp
insect.o: insect.cpp
	$(CC) -c insect.cpp
ant.o: ant.cpp
	$(CC) -c ant.cpp
bee.o: bee.cpp
	$(CC) -c bee.cpp
tools.o: tools.cpp
	$(CC) -c tools.cpp
clean:
	rm -f *.out *.o $(EXE)
