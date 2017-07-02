int triger=2;
int echo=3;
float duration;
int d;
char y;
void setup()
{
  pinMode(2,OUTPUT);
  pinMode(3,INPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  
  digitalWrite(triger,LOW);
  delayMicroseconds(2);
   digitalWrite(triger,HIGH);
   delayMicroseconds(10);
   digitalWrite(triger,LOW);
   duration=pulseIn(echo,HIGH);
  d=duration*0.017;
  delay(1000);
  Serial.print("AT\r\n");delay(100);
    Serial.print("AT+CMGF=1\r\n");delay(100);
    Serial.print("AT+CNMI=1,2,0,0,0\r\n");delay(100);
    Serial.print("AT+CMGS=\"8072084350\"\r\n");delay(100);
    if(d<5)
    {
    Serial.print("Parking space found nearby \r\n");delay(100);
    Serial.print(char(26));delay(100);
    }
    if(Serial.available()>0)
    {
      y=Serial.read();
    }
  if(y=='1')
  {
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  }
  if(y=='2')
  {
    digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(5,LOW);
  digitalWrite(4,LOW);
  }
  if(y=='3')
  {
    digitalWrite(6,LOW);
  digitalWrite(7,LOW);
   digitalWrite(5,LOW);
  digitalWrite(4,HIGH);
  }
   if(y=='4'||d<5)
  {
    digitalWrite(6,LOW);
  digitalWrite(7,LOW);
   digitalWrite(5,LOW);
  digitalWrite(4,LOW);
  }
   if(y=='5')
  {
    digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
   digitalWrite(5,HIGH);
  digitalWrite(4,LOW);
  }
 }
    
  
    
  
