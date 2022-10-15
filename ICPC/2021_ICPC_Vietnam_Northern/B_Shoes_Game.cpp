#include <iostream>
#define cin std::cin
#define cout std::cout

int main() {
	std::iostream::sync_with_stdio(false);
	cin.tie(NULL);
	int n, res = 0, tmp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		res += tmp;
	}
	cout << -res;
	return 0;
}