CC = g++
EXE = student_db

$(EXE): student_db.o driver.o
	$(CC) student_db.o driver.o -o $(EXE)
student_db.o: student_db.cpp
	$(CC) -c student_db.cpp 
driver.o: driver.cpp
	$(CC) -c driver.cpp
clean:
	rm -f *.o *.out StudentInfo.txt $(EXE)

