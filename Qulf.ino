#define RELAY_Man_Key 2 //relay pin
#define RELAY_Man_Led 3 //relay pin
#define RELAY_Man_Speaker 4 
#define RELAY_Woman_Key 5 //relay pin
#define RELAY_Woman_Led 6 //relay pin
#define RELAY_Woman_Speaker 7 
#define RELAY_Nogiron_Key 8 //relay pin
#define RELAY_Nogiron_Led 9 //relay pin
#define RELAY_Nogiron_Speaker 10 
#define Button_Man_KeyT 11 
#define Button_Woman_KeyT 12 
#define Button_Man_KeyI 13 
#define Button_Woman_KeyI 22 
#define Button_Nogiron_KeyT 24 
#define Button_Nogiron_KeyI 26 
#define ACCESS_DELAY 500
#define DENIED_DELAY 1000

bool ayolT;
bool ayolI;
bool erkakT;
bool erkakI;
bool nogironT;
bool nogironI;
bool sanagichA_bool;
bool boolSpkA;
bool sanagichE_bool;
bool boolSpkE;
bool sanagichN_bool;
bool boolSpkN;
int sanagichA;
int intSpkA;
int sanagichE;
int intSpkE;
int sanagichN;
int intSpkN;

void setup()
{ 
  ayolT = false;
  erkakT = false;
  ayolI = false;
  erkakI = false;
  nogironI = false;
  nogironT = false;
  sanagichA_bool = false;
  boolSpkA = false;
  sanagichE_bool = false;
  boolSpkE = false;
  sanagichN_bool = false;
  boolSpkN = false;
  sanagichA = 0;
  intSpkA = 0;
  sanagichE = 0;
  intSpkE = 0;
  sanagichN = 0;
  intSpkN = 0;
  Serial.begin(9600);

  pinMode(RELAY_Man_Key, OUTPUT);
  pinMode(RELAY_Man_Led, OUTPUT);
  pinMode(RELAY_Man_Speaker, OUTPUT);
  pinMode(RELAY_Woman_Key, OUTPUT);
  pinMode(RELAY_Woman_Led, OUTPUT);
  pinMode(RELAY_Woman_Speaker, OUTPUT);
  pinMode(RELAY_Nogiron_Key, OUTPUT);
  pinMode(RELAY_Nogiron_Led, OUTPUT);
  pinMode(RELAY_Nogiron_Speaker, OUTPUT);
  pinMode(Button_Man_KeyT, INPUT);
  pinMode(Button_Woman_KeyT, INPUT);
  pinMode(Button_Nogiron_KeyT, INPUT);
  pinMode(Button_Man_KeyI, INPUT);
  pinMode(Button_Woman_KeyI, INPUT);
  pinMode(Button_Nogiron_KeyI, INPUT);
  digitalWrite(RELAY_Man_Key, HIGH);
  digitalWrite(RELAY_Man_Speaker, HIGH);
  digitalWrite(RELAY_Man_Led, HIGH);
  digitalWrite(RELAY_Woman_Key, HIGH);
  digitalWrite(RELAY_Woman_Speaker, HIGH);
  digitalWrite(RELAY_Woman_Led, HIGH);
  digitalWrite(RELAY_Nogiron_Key, HIGH);
  digitalWrite(RELAY_Nogiron_Speaker, HIGH);
  digitalWrite(RELAY_Nogiron_Led, HIGH);
//  digitalWrite(7, HIGH);
}

void loop()
{
//  Serial.println(time_now_man);
  
    if(Serial.available()){
      char c = Serial.read();
      if(c == 'A' && ayolI == false)
      {
        ayolT = true;
      }

        if(c == 'E' && erkakI == false)
      {
        erkakT = true;
        
      }if(c == 'N' && nogironI == false)
      {
        nogironT = true;
      }
    }
    
           
//    int t = digitalRead(Button_Woman_KeyT);
//    Serial.println(t);
//    Serial.println(ayolT);
    delay(200);
      if(ayolT && (digitalRead(Button_Woman_KeyT) == 0) && ayolI == false){
        digitalWrite(RELAY_Woman_Key, LOW);
        delay(ACCESS_DELAY);
        digitalWrite(RELAY_Woman_Key, HIGH);
        ayolT = false;
        ayolI = true;

        digitalWrite(RELAY_Woman_Led, LOW);
        
        digitalWrite(RELAY_Woman_Speaker, LOW);
        boolSpkA = true;
        intSpkA = 0;
      }
      
//      int t1 = digitalRead(Button_Man_KeyT);
//      Serial.println(t1);
      if(erkakT && (digitalRead(Button_Man_KeyT) == 0) && erkakI == false){
        digitalWrite(RELAY_Man_Key, LOW);
        delay(ACCESS_DELAY);
        digitalWrite(RELAY_Man_Key, HIGH);
        erkakT = false;
        erkakI = true;
        
        digitalWrite(RELAY_Man_Led, LOW);
        
        digitalWrite(RELAY_Man_Speaker, LOW);
        boolSpkE = true;
        intSpkE = 0;
      }

      if(nogironT && (digitalRead(Button_Nogiron_KeyT) == 0) && nogironI == false){
        digitalWrite(RELAY_Nogiron_Key, LOW);
        delay(ACCESS_DELAY);
        digitalWrite(RELAY_Nogiron_Key, HIGH);
        nogironT = false;
        nogironI = true;
        
        digitalWrite(RELAY_Nogiron_Led, LOW);
        
        digitalWrite(RELAY_Nogiron_Speaker, LOW);
        boolSpkN = true;
        intSpkN = 0;
      }

      if(ayolI && digitalRead(Button_Woman_KeyI) == 0){
        digitalWrite(RELAY_Woman_Key, LOW);
        delay(ACCESS_DELAY);
        digitalWrite(RELAY_Woman_Key, HIGH);
        ayolI = false;

        sanagichA_bool = true;
        sanagichA = 0;
      }

//      Serial.println(digitalRead(Button_Man_KeyI));
      if(erkakI && digitalRead(Button_Man_KeyI) == 0){
        digitalWrite(RELAY_Man_Key, LOW);
        delay(ACCESS_DELAY);
        digitalWrite(RELAY_Man_Key, HIGH);
        erkakI = false;

        sanagichE_bool = true;
        sanagichE = 0;
      }

      if(nogironI && digitalRead(Button_Nogiron_KeyI) == 0){
        digitalWrite(RELAY_Nogiron_Key, LOW);
        delay(ACCESS_DELAY);
        digitalWrite(RELAY_Nogiron_Key, HIGH);
        nogironI = false;

        sanagichN_bool = true;
        sanagichN = 0;
      }

      if(sanagichA_bool){
        sanagichA++;
      }

      if(sanagichE_bool){
        sanagichE++;
      }

      if(sanagichN_bool){
        sanagichN++;
      }

      if(boolSpkE){
        intSpkE++;
      }

      if(boolSpkA){
        intSpkA++;
      }

      if(boolSpkN){
        intSpkN++;
      }
//      Serial.println(sanagichA);
      if(sanagichA >= 20){
        digitalWrite(RELAY_Woman_Led, HIGH);
        sanagichA = 0; 
        sanagichA_bool = false;       
      }

      if(sanagichE >= 20){
        digitalWrite(RELAY_Man_Led, HIGH);
        sanagichE = 0;   
        sanagichE_bool = false;      
      }

      if(sanagichN >= 20){
        digitalWrite(RELAY_Nogiron_Led, HIGH);
        sanagichN = 0;   
        sanagichN_bool = false;      
      }

      if(intSpkE >= 25){
        digitalWrite(RELAY_Man_Speaker, HIGH);
        intSpkE = 0;   
        boolSpkE = false;      
      }

      if(intSpkA >= 25){
        digitalWrite(RELAY_Woman_Speaker, HIGH);
        intSpkA = 0;   
        boolSpkA = false;      
      }

      if(intSpkN >= 25){
        digitalWrite(RELAY_Nogiron_Speaker, HIGH);
        intSpkN = 0;   
        boolSpkN = false;      
      }
}
