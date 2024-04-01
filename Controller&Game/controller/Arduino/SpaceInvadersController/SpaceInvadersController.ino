/*
 * Global variables
 */
// Acceleration values recorded from the readAccelSensor() function
int ax = 0; int ay = 0; int az = 0;
int ppg = 0;        // PPG from readPhotoSensor() (in Photodetector tab)
int sampleTime = 0; // Time of last sample (in Sampling tab)
bool sending;

// Button Variales
unsigned long lastPushed = 0;                    
const int BUTTON_PIN = 14;

// LED Variables
unsigned long before_time = 0;
const int LED_PIN = 13;
int LED = LOW;
/*
 * Initialize the various components of the wearable
 */
void setup() {
  setupAccelSensor();
  setupCommunication();
  setupDisplay();
  setupPhotoSensor();
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  sending = false;

  Serial.begin(115200);

  writeDisplay("Ready...", 1, true);
  writeDisplay("Set...", 2, false);
  writeDisplay("Play!", 3, false);
}

/*
 * The main processing loop
 */
void loop() {
  // Parse command coming from Python (either "stop" or "start")
  String command = receiveMessage();
  if(command == "stop") {
    sending = false;
    writeDisplay("Controller: Off", 0, true);
  }
  else if(command == "start") {
    sending = true;
    writeDisplay("Controller: On", 0, true);
  }
  else if(command == "HIT") {
    before_time = millis();
    digitalWrite(LED_PIN, HIGH);
  }
  else if (command.indexOf("SCORE") >= 0){  
    writeDisplay(command.c_str(), 1, false);
  }

  if(millis() - before_time >= 1000){
    digitalWrite(LED_PIN, LOW); //Turn off LED
  }

  if(command != ""){
    Serial.print("Command");
    Serial.println(command);
  } 

  //sampleSensors();
  // Send the orientation of the board
  if(sending && sampleSensors()) {
  //if(sending){
    sendMessage(String(getOrientation()));
  }
  // If button is pressed, send message 2 ==> fire
  if (detectButton() == 1) {
    sendMessage("2");
  }

  if (ppg <= 5500) {
    sendMessage("5");
  }
  /*
  Serial.print("PPG: ");
  Serial.println(ppg);
  */
}
