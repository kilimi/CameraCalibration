/*
 * CameraCalibrationClass.h
 *
 *  Created on: Oct 9, 2013
 *      Author: lulu
 */
#include <opencv2/opencv.hpp>

#ifndef CAMERACALIBRATIONCLASS_H_
#define CAMERACALIBRATIONCLASS_H_

using namespace std;
using namespace cv;

class CameraCalibrationClass {
public:
	virtual ~CameraCalibrationClass();
	CameraCalibrationClass() : flag(0), mustInitUndistort(true) {};
	int addChessboardPoints(const std::vector<std::string>& filelist, cv::Size & boardSize);
	void addPoints(const std::vector<cv::Point2f>& imageCorners, const std::vector<cv::Point3f>& objectCorners);
	double calibrate(cv::Size &);
private:
	// input points:
	vector<vector<Point3f> > objectPoints; // the points in world coordinates
	vector<vector<Point2f> > imagePoints; // the point positions in pixels
	cv::Mat cameraMatrix; // output Matrices
	cv::Mat distCoeffs;

	int flag;
	cv::Mat map1,map2; // used in image undistortion
	bool mustInitUndistort;
};

#endif /* CAMERACALIBRATIONCLASS_H_ */
