# Name: Jacklyn Trinh
# Date: 1/6/2025
# Purpose: HW 4

def load_grid(filename):
    grid = []
    with open(filename, 'r') as file:
        for line in file:
            grid.append(list(map(int, line.split())))
    return grid

def rotate_grid_90(grid):
    rows, cols = len(grid), len(grid[0])
    rotated_grid = [[0] * rows for _ in range(cols)]
    for i in range(rows):
        for j in range(cols):
            rotated_grid[j][rows - 1 - i] = grid[i][j]
    return rotated_grid

def display_grid(grid):
    for row in grid:
        print(' '.join(map(str, row)))

def main():
    filename = 'grid.txt'
    grid = load_grid(filename)
    print("Original Grid:")
    display_grid(grid)

    rotated_grid = rotate_grid_90(grid)
    print("Rotated Grid:")
    display_grid(rotated_grid)

if __name__ == "__main__":
    main()