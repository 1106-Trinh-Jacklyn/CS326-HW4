//Name: Jacklyn Trinh
//Date: 1/6/2025
//Purpose: HW 4

#include <iostream>
#include <fstream>

using namespace std;

#define MAX 100

void loadGrid(const string& filename, int& rows, int& cols, int grid[MAX][MAX]);
void rotateGrid(int rows, int cols, int grid[MAX][MAX], int rotatedGrid[MAX][MAX]);
void displayGrid(int rows, int cols, int grid[MAX][MAX]);

int main(){
  string filename = "grid.txt";
  int grid[MAX][MAX];
  int rotatedGrid[MAX][MAX];
  int rows, cols;

  loadGrid(filename, rows, cols, grid);
  cout << "Original Grid:" << endl;
  displayGrid(rows, cols, grid);

  rotateGrid(rows, cols, grid, rotatedGrid);
  cout << "Rotated Grid:" << endl;
  displayGrid(cols, rows, rotatedGrid);

  return 0;
}

void loadGrid(const string& filename, int& rows, int& cols, int grid[MAX][MAX]){
  ifstream file(filename);

  if(file.is_open()){
    int value;
    rows = 0;
    cols = 0;

    while(true){
      int colCount = 0;

      while(file >> value){
        grid[rows][colCount++] = value;

        if(file.peek() == '\n' || file.peek() == EOF){
          break;
        }
      }

      if(colCount > 0){
        if(cols == 0){
          cols = colCount;
        }
        rows++;
      }

      if(file.eof()){
        break;
      }
    }

    file.close();
  }
  else{
    throw "Error";
  }
}

void rotateGrid(int rows, int cols, int grid[MAX][MAX], int rotatedGrid[MAX][MAX]){
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      rotatedGrid[j][rows - 1 - i] = grid[i][j];
    }
  }
}

void displayGrid(int rows, int cols, int grid[MAX][MAX]){
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
}
