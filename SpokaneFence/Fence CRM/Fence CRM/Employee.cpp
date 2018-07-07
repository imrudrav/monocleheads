//
//  Employees.cpp
//  Fence CRM
//
//  Created by Tanner Orndorff on 7/6/18.
//  Copyright © 2018 Monocle Heads. All rights reserved.
//

#include "Employee.hpp"

Employee::Employee()
{
    id = 0;
    fname = " ";
    lname = " ";
    email = " ";
    phone_num = " ";
    ssn = 0;
    address = " ";
    
}

Employee::Employee(int id, string fn, string ln, string email, string pn, int ssn, string add)
{
    this->id = id;
    fname = fn;
    lname = ln;
    this->email = email;
    phone_num = pn;
    this->ssn = ssn;
    address = add;
}
