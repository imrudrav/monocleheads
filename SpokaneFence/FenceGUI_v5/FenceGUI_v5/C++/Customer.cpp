//
//  Customer.cpp
//  Fence CRM
//
//  Created by Tanner Orndorff on 11/13/17.
//  Copyright © 2017 Monocle Heads. All rights reserved.
//

#include "Customer.hpp"

//default constructor
Customer::Customer()
{
    fname = " ";
    lname = " ";
    address = " ";
    email = " ";
    id = 0;
    phone_num = 0;
    notes = " ";
    estimate_ids = new List<int>;
}
Customer::Customer(string f,string l,string a,string e, int i, int pn, string n)
{
    fname = f;
    lname = l;
    address = a;
    email = e;
    phone_num = pn;
    notes = n;
    id = i;
    estimate_ids = new List<int>;
}
Customer::~Customer()
{
    delete estimate_ids;
}

void Customer::print()
{
    cout << "First Name: " << fname << endl;
    cout << "Last Name: " << lname << endl;
    cout << "Address: " << address << endl;
    cout << "Email: " << email << endl;
    cout << "Phone Number: " << phone_num << endl;
    cout << "Notes: " << notes << endl;
    cout << "ID :" << id << endl;
}

