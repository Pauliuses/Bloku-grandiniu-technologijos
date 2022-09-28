prog: funkc.o
	g++ -o prog hash.cpp funkc.o
funkc:
	g++ -c funkc.cpp
clean:
	rm *.o prog.exe