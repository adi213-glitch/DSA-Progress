#include <bits/stdc++.h>
using namespace std;

class Customer {
private:
    std::string name;
    int credit;

public:
    Customer(std::string n = "", int c = 0){
        name =n;
        credit=c;
    }
    ~Customer(){}
    void setName(std::string n){
        name=n;
    }
    void setCredit(int c){
        credit=c;
    }
    std::string getName(){
        return name;
    }
    int getCredit(){
        return credit;
    }
    void withdraw(int amount){
        if(credit>=amount) credit-=amount;
    }
};

struct CustomerNode {
    Customer customerData;
    CustomerNode* next;

    CustomerNode(Customer cust){
        customerData=cust;
        next=NULL;
    }
    ~CustomerNode(){};
};

class CustomerLinkedList {
private:
    CustomerNode* head;

public:
    CustomerLinkedList(){
        head=NULL;
    }
    ~CustomerLinkedList(){
        while(head){
            CustomerNode * temp = head;
            head=head->next;
            delete temp;
        }
    }
    void addCustomer(std::string name, int credit){
        Customer data(name,credit);
        CustomerNode * newcustomer = new CustomerNode(data);
        if(!head) {
            head= newcustomer;
            return;
        }
        CustomerNode * temp = head;
        while(temp->next){
            temp=temp->next;
        }
        temp->next= newcustomer;
    }
    void displayAllCustomers(){
        CustomerNode * temp = head;
        while(temp){
            cout<< "Customer Name: "<< temp->customerData.getName()<<", Credit: "<<temp->customerData.getCredit()<<endl;
            temp=temp->next;
        }
    }
    Customer* findCustomer(std::string name){
        CustomerNode * temp = head;
        while(temp){
            if(temp->customerData.getName()==name) return &(temp->customerData);
            temp=temp->next;
        }
        return NULL;
    }
};






