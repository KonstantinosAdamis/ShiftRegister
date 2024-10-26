// Define pins for the 74HC595N shift register
const int dataPin = 2;   // SER pin (Data Pin)
const int clockPin = 3;  // SRCLK pin (Clock Pin)
const int latchPin = 4;  // RCLK pin (Latch Pin)

void setup() {
  // Set pin modes
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);

  // Start with the output cleared (all LEDs off)
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, 0b0000); // Initialize with 0
  digitalWrite(latchPin, HIGH);
}

void loop() {
  // Count from 0 to 15 in binary
  // Send the count to the shift register
  for (int count = 0; count <= 15; count++){
    digitalWrite(latchPin, LOW);           // Prepare to shift out data
    shiftOut(dataPin, clockPin, MSBFIRST, count); // Shift out the binary value
    digitalWrite(latchPin, HIGH);          // Latch the data to output

    delay(2000);  // Wait 1 second before incrementing the count

  }
  
}