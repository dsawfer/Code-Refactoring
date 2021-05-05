#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#define SIZE = 100

typedef struct StraightLineEquation
{
	int name;
	double p1[size][3]; //точка с координатами p1[][0] и p1[][1], и порядковым номером p1[][2]
	double p2[size][3];
	double A;
	double B;
	double C;
}Equation;


int main()
{
	int abs, var;
	int a[100]= { 0 };
	int n, item, count = 0;
	scanf("%d %d\n", &n, &item);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	printTitle("Initial array:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	
	printTitle("Target element: ")
	printf("%d\n", item);
	for (int i = 0; i < n; i++)
	{
		if (a[i] == item) 
		{
			count++;
		}
	}
	
	if (count == 0) printf("No targets");
	else 
	{
		printf("Target is found at: ");
		for (int i = 0; i < n; i++)
		{
			if (a[i] == item)
			{
				printf("%d ", i);
			}
		}
	}
	return 0;
}

int LinearSearch(int a)		//не используется
{
	return a;
}

void printTitle(char* title)	//используется
{
	printf("%s", title);
}