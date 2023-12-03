#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void convertToGrayscale(Mat& image) {
    for (int r = 0; r < image.rows; ++r) {
        for (int c = 0; c < image.cols; ++c) {
            Vec3b pixel = image.at<Vec3b>(r, c);
            uchar gray = 0.299 * pixel[2] + 0.587 * pixel[1] + 0.114 * pixel[0];
            image.at<Vec3b>(r, c) = Vec3b(gray, gray, gray);
        }
    }
}

int main() {
    Mat image = imread("imagenacolor.jpg", IMREAD_COLOR);

    if (image.empty()) {
        cerr << "Error al cargar la imagen." << endl;
        return -1;
    }

    convertToGrayscale(image);

    imwrite("resultado_secuencial.jpg", image);

    return 0;
}