//
//  Car.cpp
//  Spaces.V1.0
//
//  Created by Tanner Orndorff on 9/14/17.
//  Copyright © 2017 Monocle Heads. All rights reserved.
//

// Car.cpp

#include "Car.hpp"

///////////////////////////////////////////////////////////////////////////////////////////////////
Car::Car(std::vector<cv::Point> _contour) {
    
    currentContour = _contour; //vector of points
    
    currentBoundingRect = cv::boundingRect(currentContour);//creates rectangles around the contours
    
    currentCenter.x = (currentBoundingRect.x + currentBoundingRect.x + currentBoundingRect.width) / 2;//calculates the center of the Car by finding the middles of the bounding rectangles
    currentCenter.y = (currentBoundingRect.y + currentBoundingRect.y + currentBoundingRect.height) / 2;
    
    centerPositions.push_back(currentCenter); //puts this center at the back of the vector of centerPositions
    
    dblCurrentDiagonalSize = sqrt(pow(currentBoundingRect.width, 2) + pow(currentBoundingRect.height, 2)); // finds diagonal size of bounding rectangle using pythagorean thereom
    
    dblCurrentAspectRatio = (float)currentBoundingRect.width / (float)currentBoundingRect.height; //aspect ratio = bounding rectangle width/heighth
    
    blnStillBeingTracked = true;
    blnCurrentMatchFoundOrNewCar = true;
    
    intNumOfConsecutiveFramesWithoutAMatch = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void Car::predictNextPosition(void) {
    
    int numPositions = (int)centerPositions.size(); // stores how many cars there are in numPositions as an int
    
    if (numPositions == 1) {
        // if there is one instance of this car being on the frame, then there isn't much to predict
        predictedNextPosition.x = centerPositions.back().x;
        predictedNextPosition.y = centerPositions.back().y;
        
    }
    else if (numPositions == 2) {
        //if there are two instances of this specific object stored, take the difference of the two and add it to the current to guess where the third would be.
        
        int deltaX = centerPositions[1].x - centerPositions[0].x;
        int deltaY = centerPositions[1].y - centerPositions[0].y;
        
        predictedNextPosition.x = centerPositions.back().x + deltaX;
        predictedNextPosition.y = centerPositions.back().y + deltaY;
        
    }
    else if (numPositions == 3) {
        //if there are 3 instances of this object, average the changes of each for both x and y, then add it to the current to get the predicted next location.
        
        int sumOfXChanges = ((centerPositions[2].x - centerPositions[1].x) * 2) +
        ((centerPositions[1].x - centerPositions[0].x) * 1);
        
        int deltaX = (int)std::round((float)sumOfXChanges / 3.0);
        
        int sumOfYChanges = ((centerPositions[2].y - centerPositions[1].y) * 2) +
        ((centerPositions[1].y - centerPositions[0].y) * 1);
        
        int deltaY = (int)std::round((float)sumOfYChanges / 3.0);
        
        predictedNextPosition.x = centerPositions.back().x + deltaX;
        predictedNextPosition.y = centerPositions.back().y + deltaY;
        
    }
    else if (numPositions == 4) {
        //same as 3 but for 4
        
        int sumOfXChanges = ((centerPositions[3].x - centerPositions[2].x) * 3) +
        ((centerPositions[2].x - centerPositions[1].x) * 2) +
        ((centerPositions[1].x - centerPositions[0].x) * 1);
        
        int deltaX = (int)std::round((float)sumOfXChanges / 6.0);
        
        int sumOfYChanges = ((centerPositions[3].y - centerPositions[2].y) * 3) +
        ((centerPositions[2].y - centerPositions[1].y) * 2) +
        ((centerPositions[1].y - centerPositions[0].y) * 1);
        
        int deltaY = (int)std::round((float)sumOfYChanges / 6.0);
        
        predictedNextPosition.x = centerPositions.back().x + deltaX;
        predictedNextPosition.y = centerPositions.back().y + deltaY;
        
    }
    else if (numPositions >= 5) {
        //same as 3 but for 5+ (average of last 5 instances to predict the next one) 
        
        int sumOfXChanges = ((centerPositions[numPositions - 1].x - centerPositions[numPositions - 2].x) * 4) +
        ((centerPositions[numPositions - 2].x - centerPositions[numPositions - 3].x) * 3) +
        ((centerPositions[numPositions - 3].x - centerPositions[numPositions - 4].x) * 2) +
        ((centerPositions[numPositions - 4].x - centerPositions[numPositions - 5].x) * 1);
        
        int deltaX = (int)std::round((float)sumOfXChanges / 10.0);
        
        int sumOfYChanges = ((centerPositions[numPositions - 1].y - centerPositions[numPositions - 2].y) * 4) +
        ((centerPositions[numPositions - 2].y - centerPositions[numPositions - 3].y) * 3) +
        ((centerPositions[numPositions - 3].y - centerPositions[numPositions - 4].y) * 2) +
        ((centerPositions[numPositions - 4].y - centerPositions[numPositions - 5].y) * 1);
        
        int deltaY = (int)std::round((float)sumOfYChanges / 10.0);
        
        predictedNextPosition.x = centerPositions.back().x + deltaX;
        predictedNextPosition.y = centerPositions.back().y + deltaY;
        
    }
    else {
        // should never get here
    }
    
}



