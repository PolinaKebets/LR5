
#pragma once

#include<iostream>

void inputMatrix(int** A, int n, int k);
int* createEvenDiagonalArray(int** A, int size, int& newSize);
int calculateProduct(int* evenDiagonalArray, int newSize);
void printArray(int* evenDiagonalArray, int newSize);
int Task();
