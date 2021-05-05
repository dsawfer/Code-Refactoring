#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "header.h"

unusedStaff(char** data)
{
	int result[sizeOfResult] = { 0 };
	search("int", data, result);
	//findVars();
	//findFunc();
}