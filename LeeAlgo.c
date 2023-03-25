#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

typedef struct {
  int row, col;
} Cell;

//Traversing the array
const int NUM_DIRECTIONS = 4;
const int DIRECTION_ROW[4] = {-1, 0, 1, 0}; // U R D L
const int DIRECTION_COL[4] = {0, 1, 0, -1}; // U R D L

//helper function to check if we are within the bounds of the grid
int is_valid(int grid[][COLS], int row, int col)
{
  return row >= 0 && row < ROWS && col >=0 && col < COLS && grid[row][col] == 0;
}

//Body of the algorithm
int lee_algorithm(int grid[][COLS], Cell source, Cell target)
{
  int distance = -1;
  int queue[ROWS*COLS];
  int front = 0, rear = 0;
  int visited[ROWS][COLS] = {0}; // Array to mark visited cells

  queue[rear++] = source.row * COLS + source.col;

  while (front < rear)
  {
    int current_cell = queue[front++];
    int current_row = current_cell / COLS;
    int current_col = current_cell % COLS;

    if (current_row == target.row && current_col == target.col)
    {
      distance = visited[current_row][current_col];
      break;
    }

    for (int i = 0; i < NUM_DIRECTIONS; i++) 
    {
      int neighbor_row = current_row + DIRECTION_ROW[i];
      int neighbor_col = current_col + DIRECTION_COL[i];
// Is the neighbor cell valid and unvisited?
      if (is_valid(grid, neighbor_row, neighbor_col) && !visited[neighbor_row][neighbor_col]) 
      {
        queue[rear++] = neighbor_row * COLS + neighbor_col;
        visited[neighbor_row][neighbor_col] = visited[current_row][current_col] + 1;
        }
      }
   }
  return distance;
}



int main(void)
{
  int grid[ROWS][COLS] = {
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0},
    {0,0,1,0,1,0,0,0,1,0},
    {0,0,0,0,1,1,0,0,1,0},
    {0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0},
    {0,0,1,0,0,1,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
  };

  Cell source = {5,2};
  Cell target = {9,9};

    int distance = lee_algorithm(grid, source, target);
    printf("Lee Algorithm\n");
    printf("Shortest distance from source (%d, %d) to target (%d, %d) is %d\n", source.row, source.col, target.row, target.col, distance);

    return 0;
}
