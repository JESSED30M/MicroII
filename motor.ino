const int pinIN1 = 4;   // Sentido horario
const int pinIN2 = 5;   // Sentido antihorario
const int pinENA = 6;   // PWM

int velocidad = 255;    // Velocidad por defecto (máxima)
char comando;

void setup() {
  pinMode(pinIN1, OUTPUT);
  pinMode(pinIN2, OUTPUT);
  pinMode(pinENA, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Listo. Envia 'h' (horario), 'a' (antihorario), '0'–'9' (velocidad)");
}

void loop() {
  if (Serial.available() > 0) {
    comando = Serial.read();
    
    if (comando == 'h') {
      digitalWrite(pinIN1, HIGH);
      digitalWrite(pinIN2, LOW);
      Serial.println("Giro horario");
    } else if (comando == 'a') {
      digitalWrite(pinIN1, LOW);
      digitalWrite(pinIN2, HIGH);
      Serial.println("Giro antihorario");
    } else if (comando >= '0' && comando <= '9') {
      // Mapea '0'-'9' a 0–255
      velocidad = map(comando - '0', 0, 9, 0, 255);
      analogWrite(pinENA, velocidad);
      Serial.print("Velocidad ajustada a: ");
      Serial.println(velocidad);
    } else {
      Serial.println("Comando no válido");
    }
  }
}
