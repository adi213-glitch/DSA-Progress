#include <bits/stdc++.h>
using namespace std;

class Student {
private :
    string name;
    int rollno;
public:
    string major;

    Student(string initial_name, int initial_rollno, string initial_major){
        name= initial_name;
        rollno=initial_rollno;
        major=initial_major;
    }
    ~Student(){}
    void set_student_details(std::string new_name, int new_rollno){
        name=new_name;
        rollno=new_rollno;
    }
    string get_student_details() {
        string s= "Name: " + name + ", Roll: " + to_string(rollno);
        return s;
    }
    string get_name() {
        return name;
    }
    int get_rollno() {
        return rollno;
    }



};