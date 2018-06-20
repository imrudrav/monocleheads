//
//  Line.cpp
//  Fence CRM
//
//  Created by Tanner Orndorff on 11/13/17.
//  Copyright © 2017 Monocle Heads. All rights reserved.
//

#include "Line.hpp"
#include <math.h>

//Line(double d, double h, string mt);
//initiate all values and calculate all line properties. 
Line::Line(int id, double d,int pw, int h, string mt, bool bti, bool eti)
{
    this->id = id;
    beg_tie_in = bti;
    end_tie_in = eti;
    distance = d;
    heighth = h;
    material_type = mt;
    post_width = pw;
    MaterialCostCalc();
}
//////////////////////////////////////////////////////////////////Get fencing cost from Dad or something. It would need to be taken from somewhere
double Line::MaterialCostCalc()
{
    material_cost = 0;
    //get number of all the materials
    NumPostsCalc();
    NumSectionsCalc();
    SecLengthCalc();
    NumUChannelCalc();
    NumFenceCapsCalc();
    NumConcreteBagsCalc();
    NumPanelsCalc();
    NumRailsCalc();
    //add up cost of all the fence items
    if (material_type == "WHITE")
    {
        //materials that depend on post width
        switch(post_width)
        {
            case 4:
                if (heighth == 6)
                    material_cost += (num_posts * WHITE_POST_ECONO_4INX4INX6FT);
                else
                    material_cost += (num_posts * WHITE_POST_ECONO_4INX4INX8FT);
                material_cost += (num_caps * WHITE_POST_CAP_4INX4IN);
                break;
            case 5:
                if (heighth == 6)
                    material_cost += (num_posts * WHITE_POST_ECONO_5INX5INX6FT);
                else
                    material_cost += (num_posts * WHITE_POST_ECONO_5INX5INX8FT);
                material_cost += (num_caps * WHITE_POST_CAP_5INX5IN);
                break;
            default:
                return material_cost = 0;
        }
        //materials that do not depend on post width
        //uchannel
        material_cost += (num_u_channel * WHITE_PRIVACY_U_CHANNEL_6);
        //sections
        material_cost += (num_panels * WHITE_PRIVACY_T_G_11INX62IN);
        if (section_length > 6)
            material_cost += (num_rails * WHITE_PRIVACY_RAIL_GRN_1X5X8);
        else
            material_cost += (num_rails * WHITE_PRIVACY_RAIL_GRN_1X5X6);
    }
    else if (material_type == "TAN")
    {
        //materials that depend on post width
        switch(post_width)
        {
            case 4:
                if (heighth == 6)
                    material_cost += (num_posts * TAN_POST_PREMIUM_4INX4INX6FT);//we only have 6 foot tan posts that are 4 inches
                else
                    return material_cost = 0;
                material_cost += (num_caps * TAN_POST_CAP_4INX4IN);
                break;
            case 5:
                if (heighth == 6)
                    material_cost += (num_posts * TAN_POST_ECONO_5INX5INX6FT);
                else
                    material_cost += (num_posts * TAN_POST_ECONO_5INX5INX8FT);
                material_cost += (num_caps * TAN_POST_CAP_5INX5IN);
                break;
            default:
                return material_cost = 0;
        }
        //materials that do not depend on post width
        //uchannel
        material_cost += (num_u_channel * TAN_PRIVACY_U_CHANNEL_6);
        //sections
        material_cost += (num_panels * TAN_PRIVACY_T_G_11INX62IN);
        if (section_length > 6)
            material_cost += (num_rails * TAN_PRIVACY_RAIL_GRN_1X5X8);
        else
            material_cost += (num_rails * TAN_PRIVACY_RAIL_GRN_1X5X6);
    }
    else if (material_type == "CLAY" || material_type == "STONE")
    {
        //materials that depend on post width
        switch(post_width)
        {
            case 4:
                if (heighth == 6)
                    material_cost += (num_posts * CLAY_OR_STONE_POST_PREMIUM_4INX4INX6FT);//we only have 6 foot clay or stone posts that are 4 inches wide
                else
                    return material_cost = 0;
                material_cost += (num_caps * CLAY_OR_STONE_POST_CAP_4INX4IN);
                break;
            case 5:
                if (heighth == 6)
                    material_cost += (num_posts * CLAY_OR_STONE_POST_ECONO_5INX5INX6_5FT);//set at 6 feet tall
                else
                    material_cost += (num_posts * CLAY_OR_STONE_POST_PREMIUM_5INX5INX8FT);
                material_cost += (num_caps * CLAY_OR_STONE_POST_CAP_5INX5IN);
                break;
            default:
                return material_cost = 0;
        }
        //materials that do not depend on post width
        //uchannel
        material_cost += (num_u_channel * CLAY_OR_STONE_PRIVACY_U_CHANNEL_6FT);
        //sections
        material_cost += (num_panels * CLAY_OR_STONE_PRIVACY_T_G_11INX62IN);
        if (section_length > 6)
            material_cost += (num_rails * CLAY_OR_STONE_PRIVACY_RAIL_STD_1X5X8);
        else
            material_cost += (num_rails * CLAY_OR_STONE_PRIVACY_RAIL_STD_1X5X6);
    }
    else
        return material_cost = 0;
    material_cost += (num_concrete_bags * CONCRETE_PRE_MIX_80LBS);
    price_per_foot =  PricePerFootCalc(material_cost, distance);
    return material_cost;
}

//Calculates the number of posts needed and stores it
void Line::NumPostsCalc()
{
    num_posts = ceil((distance / 8)+1);//round number of posts up if value isnt even
    if(beg_tie_in == true)
        num_posts--;
    if(end_tie_in == true)
        num_posts--;
}
//calculates the number of section of the line
void Line::NumSectionsCalc()
{
    num_sections = ceil(distance / 8);
}
void Line::NumPanelsCalc()
{
    double length_in_inches = distance * 12;//(feet to inches)
    switch(post_width)
    {
        case 4:
            length_in_inches = length_in_inches - (num_posts * (post_width-1));//takes into account the length of the posts and subtracts one to give some cushon.
            num_panels = length_in_inches / PANEL_WIDTH;
            break;
        case 5:
            length_in_inches = length_in_inches - (num_posts * (post_width-1));//takes into account the length of the posts and subtracts one to give some cushon.
            num_panels = length_in_inches / PANEL_WIDTH;
            break;
        default:
            break;
    }
}
//calculates how much rail to buy. length should be top rail and bottom rail for whole length of line 
void Line::NumRailsCalc()
{
    //if section lengths is greater than 6, buy 8 foot
    if (section_length > 6)
        num_rails = 2*(ceil(distance / 8));//multiply by 2 because there are bottoms and top rails
    //if less than 6, buy 6
    else
        num_rails = 2*(ceil(distance / 6));//multiply by 2 because there are bottoms and top rails 
}
void Line::SecLengthCalc()
{
    section_length = distance / num_sections;
}
//Calculates the number of u channels for a specific line 
void Line::NumUChannelCalc()
{
    num_u_channel = num_sections * 2;
}
//calculates the number of fence caps for a given line
void Line::NumFenceCapsCalc()
{
    num_caps = num_posts;
}
//calculates the amount of concrete needed
void Line::NumConcreteBagsCalc()
{
    num_concrete_bags = num_posts * 1.5; //3 bags of concrete for every 2 posts.
}
double Line::PricePerFootCalc(double matcost, double dis)
{
    return price_per_foot = matcost / dis;
}
//getter for distance
double Line::GetDistance()
{
    return distance;
}
//getter for fence heighth
int Line::GetHeighth()
{
    return heighth;
}
//getter for material type
string Line::GetMaterialType()
{
    return material_type;
}
//getter for posts
int Line::GetNumPosts()
{
    return num_posts;
}
//getter for sections
int Line::GetNumSections()
{
    return num_sections;
}
//getter for material costs
double Line::GetMaterialCost()
{
    return material_cost;
}

int Line::GetID()
{
    return id;
}

void Line::print()
{
    //Print out all important values
    cout << "line distance: " << this->distance << endl;//in feet
    cout << "line heighth: " << this->heighth<<endl;
    cout << "line post width: " << post_width << endl;//4 inches or 5 inches
    cout << "line material_type: " << material_type << endl; 
    cout << "line price_per_foot: " << price_per_foot << endl;
    cout << "line num_posts: " << num_posts << endl;//************
    cout << "line num_sections: " << num_sections << endl;
    cout << "line num_concrete_bags: " << num_concrete_bags << endl;//************
    cout << "line num_u_channel: " << num_u_channel << endl;//*************
    cout << "line num_caps: " << num_caps << endl;//************
    cout << "line num_panels: " << num_panels << endl;//**************
    cout << "line num_rails: " << num_rails << endl;//***************
    cout << "line material_cost: " << material_cost << endl;
    cout << "line id: " << id << endl;
    cout << endl;
}

