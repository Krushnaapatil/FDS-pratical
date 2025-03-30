# matrix opreationss 

# Function to print a matrix
def printmat(mat):
    for row in mat:
        for val in row:
            print("\t", val, end=" ")
        print("\n")

# Function to initialize a zero matrix
def initmat(m, n):
    return [[0 for _ in range(n)] for _ in range(m)]

# Function to take matrix input from the user
def takemat():
    r = int(input("ENTER TOTAL NO. OF ROWS: "))
    c = int(input("ENTER TOTAL NO. OF COLUMNS: "))
    mat = initmat(r, c)  # Initialize with zeros
    for i in range(r):
        for j in range(c):
            mat[i][j] = int(input(f"ENTER ELEMENT [{i}][{j}]: "))
    return mat, r, c

# Function for addition of two matrices
def addmat(mat1, mat2, r, c):
    return [[mat1[i][j] + mat2[i][j] for j in range(c)] for i in range(r)]

# Function for subtraction of two matrices
def submat(mat1, mat2, r, c):
    return [[mat1[i][j] - mat2[i][j] for j in range(c)] for i in range(r)]

# Function for transpose of a matrix
def trasmat(mat, r, c):
    return [[mat[j][i] for j in range(r)] for i in range(c)]

# Function for matrix multiplication
def multmat(mat1, mat2, r1, c1, r2, c2):
    res = initmat(r1, c2)  # Initialize result matrix with zeros
    for i in range(r1):
        for j in range(c2):
            for k in range(c1):  # Since c1 == r2
                res[i][j] += mat1[i][k] * mat2[k][j]
    return res

# Main program starts here
print("**** PRACTICAL NO.09 ****")
mat1, r1, c1 = takemat()
print("\nMatrix 1:")
printmat(mat1)

mat2, r2, c2 = takemat()
print("\nMatrix 2:")
printmat(mat2)

# Display menu for operations
while True:
    print("\n******* MENU *******")
    print("1. ADDITION OF MATRICES")
    print("2. SUBTRACTION OF MATRICES")
    print("3. TRANSPOSE OF A MATRIX")
    print("4. MULTIPLICATION OF MATRICES")
    print("5. EXIT")

    ch = int(input("\nENTER YOUR CHOICE: "))

    if ch == 1:
        if r1 == r2 and c1 == c2:
            result = addmat(mat1, mat2, r1, c1)
            print("\nResultant Matrix After Addition:")
            printmat(result)
        else:
            print("\n*ADDITION NOT POSSIBLE*")

    elif ch == 2:
        if r1 == r2 and c1 == c2:
            result = submat(mat1, mat2, r1, c1)
            print("\nResultant Matrix After Subtraction:")
            printmat(result)
        else:
            print("\n*SUBTRACTION NOT POSSIBLE*")

    elif ch == 3:
        print("\nTRANSPOSE OF FIRST MATRIX:")
        result = trasmat(mat1, r1, c1)
        printmat(result)

        print("\nTRANSPOSE OF SECOND MATRIX:")
        result = trasmat(mat2, r2, c2)
        printmat(result)

    elif ch == 4:
        if c1 == r2:
            print("\nMULTIPLICATION OF MATRICES:")
            result = multmat(mat1, mat2, r1, c1, r2, c2)
            printmat(result)
        else:
            print("\n*MULTIPLICATION NOT POSSIBLE* (Columns of Matrix 1 must equal Rows of Matrix 2)")

    elif ch == 5:
        print("\n*** TERMINATED SUCCESSFULLY ***")
        break

    else:
        print("\n** WRONG CHOICE, TRY AGAIN **")
