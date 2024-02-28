const int trigPin = 8;
const int echoPin = 9;
const int ledPin = 7;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance < 600) { // Adjust this threshold according to your needs
    digitalWrite(ledPin, HIGH); // Turn on LED if obstacle is detected
  } else {
    digitalWrite(ledPin, LOW); // Turn off LED if no obstacle is detected
  }

  delay(100); // Wait for a short time before next reading
}
