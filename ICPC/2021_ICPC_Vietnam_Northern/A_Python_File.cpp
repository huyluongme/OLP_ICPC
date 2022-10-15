#include <iostream>
#include <algorithm>
#define cin std::cin
#define cout std::cout

std::string str_toupper(std::string s) {
	std::transform(s.begin(), s.end(), s.begin(),
		[](unsigned char c) { return std::tolower(c); }
	);
	return s;
}

int main() {
	std::iostream::sync_with_stdio(false);
	cin.tie(NULL);
	std::string inp;
	cin >> inp;
	inp = str_toupper(inp);
	size_t find = inp.find('.');
	if (find != std::string::npos) {
		if (inp.substr(find + 1).compare("py") == 0)
			cout << "yes";
		else cout << "no";
	}
	else cout << "no";
	return 0;
}