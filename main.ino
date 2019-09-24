
#include <SoftwareSerial.h>
#include <Key.h>
#include <Keypad.h>
#include <LiquidCrystal.h>


LiquidCrystal lcd(42,43,44,45,46,47);

const int trigPin[] = {3,5};
const int echoPin[] = {2,4} ;
long usvalue[2];
int distance[2];
int totTable=2;
int tabRem=2;
bool menu[]={true,true};
int i1,i2;
int T1=00,T2=0;

const byte ROWS=4;  
const byte COLS=3;
char keys[ROWS][COLS]={{'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'}};
byte rowPins[ROWS]={41,48,49,50};
byte colPins[COLS]={51,52,53};

Keypad keypad0=Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS) ;
SoftwareSerial BTserial(10,11);
int sensorPin=A0;
int sensorValue=0;

 char x[2];

//Keypad(makeKeymaps(userKeymap),row[],col[],ROWS,COLS);
const byte ROWS1=4;  // put your setup code here, to run once:
const byte COLS1=4;
char keys1[ROWS1][COLS1]={{'1','2','3','4'},{'5','6','7','8'},{'9','A','B','C'},{'D','E','F','G'}};
byte rowPins1[ROWS1]={22,23,24,25};
byte colPins1[COLS1]={8,9,12,13};
byte led[2]={30,31};

Keypad keypad1=Keypad(makeKeymap(keys1),rowPins1,colPins1,ROWS1,COLS1) ;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i=0; i<2; i++)
  {
    pinMode(trigPin[i], OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin[i], INPUT);
  }
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.setCursor(0,0);
  analogWrite(7,100);
  BTserial.begin(38400);
  for (int i=0; i<4; i++)
  {
    pinMode(rowPins[i],INPUT);
    if (i<3)
      pinMode(colPins[i],INPUT);
    pinMode(rowPins1[i],INPUT);
    pinMode(colPins1[i],INPUT);
  } 

}

void loop() {
  // put your main code here, to run repeatedly:
  tabRem=2;
  for (int i=0; i<2; i++)
  {
    menu[i]=true;
    digitalWrite(trigPin[i], LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin[i], HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin[i], LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    usvalue[i] = pulseIn(echoPin[i], HIGH);
    // Calculating the distance
    distance[i] = usvalue[i] * 0.034 / 2;
    // Prints the distance on the Serial Monitor
    Serial.print(i+1);
    Serial.print("Distance: ");
    Serial.println(distance[i]);
    if (distance[i]>10)
    {
      menu[i]=false;
      digitalWrite(led[i],HIGH);
    }
    else 
    {
      digitalWrite(led[i],LOW);
    }
    if (!menu[i])
    {
      tabRem--;
    }
  }
  for (int i=0; i<2; i++)
  {
    Serial.print(menu[i]);
  }
  char key=NO_KEY,key1=NO_KEY;

  if (!menu[0])
  {
    key =keypad0.getKey();
  }
  if (!menu[1])
  {
    key1 = keypad1.getKey();
  }
  Serial.print(key);
  Serial.print('\n');
  Serial.print(key1);
  Serial.print('\n');
    if(key!=NO_KEY)
    {
      BTserial.write("Table 1\n");
      if (key=='1')
      BTserial.write("chicken butter masala\n");
      else if (key=='2')
      BTserial.write("chicken roasted\n");
      else if (key=='3')
      BTserial.write("paav bhaji\n");
      else if (key=='4')
      BTserial.write("chicken chilli\n");
      else if (key=='5')
      BTserial.write("chicken kebab\n");
      else if (key=='6')
      BTserial.write("rajma roti\n");
      else if (key=='7')
      BTserial.write("chicken chowmin\n");
      else if (key=='8')
      BTserial.write("Chole Bhature\n");
      /*else if (key=='9')
      BTserial.write("chicken do pyasa\n");
      */
      else if (key=='9')
      BTserial.write("CHICKEN DO Pyasa\n");
      else if (key=='*')
      BTserial.write("barbeque chicken\n");
      else if (key=='0')
      BTserial.write("Shahi Paneer\n");
      else if(key=='#')
      {
        BTserial.write("Table 1 Time:");
        String s="";
        while (!BTserial.available());
        if (BTserial.available())
        {
          Serial.println("Avlble");
          char c;
          c=BTserial.read();
          Serial.println(c);
          while (c!='m')
          {
            s+=c;
            while (!BTserial.available());
            if (BTserial.available())
            {
              c=BTserial.read();
              Serial.print("string:");
              Serial.println(s);
            }
          }
          T1=s.toInt();
          Serial.print("T1:");
          Serial.println(T1);
          i1=0;
      }
    }
    Serial.println(key);
    }
    
    if(key1!=NO_KEY)
    { 
      BTserial.write("Table 2\n");
      if (key1=='1')
      BTserial.write("chicken butter masala\n");
      else if (key1=='2')
      BTserial.write("chicken roasted\n");
      else if (key1=='3')
      BTserial.write("paav bhaji\n");
      else if (key1=='4')
      BTserial.write("chicken chilli\n");
      else if (key1=='5')
      BTserial.write("chicken kebab\n");
      else if (key1=='6')
      BTserial.write("rajma roti\n");
      else if (key1=='7')
      BTserial.write("chicken chowmin\n");
      else if (key1=='8')
      BTserial.write("Chole Bhatura\n");
      else if (key1=='9')
      BTserial.write("chicken do pyasa\n");
      else if (key1=='A')
      BTserial.write("MOTTON BIRYANI\n");
      else if (key1=='B')
      BTserial.write("CHICKEN SOUP\n");
      else if (key1=='C')
      BTserial.write("naan\n");
      else if (key1=='D')
      BTserial.write("afgan chicken\n");
      else if (key1=='E')
      BTserial.write("chaap\n");
      else if (key1=='F')
      BTserial.write("Shahi Paneer\n");
      /*else if (key1=='G')
      BTserial.write("kadhai chicken\n");*/
      else if(key1=='G')
      {
        BTserial.write("Table 2 Time:");
        String s="";
        while (!BTserial.available());
        if (BTserial.available())
        {
          Serial.println("Avlble");
          char c;
          c=BTserial.read();
          Serial.println(c);
          while (c!='m')
          {
            s+=c;
            while (!BTserial.available());
        if (BTserial.available())
        {
            c=BTserial.read();
            Serial.print("string:");
          Serial.println(s);
        }
          }
          T2=s.toInt();
          Serial.print("T2:");
        Serial.println(T2);
          i2=0;
        }
      }
      Serial.println(key1);
    }

    /*if(key=='#')
    {
      BTserial.write("Table 1 Time:");
      String s="";
      if (BTserial.available())
      {
        char c;
        while (c!='\n')
        {
          c=BTserial.read();
          s+=c;
        }
        T1=s.toInt();
        i1=0;
      }
    }*/

    
    
    lcd.setCursor(0,0);
    lcd.print("Table1:");
    lcd.setCursor(9,0);
    lcd.print(T1);
    lcd.setCursor(11,0);
    lcd.print("mins");
    lcd.setCursor(0,1);
    lcd.print("Table2:");
    lcd.setCursor(9,1);
    lcd.print(T2);
    lcd.setCursor(11,1);
    lcd.print("mins");

    if (i1!=0&&i1%60==0)
    {
      //lcd.clear();
      T1--;
    }
    if (i2!=0&&i2%60==0)
    {
      //lcd.clear(); 
      T2--;
    }
    if (T1>0)
    i1++;
    if (T2>0)
    i2++;
    delay(1000);
}
