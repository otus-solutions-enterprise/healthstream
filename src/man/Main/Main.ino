#define USE_ARDUINO_INTERRUPTS true    // Set-up low-level interrupts for most acurate BPM math.

int SERIAL_SPEED = 9600;

int PULSE_ANALOG_PIN = 0;
int PULSE_THRESHOLD_NOISE = 550;

void setup(){
    Serial.begin(SERIAL_SPEED);
    pinMode(10, INPUT); // Setup for leads off detection LO +
    pinMode(11, INPUT); // Setup for leads off detection LO -
  }

void loop(){
    post(readPulseSensor(), 0);
    post(readECGSensor(), 1);
  }

int readPulseSensor(){    
    int pulse = analogRead(PULSE_ANALOG_PIN);

    if(pulse > PULSE_THRESHOLD_NOISE){
        return pulse;
      }else{
        return pulse;
      }      
}

int readECGSensor(){    
   if((digitalRead(10) == 1)|| (digitalRead(11) == 1)){
      return 0;
   }else{    
      return analogRead(A1);
  }
}

int post(int value, int concat){
    if(concat == 0){
      Serial.print(value);
    }else{
      Serial.print(",");
      Serial.println(value);
    }
}
