#include <Servo.h>
#include <SoftwareSerial.h> 
#include <Wire.h>  //引用二個函式庫SoftwareSerial及Wire SoftwareSerial 
SoftwareSerial I2CBT(0,1); //定義PIN10及PIN11分別為藍芽的RX及TX腳位 
Servo myservo;

void setup() { 
  myservo.attach(9);//定義伺服馬達信號腳位
  I2CBT.begin(9600); //藍牙鮑率57600
} 

void loop() { 
  int  insize;//接收資料暫存
  while(1){ 
  if ((insize=(I2CBT.available()))>0)
  {  
    insize=I2CBT.read();
  }
  if(insize=='a'){
      myservo.write(160);//伺服馬達轉到160度(開門)
      delay(3000);//門開3秒
      insize=0;//清除暫存資料
      }
      else{
        myservo.write(1);//伺服馬達轉到1度(關門)
        } 
  }
}
