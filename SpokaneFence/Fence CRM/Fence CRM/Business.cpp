//
//  Business.cpp
//  Fence CRM
//
//  Created by Tanner Orndorff on 11/13/17.
//  Copyright © 2017 Monocle Heads. All rights reserved.
//

#include "Business.hpp"

//Implementation of Buisness

//constructor
Business::Business()
{
    
}
//adds estimate to the business
void Business::AddEstimate(Estimate* e)
{
    estimates->add(e);
}
//removes estimate from the business records
void Business::RemoveEstimate(int i)
{
    estimates->remove(i);
}
//retrieves estimate from the business records
Estimate* Business::FetchEstimate(int i)
{
    Estimate* temp = estimates->fetch(i);
    return temp;
}
//adds customer to the business records
void Business::AddCustomer(Customer* c)
{
    customers->add(c);
}
//removes customer from the business records
void Business::RemoveCustomer(int i)
{
    customers->remove(i);
}
//fetches customer from the business records 
Customer* Business::FetchCustomer(int i)
{
    Customer* temp = customers->fetch(i);
    return temp;
}

