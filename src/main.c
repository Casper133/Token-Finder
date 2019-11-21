#include "main.h"
#include <stdio.h>

int main() {
  return 0;
}

int isCharSymbol(char symbol) {
  return symbol != '"' && symbol != '\\';
}

int isEscapedSymbol(char symbol) {
  return symbol == '\\' || symbol == 'n' || symbol == 't' || symbol == '"';
}
