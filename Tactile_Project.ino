int motor1 = 5;
int motor2 = 6;
int motor3 = 10;
int motor4 = 11;
int incomingByte = 0;
void setup() {
  Serial.begin(9600);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);
  while(!Serial);
  
}

void loop() {

  int duration = 400;
  float soa = 0.32*duration + 47.3; // SOA = stimulus onset asynchrony
  if (Serial.available() ){
    incomingByte = Serial.read();
    if(incomingByte == '1'){
      //Downwards Apparent Tactile Motion on left side
      Serial.println("Downwards Apparent Tactile Motion on left side");
      digitalWrite(motor1,HIGH);
      delay(soa);
      digitalWrite(motor4,HIGH);
      delay(duration - soa);
      digitalWrite(motor1,LOW);
      delay(duration - soa);
      digitalWrite(motor4, LOW);
      incomingByte = 0;
    }

    if(incomingByte == '2'){
      //Upwards Apparent tactile Motion on left side
      Serial.println("Upwards Apparent Tactile Motion on left side");
      digitalWrite(motor4,HIGH);
      delay(soa);
      digitalWrite(motor1,HIGH);
      delay(duration - soa);
      digitalWrite(motor4,LOW);
      delay(duration - soa);
      digitalWrite(motor1, LOW);
      incomingByte = 0;
    }

    if(incomingByte == '3'){
      //Downwards Apparent tactile Motion on right side
      Serial.println("Downwards Apparent Tactile Motion on right side");
      digitalWrite(motor2,HIGH);
      delay(soa);
      digitalWrite(motor3,HIGH);
      delay(duration - soa);
      digitalWrite(motor2,LOW);
      delay(duration - soa);
      digitalWrite(motor3, LOW);
      incomingByte = 0;
    }

    if(incomingByte == '4'){
      //Upwards Apparent tactile Motion on right side
      Serial.println("Upwards Apparent Tactile Motion on right side");
      digitalWrite(motor3,HIGH);
      delay(soa);
      digitalWrite(motor2,HIGH);
      delay(duration - soa);
      digitalWrite(motor3,LOW);
      delay(duration - soa);
      digitalWrite(motor2, LOW);
      incomingByte = 0;
    }

    if(incomingByte == '5'){
      //This block makes a square motion, 4,1,2,3,4
      Serial.println("This block makes a square motion");
      duration = 250;
      soa = 0.32*duration + 47.3; //soa = 111.3
      digitalWrite(motor4, HIGH); // t = 0
      delay(soa);
      digitalWrite(motor1, HIGH); // t = 111.3; Motor4 = 111.3, Motor1 = 0
      delay(duration - soa);
      digitalWrite(motor4, LOW); // t = 200; Motor4 = 200, Motor1 = 88.7
      delay(soa - (duration - soa));
      digitalWrite(motor2,HIGH); // t = 222.6; Motor1 = 111.3, Motor2 = 0;
      delay(duration - soa);
      digitalWrite(motor1,LOW);// t = 311.3; Motor1 = 200; Motor2 = 88.7
      delay(soa - (duration - soa));
      digitalWrite(motor3,HIGH);// t = 333.9; Motor2 = 111.3; Motor3 = 0
      delay(duration - soa);
      digitalWrite(motor2,LOW);//  Motor2 = 200; Motor3 = 88.7
      delay(soa - (duration - soa));
      digitalWrite(motor4,HIGH);// Motor3 = 111.3; Motor4 = 0
      delay(duration - soa);
      digitalWrite(motor3, LOW);// Motor3 = 200; Motor4 = 88.7
      delay(duration - soa);
      digitalWrite(motor4, LOW);
      delay(1000);
      duration = 500;
      soa = 0.32*duration + 47.3;
      incomingByte = 0;
      }

      if(incomingByte == '6'){
      //Phantom illusion on left side
      Serial.println("Phantom illusion on left side in middle");
      digitalWrite(motor1,HIGH);
      digitalWrite(motor4,HIGH);
      delay(2000);
      digitalWrite(motor1,LOW);
      digitalWrite(motor4, LOW);
      incomingByte = 0;
    }

    if(incomingByte == '7'){
      //Phantom illusion on right side
      Serial.println("Phantom illusion on right side in middle");
      digitalWrite(motor2,HIGH);
      digitalWrite(motor3,HIGH);
      delay(2000);
      digitalWrite(motor2,LOW);
      digitalWrite(motor3, LOW);
      incomingByte = 0;
    }

     if(incomingByte == '8'){
      //Phantom illusion on right side
      Serial.println("Phantom illusion closer to upper motor on right side ");
      analogWrite(motor2,191);
      analogWrite(motor3,64);
      delay(2000);
      analogWrite(motor2,0);
      analogWrite(motor3, 0);
      incomingByte = 0;
    }

    if(incomingByte == '9'){
      //Phantom illusion on right side
      Serial.println("Phantom illusion closer to lower motor on right side ");
      analogWrite(motor2,64);
      analogWrite(motor3,191);
      delay(2000);
      analogWrite(motor2,0);
      analogWrite(motor3, 0);
      incomingByte = 0;
    }
    }
  }
  


