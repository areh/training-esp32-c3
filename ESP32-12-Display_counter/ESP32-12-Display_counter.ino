/*
 * ESP32-12-Display_counter
 *
 * Count from 0 to 9999 and show it on the LED display
 *
 */

#include <GyverSegment.h> // For LED display (MAX7219)

#define DIO_PIN 10        // 7-segment MAX7219 - DIN pin (data)
#define CLK_PIN  6        // 7-segment MAX7219 - CLK pin
#define LAT_PIN  7        // 7-segment MAX7219 - CS pin

Disp7219<1> disp(DIO_PIN, CLK_PIN, LAT_PIN);    // Display object

int dispCounter;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("* * * * * * * * * * 7-segment display counter * * * * * * * * * *");
  disp.brightness(8);
  dispCounter = 0;
}//setup

void loop() {
  disp.clear();             // Clear display buffer
  disp.setCursorEnd();      // Set cursor at end (right hand side)
  disp.printRight(false);   // Print from the right
  disp.print(dispCounter);  // Print float (decimal) number
  disp.update();            // Update display to show content

  if (dispCounter >= 9999) {
    dispCounter = 0;
  } else {
    dispCounter++;
  }//if..else
  delay(10);
}//loop

//EOF
