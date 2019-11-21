#include "main.h"
#include <stdio.h>
#define stateNumber 5
#define charType 5

int main() {
  int stateTransitionArray[stateNumber][charType] =
      {
          {0, 0, 0, 0, 0},
          {2, 0, 0, 0, 0},
          {4, 2, 3, 0, 0},
          {0, 0, 0, 2, 0},
          {0, 0, 0, 0, 0},
      };

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
