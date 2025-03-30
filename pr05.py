# Write a Python program to store first year percentage of students in array.
# Write function for sorting array of floating point numbers in ascending order
# using a) Selection Sort b) Bubble sort and display top five scores.

def bubble_sort(arr):
    n = len(arr)
    sorted_arr = arr.copy()  # Copy to preserve original list
    for i in range(n - 1):
        for j in range(n - i - 1):
            if sorted_arr[j] > sorted_arr[j + 1]:  # Swap elements if needed
                sorted_arr[j], sorted_arr[j + 1] = sorted_arr[j + 1], sorted_arr[j]
    print("\nMarks of students after Bubble Sort:")
    print(sorted_arr)
    return sorted_arr

def selection_sort(arr):
    sorted_arr = arr.copy()  # Copy to preserve original list
    for i in range(len(sorted_arr)):
        min_idx = i
        for j in range(i + 1, len(sorted_arr)):
            if sorted_arr[min_idx] > sorted_arr[j]:
                min_idx = j
        sorted_arr[i], sorted_arr[min_idx] = sorted_arr[min_idx], sorted_arr[i]
    print("\nMarks of students after Selection Sort:")
    print(sorted_arr)
    return sorted_arr

def top_5(sorted_arr):
    print("\nTop 5 scores:")
    print(sorted_arr[-5:][::-1])  # Reverse last 5 elements to get top scores

# Main program
list1 = []
n = int(input("Enter number of students: "))
for i in range(n):
    m = int(input(f"Enter marks of student {i+1}: "))
    list1.append(m)

while True:
    print("\n******* MENU *******")
    print("1. Bubble Sort")
    print("2. Selection Sort")
    print("3. Top 5 scores (Bubble Sort)")
    print("4. Top 5 scores (Selection Sort)")
    print("5. Exit")
    
    ch = int(input("Enter your choice: "))
    
    if ch == 1:
        sorted_bubble = bubble_sort(list1)
    elif ch == 2:
        sorted_selection = selection_sort(list1)
    elif ch == 3:
        if 'sorted_bubble' in locals():
            top_5(sorted_bubble)
        else:
            print("\nPerform Bubble Sort first!")
    elif ch == 4:
        if 'sorted_selection' in locals():
            top_5(sorted_selection)
        else:
            print("\nPerform Selection Sort first!")
    elif ch == 5:
        print("\n*** Terminated Successfully ***")
        break
    else:
        print("\nWrong choice! Try again.")
