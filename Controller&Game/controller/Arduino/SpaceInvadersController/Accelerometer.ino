// ----------------------------------------------------------------------------------------------------
// =========== Accelerometer Sensor ============ 
// ----------------------------------------------------------------------------------------------------

/*
 * Configure the analog input pins to the accelerometer's 3 axes
 */
const int X_PIN = A4;
const int Y_PIN = A3;
const int Z_PIN = A2;

/*
 * Set the "zero" states when each axis is neutral
 * NOTE: Customize this for your accelerometer sensor!
 */
const int X_ZERO = 2300;
const int Y_ZERO = 1950;
const int Z_ZERO = 1950;


/*
 * Configure the analog pins to be treated as inputs by the MCU
 */
void setupAccelSensor() {
  pinMode(X_PIN, INPUT);
  pinMode(Y_PIN, INPUT);
  pinMode(Z_PIN, INPUT);
}

/*
 * Read a sample from the accelerometer's 3 axes
 */
void readAccelSensor() {
  ax = analogRead(X_PIN); 
  ay = analogRead(Y_PIN);
  az = analogRead(Z_PIN);
}

/*
 * Get the orientation of the accelerometer
 * Returns orientation as an integer:
 * 0 == flat
 * 1 == up
 * 2 == down
 * 3 == left
 * 4 == right
 */
int getOrientation() {
  int orientation = 0;

  // Subtract out the zeros
  int x = ax - X_ZERO;
  int y = ay - Y_ZERO;
  int z = az - Z_ZERO;


  Serial.print("ax: ");
  Serial.print(x);
  Serial.print(", ay: ");
  Serial.print(y);
  Serial.print(", az: ");
  Serial.println(z);
  

  // Use az to determine left or right
  if(abs(z) > 120 && abs(z) < 200) {
    if( z > 0 ) // left
      orientation = 3;
    else
      orientation = 4;
  }
  else if(abs(z) > 200) {
    if( z > 0 ) // very left
      orientation = 6;
    else
      orientation = 7;
  }
  // If ay has biggest magnitude, it's either up or down
  else if(abs(y) + 150 >= abs(x) && abs(y) >= abs(z) && abs(x) > 150) {
    if( y < 0 ) // up
      orientation = 1;
  }
  // If az biggest magnitude, it's flat (or upside-down)
  else if(abs(x) < 120 && abs(y) < 120 && abs(z) < 120) {
    orientation = 0; // flat
  }
  /*
  Serial.print("Orientation: ");
  Serial.println(orientation);
  */
  return orientation;
}
