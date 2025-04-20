
#define BOARD_LED 8

bool state = false;


void setup() 
{
  pinMode(BOARD_LED, OUTPUT);
}

void loop() 
{
  state = !state;
  digitalWrite(BOARD_LED, state);
  delay(2000U);
}
