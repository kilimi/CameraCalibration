/*
 * CameraCalibrationClass.cpp
 *
 *  Created on: Oct 9, 2013
 *      Author: lulu
 */

#include "CameraCalibrationClass.h"
#include <stdio.h>

CameraCalibrationClass::~CameraCalibrationClass() {
	// TODO Auto-generated destructor stub
}

void CameraCalibrationClass::addPoints(const std::vector<cv::Point2f>& imageCorners,
		const std::vector<cv::Point3f>& objectCorners)
{
	imagePoints.push_back(imageCorners);
	objectPoints.push_back(objectCorners);
}

int CameraCalibrationClass::addChessboardPoints(const std::vector<std::string>& filelist, cv::Size & boardSize)
{
	std::vector<cv::Point2f> imageCorners;
	std::vector<cv::Point3f> objectCorners;

	for (int i=0; i<boardSize.height; i++) {
		for (int j=0; j<boardSize.width; j++) {
			objectCorners.push_back(cv::Point3f(i, j, 0.0f));
		}
	}
	cv::Mat image;
	int successes = 0;
	for (unsigned int i=0; i< filelist.size(); i++)
	{
		image = cv::imread(filelist[i],0);

		bool found = cv::findChessboardCorners(image, boardSize, imageCorners);
//		if (i == 100)
//		{
//			drawChessboardCorners(image, boardSize, imageCorners, found);
//			//imshow("corners", image);
//			imwrite("corners.png", image);
//			waitKey(0);
//		}

		cv::cornerSubPix(image, imageCorners, cv::Size(5,5), cv::Size(-1,-1),
				cv::TermCriteria(cv::TermCriteria::MAX_ITER + cv::TermCriteria::EPS, 30, 0.1));
		if (imageCorners.size() == boardSize.area())
		{
			addPoints(imageCorners, objectCorners);
			successes++;
		}
		else
		{
			cout << i << ": " << filelist[i] << endl;
			remove(filelist[i].c_str());
		}
	}
	return successes;
}

double CameraCalibrationClass::calibrate(cv::Size &imageSize)
{
	mustInitUndistort= true;
	std::vector<cv::Mat> rvecs, tvecs;
	double res = 	calibrateCamera(objectPoints, imagePoints, imageSize, cameraMatrix, distCoeffs, rvecs, tvecs, flag);
	cout  << cameraMatrix << endl;

	return res;

}
