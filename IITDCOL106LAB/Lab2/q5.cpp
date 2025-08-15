#include <string>

using namespace std;
class Question {
private:
    std::string student_name;
    std::string question_text;

public:
    Question(std::string name = "", std::string text = ""){
        student_name =name;
        question_text= text;
    }
    void set(std::string name, std::string text){
        student_name =name;
        question_text= text;
    }
    std::string getStudentName() const {
        return student_name;
    }
    std::string getQuestionText() const {
        return question_text;
    }
};

struct QuestionNode {
    Question data;
    QuestionNode* next;

    QuestionNode(Question q){
        data=q;
        next=nullptr;
    }
};

class QuestionStack {
private:
    QuestionNode* top;

public:
    QuestionStack(){
        top=nullptr;
    }
    ~QuestionStack(){
    
        while(top){
            QuestionNode * temp = top;
            top=top->next;
            delete temp;
        }
    }
    void push(Question q){
        QuestionNode * que = new QuestionNode (q);
        que->next= top;
        top=que;
    }
    Question pop(){
        if(!top) return Question();
        QuestionNode * temp = top;
        top=top->next;
        temp->next=nullptr;
        Question  ans = temp->data; 
        delete temp;
        return (ans);
    }
    Question peek() {
        if(!top) return Question();
        
        return (top->data);
    }
    bool isEmpty() {
        if(top) return false;
        return true;
    }
};

class Teacher {
private:
    std::string name;
    QuestionStack question_stack;

public:
    Teacher(std::string name = ""){
        this->name = name;
    }
    void set(std::string name){
        this->name = name;
    }
    
    void askQuestion(std::string student_name, std::string question_text){
        question_stack.push(Question(student_name, question_text));
    }
    std::string answerQuestion(){
        if(question_stack.isEmpty()) return "";
        return (question_stack.pop().getStudentName());
    }
    std::string peekNextQuestion(){
        if(question_stack.isEmpty()) return "";
        Question q  = question_stack.peek();
        return (q.getQuestionText());
        
    }
    bool checkStatus(){
        if(question_stack.isEmpty()) return false;
        return true;
    }
};