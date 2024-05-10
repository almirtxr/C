#include <stdio.h>
#include <string.h>

int main() {
	char palavra[20];
	sprintf(palavra, "MELANCIA");

	int acertou = 0;
	int enforcou = 1;

	do {
        for (int i = 0; i < strlen(palavra); i++) {
            printf("_ ");
        }

        printf("\n");

		char chute;
		scanf(" %c", &chute);

	} while (!acertou && !enforcou);

	return 0;
}
