//! [includes]
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>

using namespace cv;
//! [includes]

int main()
{
    //! [imread]
    std::string image_path = samples::findFile("/home/yizhouw/Repositories/opencv/starry_night.jpg");
    Mat img = imread(image_path, IMREAD_COLOR);
    //! [imread]

    //! [empty]
    if(img.empty())
    {
        std::cout << "Could not read the image: " << image_path << std::endl;
        return 1;
    }
    //! [empty]

    //! [imshow]
    imshow("Display window", img);
    int k = waitKey(0); // Wait for a keystroke in the window
    //! [imshow]

    //! [imsave]
    if(k == 's')
    {
        imwrite("/home/yizhouw/Repositories/opencv/starry_night.png", img);
    }
    //! [imsave]

    //! convert cv mat to jpg or png
    std::vector <uchar> buf;
    cv::imencode(".jpg", img, buf);    // can also be .png
    FILE* pFile;
    pFile = fopen("file.jpg", "wb");
    fwrite(buf.data(), 1, buf.size()*sizeof(uchar), pFile);
    fclose(pFile);

    return 0;
}