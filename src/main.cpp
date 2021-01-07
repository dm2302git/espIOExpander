#include <Arduino.h>
#include <MCP23017.h>

#define MCP23017_ADDR 0x20
#define INT_PIN 3

MCP23017 mcp = MCP23017(MCP23017_ADDR);

void setup() {
    Wire.begin();
	Wire.begin(4,5); //SDA = GPIO4 / SCL = GPIO5
    mcp.init();

    Serial.begin(9200);

    mcp.portMode(MCP23017Port::A, 0b11111111);          //Port A as input rechts
    mcp.portMode(MCP23017Port::B, 0); 					//Port B as output links
    mcp.writeRegister(MCP23017Register::IPOL_A, 0x00); 	// Reset Port A
    mcp.writeRegister(MCP23017Register::IPOL_B, 0x00);	// Reset Port B

	//mcp.pinMode(0, INPUT);
  //GPIO Wemos
    pinMode(2, OUTPUT);  // LED = GPIO2 / use the p13 LED as debugging
	pinMode(16, OUTPUT); // D0 = GPIO16 / Test Relay intern
} 
void loop(){

	  // The LED will 'echo' the button
  	digitalWrite(0, mcp.digitalRead(0));
	
	digitalWrite(16, true);
	mcp.digitalWrite(8,1);

  	delay(1000); 

	digitalWrite(16, false);
  	mcp.digitalWrite(8,0);

   	delay(1000); 
	   if (mcp.digitalRead(0)) 
	   {
		   mcp.digitalWrite(9,1);
	   }
	   else
	   {
		   mcp.digitalWrite(9,0);
	   }
	   
	   
  /*
  myMCP.setPin(1,B,ON); 
  delay(1000); 
  myMCP.setPin(1,A,OFF); 
  delay(1000); 
  myMCP.setPin(1,B,OFF); 
  delay(1000); 
  myMCP.setPort(B10101010,B00011000); 
  delay(1000); 
  for(int i=0; i<=7; i++){ 
    myMCP.togglePin(i,A); 
  } 
  delay(1000); 
  myMCP.setPort(B00000000, A); 
  myMCP.setPort(B00000000, B); 
  delay(1000); 
  */
}