# Name: Jacklyn Trinh
# Date: 1/6/2025
# Purpose: HW 4

file_name = "grid.txt"

def load_array(filename):
    array = []
    file = open(filename, 'r')
    for line in file:
        row = [int(num) for num in line.split()]
        array.append(row)
    file.close()

    return array

def rotate_array(in_array):
    rows = len(in_array)
    cols = len(in_array[0]) if rows > 0 else 0
    out_array = [[0 for _ in range(rows)] for _ in range(cols)]
    for i in range(rows):
        for j in range(cols):
            out_array[j][rows - 1 - i] = in_array[i][j]
    return out_array

def display_array(array):
    for row in array:
        print(" ".join([str(num) for num in row]))

def main():
    grid = load_array(file_name)

    print("Original Grid:")
    display_array(grid)

    rotated_grid = rotate_array(grid)

    print("Rotated Grid:")
    display_array(rotated_grid)

if __name__ == "__main__":
    main()