//
//  List.hpp
//  Fence CRM
//
//  Created by Tanner Orndorff on 12/27/17.
//  Copyright © 2017 Monocle Heads. All rights reserved.
//
// This class is meant to hold lists of objects (customers, invoices, estimates, fences) etc. When initiated, the type of object it holds can be accessed. It will have functions that will add, remove, and find said objects and retrieve their data.
// This list holds objects that have an integer id.

#ifndef List_hpp
#define List_hpp

#include "Node.hpp"
#include <stdio.h>
using namespace std;

template<typename T>
class List
{
    //constructor
public:
    bool is_empty();
    Node<T>* front;
    int count = 0;
    
    List();
    //deconstructor
    ~List();
    //add node
    void add(T*);
    //remove node
    void remove(int);
    //fetch node
    T* fetch(int);
    //print list
    void print();
    
    
};

//constructor****
//set all member variables to null
template<typename T>
List<T>::List()
{
    front = nullptr;
}
//destructor
template<typename T>
List<T>::~List<T>()
{
    if(front != nullptr)
        delete front;
}
//add node*****
//takes in object and adds it to the List
template<typename T>
void List<T>::add(T* data)
{
    //create new node that holds passed in data
    Node<T>* temp = new Node<T>(data);
    //set next to the front of the list
    temp->next = front;
    //set front to the new node
    front = temp;
    //delete old new node pointer
    temp = nullptr;
    count++;
}
//remove node**********
//finds node with a given Id and removes it from the list
template<typename T>
void List<T>::remove(int id)
{
    //find node
    Node<T>* temp = front;
    if(temp->object->id == id)
    {
        front = temp->next;
        //detach and delete
        temp->next = nullptr;
        delete temp;
        count--;
    }
    else
    {
        //as long as the next object's id does not equal the id we are looking for and the next pointer isnt null iterate through
        while (temp->next->object->id != id && temp->next != nullptr)
        {
            temp = temp->next;
        }
        if (temp != nullptr)
        {
            //skip over object to be deleted
            Node<T>* match = temp->next;
            temp->next = temp->next->next;
            //delete object
            match->next = nullptr;
            delete match;
            count--;
        }
    }
}
//fetch function
//returns the object with the corresponding ID
//returns nullptr if it isnt found
//print function*******
template<typename T>
T* List<T>::fetch(int id)
{
    //iterate and find the object
    Node<T>* temp = front;
    if(temp->object->id == id)
    {
        return temp->object;
    }
    else
    {
        while(temp->next->object->id != id && temp->next != nullptr)
        {
            temp = temp->next;
        }
        if(temp !=nullptr)
        {
            return temp->next->object;
        }
        else
            return nullptr;
    }
}
//print function
//calls the print functio of the object
template<typename T>
void List<T>::print()
{
    Node<T>* temp = front;
    //exit when the list is empty
    while(temp != nullptr)
    {
        //print current node data
        temp->object->print();
        cout << endl;
        temp = temp->next;
    }
}

//says if the list is empty or not
template<typename T>
bool List<T>::is_empty()
{
    if(front == nullptr)
        return true;
    else
        return false;
}


#endif /* List_hpp */


