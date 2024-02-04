#include <stdio.h>

#define TABSTOP 2
#define LIMIT 1000

int main() {
  int i, j, c;
  char output[LIMIT];
  printf("-- PROGRAM --\n");
  for (i = j = 0; (c = getchar()) != EOF && i < LIMIT; i++, j++) {
    if (j >= TABSTOP || c == '\n') {
      j = 0;
    }
    if (c == '\t') {
      for (j; j < TABSTOP; j++, i++) {
        output[i] = ' ';
      }
      i--;
    } else {
      output[i] = c;
    }
  }
  output[i] = '\0';
  printf("\n-- OUTPUT --\n%s\n", output);
  printf("-- END --\n");
  return 0;
}
