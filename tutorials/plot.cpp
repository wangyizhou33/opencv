#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/plot.hpp>

int main() {

  cv::Mat xData, yData, display;
  cv::Ptr<cv::plot::Plot2d> plot;
  xData.create(1, 100, CV_64F); // 1 Row, 100 columns, Double
  yData.create(1, 100, CV_64F);

  for (double i = 0.; i < 100.; ++i) {
    xData.at<double>(i) = i / 10.0;
    yData.at<double>(i) = std::sin(i / 10);
  }

  plot = cv::plot::Plot2d::create(xData, yData);
  plot->setPlotBackgroundColor(cv::Scalar(255, 255, 255));
  plot->setPlotGridColor(cv::Scalar(0, 0, 0));
  plot->setPlotAxisColor(cv::Scalar(255, 0, 0)); // b,g,r,a
  plot->setPlotLineColor(cv::Scalar(0, 255, 0)); // b,g,r,a
  plot->setPlotTextColor(cv::Scalar(0, 0, 0));   // b,g,r,a
  plot->setPlotLineWidth(2);   // b,g,r,a

  plot->setPlotSize(300, 100);
  plot->setMaxX(20);
  plot->setMinX(-10);
  plot->setMaxY(2.);
  plot->setMinY(-2.);
  plot->render(display);

  imshow("Plot", display);
  cv::waitKey();

  // save plot to file
  std::vector<uchar> buf;
  cv::imencode(".jpg", display, buf); // can also be .png
  FILE *pFile;
  pFile = fopen("plot.jpg", "wb");
  fwrite(buf.data(), 1, buf.size() * sizeof(uchar), pFile);
  fclose(pFile);

  return 0;
}
