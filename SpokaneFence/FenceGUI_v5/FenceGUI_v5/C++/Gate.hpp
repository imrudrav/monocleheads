//
//  Gate.hpp
//  Fence CRM
//
//  Created by Tanner Orndorff on 11/13/17.
//  Copyright © 2017 Monocle Heads. All rights reserved.
//

#ifndef Gate_hpp
#define Gate_hpp

#include "Customer.hpp"
#include <stdio.h>
#include <string>
using namespace std;

class Gate
{
public:
    //properties
    int width;//4,5 OR 6
    string color;//WHITE , TAN, CLAY, or STONE
    string material;//VINYL OR METAL
    double cost;
    int id;
    double start;
    //constructor
    Gate(int id, int width, string color, string material);
    double CostCalc( int w, string c, string m);
    //getters
    int GetWidth();
    string GetColor();
    string GetMaterial();
    double GetCost();
    int GetID();
    void print();//prints gate to console for testing
};
#endif /* Gate_hpp */

