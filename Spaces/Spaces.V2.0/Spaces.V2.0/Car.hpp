//
//  CAR.hpp
//  Spaces.V1.0
//
//  Created by Tanner Orndorff on 9/14/17.
//  Copyright © 2017 Monocle Heads. All rights reserved.
//

// CAR.hpp

#ifndef MY_CAR
#define MY_CAR

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////
class Car {
public:
    // member variables ///////////////////////////////////////////////////////////////////////////
    std::vector<cv::Point> currentContour; //stores the point of contour - IDK WHAT THAT MEANS
    
    cv::Rect currentBoundingRect;  // is the rectangle that follows the Car
    
    std::vector<cv::Point> centerPositions; //vector of all the center positions of a certain car object found on page
    
    double dblCurrentDiagonalSize; //???????????????
    double dblCurrentAspectRatio; //????????????????
    
    bool blnCurrentMatchFoundOrNewCar; //????????????
    
    bool blnStillBeingTracked; //Car is still being tracked
    
    int intNumOfConsecutiveFramesWithoutAMatch; //how many frames its been since the last car was seen
    
    cv::Point predictedNextPosition; // where we think the next position of the car will be
    cv::Point currentCenter;
    
    // function prototypes ////////////////////////////////////////////////////////////////////////
    Car(std::vector<cv::Point> _contour);
    Car(Car &d);
    void predictNextPosition(void); //predicts next position of car with a point
    
};

#endif    // MY_CAR

