# Write a Python program to store marks scored in subject “Fundamental of Data
# Structure” by N students in the class. Write functions to compute following:
# a) The average score of class
# b) Highest score and lowest score of class
# c) Count of students who were absent for the test
# d) Display mark with highest frequency

# Function to calculate the average marks
def avg(l):
    summ = 0
    cnt = 0
    for i in range(len(l)):
        if l[i] != -1:  # -1 represents an absent student
            summ += l[i]
            cnt += 1
    if cnt == 0:  # Avoid division by zero
        print("No valid marks to calculate average.")
        return
    average = summ / cnt
    print("TOTAL MARKS:", summ)
    print("AVG MARKS:", average)

# Function to count the number of absent students
def abse(l):
    cnt = sum(1 for i in l if i == -1)
    return cnt

# Function to find the maximum marks
def max1(l):
    valid_marks = [i for i in l if i != -1]
    return max(valid_marks) if valid_marks else "No valid marks available"

# Function to find the minimum marks
def min1(l):
    valid_marks = [i for i in l if i != -1]
    return min(valid_marks) if valid_marks else "No valid marks available"

# Function to find the highest frequency of marks
def maxf(l):
    valid_marks = [i for i in l if i != -1]
    if not valid_marks:
        print("No valid marks available for frequency calculation.")
        return
    
    freq_dict = {}
    for mark in valid_marks:
        freq_dict[mark] = freq_dict.get(mark, 0) + 1
    
    max_freq = max(freq_dict.values())
    most_frequent_marks = [mark for mark, freq in freq_dict.items() if freq == max_freq]

    print("\nMarks Frequency:")
    for mark, freq in freq_dict.items():
        print(f"{mark} --> {freq} times")
    
    print("\nHIGHEST MARKS FREQUENCY:", max_freq, "times for marks:", most_frequent_marks)

# Accept marks of 'n' students
student_marks = []
n = int(input("Enter number of students: "))

print("Enter marks of students (-1 for absent students):")
for i in range(n):
    marks = int(input(f"Student {i+1} marks: "))
    student_marks.append(marks)

while True:
    print("\n****** MENU ******")
    print("1. AVERAGE")
    print("2. MAXIMUM MARKS")
    print("3. MINIMUM MARKS")
    print("4. ABSENT STUDENTS COUNT")
    print("5. HIGHEST MARK FREQUENCY")
    print("6. EXIT")
    print("******************\n")

    ch = int(input("ENTER YOUR CHOICE: "))
    
    if ch == 1:
        avg(student_marks)
    elif ch == 2:
        print("MAX MARKS:", max1(student_marks))
    elif ch == 3:
        print("MIN MARKS:", min1(student_marks))
    elif ch == 4:
        print("NUMBER OF ABSENT STUDENTS:", abse(student_marks))
    elif ch == 5:
        maxf(student_marks)
    elif ch == 6:
        print("\n*** THANK YOU ***\n")
        break
    else:
        print("\n*** INVALID CHOICE ***\n")
