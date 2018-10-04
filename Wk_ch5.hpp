#include <iostream>

using namespace std;

template<class T>

class Linked{
    
private:
    int size;
    struct node{
        T info;
        node * link;
    };
    node * head, * cur;
    
public:
    Linked();
    ~Linked();
    void insert(T item);
    void insert(T item, int i);
    void remove(int i);
    void print();
    int getSize()const{return size;};
    T getInfo(int i);
};
// Constructor: initializes head and assigns nullptr to the pointer in head.
template<class T>
Linked<T>::Linked(){
    head = new node;
    head->link = nullptr;
    size = 0;
}
// Deconstructor: deletes each of the pointers in the linked list.
template<class T>
Linked<T>::~Linked(){
    while(head != NULL){
        cur = head;
        head = head -> link;
        delete cur;
    }

}
// insert(T): creates a new node at end of list and adds item passed to that node.
// Should be passed an item.
template<class T>
void Linked<T>::insert(T item){
    node * prev;
    cur = head;
    while(cur!=NULL){
        prev=cur;
        cur = cur->link;
    }
    if(cur!=head){
        size++;
        cur = new node;
        cur -> info =  item;
        cur -> link = nullptr;
        prev->link=cur;
    }else{
        cur = new node;
        head->link = cur;
        cur->info = item;
        size++;
        cur->link = nullptr;
    }
}
// insert(T, int): creates a new node and inserts it at the position indicated by i with
// item held in the node's info.
// is pass the type T and an int.
template<class T>
void Linked<T>::insert(T item, int i){
    if(i<=size&&i>0){
        cur = head;
        for(int j=0; j<i;j++)
            cur = cur->link;
        node * a,*b=cur->link;
        a = new node;
        a->link=b;
        cur->link=a;
    }else{
        cout << i <<" is outside the bounds of the list. Inserting " << item << " at the end of the list\n";
        cur = head;
        while(cur!=NULL){
            cur = cur->link;
        }
        size++;
        cur = new node;
        cur -> info =  item;
        cur -> link = nullptr;	
    }
}
// remove(int): deletes the node at position i.
// passed the integer location of the value to be deleted.
template<class T>
void Linked<T>::remove(int i){
    if(i ==0){
        cur = head->link;
        delete head;
        head = cur;
    }else if(i==size){
        cur = head;
        while(cur->link->link!=NULL)
            cur = cur->link;
        node * a = cur -> link;
        delete a;
        cur->link = nullptr;
    }else{
        node * a;
        cur=head;
        for(int j=0;j<i-1;j++)
            cur=cur->link;
        a = cur->link;
        cur->link=a->link;
        delete a;
    }
}
//print(): prints the values stored in the list.
template<class T>
void Linked<T>::print(){
    cout << "The list holds: ";
    cur = head->link;
    while(cur != NULL){
        cout << cur->info << " ";
        cur = cur->link;
    }
    cout << endl;
}
//getInfo(int i): returns the info held at position i.
template<class T>
T Linked<T>::getInfo(int i){
    if(i<=size&&i>0){
        cur = head;
        for(int j=0; j<i;j++)
            cur = cur->link;
        return cur->info;
    }else{
        cout << i <<" is outside the bounds of the list. Returning NULL.\n";
        return 0;
    }
}
