
#define BOARD_LED 8

bool state = false;


void setup() 
{
  pinMode(BOARD_LED, OUTPUT);
  Serial.begin(115200);
}

void loop() 
{
  state = !state;
  digitalWrite(BOARD_LED, state);
  Serial.print("LED state : ");
  if(state)
    Serial.println("OFF");
  else
    Serial.println("ON");
  delay(2000U);
}
