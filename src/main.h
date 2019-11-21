#ifndef TOKEN_FINDER__MAIN_H_
#define TOKEN_FINDER__MAIN_H_

int getTransitionTableColumn(char symbol, int currentState);

int isCharSymbol(char symbol);

int isEscapedSymbol(char symbol);

#endif  // TOKEN_FINDER__MAIN_H_
