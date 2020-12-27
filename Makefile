build:
	g++ -std=c++11 p1.cpp -o p1
	g++ -std=c++11 p2.cpp -o p2
	g++ -std=c++11 p3.cpp -o p3
run-p1:
	./p1
run-p2:
	./p2
run-p3:
	./p3
clean:
	rm -f *.o p1 p2 p3
