#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char str[101];
	scanf("%s", str);

	for (int i = 0; i < strlen(str); i++) {
		if (i % 10 == 9) printf("%c\n", str[i]);
		else printf("%c", str[i]);
	}

	return 0;
}
