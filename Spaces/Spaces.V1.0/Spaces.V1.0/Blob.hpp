//
//  Blob.hpp
//  Spaces.V1.0
//
//  Created by Tanner Orndorff on 9/14/17.
//  Copyright © 2017 Monocle Heads. All rights reserved.
//

// Blob.hpp

#ifndef MY_BLOB
#define MY_BLOB

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

///////////////////////////////////////////////////////////////////////////////////////////////////
class Blob {
    public:
    // member variables ///////////////////////////////////////////////////////////////////////////
    std::vector<cv::Point> currentContour;
    
    cv::Rect currentBoundingRect;
    
    std::vector<cv::Point> centerPositions;
    
    double dblCurrentDiagonalSize;
    double dblCurrentAspectRatio;
    
    bool blnCurrentMatchFoundOrNewBlob;
    
    bool blnStillBeingTracked;
    
    int intNumOfConsecutiveFramesWithoutAMatch;
    
    cv::Point predictedNextPosition;
    
    // function prototypes ////////////////////////////////////////////////////////////////////////
    Blob(std::vector<cv::Point> _contour);
    void predictNextPosition(void);
    
};

#endif    // MY_BLOB

