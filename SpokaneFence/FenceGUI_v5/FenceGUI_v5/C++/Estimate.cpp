//
//  Estimate.cpp
//  Fence CRM
//
//  Created by Tanner Orndorff on 11/13/17.
//  Copyright © 2017 Monocle Heads. All rights reserved.
//

#include "Estimate.hpp"
//constructor
Estimate::Estimate()
{
    fences = new List<Fence>();
}
Estimate::Estimate(int cid, int eid, int rid, string date)
{
    customer_id = cid;
    employee_id = eid;
    rep_id = rid;
    this->date = date;
    total_cost = 0;
    fences = new List<Fence>();
}
Estimate::~Estimate()
{
    delete fences;
}
//addfence to lists of fences on estimate
void Estimate::AddFence(Fence* f)
{
    fences->add(f);
}
//removes fence in estimate list with given ID
void Estimate::RemoveFence(int i)
{
    fences->remove(i);
}
//fetches fence in estimate list with given ID
Fence* Estimate::FetchFence(int i)
{
    
    Fence* temp = fences->fetch(i);
    return temp;
}
//add the cost of all the fences in the estimate
void Estimate::TotalCostCalc()
{
    total_cost = 0;
    Node<Fence>* temp = fences->front;
    //check each fence in estimate and add the material cost
    while(temp != nullptr)
    {
        total_cost = total_cost + temp->object->GetMaterialCost();
    }
}

