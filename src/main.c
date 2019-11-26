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
  int startIndex = -1;
  int isStringNotFound = 1;

  for (int i = 0; i < strlen(str); i++) {
    char currentSymbol = str[i];
    int currentColumn = getTransitionTableColumn(currentSymbol, currentState);
    int nextState = stateTransitionArray[currentState][currentColumn];

    if (currentSymbol == '\"') {
      if (nextState == 4) {
        printf("Correct string: ");

        for (j = startIndex; j < i + 1; j++) {
          printf("%c", str[j]);
        }

        printf("\n");

        isStringNotFound = 0;
        currentState = 1;
        startIndex = -1;
        continue;
      }

      if (nextState == 2) {
        startIndex = i;
      }
    }

    if (startIndex == -1) {
      continue;
    }

    currentState = nextState;
  }

  if (isStringNotFound) {
    printf("There are no C-strings in input string\n");
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
