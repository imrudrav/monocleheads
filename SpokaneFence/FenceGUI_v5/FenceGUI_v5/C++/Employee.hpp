//
//  Employees.hpp
//  Fence CRM
//
//  Created by Tanner Orndorff on 7/6/18.
//  Copyright © 2018 Monocle Heads. All rights reserved.
//

#ifndef Employees_hpp
#define Employees_hpp

#include "List.hpp"
#include <stdio.h>
using namespace std;

class Employee
{
public:
    int id;
    string fname;
    string lname;
    string email;
    string phone_num;
    int ssn;
    string address;
    Employee();
    Employee(int id, string fn, string ln, string email, string pn, int ssn, string add);
};



#endif /* Employees_hpp */

