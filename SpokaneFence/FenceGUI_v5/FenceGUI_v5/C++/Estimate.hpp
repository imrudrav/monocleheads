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
public:
    int id;
    List<Fence>* fences;
    int customer_id;
    int employee_id;
    int rep_id;
    string date;
    double total_cost;
    Estimate();
    Estimate(int cid, int eid, int rid, string date);
    ~Estimate();
    void AddFence(Fence* f);
    void RemoveFence(int i);
    Fence* FetchFence(int i);
    void TotalCostCalc();
};
#endif /* Estimate_hpp */

