#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);

int main() {
  int len;
  char line[MAXLINE];
  char longest[MAXLINE];
  while ((len = getline(line, MAXLINE)) > 0) {
    if (len > 80) {
      printf("%d %s", len - 1, line);
    }
  }
  return 0;
}

int getline(char s[], int lim) {
  int c,i;
  for (i = 0; (c=getchar()) != EOF && c != '\n'; ++i) {
    if (i < lim - 1)
      s[i] = c;
  }
  if (c == '\n') {
    if (i < lim -2) {
      s[i] = c;
    }
    ++i;
  }
  if (i < lim - 1) {
    s[i] = '\0';
  } else {
    s[lim -1] = '\0';
  }
  return i;
}

void copy(char to[], char from[]) {
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}