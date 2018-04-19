#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using std::accumulate;	using std::endl;
using std::cin;			using std::string;
using std::cout;		using std::vector;

int main()
{
	cout << "Enter a list of strings, "
		 << "followed by end-of-file: " << endl;
	string word;
	vector<string> words;
	while (cin >> word)
		words.push_back(word);

	string sum;
	sum = accumulate(words.begin(), words.end(), sum);

	cout << endl << "The accumulated string is: " << sum << endl;

	return 0;
}