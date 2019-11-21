#include "main.h"
#include <stdio.h>
#include <string.h>
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

  printf("Enter the string:\n");
  char str[50] = {};

  int j = 0;
  char c = '\0';

  do {
    scanf("%c", &c);
    str[j++] = c;
  } while (c != '\n');

  str[j - 1] = '\0';

  int currentState = 1;

  for (int i = 0; i < strlen(str); i++) {
    char currentSymbol = str[i];
    int currentColumn = getTransitionTableColumn(currentSymbol, currentState);
    currentState = stateTransitionArray[currentState][currentColumn];
  }

  if (currentState == 4) {
    printf("\nString is correct\n");
  } else {
    printf("\nString is incorrect\n");
  }

  return 0;
}

int getTransitionTableColumn(char symbol, int currentState) {
  if (currentState == 3 && isEscapedSymbol(symbol)) {
    return 3;
  }

  if (symbol == '"') {
    return 0;
  }

  if (isCharSymbol(symbol)) {
    return 1;
  }

  if (symbol == '\\') {
    return 2;
  }

  return 4;
}

int isCharSymbol(char symbol) {
  return symbol != '"' && symbol != '\\';
}

int isEscapedSymbol(char symbol) {
  return symbol == '\\' || symbol == 'n' || symbol == 't' || symbol == '"';
}
