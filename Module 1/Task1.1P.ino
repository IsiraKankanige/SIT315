//pin declaration for the led
uint8_t led = 13;
//pin declaration for the temperature sensor 
uint8_t tmp = A1;

int temp; // temperature global variable 

void setup()
{
  pinMode(tmp, INPUT); //Setting up the input variable of the circuit 
  pinMode(13, OUTPUT); //Setting up the output variable of the circuit
  Serial.begin(9600);
}

void loop()
{
  temp = analogRead(tmp); //storing the analog sensory data from the temperature sensor 
  Serial.print("temperature:"); //setting up a string to print in the serial monitor 
  Serial.println(temp); //printing out the temperature values to the serial monitor
  if(temp >150){
    digitalWrite(13, HIGH); //turing the led on 
  }
  else{
    digitalWrite(13, LOW); // turning led off
  }
  delay(100);
  
}