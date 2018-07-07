//
//  Gate.cpp
//  Fence CRM
//
//  Created by Tanner Orndorff on 11/13/17.
//  Copyright © 2017 Monocle Heads. All rights reserved.
//

#include "Gate.hpp"

//implementation of Gate class
//MUST PASS ALL STRINGS AS ALL CAPS
Gate::Gate(int i, int w, string c, string m)
{
    //initiate all values
    width = w;
    material = m;
    color = c;
    //call the cost calc function once I have info about how to estimate the cost of a gate
    cost = CostCalc( width, color, material);
    id = i;
}

//instantiate getters for the properties
int Gate::GetWidth()
{
    return width;
}
string Gate::GetMaterial()
{
    return material;
}
string Gate::GetColor()
{
    return color;
}
int Gate::GetID()
{
    return id;
}
double Gate::GetCost()
{
    return cost;
}

void Gate::print()
{
    cout << "gate ID: " << this->id << endl;
    cout << "gate color: " << this->color << endl;
    cout << "gate material: " << this->material << endl;
    cout << "gate width: " << this->width << endl;
    cout << "gate cost: " << this->cost << endl;
    cout << endl;
}

//Gates are 6 feet tall.
//calculates the cost of the gate based on the width, material, and gate style.
//If no match is found on cost sheet, then 0 is returned.
double Gate::CostCalc( int w, string c, string m)
{
    if (c == "WHITE")
    {
        switch (w)
        {
            case 4:
                if(m == "METAL")
                    return WHITE_METAL_GATE_T_G_4X6;
                else if(m == "VINYL")
                    return WHITE_VINYL_GATE_T_G_4X6;
                else
                    return 0;//input was not correct
            case 5:
                if(m == "METAL")
                    return WHITE_METAL_GATE_T_G_5X6;
                else if(m == "VINYL")
                    return WHITE_VINYL_GATE_T_G_5X6;
                else
                    return 0;
            case 6:
                if(m == "METAL")
                    return WHITE_METAL_GATE_T_G_6X6;
                else
                    return 0;
            default:
                return 0;
        }
    }
    else if (c == "TAN")
    {
        switch (w)
        {
            case 4:
                if(m == "METAL")
                    return TAN_METAL_GATE_T_G_4X6;
                else if(m == "VINYL")
                    return TAN_VINYL_GATE_T_G_4X6;
                else
                    return 0;//input was not correct
            case 5:
                if(m == "METAL")
                    return TAN_METAL_GATE_T_G_5X6;
                else if(m == "VINYL")
                    return TAN_VINYL_GATE_T_G_5X6;
                else
                    return 0;//INCORRECT INPUT
            case 6:
                if(m == "METAL")
                    return TAN_METAL_GATE_T_G_6X6;
                else
                    return 0;//INCORRECT INPUT
            default:
                return 0;
        }
    }
    else if (c == "CLAY" || c == "STONE")
    {
        switch (w)
        {
            case 4:
                if(m == "METAL")
                    return CLAY_OR_STONE_METAL_GATE_T_G_4X6;
                else if(m == "VINYL")
                    return CLAY_OR_STONE_VINYL_GATE_T_G_4X6;
                else
                    return 0;//input was not correct
            case 5:
                if(m == "METAL")
                    return CLAY_OR_STONE_METAL_GATE_T_G_5X6;
                else if(m == "VINYL")
                    return CLAY_OR_STONE_VINYL_GATE_T_G_5X6;
                else
                    return 0;
            case 6:
                if(m == "METAL")
                    return CLAY_OR_STONE_METAL_GATE_T_G_6X6;
                else
                    return 0;
            default:
                return 0;
        }
    }
    else
        return 0;//the input was not correct
    
}

