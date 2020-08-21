// Static variables.

// 1 minute = 60000 milliseconds.
// 60 Minutes = 3,600,000 Milliseconds.

const int motorPin=8;
const int ledPin=LED_BUILTIN;
const int sensorPin=2;
const int runPumpTime=60000;

// dynamic variables.
int state = 0;

void setup()
{
  pinMode(motorPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);

  digitalWrite(ledPin, LOW);

  Serial.begin(9600);
  Serial.println("--- Start Water Level Monitoring ---");
  Serial.println();
}

void loop() {
  // read the state of the sensorPin value.
  state = digitalRead(sensorPin);

  if (state == HIGH) {
    Serial.println(state);
    awaitToRun(5000);
    runPump(10000);
  } else {
    digitalWrite(motorPin, LOW);
    digitalWrite(ledPin, LOW);
  }
}

void awaitToRun(int time) {
  Serial.println("waiting to run");
  delay(time);
}

void runPump(int time) {
  Serial.println("running");
  digitalWrite(motorPin, HIGH);
  digitalWrite(ledPin, HIGH);

  delay(time);

  Serial.println("stopped running");
}
