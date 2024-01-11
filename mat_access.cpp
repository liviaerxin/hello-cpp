// C++ Program to access OpenCV mat pixel data
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main() {
  // Single Channel Pixel
  cv::Mat matF(3, 3, CV_32F);
  randu(matF, Scalar(0), Scalar(10));
  cout << matF.cols << "," << matF.step1() << "," << matF.elemSize1() << ","
       << matF.elemSize() << "," << matF.channels() << endl;

  int rowIdx = 1;
  int colIdx = 1;

  // 1.
  float f1 = matF.at<float>(rowIdx, colIdx);

  // 2.
  float *fData2 = (float *)matF.data;
  float f2 = fData2[rowIdx * matF.step1() + colIdx];

  // 3.
  float *fData3 = matF.ptr<float>(0);
  float f3 = fData3[rowIdx * matF.step1() + colIdx];

  // 4.
  float *fData4 = matF.ptr<float>(rowIdx);
  float f4 = fData4[colIdx];

  // 5.
  Mat1f mm(matF); // Or directly create like: Mat1f mm(3, 3);
  float f5 = mm(rowIdx, colIdx);

  // f1 == f2 == f3 == f4 == f5
  cout << "f1: " << f1 << endl;
  cout << "f2: " << f2 << endl;
  cout << "f3: " << f3 << endl;
  cout << "f4: " << f4 << endl;
  cout << "f5: " << f5 << endl;

  // 3-Channels Pixel
  cv::Mat bgrMat(3, 3, CV_8UC3);
  randu(bgrMat, Scalar(100, 100, 100), Scalar(110, 110, 110));

  cout << bgrMat.cols << "," << bgrMat.step1() << "," << bgrMat.elemSize1()
       << "," << bgrMat.elemSize() << "," << bgrMat.channels() << endl;

  // 1.
  cout << "1: " << endl;
  for (int i = 0; i < bgrMat.rows; i++) {
    for (int j = 0; j < bgrMat.cols; j++) {
      Vec3b bgrPixel = bgrMat.at<Vec3b>(i, j);
      cout << "Pixel at: [" << i << "," << j << "]: " << bgrPixel << endl;
      // do something with BGR values...
    }
  }

  // 2.
  cout << "2: " << endl;
  uint8_t *ptr = (uint8_t *)bgrMat.data;
  int channels = bgrMat.channels();
  Scalar_<uint8_t> bgrPixel;

  for (int i = 0; i < bgrMat.rows; i++) {
    for (int j = 0; j < bgrMat.cols; j++) {
      bgrPixel[0] = ptr[i * bgrMat.rows * channels + j * channels + 0]; // B
      bgrPixel[1] = ptr[i * bgrMat.rows * channels + j * channels + 1]; // B
      bgrPixel[2] = ptr[i * bgrMat.rows * channels + j * channels + 2]; // B
      cout << "Pixel at: [" << i << "," << j << "]: " << bgrPixel << endl;
      // do something with BGR values...
    }
  }

  // 3.
  cout << "3: " << endl;
  for (int i = 0; i < bgrMat.rows; i++) {
    uint8_t *rowPtr = (uint8_t *)bgrMat.row(i).data;
    for (int j = 0; j < bgrMat.cols; j++) {
      bgrPixel.val[0] = rowPtr[j * channels + 0]; // B
      bgrPixel.val[1] = rowPtr[j * channels + 1]; // G
      bgrPixel.val[2] = rowPtr[j * channels + 2]; // R
      cout << "Pixel at: [" << i << "," << j << "]: " << bgrPixel << endl;
      // do something with BGR values...
    }
  }

  return 0;
}