//
//  Business.hpp
//  Fence CRM
//
//  Created by Tanner Orndorff on 11/13/17.
//  Copyright © 2017 Monocle Heads. All rights reserved.
//

#ifndef Business_hpp
#define Business_hpp

#include "Estimate.hpp"
#include <stdio.h>
using namespace std;

class Business
{
    //linked list of customers
    //linked list of estimates
    List<Customer>* customers;
    List<Estimate>* estimates;
    //vector<Invoice*> invoices;
    //constructor
public:
    Business();
    void AddEstimate(Estimate* b);
    void RemoveEstimate(int id);
    Estimate* FetchEstimate(int id);
    void AddCustomer(Customer* c);
    void RemoveCustomer(int id);
    Customer* FetchCustomer(int id);
    //void AddInvoice(Invoice* i);
    //void RemoveInvoice(int id);
    
};

#endif /* Business_hpp */
