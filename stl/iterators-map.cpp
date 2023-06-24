#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;
using std::string;

/**
 * Iterators are used to iterate over containers.
 * Containers are data structures like vector, map, set, queue, etc
 * Range based for loop internally use iterators
 */

int main() {
	unordered_map<string, int> score;
	score.insert({ "Sangeeta", 20 });
	score["Suyash"] = 14;
	score["Sandeep"] = 23;
	score["Shubham"] = 100;

	// Method 1 - How range based for loops work
	// Looks ugly, Not readable
	for (unordered_map<string, int>::iterator it = score.begin(); it != score.end(); it++) {
		cout << it -> first << " " << it -> second << endl;
	}

	cout << endl;

	// Method 2
	// Readable way using typed definitions
	using ScoreMap = unordered_map<string, int>;
	for (ScoreMap::iterator it = score.begin(); it != score.end(); it++) {
		cout << (*it).first << " " << (*it).second << endl;
	}

	cout << endl;

	// Method 3
	// Range-based for loop
	for (auto kv: score) {
		cout << kv.first << " " << kv.second << endl; 
	}

	cout << endl;

	// Method 4
	// It's like destructuring from JavaScript
	for (auto [key, value]: score) {
		cout << key << " " << value << endl;
	}

	return 0;
}