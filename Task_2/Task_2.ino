int buzzer =2;
int count=0;
int sensor1=A1;
int sensor2=A5;
int sensor1_value=0;
int sensor2_value=0;
void setup()
{
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(sensor1,INPUT);
  pinMode(sensor2,INPUT);
  Serial.begin(9600);
}
void tonning(){
  for(int i = 1000;i<10000;i+=1000)
  {
    tone(buzzer, i);
    delay(100);
  }
  for(int i = 10000;i>1000;i-=1000)
  {
    tone(buzzer, i);
    delay(100);
  }
}
void PersonInOut(int sensor,int val,int sign){
    if(sensor<val)
  {  
    delay(100);
    count+=sign;
  }
}
void loop()
{
  sensor1_value=analogRead(sensor1);
  sensor2_value=analogRead(sensor2);
  
  PersonInOut(sensor1_value,300,1);
  PersonInOut(sensor2_value,120,-1);
  
  if(count<0)
    count=0;
  if(count>6)
    count=6;
  if(count>5)
    {
      tonning();
      digitalWrite(LED_BUILTIN,HIGH);
    }
  else{
        digitalWrite(LED_BUILTIN,LOW);
        noTone(buzzer);
        }
    
    
  Serial.println("count:");
  Serial.println(count);
  Serial.println("sensor1_value");
  Serial.println(sensor1_value);
  Serial.println("sensor2_value");
  Serial.println(sensor2_value);
  delay(200);
}
