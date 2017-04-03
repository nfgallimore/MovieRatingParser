#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility>
#include <stdio.h>
#include <string.h>

#include "MovieRatingParser.hpp"

using namespace std;


 

int MovieRatingParser::parser() {
	string line;
	// need to make a pair to keep track of count of reviews for named movie
	map<string, int> ratingsMap;
	int numberOfRatings;
	ifstream ratingsFile(FILENAME);

	if (ratingsFile.is_open()) {

		// gets NumberOfRatings from first line
		if (getline(ratingsFile, line)) {
			numberOfRatings = stoi(line);
		}
		int lineCount = 0;
		int rating;
		string movieName;
		while (getline (ratingsFile, line)) {
			if (lineCount % 2 == 0) {
				cout << "movieName: " << line << '\n';
				movieName = line;
				lineCount++;
			}
			else if (lineCount % 2 != 0){
				cout << "count: " << line << '\n';
				rating = stoi(line);
				lineCount++;
			}
			ratingsMap.insert(std::pair<string, int>(movieName, rating));
		}
		ratingsFile.close();
	}
	else {
		cout << "File cannot be opened";
		return -1;
	}
	for(auto elem : ratingsMap)
	{
	   std::cout << elem.first << " " << elem.second << "\n";
	}
	return 0;
}
void MovieRatingParser::parse() {
	parser();
}
void print() {


}
int main(int argc, char** argsv) {
	MovieRatingParser parser;
	parser.parse();
	return 0;
}