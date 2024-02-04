#include <stdio.h>

#define MAXSIZE 1000
#define COLWIDTH 16

int gline(char line[], int maxsize);
void foldline(char line[], int colwidth);

/* test functions */
int test(char actual[], char expected[]);
void runtests();

int main() {
  char line[MAXSIZE] = { 0 };
  int len;
  while ((len = gline(line, MAXSIZE)) != 0) {
    if (len > COLWIDTH) {
      foldline(line, COLWIDTH);
    }
    printf("%s\n", line);
  }

  runtests();

  return 0;
}

int gline(char line[], int maxsize) {
  int i, c;
  for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
    line[i] = c;
  }
  line[i + 1] = '\0';
  return i;
}

void foldline(char line[], int colwidth) {
  int i, j, m;
  m = 0;
  for (i = j = 0; line[i] != '\0'; i++, j++) {
    /* if we have a space and have exceeded the column width looking forward one extra char then we're done*/
    if (j > colwidth + 1 && m != 0) {
      break;
    }
    if (line[i] == '\n') {
      j = m = 0;
    }
    if (line[i] == ' ' || line[i] == '\t' && i > m) {
      m = i;
    }
  }
  if (m > 0 && j > COLWIDTH) {
    line[m] = '\n';
    foldline(line, COLWIDTH);
  }
}

/* presumably we'll learn some more and make this better - test cases work for col width 16 */
void runtests() {
  int success = 0;
  char actual[] = "hi hellooooooooooooooooooooooooooooooooooooooooooooooooooo bye";
  char expected[] = "hi\nhellooooooooooooooooooooooooooooooooooooooooooooooooooo\nbye";
  foldline(actual, COLWIDTH);
  success = test(actual, expected);
  if (success == 1) {
    printf("tests pass\n");
    printf("actual: %s\n", actual);
    printf("expected: %s\n", expected);
  } else {
    printf ("tests fail\n");
    printf("actual: %s\n", actual);
    printf("expected: %s\n", expected);
  }
  char actual1[] = "Hello, world - how's it going? I'm terrific, thanks for asking.";
  char expected1[] = "Hello, world -\nhow's it going?\nI'm terrific,\nthanks for\nasking.";
  foldline(actual1, COLWIDTH);
  success = test(actual1, expected1);
  if (success == 1) {
    printf("tests pass\n");
    printf("actual: %s\n", actual1);
    printf("expected: %s\n", expected1);
  } else {
    printf ("tests fail\n");
    printf("actual: %s\n", actual1);
    printf("expected: %s\n", expected1);
  }
  char actual2[] = "hello, world";
  char expected2[] = "hello, world";
  foldline(actual2, COLWIDTH);
  success = test(actual2, expected2);
  if (success == 1) {
    printf("tests pass\n");
    printf("actual: %s\n", actual2);
    printf("expected: %s\n", expected2);
  } else {
    printf ("tests fail\n");
    printf("actual: %s\n", actual2);
    printf("expected: %s\n", expected2);
  }
}

int test(char actual[], char expected[]) {
  int i, res;
  res = 1;
  for (i = 0; expected[i] != '\0'; i++) {
    if (actual[i] != expected[i]) {
      res = 0;
    }
  }
  return res;
}