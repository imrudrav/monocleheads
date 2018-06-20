//
//  main.cpp
//  Spaces.V1.0
//
//  Created by Tanner Orndorff on 9/14/17.
//  Copyright © 2017 Monocle Heads. All rights reserved.
//

// main.cpp

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include<iostream>

#include "Blob.hpp"

#define SHOW_STEPS // un-comment or comment this line to show steps or not

// global variables ///////////////////////////////////////////////////////////////////////////////
const cv::Scalar SCALAR_BLACK = cv::Scalar(0.0, 0.0, 0.0);
const cv::Scalar SCALAR_WHITE = cv::Scalar(255.0, 255.0, 255.0);
const cv::Scalar SCALAR_YELLOW = cv::Scalar(0.0, 255.0, 255.0);
const cv::Scalar SCALAR_GREEN = cv::Scalar(0.0, 200.0, 0.0);
const cv::Scalar SCALAR_RED = cv::Scalar(0.0, 0.0, 255.0);
const std::string CAR_IS = "Car is in Box";
const std::string CAR_ISNT = "No Car is in Box";

// function prototypes ////////////////////////////////////////////////////////////////////////////
void matchCurrentFrameBlobsToExistingBlobs(std::vector<Blob> &existingBlobs, std::vector<Blob> &currentFrameBlobs);
void addBlobToExistingBlobs(Blob &currentFrameBlob, std::vector<Blob> &existingBlobs, int &intIndex);
void addNewBlob(Blob &currentFrameBlob, std::vector<Blob> &existingBlobs);
double distanceBetweenPoints(cv::Point point1, cv::Point point2);
void drawAndShowContours(cv::Size imageSize, std::vector<std::vector<cv::Point> > contours, std::string strImageName);
void drawAndShowContours(cv::Size imageSize, std::vector<Blob> blobs, std::string strImageName);
bool checkIfBlobsCrossedTheLine(std::vector<Blob> &blobs, int &intHorizontalLinePosition, int &carCount);
void drawBlobInfoOnImage(std::vector<Blob> &blobs, cv::Mat &imgFrame2Copy);
void drawCarCountOnImage(int &carCount, cv::Mat &imgFrame2Copy);
void drawLaneStatusOnImage(bool &carIsInBox, cv::Mat &imgFrame2Copy);

///////////////////////////////////////////////////////////////////////////////////////////////////
int main(void) {
    
    cv::VideoCapture capVideo; //will use to open desired video
    
    cv::Mat imgFrame1; //first frame of the video
    cv::Mat imgFrame2; //second frame of the video
    
    std::vector<Blob> blobs; //vector of blob objects
    
    cv::Point crossingLine[2]; //array of points that designate the crossing line
    
    int carCount = 0; //count of cars that cross the line
    
    capVideo.open("/Users/tannerorndorff/Documents/Monocleheads/Projects/Spaces.V2.0/Spaces.V2.0/SurveillanceFeedParkingLot.mp4"); //opens desired video.
    
    if (!capVideo.isOpened()) {                                                 // if unable to open video file
        std::cout << "error reading video file" << std::endl << std::endl;      // show error message
        //_getch();                   // it may be necessary to change or remove this line if not using Windows
        return(0);                                                              // and exit program
    }
    
    if (capVideo.get(CV_CAP_PROP_FRAME_COUNT) < 2) {
        std::cout << "error: video file must have at least two frames";
        //_getch();                   // it may be necessary to change or remove this line if not using Windows
        return(0);
    }
    
    capVideo.read(imgFrame1); //if has at least 2 files, it will read the two first frames and store in these variables
    capVideo.read(imgFrame2);
    
    int intHorizontalLinePosition = (int)std::round((double)imgFrame1.rows * 0.25); //sets the crossing line position
    //create rectangle
    //create 2 point object
    cv::Point rect_point1;
    cv::Point rect_point2;
    
    rect_point1.x=530;//these points designate the location of the square that checks to see if cars are in them
    rect_point1.y=200;
    rect_point2.x=600;
    rect_point2.y=270;

    
    
    
    crossingLine[0].x = 0;
    crossingLine[0].y = intHorizontalLinePosition;
    
    crossingLine[1].x = imgFrame1.cols - 1;
    crossingLine[1].y = intHorizontalLinePosition;
    
    char chCheckForEscKey = 0; //variable to check to see if the user has exited the program with the escape key
    
    bool blnFirstFrame = true; //shows whether or not the first frame opened
    
    int frameCount = 2; //starting frame count before code is added to the video
    
    while (capVideo.isOpened() && chCheckForEscKey != 27) {//if the video is opened and the escape key is not hit
        
        std::vector<Blob> currentFrameBlobs; //vector of blobs on this current frame
        
        cv::Mat imgFrame1Copy = imgFrame1.clone(); //copys both of the image frames ????????? why
        cv::Mat imgFrame2Copy = imgFrame2.clone();
        
        cv::Mat imgDifference; //two more potential frames
        cv::Mat imgThresh;
        
        cv::cvtColor(imgFrame1Copy, imgFrame1Copy, CV_BGR2GRAY); //converts image copyies to grey scale
        cv::cvtColor(imgFrame2Copy, imgFrame2Copy, CV_BGR2GRAY);
        
        //cv::imshow("imgFrame1CopyPreBlur", imgFrame1Copy);
        
        cv::GaussianBlur(imgFrame1Copy, imgFrame1Copy, cv::Size(5, 5), 0); //smooths the images to reduce noise
        cv::GaussianBlur(imgFrame2Copy, imgFrame2Copy, cv::Size(5, 5), 0);
        
        //cv::imshow("imgFrame1CopyPostBlur", imgFrame1Copy);
        
        cv::absdiff(imgFrame1Copy, imgFrame2Copy, imgDifference);//finds the absolute difference between these two images and stores it in difference
        
        //cv::imshow("imgDifference", imgDifference);
        
        cv::threshold(imgDifference, imgThresh, 30, 255.0, CV_THRESH_BINARY);//if any pixel is above an intensity of 30, then it is set to 255(white)
    
        //cv::imshow("imgThresh", imgThresh);
        
        cv::Mat structuringElement3x3 = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3)); //creates image with  different size rectangles on them to dilate/erode the imgThresh
        cv::Mat structuringElement5x5 = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5));
        cv::Mat structuringElement7x7 = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(7, 7));
        cv::Mat structuringElement15x15 = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(15, 15));
        
        for (unsigned int i = 0; i < 2; i++) {
            cv::dilate(imgThresh, imgThresh, structuringElement5x5);
            cv::dilate(imgThresh, imgThresh, structuringElement5x5);
            cv::erode(imgThresh, imgThresh, structuringElement5x5);
        }
        
        cv::Mat imgThreshCopy = imgThresh.clone();
        
        //cv::imshow("imgThreshPostErodeandDilate", imgThreshCopy);
        
        std::vector<std::vector<cv::Point> > contours; //vector of vector of points
        
        cv::findContours(imgThreshCopy, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE); //finds contours and only returns the outer ones (parent contours) becuase of retr_external
        
        
        drawAndShowContours(imgThresh.size(), contours, "imgContours"); //draws contours onto image and shows it in a window
        
        std::vector<std::vector<cv::Point>> convexHulls(contours.size()); //creates another vector of vectors that is the same size as the contors(just as many blobs)
        
        for (unsigned int i = 0; i < contours.size(); i++) {
            cv::convexHull(contours[i], convexHulls[i]); //draws an image around all of the contours
        }
        
        drawAndShowContours(imgThresh.size(), convexHulls, "imgConvexHulls"); //draw convex hulls in its own window 
        
        for (auto &convexHull : convexHulls) {//for every convex hull in convex hulls
            Blob possibleBlob(convexHull); //check to see if this convex hull is a blob 
            
            if (possibleBlob.currentBoundingRect.area() > 400 &&//if its too big or too small it wont be a blob
                possibleBlob.dblCurrentAspectRatio > 0.2 &&
                possibleBlob.dblCurrentAspectRatio < 4.0 &&
                possibleBlob.currentBoundingRect.width > 30 &&
                possibleBlob.currentBoundingRect.height > 30 &&
                possibleBlob.dblCurrentDiagonalSize > 60.0 &&
                (cv::contourArea(possibleBlob.currentContour) / (double)possibleBlob.currentBoundingRect.area()) > 0.50) {
                currentFrameBlobs.push_back(possibleBlob);
            }
        }
        
        drawAndShowContours(imgThresh.size(), currentFrameBlobs, "imgCurrentFrameBlobs"); //shows those contours that have been made into blobs
        
        if (blnFirstFrame == true) {
            for (auto &currentFrameBlob : currentFrameBlobs) {//if its the first frame, then put currentframeblobs into blobs vector
                blobs.push_back(currentFrameBlob);
            }
        } else {
            matchCurrentFrameBlobsToExistingBlobs(blobs, currentFrameBlobs); //if not first frame, then match currentframeblobs to existing blobs
        }
        
        drawAndShowContours(imgThresh.size(), blobs, "imgBlobs");
        
        imgFrame2Copy = imgFrame2.clone();          // get another copy of frame 2 since we changed the previous frame 2 copy in the processing above
        
        drawBlobInfoOnImage(blobs, imgFrame2Copy); //draws blob info on image
        
        bool carIsInBox = checkIfBlobsCrossedTheLine(blobs, intHorizontalLinePosition, carCount);
        
        //bool blnAtLeastOneBlobCrossedTheLine = checkIfBlobsCrossedTheLine(blobs, intHorizontalLinePosition, carCount);
        
//        if (blnAtLeastOneBlobCrossedTheLine == true) {
//            cv::line(imgFrame2Copy, crossingLine[0], crossingLine[1], SCALAR_GREEN, 2);
//        }
//        else {
//            cv::line(imgFrame2Copy, crossingLine[0], crossingLine[1], SCALAR_RED, 2);
//            cv::rectangle(imgFrame2Copy, rect_point1, rect_point2, SCALAR_BLACK,2);
//        }
        
        //drawCarCountOnImage(carCount, imgFrame2Copy);
        cv::rectangle(imgFrame2Copy, rect_point1, rect_point2, SCALAR_BLACK,2);

        
        drawLaneStatusOnImage(carIsInBox, imgFrame2Copy);
        
        cv::imshow("imgFrame2Copy", imgFrame2Copy);
        
        //cv::waitKey(0);                 // uncomment this line to go frame by frame for debugging
        
        // now we prepare for the next iteration
        
        currentFrameBlobs.clear();
        
        imgFrame1 = imgFrame2.clone();           // move frame 1 up to where frame 2 is
        
        if ((capVideo.get(CV_CAP_PROP_POS_FRAMES) + 1) < capVideo.get(CV_CAP_PROP_FRAME_COUNT)) {
            capVideo.read(imgFrame2);
        }
        else {
            std::cout << "end of video\n";
            break;
        }
        
        blnFirstFrame = false;
        frameCount++;
        chCheckForEscKey = cv::waitKey(1);
    }
    
    if (chCheckForEscKey != 27) {               // if the user did not press esc (i.e. we reached the end of the video)
        cv::waitKey(0);                         // hold the windows open to allow the "end of video" message to show
    }
    // note that if the user did press esc, we don't need to hold the windows open, we can simply let the program end which will close the windows
    
    return(0);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void matchCurrentFrameBlobsToExistingBlobs(std::vector<Blob> &existingBlobs, std::vector<Blob> &currentFrameBlobs) {
    
    for (auto &existingBlob : existingBlobs) {
        
        existingBlob.blnCurrentMatchFoundOrNewBlob = false; //set all properties to false
        
        existingBlob.predictNextPosition(); //predict next position of each blob
    }
    
    for (auto &currentFrameBlob : currentFrameBlobs) {//for every current frame blobs in vector
        
        int intIndexOfLeastDistance = 0;
        double dblLeastDistance = 100000.0;
        
        for (unsigned int i = 0; i < existingBlobs.size(); i++) {//compare to all of the existing blobs
            
            if (existingBlobs[i].blnStillBeingTracked == true) {//if existing blob is being tracked
                
                double dblDistance = distanceBetweenPoints(currentFrameBlob.centerPositions.back(), existingBlobs[i].predictedNextPosition); //find distance between current and predicted of that existing one
                
                if (dblDistance < dblLeastDistance) {//if distance is less than the least distance
                    dblLeastDistance = dblDistance; //least distance is equal to distance
                    intIndexOfLeastDistance = i; //index is equal to i
                }
            }
        }
        
        if (dblLeastDistance < currentFrameBlob.dblCurrentDiagonalSize * 0.5) {//if its within half of a diagonal of the blob, then add it to existing
            addBlobToExistingBlobs(currentFrameBlob, existingBlobs, intIndexOfLeastDistance);
        }
        else {
            addNewBlob(currentFrameBlob, existingBlobs); //create a new blob
        }
        
    }
    
    for (auto &existingBlob : existingBlobs) { //for every exisitng blob
        
        if (existingBlob.blnCurrentMatchFoundOrNewBlob == false) {//if it has no pair, then increase the consecutive frames iwthout a match
            existingBlob.intNumOfConsecutiveFramesWithoutAMatch++;
        }
        
        if (existingBlob.intNumOfConsecutiveFramesWithoutAMatch >= 5) {//blob is no longer being tracked if not recognized within 5 frames
            existingBlob.blnStillBeingTracked = false;
        }
        
    }
    
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void addBlobToExistingBlobs(Blob &currentFrameBlob, std::vector<Blob> &existingBlobs, int &intIndex) {
    
    existingBlobs[intIndex].currentContour = currentFrameBlob.currentContour; //updates an existing blob with the current blob being passed
    existingBlobs[intIndex].currentBoundingRect = currentFrameBlob.currentBoundingRect;
    
    existingBlobs[intIndex].centerPositions.push_back(currentFrameBlob.centerPositions.back());
    
    existingBlobs[intIndex].dblCurrentDiagonalSize = currentFrameBlob.dblCurrentDiagonalSize;
    existingBlobs[intIndex].dblCurrentAspectRatio = currentFrameBlob.dblCurrentAspectRatio;
    
    existingBlobs[intIndex].blnStillBeingTracked = true;
    existingBlobs[intIndex].blnCurrentMatchFoundOrNewBlob = true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void addNewBlob(Blob &currentFrameBlob, std::vector<Blob> &existingBlobs) {
    
    currentFrameBlob.blnCurrentMatchFoundOrNewBlob = true; //adds new blob to the existing blobs vector
    
    existingBlobs.push_back(currentFrameBlob);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
double distanceBetweenPoints(cv::Point point1, cv::Point point2) {
    
    int intX = abs(point1.x - point2.x); //finds the distance between two points directly with pythagorean theorum
    int intY = abs(point1.y - point2.y);
    
    return(sqrt(pow(intX, 2) + pow(intY, 2)));
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void drawAndShowContours(cv::Size imageSize, std::vector<std::vector<cv::Point> > contours, std::string strImageName) {
    cv::Mat image(imageSize, CV_8UC3, SCALAR_BLACK); //creates black src image
    
    cv::drawContours(image, contours, -1, SCALAR_WHITE, -1); //negative parameter means that all contours are drawn in scalar white
    
    //cv::imshow(strImageName, image); //show the image
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void drawAndShowContours(cv::Size imageSize, std::vector<Blob> blobs, std::string strImageName) {
    
    cv::Mat image(imageSize, CV_8UC3, SCALAR_BLACK); //creates black src image
    
    std::vector<std::vector<cv::Point> > contours; //vector of vectors of points that contours can be stored in
    
    for (auto &blob : blobs) {
        if (blob.blnStillBeingTracked == true) {
            contours.push_back(blob.currentContour); //puts all the current blobs into the contours vector
        }
    }
    
    cv::drawContours(image, contours, -1, SCALAR_WHITE, -1); //draws the contors of the blobs in scalar white
    
    //cv::imshow(strImageName, image); //shows the image in a window
}

///////////////////////////////////////////////////////////////////////////////////////////////////
bool checkIfBlobsCrossedTheLine(std::vector<Blob> &blobs, int &intHorizontalLinePosition, int &carCount) {
    bool blnAtLeastOneBlobCrossedTheLine = false;
    
    for (auto blob : blobs) {
        
        if (blob.blnStillBeingTracked == true && blob.centerPositions.size() >= 2) {
            int prevFrameIndex = (int)blob.centerPositions.size() - 2;
            int currFrameIndex = (int)blob.centerPositions.size() - 1;
            
            if (blob.centerPositions[prevFrameIndex].y > 200 && blob.centerPositions[currFrameIndex].y <= 270 && blob.centerPositions[prevFrameIndex].x > 530 && blob.centerPositions[currFrameIndex].x <= 600) {
                carCount++;
                blnAtLeastOneBlobCrossedTheLine = true;
            }
        }
//        rect_point1.x=530;
//        rect_point1.y=200;
//        rect_point2.x=600;
//        rect_point2.y=270;
    }
    
    return blnAtLeastOneBlobCrossedTheLine;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void drawBlobInfoOnImage(std::vector<Blob> &blobs, cv::Mat &imgFrame2Copy) {
    
    for (unsigned int i = 0; i < blobs.size(); i++) {
        
        if (blobs[i].blnStillBeingTracked == true) {
            cv::rectangle(imgFrame2Copy, blobs[i].currentBoundingRect, SCALAR_RED, 2);
            
            int intFontFace = CV_FONT_HERSHEY_SIMPLEX;
            double dblFontScale = blobs[i].dblCurrentDiagonalSize / 60.0;
            int intFontThickness = (int)std::round(dblFontScale * 1.0);
            
            cv::putText(imgFrame2Copy, std::to_string(i), blobs[i].centerPositions.back(), intFontFace, dblFontScale, SCALAR_GREEN, intFontThickness);
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////
void drawCarCountOnImage(int &carCount, cv::Mat &imgFrame2Copy) {
    
    int intFontFace = CV_FONT_HERSHEY_SIMPLEX;
    double dblFontScale = (imgFrame2Copy.rows * imgFrame2Copy.cols) / 300000.0;
    int intFontThickness = (int)std::round(dblFontScale * 1.5);
    
    cv::Size textSize = cv::getTextSize(std::to_string(carCount), intFontFace, dblFontScale, intFontThickness, 0);
    
    cv::Point ptTextBottomLeftPosition;
    
    ptTextBottomLeftPosition.x = imgFrame2Copy.cols - 1 - (int)((double)textSize.width * 1.25);
    ptTextBottomLeftPosition.y = (int)((double)textSize.height * 1.25);
    
    cv::putText(imgFrame2Copy, std::to_string(carCount), ptTextBottomLeftPosition, intFontFace, dblFontScale, SCALAR_GREEN, intFontThickness);
    
}

///////////////////////////////////////////////////////////////////////////////////////////////////
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
        cv::putText(imgFrame2Copy, CAR_IS, ptTextBottomLeftPosition, intFontFace, dblFontScale, SCALAR_BLACK, intFontThickness);
    }
    else
    {
        cv::putText(imgFrame2Copy, CAR_ISNT, ptTextBottomLeftPosition, intFontFace, dblFontScale, SCALAR_BLACK, intFontThickness);
    }
    
}









