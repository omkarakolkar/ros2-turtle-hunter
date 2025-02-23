class Students:
    def __init__(self, name, age, grade):
        self.name = name
        self.age = age
        self.grade = grade

    def get_grade(self):
        return self.grade

class Course:
    def __init__(self, name, max_students):
        self.name = name
        self.max_students = max_students
        self.students = []
        
    def add_student(self, student):
        if len(self.students) <= self.max_students:
            self.students.append(student)
            return True
        return False
    
    def get_avg_grade(self):
        value = 0
        for student in self.student:
            value += student.get_grade()

        return value / len(self.students)


# class Dog:
#     def __init__(self, name, age): #fist function to be called by python by default
#         self.name = name 
#         self.age = age
        
#     def get_name(self):
#         return self.name
    
#     def get_age(self):
#         return self.age

# d = Dog("Ti", 12)
# print(d.name)
# d2 = Dog("Ror", 18)
# print(d2.age)

# class Dog:

#     def __init__(self, name):
#         self.name = name

#     def add_one(self, x): #function with variable x
#         return x + 2
    
#     def bark(self): # func with no variable
#         print("bark bow bow")

# d = Dog() #declaring class to variable d
# d.bark() #calling the function
# print(d.add_one(3))
# print(type(d)) #prints class type (<class "__main__.Dog">)