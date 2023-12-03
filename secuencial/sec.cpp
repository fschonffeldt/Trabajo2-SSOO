#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>

using namespace cv;
using namespace std;

int main() {
    // Solicitar al usuario la ruta de la imagen de entrada
    string inputName;
    getline(cin,inputName);
    Mat image = imread(inputName, IMREAD_COLOR);

    if (image.empty()) {
        cerr << "Error al cargar la imagen." << endl;
        return -1;
    }

    // Solicitar al usuario el nombre de la imagen de salida
    cout << "Ingrese el nombre de la imagen en escala de grises de salida (con extensión, por ejemplo, resultado.jpg): ";
    string outputName;
    getline(cin, outputName);

    // Medir el tiempo de ejecución
    auto start_time = chrono::high_resolution_clock::now();

    Mat grayImage;
    cvtColor(image, grayImage, COLOR_BGR2GRAY);

    // Medir el tiempo total
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);

    // Guardar la imagen en escala de grises
    imwrite(outputName, grayImage, {IMWRITE_JPEG_QUALITY, 95});

    cout << "Imagen en escala de grises guardada como: " << outputName << endl;
    cout << "Tiempo total de ejecución: " << duration.count() << " ms" << endl;

    return 0;
}
