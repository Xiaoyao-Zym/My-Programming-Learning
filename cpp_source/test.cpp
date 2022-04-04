#include<iostream>
#include<opencv2\opencv.hpp>
using namespace std;
using namespace cv;
 
//void
//{
 
        //������Ҫ�޸ĵı���
	int eigenNum = 2;   //����������Ŀ
	int trainNum = 200; //ѵ��������Ŀ
	int testNum = 200;  //����������Ŀ
	int nrows = 112, ncols = 92; //������С
	string trainPath = "F:\\����ѧϰ\\DataSet\\facetrain\\"; //ѵ�������洢·��
	string testPath = "F:\\����ѧϰ\\DataSet\\facetest\\";  //���������洢·��
 
	//��������������
	string samplePath;//��ǰ����
	Mat srcSample;    //��ǰ����
	Mat sampleAve = Mat::zeros(nrows, ncols, CV_32FC1);//������ֵ
	Mat covMatrix = Mat::zeros(ncols, ncols, CV_32FC1);//Э�������
	Mat eigenVecs(ncols, eigenNum, CV_32FC1); //��������
	Mat eigenVals(eigenNum, 1, CV_32FC1);     //����ֵ
	vector<Mat> trainSamples; //�洢ѵ������
           //����ͼ�񣬼����ֵ(ͼ��ID�Ŵ�1��ʼ)
	for (int i = 1; i <= trainNum; i++)
	{
		samplePath = trainPath + to_string(static_cast<long long>(i)) + ".png";
		srcSample = imread(samplePath, 0);        //���뵱ǰ����
		if (srcSample.empty())
		{
			cout << "ͼ�񲻴���" << endl;
			return;
		}
		srcSample.convertTo(srcSample, CV_32FC1); //��������ת��
		trainSamples.push_back(srcSample.clone());        //�洢��ǰ����
		sampleAve += srcSample / double(trainNum);//����������ֵ
	}
            //����Э�������
	for (int i = 0; i < trainNum; i++)
	{
		srcSample = trainSamples[i] - sampleAve;//���Ļ�����
		covMatrix += srcSample.t()*srcSample/double(trainNum);//����Э�������
	}
            //������������������ֵ
	Mat calcVecs, calcVals;
	eigen(covMatrix, calcVals, calcVecs);
	eigenVecs = (calcVecs.rowRange(0, eigenNum)).t();
	eigenVals = calcVals.rowRange(0, eigenNum);
 
	//������������
	CvMat storeMat;
	storeMat = eigenVecs;
	cvSave("eigenVecs.txt", &storeMat);
    	//������ȡͼ���ع�
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