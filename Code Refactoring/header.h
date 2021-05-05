#pragma once

#define length 300
#define width 100
#define sizeOfResult 20

char** readFile(int mode);
freeAll(char** firstFile, char** secondFile, char** firstHeader);

search(char* needle, char** haystack, int result[][2]);
int searchInLine(char* needle, char* haystack, int* offsetTable);
addToResult(int index, int row, int result[][2]);
letterExist(char letter, char* needle);
checkWord(char* haystack, int step, int sizeOfNeedle);

unusedStaff(char** data);

//function name:
//
//content
//content
//content
//
//------------------------------------------------------------------
//
//function name:
//
//content
//content
//content
//
//------------------------------------------------------------------
//
