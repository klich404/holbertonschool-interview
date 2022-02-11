#ifndef SANDPILES_H
#define SANDPILES_H

static void print_grid(int grid[3][3]);
void sand_topple(int *grid);
int is_done(int *grid);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

#endif /* SANDPILES_H */
