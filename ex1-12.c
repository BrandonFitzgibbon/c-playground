#include <stdio.h>

int main() {
  int c, lc;
  lc = -1;
  while ((c = getchar()) != '\n') {
    if (c != ' ' && c != '\t') {
      putchar(c);
    } else {
      if (lc != ' ' && lc != '\t' && lc != -1)
        putchar('\n');
    }
    lc = c;
  }

  putchar('\n');
}