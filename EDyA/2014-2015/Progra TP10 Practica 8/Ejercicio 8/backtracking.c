#include <stdio.h>
#include <stdlib.h>

#define ROWS 8

int table[ROWS][ROWS];

int getcol(int row)
{
	int i;
	for(i=0; i < ROWS; i++)
		if(table[row][i] == 'Q')
			return i;

	
}

void print_table(void) {
	int i, j;
	printf("\n");
	for(i=0; i < ROWS; i++) {
			 for(j=0;j < ROWS;j++)
	 printf("%c",table[i][j]);
			 printf("\n");
	}
}

int feasible(int row, int col)
{
 int i, j;

 for(i = 0; i < ROWS; i++) {
	 j = getcol(i);

	 if(col == j || abs(row - i) == abs(col - j))
		 return 0;
 }

 return 1;
}


void solve(int row)
{
	int col;
	static int x = 0;

	if (row == ROWS && !x) {
		x = 1;
		print_table();
		return;
	}

	for (col = 0; col < ROWS; col++)
		if (feasible(row, col)) {
			table[row][col] = 'Q';
			solve(row + 1);
			table[row][col] = '.';
		}
}

 
int main(void) {
	int i, j;

 for(i=0;i < ROWS;i++)
		 for(j=0;j < ROWS;j++)
			 table[i][j]='.';

	solve(0);

	return 0;
}
