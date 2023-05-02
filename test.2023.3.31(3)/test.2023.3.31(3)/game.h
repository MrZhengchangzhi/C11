#pragma once


#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stddef.h>
#include <stdlib.h>

#define ROW 3
#define COL 3

void Initboard(char arr[ROW][COL], int row, int col);
void Displayboard(char arr[ROW][COL], int row, int col);
void Play_move(char arr[ROW][COL], int row, int col);
void Comp_move(char arr[ROW][COL], int row, int col);
char Is_win(char arr[ROW][COL], int row,int col);
int Full(char arr[ROW][COL], int row, int col);