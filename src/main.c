#include "main.h"
#include <stdio.h>

int main() {
  printf("Hello, World!\n");
  return 0;
}

int isEscapedSymbol(char symbol) {
  return symbol == '\\' || symbol == 'n' || symbol == 't' || symbol == '"';
}
