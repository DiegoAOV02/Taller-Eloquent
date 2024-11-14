#include <EloquentTinyML.h>

// sensor_model.h contains the array you exported from the previous step with xxd or tinymlgen
#include "sensor_model.h"

#define NUMBER_OF_INPUTS 1
#define NUMBER_OF_OUTPUTS 1
#define TENSOR_ARENA_SIZE 2 * 1024

Eloquent::TinyML::TfLite<NUMBER_OF_INPUTS, NUMBER_OF_OUTPUTS, TENSOR_ARENA_SIZE> ml;

void setup() {
  Serial.begin(115200);
  Serial.println("Iniciando modelo");
  ml.begin(sensor_model);
  Serial.println("Modelo iniciado");
}

void loop() {

  if (Serial.available() > 0) {
    float x = Serial.parseFloat();
    Serial.println("Reading..");
    delay(2000);
    //float x = 35.22;
    float input[1] = { x };
    float predicted = ml.predict(input);
    Serial.print("X = ");
    Serial.print(x);
    Serial.print("\t predicted: ");
    Serial.println(predicted);
    if (predicted > 0.50) {
      Serial.print("\t There is moisture: ");
    } else {
      Serial.print("\t drain water: ");
    }
  }
}


/*

En caso de esperar multiples salidas del resultado del modelo, se debe declarar de la siguiente manera:

float input[10] = { ... };
float output[5] = { 0 };

ml.predict(input, output);
*/