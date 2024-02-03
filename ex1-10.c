#include <stdio.h>

int main() {
  int c;

  while ((c = getchar()) != '\n') {
    if (c == '\t') {
      putchar('\\');
      putchar('t');
    }

    if (c == '\b') {
      putchar('\\');
      putchar('b');
    }

    if (c == '\\') {
      putchar('\\');
      putchar('\\');
    }

    if (c != '\t' && c != '\b' && c != '\\') {
      putchar(c);
    }
  }

  putchar('\n');

  return 0;
}