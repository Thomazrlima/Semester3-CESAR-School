void decimalToBinary(int decimalNumber, int binaryArray[]) {
    int index = 0;
  
    while (decimalNumber > 0) {
        binaryArray[index++] = decimalNumber % 2;
        decimalNumber /= 2;
    }
  
    while (index < 4) {
        binaryArray[index++] = 0;
    }
}


void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int entrada = analogRead(A0) * 0.0293255;
  int saida[4];
  
  decimalToBinary(entrada, saida);

  if (((saida[3] == 1) && (saida[1] == 1)) || ((saida[3] == 1) && (saida[2] == 1))) {
    digitalWrite(9, HIGH);
  } else {
    digitalWrite(9, LOW);
  }
}