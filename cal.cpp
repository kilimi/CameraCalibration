#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <cstdio>
#include "CameraCalibrationClass.h"


using namespace cv;
using namespace std;

int main()
{
	char path[255] = "/home/lulu/cameraCalibration/frame";
	char dest[255];
	Size boardSize(9, 6);
	vector<string> imagePath;
	for (int i = 1; i < 15; i++ )
	{
		sprintf(dest, "%s%d.tiff", path, i);
		cout<< dest<< endl;
		imagePath.push_back(string(dest));
	}


	CameraCalibrationClass cc = CameraCalibrationClass();
	int s  = cc.addChessboardPoints(imagePath, boardSize);
	cout << s << endl;
	double res = cc.calibrate(boardSize);



	cout << "Final re-proj error: "<< res << endl;
	waitKey(0);
	return 0;
}
