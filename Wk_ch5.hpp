#include <iostream>
#include <cassert>
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

/*
2. Extend the class linkedListType by adding the following operations:
a. Find and delete the node with the smallest info in the list. (Delete only
the first occurrence and traverse the list only once.)
b. Find and delete all occurrences of a given info from the list. (Traverse
the list only once.) Add these as abstract functions in the class
linkedListType and provide the definitions of these functions in the
class unorderedLinkedList. Also write a program to test these
functions.
*/

template <class Type>
struct nodeType
{
Type info;
nodeType<Type> *link;
};

template <class Type>
class linkedListIterator
{
public:
	linkedListIterator();
	//Default constructor
	//Postcondition: current = NULL;
	linkedListIterator(nodeType<Type> *ptr);
	//Constructor with a parameter.
	//Postcondition: current = ptr;
	Type operator*();
	//Function to overload the dereferencing operator *.
	//Postcondition: Returns the info contained in the node.
	linkedListIterator<Type> operator++();
	//Overload the preincrement operator.
	//Postcondition: The iterator is advanced to the next node.
	bool operator==(const linkedListIterator<Type>& right) const;
	//Overload the equality operator.
	//Postcondition: Returns true if this iterator is equal to
	// the iterator specified by right, otherwise it returns
	// false.
	bool operator!=(const linkedListIterator<Type>& right) const;
	//Overload the not equal to operator.
	//Postcondition: Returns true if this iterator is not equal to
	// the iterator specified by right, otherwise it returns
	// false.
private:
	nodeType<Type> *current; //pointer to point to the current
	//node in the linked list
};

template <class Type>
linkedListIterator<Type>::linkedListIterator()
{
	current = NULL;
}

template <class Type>
linkedListIterator<Type>::
linkedListIterator(nodeType<Type> *ptr)
{
	current = ptr;
}

template <class Type>
Type linkedListIterator<Type>::operator*()
{
	return current->info;
}

template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++()
{
	current = current->link;
	return *this;
}

template <class Type>
bool linkedListIterator<Type>::operator==
(const linkedListIterator<Type>& right) const
{
	return (current == right.current);
}

template <class Type>
bool linkedListIterator<Type>::operator!=
(const linkedListIterator<Type>& right) const
{
	return (current != right.current);
}

template <class Type>
class linkedListType
{
public:
	const linkedListType<Type>& operator= (const linkedListType<Type>&);
	//Overload the assignment operator.
	void initializeList();
	//Initialize the list to an empty state.
	//Postcondition: first = NULL, last = NULL, count = 0;
	bool isEmptyList() const;
	//Function to determine whether the list is empty.
	//Postcondition: Returns true if the list is empty, otherwise
	// it returns false.
	void print() const;
	//Function to output the data contained in each node.
	//Postcondition: none
	int length() const;
	//Function to return the number of nodes in the list.
	//Postcondition: The value of count is returned.
	void destroyList();
	//Function to delete all the nodes from the list.
	//Postcondition: first = NULL, last = NULL, count = 0;
	Type front() const;
	//Function to return the first element of the list.
	//Precondition: The list must exist and must not be empty.
	//Postcondition: If the list is empty, the program terminates;
	// otherwise, the first element of the list is returned.
	Type back() const;
	//Function to return the last element of the list.
	//Precondition: The list must exist and must not be empty.
	//Postcondition: If the list is empty, the program
	// terminates; otherwise, the last
	// element of the list is returned.
	virtual bool search(const Type& searchItem) const = 0;
	//Function to determine whether searchItem is in the list.
	//Postcondition: Returns true if searchItem is in the list,
	// otherwise the value false is returned.
	virtual void insertFirst(const Type& newItem) = 0;
	//Function to insert newItem at the beginning of the list.
	//Postcondition: first points to the new list, newItem is
	// inserted at the beginning of the list, last points to
	// the last node in the list, and count is incremented by
	// 1.
	virtual void insertLast(const Type& newItem) = 0;
	//Function to insert newItem at the end of the list.
	//Postcondition: first points to the new list, newItem is
	// inserted at the end of the list, last points to the
	// last node in the list, and count is incremented by 1.
	virtual void deleteNode(const Type& deleteItem) = 0;
	//Function to delete deleteItem from the list.
	//Postcondition: If found, the node containing deleteItem is
	// deleted from the list. first points to the first node,
	// last points to the last node of the updated list, and
	// count is decremented by 1.
	virtual void deleteMin() = 0;
	virtual void deleteIn(Type& deleteItem) = 0;
	linkedListIterator<Type> begin();
	//Function to return an iterator at the beginning of the
	//linked list.
	//Postcondition: Returns an iterator such that current is set
	// to first.
	linkedListIterator<Type> end();
	//Function to return an iterator one element past the
	//last element of the linked list.
	//Postcondition: Returns an iterator such that current is set
	// to NULL.
	linkedListType();
	//default constructor
	//Initializes the list to an empty state.
	//Postcondition: first = NULL, last = NULL, count = 0;
	linkedListType(const linkedListType<Type>& otherList);
	//copy constructor
	~linkedListType();
	//destructor
	//Deletes all the nodes from the list.
	//Postcondition: The list object is destroyed.
protected:
	int count; //variable to store the number of list elements
	//
	nodeType<Type> *first; //pointer to the first node of the list
	nodeType<Type> *last; //pointer to the last node of the list
private:
	void copyList(const linkedListType<Type>& otherList);
	//Function to make a copy of otherList.
	//Postcondition: A copy of otherList is created and assigned
	// to this list.
};

template <class Type>
void linkedListType<Type>::copyList
(const linkedListType<Type>& otherList)
{
	nodeType<Type> *newNode; //pointer to create a node
	nodeType<Type> *current; //pointer to traverse the list
	if (first != NULL) //if the list is nonempty, make it empty
		destroyList();
	if (otherList.first == NULL) //otherList is empty
	{
		first = NULL;
		last = NULL;
		count = 0;
	}
	else
	{
		current = otherList.first; //current points to the
		//list to be copied
		count = otherList.count;
		//copy the first node
		first = new nodeType<Type>; //create the node
		first->info = current->info; //copy the info
		first->link = NULL; //set the link field of the node to NULL
		last = first; //make last point to the first node
		current = current->link; //make current point to the next
		// node
		//copy the remaining list
		while (current != NULL)
		{
			newNode = new nodeType<Type>; //create a node
			newNode->info = current->info; //copy the info
			newNode->link = NULL; //set the link of newNode to NULL
			last->link = newNode; //attach newNode after last
			last = newNode; //make last point to the actual last
			//node
			current = current->link; //make current point to the
			//next node
		}//end while
	}//end else
}//end copyList

template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin()
{
	linkedListIterator<Type> temp(first);
	return temp;
}

template <class Type>
linkedListIterator<Type> linkedListType<Type>::end()
{
	linkedListIterator<Type> temp(NULL);
	return temp;
}

template <class Type>
Type linkedListType<Type>::back() const
{
	assert(last != NULL);
	return last->info; //return the info of the last node
}//end back

template <class Type>
Type linkedListType<Type>::front() const
{
	assert(first != NULL);
	return first->info; //return the info of the first node
}//end front

template <class Type>
int linkedListType<Type>::length() const
{
	return count;
}

template <class Type>
void linkedListType<Type>::print() const
{
	nodeType<Type> *current; //pointer to traverse the list
	current = first; //set current point to the first node
	while (current != NULL) //while more data to print
	{
		cout << current->info << " ";
		current = current->link;
	}
}//end print

template <class Type>
void linkedListType<Type>::initializeList()
{
	destroyList(); //if the list has any nodes, delete them
}

template <class Type>
void linkedListType<Type>::destroyList()
{
	nodeType<Type> *temp; //pointer to deallocate the memory
	//occupied by the node
	while (first != NULL) //while there are nodes in the list
	{
		temp = first; //set temp to the current node
		first = first->link; //advance first to the next node
		delete temp; //deallocate the memory occupied by temp
	}
	last = NULL; //initialize last to NULL; first has already
	//been set to NULL by the while loop
	count = 0;
}

template <class Type>
linkedListType<Type>::linkedListType() //default constructor
{
	first = NULL;
	last = NULL;
	count = 0;
}

template <class Type>
bool linkedListType<Type>::isEmptyList() const
{
	return (first == NULL);
}

template <class Type>
linkedListType<Type>::~linkedListType() //destructor
{
	destroyList();
}

template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=
(const linkedListType<Type>& otherList)
{
	if (this != &otherList) //avoid self-copy
	{
		copyList(otherList);
	}//end else
	return *this;
}



template <class Type>
class unorderedLinkedList:public linkedListType<Type>
{
public:
	bool search(const Type& searchItem) const;
	//Function to determine whether searchItem is in the list.
	//Postcondition: Returns true if searchItem is in the list,
	// otherwise the value false is returned.
	void insertFirst(const Type& newItem);
	//Function to insert newItem at the beginning of the list.
	//Postcondition: first points to the new list, newItem is
	// inserted at the beginning of the list, last points to
	// the last node, and count is incremented by 1.
	//
	void insertLast(const Type& newItem);
	//Function to insert newItem at the end of the list.
	//Postcondition: first points to the new list, newItem is
	// inserted at the end of the list, last points to the
	// last node, and count is incremented by 1.
	void deleteNode(const Type& deleteItem);
	//Function to delete deleteItem from the list.
	//Postcondition: If found, the node containing deleteItem
	// is deleted from the list. first points to the first
	// node, last points to the last node of the updated
	// list, and count is decremented by 1.
	void deleteMin();
	void deleteIn(Type& deleteItem);
};

template <class Type>
bool unorderedLinkedList<Type>::
search(const Type& searchItem) const
{
	nodeType<Type> *current; //pointer to traverse the list
	bool found = false;
	current = linkedListType<Type>::first; //set current to point to the first
					 //node in the list
	while (current != NULL && !found)	 //search the list
		if (current->info == searchItem) //searchItem is found
			found = true;
		else
			current = current->link; //make current point to
									 //the next node
	return found;
}//end search

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
	nodeType<Type> *newNode; //pointer to create the new node
	newNode = new nodeType<Type>; //create the new node
	newNode->info = newItem; //store the new item in the node
	newNode->link = linkedListType<Type>::first; //insert newNode before first
	linkedListType<Type>::first = newNode; //make first point to the actual first node
	linkedListType<Type>::count++; //increment count
	if (linkedListType<Type>::last == NULL) //if the list was empty, newNode is also
		//the last node in the list
		linkedListType<Type>::last = newNode;
}//end insertFirst

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
	nodeType<Type> *newNode; //pointer to create the new node
	newNode = new nodeType<Type>; //create the new node
	newNode->info = newItem; //store the new item in the node
	newNode->link = NULL; //set the link field of newNode to NULL
	if (linkedListType<Type>::first == NULL) //if the list is empty, newNode is
	//both the first and last node
	{
		linkedListType<Type>::first = newNode;
		linkedListType<Type>::last = newNode;
		linkedListType<Type>::count++; //increment count
	}
	else //the list is not empty, insert newNode after last
	{
		linkedListType<Type>::last->link = newNode; //insert newNode after last
		linkedListType<Type>::last = newNode; //make last point to the actual
		//last node in the list
		linkedListType<Type>::count++; //increment count
	}
}//end insertLast

template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
	nodeType<Type> *current; //pointer to traverse the list
	nodeType<Type> *trailCurrent; //pointer just before current
	bool found;
	if (linkedListType<Type>::first == NULL) //Case 1; the list is empty.
		cout << "Cannot delete from an empty list." << endl;
	else
	{
		if (linkedListType<Type>::first->info == deleteItem) //Case 2
		{
		current = linkedListType<Type>::first;
		linkedListType<Type>::first = linkedListType<Type>::first->link;
		linkedListType<Type>::count--;
		if (linkedListType<Type>::first == NULL) //the list has only one node
			linkedListType<Type>::last = NULL;
		delete current;
		}
		else //search the list for the node with the given info
		{
			found = false;
			trailCurrent = linkedListType<Type>::first; //set trailCurrent to point
			//to the first node
			current = linkedListType<Type>::first->link; //set current to point to
			//the second node
			while (current != NULL && !found)
			{
				if (current->info != deleteItem)
				{
					trailCurrent = current;
					current = current-> link;
				}
				else
					found = true;
			}//end while
			if (found) //Case 3; if found, delete the node
			{
				trailCurrent->link = current->link;
				linkedListType<Type>::count--;
				if (linkedListType<Type>::last == current) //node to be deleted was the
									//last node
					linkedListType<Type>::last = trailCurrent; //update the value of last
				delete current; //delete the node from the list
			}
			else
				cout << "The item to be deleted is not in " << "the list." << endl;
		}//end else
	}//end else
}//end deleteNode

template <class Type>
void unorderedLinkedList<Type>::deleteIn(Type& deleteItem)	
{
	nodeType<Type> *current; //pointer to traverse the list
	nodeType<Type> *trailCurrent; //pointer just before current

	if (linkedListType<Type>::first == NULL) //Case 1; the list is empty.
		cout << "Cannot delete from an empty list." << endl;
	else
	{
		while (linkedListType<Type>::first->info == deleteItem) //Case 2
		{
			current = linkedListType<Type>::first;
			linkedListType<Type>::first = linkedListType<Type>::first->link;
			linkedListType<Type>::count--;
			if (linkedListType<Type>::first == NULL) //the list has only one node
				linkedListType<Type>::last = NULL;
			delete current;
			
		}//end while
		trailCurrent = linkedListType<Type>::first; //set trailCurrent to point to the first node
		current = linkedListType<Type>::first->link; //set current to point to the second node
		while (current != NULL)
		{
			if (current->info != deleteItem)
			{
				trailCurrent = current;
				current = current-> link;
			}else{
				trailCurrent->link = current->link;
				linkedListType<Type>::count--;
				if (linkedListType<Type>::last == current) //node to be deleted was the last node
					linkedListType<Type>::last = trailCurrent; //update the value of last
				delete current; //delete the node from the list
				linkedListType<Type>::count--;
				current = trailCurrent->link;
			}
		}//end while
	}//end else
}//end deleteIn

template <class Type>
void unorderedLinkedList<Type>::deleteMin(){
	nodeType<Type> *current, *trailCurrent, *min, *trailMin=nullptr;
		
	if(!linkedListType<Type>::isEmptyList()){
		trailCurrent = linkedListType<Type>::first;
		current = trailCurrent->link;
		min = linkedListType<Type>::first;
		while(current != NULL){
			if(current->info < min->info){
				min = current;
				trailMin=trailCurrent;
				}
			trailCurrent=current;
			current=current->link;
			}//end while
		if(trailMin==NULL){ // Then min == first.
			linkedListType<Type>::first=linkedListType<Type>::first->link;
			delete min;
			linkedListType<Type>::count--;
		}else if(linkedListType<Type>::last == min){
			linkedListType<Type>::last = trailMin;
			delete min;
			linkedListType<Type>::count--;
		}else{
			trailMin->link = min->link;
			delete min;
			linkedListType<Type>::count--;
		}
	}
	else
		cout << "The list is empty. The smallest item cannot be deleted.\n";
}
/*
4. (Dividing a linked list into two sublists of almost equal sizes)

a. Add the operation divideMid to the class linkedListType as follows:
void divideMid(linkedListType<Type> &sublist);
//This operation divides the given list into two sublists
//of (almost) equal sizes.
//Postcondition: first points to the first node and last
// points to the last node of the first sublist.
// sublist.first points to the first node and sublist.last
// points to the last node of the second sublist.
Consider the following statements:
unorderedLinkedList<int> myList;
unorderedLinkedList<int> subList;
Suppose myList points to the list with elements 34 65 27 89 12 (in this
order). The statement:
myList.divideMid(subList);
divides myList into two sublists: myList points to the list with the
elements 34 65 27, and subList points to the sublist with the elements
89 12.

b. Write the definition of the function template to implement the operation
divideMid. Also write a program to test your function.
*/
