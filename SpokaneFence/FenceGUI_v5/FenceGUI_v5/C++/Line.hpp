//
//  Line.hpp
//  Fence CRM
//
//  Created by Tanner Orndorff on 11/13/17.
//  Copyright © 2017 Monocle Heads. All rights reserved.
//

#ifndef Line_hpp
#define Line_hpp

#include <stdio.h>
#include "Gate.hpp"
using namespace std;

class Line
{
public:
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
    const double PANEL_WIDTH = 11.25; //panel width in inches
    double material_cost;
    int id;
    bool beg_tie_in;
    bool end_tie_in;
    double section_length;
    void NumPostsCalc();
    void NumSectionsCalc();
    void NumUChannelCalc();
    void NumFenceCapsCalc();
    void SecLengthCalc();
    double PricePerFootCalc(double,double);
    void NumConcreteBagsCalc();
    void NumPanelsCalc();
    void NumRailsCalc();
    //takes in distance, post width, heighth, material type, front tie in, back tie in. Material type is equal to WHITE, TAN, CLAY, or STONE
    Line(int id, double distance,int post_width, int heighth, string material_type, bool front_tie_in, bool back_tie_in);
    int post_width;//4 inches or 5 inches
    double MaterialCostCalc();
    double GetDistance();
    int GetHeighth();
    string GetMaterialType();
    int GetNumPosts();
    int GetNumSections();
    double GetMaterialCost();
    int GetID();
    int GetNumInserts();
    void print();
    
};
#endif /* Line_hpp */

