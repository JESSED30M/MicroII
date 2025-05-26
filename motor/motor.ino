const int pinIN1 = 4;   // Sentido horario
const int pinIN2 = 5;   // Sentido antihorario
const int pinENA = 6;   // PWM para velocidad

int velocidad = 255;    // Velocidad por defecto (máxima)

void setup() {
  pinMode(pinIN1, OUTPUT);
  pinMode(pinIN2, OUTPUT);
  pinMode(pinENA, OUTPUT);

  // ------------ CONFIGURA AQUÍ EL COMPORTAMIENTO DESEADO ------------
  
  ajustarVelocidad(150);  // Cambia valor entre 0 y 255
  giroHorario();          // O cambia por giroAntihorario();

  // -------------------------------------------------------------------
}

void loop() {
  // Aquí podrías agregar más lógica si quieres
}

// Función para girar en sentido horario
void giroHorario() {
  digitalWrite(pinIN1, HIGH);
  digitalWrite(pinIN2, LOW);
}

// Función para girar en sentido antihorario
void giroAntihorario() {
  digitalWrite(pinIN1, LOW);
  digitalWrite(pinIN2, HIGH);
}

// Función para ajustar la velocidad del motor
void ajustarVelocidad(int v) {
  velocidad = constrain(v, 0, 255); // Asegura que esté en el rango válido
  analogWrite(pinENA, velocidad);
}
