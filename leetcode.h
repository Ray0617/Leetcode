#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <limits.h>
#include <string>
#include <iostream>
#include <assert.h>
using namespace std;
vector<vector<char>> str2chmatrix(string str); // ["ab", "cd"]
vector<string> str2strvec(string str); // ["str1", "str2"]
vector<string> load(string filename);
void dump(string str);
void dump(vector<int> vec);
void dump(vector<string> vec);
void dump(vector<vector<char>> vec);
void dump(vector<vector<int>> vec);