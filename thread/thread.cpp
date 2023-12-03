#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <thread>

using namespace cv;
using namespace std;

// Número máximo de hilos (debe ser ajustado según el numero de nucleos del PC )
const int MAX_THREADS = 8;

// Función que convierte a escala de grises un rango de filas de la imagen
void convertirGrisParalelo(Mat& image, int start_row, int end_row) {
    // Itera sobre el rango de filas
    for (int r = start_row; r < end_row; ++r) {
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

// Función que divide la imagen en rangos y procesa cada rango en un hilo separado
void procesarRango(Mat& image, int num_threads) {
    int rows = image.rows;
    int chunk_size = rows / num_threads;

    // Arreglo de hilos
    thread threads[MAX_THREADS];

    // Crea y ejecuta hilos para procesar diferentes rangos de filas
    for (int i = 0; i < num_threads; ++i) {
        int start_row = i * chunk_size;
        int end_row = (i == num_threads - 1) ? rows : (i + 1) * chunk_size;

        // Cada hilo ejecuta la función convertirGrisParalelo
        threads[i] = thread(convertirGrisParalelo, ref(image), start_row, end_row);
    }

    // Espera a que todos los hilos terminen
    for (int i = 0; i < num_threads; ++i) {
        threads[i].join();
    }
}

int main(int argc, char *argv[]) {
    // Verifica que se proporcionen los argumentos correctos en la línea de comandos
    if (argc != 4) {
        cerr << "Uso: " << argv[0] << " <imagenEntrada> <nombreSalida> <numHilos>" << endl;
        return -1;
    }

    // Obtiene los nombres de los archivos de entrada y salida, así como el número de hilos
    string inputImageName = argv[1];
    string outputImageName = argv[2];
    int num_threads = stoi(argv[3]);

    // Inicia el cronómetro
    auto start_time = chrono::high_resolution_clock::now();

    // Lee la imagen de entrada
    Mat image = imread(inputImageName, IMREAD_COLOR);

    // Verifica si la imagen se cargó correctamente
    if (image.empty()) {
        cerr << "Error al cargar la imagen de entrada." << endl;
        return -1;
    }

    // Procesa la imagen dividiéndola en rangos y utilizando múltiples hilos
    procesarRango(image, num_threads);

    // Detiene el cronómetro
    auto end_time = chrono::high_resolution_clock::now();
    // Calcula la duración total
    auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);

    // Guarda la imagen de salida
    imwrite(outputImageName, image);

    // Muestra el tiempo total de ejecución en segundos 
    cout << fixed << setprecision(6);
    cout << "Tiempo total de ejecución: " << duration.count() / 1000.0 << " segundos" << endl;

    return 0;
}
