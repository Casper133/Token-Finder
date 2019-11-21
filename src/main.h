#ifndef TOKEN_FINDER__MAIN_H_
#define TOKEN_FINDER__MAIN_H_

int isCharSymbol(char symbol);

int isEscapedSymbol(char symbol);

int getTransitionTableColumn(char symbol);

int getColumnOfCompositeSymbol(char symbol);

#endif  // TOKEN_FINDER__MAIN_H_
