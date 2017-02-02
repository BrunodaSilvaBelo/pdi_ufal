/**
   \mainpage
   \brief
   \author Bruno da Silva Belo
   \see https://github.com/isocpp/CppCoreGuidelines
*/

#include <stdio.h>
#include <opencv2/opencv.hpp>

int main(int argc, char **argv) {
  // if (argc != 2) {
  //   printf("usage: pdi <image_path>\n");
  //   return -1;
  // }

  // auto image = cv::imread(argv[1], 1);

  // if (!image.data) {
  //   printf("No image data\n");
  //   return -1;
  // }

  // cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE);
  // cv::imshow("Display Image", image);
  // cv::waitKey(0);
  auto webcam{cv::VideoCapture(0)};
  if (!webcam.isOpened()) {
    printf("ERROR webcam\n");
    return -1;
  }
  // webcam.set(CV_CAP_PROP_FRAME_WIDTH , 352);
  // webcam.set(CV_CAP_PROP_FRAME_HEIGHT , 288);

  cv::Mat frame;
  for(;;) {
    webcam >> frame;
    cv::imshow("Frame", frame);
    if(cv::waitKey(5) > 0)
      break;
  }

  return 0;
}
