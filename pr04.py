# Write a Python program that determines the location of a saddle point of matrix if one
# exists. An m x n matrix is said to have a saddle point if some entry a[i][j] is the smallest
# value in row i and the largest value in j.

def saddle(mat, r, c):
    # Process each row
    for i in range(r):
        # Find the minimum element in the row
        min_row = mat[i][0]
        col_ind = 0
        for j in range(1, c):
            if mat[i][j] < min_row:
                min_row = mat[i][j]
                col_ind = j
        
        # Check if the minimum element in the row is also the maximum in its column
        is_saddle = True
        for k in range(r):
            if mat[k][col_ind] > min_row:  # If any element in the column is greater, it's not a saddle point
                is_saddle = False
                break

        # If it's a saddle point, print it
        if is_saddle:
            print(f"Saddle point found: {min_row} at location m[{i}][{col_ind}]")
            return True

    print("No saddle point found.")
    return False

# Function to print a matrix
def printmat(mat):
    for row in mat:
        for elem in row:
            print(f"\t{elem}", end=" ")
        print()

# Function to take matrix input
def inputmat():
    r = int(input("Enter number of rows: "))
    c = int(input("Enter number of columns: "))
    mat = []
    
    print("Enter matrix elements row-wise:")
    for i in range(r):
        row = list(map(int, input().split()))  # Takes space-separated input for a row
        if len(row) != c:
            print("Error: Number of elements doesn't match column size. Try again.")
            return inputmat()  # Re-enter the matrix
        mat.append(row)
    
    return mat, r, c

# Main program
print("Practical No. 08 - Saddle Point Finder")
print("Code by Krushna ~~~~\n")

# Input matrix
matrix, rows, cols = inputmat()

# Print matrix
print("\nGiven Matrix:")
printmat(matrix)

# Find Saddle Point
saddle(matrix, rows, cols)
