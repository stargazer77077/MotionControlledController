int detectButton() {
  int detected = 0;
  if (digitalRead(BUTTON_PIN) == LOW && millis() - lastPushed > 200) {
    lastPushed = millis();
    detected = 1;
  }
  return detected;
}