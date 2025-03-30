# Write a Python program to compute following operations on String:
# a) To display word with the longest length
# b) To determines the frequency of occurrence of particular character in the string
# c) To check whether given string is palindrome or not
# d) To display index of first appearance of the substring
# e) To count the occurrences of each word in a given string


# Function for Insertion Sort
def insertionSort(arr):
    for i in range(1, len(arr)):  # Start from second element (index 1)
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

# Function to print the top 5 scores
def top_5(arr):
    sorted_arr = sorted(arr, reverse=True)  # Sort in descending order
    print("\nTop 5 scores:", sorted_arr[:5])  # Print top 5 elements

# Function for Shell Sort
def shellSort(arr):
    n = len(arr)
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2

# Main program
arr = []
n = int(input("Enter number of students: "))
for i in range(n):
    marks = int(input(f"Enter marks of student {i+1}: "))
    arr.append(marks)

while True:
    print("\n******* MENU *******")
    print("1. Insertion Sort")
    print("2. Shell Sort")
    print("3. Top 5 using Insertion Sort")
    print("4. Top 5 using Shell Sort")
    print("5. Exit")
    
    ch = int(input("Enter your choice: "))
    
    if ch == 1:
        sorted_arr = arr[:]  # Create a copy to preserve original order
        insertionSort(sorted_arr)
        print("\nSorted list using Insertion Sort:", sorted_arr)
    
    elif ch == 2:
        sorted_arr = arr[:]  # Create a copy to preserve original order
        shellSort(sorted_arr)
        print("\nSorted list using Shell Sort:", sorted_arr)
    
    elif ch == 3:
        sorted_arr = arr[:]
        insertionSort(sorted_arr)
        top_5(sorted_arr)
    
    elif ch == 4:
        sorted_arr = arr[:]
        shellSort(sorted_arr)
        top_5(sorted_arr)
    
    elif ch == 5:
        print("\n*** Terminated Successfully ***")
        break
    
    else:
        print("\n*** Wrong choice ***")
