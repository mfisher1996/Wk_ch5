/*Part 1 02/10/2018

A. Lecture - Guided Practice
	1. Power Point Ch6_B Part 1
		a. Shcematic of a linked list
			head -> [info]link->[info]link->[info]link-v
	*2. Exercises pg 344
		1 a-e, 2 a-d, 3 a-e
		1 a. In a linked list, the order of the elements is determined by the order in which the nodes are created.
		  	ANSWER:T
		  b. In a lnked list, memory allocated for the nodes is sequential.
			ANSWER:F
		  c. A single lined list can be traversed in either direction.
			ANSWER:F
		  d.In a linked list, nodes are always inserted either at the beginning or the end because a linked list is not a random access data structure.
			ANSWER:F
		  e.The head pointer of a linked list cannot be used to traverse the list.
			ANSWER:T
B. Lab 
	*1. Skills review: 
		Write the code for likned list, not ADT. Write a program to 
	create a linked list with 20, 30, 40, 60. Print the node. Add 55, 65
	and 15 to the list while maintaning sequential order. Print the node.
	Delete the first, then last, then middle node. then print the list and
	the node.
{
*/
#include <iostream>
#include "Wk_ch5.hpp"

using namespace std;

int intCheck(int chk, int lowL, int upL);
void clearBuff();

int main(){
    Linked<int> list;
    int num, len;
    cout << "Please input 4 numbers for the list.\n";
    cin >> num;
    num=intCheck(num, 0, 100);
    list.insert(num);
    cin >> num;
    num=intCheck(num,0,100);
    list.insert(num);
    cin >> num;
    num=intCheck(num,0,100);
    list.insert(num);
    cin >> num;
    num=intCheck(num,0,100);
    list.insert(num);
    list.print();
    cout << "Please input 3 more numbers for the list.\n";
    cin >> num;
    num=intCheck(num,0,100);
    list.insert(num);
    cin >> num;
    num=intCheck(num,0,100);
    list.insert(num);
    cin >> num;
    num=intCheck(num,0,100);
    list.insert(num);
    list.print();
    len = list.getSize();
    list.remove(1);
    list.remove(len);
    list.remove(len/2);
    cout << "After deleting the first, last and middle elements,\n";
    list.print();
    return 0;
}

int intCheck(int chk, int lowL, int upL){
    while(!cin||chk<lowL||chk>upL){
        clearBuff();
        cout<<"The number you inputed is invalid.\nPlease input a number above "<<lowL<<" but below "<<upL<<".\n";
        cin>>chk;
        clearBuff();
    }
    
    return chk;
}

void clearBuff(){
    cin.clear();
    cin.ignore(INT_MAX, '\n');
}
/*
}


Part 2 04/10/2018

A. Lecture - Guided Practice
	1. Power Point Ch6_B Part 2
	*2. Students complete
		a. 4 a-i
		b. 5 a-g
		c. 6
		d. 7 a-b
	3. Video on linked lists
	
B. Lab
	1. Skills Review:
		Students write???
	2. Independent Practice
		a. UML Diagram Pg 285

*/
