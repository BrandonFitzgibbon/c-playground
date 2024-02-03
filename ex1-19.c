#include <stdio.h>

#define CHARLIMIT 1000

void reverse(char input[]);
int gline(char line[], int limit);

int main() {
  int con;
  char line[CHARLIMIT];
  while ((con = gline(line, CHARLIMIT)) != -1) {
    putchar('\n');
    reverse(line);
    printf("%s\n", line);
  }
  return 0;
}

void reverse(char input[]) {
  /* find length of char array */
  int i, j, c;
  for (i = 0; input[i] != '\0'; i++) {
    ;
  }

  /* i is len and input[i] will be our null character*/

  for (j = 0; j < i / 2; j++) {
    /* we want to swap index j with index i - j - 1 to avoid swapping the null character*/
    c = input[j];
    input[j] = input[i - j - 1];
    input[i - j - 1] = c;
  }

  return;
}

int gline(char line[], int limit) {
  int i, c;
  /* read until EOF or a new line */
  for (i = 0; (c = getchar()) != EOF && c != '\n' && i < limit - 1; i++) {
    line[i] = c;
  }

  /* temrinate string */
  line[i] = '\0';

  if (c == EOF) {
    return -1;
  }

  return i;
}