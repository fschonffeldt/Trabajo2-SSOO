#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>

using namespace cv;
using namespace std;

void convertirGris(Mat& image) {
    for (int r = 0; r < image.rows; ++r) {
        for (int c = 0; c < image.cols; ++c) {
            Vec3b pixel = image.at<Vec3b>(r, c);
            uchar gray = 0.299 * pixel[2] + 0.587 * pixel[1] + 0.114 * pixel[0];
            image.at<Vec3b>(r, c) = Vec3b(gray, gray, gray);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Uso: " << argv[0] << " <imagenEntrada> <nombreSalida>" << endl;
        return -1;
    }

    string inputImageName = argv[1];
    string outputImageName = argv[2];

    auto start_time = chrono::high_resolution_clock::now();

    Mat image = imread(inputImageName, IMREAD_COLOR);

    if (image.empty()) {
        cerr << "Error al cargar la imagen de entrada." << endl;
        return -1;
    }

    convertirGris(image);

    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);

    imwrite(outputImageName, image);

	cout << fixed << setprecision(6);
	cout << "Tiempo total de ejecución: " << duration.count() / 1000.0 << " segundos" << endl;

    return 0;
}
