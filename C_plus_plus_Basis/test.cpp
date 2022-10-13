#include<iostream>
#include<opencv2\opencv.hpp>
using namespace std;
using namespace cv;
 
//void
//{
 
        //定义需要修改的变量
	int eigenNum = 2;   //特征向量数目
	int trainNum = 200; //训练样本数目
	int testNum = 200;  //测试样本数目
	int nrows = 112, ncols = 92; //样本大小
	string trainPath = "F:\\机器学习\\DataSet\\facetrain\\"; //训练样本存储路径
	string testPath = "F:\\机器学习\\DataSet\\facetest\\";  //测试样本存储路径
 
	//定义程序所需变量
	string samplePath;//当前样本
	Mat srcSample;    //当前样本
	Mat sampleAve = Mat::zeros(nrows, ncols, CV_32FC1);//样本均值
	Mat covMatrix = Mat::zeros(ncols, ncols, CV_32FC1);//协方差矩阵
	Mat eigenVecs(ncols, eigenNum, CV_32FC1); //特征向量
	Mat eigenVals(eigenNum, 1, CV_32FC1);     //特征值
	vector<Mat> trainSamples; //存储训练样本
           //加载图像，计算均值(图像ID号从1开始)
	for (int i = 1; i <= trainNum; i++)
	{
		samplePath = trainPath + to_string(static_cast<long long>(i)) + ".png";
		srcSample = imread(samplePath, 0);        //载入当前样本
		if (srcSample.empty())
		{
			cout << "图像不存在" << endl;
			return;
		}
		srcSample.convertTo(srcSample, CV_32FC1); //数据类型转换
		trainSamples.push_back(srcSample.clone());        //存储当前样本
		sampleAve += srcSample / double(trainNum);//计算样本均值
	}
            //计算协方差矩阵
	for (int i = 0; i < trainNum; i++)
	{
		srcSample = trainSamples[i] - sampleAve;//中心化处理
		covMatrix += srcSample.t()*srcSample/double(trainNum);//计算协方差矩阵
	}
            //计算特征向量和特征值
	Mat calcVecs, calcVals;
	eigen(covMatrix, calcVals, calcVecs);
	eigenVecs = (calcVecs.rowRange(0, eigenNum)).t();
	eigenVals = calcVals.rowRange(0, eigenNum);
 
	//保存特征向量
	CvMat storeMat;
	storeMat = eigenVecs;
	cvSave("eigenVecs.txt", &storeMat);
    	//特征提取图像重构
	samplePath = testPath + "2.png";
	srcSample = imread(samplePath,0);
	imshow("src", srcSample);
	srcSample.convertTo(srcSample, CV_32FC1);
	srcSample = srcSample - sampleAve;
	Mat feature = srcSample*eigenVecs;
	Mat reconImg = feature*eigenVecs.t() + sampleAve;
	normalize(reconImg, reconImg, 0, 255,CV_MINMAX, CV_8UC1);
	imshow("reconstruction", reconImg);
	samplePath = to_string(eigenNum) + ".png";
	imwrite(samplePath, reconImg);