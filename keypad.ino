const int trigPin[] = {3,5};
const int echoPin[] = {2,4} ;
long usvalue[2];
int distance[2];
int totTable=2;
int tabRem=2;
bool menu[]={true,true};
int i1,i2;

const byte ROWS=4;  
const byte COLS=3;
char keys[ROWS][COLS]={{'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'}};
byte rowPins[ROWS]={48,49,50,51};
byte colPins[COLS]={52,53,41};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i=0; i<2; i++)
  {
    pinMode(trigPin[i], OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin[i], INPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i=0; i<2; i++)
  {
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
    delay(1000);
  }
  
}
