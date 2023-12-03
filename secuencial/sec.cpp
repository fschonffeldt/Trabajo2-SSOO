#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>

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
    // Solicitar al usuario la ruta de la imagen de entrada
     string imagePath;
     getline(cin, imagePath);

    // Medir el tiempo de ejecución
    auto start_time = chrono::high_resolution_clock::now();

    Mat image = imread(imagePath, IMREAD_COLOR);

    if (image.empty()) {
        cerr << "Error al cargar la imagen." << endl;
        return -1;
    }

    convertToGrayscale(image);

    // Medir el tiempo total
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);

    imwrite("secuencial.jpg", image);

    cout << "Imagen en escala de grises guardada como: secuencial.jpg" << endl;
    cout << "Tiempo total de ejecución: " << duration.count() << " ms" << endl;

    return 0;
}

