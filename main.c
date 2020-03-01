/*
* Rubik's Cube Solving Program
* version 1.00a
* 
* Copyright(c) 2020 Marina Akitsuki. All rights reserved.
* Date modified: 2020/03/01
* 
*/

#include <time.h>
#include "declaration.h"

int main()
{
	cube_print();
	cube_messup();
	cube_create_snapshot();
	cube_print();

	clock_t t1, t2;
	double t;

	t1 = clock();
	solve_all();
	// cube_print();
	cube_recover_from_snapshot();
	// cube_print();
	final_all();
	t2 = clock();
	
	t = (double)(t2 - t1) / CLOCKS_PER_SEC;
	printf("t = %lfs\n\n", t);
	cube_print();

	return 0;
}
