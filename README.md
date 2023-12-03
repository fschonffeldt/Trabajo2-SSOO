## Introducción
Los siguientes 3 codigos estan creados en c++ linux,permiten transformar una imagen a color formato .jpg 
a una imagen en escalas de grises 

El codigo secuencial spermite transformar la imagen a escalas de grises analizando la matriz sin ninguna libreria o funcion disponible.

El codigo openMP  permite transformar la imagen a escala de grises a travez de un procesamiento en paralelo utilizando la libreria openMP.

El codigo thread  permite transformar la imagen a escala de grises a travez de un procesamiento en paralelo utilizando la libreria thread.

## Paso 1: clonar git

1. Abra su consola e inicie sesión en gitHub
2. Luego, para clonar el repositorio utilize el comando git clone y pegue el siguiente enlace https://github.com/fschonffeldt/Trabajo2-SSOO.git 

## Paso 2: Instalación de librerías
1. Una vez clonado el repositorio, debe instalar las siguientes librerías para la compilación de los programas.
2. Ingrese como administrador y ingrese el comando "apt install update".
3. Escriba en su consola el siguiente comando para instalar la librería Opencv "apt install opencv-data".
4. Luego escriba por consola "apt install python3.opencv", esta librería incluye todas las dependencias necesaria de Opencv.

## Paso 3: cambio de ubicación de la librería Opencv
1. Primero hay que encontrar la ubicación de a librería Opencv, para lograrlo lo hacemos con el siguiente comando "dpkg -L libopencv -dev | grep pkgconfig".
2. Esto dará 2 rutas, se debe copiar la segunda "/usr/lib/aarch64-linux-gnu/pkgconfig/opencv4.pc".
3. Copiamos la ruta y la ingresamos en el siguiente comando "export PKG_CONFIG_PATH=/usr/lib/x86_64-linux-gnu/pkgconfig/opencv4.pc:$PKG_CONFIG_PATH" (aquí el comando ya está con la ruta).
4. Para asegurar que fue exitoso el cambio de ubicación puedes ejecutar el siguiente comando "pkg config --cflags --libs opencv4" y deberían aparecer todas las librerías (-I/usr/include/opencv4 -lopencv_stitching -lopencv_alphamat -lopencv_aruco -lopencv_barcode -lopencv_bgsegm -lopencv_bioinspired -lopencv_ccalib -lopencv_dnn_objdetect -lopencv_dnn_superres -lopencv_dpm -lopencv_face -lopencv_freetype -lopencv_fuzzy -lopencv_hdf -lopencv_hfs -lopencv_img_hash -lopencv_intensity_transform -lopencv_line_descriptor -lopencv_mcc -lopencv_quality -lopencv_rapid -lopencv_reg -lopencv_rgbd -lopencv_saliency -lopencv_shape -lopencv_stereo -lopencv_structured_light -lopencv_phase_unwrapping -lopencv_superres -lopencv_optflow -lopencv_surface_matching -lopencv_tracking -lopencv_highgui -lopencv_datasets -lopencv_text -lopencv_plot -lopencv_ml -lopencv_videostab -lopencv_videoio -lopencv_viz -lopencv_wechat_qrcode -lopencv_ximgproc -lopencv_video -lopencv_xobjdetect -lopencv_objdetect -lopencv_calib3d -lopencv_imgcodecs -lopencv_features2d -lopencv_dnn -lopencv_flann -lopencv_xphoto -lopencv_photo -lopencv_imgproc -lopencv_core).
5. Si el comando no se ejecuta, escribe en la consola "apt install pkg-config" para que se descargue lo necesario para ejecutar el comando.

Con estos pasos tendrás instaladas todas las librerías y configuraciones necesarias para ejecutar los códigos.
