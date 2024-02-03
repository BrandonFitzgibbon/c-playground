#include <stdio.h>

int main() {
  int i, j, c, len;
  len = 'z' - 'a' + 1;
  int alpha[len];
  for (i = 0; i < len + 1; ++i) {
    alpha[i] = 0;
  }
  while ((c = getchar()) != '\n') {
    /* lowercase letters */
    if (c >= 97 && c <= 122) {
      ++alpha[c - 'a'];
    }
  }
  for (i = 0; i < len; i++) {
    putchar('a' + i);
    printf(": ");
    for (j = 0; j < alpha[i]; j++) {
      putchar('-');
    }
    putchar('\n');
  }

  return 0;
}