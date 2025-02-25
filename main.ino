#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Configuración del sensor ultrasonido
const int triggerPin = 26;
const int echoPin = 27;

// Configuración de los LEDs
const int ledVerde = 22;
const int ledAmarillo = 23;
const int ledRojo = 24;

// Configuración del buzzer
const int buzzer = 25;

// Configuración de la pantalla LCD I2C
LiquidCrystal_I2C lcd(0x27, 16, 2); // Sustituye 0x27 por la dirección que obtuviste en el escaneo I2C

// Variables para la distancia
long duracion;
float distancia;

void setup() {
  // Inicialización de los pines
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledRojo, OUTPUT);
  pinMode(buzzer, OUTPUT);

  // Inicialización de la pantalla LCD
  Wire.begin();       // Inicia comunicación I2C
  lcd.init();         // Inicializa la pantalla LCD
  lcd.backlight();    // Activa la luz de fondo
  lcd.print("Iniciando...");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Generar un pulso de disparo (trigger) de 10 microsegundos
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  // Calcular duración del pulso de retorno (echo)
  duracion = pulseIn(echoPin, HIGH, 30000); // Timeout de 30 ms para evitar lecturas incorrectas

  // Verificar si se recibió un pulso válido
  if (duracion > 0) {
    // Convertir duración a distancia en cm
    distancia = (duracion * 0.034) / 2;

    // Mostrar la distancia en la pantalla LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Distancia:");
    lcd.setCursor(0, 1);
    lcd.print(distancia);
    lcd.print(" cm");

    // Control de LEDs y buzzer basado en la distancia
    if (distancia > 8) {
      digitalWrite(ledVerde, HIGH);
      digitalWrite(ledAmarillo, LOW);
      digitalWrite(ledRojo, LOW);
      digitalWrite(buzzer, HIGH);
    } else if (distancia > 4 && distancia <= 8) {
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledAmarillo, HIGH);
      digitalWrite(ledRojo, LOW);

      // Activar buzzer por 1 segundo
      digitalWrite(buzzer, HIGH);
      delay(1000);
      digitalWrite(buzzer, LOW);
    } else if (distancia <= 4) {
      digitalWrite(ledVerde, LOW);
      digitalWrite(ledAmarillo, LOW);
      digitalWrite(ledRojo, HIGH);

      // Activar buzzer continuamente
      digitalWrite(buzzer, LOW);
    }
  } else {
    // Si no se recibe un pulso válido, mostrar un error en la pantalla
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Error: Sin eco");
    distancia = -1; // Indicar que no hay una medición válida
  }

  // Pequeño retraso para evitar interferencias
  delay(200);
}
