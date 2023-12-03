#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>

using namespace cv;
using namespace std;

// Función que convierte la imagen a escala de grises utilizando el método de luminosidad
void convertirGris(Mat& image) {
    for (int r = 0; r < image.rows; ++r) {
        for (int c = 0; c < image.cols; ++c) {
            // Obtiene el píxel en la posición (r, c)
            Vec3b pixel = image.at<Vec3b>(r, c);
            // Calcula el valor de gris utilizando el método de luminosidad
            uchar gray = 0.299 * pixel[2] + 0.587 * pixel[1] + 0.114 * pixel[0];
            // Asigna el valor de gris al píxel en la posición (r, c)
            image.at<Vec3b>(r, c) = Vec3b(gray, gray, gray);
        }
    }
}

int main(int argc, char *argv[]) {
    // Verifica que se proporcionen los argumentos correctos en la línea de comandos
    if (argc != 3) {
        cerr << "Uso: " << argv[0] << " <imagenEntrada> <nombreSalida>" << endl;
        return -1;
    }

    // Obtiene los nombres de los archivos de entrada y salida
    string inputImageName = argv[1];
    string outputImageName = argv[2];

    // Inicia el cronómetro para medir el tiempo de ejecución
    auto start_time = chrono::high_resolution_clock::now();

    // Lee la imagen de entrada en formato BGR
    Mat image = imread(inputImageName, IMREAD_COLOR);

    // Verifica si la imagen se cargó correctamente
    if (image.empty()) {
        cerr << "Error al cargar la imagen de entrada." << endl;
        return -1;
    }

    // Aplica la conversión a escala de grises a la imagen
    convertirGris(image);

    // Detiene el cronómetro al final de la ejecución
    auto end_time = chrono::high_resolution_clock::now();
    // Calcula la duración total de la ejecución
    auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);

    // Guarda la imagen resultante en escala de grises
    imwrite(outputImageName, image);

    // Muestra el tiempo total de ejecución en segundos
    cout << fixed << setprecision(6);
    cout << "Tiempo total de ejecución: " << duration.count() / 1000.0 << " segundos" << endl;

    return 0;
}
