#include<iostream>
#include<memory>
using namespace std;

// Forward declaration of Student class
class Student;

class Teacher {
    public:
        // Smart pointer to hold Student object
        shared_ptr<Student> s;
    
        // Method to set the student pointer
        void setStudent(shared_ptr<Student> s1) {
            s = s1;
            cout << "Teacher: Student pointer set" << endl;
        }
};

class Student {
    public:
        // Smart pointer to hold Teacher object
        shared_ptr<Teacher> t;
    
        // Method to set the teacher pointer
        void setTeacher(shared_ptr<Teacher> t1) {
            t = t1;
            cout << "Student: Teacher pointer set" << endl;
        }
};

int main(){
    // Declare smart pointers for Teacher and Student
    shared_ptr<Teacher> teacherObj;
    shared_ptr<Student> studentObj;

    cout << "Creating Teacher and Student objects..." << endl;

    // Create objects using make_shared
    teacherObj = make_shared<Teacher>();
    studentObj = make_shared<Student>();

    cout << "Setting up circular references..." << endl;

    // Create circular reference between Teacher and Student
    teacherObj->setStudent(studentObj);
    studentObj->setTeacher(teacherObj);

    cout << "Program completed successfully" << endl;

    return 0;
}

// Creating Teacher and Student objects...
// Setting up circular references...
// Teacher: Student pointer set
// Student: Teacher pointer set
// Program completed successfully

// -------------------------------------------------

// To break the circular reference, replace one of the std::shared_ptr 
// references with a std::weak_ptr. A std::weak_ptr does not contribute
// to the reference count, thereby allowing proper destruction of objects
// when they go out of scope.

#include<iostream>
#include<memory>
using namespace std;

// Forward declaration of Student class
class Student;

class Teacher {
    public:
        // Weak pointer to hold Student object to prevent circular reference
        weak_ptr<Student> s;

        // Method to set the student pointer
        void setStudent(shared_ptr<Student> s1) {
            s = s1;
            cout << "Teacher: Student pointer set" << endl;
        }
};

class Student {
    public:
        // Weak pointer to hold Teacher object to prevent circular reference
        weak_ptr<Teacher> t;

        // Method to set the teacher pointer
        void setTeacher(shared_ptr<Teacher> t1) {
            t = t1;
            cout << "Student: Teacher pointer set" << endl;
        }
};

int main(){
    // Declare smart pointers for Teacher and Student
    shared_ptr<Teacher> teacherObj;
    shared_ptr<Student> studentObj;

    cout << "Creating Teacher and Student objects..." << endl;

    // Create objects using make_shared
    teacherObj = make_shared<Teacher>();
    studentObj = make_shared<Student>();

    cout << "Setting up circular references..." << endl;

    // Create circular reference between Teacher and Student
    teacherObj->setStudent(studentObj);
    studentObj->setTeacher(teacherObj);

    cout << "Program completed successfully" << endl;

    return 0;
}

// Creating Teacher and Student objects...
// Setting up circular references...
// Teacher: Student pointer set
// Student: Teacher pointer set
// Program completed successfully