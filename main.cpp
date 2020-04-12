#include <iostream>
using namespace std;
int m[100000];

int main() {
	int n, L;
	int total = 0,output = 0;
	int i,t;
	int P;
	scanf_s("%d %d", &n, &L);
	for (i = 0; i < n; i++) {
		cin >> t;
		total += t;
		m[i] = t;
	}
	P = m[0];
	if (P > L) {
		P = L;
	}
	total -= P;
	for (i = 1; i < n; i++) {
		int a = m[i];
		if (P >= a) {
			if (P >= total) {
				output += total;
				break;
			}
			else if (P + a > L) {
				P -= a;
				output += a;
			}
			else
				P += a;
		}
		else {
			if (i == n - 1)
			{
				output += P;
			}
			else if (P + a > L) {//這裡邏輯多思考
				if ((P + a - L) > (P - a)) {
					output += P;
					P = 0;
				}
				else {
					P = L;
				}
			}
			else {
				P += a;
			}
		}
		total -= a;
	}
	cout << output;
}
