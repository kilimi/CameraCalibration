#include <opencv2/opencv.hpp>
#include "CameraCalibrationClass.h"

using namespace cv;
using namespace std;

int main()
{

	Mat image = imread("/home/lulu/cameraCalibration/frame1.tiff");
	// output vectors of image points
	/*std::vector<cv::Point2f> imageCorners;
	// number of corners on the chessboard
	cv::Size boardSize(9, 6);
	// Get the chessboard corners
	bool found = findChessboardCorners(image, boardSize, imageCorners);
	drawChessboardCorners(image, boardSize, imageCorners, found); // corners have been found

	imshow("", image);
*/
	waitKey(0);
	return 0;
}
