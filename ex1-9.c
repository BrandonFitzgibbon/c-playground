#include <stdio.h>

int main() {
  int c, lc;
  lc = -1;

  while ((c = getchar()) != '\n') {
    if (c == ' ' && lc != ' ') {
      putchar(c);
    }
    if (c != ' ') {
      putchar(c);
    }
    lc = c;
  }

  putchar('\n');

  return 0;
}