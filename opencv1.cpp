#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;
int main(int, char *argv[])
{
    Mat in_image, out_image;
    // Usage： <cmd> <file_in> <file_out>
    //读取原始图像
    in_image = imread(argv[1], IMREAD_UNCHANGED);
    if (in_image.empty()) {
        //检查是否读取图像
        cout << "Error! Input image cannot be read...\n";
        return -1;
    }
    //创建两个具有图像名称的窗口
    namedWindow(argv[1], WINDOW_AUTOSIZE);
    namedWindow(argv[2], WINDOW_AUTOSIZE>;
    //在之前创建的窗口中显示图片
    imshow(argv[1], in_image);
    cvtColor(in_image, out_image, COLOR BGR2GRAY);
    imshow(argv[2], in_image);
    cout << "Press any key to exit...\n";
    waitKey(); // Wait for key press
    //写入图像
    imwrite(argv[2], in_image);
    return 0；
}