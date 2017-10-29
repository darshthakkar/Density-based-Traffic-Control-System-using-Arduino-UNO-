

int one = A0; 
int two = A1;
int three = A2;
int four = A3;          //takes sensor inputs

int oneG = 2;
int oneY = 3;
int oneR = 4;
int twoG = 5;
int twoY = 6;
int twoR = 7;
int threeG = 8;
int threeY = 9;
int threeR = 10;
int fourG = 11;
int fourY = 12;
int fourR = 13;         //signal lights

//int one_value = 0;
//int two_value = 0;
//int three_value = 0;
//int four_value = 0;
int t =3;
int baseline = 100;
int baseline2 = 158;
int baseline3 = 140;
int p1 = 0;
int p2 = 0;
int p3 = 0;
int p4 = 0;

int pre1 = 0;
int pre2 = 0;
int pre3 = 0;
int pre4 = 0;

int max1=0;
int status1=0; //Check whether signal is on or off
int dum_max=0;

int g1=0;
int g2=0;
int g3=0;
int g4=0;

float one_count = 0;
float two_count = 0;
float three_count = 0;
float four_count = 0;

void setup() {
  pinMode(oneG,OUTPUT);
  pinMode(oneY,OUTPUT);
  pinMode(oneR,OUTPUT);
  pinMode(twoG,OUTPUT);
  pinMode(twoY,OUTPUT);
  pinMode(twoR,OUTPUT);
  pinMode(threeG,OUTPUT);
  pinMode(threeY,OUTPUT);
  pinMode(threeR,OUTPUT);
  pinMode(fourG,OUTPUT);
  pinMode(fourY,OUTPUT);
  pinMode(fourR,OUTPUT);
  
  
  
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  pre1 = analogRead(one);    
  pre2 = analogRead(two);
  pre3 = analogRead(three);
  pre4 = analogRead(four);

  if(p1>baseline && pre1<baseline && g1!=1)
  {
    one_count++;
  }
  p1 = pre1;
 
  if(p2>baseline && pre2<baseline && g2 !=1)
  {
    two_count++;
  }
  p2 = pre2;
 
  if(p3>baseline2 && pre3<baseline2 && g3!=1)
  {
    three_count++;
  }
  p3 = pre3;
 
  if(p4>baseline3 && pre4<baseline3 && g4!=1)
  {
    four_count++;
  }
  p4 = pre4; 
  
  if((one_count>=two_count) && (one_count>=three_count) && (one_count>=four_count))
    { max1=1;}
  else if((two_count>=three_count) && (two_count>=four_count) && (two_count>one_count))
    { max1=2;} 
  else if((three_count>=four_count) && (three_count>two_count) && (three_count>one_count))
    { max1=3;}
  else if((four_count>three_count) && (four_count>two_count) && (four_count>one_count))
    { max1=4;}
  
  if(status1==0)
      {  dum_max=max1;  }
    
  if((one_count<=0)&&(two_count<=0)&&(three_count<=0)&&(four_count<=0))
  {
      digitalWrite(oneG, LOW);
      digitalWrite(oneY, LOW);
      digitalWrite(oneR, LOW);
      digitalWrite(twoG, LOW);
      digitalWrite(twoY, LOW);
      digitalWrite(twoR, LOW);
      digitalWrite(threeG, LOW);
      digitalWrite(threeY, LOW);
      digitalWrite(threeR, LOW);
      digitalWrite(fourG, LOW);
      digitalWrite(fourY, LOW);
      digitalWrite(fourR, LOW);
  }
  else{
  
  if(dum_max==1)
  { status1=1;
    g1=1;
    digitalWrite(oneG, HIGH);
    digitalWrite(oneY, LOW);
    digitalWrite(oneR, LOW);
    
    if((two_count>=three_count) && (two_count>=four_count))
    {
      digitalWrite(twoG, LOW);
      digitalWrite(twoY, HIGH);
      digitalWrite(twoR, LOW);
      digitalWrite(threeG, LOW);
      digitalWrite(threeY, LOW);
      digitalWrite(threeR, HIGH);
      digitalWrite(fourG, LOW);
      digitalWrite(fourY, LOW);
      digitalWrite(fourR, HIGH);
    }
    else if((three_count>two_count) && (three_count>=four_count))
    {
      digitalWrite(twoG, LOW);
      digitalWrite(twoY, LOW);
      digitalWrite(twoR, HIGH);
      digitalWrite(threeG, LOW);
      digitalWrite(threeY, HIGH);
      digitalWrite(threeR, LOW);
      digitalWrite(fourG, LOW);
      digitalWrite(fourY, LOW);
      digitalWrite(fourR, HIGH);
    }
    else if((four_count>three_count) && (four_count>two_count))
    {
      digitalWrite(twoG, LOW);
      digitalWrite(twoY, LOW);
      digitalWrite(twoR, HIGH);
      digitalWrite(threeG, LOW);
      digitalWrite(threeY, LOW);
      digitalWrite(threeR, HIGH);
      digitalWrite(fourG, LOW);
      digitalWrite(fourY, HIGH);
      digitalWrite(fourR, LOW);
    }
    
    one_count = one_count - t*0.01;
    
    if(one_count<=0)
       {
         status1=0;
          g1=0;
       } 
  }
  
  
  else if(dum_max==2)
  { status1=1;
    g2=1;
    digitalWrite(twoG, HIGH);
    digitalWrite(twoY, LOW);
    digitalWrite(twoR, LOW);
    
    if((one_count>=three_count) && (one_count>four_count))
    {
      digitalWrite(oneG, LOW);
      digitalWrite(oneY, HIGH);
      digitalWrite(oneR, LOW);
      digitalWrite(threeG, LOW);
      digitalWrite(threeY, LOW);
      digitalWrite(threeR, HIGH);
      digitalWrite(fourG, LOW);
      digitalWrite(fourY, LOW);
      digitalWrite(fourR, HIGH);
    }
    else if((three_count>=four_count) && (three_count>one_count))
    {
      digitalWrite(oneG, LOW);
      digitalWrite(oneY, LOW);
      digitalWrite(oneR, HIGH);
      digitalWrite(threeG, LOW);
      digitalWrite(threeY, HIGH);
      digitalWrite(threeR, LOW);
      digitalWrite(fourG, LOW);
      digitalWrite(fourY, LOW);
      digitalWrite(fourR, HIGH);
    }
    else if((four_count>one_count) && (four_count>three_count))
    {
      digitalWrite(oneG, LOW);
      digitalWrite(oneY, LOW);
      digitalWrite(oneR, HIGH);
      digitalWrite(threeG, LOW);
      digitalWrite(threeY, LOW);
      digitalWrite(threeR, HIGH);
      digitalWrite(fourG, LOW);
      digitalWrite(fourY, HIGH);
      digitalWrite(fourR, LOW);
    }
    two_count = two_count - t*0.01;
    if(two_count<=0)
       {
         status1=0;
          g2=0;
       }
  }
  
  else if(dum_max==3)
  { status1=1;
    g3=1;
    digitalWrite(threeG, HIGH);
    digitalWrite(threeY, LOW);
    digitalWrite(threeR, LOW);
    
    if((one_count>=two_count) && (one_count>=four_count))
    {
      digitalWrite(twoG, LOW);
      digitalWrite(twoY, LOW);
      digitalWrite(twoR, HIGH);
      digitalWrite(oneG, LOW);
      digitalWrite(oneY, HIGH);
      digitalWrite(oneR, LOW);
      digitalWrite(fourG, LOW);
      digitalWrite(fourY, LOW);
      digitalWrite(fourR, HIGH);
    }
   else if((two_count>=four_count) && (two_count>one_count))
    {
      digitalWrite(twoG, LOW);
      digitalWrite(twoY, HIGH);
      digitalWrite(twoR, LOW);
      digitalWrite(oneG, LOW);
      digitalWrite(oneY, LOW);
      digitalWrite(oneR, HIGH);
      digitalWrite(fourG, LOW);
      digitalWrite(fourY, LOW);
      digitalWrite(fourR, HIGH);
    }
   else if((four_count>two_count) && (four_count>one_count))
    {
      digitalWrite(twoG, LOW);
      digitalWrite(twoY, LOW);
      digitalWrite(twoR, HIGH);
      digitalWrite(oneG, LOW);
      digitalWrite(oneY, LOW);
      digitalWrite(oneR, HIGH);
      digitalWrite(fourG, LOW);
      digitalWrite(fourY, HIGH);
      digitalWrite(fourR, LOW);
    }
   
    three_count = three_count - t*0.01;
    if(three_count<=0)
       {
         status1=0;
          g3=0;
       }  
  }
  
 else if(dum_max==4)
  { status1=1;
    g4=1;
    digitalWrite(fourG, HIGH);
    digitalWrite(fourY, LOW);
    digitalWrite(fourR, LOW);
    if((one_count>=two_count) && (one_count>=three_count))
    {
      digitalWrite(twoG, LOW);
      digitalWrite(twoY, LOW);
      digitalWrite(twoR, HIGH);
      digitalWrite(oneG, LOW);
      digitalWrite(oneY, HIGH);
      digitalWrite(oneR, LOW);
      digitalWrite(threeG, LOW);
      digitalWrite(threeY, LOW);
      digitalWrite(threeR, HIGH);
    }  
    else if((two_count>one_count) && (two_count>=three_count))
    {
      digitalWrite(twoG, LOW);
      digitalWrite(twoY, HIGH);
      digitalWrite(twoR, LOW);
      digitalWrite(oneG, LOW);
      digitalWrite(oneY, LOW);
      digitalWrite(oneR, HIGH);
      digitalWrite(threeG, LOW);
      digitalWrite(threeY, LOW);
      digitalWrite(threeR, HIGH);
    } 
    else if((three_count>two_count) && (three_count>one_count))
    {
      digitalWrite(twoG, LOW);
      digitalWrite(twoY, LOW);
      digitalWrite(twoR, HIGH);
      digitalWrite(oneG, LOW);
      digitalWrite(oneY, LOW);
      digitalWrite(oneR, HIGH);
      digitalWrite(threeG, LOW);
      digitalWrite(threeY, HIGH);
      digitalWrite(threeR, LOW);
    } 
    four_count = four_count - t*0.01;
    if(four_count<=0)
       {
         status1=0;
          g4=0;
       }
  }
  }
  Serial.print(pre1);
  Serial.print("\t");
  Serial.print(pre2);
  Serial.print("\t");
  Serial.print(pre3);
  Serial.print("\t");
  Serial.print(pre4);
  Serial.print("\t");
  Serial.print(one_count);
  Serial.print("\t");
  Serial.print(two_count);
  Serial.print("\t");
  Serial.print(three_count);
  Serial.print("\t");
  Serial.print(four_count);
  Serial.print("\n");
 
  delay(10);                  
}
