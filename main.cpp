//Name: Jacklyn Trinh
//Date: 1/6/2025
//Purpose: HW 4

#include <iostream>
#include <fstream>

using namespace std;

#define ROWS 5
#define COLS 4
#define FILENAME "grid.txt"

void loadArray(ifstream& file, int& rows, int& cols, int array[][COLS]);
void rotateArray(int rows, int cols, int inArray[][COLS], int outArray[][ROWS]);
void displayArray1(int rows, int cols, int array[][COLS]);
void displayArray2(int rows, int cols, int array[][ROWS]);

int main(){
  int rows, cols;
  int grid[ROWS][COLS];
  int rotatedGrid[COLS][ROWS];


  ifstream file(FILENAME);
  if(file.is_open()){
    loadArray(file, rows, cols, grid);
    file.close();
  }
  else{
    throw "Error";
  }

  cout << "Original Grid:" << endl;
  displayArray1(rows, cols, grid);

  rotateArray(rows, cols, grid, rotatedGrid);

  cout << "Rotated Grid:" << endl;
  displayArray2(cols, rows, rotatedGrid);

  return 0;
}

void loadArray(ifstream& file, int& rows, int& cols, int array[][COLS]){
  int value;
  rows = 0;
  cols = 0;

  while(true){
    int colCount = 0;

    while(file >> value){
      array[rows][colCount++] = value;

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
}

void rotateArray(int rows, int cols, int inArray[][COLS], int outArray[][ROWS]){
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      outArray[j][rows - 1 - i] = inArray[i][j];
    }
  }
}

void displayArray1(int rows, int cols, int array[][COLS]){
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      cout << array[i][j] << " ";
    }
    cout << endl;
  }
}

void displayArray2(int rows, int cols, int array[][ROWS]){
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      cout << array[i][j] << " ";
    }
    cout << endl;
  }
}