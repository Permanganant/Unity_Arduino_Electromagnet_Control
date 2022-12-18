// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;
// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;

// Motor C connections
int enC = 10;
int in5 = 12;
int in6 = 13;
// Motor D connections
int enD = 11;
int in7 = 2;
int in8 = 6;
int value = 0;
int q = -1;
int DERECE = 180;

char inChar;
int inByte;
String incomingByte; // for incoming serial data
int pitch = 0;
int yaw = 0;
int  check = -10;
void setup() {

  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(enC, OUTPUT);
  pinMode(enD, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  pinMode(in7, OUTPUT);
  pinMode(in8, OUTPUT);
  // Turn off motors - Initial state
  digitalWrite(in5, LOW); digitalWrite(in6, HIGH); //C
  digitalWrite(in7, HIGH); digitalWrite(in8, LOW); //D
  digitalWrite(in1, HIGH); digitalWrite(in2, LOW); //A
  digitalWrite(in3, LOW); digitalWrite(in4, HIGH); //B

}
void loop() {

  //motor_code();
  //q = serial_read(0);
  //q = q + 1;
  //delay(50);
  //if (q == DERECE) {
    //q = 0;
    //delay(5000);
  //}
//  digitalWrite(LED_BUILTIN, );
  //delay(1000);
  //Serial.print("Disarda");
  if (Serial.available()) {
    //digitalWrite(LED_BUILTIN, HIGH);
    //delay(1000);
    // read the incoming byte:
    //Serial.print("Icerde");
    incomingByte = Serial.readStringUntil('\n');
    //inByte = Serial.read();
    //inChar = inByte;
    //incomingByte+=inChar;
    //Serial.println(inChar);
    //char c = Serial.read();  //gets one byte from serial buffer
    //incomingByte += c; 
     //incomingByte = Serial.readString();
    //Serial.print("I received: ");
    //Serial.print(incomingByte);
    if ( incomingByte[0] == 'S' && incomingByte[7] == 'F') {
      //digitalWrite(LED_BUILTIN, LOW);   // turn the LED on 
      //delay(1000);        
      //Serial.print("Pitch ");
      pitch = 100 * String(incomingByte[1]).toInt() + 10 *  String(incomingByte[2]).toInt() + String(incomingByte[3]).toInt();
      //Serial.print(pitch);
      //Serial.print("Yaw ");
      yaw = 100 * String(incomingByte[4]).toInt() + 10 *  String(incomingByte[5]).toInt() + String(incomingByte[6]).toInt();
      //Serial.print(yaw);
      //Serial.println(incomingByte[1:3]);
    }
    //else{
      //digitalWrite(LED_BUILTIN, LOW);   // turn the LED on 
      //delay(500); 
      //}
    
  }
 
  
  
  q = yaw;
  if (q <= 90) {
    //Serial.print("Condition 1");
    value = q * 510 / 90;
    //Serial.print("Value 1:");
    //Serial.print(value);

    if (value <= 255) {
      analogWrite(enC, 255 - value);
      analogWrite(enD, 255 - value);
      

    }
    else {
      digitalWrite(in5, HIGH); digitalWrite(in6, LOW); //C
      digitalWrite(in7, LOW); digitalWrite(in8, HIGH); //D

      analogWrite(enC, value-255);
      analogWrite(enD, value-255);
      

    }
  }
  else if (q > 90 && q <= 180) {
    //Serial.print("Condition 2");
    value = (q - 90) * 510 / 90;
    //Serial.print("Value 2:");
    //Serial.print(value);
    if (value <= 255) {
      analogWrite(enA, 255 - value);
      analogWrite(enB, 255 - value);
      //check = q;


    }
    else {
      digitalWrite(in1, LOW); digitalWrite(in2, HIGH); //A
      digitalWrite(in3, HIGH); digitalWrite(in4, LOW); //B

      analogWrite(enA, value);
      analogWrite(enB, value);
      

    }
  }

  else if (q > 180 && q <= 270) {
    //Serial.print("Condition 3");
    value = (q - 180) * 510 / 90;
    //Serial.print("Value 3:");
    //Serial.print(value);
    if (value <= 255) {
      analogWrite(enC, 255 - value);
      analogWrite(enD, 255 - value);
      


    }
    else {
      digitalWrite(in5, LOW); digitalWrite(in6, HIGH); //C
      digitalWrite(in7, HIGH); digitalWrite(in8, LOW); //D

      analogWrite(enC, value - 255);
      analogWrite(enD, value - 255);
      

    }

  }

  else if (q > 270 && q <= 360) {
    //Serial.print("Condition 4");
    value = (q - 270) * 510 / 90;
    //Serial.print("Value 4:");
    //Serial.print(value);
    if (value <= 255) {
      analogWrite(enA, 255 - value);
      analogWrite(enB, 255 - value);
      


    }
    else {
      digitalWrite(in1, HIGH); digitalWrite(in2, LOW); //A
      digitalWrite(in3, LOW); digitalWrite(in4, HIGH); //B

      analogWrite(enA, value);
      analogWrite(enB, value);
      

    }

  }

}

int serial_read(int state) {
  // send data only when you receive data:
  if (Serial.available() > 0 ) {
    // read the incoming byte:

    incomingByte = Serial.readString();
    //Serial.print("I received: ");
    //Serial.print(incomingByte);
    if ( incomingByte[0] == 'S' && incomingByte[7] == 'F') {
      //Serial.print("Pitch ");
      pitch = 100 * String(incomingByte[1]).toInt() + 10 *  String(incomingByte[2]).toInt() + String(incomingByte[3]).toInt();
      //Serial.print(pitch);
      //Serial.print("Yaw ");
      yaw = 100 * String(incomingByte[4]).toInt() + 10 *  String(incomingByte[5]).toInt() + String(incomingByte[6]).toInt();
      //Serial.print(yaw);
      //Serial.println(incomingByte[1:3]);
    }
    // say what you got:


  }
  if (state == 1) {
    return pitch;
  }
  else {
    return yaw;
  }
}
