#include <time.h>
#include "declaration.h"

int side_up[9] = { 6, 6, 6, 6, 6, 6, 6, 6, 6 };
int side_dn[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
int side_lf[9] = { 4, 4, 4, 4, 4, 4, 4, 4, 4 };
int side_rt[9] = { 3, 3, 3, 3, 3, 3, 3, 3, 3 };
int side_fr[9] = { 2, 2, 2, 2, 2, 2, 2, 2, 2 };
int side_bk[9] = { 5, 5, 5, 5, 5, 5, 5, 5, 5 };

int _snapshot_side_up[9];
int _snapshot_side_dn[9];
int _snapshot_side_lf[9];
int _snapshot_side_rt[9];
int _snapshot_side_fr[9];
int _snapshot_side_bk[9];

#define STEPNUM 100

int messuprand[MAXSTEPNUM];
int countermessuprand[MAXSTEPNUM];

char messupstep[MAXSTEPNUM];
char countermessupstep[MAXSTEPNUM];

void generate_messuprand()
{
	srand((unsigned)time(NULL));
	int i = 0;
	for (; i != STEPNUM; ++i) messuprand[i] = rand() % 12;
	messuprand[i] = -1;
}

void generate_countermessuprand()
{
	int i = 0;
	for (; messuprand[i] != -1; ++i)
	{
		if (messuprand[i] % 2 == 0) countermessuprand[i] = messuprand[i] + 1;
		else countermessuprand[i] = messuprand[i] - 1;
	}
	countermessuprand[i] = -1;
	for (int j = 0; j < i - 1 - j; ++j)
	{
		int temp = countermessuprand[j];
		countermessuprand[j] = countermessuprand[i - 1 - j];
		countermessuprand[i - 1 - j] = temp;
	}
}

void rand_to_step(int* rand, char* step)
{
	int i = 0;
	for (; rand[i] != -1; ++i)
	{
		int temp = rand[i];
		if (temp == 0) step[i] = 'U';
		else if (temp == 1) step[i] = 'u';
		else if (temp == 2) step[i] = 'D';
		else if (temp == 3) step[i] = 'd';
		else if (temp == 4) step[i] = 'L';
		else if (temp == 5) step[i] = 'l';
		else if (temp == 6) step[i] = 'R';
		else if (temp == 7) step[i] = 'r';
		else if (temp == 8) step[i] = 'F';
		else if (temp == 9) step[i] = 'f';
		else if (temp == 10) step[i] = 'B';
		else if (temp == 11) step[i] = 'b';
		else if (temp == 12) step[i] = '0';
		else if (temp == 13) step[i] = '1';
		else if (temp == 14) step[i] = '2';
		else if (temp == 15) step[i] = '3';
		else if (temp == 16) step[i] = '4';
		else if (temp == 17) step[i] = '5';
		else
		{
			printf("Error: Illegal number \"%d\"\n", temp);
			exit(1);
		}
	}
	step[i] = '\0';
}

void cube_messup()
{
	generate_messuprand();
	rand_to_step(messuprand, messupstep);
	operation_analysis(messupstep);
}

void cube_countermessup()
{
	generate_countermessuprand();
	rand_to_step(countermessuprand, countermessupstep);
	operation_analysis(countermessupstep);
}

void cube_create_snapshot()
{
	for (int i = 0; i != 9; ++i)
	{
		_snapshot_side_up[i] = side_up[i];
		_snapshot_side_dn[i] = side_dn[i];
		_snapshot_side_lf[i] = side_lf[i];
		_snapshot_side_rt[i] = side_rt[i];
		_snapshot_side_fr[i] = side_fr[i];
		_snapshot_side_bk[i] = side_bk[i];
	}
}

void cube_recover_from_snapshot()
{
	for (int i = 0; i != 9; ++i)
	{
		side_up[i] = _snapshot_side_up[i];
		side_dn[i] = _snapshot_side_dn[i];
		side_lf[i] = _snapshot_side_lf[i];
		side_rt[i] = _snapshot_side_rt[i];
		side_fr[i] = _snapshot_side_fr[i];
		side_bk[i] = _snapshot_side_bk[i];
	}
}
