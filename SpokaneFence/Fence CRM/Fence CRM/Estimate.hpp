//
//  Estimate.hpp
//  Fence CRM
//
//  Created by Tanner Orndorff on 11/13/17.
//  Copyright © 2017 Monocle Heads. All rights reserved.
//

#ifndef Estimate_hpp
#define Estimate_hpp
#include <stdio.h>
#include "Fence.hpp"
using namespace std;

///
class Estimate
{
    int id;
    List<Fence>* fences;
    int customer_id;
    double total_cost;
public:
    Estimate();
    void AddFence(Fence* f);
    void RemoveFence(int i);
    Fence* FetchFence(int i);
    void TotalCostCalc();
    double GetTotalCost();
    int GetCustomerId();
    void SetCustomerId(int i);
    int GetID();
};
#endif /* Estimate_hpp */
