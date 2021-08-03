const uint8_t BTN_PIN = 2; 
const uint8_t LED_PIN = 13;
uint8_t tmp = A1;

//Creating two variables to store the inacive states of the button and the LED
uint8_t buttonPrevState = LOW;
uint8_t ledState = LOW;
int temp; // temperature global variable 

//Initial setup which runs one time whenever the arduino starting 
void setup()
{
  //Settung up the button pin which is pin 2 as an Input pin
  pinMode(BTN_PIN, INPUT_PULLUP);
  //Setting up the LED pin as an output pin 
  pinMode(tmp, INPUT);
  //Setting up the data transmission 
  Serial.begin(9600);
  //Attaching the interrupt for the button pin
  attachInterrupt(digitalPinToInterrupt(BTN_PIN),servR, CHANGE);
}

void loop() //This loop will be running for the whole time the device is on
  			//This will be paused by an interrupt and will stores the values from the interrupt with the use of global variables 
{
  if(temp >150){
    digitalWrite(13, HIGH); //turing and keeping the led on 
    //The led will be turned and stay on (by an interrupt) untill an analog value lower than 150 comes to the sensor
  }
  else{
    digitalWrite(13, LOW); // turning and keeping the led off
    //The led will be turned and stay off (by an interrupt) untill an analog value greater than 150 comes to the sensor
  }

  //delaying the the process 
  delay(500);
}
void servR(){
  temp = analogRead(tmp); //storing the analog sensory data from the temperature sensor 
  Serial.print("temperature:"); //setting up a string to print in the serial monitor 
  Serial.println(temp);
}
  