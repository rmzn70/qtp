// Simple Arduino sketch: blink built-in LED and print status over Serial.

const int LED_PIN = LED_BUILTIN;
const unsigned long BLINK_INTERVAL_MS = 500;

unsigned long lastToggleMs = 0;
bool ledState = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  Serial.begin(9600);
  while (!Serial) {
    ; // Wait for Serial on boards that require it.
  }

  Serial.println("Arduino sketch started.");
}

void loop() {
  const unsigned long now = millis();

  if (now - lastToggleMs >= BLINK_INTERVAL_MS) {
    lastToggleMs = now;
    ledState = !ledState;

    digitalWrite(LED_PIN, ledState ? HIGH : LOW);
    Serial.println(ledState ? "LED ON" : "LED OFF");
  }
}
