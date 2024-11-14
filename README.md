# Taller de uso de EloquentTinyML en ESP-32

## Requisitos

- ESP-32
- Arduino IDE
- Google Colab

## Instrucciones

1. Es necesario abrir un nuevo proyecto en la plataforma [Google Colab](https://colab.research.google.com/).

2. Generar un nuevo cuaderno de Python en donde pegarán el dataset `sensor_dataset.csv`

3. Una vez cargado el dataset, se procederá con el entrenamiento del modelo en Google Colab corriendo los códigos que están en el archivo `eloquent.ipynb`

4. Una vez entrenado el modelo, se debe descargar el archivo `taller-eloquent.h` y cargarlo en el proyecto de Arduino IDE.

5. Al mismo tiempo, se debe crear un archivo `sensor_model.h` en donde deberán pegar el resultado obtenido de la última celda de código en el cuaderno de Google Colab.

```python
# Obteniendo el array C con xxd
# Install xxd if it is not available
!apt-get -qq install xxd
# Save the file as a C source file
!xxd -i moisture_sensor_model.tflite > sensor_model.cc
# Print the source file
!cat sensor_model.cc
```

## Arduino IDE

1. Se debe instalar la librería de EloquentTinyML la versión 0.0.5 de Simone Salerno.

2. Copiar el archivo `taller-eloquent.h` de este repositorio y pegarlo en la carpeta del proyecto de Arduino IDE.

3. Crear un nuevo archivo `sensor_model.h` dentro de este archivo se debe pegar el resultado obtenido del cuaderno de Google Colab de la celda: 

```python
from tinymlgen import port
# Convertir modelo en un array C
c_code = port(model, pretty_print=True)
print(c_code)
```

4. Una vez cargado el modelo en el archivo `sensor_model.h`, se debe cargar el código en la placa ESP-32.

5. Ya que se haya cargado el código en la placa, se debe abrir el monitor serial para ingresar valores de humedad y observar la predicción del modelo.