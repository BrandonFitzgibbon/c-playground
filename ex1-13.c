#include <stdio.h>

#define MAX 10 /* max length for words tracked in histogram */

int main() {
  int i, j, c, lc, wl;
  lc = -1;
  wl = 0;
  int hist[MAX + 1];
  for (i = 0; i < MAX + 1; ++i) {
    hist[i] = 0;
  }
  while ((c = getchar()) != '\n') {
    if (c != ' ') {
      ++wl;
    } else {
      if (wl > 1) {
        if (wl > MAX) {
          ++hist[MAX];
        } else {
          ++hist[wl - 1];
        }
      }
      wl = 0;
    }
    lc = c;
  }
  if (wl > 1) {
    if (wl > MAX) {
      ++hist[MAX];
    } else {
      ++hist[wl - 1];
    }
  }
  putchar('\n');
  printf("HORIZONTAL HISTOGRAM\n");
  /* horizontal */
  for (i = 0; i < MAX + 1; i++) {
    printf("%d:", i + 1);
    for (j = 0; j < hist[i]; j++) {
      putchar('-');
    }
    putchar('\n');
  }
  putchar('\n');
  /* vertical */
  printf("VERTICAL HISTOGRAM\n");
  wl = 0;
  for (i = 0; i < MAX + 1; i++) {
    if (hist[i] > wl)
      wl = hist[i];
  }
  /* scan from the largest histogram value*/
  for (j = wl; j > 0; j--) {
    printf("%d ", j);
    for (i = 0; i < MAX + 1; i++) {
      if (i >= 10) {
        putchar(' ');
      }
      if (hist[i] >= j) {
        putchar('-');
      } else {
        putchar(' ');
      }
      putchar(' ');
    }
    putchar('\n');
  }
  printf("%s ", "C");
  for (i = 0; i < MAX + 1; i++) {
    printf("%d ", i + 1);
  }
  putchar('\n');

  return 0;
}