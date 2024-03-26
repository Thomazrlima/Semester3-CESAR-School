const int botaoMoeda = 2;
const int pinoFlipFlop = 3;

int valorMoeda = 50;

int acumulado = 0;

void setup() {
  pinMode(botaoMoeda, INPUT);
  pinMode(pinoFlipFlop, OUTPUT);
  digitalWrite(pinoFlipFlop, LOW);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(botaoMoeda) == HIGH) {
    acumulado += valorMoeda;
    Serial.print("Valor acumulado: R$");
    Serial.println(acumulado / 100.0);
    delay(500);
  }

  if (acumulado >= 150) {
    digitalWrite(pinoFlipFlop, HIGH);
    Serial.println("Café liberado!");
    delay(2000);
    digitalWrite(pinoFlipFlop, LOW);
    acumulado -= 150;
    Serial.print("Troco: R$");
    Serial.println(acumulado / 100.0);
  }
}
