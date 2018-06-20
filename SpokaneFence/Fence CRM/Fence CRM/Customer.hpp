//
//  Customer.hpp
//  Fence CRM
//
//  Created by Tanner Orndorff on 11/13/17.
//  Copyright © 2017 Monocle Heads. All rights reserved.
//

#ifndef Customer_hpp
#define Customer_hpp

#include "List.hpp"

using namespace std;

class Customer
{
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
public:
    Customer();
    ~Customer();
    Customer(string f,string l,string a,string e,int,int pn, string n);
    //getters and setters
    int GetID();
    void AddEstimateID();
    void RemoveEstimateID(int id);
    int FetchEstimateId(int id);
    string GetFName();
    string GetLName();
    string GetAddress();
    string GetEmail();
    int GetPhoneNum();
    string GetNotes();
    void SetFName(string f);
    void SetLName(string l);
    void SetAddress(string a);
    void SetPhoneNum(int pn);
    void SetEmail(string e);
    void print();
    
    
    
};
#endif /* Customer_hpp */
