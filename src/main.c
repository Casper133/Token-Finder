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

  int action;
  do {
    printf("(1) Check the string\n"
           "(2) Exit\n"
           "Enter the action:\n");
    scanf("%d", &action);

    if (action == 1) {
      printf("Enter the string:\n");
      char str[50] = {};
      gets(str);

      int currentState = 1;

      for (int i = 0; i < strlen(str); i++) {
        char currentSymbol = str[i];
        int currentColumn = getTransitionTableColumn(currentSymbol, currentState);
        currentState = stateTransitionArray[currentState][currentColumn];
      }

      if (currentState == 4) {
        printf("String is correct\n");
      } else {
        printf("String is incorrect\n");
      }
    }
  } while (action != 2);
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
