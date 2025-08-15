#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Book {
private:
    std::string title;
    std::string author;
    int pages;

public:
    
    void set_book_details(std::string title, std::string author, int pages){
        this->title= title;
        this->author = author;
        this ->pages = pages;
    }
    void print_book_details(){
        std::cout<<"Title: "<<title<< ", Author: "<< author<< ", Pages: "<<pages<<std::endl;
    }
};

void evaluate(std::vector<std::string> parsed_args){
    for(string s : parsed_args){
        
        int n =s.length();
        string titlename="", authorname="";
        int nopages=0,i=0;
        
            
        while(i<n && s[i]!=' '){
            titlename+=s[i++];
        }
        i++;
            
        while(i<n && s[i]!=' '){
            authorname+=s[i++];
        }
        i++;
           
        while(i<n){
            nopages*=10;
            nopages +=( s[i++]-'0');
        }
        Book b1;
        b1.set_book_details(titlename , authorname, nopages);
        b1.print_book_details();
    }

}
