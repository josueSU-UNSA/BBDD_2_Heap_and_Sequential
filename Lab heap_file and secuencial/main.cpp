#include<iostream>
#include<string.h>
#include"Record_instructor.h"
#include<assert.h>
using namespace std;


template<class T>
class Heap_file{
    private:
        int m_capicity_block;

};

//this class will be template 
//because the table's structure 
//would may be other 
template<class T>
class Node_sequential_file{
    public:
        string m_key;
        T m_value;
        unsigned int m_number_bytes;
        Node_sequential_file<T>*m_pNext;
    public:
        Node_sequential_file(string,T,unsigned int);
        Node_sequential_file(Record_instructor);

};



template<class T>
Node_sequential_file<T>::Node_sequential_file(string  key, T value,unsigned int number_bytes){
    this->m_value=value;
    this->m_key=key;
    this->m_number_bytes=number_bytes;
    this->m_pNext=0;
}
template<class T>
Node_sequential_file<T>::Node_sequential_file(Record_instructor value){
    this->m_value=value;
    this->m_key=value.get_primary_key();
    this->m_number_bytes=value.size_record();
    this->m_pNext=0;
}
// template<>
// class Node_sequential_file<Record_instructor>{
//     public:
//         string m_key;
//         Record_instructor m_value;
//         unsigned int m_number_bytes;
//         Node_sequential_file<Record_instructor>*m_pNext;
//     public:
//         Node_sequential_file(Record_instructor value){
//             this->m_value=value;
//             this->m_key=value.get_primary_key();
//             this->m_number_bytes=value.size_record();
//             this->m_pNext=0;
//         }
// };
template<class T>
class Sequential_file{
    private:
        int m_capicity_block;
    public:
        Node_sequential_file<T>*m_pHead;
        unsigned int  m_size;
        Sequential_file(int);
        
        bool insert(unsigned int pos,T record);
        // bool insert(unsigned int pos,Record_instructor record);
        
        bool insert_overflow_block();
};
template<class T>
Sequential_file<T>::Sequential_file(int capicity_block){
    this->m_capicity_block=capicity_block;
    this->m_pHead=0;
    this->m_size=this->m_size_bytes_current=0;
}

template<class T>
bool Sequential_file<T>::insert(unsigned int pos,T record){
    Node_sequential_file<T>*record_input_new=new Node_sequential_file<T>(record);
    
    if(this->m_size*record_input_new->m_number_bytes+record_input_new->m_number_bytes<this->m_capicity_block){ 
        return true;
    }
}

// template<class T>
// bool Sequential_file<T>::insert(unsigned int pos,Record_instructor record){
//     // string ID,string name ,string dept_name,double salary
//     Node_sequential_file<Record_instructor>*record_input_new=new Node_sequential_file<Record_instructor>(record.get_ID(),record.get_name(),record.get_dept_name(),record.salary()) ;
//     //This condition is used to check if  we can  insert the record in the structure
//     //the paarameters are the size of the record and the block's capicity 
//     if(this->m_size*record_input_new->m_number_bytes +record_input_new->m_number_bytes < this->m_capicity_block){ 
//         if(!pos){
//             record_input_new->m_pNext=this->m_pHead;
//             this->m_pHead=record_input_new;
//             this->m_size++;
//         }
//         if(pos>this->m_size || pos<0){
//             cout<<"incorrrect position to insert"<<endl;
//             return false;
//         }
//     }
//     else{
//         cout<<"the structure is full this record is going to store in the overflow_block"<<endl;
//         return insert_overflow_block();//esto retorna falso
//     }
// }
template<class T>
bool Sequential_file<T>::insert_overflow_block(){
    return 0;
}
// template<class T>

string aux(){
    char aux_2[3]="ab";
    return aux_2;
}
int main(){
    // string ID,string name,string dept_name,float salary
    Record_instructor t("211","2020","2020",2000);
    // cout<<t.size_record();
    // Remember this
    // RIGHT=LEFT
    // int a =13
    // RIGHT VALUE=LEFT VALUE
    // Rvalue=Lvalue
    // string name;

    // cout<<name.size();
    // cout<<sizeof(41233.544112)<<endl;//Rvalue's bytes
    
    // char t1[11] ;
    
    // cout<<t1<<endl;
    // cout<<sizeof(t1)/sizeof(t1[0]);
    
    // (*t1==*t2)?cout<<"TRUE"<<endl:cout<<"FALSE"<<endl;
    
    
    return 0;
}