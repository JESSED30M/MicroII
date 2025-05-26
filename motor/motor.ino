const int pinIN1 = 4;   // Sentido horario
const int pinIN2 = 5;   // Sentido antihorario
const int pinENA = 6;   // PWM

int velocidad = 150;    // Velocidad por defecto

// --- FUNCIONES PARA CONTROLAR MOTOR ---

void giroHorario(int vel) {
  digitalWrite(pinIN1, HIGH);
  digitalWrite(pinIN2, LOW);
  analogWrite(pinENA, vel);
  Serial.print("Giro horario a velocidad: ");
  Serial.println(vel);
}

void giroAntiHorario(int vel) {
  digitalWrite(pinIN1, LOW);
  digitalWrite(pinIN2, HIGH);
  analogWrite(pinENA, vel);
  Serial.print("Giro antihorario a velocidad: ");
  Serial.println(vel);
}

void detenerMotor() {
  digitalWrite(pinIN1, LOW);
  digitalWrite(pinIN2, LOW);
  analogWrite(pinENA, 0);
  Serial.println("Motor detenido");
}

void setup() {
  pinMode(pinIN1, OUTPUT);
  pinMode(pinIN2, OUTPUT);
  pinMode(pinENA, OUTPUT);

  Serial.begin(9600);
  Serial.println("Iniciando motor");

  // --- ACTIVA SOLO UNA OPCIÓN A LA VEZ (descomenta para probar) ---
  
  //giroHorario(velocidad);         // <-- Giro horario
  giroAntiHorario(velocidad);   // <-- Giro antihorario
  //detenerMotor();                // <-- Detener motor
}

void loop() {
  // Puedes dejar vacío o agregar código adicional más adelante
}