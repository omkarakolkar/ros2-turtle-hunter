//Omkar akolkar tag 
#include <iostream>
#include <cstdlib> 
#include <cmath>   

using namespace std;

// utitlity functions
void safeStringCopy(char* destination, const char* source, size_t maxLength) {
    size_t i = 0;
    while (i < maxLength - 1 && source[i] != '\0') {
        destination[i] = source[i];
        i++;
    }
    destination[i] = '\0'; 
}

bool stringsAreEqual(const char* str1, const char* str2) {
    while (*str1 && *str2) {
        if (*str1 != *str2) return false;
        str1++;
        str2++; //omkar akolkar
    }
    return *str1 == *str2;
}

// Base class erson
class Person {
protected:
    char surname[50];
    char firstName[50];
    char email[100];

public:
    Person() {
        surname[0] = '\0';
        firstName[0] = '\0';
        email[0] = '\0';
    }

    
    Person(const char* surname, const char* firstName, const char* email) {
        safeStringCopy(this->surname, surname, sizeof(this->surname));
        safeStringCopy(this->firstName, firstName, sizeof(this->firstName));
        safeStringCopy(this->email, email, sizeof(this->email));
    }

    const char* getEmail() const { return email; }
    virtual void display() const {
        cout << "Name: " << firstName << " " << surname
             << ", Email:" << email << endl;
    }
};


class Lecturer : public Person {
    char academicTitle[20];

public:
    Lecturer(const char* surname, const char* firstName, const char* email, const char* academicTitle)
        : Person(surname, firstName, email) {
        safeStringCopy(this->academicTitle, academicTitle, sizeof(this->academicTitle));
    }//omkar akolkar

    const char* getAcademicTitle() const { return academicTitle; }

    void display() const override {
        cout << academicTitle << " " << firstName << " " << surname
             << ", Email: " << email << endl;
    }
};

// Derived class STUDENT
class Student : public Person {
    char university[50];
    int matriculationNumber;
    bool hasCourse;//omkar akolkar

public:
    Student() : Person(), matriculationNumber(0), hasCourse(false) {
        university[0] = '\0';
    }

    Student(const char* surname, const char* firstName, const char* email, const char* university, int matricNumber)
        : Person(surname, firstName, email), matriculationNumber(matricNumber), hasCourse(false) {
        safeStringCopy(this->university, university, sizeof(this->university));
    }

    const char* getUniversity() const { return university; }
    bool canRegister() const { return stringsAreEqual(university, "our University") || !hasCourse; }
    void setRegistered() { hasCourse = true; }

    void display() const override {
        Person::display();//omkar akolkar
        cout << "University: " << university << ", Matriculation Nuber: " << matriculationNumber << endl;
    }
};

// Class COURSE
class Course {
    char name[50];
    Lecturer lecturer;
    int maxSeats;
    Student* participants;
    int numParticipants;

public:
    Course(const char* name, Lecturer lecturer, int maxSeats)
        : lecturer(lecturer), maxSeats(maxSeats), numParticipants(0) {
        safeStringCopy(this->name, name, sizeof(this->name));//omkar akolkar
        participants = new Student[maxSeats];  // Dynamic allocation of maxSeats
    }

    ~Course() {
        delete[] participants;  
    }

    const char* getName() const { return name; }
    bool isFull() const { return numParticipants >= maxSeats; }
    int getFreeSeats() const { return maxSeats - numParticipants; }
    const Lecturer& getLecturer() const { return lecturer; }

    bool registerStudent(const Student& student) {
        for (int i = 0; i < numParticipants; ++i) {
            if (stringsAreEqual(participants[i].getEmail(), student.getEmail())) {
                return false;
            }
        }
        if (!isFull()) {
            participants[numParticipants++] = student;
            return true;
        }
        return false;//omkarakolkar
    }

    void display() const {
        cout << "cours: " << name << ", Lecturer:";
        lecturer.display();
        cout << "Participants (" << numParticipants << "/" << maxSeats << "):\n";
        for (int i = 0; i < numParticipants; ++i) {
            participants[i].display();
        }
        if (numParticipants < 3) {
            cout << "Curse will not take place\n";
        }
    }

    Student* getParticipants() const { return participants; }
    int getNumParticipants() const { return numParticipants; }
};


void registerForCourse(Course* courses, int numCourses, Student* students, int numStudents) {
    string studentEmail, courseName;
    cout << "Enter student email: ";
    cin >> studentEmail;
    cout << "Enter course name: ";
    cin.ignore(); 
    getline(cin, courseName);

    Student* studentPtr = nullptr;
    for (int i = 0; i < numStudents; ++i) {
        if (stringsAreEqual(students[i].getEmail(), studentEmail.c_str()) && students[i].canRegister()) {
            studentPtr = &students[i];
            break;
        }
    }

    if (!studentPtr) {
        cout << "Student not found can't register.\n";
        return;
    }

    Course* coursePtr = nullptr;
    for (int i = 0; i < numCourses; ++i) {
        if (stringsAreEqual(courses[i].getName(), courseName.c_str())) {
            coursePtr = &courses[i];
            break;//omkarakolkar
        }
    }

    if (!coursePtr || !coursePtr->registerStudent(*studentPtr)) {
        cout << "Course not found / student cannot registred.\n";
        return;
    }

    studentPtr->setRegistered();
    cout << "Student registerd successfuly \n";
}


void displayCourses(Course* courses, int numCourses) {
    for (int i = 0; i < numCourses; ++i) {
        courses[i].display();
    }
}

void displayAvailableCourses(Course* courses, int numCourses) {
    for (int i = 0; i < numCourses; ++i) {
        if (!courses[i].isFull()) {
            cout << courses[i].getName() << " has " << courses[i].getFreeSeats() << " free seats.\n";
        }
    }
}

void notifyParticipants(Course* courses, int numCourses) {
    for (int i = 0; i < numCourses; ++i) {
        if (courses[i].getNumParticipants() < 3) {
            cout << "Course \"" << courses[i].getName() << "\" is canceled. Notify participants:\n";
            for (int j = 0; j < courses[i].getNumParticipants(); ++j) {
                courses[i].getParticipants()[j].display();
            }
        }
    }
}

// Main function
int main() {
    Lecturer lecturer1("Smith", "Sam", "sam.smith@un.edu", "Dr.");
    Lecturer lecturer2("Brown", "Emily", "emily.brown@uni.edu", "Prof.");
    Lecturer lecturer3("Orendi", "Claudia", "claudia.orendi@uni.edu", "Dr.");//omkarakolkar

    Course courses[] = {
        {"Buisness", lecturer1, 10},
        {"Databases", lecturer2, 10},
        {"Software Engineering", lecturer3, 10}
    };
    int numCourses = sizeof(courses) / sizeof(courses[0]);

    Student students[] = {
        {"Rane", "Sawan", "sawan.rane@otheruni.edu", "Other University", 101},
        {"Mueller", "Thomas", "thomas.mueller@uni.edu", "Our University", 102},
        {"Dhonde", "Atharva", "atharva.dhonde@uni.edu", "Our University", 103},
        {"Akolkar", "Eshita", "eshita.akolkar@otheruni.edu", "Other University", 104}
    };
    int numStudents = sizeof(students) / sizeof(students[0]);

    int choice;
    do {
        cout << "\n1. Register for a course\n"
             << "2. Display courses\n"
             << "3. Display courses with free seats\n"
             << "4. Notify participants of canceled courses\n"
             << "5. exit\n"
             << "Enter your choice: ";
        cin >> choice;//omkarakolkar

        switch (choice) {
        case 1:
            registerForCourse(courses, numCourses, students, numStudents);
            break;
        case 2:
            displayCourses(courses, numCourses);
            break;
        case 3:
            displayAvailableCourses(courses, numCourses);
            break;
        case 4:
            notifyParticipants(courses, numCourses);
            break;
        case 5:
            cout << "Exiting program. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;//omkarakolkar
}
