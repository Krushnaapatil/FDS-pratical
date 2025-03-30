# // In second year computer engineering class, group A student’s play cricket, group B
# // students play badminton and group C students play football.
# // Write a Python program using functions to compute following: -
# // a) List of students who play both cricket and badminton
# // b) List of students who play either cricket or badminton but not both
# // c) Number of students who play neither cricket nor badminton
# // d) Number of students who play cricket and football but not badminton.
# // (Note- While realizing the group, duplicate entries should be avoided, Do not use SET
# // built-in functions)

# Function to remove duplicates from a list
def removeDuplicate(d):
    lst = []
    for i in d:
        if i not in lst:
            lst.append(i)
    return lst

# Function for finding the intersection between two sets (A & B)
def intersection(lst1, lst2):
    return [val for val in lst1 if val in lst2]

# Function for symmetric difference (elements in either list but not both)
def sym_diff(lst1, lst2):
    return [val for val in lst1 + lst2 if (val in lst1) != (val in lst2)]

# Function for set union
def union(lst1, lst2):
    return list(set(lst1 + lst2))

# Function for set difference (A - B)
def diff(lst1, lst2):
    return [val for val in lst1 if val not in lst2]

# Function for finding students who play both cricket and badminton
def CB(lst1, lst2):
    lst3 = intersection(lst1, lst2)
    print("\nList of students who play both cricket and badminton:", lst3)
    return len(lst3)

# Function for finding students who play either cricket or badminton but not both
def eCeB(lst1, lst2):
    lst3 = sym_diff(lst1, lst2)
    print("\nList of students who play either cricket or badminton but not both:", lst3)
    return len(lst3)

# Function for finding students who play neither cricket nor badminton
def nCnB(lst1, lst2, lst3):
    lst4 = diff(lst1, union(lst2, lst3))
    print("\nList of students who play neither cricket nor badminton:", lst4)
    return len(lst4)

# Function for finding students who play cricket and football but not badminton
def CBnF(lst1, lst2, lst3):
    lst4 = diff(intersection(lst1, lst2), lst3)
    print("\nList of students who play cricket and football but not badminton:", lst4)
    return len(lst4)

# Main function
se = []
n = int(input("\nEnter number of students in SE COMP: "))
print("Enter the names of", n, "students:")
for i in range(n):
    ele = input()
    se.append(ele)
print("Original list of students in SE COMP:", se)

# Creating an empty list for Cricket
Cricket = []
n = int(input("\nEnter number of students who play cricket: "))
print("Enter the names of", n, "students who play cricket:")
for i in range(n):
    ele = input()
    Cricket.append(ele)
Cricket = removeDuplicate(Cricket)
print("List of students playing cricket after removing duplicates:", Cricket)

# Creating an empty list for Football
Football = []
n = int(input("\nEnter number of students who play football: "))
print("Enter the names of", n, "students who play football:")
for i in range(n):
    ele = input()
    Football.append(ele)
Football = removeDuplicate(Football)
print("List of students playing football after removing duplicates:", Football)

# Creating an empty list for Badminton
Badminton = []
n = int(input("\nEnter number of students who play badminton: "))
print("Enter the names of", n, "students who play badminton:")
for i in range(n):
    ele = input()
    Badminton.append(ele)
Badminton = removeDuplicate(Badminton)
print("List of students playing badminton after removing duplicates:", Badminton)

while True:
    print("\n--------------------MENU--------------------")
    print("1. List of students who play both cricket and badminton")
    print("2. List of students who play either cricket or badminton but not both")
    print("3. List of students who play neither cricket nor badminton")
    print("4. Number of students who play cricket and football but not badminton")
    print("5. Exit")
    
    ch = int(input("Enter your choice (1 to 5): "))
    
    if ch == 1:
        print("Number of students who play both cricket and badminton:", CB(Cricket, Badminton))
    elif ch == 2:
        print("Number of students who play either cricket or badminton but not both:", eCeB(Cricket, Badminton))
    elif ch == 3:
        print("Number of students who play neither cricket nor badminton:", nCnB(se, Cricket, Badminton))
    elif ch == 4:
        print("Number of students who play cricket and football but not badminton:", CBnF(Cricket, Football, Badminton))
    elif ch == 5:
        print("\n*** THANK YOU ***\n")
        break
    else:
        print("\n*** Invalid choice ***\n")
