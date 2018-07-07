//
//  Customer.hpp
//  Fence CRM
//
//  Created by Tanner Orndorff on 11/13/17.
//  Copyright © 2017 Monocle Heads. All rights reserved.
//

#ifndef Customer_hpp
#define Customer_hpp

#include "Employee.hpp"

using namespace std;

class Customer
{
public:
    //properties
    int id;
    string fname;
    string lname;
    string address;
    string email;
    int phone_num;
    string notes;
    List<int>* estimate_ids;
    //constructor
    Customer();
    ~Customer();
    Customer(string f,string l,string a,string e,int,int pn, string n);
    //getters and setters
    void AddEstimateID();
    void RemoveEstimateID(int id);
    int FetchEstimateId(int id);
    void print();
    
    
    
};
#endif /* Customer_hpp */
