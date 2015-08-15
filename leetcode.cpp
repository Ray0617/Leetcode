#include "leetcode.h"
#include <fstream>

vector<vector<char>> str2chmatrix(string str) {
	// ["ab", "cd"]
	auto strvec = str2strvec(str);
	vector<vector<char>> result;
	for (auto str : strvec)
		result.push_back(vector<char>(str.begin(), str.end()));
	return result;
}
vector<string> str2strvec(string str) {
	// ["str1", "str2"]
	vector<string> result;
	size_t pos = 0;
	while (true) {
		auto start = str.find("\"", pos);
		if (start == string::npos)
			break;
		start++;
		auto end = str.find("\"", start);
		if (end == string::npos)
			break;
		string s = str.substr(start, end - start);
		result.push_back(s);
		pos = end + 1;
	}
	return result;
}
vector<string> load(string filename) {
	vector<string> result;
	ifstream input(filename.c_str());
	while (!input.eof()) {
		string str;
		getline(input, str);
		if (!str.empty())
			result.push_back(str);
	}
	return result;
}
void dump(string str) {
	cout << str << endl;
}
void dump(vector<int> vec) {
	for (auto i : vec)
		cout << i << " ";
	cout << endl;
}
void dump(vector<string> vec) {
	for (auto str : vec)
		cout << str << endl;
}
void dump(vector<vector<char>> vec) {
	for (auto row : vec) {
		for (auto ch : row)
			cout << ch;
		cout << endl;
	}
}
void dump(vector<vector<int>> vec) {
	for (auto v : vec) {
		for (auto i : v)
			cout << i << " ";
		cout << endl;
	}
}
