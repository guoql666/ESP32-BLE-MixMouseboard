/**
 * This example turns the ESP32 into a Bluetooth LE keyboard that writes the words, presses Enter, presses a media key and then Ctrl+Alt+Delete
 */
#include <BleMouseboard.h>

BleMouseboard BleMouseboard;

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  BleMouseboard.begin();
}

void loop() {
  if(BleMouseboard.isConnected()) {
    
    Serial.println("Sending 'Hello world'...");
    BleMouseboard.print("Hello world");

    delay(1000);

    Serial.println("Sending Enter key...");
    BleMouseboard.writeKeyboard(KEY_RETURN);

    delay(1000);

    Serial.println("Sending Play/Pause media key...");
    BleMouseboard.writeKeyboard(KEY_MEDIA_PLAY_PAUSE);

    delay(1000);

   //
   // Below is an example of pressing multiple keyboard modifiers 
   // which by default is commented out.
    /*
    Serial.println("Sending Ctrl+Alt+Delete...");
    bleKeyboard.press(KEY_LEFT_CTRL);
    bleKeyboard.press(KEY_LEFT_ALT);
    bleKeyboard.press(KEY_DELETE);
    delay(100);
    bleKeyboard.releaseAll();
    */
  }

  Serial.println("Waiting 5 seconds...");
  delay(5000);
}
