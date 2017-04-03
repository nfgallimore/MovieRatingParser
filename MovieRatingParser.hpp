class MovieRatingParser {
public:
	const char* FILENAME = "ratings.dat"; // throws warning if not using c++11
	void parse();
private:
	int parser();
};