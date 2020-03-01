#include "declaration.h"

void side_clockwise(int* side)
{
	int temp = side[0];
	side[0] = side[6];
	side[6] = side[8];
	side[8] = side[2];
	side[2] = temp;
	temp = side[1];
	side[1] = side[3];
	side[3] = side[7];
	side[7] = side[5];
	side[5] = temp;
}

void side_counterclockwise(int* side)
{
	int temp = side[0];
	side[0] = side[2];
	side[2] = side[8];
	side[8] = side[6];
	side[6] = temp;
	temp = side[1];
	side[1] = side[5];
	side[5] = side[7];
	side[7] = side[3];
	side[3] = temp;
}

void move_cells(int num, int** group)
{
	int temp[9];
	for (int j = 0; j != num; ++j)
	{
		temp[j] = **(group + j);
	}
	for (int i = 0; i != 4; ++i)
	{
		if (i != 3)
			for (int j = 0; j != num; ++j) **(group + i * num + j) = **(group + (i + 1) * num + j);
		else
			for (int j = 0; j != num; ++j) **(group + i * num + j) = temp[j];
	}
}

void place_fr_to_up()
{
	int* group[36] =
	{
		side_fr + 0, side_fr + 1, side_fr + 2, side_fr + 3, side_fr + 4, side_fr + 5, side_fr + 6, side_fr + 7, side_fr + 8,
		side_dn + 0, side_dn + 1, side_dn + 2, side_dn + 3, side_dn + 4, side_dn + 5, side_dn + 6, side_dn + 7, side_dn + 8,
		side_bk + 8, side_bk + 7, side_bk + 6, side_bk + 5, side_bk + 4, side_bk + 3, side_bk + 2, side_bk + 1, side_bk + 0,
		side_up + 0, side_up + 1, side_up + 2, side_up + 3, side_up + 4, side_up + 5, side_up + 6, side_up + 7, side_up + 8
	};
	move_cells(9, group);
	side_clockwise(side_rt);
	side_counterclockwise(side_lf);
}

void place_fr_to_dn()
{
	int* group[36] =
	{
		side_fr + 0, side_fr + 1, side_fr + 2, side_fr + 3, side_fr + 4, side_fr + 5, side_fr + 6, side_fr + 7, side_fr + 8,
		side_up + 0, side_up + 1, side_up + 2, side_up + 3, side_up + 4, side_up + 5, side_up + 6, side_up + 7, side_up + 8,
		side_bk + 8, side_bk + 7, side_bk + 6, side_bk + 5, side_bk + 4, side_bk + 3, side_bk + 2, side_bk + 1, side_bk + 0,
		side_dn + 0, side_dn + 1, side_dn + 2, side_dn + 3, side_dn + 4, side_dn + 5, side_dn + 6, side_dn + 7, side_dn + 8
	};
	move_cells(9, group);
	side_clockwise(side_lf);
	side_counterclockwise(side_rt);
}

void place_fr_to_lf()
{
	int* group[36] =
	{
		side_fr + 0, side_fr + 1, side_fr + 2, side_fr + 3, side_fr + 4, side_fr + 5, side_fr + 6, side_fr + 7, side_fr + 8,
		side_rt + 0, side_rt + 1, side_rt + 2, side_rt + 3, side_rt + 4, side_rt + 5, side_rt + 6, side_rt + 7, side_rt + 8,
		side_bk + 0, side_bk + 1, side_bk + 2, side_bk + 3, side_bk + 4, side_bk + 5, side_bk + 6, side_bk + 7, side_bk + 8,
		side_lf + 0, side_lf + 1, side_lf + 2, side_lf + 3, side_lf + 4, side_lf + 5, side_lf + 6, side_lf + 7, side_lf + 8
	};
	move_cells(9, group);
	side_clockwise(side_up);
	side_counterclockwise(side_dn);
}

void place_fr_to_rt()
{
	int* group[36] =
	{
		side_fr + 0, side_fr + 1, side_fr + 2, side_fr + 3, side_fr + 4, side_fr + 5, side_fr + 6, side_fr + 7, side_fr + 8,
		side_lf + 0, side_lf + 1, side_lf + 2, side_lf + 3, side_lf + 4, side_lf + 5, side_lf + 6, side_lf + 7, side_lf + 8,
		side_bk + 0, side_bk + 1, side_bk + 2, side_bk + 3, side_bk + 4, side_bk + 5, side_bk + 6, side_bk + 7, side_bk + 8,
		side_rt + 0, side_rt + 1, side_rt + 2, side_rt + 3, side_rt + 4, side_rt + 5, side_rt + 6, side_rt + 7, side_rt + 8
	};
	move_cells(9, group);
	side_clockwise(side_dn);
	side_counterclockwise(side_up);
}

void place_up_to_lf()
{
	int* group[36] =
	{
		side_up + 0, side_up + 1, side_up + 2, side_up + 3, side_up + 4, side_up + 5, side_up + 6, side_up + 7, side_up + 8,
		side_rt + 2, side_rt + 5, side_rt + 8, side_rt + 1, side_rt + 4, side_rt + 7, side_rt + 0, side_rt + 3, side_rt + 6,
		side_dn + 8, side_dn + 7, side_dn + 6, side_dn + 5, side_dn + 4, side_dn + 3, side_dn + 2, side_dn + 1, side_dn + 0,
		side_lf + 6, side_lf + 3, side_lf + 0, side_lf + 7, side_lf + 4, side_lf + 1, side_lf + 8, side_lf + 5, side_lf + 2
	};
	move_cells(9, group);
	side_clockwise(side_bk);
	side_counterclockwise(side_fr);
}

void place_up_to_rt()
{
	int* group[36] =
	{
		side_up + 0, side_up + 1, side_up + 2, side_up + 3, side_up + 4, side_up + 5, side_up + 6, side_up + 7, side_up + 8,
		side_lf + 6, side_lf + 3, side_lf + 0, side_lf + 7, side_lf + 4, side_lf + 1, side_lf + 8, side_lf + 5, side_lf + 2,
		side_dn + 8, side_dn + 7, side_dn + 6, side_dn + 5, side_dn + 4, side_dn + 3, side_dn + 2, side_dn + 1, side_dn + 0,
		side_rt + 2, side_rt + 5, side_rt + 8, side_rt + 1, side_rt + 4, side_rt + 7, side_rt + 0, side_rt + 3, side_rt + 6
	};
	move_cells(9, group);
	side_clockwise(side_fr);
	side_counterclockwise(side_bk);
}

void operation_U()
{
	int* group[12] =
	{
		side_fr + 0, side_fr + 1, side_fr + 2,
		side_rt + 0, side_rt + 1, side_rt + 2,
		side_bk + 0, side_bk + 1, side_bk + 2,
		side_lf + 0, side_lf + 1, side_lf + 2
	};
	move_cells(3, group);
	side_clockwise(side_up);
}

void operation_u()
{
	int* group[12] =
	{
		side_fr + 0, side_fr + 1, side_fr + 2,
		side_lf + 0, side_lf + 1, side_lf + 2,
		side_bk + 0, side_bk + 1, side_bk + 2,
		side_rt + 0, side_rt + 1, side_rt + 2
	};
	move_cells(3, group);
	side_counterclockwise(side_up);
}

void operation_D()
{
	int* group[12] =
	{
		side_fr + 6, side_fr + 7, side_fr + 8,
		side_lf + 6, side_lf + 7, side_lf + 8,
		side_bk + 6, side_bk + 7, side_bk + 8,
		side_rt + 6, side_rt + 7, side_rt + 8
	};
	move_cells(3, group);
	side_clockwise(side_dn);
}

void operation_d()
{
	int* group[12] =
	{
		side_fr + 6, side_fr + 7, side_fr + 8,
		side_rt + 6, side_rt + 7, side_rt + 8,
		side_bk + 6, side_bk + 7, side_bk + 8,
		side_lf + 6, side_lf + 7, side_lf + 8
	};
	move_cells(3, group);
	side_counterclockwise(side_dn);
}

void operation_L()
{
	int* group[12] =
	{
		side_fr + 0, side_fr + 3, side_fr + 6,
		side_up + 0, side_up + 3, side_up + 6,
		side_bk + 8, side_bk + 5, side_bk + 2,
		side_dn + 0, side_dn + 3, side_dn + 6
	};
	move_cells(3, group);
	side_clockwise(side_lf);
}

void operation_l()
{
	int* group[12] =
	{
		side_fr + 0, side_fr + 3, side_fr + 6,
		side_dn + 0, side_dn + 3, side_dn + 6,
		side_bk + 8, side_bk + 5, side_bk + 2,
		side_up + 0, side_up + 3, side_up + 6
	};
	move_cells(3, group);
	side_counterclockwise(side_lf);
}

void operation_R()
{
	int* group[12] =
	{
		side_fr + 2, side_fr + 5, side_fr + 8,
		side_dn + 2, side_dn + 5, side_dn + 8,
		side_bk + 6, side_bk + 3, side_bk + 0,
		side_up + 2, side_up + 5, side_up + 8
	};
	move_cells(3, group);
	side_clockwise(side_rt);
}

void operation_r()
{
	int* group[12] =
	{
		side_fr + 2, side_fr + 5, side_fr + 8,
		side_up + 2, side_up + 5, side_up + 8,
		side_bk + 6, side_bk + 3, side_bk + 0,
		side_dn + 2, side_dn + 5, side_dn + 8
	};
	move_cells(3, group);
	side_counterclockwise(side_rt);
}

void operation_F()
{
	int* group[12] =
	{
		side_up + 6, side_up + 7, side_up + 8,
		side_lf + 8, side_lf + 5, side_lf + 2,
		side_dn + 2, side_dn + 1, side_dn + 0,
		side_rt + 0, side_rt + 3, side_rt + 6
	};
	move_cells(3, group);
	side_clockwise(side_fr);
}

void operation_f()
{
	int* group[12] =
	{
		side_up + 6, side_up + 7, side_up + 8,
		side_rt + 0, side_rt + 3, side_rt + 6,
		side_dn + 2, side_dn + 1, side_dn + 0,
		side_lf + 8, side_lf + 5, side_lf + 2
	};
	move_cells(3, group);
	side_counterclockwise(side_fr);
}

void operation_B()
{
	int* group[12] =
	{
		side_up + 2, side_up + 1, side_up + 0,
		side_rt + 8, side_rt + 5, side_rt + 2,
		side_dn + 6, side_dn + 7, side_dn + 8,
		side_lf + 0, side_lf + 3, side_lf + 6
	};
	move_cells(3, group);
	side_clockwise(side_bk);
}

void operation_b()
{
	int* group[12] =
	{
		side_up + 2, side_up + 1, side_up + 0,
		side_lf + 0, side_lf + 3, side_lf + 6,
		side_dn + 6, side_dn + 7, side_dn + 8,
		side_rt + 8, side_rt + 5, side_rt + 2
	};
	move_cells(3, group);
	side_counterclockwise(side_bk);
}

void operation_analysis(char* step)
{
	for (int i = 0; step[i] != '\0'; ++i)
	{
		if (step[i] == 'U') operation_U();
		else if (step[i] == 'u') operation_u();
		else if (step[i] == 'D') operation_D();
		else if (step[i] == 'd') operation_d();
		else if (step[i] == 'L') operation_L();
		else if (step[i] == 'l') operation_l();
		else if (step[i] == 'R') operation_R();
		else if (step[i] == 'r') operation_r();
		else if (step[i] == 'F') operation_F();
		else if (step[i] == 'f') operation_f();
		else if (step[i] == 'B') operation_B();
		else if (step[i] == 'b') operation_b();
		else if (step[i] == '0') place_fr_to_up();
		else if (step[i] == '1') place_fr_to_dn();
		else if (step[i] == '2') place_fr_to_lf();
		else if (step[i] == '3') place_fr_to_rt();
		else if (step[i] == '4') place_up_to_lf();
		else if (step[i] == '5') place_up_to_rt();
		else if (step[i] == '-')
			;
		else
		{
			printf("Error: Illegal operation \"%c\"\n", step[i]);
			exit(1);
		}
	}
}
