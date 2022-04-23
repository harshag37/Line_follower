#define ENA   14          // Enable/speed motors Right        GPIO14(D5)
#define ENB   12          // Enable/speed motors Left         GPIO12(D6)
#define INA1  15          // L298N in1 motors Right           GPIO13(D7)
#define INA2  13          // L298N in2 motors Right           GPIO15(D8)
#define INB1  0           // L298N in3 motors Left            GPIO0(D3)
#define INB2  2           // L298N in4 motors Left            GPIO2(D4)

#define IR1   9          // IR sensor input                   GPIO9(SD2)
#define IR2   10          // IR sensor input                  GPIO10(SD3)
#define IR3   16          // IR sensor input                  GPIO16(D0)
#define IR4   5          // IR sensor input                   GPIO5(D1)
#define IR5   4           // IR sensor input                  GPIO4(D2)

#define W 0
#define B 1

int ir1=0, ir2=0, ir3=0, ir4=0, ir5=0;
int speedCar = 240;         // 0-255
int speed_Coeff=1;

void setup() {
 
 pinMode(ENA, OUTPUT);
 pinMode(ENB, OUTPUT); 
 pinMode(INA1, OUTPUT);
 pinMode(INA2, OUTPUT);
 pinMode(INB1, OUTPUT);
 pinMode(INB2, OUTPUT); 
 
 pinMode(IR1, INPUT);
 pinMode(IR2, INPUT);
 pinMode(IR3, INPUT);
 pinMode(IR4, INPUT);
 pinMode(IR5, INPUT); 
 
}

void goAhead(){ 

      analogWrite(ENA, speedCar*speed_Coeff);    //enable(ENA) and speed 0-255
      analogWrite(ENB, speedCar*speed_Coeff);
      digitalWrite(INA1, LOW);
      digitalWrite(INA2, HIGH);

      digitalWrite(INB1, HIGH);
      digitalWrite(INB2, LOW);
      
  }

void goBack(){ 

      analogWrite(ENA, speedCar*speed_Coeff);    //enable(ENA) and speed 0-255
      analogWrite(ENB, speedCar*speed_Coeff);
      digitalWrite(INA1, HIGH);
      digitalWrite(INA2, LOW);
      digitalWrite(INB1, LOW);
      digitalWrite(INB2, HIGH);   
  }

void goRight(){ 

      analogWrite(ENA, speedCar*speed_Coeff);    //enable(ENA) and speed 0-255
      analogWrite(ENB, speedCar*speed_Coeff);
      digitalWrite(INA1, LOW);
      digitalWrite(INA2, LOW);  
      digitalWrite(INB1, HIGH);
      digitalWrite(INB2, LOW);
  }
void goSharpRight(){ 

      analogWrite(ENA, speedCar*speed_Coeff);    //enable(ENA) and speed 0-255
      analogWrite(ENB, speedCar*speed_Coeff);
      digitalWrite(INA1, HIGH);
      digitalWrite(INA2, LOW);  
      digitalWrite(INB1, HIGH);
      digitalWrite(INB2, LOW);
  }

void goLeft(){

      analogWrite(ENA, speedCar*speed_Coeff);    //enable(ENA) and speed 0-255
      analogWrite(ENB, speedCar*speed_Coeff);
      digitalWrite(INA1, LOW);
      digitalWrite(INA2, HIGH);
      digitalWrite(INB1, LOW); 
      digitalWrite(INB2, LOW);
}
void goSharpLeft(){

      analogWrite(ENA, speedCar*speed_Coeff);    //enable(ENA) and speed 0-255
      analogWrite(ENB, speedCar*speed_Coeff);
      digitalWrite(INA1, LOW);
      digitalWrite(INA2, HIGH);
      digitalWrite(INB1, LOW); 
      digitalWrite(INB2, HIGH);
}
void stopRobot(){  

      analogWrite(ENA, 0);    //enable(ENA) and speed 0-255
      analogWrite(ENB, 0);
 }
void make(int s1, int s2, int s3, int s4, int s5){
  ir1 = s1;
  ir2 = s2;
  ir3 = s3;
  ir4 = s4;
  ir5 = s5;
  
}
void loop() {
    ir1 = digitalRead(IR1);
    ir2 = digitalRead(IR2);
    ir3 = digitalRead(IR3);
    ir4 = digitalRead(IR4);
    ir5 = digitalRead(IR5);

    if(ir1 == B and ir2 == B and ir3 == W and ir4 == B and ir5 == B) goAhead();
    if(ir1 == B and ir2 == W and ir3 == W and ir4 == W and ir5 == B) goAhead();
    if(ir1 == W and ir2 == W and ir3 == W and ir4 == W and ir5 == W) goAhead();
    if(ir1 == W and ir2 == W and ir3 == B and ir4 == W and ir5 == W) goAhead();
    if(ir1 == W and ir2 == B and ir3 == B and ir4 == B and ir5 == W) goAhead();

    
    if(ir1 == W and ir2 == W and ir3 == B and ir4 == B and ir5 == B) goSharpLeft();
    if(ir1 == B and ir2 == W and ir3 == W and ir4 == B and ir5 == B) goLeft();
    if(ir1 == W and ir2 == B and ir3 == B and ir4 == B and ir5 == B) goSharpLeft();
    if(ir1 == W and ir2 == W and ir3 == W and ir4 == B and ir5 == B) goLeft();
    
    if(ir1 == B and ir2 == B and ir3 == W and ir4 == W and ir5 == W) goSharpRight();
    if(ir1 == B and ir2 == B and ir3 == W and ir4 == W and ir5 == B) goRight();
    if(ir1 == B and ir2 == B and ir3 == B and ir4 == W and ir5 == W) goSharpRight();
    if(ir1 == B and ir2 == B and ir3 == B and ir4 == B and ir5 == W) goRight();

    
    if(ir1 == B and ir2 == B and ir3 == B and ir4 == B and ir5 == B) goBack();
    
    
    

}
