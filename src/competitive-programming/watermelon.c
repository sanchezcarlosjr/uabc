// 4A Watermelon
#include "stdio.h"

int main() {
	unsigned short w;
	scanf("%hu", &w);
	printf((w > 2 && w % 2 == 0) ? "YES": "NO");
	return 0;
}
