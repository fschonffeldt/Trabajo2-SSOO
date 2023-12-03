#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <omp.h>

using namespace cv;
using namespace std;

// Función que convierte la imagen a escala de grises utilizando OpenMP para paralelizar el bucle externo
void convertirGrisParaleloOpenMP(Mat& image) {
    // Directiva OpenMP para paralelizar el bucle externo (filas de la imagen)
    #pragma omp parallel for
    for (int r = 0; r < image.rows; ++r) {
        // Bucle interno que recorre las columnas de la imagen
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
    if (argc != 4) {
        cerr << "Uso: " << argv[0] << " <imagenEntrada> <nombreSalida> <numHilos>" << endl;
        return -1;
    }

    // Obtiene los nombres de los archivos de entrada y salida y el número de hilos
    string inputImageName = argv[1];
    string outputImageName = argv[2];
    int num_threads = stoi(argv[3]);

    // Inicia el cronómetro para medir el tiempo de ejecución
    auto start_time = chrono::high_resolution_clock::now();

    // Establece el número de hilos para OpenMP
    omp_set_num_threads(num_threads);

    // Lee la imagen de entrada en formato BGR
    Mat image = imread(inputImageName, IMREAD_COLOR);

    // Verifica si la imagen se cargó correctamente
    if (image.empty()) {
        // Intenta abrir desde el directorio actual si la ruta completa falla
        image = imread(string("./") + inputImageName, IMREAD_COLOR);

        if (image.empty()) {
            cerr << "Error al cargar la imagen de entrada: " << inputImageName << endl;
            return -1;
        }
    }

    // Aplica la conversión a escala de grises utilizando OpenMP
    convertirGrisParaleloOpenMP(image);

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
