//
//  Fence.hpp
//  Fence CRM
//
//  Created by Tanner Orndorff on 11/13/17.
//  Copyright © 2017 Monocle Heads. All rights reserved.
//

#ifndef Fence_hpp
#define Fence_hpp
#include <stdio.h>
#include "Line.hpp"
using namespace std;

class Fence
{
public:
    List<Line>* lines;
    List<Gate>* gates;
    double material_cost;
    double distance;//in feet
    int heighth;
    string material_type;
    double price_per_foot;
    double num_posts;//************
    int num_sections;
    double num_concrete_bags;//************
    int num_u_channel;//*************
    int num_caps;//************
    double num_panels;//**************
    int num_rails;//***************
    int num_screws;
    int num_inserts;
    int id;
    //All variables are recalculated upon object contruction and line addition
    //takes id passed in from main
    Fence(int);
    ~Fence();
    void fenceStats();
    void AddLine(Line* l);
    void RemoveLine(int id);
    Line* FetchLine(int id);
    void AddGate(Gate* g);
    void RemoveGate(int id);
    Gate* FetchGate(int id);
    void MaterialCostCalc();
    //variables are the total for all the lines in the fence
    double GetMaterialCost();
    double distanceCalc();
    double price_per_footCalc();
    double num_postsCalc();
    int num_sectionsCalc();
    double num_concrete_bagsCalc();
    int num_u_channelCalc();
    int num_capsCalc();
    double num_panelsCalc();
    int num_railsCalc();
    int num_insertsCalc();
    int num_screwsCalc();
    void print();
};
#endif /* Fence_hpp */

