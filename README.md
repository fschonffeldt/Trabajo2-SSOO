## Introducción
Los siguientes 3 codigos estan creados en c++ linux,permiten transformar una imagen a color formato .jpg 
a una imagen en escalas de grises 

El codigo secuencial spermite transformar la imagen a escalas de grises analizando la matriz sin ninguna libreria o funcion disponible.

El codigo openMP  permite transformar la imagen a escala de grises a travez de un procesamiento en paralelo utilizando la libreria openMP.

El codigo thread  permite transformar la imagen a escala de grises a travez de un procesamiento en paralelo utilizando la libreria thread.

## Paso 1: clonar git

1. Abra su consola e inicie sesion en gitHub
2. Luego, para clonar el repositorio utilize el comando git clone y pege el siguiente enlance https://github.com/fschonffeldt/Trabajo2-SSOO.git 

## Paso 2: Instalacion de librerias
1. Una vez clonado el repositorio, necesitara instalar las siguientes librerias para la compilacion de los programas
2. Ingrese como administrador y ingrese el comando apt install update
3. Escriba en su consola el siguiente comando para instalar la libreria Opencv apt install opencv-data
4. Luego escriba por consola apt install python3.opencv, esta libreria incluye todas las dependencias necesaria de Opencv

## Paso 3: cambio de ubicacion de la libreria Opencv

1. Primero hay que encontrar la ubicacion de a libreria Opencv, para lograrlo lo hacemos con el siguiente comando dpkg -L libopencv -dev | grep pkgconfig.
2. Esto dara 2 rutas y se eligira la segunda /usr/lib/aarch64-linux-gnu/pkgconfig/opencv4.pc
3. Copiamos esa ruta y la ingresamos en el siguiente comando export PKG_CONFIG_PATH=/usr/lib/aarch64-linux-gnu/pkgconfig/opencv4.pc
4. Para asegurar que fue exitoso el cambio de ubicacion puedes ejecutar el siguiente comando pkg config --cflags --libs opencv4:$PKG_CONFIG_PATH
5. Si el comando no ejecuta , instalar apt install pkg-config

Con estos pasos tendra instaladas todas las librerias y configuraciones necesarias para ejecutar los codigos.