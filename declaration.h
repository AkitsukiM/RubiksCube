#ifndef DECLARATION_H
#define DECLARATION_H

#include <stdio.h>
#include <stdlib.h>

#define MAXSTEPNUM 1000

// cubeinput.c
extern int side_up[9], side_dn[9], side_lf[9], side_rt[9], side_fr[9], side_bk[9];
void cube_messup();
void cube_countermessup();
void cube_create_snapshot();
void cube_recover_from_snapshot();

// cubeprint.c
void cube_print();

// cubesolve.c
void solve_all();
void final_all();

// operation.c
void operation_analysis(char* step);

#endif // !DECLARATION_H
