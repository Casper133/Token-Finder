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

int getTransitionTableColumn(char symbol) {
  switch (symbol) {
    case '"':
      return 0;
    case '\\':
      return 2;
    default:
      return getColumnOfCompositeSymbol(symbol);
  }
}

int getColumnOfCompositeSymbol(char symbol) {
  if (isCharSymbol(symbol)) {
    return 1;
  }

  if (isEscapedSymbol(symbol)) {
    return 3;
  }

  return 4;
}
