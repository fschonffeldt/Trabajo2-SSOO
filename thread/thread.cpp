#include <iostream>
#include <opencv2/opencv.hpp>
#include <thread>

using namespace cv;
using namespace std;

void convertToGrayscaleThread(Mat& image, int start_row, int end_row) {
    for (int r = start_row; r < end_row; ++r) {
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

    int num_threads = 4; // ajusta según sea necesario
    int rows_per_thread = image.rows / num_threads;
    vector<thread> threads;

    for (int i = 0; i < num_threads; ++i) {
        int start_row = i * rows_per_thread;
        int end_row = (i == num_threads - 1) ? image.rows : (i + 1) * rows_per_thread;
        threads.emplace_back(convertToGrayscaleThread, ref(image), start_row, end_row);
    }

    for (auto& t : threads) {
        t.join();
    }

    imwrite("resultado_thread.jpg", image);

    return 0;
}
