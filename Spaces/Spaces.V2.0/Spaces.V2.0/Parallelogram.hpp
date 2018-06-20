//
//  Parallelogram.hpp
//  Spaces.V2.0
//
//  Created by Tanner Orndorff on 9/26/17.
//  Copyright © 2017 Monocle Heads. All rights reserved.
//

#ifndef Parallelogram_hpp
#define Parallelogram_hpp

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace cv;
////////////////////////////Parallelogram class

class Parallelogram {
public:
    //4 points that represent a parallelogram
    //(in order: bottom right, bottom left, top left, top right)
    std::vector<std::vector<Point>> pts;
    //member functions
    //slope equation for each 
};



#endif /* Parallelogram_hpp */
