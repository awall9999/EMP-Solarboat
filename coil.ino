// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 6, 11, 10, 9, 8);
int up = 14;   
int left = 15;
int right = 16;
int down = 17;
int ButtonD4 = 4;
int ButtonD5 = 5;
int ok = 12;
int LEDpin = 13; // onboard Led
int Pin1=2;
int Pin2=3;
int Pin3=18;
int Pin4=19;
int Analog1=20;
int Analog2=21;
int Counter=0;
int Turns=0;
int a=0; int c=0;

void setup() {
  // put your setup code here, to run once:
 // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Coil-O-Mat V1.0");
  delay (3000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Set=U/D Go=OK");
  lcd.setCursor(0, 1);
  lcd.print(0);
  
  pinMode(up, INPUT);
  pinMode(left, INPUT);
  pinMode(right, INPUT);
  pinMode(down, INPUT);
  pinMode(ButtonD4, INPUT);
  pinMode(ButtonD5, INPUT);
  pinMode(ok, INPUT);
  pinMode(Pin1, INPUT);
  digitalWrite(Pin1, HIGH);
  pinMode(Pin2, OUTPUT);
  
    
  pinMode(LEDpin, OUTPUT);
  digitalWrite(Pin2,LOW);
}

void disp2() {
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Coil Windings");
  lcd.setCursor(0, 1);  
  lcd.print(Counter); lcd.print("/");lcd.print(Turns);lcd.print(" Turns");
  }


void display() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Set=U/D Go=OK");
  lcd.setCursor(0, 1);
  lcd.print(Counter);

  }

void launch() {
  digitalWrite(LEDpin,HIGH);
  digitalWrite(Pin2,HIGH);
  while (Counter > 0) { 
  if (digitalRead(Pin1) == 0) {
                           Counter = Counter -1;
                           disp2();
                            
                           while (digitalRead(Pin1) == 0){} 
                           delay(200);
  }         
  }
  
  digitalWrite(LEDpin,LOW);
  digitalWrite(Pin2,LOW);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Coil Finished");
  delay(5000);
  display();
  
  }

void MotorStart() {
 lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Motor Start in:");
 while (c < 5000) {
 
 if (c < 1000) { lcd.setCursor(0, 1);lcd.print("5 sec.");}
  else if (c > 4000) { lcd.setCursor(0, 1);lcd.print("1 sec.");}
  else if (c > 3000) { lcd.setCursor(0, 1);lcd.print("2 sec.");}
  else if (c > 2000) { lcd.setCursor(0, 1);lcd.print("3 sec.");}
  else if (c > 1000) { lcd.setCursor(0, 1);lcd.print("4 sec.");}
  
 c=millis()-a;
 
 
 }
 
  
  }

void loop() {
  
  
  

  if (digitalRead(up) == 0) {
                           Counter = Counter +50;
                           display();
                           delay(300);                  
                           
                           
  }
else if (digitalRead(down) == 0) {
                           Counter = Counter -50;
                           if (Counter < 0) {Counter=0;} 
                           display();
                           delay(300);                       
}

else if (digitalRead(ButtonD4) == 0) {
                           Counter = Counter +500;
                           if (Counter < 0) {Counter=0;} 
                           display();
                           delay(300);                       
}
else if (digitalRead(ButtonD5) == 0) {
                           Counter = Counter +1000;
                           if (Counter < 0) {Counter=0;} 
                           display();
                           delay(300);                       
}

else if (digitalRead(ok) == 0) {
                           Turns = Counter;
                           a=millis();
                           c=millis()-a;
                           MotorStart();
                           disp2() ;
                           launch();
                           delay(300);              
                            
  }
  
  

}
