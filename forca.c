#include <stdio.h>
#include <string.h>

int main() {
	char palavra[20];
	sprintf(palavra, "MELANCIA");

	int acertou = 0;
	int enforcou = 0;

	do {
		char chute;
		scanf(" %c", &chute);

		for (int i = 0; i < strlen(palavra); i++) {
			if (palavra[i] == chute) {
				printf("A posi��o %d tem essa letra!\n", i);
				acertou = 1;
			}
		}

		if (!acertou) {
			enforcou = 1;
			printf("Voc� errou!\n");
		}

	} while (!acertou && !enforcou);

	return 0;
}
