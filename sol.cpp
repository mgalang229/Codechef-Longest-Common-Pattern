#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		string a, b;
		cin >> a >> b;
		auto CheckUpper = [&](char ch) {
			return (ch >= 'A' && ch <= 'Z' ? true : false);
		};
		auto CheckLower = [&](char ch) {
			return (ch >= 'a' && ch <= 'z' ? true : false);
		};
		auto CheckDigit = [&](char ch) {
			return (ch >= '0' && ch <= '9' ? true : false);
		};
		vector<int> uppercase(26, 0), lowercase(26, 0), digits(10, 0);
		// count the uppercase, lowercase, and digit occurrences in string 'a'
		for (int i = 0; i < (int) a.size(); i++) {
			if (CheckUpper(a[i])) {
				// for uppercase letters
				uppercase[a[i] - 'A'] += 1;
			} else if (CheckLower(a[i])) {
				// for lowercase letters
				lowercase[a[i] - 'a'] += 1;
			} else if (CheckDigit(a[i])) {
				// for numerical digits
				digits[a[i] - '0'] += 1;
			}
		}
		int cnt = 0;
		for (int i = 0; i < (int) b.size(); i++) {
			if (CheckUpper(b[i]) && uppercase[b[i] - 'A'] > 0) {
				// if it's an uppercase letter and is also present in string 'a', then
				// increment 'cnt' and decrement the frequency of this letter
				cnt++;
				uppercase[b[i] - 'A'] -= 1;
			} else if (CheckLower(b[i]) && lowercase[b[i] - 'a'] > 0){
				// if it's a lowercase letter and is also present in string 'a', then
				// increment 'cnt' and decrement the frequency of this letter
				cnt++;
				lowercase[b[i] - 'a'] -= 1;
			} else if (CheckDigit(b[i]) && digits[b[i] - '0'] > 0) {
				// if it's a numerical digit and is also present in string 'a', then
				// increment 'cnt' and decrement the frequency of this numerical digit
				cnt++;
				digits[b[i] - '0'] -= 1;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
