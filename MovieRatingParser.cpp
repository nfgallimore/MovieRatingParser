#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <limits>

#include "MovieRatingParser.hpp"

using namespace std;

int MovieRatingParser::parser() {

	string line;
	int numberOfRatings;
	multimap<string, double> ratingsMap;
	ifstream ratingsFile(FILENAME);

	if (ratingsFile.is_open()) {

		// gets NumberOfRatings from first line
		if (getline(ratingsFile, line)) numberOfRatings = stoi(line);

		string movieName;

		for (int i = 0; getline (ratingsFile, line); i++) {
			if (i % 2 == 0) 
				movieName = line;
			else {
				ratingsMap.insert(std::pair<string, double>(movieName, stoi(line)));
			}
		}
		ratingsFile.close();
	}
	else {
		cout << "File cannot be opened";
		return -1;
	}
	map<string, double> avgMap;
	for (auto movieName: ratingsMap)
	{
		pair <std::multimap<string, double>::iterator, std::multimap<string, double>::iterator> ret;
		ret = ratingsMap.equal_range(movieName.first);
		double sum = 0;
		for (multimap<string, double>::iterator it = ret.first; it != ret.second; ++it) {
      		sum += it->second;
		}
		avgMap.insert(std::make_pair(movieName.first, (sum/(double)ratingsMap.count(movieName.first))));
	}
	for (auto avg : avgMap) {
		if (ratingsMap.count(avg.first) == floor(ratingsMap.count(avg.first)))
			cout << avg.first << ": " << ratingsMap.count(avg.first) << " reviews, average of " << avg.second << " out of 5\n";
		else 
			cout << avg.first << ": " << ratingsMap.count(avg.first) << " review, average of " << std::fixed << std::setprecision(1) << avg.second << " out of 5\n";

	}

	return 0;
}
void MovieRatingParser::parse() {
	parser();
}