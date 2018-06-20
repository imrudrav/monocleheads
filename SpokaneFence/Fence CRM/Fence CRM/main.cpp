//
//  main.cpp
//  Fence CRM
//
//  Created by Tanner Orndorff on 11/13/17.
//  Copyright © 2017 Monocle Heads. All rights reserved.
//

#include <iostream>
using namespace std;
#include "Business.hpp"

//functioning node class **********
//list class ***********
//allow it to be initialized as a template. ******************
//store estimate, fence, line, gate, and customer all in the class *****************
//deconstructor for List class and NOde Class (NO MEMORY LEAKS) ********************
//test *************************
//Get rid of the invoice ****************************
//Use cost sheet to enter in all the supply cost********************
//complete material cost algorithms
    //gate******************************
    //line******************************
    //fence*****************************
//test
    //fix gates added to line and how it affects materials *******************
    //add concrete cost and screw cost****************************
    //get price of screws
//test
//test all code in main!!!!******************************************
//pass estimate into quickbooks where it creates an estimate 
//Move onto the GUI....

//*************************
//Talk to dad about the following
    //How much top rail and bottom rail he orders 

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Fence* f = new Fence(0);
    Line* one = new Line(1, 4, 5, 6, "WHITE", false, false );
    Line* two = new Line(2, 4, 5, 6, "WHITE", false, true );
    Line* three = new Line(3, 70, 5, 6, "WHITE", false, true );
    Line* four = new Line(4, 110, 5, 6, "WHITE", false, true );
    Line* five = new Line(5, 70, 5, 6, "WHITE", false, true );
    Line* six = new Line(6, 5, 5, 6, "WHITE", false, false );
    Line* seven = new Line(7, 5, 5, 6, "WHITE", false, false );
    
    //add lines to fence
    f->AddLine(one);
    f->AddLine(two);
    f->AddLine(three);
    f->AddLine(four);
    f->AddLine(five);
    f->AddLine(six);
    f->AddLine(seven);
    
    Gate* left = new Gate(1,5,"WHITE","VINYL");
    Gate* right = new Gate(2,4,"WHITE","VINYL");
    
    //add gates to fence
    f->AddGate(left);
    f->AddGate(right);
    
    f->print();
    
    //test fence material cost calc
    
    return 0;
}


