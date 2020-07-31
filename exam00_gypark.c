#include <stdio.h>

int main() {
	int n, m, idx = 0, cnt = 0; scanf("%d %d", &n, &m);
	int t = n;
	int check[1001] = { 0 };
	printf("<");
	while (t--) {
		while (1) {
			if (!check[idx]) cnt++;
			if (cnt == m) break;
			idx++;
			idx %= n;
		}
		check[idx] = 1;
		cnt = 0;
		printf("%d", idx + 1);
		if (t) printf(", ");
	}
	puts(">");
}