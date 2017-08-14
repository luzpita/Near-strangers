

int trigPin = 4; // Pin disparador. Se puede usar otro pin digital
int echoPin = 3; // Pin eco. Se puede usar otro pin digital
long duracion;

void setup() {
  Serial.begin(4800); // Establece la velocidad de datos del puerto serie
  pinMode(trigPin, OUTPUT); // Establece pin como salida
  pinMode(echoPin, INPUT); // Establece pin como entrada
  digitalWrite(trigPin, LOW); // Pone el pin a un estado logico bajo
}
void loop() {

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duracion = pulseIn(echoPin, HIGH ); //Devuelve la longitud del pulso del pin Echo en us
  int distancia = duracion / 58;


if (distancia <= 100 && distancia >= 8){// si la distancia es mayor a 500cm o menor a 0cm
    Serial.println(distancia);           // envia el valor de la distancia por el puerto serial           // no mide nada
  } else { 
   Serial.println("a");   
  }

    delay(100);
  }


