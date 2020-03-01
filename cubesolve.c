#include "declaration.h"

char solvestep[MAXSTEPNUM];
char finalstep[MAXSTEPNUM];
int iter_w = 0;

int fr_color[4] = { 2, 3, 5, 4 };
int rt_color[4] = { 3, 5, 4, 2 };

void initialize_string(char* str, int len)
{
	for (int i = 0; i != len; ++i) str[i] = '\0';
}

void write_string_to_solvestep_and_perform(char* str)
{
	for (int i = 0; str[i] != '\0'; ++i) solvestep[iter_w++] = str[i];
	operation_analysis(str);
}

void solve_down_edge()
{
	for (int i = 0; i != 4; ++i)
	{
		int x = fr_color[i];
		while (1)
		{
			if (side_fr[4] == x) break;
			write_string_to_solvestep_and_perform("2");
		}

		if (side_dn[1] == 1 && side_fr[7] == x);
		else if (side_dn[1] == x && side_fr[7] == 1) write_string_to_solvestep_and_perform("fDrd");
		else if (side_dn[3] == 1 && side_lf[7] == x) write_string_to_solvestep_and_perform("LLuFF");
		else if (side_dn[3] == x && side_lf[7] == 1) write_string_to_solvestep_and_perform("lf");
		else if (side_dn[5] == 1 && side_rt[7] == x) write_string_to_solvestep_and_perform("rrUFF");
		else if (side_dn[5] == x && side_rt[7] == 1) write_string_to_solvestep_and_perform("RF");
		else if (side_dn[7] == 1 && side_bk[7] == x) write_string_to_solvestep_and_perform("BBUUFF");
		else if (side_dn[7] == x && side_bk[7] == 1) write_string_to_solvestep_and_perform("BBUrFR");

		else if (side_up[1] == 1 && side_bk[1] == x) write_string_to_solvestep_and_perform("UUFF");
		else if (side_up[1] == x && side_bk[1] == 1) write_string_to_solvestep_and_perform("UrFR");
		else if (side_up[3] == 1 && side_lf[1] == x) write_string_to_solvestep_and_perform("uFF");
		else if (side_up[3] == x && side_lf[1] == 1) write_string_to_solvestep_and_perform("Lfl");
		else if (side_up[5] == 1 && side_rt[1] == x) write_string_to_solvestep_and_perform("UFF");
		else if (side_up[5] == x && side_rt[1] == 1) write_string_to_solvestep_and_perform("rFR");
		else if (side_up[7] == 1 && side_fr[1] == x) write_string_to_solvestep_and_perform("FF");
		else if (side_up[7] == x && side_fr[1] == 1) write_string_to_solvestep_and_perform("urFR");

		else if (side_fr[5] == 1 && side_rt[3] == x) write_string_to_solvestep_and_perform("Drd");
		else if (side_fr[5] == x && side_rt[3] == 1) write_string_to_solvestep_and_perform("F");
		else if (side_rt[5] == 1 && side_bk[3] == x) write_string_to_solvestep_and_perform("DDbDD");
		else if (side_rt[5] == x && side_bk[3] == 1) write_string_to_solvestep_and_perform("DRd");
		else if (side_bk[5] == 1 && side_lf[3] == x) write_string_to_solvestep_and_perform("dlD");
		else if (side_bk[5] == x && side_lf[3] == 1) write_string_to_solvestep_and_perform("DDBDD");
		else if (side_lf[5] == 1 && side_fr[3] == x) write_string_to_solvestep_and_perform("f");
		else if (side_lf[5] == x && side_fr[3] == 1) write_string_to_solvestep_and_perform("dLD");

		else
			;
	}
}

void solve_down_corner()
{
	for (int i = 0; i != 4; ++i)
	{
		int x = fr_color[i];
		int y = rt_color[i];
		while (1)
		{
			if (side_fr[4] == x) break;
			write_string_to_solvestep_and_perform("2");
		}

		if (side_dn[2] == 1 && side_fr[8] == x && side_rt[6] == y);
		else if (side_dn[2] == y && side_fr[8] == 1 && side_rt[6] == x) write_string_to_solvestep_and_perform("fuFUfuF");
		else if (side_dn[2] == x && side_fr[8] == y && side_rt[6] == 1) write_string_to_solvestep_and_perform("RUruRUr");

		// BUb-
		else if (side_dn[8] == 1 && side_rt[8] == x && side_bk[6] == y) write_string_to_solvestep_and_perform("BUbfuF");
		else if (side_dn[8] == y && side_rt[8] == 1 && side_bk[6] == x) write_string_to_solvestep_and_perform("BUbfUUFUfuF");
		else if (side_dn[8] == x && side_rt[8] == y && side_bk[6] == 1) write_string_to_solvestep_and_perform("BUbufUF");

		// LUUl-
		else if (side_dn[6] == 1 && side_bk[8] == x && side_lf[6] == y) write_string_to_solvestep_and_perform("LUUlfuF");
		else if (side_dn[6] == y && side_bk[8] == 1 && side_lf[6] == x) write_string_to_solvestep_and_perform("LUUlfUUFUfuF");
		else if (side_dn[6] == x && side_bk[8] == y && side_lf[6] == 1) write_string_to_solvestep_and_perform("LUUlufUF");

		// luL-
		else if (side_dn[0] == 1 && side_lf[8] == x && side_fr[6] == y) write_string_to_solvestep_and_perform("luLufUF");
		else if (side_dn[0] == y && side_lf[8] == 1 && side_fr[6] == x) write_string_to_solvestep_and_perform("luLfuF");
		else if (side_dn[0] == x && side_lf[8] == y && side_fr[6] == 1) write_string_to_solvestep_and_perform("luLfUUFUfuF");

		// -
		else if (side_up[8] == 1 && side_rt[0] == x && side_fr[2] == y) write_string_to_solvestep_and_perform("fUUFUfuF");
		else if (side_up[8] == y && side_rt[0] == 1 && side_fr[2] == x) write_string_to_solvestep_and_perform("ufUF");
		else if (side_up[8] == x && side_rt[0] == y && side_fr[2] == 1) write_string_to_solvestep_and_perform("fuF");

		// U-
		else if (side_up[2] == 1 && side_bk[0] == x && side_rt[2] == y) write_string_to_solvestep_and_perform("UfUUFUfuF");
		else if (side_up[2] == y && side_bk[0] == 1 && side_rt[2] == x) write_string_to_solvestep_and_perform("fUF");
		else if (side_up[2] == x && side_bk[0] == y && side_rt[2] == 1) write_string_to_solvestep_and_perform("UfuF");

		// UU-
		else if (side_up[0] == 1 && side_lf[0] == x && side_bk[2] == y) write_string_to_solvestep_and_perform("UUfUUFUfuF");
		else if (side_up[0] == y && side_lf[0] == 1 && side_bk[2] == x) write_string_to_solvestep_and_perform("UfUF");
		else if (side_up[0] == x && side_lf[0] == y && side_bk[2] == 1) write_string_to_solvestep_and_perform("UUfuF");

		// u-
		else if (side_up[6] == 1 && side_fr[0] == x && side_lf[2] == y) write_string_to_solvestep_and_perform("ufUUFUfuF");
		else if (side_up[6] == y && side_fr[0] == 1 && side_lf[2] == x) write_string_to_solvestep_and_perform("UUfUF");
		else if (side_up[6] == x && side_fr[0] == y && side_lf[2] == 1) write_string_to_solvestep_and_perform("ufuF");

		else
			;
	}
}

void solve_middle_edge()
{
	for (int i = 0; i != 4; ++i)
	{
		int x = fr_color[i];
		int y = rt_color[i];
		while (1)
		{
			if (side_fr[4] == x) break;
			write_string_to_solvestep_and_perform("2");
		}

		if (side_fr[5] == x && side_rt[3] == y);
		else
		{
			if (side_fr[5] == y && side_rt[3] == x) write_string_to_solvestep_and_perform("URurufUF");
			else if (side_rt[5] == x && side_bk[3] == y || side_rt[5] == y && side_bk[3] == x) write_string_to_solvestep_and_perform("2URurufUF3");
			else if (side_bk[5] == x && side_lf[3] == y || side_bk[5] == y && side_lf[3] == x) write_string_to_solvestep_and_perform("22URurufUF33");
			else if (side_lf[5] == x && side_fr[3] == y || side_lf[5] == y && side_fr[3] == x) write_string_to_solvestep_and_perform("3URurufUF2");
			else
				;
			
			while (1)
			{
				if (side_fr[1] == x && side_up[7] == y || side_rt[1] == y && side_up[5] == x) break;
				write_string_to_solvestep_and_perform("U");
			}

			if (side_fr[1] == x && side_up[7] == y) write_string_to_solvestep_and_perform("URurufUF");
			else write_string_to_solvestep_and_perform("ufUFURur");
		}
	}
}

void solve_up_edge()
{
	while (1)
	{
		if (side_up[1] == 6 && side_up[3] == 6 && side_up[5] == 6 && side_up[7] == 6)
			break;
		if (side_up[3] == 6 && (side_up[1] == 6 || side_up[5] == 6))
			;
		else if (side_up[1] == 6 && (side_up[5] == 6 || side_up[7] == 6))
			write_string_to_solvestep_and_perform("3");
		else if (side_up[5] == 6 && side_up[7] == 6)
			write_string_to_solvestep_and_perform("22");
		else if (side_up[7] == 6 && side_up[3] == 6)
			write_string_to_solvestep_and_perform("2");
		else
			;
		write_string_to_solvestep_and_perform("FRUruf");
	}
	while (1)
	{
		if ((side_fr[1] == 2 && side_rt[1] == 3 && side_bk[1] == 5 && side_lf[1] == 4)
			|| (side_fr[1] == 4 && side_rt[1] == 2 && side_bk[1] == 3 && side_lf[1] == 5)
			|| (side_fr[1] == 5 && side_rt[1] == 4 && side_bk[1] == 2 && side_lf[1] == 3)
			|| (side_fr[1] == 3 && side_rt[1] == 5 && side_bk[1] == 4 && side_lf[1] == 2))
			break;
		if ((side_fr[1] == 2 && side_rt[1] == 3)
			|| (side_fr[1] == 4 && side_rt[1] == 2)
			|| (side_fr[1] == 5 && side_rt[1] == 4)
			|| (side_fr[1] == 3 && side_rt[1] == 5))
			write_string_to_solvestep_and_perform("3");
		else if ((side_rt[1] == 3 && side_bk[1] == 5)
			|| (side_rt[1] == 2 && side_bk[1] == 3)
			|| (side_rt[1] == 4 && side_bk[1] == 2)
			|| (side_rt[1] == 5 && side_bk[1] == 4))
			;
		else if ((side_bk[1] == 5 && side_lf[1] == 4)
			|| (side_bk[1] == 3 && side_lf[1] == 5)
			|| (side_bk[1] == 2 && side_lf[1] == 3)
			|| (side_bk[1] == 4 && side_lf[1] == 2))
			write_string_to_solvestep_and_perform("2");
		else if ((side_fr[1] == 2 && side_lf[1] == 4)
			|| (side_fr[1] == 4 && side_lf[1] == 5)
			|| (side_fr[1] == 5 && side_lf[1] == 3)
			|| (side_fr[1] == 3 && side_lf[1] == 2))
			write_string_to_solvestep_and_perform("22");
		else
			;
			write_string_to_solvestep_and_perform("RUrURUUr");
	}
}

void solve_up_corner()
{
	while (1)
	{
		if (side_up[0] == 6 && side_up[2] == 6 && side_up[8] == 6 && side_up[6] == 6)
			break;
		if (side_up[0] == 6)
		{
			if (side_up[2] == 6 || side_up[8] == 6)
				write_string_to_solvestep_and_perform("2");
			else if (side_up[6] == 6)
				write_string_to_solvestep_and_perform("22");
			else
				;
		}
		else if (side_up[2] == 6)
		{
			if (side_up[8] == 6 || side_up[6] == 6)
				;
			else
				write_string_to_solvestep_and_perform("3");
		}
		else if (side_up[8] == 6)
		{
			if (side_up[6] == 6)
				write_string_to_solvestep_and_perform("3");
			else
				write_string_to_solvestep_and_perform("22");
		}
		else if (side_up[6] == 6)
			write_string_to_solvestep_and_perform("2");
		else
			;
		write_string_to_solvestep_and_perform("rULuRUlu");
	}
	while (1)
	{
		if (side_fr[1] == side_fr[2] && side_rt[0] == side_rt[1]
			&& side_rt[1] == side_rt[2] && side_bk[0] == side_bk[1]
			&& side_bk[1] == side_bk[2] && side_lf[0] == side_lf[1]
			&& side_lf[1] == side_lf[2] && side_fr[0] == side_fr[1])
			break;
		if (side_fr[1] == side_fr[2] && side_rt[0] == side_rt[1])
			;
		else if (side_rt[1] == side_rt[2] && side_bk[0] == side_bk[1])
			write_string_to_solvestep_and_perform("2");
		else if (side_bk[1] == side_bk[2] && side_lf[0] == side_lf[1])
			write_string_to_solvestep_and_perform("22");
		else if (side_lf[1] == side_lf[2] && side_fr[0] == side_fr[1])
			write_string_to_solvestep_and_perform("3");
		else
			;
		write_string_to_solvestep_and_perform("LFrULuRUlufl");
	}
	while (1)
	{
		if (side_fr[1] == side_fr[4]) break;
		write_string_to_solvestep_and_perform("U");
	}
}

void solve_to_final()
{
	for (int i = iter_w; i >= 0; --i)
	{
		if (solvestep[i] == '2')
		{
			finalstep[i] = '-';
			for (int j = i; j != iter_w; ++j)
			{
				if (finalstep[j] == 'L') finalstep[j] = 'F';
				else if (finalstep[j] == 'l') finalstep[j] = 'f';
				else if (finalstep[j] == 'R') finalstep[j] = 'B';
				else if (finalstep[j] == 'r') finalstep[j] = 'b';
				else if (finalstep[j] == 'F') finalstep[j] = 'R';
				else if (finalstep[j] == 'f') finalstep[j] = 'r';
				else if (finalstep[j] == 'B') finalstep[j] = 'L';
				else if (finalstep[j] == 'b') finalstep[j] = 'l';
				else
					;
			}
		}
		else if (solvestep[i] == '3')
		{
			finalstep[i] = '-';
			for (int j = i; j != iter_w; ++j)
			{
				if (finalstep[j] == 'L') finalstep[j] = 'B';
				else if (finalstep[j] == 'l') finalstep[j] = 'b';
				else if (finalstep[j] == 'R') finalstep[j] = 'F';
				else if (finalstep[j] == 'r') finalstep[j] = 'f';
				else if (finalstep[j] == 'F') finalstep[j] = 'L';
				else if (finalstep[j] == 'f') finalstep[j] = 'l';
				else if (finalstep[j] == 'B') finalstep[j] = 'R';
				else if (finalstep[j] == 'b') finalstep[j] = 'r';
				else
					;
			}
		}
		else
			finalstep[i] = solvestep[i];
	}
}

void solve_all()
{
	initialize_string(solvestep, MAXSTEPNUM);
	solve_down_edge();
	solve_down_corner();
	solve_middle_edge();
	solve_up_edge();
	solve_up_corner();
	printf("solvestep: %s\n\n", solvestep);
}

void final_all()
{
	initialize_string(finalstep, MAXSTEPNUM);
	solve_to_final();
	operation_analysis(finalstep);
	printf("finalstep: %s\n\n", finalstep);
}
