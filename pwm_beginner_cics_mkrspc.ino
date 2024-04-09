// Author:      Luke LaCasse
// Date:        April 18, 2024
// Title:       Implement PWM using built-in Arduino functions and RP2040 Microcontroller
// Description: Implement PWM on RP2040 in the Arduino IDE using the built-in Analog Functions. This sketch is intended
//              to be used with a discrete indicator LED (built-in or external).

#define LED_PIN LED_BUILTIN               // Pin Mapping for LED
#define PWM_MAX 255                       // Maximum value for PWM, value set by Arduino

uint8_t pwm_value;                        // Stores current PWM output value
bool    count_up;                         // Determines count direction

void setup() {
  Serial.begin(115200);                   // Initialize Serial Port
  while(!Serial);                         // Wait for Serial Port to Initialize
  Serial.println("Serial Port Opened!");

  pinMode(LED_PIN, OUTPUT);               // Set LED Pin as an OUTPUT
  pwm_value = 0;                          // Start LED in off state
  count_up = true;                        // Begin increasing LED PWM value when loop starts
}

void loop() {
  analogWrite(LED_PIN, pwm_value);
  
  // Determine count direction based on current PWM output value
  if(count_up){
    if(pwm_value < PWM_MAX){
      pwm_value++;
    }else{
      count_up = false;
    }
  }else{
    if(pwm_value > 0){
      pwm_value--;
    }else{
      count_up = true;
    }
  }

  delay(5);
}
