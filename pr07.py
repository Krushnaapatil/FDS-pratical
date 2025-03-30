# Write a Python program to store first year percentage of students in array.
# Write function for sorting array of floating point numbers in ascending order
# using quick sort and display top five scores.

# Function to input percentage of students
def input_percentage():
    perc = []
    number_of_students = int(input("ENTER THE TOTAL NUMBER OF STUDENTS: "))
    for i in range(number_of_students):
        perc.append(float(input(f"ENTER THE PERCENTAGE OF STUDENT {i+1}: ")))
    return perc

# Function to print percentages
def print_percentage(perc):
    if not perc:
        print("NO DATA AVAILABLE!")
        return
    for percentage in perc:
        print(f"{percentage:.2f}")

# Function for partitioning (used in Quick Sort)
def percentage_partition(perc, start, end):
    pivot = perc[start]
    lower_bound = start + 1
    upper_bound = end

    while True:
        while lower_bound <= upper_bound and perc[lower_bound] <= pivot:
            lower_bound += 1
        while lower_bound <= upper_bound and perc[upper_bound] >= pivot:
            upper_bound -= 1
        if lower_bound <= upper_bound:
            perc[lower_bound], perc[upper_bound] = perc[upper_bound], perc[lower_bound]
        else:
            break

    perc[start], perc[upper_bound] = perc[upper_bound], perc[start]
    return upper_bound

# Quick Sort function
def quick_sort(perc, start, end):
    if start < end:
        partition_index = percentage_partition(perc, start, end)
        quick_sort(perc, start, partition_index - 1)
        quick_sort(perc, partition_index + 1, end)
    return perc

# Function to display the top five percentages
def display_top_five(perc):
    if not perc:
        print("NO DATA AVAILABLE!")
        return

    n = len(perc)
    print("TOP FIVE PERCENTAGES ARE:")
    for i in range(n - 1, max(n - 6, -1), -1):  # Display top 5 scores
        print(f"{perc[i]:.2f}")

# Main Function
print("\n****** PRACTICAL NO-07(B-16) QUICK SORT ******")
unsorted_per = []
sorted_per = []

while True:
    print("\n-------------------- MENU --------------------")
    print("1. ACCEPT PERCENTAGE OF STUDENTS")
    print("2. DISPLAY PERCENTAGE OF STUDENTS (UNSORTED)")
    print("3. PERFORM QUICK SORT (SORTED)")
    print("4. DISPLAY TOP FIVE SCORES")
    print("5. EXIT")

    ch = int(input("ENTER YOUR CHOICE FROM MENU (1-5): "))

    if ch == 1:
        unsorted_per = input_percentage()
        sorted_per = []  # Reset sorted list when new input is taken
    elif ch == 2:
        print("UNSORTED PERCENTAGES:")
        print_percentage(unsorted_per)
    elif ch == 3:
        if not unsorted_per:
            print("NO DATA AVAILABLE TO SORT!")
        else:
            print("PERCENTAGES OF STUDENTS AFTER PERFORMING QUICK SORT:")
            sorted_per = quick_sort(unsorted_per[:], 0, len(unsorted_per) - 1)  # Sorting a copy
            print_percentage(sorted_per)
    elif ch == 4:
        display_top_five(sorted_per)
    elif ch == 5:
        print("THANK YOU! PROGRAM TERMINATED.")
        break
    else:
        print("INVALID CHOICE! PLEASE ENTER A VALID OPTION.")
