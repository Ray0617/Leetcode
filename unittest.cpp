#include "leetcode.h"
int main() {
	auto strvec = str2strvec("[\"ab\",\"cd\"]");
	cout << strvec.size() << endl;
	cout << strvec[0] << endl;
	cout << strvec[1] << endl;
 	assert(strvec[0] == "ab" && strvec[1] == "cd");
	return 0;
}