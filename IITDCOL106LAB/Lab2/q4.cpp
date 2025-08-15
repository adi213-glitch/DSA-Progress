#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Patient {
private:
    std::string name;
    int age;
    std::string disease;

public:
    
    void set_patient_details(std::string name, int age, std::string disease){
        this->name = name;
        this-> age = age;
        this ->disease = disease;
    }
    void print_patient_details(){

        cout<<"Name: "<<name<<", Age: "<<age<<", Disease: "<<disease<<endl;
    }
};

void evaluate(std::string input_line){
    int N=0, i=0;
    while(input_line[i]!=' '){
        N*=10;
        N+= (input_line[i++]-'0');
    }
    i++;
    // let I be number of patients counter
    int  n= input_line.length();
    for(int I=1; I<=N; I++){
        string patname="", disname="";
        int ageyo = 0;
        while(i<n && input_line[i]!=' '){
            patname+=input_line[i++];
        }
        i++;
        while(i<n && input_line[i]!=' '){
            ageyo *=10;
            ageyo += (input_line[i++]-'0');
        }
        i++;
        while(i<n && input_line[i]!=' '){
            disname+=input_line[i++];
        }
        i++;
        Patient p1;
        p1.set_patient_details(patname, ageyo, disname);
        p1.print_patient_details();

    }
}
