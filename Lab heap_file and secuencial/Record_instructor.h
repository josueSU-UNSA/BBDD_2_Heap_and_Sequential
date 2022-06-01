//Exm: 1 | "Josue" | "Computer Science"| 19|76698040|76698040
using namespace std;
#include<iostream>
#include<assert.h>
class Record_instructor{
    private:
        char ID[6];
        char name[21];
        char dept_name[21];
        double salary;
    public:
        //Constructor
        Record_instructor();
        Record_instructor(string,string,string,double);
        //Method to get the number of bytes in the record
        unsigned int size_record()const;
        
        // get method's
        string get_ID()const;
        string get_name()const;
        string get_dept_name()const;
        double get_salary()const;
        string get_primary_key()const;
        // set method's
        void set_ID(string);
        void set_name(string);
        void set_dept_name(string);
        void set_salary(double);
        // friend ostream& operator <<(ostream &o,const Record_instructor&p){
        //     o<<p.get_ID()<<" "<<p.get_name()<<" "<<p.get_dept_name()<<" "<<p.get_salary();
        //     return o;
        // }
        string print();
        

};
Record_instructor::Record_instructor(){
    //this condition define the all variables as not nulls and 
    //inside the limis of length
    // char ID[6];
    //     char name[21];
    //     char dept_name[21];
    //     float salary;
    // string ID,string name ,string dept_name,double salary
    for(int i=0;i<6;i++)this->ID[i]=' ';
    for(int i=0;i<21;i++)this->name[i]=' ';
    for(int i=0;i<21;i++)this->dept_name[i]=' ';
    this->salary=0;
    
    // this->ID="";
    // this->name="";
    // this->dept_name=" ";
    // this->salary=0;
    
}
Record_instructor::Record_instructor(string ID,string name ,string dept_name,double salary){
    //this condition define the all variables as not nulls and 
    //inside the limis of length
    // char ID[6];
    //     char name[21];
    //     char dept_name[21];
    //     float salary;
    if(ID.size()>0 && ID.size()<=5 && name.size()>0 && name.size()<=20 && dept_name.size()>0 && dept_name.size()<=20 && salary>=0){
        for(int i=0;i<ID.size();i++)this->ID[i]=ID[i];
        for(int i=0;i<name.size();i++)this->name[i]=name[i];
        for(int i=0;i<dept_name.size();i++)this->dept_name[i]=dept_name[i];
        this->salary=salary;
    }
    else{
        cout<<"error input ";
        assert(0);
    }
    
}
unsigned int Record_instructor::size_record()const{
    //We substract one from the STRING's length
    //because the calculation is char by char
    //and in all string variables there's
    //a extra character,the final string character:'\0'
    //we won't use this 
    
    return (sizeof(this->ID)-1)+(sizeof(this->name)-1)+(sizeof(this->dept_name)-1)+sizeof(salary);
}


// get method's
string Record_instructor::get_ID()const{
    return this->ID; 
}
string Record_instructor::get_name()const{
    return this->name;
}
string Record_instructor::get_dept_name()const{
    return this->dept_name;
}
double Record_instructor::get_salary()const{
    return this->salary;
}
//Check this method
string Record_instructor::get_primary_key()const{
    string aux=this->get_ID();
    return aux;
}
// set method's
void Record_instructor::set_ID(string ID){
    if(ID.size()>0 && ID.size()<=5){
        for(int i=0;i<ID.size();i++)this->ID[i]=ID[i];
    }
    else assert(0);
}

void Record_instructor::set_name(string name){
    if(name.size()>0 && name.size()<=20){
        for(int i=0;i<name.size();i++)this->name[i]=name[i];
    }
    else assert(0);
}

void Record_instructor::set_dept_name(string dept_name){
    if(dept_name.size()>0 && dept_name.size()<=20){
        
        for(int i=0;i<dept_name.size();i++)this->dept_name[i]=dept_name[i];
        this->salary=salary;
    }
}

void Record_instructor::set_salary(double salary){
    if(salary>=0){
        this->salary=salary;
    }
}

string Record_instructor::print(){
    string aux=this->ID;
    aux+=" ";
    aux+=this->name;
    aux+=" ";
    aux+=this->dept_name;
    aux+=" ";
    aux+=this->salary;
    return aux;
}
