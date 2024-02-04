#include <stdio.h>

#define TABSTOP 2
#define LIMIT 1000

int main() {
  int i, j, c, len;
  char output[LIMIT];
  len = 0;
  printf("-- PROGRAM --\n");
  for (i = 0; (c = getchar()) != EOF && i < LIMIT; i++) {
    if (c == ' ') {
      len++;
      output[i] = c;
    }
    else {
      if (len >= TABSTOP) {
        /* process the tabbing*/
        /* move the cursor back to the beginning of spaces */
        i = i - len;
        /* insert tabs */
        for (j = 0; j < len / TABSTOP; j++) {
          output[i] = '\t';
          i++;
        }
        /* insert spaces */
        for (j = 0; j < len % TABSTOP; j++) {
          output[i] = ' ';
          i++;
        }
      }
      len = 0;
      output[i] = c;
    }
  }
  output[i] = '\0';
  printf("\n-- OUTPUT --\n%s\n", output);
  printf("-- END --\n");
  return 0;
}
