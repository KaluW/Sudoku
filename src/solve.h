#ifndef SOLVE_H
#define SOLVE_H

#include <stdbool.h>
#include <stdint.h>

bool SolveSudoku(void);
bool FindUnassignedLocation(uint8_t *rowp, uint8_t *colp);
void randSeq(uint8_t *seq);
bool isSafe(uint8_t row, uint8_t col, uint8_t num);
bool UsedInBox(uint8_t boxStartRow, uint8_t boxStartCol, uint8_t num);
bool UsedInCol(uint8_t col, uint8_t num);
bool UsedInRow(uint8_t row, uint8_t num);
void GenerateSudoku(void);
bool isWin(void);

#endif