int xValue = 512, yValue = 512;
byte send_byte;                                   //Declare some global byte variables


void setup() {
  //pinMode(7, INPUT_PULLUP); //set pin 7 as an input and enable the internal pull-up resistor
  Serial.begin(38400);
}

void loop() {
  xValue = analogRead(A0); // read X axis value [0..1023]
  yValue = analogRead(A1); // read Y axis value [0..1023]
  send_byte = B00000000;                                            //Set the send_byte variable to 0
//Print values check if okay
//  Serial.print(xValue);
//  Serial.print(", ");
//  Serial.println(yValue);

  if(xValue < 300)send_byte |= B00000010;                  //If the variable received_data[0] is smaller then 80 set bit 0 of the send byte variable
  if(xValue > 700)send_byte |= B00000001;                 //If the variable received_data[0] is larger then 170 set bit 1 of the send byte variable
  if(yValue < 300)send_byte |= B00001000;                  //If the variable received_data[1] is smaller then 80 set bit 3 of the send byte variable
  if(yValue > 700)send_byte |= B00000100;                 //If the variable received_data[1] is larger then 170 set bit 2 of the send byte variable
  if(send_byte)Serial.print((char)send_byte);                       //Send the send_byte variable if it's value is larger then 0
  delay(40);                                                        //Create a 40 millisecond loop delay

}
