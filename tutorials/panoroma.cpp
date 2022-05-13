// CPP program to Stitch
// https://www.geeksforgeeks.org/stitching-input-images-panorama-using-opencv-c/
// input images (panorama) using OpenCV
#include <fstream>
#include <iostream>

// Include header files from OpenCV directory
// required to stitch images.
#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/stitching.hpp"

using namespace std;
using namespace cv;

// Define mode for stitching as panorama
// (One out of many functions of Stitcher)
Stitcher::Mode mode = Stitcher::PANORAMA;

// Array for pictures
vector<Mat> imgs;

int main(int argc, char *argv[]) {

    // Read the images
    // and push into the image array
    imgs.push_back(imread(samples::findFile(
        "/home/yizhouw/Repositories/opencv/Blender_Suzanne1.jpg")));
    imgs.push_back(imread(samples::findFile(
        "/home/yizhouw/Repositories/opencv/Blender_Suzanne2.jpg")));

    // Define object to store the stitched image
    Mat pano;

    // Create a Stitcher class object with mode panoroma
    Ptr<Stitcher> stitcher = Stitcher::create(mode);

    // Command to stitch all the images present in the image array
    Stitcher::Status status = stitcher->stitch(imgs, pano);

    if (status != Stitcher::OK) {
        // Check if images could not be stitched
        // status is OK if images are stitched successfully
        cout << "Can't stitch images\n";
        return -1;
    }

    // Store a new image stitched from the given
    // set of images as "result.jpg"
    imwrite("result.jpg", pano);

    // Show the result
    imshow("Result", pano);

    waitKey(0);
    return 0;
}