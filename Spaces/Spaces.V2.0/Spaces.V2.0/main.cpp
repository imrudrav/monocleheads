//
//  main.cpp
//  Spaces.V2.0
//
//  Created by Tanner Orndorff on 9/18/17.
//  Copyright © 2017 Monocle Heads. All rights reserved.
//

#include <iostream>
#include "Car.hpp"
#include "Parallelogram.hpp"
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace cv;

//How will this work with the Car class?

//GLobal Variables
const int BLUR_CONSTANT = 5;
const int THRESH_VALUE = 70;
const int MAX_THRESH = 255;
const int CAR_SIZE = 4000;
const int CAR_NUMBER = 10;
const cv::Scalar SCALAR_BLACK = cv::Scalar(0.0, 0.0, 0.0);
const cv::Scalar SCALAR_WHITE = cv::Scalar(255.0, 255.0, 255.0);
const Mat STRUCT_ELEMENT_SMALL = getStructuringElement(MORPH_RECT, Size(3,3));
const Mat STRUCT_ELEMENT_MED = getStructuringElement(MORPH_RECT, Size(7,7));
const Mat STRUCT_ELEMENT_LRG = getStructuringElement(MORPH_RECT, Size(15,15));
const Point TEST_RECT_1 = Point(150,290);
const Point TEST_RECT_2 = Point(285,400);
const std::string CAR_IS = "Car is in spot.";
const std::string CAR_ISNT = "Spot is open.";
const std::string FILE_NAME = "/Users/tannerorndorff/Documents/Monocleheads/Spaces/Spaces.V2.0/Spaces.V2.0/Version2.mov";
bool isInSpot = false;
std::vector<Car> cars;
//Functions Needed
//read video
bool readVideo(std::string fileName, VideoCapture cap);
Mat getFrameOriginal(Mat firstFrame);
void drawShowContours(Size imgSize, std::vector<std::vector<Point>> contours, std::string FILE_NAME);
void parkingSpaceDraw(std::vector<std::vector<Point>> pts, Mat output, Scalar color );
bool checkSpotOccupancy(Point center);
void drawLaneStatusOnImage(bool &carIsInBox, cv::Mat &imgFrame2Copy);
//matchCurrentToExisting
//drawPolygon
//parkingStatus
//writeParkingStatus

int main(void) {
    cv::VideoCapture capVideo; //will use to open desired video
 
    cv::Mat frame1; //first frame of the video
    cv::Mat frame2; //second frame of the video
    
    //int carCount = 0; //count of cars that cross the line
    
    capVideo.open(FILE_NAME); //opens desired video.
    
    
    if (!capVideo.isOpened()) {                                                 // if unable to open video file
        std::cout << "error reading video file" << std::endl << std::endl;      // show error message
        return(0);                                                              // and exit program
    }
    
    if (capVideo.get(CV_CAP_PROP_FRAME_COUNT) < 2) {
        std::cout << "error: video file must have at least two frames";
        return(0);
    }
    
    capVideo.read(frame1); //if has at least 2 files, it will read the two first frames and store in these variables
    capVideo.read(frame2);
   
    const Mat FRAME_ORIGINAL = getFrameOriginal(frame1);
    
    //imshow("OG", FRAME_ORIGINAL);
    
    char checkForEscKey = 0; //variable to check to see if the user has exited the program with the escape key
    
    bool firstFrame = true; //shows whether or not the first frame opened
    
    bool carIsInSpot = false;
    
    int frameCount = 2; //starting frame count before code is added to the video
    
    //draw polygon over parking spot
    std::vector<std::vector<cv::Point>> pts;
    std::vector<Point> spot;
    Point tr = Point(205, 320);
    spot.push_back(tr);
    Point tl = Point(125, 337);
    spot.push_back(tl);
    Point bl = Point(205, 400);
    spot.push_back(bl);
    Point br = Point(305, 370);
    spot.push_back(br);
    pts.push_back(spot);
    parkingSpaceDraw(pts,frame1, SCALAR_WHITE);
    rectangle(frame1, TEST_RECT_1, TEST_RECT_2, SCALAR_WHITE);
    //imshow("Frame1", frame1);
    //write on video if someone is in the spot or not.
    //prepare to move on

    
    while (capVideo.isOpened() && checkForEscKey != 27) {//if the video is opened and the escape key is not hit
        
        cv::Mat frame1Copy = frame1.clone(); //copys both of the image frames ????????? why
        cv::Mat frame2Copy = frame2.clone();
        
        cv::Mat difference; //two more potential frames
        cv::Mat thresh;
        
        cv::cvtColor(frame1Copy, frame1Copy, CV_BGR2GRAY); //converts image copyies to grey scale
        
        //cv::imshow("PreBlur", frame1Copy);
        //blur images
        
        cv::GaussianBlur(frame1Copy, frame1Copy, Size(BLUR_CONSTANT,BLUR_CONSTANT), 0); // the higher the size, the more blur!!

        //imshow("PostBlur", frame1Copy);
        

        //take the difference of the two images
        
        absdiff(frame1Copy, FRAME_ORIGINAL, difference);

        //i need to take the difference of the empty parking lot with the live video of it.
        //it wont work if i am comparing close frames because it uses difference to track objects.
        //i will need a picture in the daylight of the parking lot empty and a picture at night with it empty
        
        //imshow("Difference", difference);
        
        //thresh the image so that it is two colored, black and white
        threshold(difference, thresh, THRESH_VALUE, MAX_THRESH, THRESH_BINARY);
        
        //imshow("threshold", thresh);
        
        //dilate the white spots/erode
        for (int i = 0; i < 2; i++) // we want to go through 3 times
        {
            dilate(thresh, thresh, STRUCT_ELEMENT_MED);
            dilate(thresh, thresh, STRUCT_ELEMENT_MED);
            erode(thresh, thresh, STRUCT_ELEMENT_MED);
        }
        
        //imshow("Post Dilate", thresh);
        
        //draw contours
        Mat threshCopy = thresh.clone();
        
        std::vector<std::vector<Point>> contours;
        
        findContours(threshCopy, contours, CV_RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
        
        drawShowContours(threshCopy.size(), contours, "contours");
        
        
        //turn these blobs into convex hull
        std::vector<std::vector<Point>> convexHull(contours.size());
       
        //turn each contour into a convex hull
        
        for (int i = 0; i < contours.size(); i++)
        {
            cv::convexHull(contours[i], convexHull[i]);
        }
        
        drawShowContours(threshCopy.size(), convexHull, "convexHull" );
        
        //check to see if convex are the right size to be cars
        for (auto &convexHull : convexHull)
        {
            Car possibleCar(convexHull);
            //check to see if it's big enough
            if(possibleCar.currentBoundingRect.area() >(CAR_SIZE))
            {
                //Car* carRef = &possibleCar;
                //it is car: draw rectangle around it. put in array of cars
                cars.push_back(possibleCar);
                rectangle(frame2Copy, possibleCar.currentBoundingRect, SCALAR_WHITE);
                //drawLaneStatusOnImage(carIsInSpot, frame2Copy);
            }
            
            
        }
        //compare each car to each spot
        for (int i = 0; i<cars.size(); i++)
        {
            carIsInSpot = checkSpotOccupancy(cars[i].currentCenter);
            drawLaneStatusOnImage(carIsInSpot, frame2Copy);
        }
        cars.clear();
        
        
        imshow("imgFrame2Copy", frame2Copy);
        
        //cv::waitKey(0);                 // uncomment this line to go frame by frame for debugging
        
        // now we prepare for the next iteration
        
        frame1 = frame2.clone();           // move frame 1 up to where frame 2 is
        
        if ((capVideo.get(CV_CAP_PROP_POS_FRAMES) + 1) < capVideo.get(CV_CAP_PROP_FRAME_COUNT)) {
            capVideo.read(frame2);
        }
        else {
            std::cout << "end of video\n";
            break;
        }
        
        firstFrame = false;
        frameCount++;
        checkForEscKey = cv::waitKey(1);
    }
    
    if (checkForEscKey != 27) {               // if the user did not press esc (i.e. we reached the end of the video)
        cv::waitKey(0);                         // hold the windows open to allow the "end of video" message to show
    }
    // note that if the user did press esc, we don't need to hold the windows open, we can simply let the program end which will close the windows
    
    return(0);
}

///////////////////////////////////////////////
bool readVideo(std::string fileName, VideoCapture cap)
{
    cap.open(fileName);
    if(cap.isOpened())
        return true;
    else
    {
        std::cout << "Error reading video...." << std::endl;
        return false;
    }
    
}
//////////////////////////////////////////////
Mat getFrameOriginal(Mat firstFrame)
{
    //convert frame to grey and then blur.
    cvtColor(firstFrame, firstFrame, CV_BGR2GRAY);
    GaussianBlur(firstFrame, firstFrame, Size(BLUR_CONSTANT,BLUR_CONSTANT), 0);
    return firstFrame;
    
}

//draw contours
//takes array of array of contours and draws them on blank image.
//////////////////////////////////////////////

void drawShowContours(Size imgSize, std::vector<std::vector<Point>> contours, std::string fileName)
{
    //create black image
    Mat blkImage(imgSize, CV_8UC3, SCALAR_BLACK);
    //draw contours on image
    drawContours(blkImage, contours, -1, SCALAR_WHITE, -1);
    //show image
    //imshow(fileName, blkImage);
    
}

////////////////////////////////////////////////
void parkingSpaceDraw(std::vector<std::vector<Point>> pts, Mat output, Scalar color)
{
    fillPoly(output, pts, SCALAR_WHITE);
    //imshow("Polygon", output);
}
////////////////////////////////////////////////
bool checkSpotOccupancy(Point center)
{
    //if car center point is within parallelogram
    if (center.x >= TEST_RECT_1.x && center.x <= TEST_RECT_2.x && center.y >= TEST_RECT_1.y && center.y <= TEST_RECT_2.y )
        return true;
    else
        return false;
}
////////////////////////////////////////////////
void drawLaneStatusOnImage(bool &carIsInBox, cv::Mat &imgFrame2Copy) {
    
    
    int intFontFace = CV_FONT_HERSHEY_SIMPLEX;
    double dblFontScale = (imgFrame2Copy.rows * imgFrame2Copy.cols) / 300000.0;
    int intFontThickness = (int)std::round(dblFontScale * 1.5);
    
    cv::Size textSize = cv::getTextSize(CAR_IS, intFontFace, dblFontScale, intFontThickness, 0);
    
    cv::Point ptTextBottomLeftPosition;
    
    ptTextBottomLeftPosition.x = imgFrame2Copy.cols - 1 - (int)((double)textSize.width * 1.25);
    ptTextBottomLeftPosition.y = (int)((double)textSize.height * 1.25);
    
    if (carIsInBox == true)
    {
        cv::putText(imgFrame2Copy, CAR_IS, ptTextBottomLeftPosition, intFontFace, dblFontScale, SCALAR_WHITE, intFontThickness);
    }
    else
    {
        cv::putText(imgFrame2Copy, CAR_ISNT, ptTextBottomLeftPosition, intFontFace, dblFontScale, SCALAR_WHITE, intFontThickness);
    }
    
}






