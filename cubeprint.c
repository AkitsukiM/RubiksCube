#include "declaration.h"

//     012
//     345
//     678
// 012 012 012 012
// 345 345 345 345
// 678 678 678 678
//     012
//     345
//     678
//     876
//     543
//     210

void cube_print()
{
	printf("    %d%d%d\n", side_up[0], side_up[1], side_up[2]);
	printf("    %d%d%d\n", side_up[3], side_up[4], side_up[5]);
	printf("    %d%d%d\n", side_up[6], side_up[7], side_up[8]);
	printf("%d%d%d %d%d%d %d%d%d %d%d%d\n", side_lf[0], side_lf[1], side_lf[2], side_fr[0], side_fr[1], side_fr[2], side_rt[0], side_rt[1], side_rt[2], side_bk[0], side_bk[1], side_bk[2]);
	printf("%d%d%d %d%d%d %d%d%d %d%d%d\n", side_lf[3], side_lf[4], side_lf[5], side_fr[3], side_fr[4], side_fr[5], side_rt[3], side_rt[4], side_rt[5], side_bk[3], side_bk[4], side_bk[5]);
	printf("%d%d%d %d%d%d %d%d%d %d%d%d\n", side_lf[6], side_lf[7], side_lf[8], side_fr[6], side_fr[7], side_fr[8], side_rt[6], side_rt[7], side_rt[8], side_bk[6], side_bk[7], side_bk[8]);
	printf("    %d%d%d\n", side_dn[0], side_dn[1], side_dn[2]);
	printf("    %d%d%d\n", side_dn[3], side_dn[4], side_dn[5]);
	printf("    %d%d%d\n", side_dn[6], side_dn[7], side_dn[8]);
	printf("\n");
}
