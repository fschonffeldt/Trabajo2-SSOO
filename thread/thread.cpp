#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <thread>

using namespace cv;
using namespace std;

const int MAX_THREADS = 8;  // Número máximo de hilos (ajusta según sea necesario)

void convertirGrisParalelo(Mat& image, int start_row, int end_row) {
    for (int r = start_row; r < end_row; ++r) {
        for (int c = 0; c < image.cols; ++c) {
            Vec3b pixel = image.at<Vec3b>(r, c);
            uchar gray = 0.299 * pixel[2] + 0.587 * pixel[1] + 0.114 * pixel[0];
            image.at<Vec3b>(r, c) = Vec3b(gray, gray, gray);
        }
    }
}

void procesarRango(Mat& image, int num_threads) {
    int rows = image.rows;
    int chunk_size = rows / num_threads;

    thread threads[MAX_THREADS];

    for (int i = 0; i < num_threads; ++i) {
        int start_row = i * chunk_size;
        int end_row = (i == num_threads - 1) ? rows : (i + 1) * chunk_size;

        threads[i] = thread(convertirGrisParalelo, ref(image), start_row, end_row);
    }

    for (int i = 0; i < num_threads; ++i) {
        threads[i].join();
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        cerr << "Uso: " << argv[0] << " <imagenEntrada> <nombreSalida> <numHilos>" << endl;
        return -1;
    }

    string inputImageName = argv[1];
    string outputImageName = argv[2];
    int num_threads = stoi(argv[3]);

    auto start_time = chrono::high_resolution_clock::now();

    Mat image = imread(inputImageName, IMREAD_COLOR);

    if (image.empty()) {
        cerr << "Error al cargar la imagen de entrada." << endl;
        return -1;
    }

    procesarRango(image, num_threads);

    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);

    imwrite(outputImageName, image);

	cout << fixed << setprecision(6);
	cout << "Tiempo total de ejecución: " << duration.count() / 1000.0 << " segundos" << endl;

    return 0;
}
