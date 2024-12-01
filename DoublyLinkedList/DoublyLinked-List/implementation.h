#pragma once 
#include <iostream> 
#include <ctime> 
#include <cstdlib> 
#include <random> 
#include <set> 
#include <vector>
#include <string>
using namespace std;

class Node 
{

public:
    double data; 
    int id; 
    string name;

    Node* next; 

    Node* prev;

    Node(double info = 0,const string& n= "", int i = 0, Node * nt = nullptr, Node * pt = nullptr) 
        :  data(info),name(n) ,id(i),next(nt), prev(pt) {}

};

class mystructure 
{
    using Nodepointer = Node*;

    Nodepointer head, tail; 

public:
    mystructure() : head(0), tail(0) {}
    mystructure(const mystructure& orig)
    {
        head = nullptr;
        tail = nullptr;

        if (orig.head != nullptr) 
        {
            head = new Node(orig.head->data, orig.head->name,orig.head->id );

            tail = head;
            Nodepointer currorig = orig.head->next;

            while (currorig != nullptr) 
            {

                Nodepointer newnode = new Node(currorig->data,currorig->name, currorig->id);

                tail->next = newnode;

                newnode->prev = tail;

                tail = newnode;

                currorig = currorig->next;
            }

        }

    }
    ~mystructure() 
    {

        while (head != nullptr) 
        { 
            Nodepointer curr = head;

            head = head->next;

            if (head != nullptr)
            {

                head->prev = nullptr;
            }
            delete curr;

        }
        tail = nullptr; 
    }

    void delete_Node(int index) 
    {
        if (head == nullptr) 
        {
            cout << "it is empty list" << endl;
            return;

        }
        if (index == 0) 
        {

            Node* temp = head;

            head = head->next; 
            if (head != nullptr) 
            { 

                head->prev = nullptr;

            }
            delete temp; 

            return;

        }
        Node* current = head;

        int current_index = 0;
        while (current != nullptr && current_index < index)
        {

            current = current->next;

            current_index++;

        }

        if (current == nullptr) 
        {
            return;
        }      
        if (current->prev != nullptr)
        {
            current->prev->next = current->next;
        }
        if (current->next != nullptr) 
        {
            current->next->prev = current->prev; 
        }
        delete current;
    }

    

    void push(double dat, int indexid,const string& name) 
    {
        Node* current = head;
        Nodepointer previous = nullptr;
        while (current != nullptr) 
        {

            if (current->data == dat) 
            { 

                delete_by_the_same_rating(dat);

                if (previous == nullptr)
                { 
                    head = current->next;
                }
                else 
                {
                    previous->next = current->next;
                }
                delete current;
                break;

            }
            previous = current;
            current = current->next;
        }
        if (dat > 0.75) 
        {

            Node* new_node = new Node(dat,name, indexid);
            new_node->next = head; 

            new_node->prev = nullptr; 
            if (head != nullptr)
            {
                head->prev = new_node;
            }
            head = new_node;
        }
        else if (dat < 0.75) 
        {
            Node* new_node1 = new Node(dat,name, indexid);

            tail = head; 

            new_node1->next = nullptr;

            if (head == nullptr) 
            {

                new_node1->prev = nullptr;

                head = new_node1;
                return;
            }
            while (tail->next != nullptr)
            {
                tail = tail->next;
            }
            tail->next = new_node1;
            new_node1->prev = tail; 
        }
    }
   
    void display(ostream& out) const 
    {
        Nodepointer ptr = head;
        int i = 1;   
        while (ptr != nullptr) 
        {       
            out << i << " " << ptr->name<< " " << ptr->data << " " << "orders:" << ptr->id << " " << endl;
            ptr = ptr->next;
            i++;
       }
    }
   
    set<int> uniquenumbers() 
    {
        default_random_engine dre(time(NULL));
        uniform_int_distribution<int> dis1(1000000000, 1100000000);
        set<int> unique;
        for (int i = 0; i < 10; i++)
        {
            int random_number;
            do 
            {
                random_number = dis1(dre);
            } while (unique.count(random_number) > 0);
            unique.insert(random_number);
        }
        return unique;
    }
   
    void delete_Nodes_from_front() 
    {
        if (head == nullptr) 
        { 
            cout << "The list is empty" << endl;
            return;
        }
        Node* temp = head;  
        head = head->next; 
        if (head != nullptr) 
        {
            head->prev = nullptr;
        }
        delete temp;
    }
    
    void delete_by_the_same_rating(int val)
    {
        if (head == nullptr) 
        {
            cout << "The list is empty" << endl;
            return;
        }
        Nodepointer temp = head;
        while (temp != nullptr && temp->data != val) 
        {
            temp = temp->next;
        }
        if (temp != nullptr) 
        { 
            if (temp == head && temp->data == val) 
            {
                delete_Nodes_from_front();
            }
            else {
                Nodepointer temp1 = temp;  
                Nodepointer temp2 = temp->next;
                temp = temp->prev;
                while (temp2 == nullptr && head->next->data) 
                {
                    delete temp1;
                    temp1 = temp2; 
                    temp2 = temp2->next;
                }
                if (temp2 != nullptr) 
                {
                    delete temp1; 
                    temp->next = temp2;  
                    if (temp2 != nullptr)
                    {
                        temp2->prev = temp;
                    }
                }
            }

        }

    }

};