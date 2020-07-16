float ADC_VALUE1,volt1;
float ADC_VALUE2,volt2;
int flag=0; // to check the position of solar panel
#define LDR1 A0 //connect first LDR to A0 of arduino
#define LDR2 A1 //connect second LDR to A1 of arduino
void setup() 
{
  Serial.begin(9600);
  pinMode(2,INPUT_PULLUP); //initialization of ports
  pinMode(3,INPUT_PULLUP);
  pinMode(4,OUTPUT);//connect port 4 and 5 to Motor driver
  pinMode(5,OUTPUT);
}

void loop()
{
  ADC_VALUE1 = analogRead(LDR1);
  volt1 = (ADC_VALUE1*5)/1024; //conversion into Voltage 5 because Vcc=5 and 1024 beause 10 bit ADC
  ADC_VALUE2 = analogRead(LDR2);
  volt2 = (ADC_VALUE2*5)/1024;
  
  
  if (volt1<=1)
  {
   rotate_east(); 
    
  }
  else if(volt2<=1)
  {
   rotate_west(); 
  }
  else
  {
   middle(); 
  }
}


void rotate_east()
{
  if(flag==0)
  {
    Serial.print("panel is in east direction");
    flag=0;
  }
  else if(flag==1)
  {
    rotate_clock();
    Serial.println("panel is reaching east direction");
    delay(200);
    stop_motor();
    flag=0;
    Serial.println("panel reached east direction");
  }
  else if(flag==2)
  {
    rotate_clock();
    Serial.println("panel is reaching east direction");
    delay(400);
    stop_motor();
    flag=0;
    Serial.println("panel reached east direction");
    
  }
}  
void rotate_west()
{
  if(flag==2)
  {
    Serial.print("panel is in west direction");
    flag=2;
  }
  else if(flag==1)
  {
    rotate_anticlock();
    Serial.println("panel is reaching west direction");
    delay(200);
    stop_motor();
    flag=2;
    Serial.println("panel reached west direction");
  }
  else if(flag==0)
  {
    rotate_anticlock();
    Serial.println("panel is reaching west direction");
    delay(400);
    stop_motor();
    flag=2;
    Serial.println("panel reached west direction");
    
  }
}    
void middle()
{
  if(flag==1)
  {
    Serial.print("panel is in centre");
    flag=1;
  }
  else if(flag==0
  )
  {
    rotate_anticlock();
    Serial.println("panel is reaching east direction");
    delay(200);
    stop_motor();
    flag=1;
    Serial.println("panel reached east direction");
  }
  else if(flag==2)
  {
    rotate_clock();
    Serial.println("panel is reaching west direction");
    delay(200);
    stop_motor();
    flag=1;
    Serial.println("panel reached west direction");
    
  } 
  
}

void rotate_clock()
{
  digitalWrite(4,1);
  digitalWrite(5,0);
}
  
void rotate_anticlock()
{
  digitalWrite(4,0);
  digitalWrite(5,1);
  
}
void stop_motor()
{
  digitalWrite(4,0);
  digitalWrite(5,0);
}
