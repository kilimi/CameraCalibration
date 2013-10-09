#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <cstdio>
#include "CameraCalibrationClass.h"

#include <dirent.h>

using namespace cv;
using namespace std;

int main()
{
	char path[255] = "/home/lulu/cameraCalibration/";
	unsigned int sample_size = 300;
	Size boardSize(9, 6);
	vector<string> imagePath;
//	for (int i = 1; i < 15; i++ )
//	{
//		sprintf(dest, "%s%d.tiff", path, i);
//		cout<< dest<< endl;
//		imagePath.push_back(string(dest));
//	}

	DIR *dir;
	class dirent *ent;

	dir = opendir(path);
	string full_path;
	while ((ent = readdir(dir)) != NULL) {
		if(ent->d_type == DT_REG)
		{
			full_path = string(path);
			full_path.append(ent->d_name);

			imagePath.push_back(full_path);

			if(sample_size <= 0)
				break;

			--sample_size;
		}
	}

	CameraCalibrationClass cc = CameraCalibrationClass();
	int s  = cc.addChessboardPoints(imagePath, boardSize);
	cout << s << endl;
	double res = cc.calibrate(boardSize);

	cout << "Final re-proj error: "<< res << endl;
	waitKey(0);
	return 0;
}
