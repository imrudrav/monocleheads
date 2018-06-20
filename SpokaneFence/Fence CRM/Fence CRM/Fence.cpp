//
//  Fence.cpp
//  Fence CRM
//
//  Created by Tanner Orndorff on 11/13/17.
//  Copyright © 2017 Monocle Heads. All rights reserved.
//

#include "Fence.hpp"


//constructor
Fence::Fence(int i)
{
    lines = new List<Line>;
    gates = new List<Gate>;
    id = i;
}
//addline
void Fence::AddLine(Line* l)
{
    //adds line to the fence
    lines->add(l);
    fenceStats();
    MaterialCostCalc();
}
//Remove Line
void Fence::RemoveLine(int id)
{
    lines->remove(id);
    fenceStats();
    MaterialCostCalc();
}
//Fetch Line
Line* Fence::FetchLine(int id)
{
    return lines->fetch(id);
}
void Fence::MaterialCostCalc()
{
    material_cost = 0;
    //calc number of inserts (# of gates and post width)
    Node<Line>* tempLine = lines->front;
    //go through the linked list of lines and get the material cost of each one
    while(tempLine != nullptr)//while the list is not over
    {
        //add current material cost
        material_cost += tempLine->object->GetMaterialCost();
        //move cursor down the list
        tempLine = tempLine->next;
    }
    Node<Gate>* tempGate = gates->front;
    
    while(tempGate != nullptr)
    {
        //add current material cost
        material_cost += tempGate->object->GetCost();
        //add insert
        switch(this->lines->front->object->post_width)
        {
            case 4:
                material_cost += INSERT_TWO_SIDED_4INX8FT;
                break;
            case 5:
                material_cost += INSERT_TWO_SIDED_5INX8F;
                break;
        }
        tempGate = tempGate->next;
    }
    //material_cost += num_screws * 
}
//variables are the total for all the lines in the fence
double Fence::GetMaterialCost()
{
    return material_cost;
}
int Fence::GetID()
{
    return id;
}
//add remove and fetch gates
//void AddGate(Gate* g);
void Fence::AddGate(Gate* g)
{
    gates->add(g);
    fenceStats();
    MaterialCostCalc();
}

//void RemoveGate(int id);
void Fence::RemoveGate(int i)
{
    gates->remove(i);
    fenceStats();
    MaterialCostCalc();
}
//Gets gate from list with ID, returns null if it isnt there
Gate* Fence::FetchGate(int i)
{
    return gates->fetch(i);
}

//calculates the total items for the whole fence
void Fence::fenceStats()
{
    num_screws = num_screwsCalc();
    num_inserts = gates->count;
    distance = distanceCalc();//in feet
    heighth = lines->front->object->GetHeighth();
    material_type = lines->front->object->GetMaterialType();
    price_per_foot = price_per_footCalc();//(material cost / distance)
    num_posts = num_postsCalc();//************
    num_sections = num_sectionsCalc();;
    num_concrete_bags = num_concrete_bagsCalc();//************
    num_u_channel = num_u_channelCalc();//*************
    num_caps = num_capsCalc();//************
    num_panels = num_panelsCalc();//**************
    num_rails = num_railsCalc();//***************
}

double Fence::distanceCalc()
{
    distance = 0;
    Node<Line>* tempLine = lines->front;
    while(tempLine != nullptr)
    {
        distance += tempLine->object->GetDistance();
        tempLine = tempLine->next;
    }
    Node<Gate>* tempGate = gates->front;
    while(tempGate != nullptr)
    {
        distance += tempGate->object->GetWidth();
        tempGate = tempGate->next;
    }
    return distance;
}
double Fence::price_per_footCalc()
{
    price_per_foot = material_cost/distance;
    return price_per_foot;
}
double Fence::num_postsCalc()
{
    num_posts = 0;
    Node<Line>* tempLine = lines->front;
    while(tempLine != nullptr)
    {
        num_posts += tempLine->object->GetNumPosts();
        tempLine = tempLine->next;
    }
    return num_posts;
}
int Fence::num_sectionsCalc()
{
    num_sections = 0;
    Node<Line>* tempLine = lines->front;
    while(tempLine != nullptr)
    {
        num_sections += tempLine->object->GetNumSections();
        tempLine = tempLine->next;
    }
    return num_sections;
}
double Fence::num_concrete_bagsCalc()
{
    num_concrete_bags = num_posts * 1.5;
    return num_concrete_bags;
}
int Fence::num_u_channelCalc()
{
    num_u_channel = num_sections * 2;
    return num_u_channel;
}
int Fence::num_capsCalc()
{
    num_caps = num_posts;
    return num_caps;
}
double Fence::num_panelsCalc()
{
    num_panels = 0;
    Node<Line>* tempLine = lines->front;
    while(tempLine != nullptr)
    {
        num_panels += tempLine->object->num_panels;
        tempLine = tempLine->next;
    }
    return num_panels;
}
int Fence::num_railsCalc()
{
    num_rails = num_u_channel;
    return num_rails;
}
int Fence::num_insertsCalc()
{
    num_inserts = gates->count;
    return num_inserts;
}

int Fence::num_screwsCalc()
{
    num_screws = num_u_channel*2;
    return num_screws;
}

void Fence::print()
{
    cout << "Fence Material Cost : " << material_cost << endl;
    cout << "Number of Lines: " << lines->count << endl;
    cout << "Number of Gates: " << gates->count << endl << endl;
    cout << "Fence Stats: " << endl;
    cout << "Posts and Caps : " << num_caps << endl;
    cout << "Concrete Bags : " << num_concrete_bags << endl;
    cout << "U Channel and Rail : " << num_u_channel << endl;
    cout << "Sections: " << num_sections << endl;
    cout << "Panels: " << num_panels << endl;
    cout << "Total Length: " << distance << endl;
    cout << "Price Per Foot: " << price_per_foot << endl << endl << endl << endl;
    
    Node<Line>* tempLine = lines->front;
    while(tempLine != nullptr)
    {
        tempLine->object->print();
        tempLine = tempLine->next;
    }
    Node<Gate>* tempGate = gates->front;
    while(tempGate != nullptr)
    {
        tempGate->object->print();
        tempGate = tempGate->next;
    }
}
