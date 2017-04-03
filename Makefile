install:
	g++ -o MovieRatingParser.o MovieRatingParser.cpp -c -std=c++11 && g++ -o main main.cpp MovieRatingParser.o -std=c++11
clean:
	rm -rf a.out main *.o