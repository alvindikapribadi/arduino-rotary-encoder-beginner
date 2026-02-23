/*
===========================================================
PROJECT TITLE  : Arduino Rotary Encoder Test
DESCRIPTION    :
This project demonstrates how to use a rotary encoder
as a digital input device with Arduino.

- Rotate clockwise  -> Counter increases
- Rotate counterclockwise -> Counter decreases
- Result is displayed on Serial Monitor

This example uses direct digital reading (no library)
so beginners can understand how rotary encoders work.

-----------------------------------------------------------
COMPONENT LIST :
1. Arduino Uno / Nano
2. Rotary Encoder Module (CLK, DT, SW, +, GND)
3. Jumper Wires
4. Breadboard (optional)

-----------------------------------------------------------
WIRING CONNECTION :

Rotary Encoder   ->   Arduino

CLK  ------------>   Pin 2
DT   ------------>   Pin 3
SW   ------------>   Pin 4 (Not used in this example)
+    ------------>   5V
GND  ------------>   GND

===========================================================
*/

#define CLK 2
#define DT  3

int counter = 0;
int currentStateCLK;
int lastStateCLK;

void setup() {

  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);

  Serial.begin(9600);

  // Read the initial state of CLK
  lastStateCLK = digitalRead(CLK);

  Serial.println("Rotary Encoder Test Started");
}

void loop() {

  // Read current CLK state
  currentStateCLK = digitalRead(CLK);

  // If the CLK state has changed
  if (currentStateCLK != lastStateCLK) {

    // Check rotation direction
    if (digitalRead(DT) != currentStateCLK) {
      counter++;  // Clockwise
      Serial.print("Direction: CW | Counter: ");
    } else {
      counter--;  // Counterclockwise
      Serial.print("Direction: CCW | Counter: ");
    }

    Serial.println(counter);
  }

  // Save last CLK state
  lastStateCLK = currentStateCLK;
}
