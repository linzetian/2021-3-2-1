//图像混合（用addWeighted）（两幅图大小，类型要一样）
#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

int main()
{
	Mat src1, src2,dst;
	src1 = imread("F:/image/1.6.png");
	src2 = imread("F:/image/1.4.png");
	if (!src1.data||!src2.data)
	{
		printf("can not load iamge");
		return -1;
	}
	namedWindow("input1", WINDOW_AUTOSIZE);
	imshow("input1",src1);
	namedWindow("input2", WINDOW_AUTOSIZE);
	imshow("input2", src2);
	double alpla = 0.5;
	if (src1.rows == src2.rows && src1.cols == src2.cols && src1.type() == src2.type())
	{
		addWeighted(src1,alpla, src2,1.0-alpla,0.0, dst);
	}
	else
	{
		printf("the size of two picture is not same\n");
	}
	namedWindow("mixture", WINDOW_AUTOSIZE);
	imshow("mixture", dst);
	waitKey(2);
	return 0;
}