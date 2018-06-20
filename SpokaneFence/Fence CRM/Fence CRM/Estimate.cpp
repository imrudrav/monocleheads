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
//returns the total cost on the estimate
double Estimate::GetTotalCost()
{
    return total_cost;
}
int Estimate::GetCustomerId()
{
    return customer_id;
}
void Estimate::SetCustomerId(int i)
{
    customer_id = i;
}
int Estimate::GetID()
{
    return id;
}
