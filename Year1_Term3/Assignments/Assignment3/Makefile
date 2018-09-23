CC = g++ 
exe_file = run_game

$(exe_file): game.o player.o property.o house.o apartmentComplex.o businessComplex.o driver.o tools.o 
	$(CC) game.o player.o property.o house.o apartmentComplex.o businessComplex.o driver.o tools.o -o $(exe_file)
game.o: game.cpp
	$(CC) -c game.cpp
player.o: player.cpp
	$(CC) -c player.cpp
property.o: property.cpp
	$(CC) -c property.cpp
house.o: house.cpp
	$(CC) -c house.cpp
apartmentComplex.o: apartmentComplex.cpp
	$(CC) -c apartmentComplex.cpp
businessComplex.o: businessComplex.cpp
	$(CC) -c businessComplex.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
tools.o: tools.cpp
	$(CC) -c tools.cpp
clean:
	rm -f *.out *.o $(exe_file)
