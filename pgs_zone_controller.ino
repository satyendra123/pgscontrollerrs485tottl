/*
#include <SoftwareSerial.h>

// Define the data packets
byte data_packets[][8] = {
  {0xAA, 0x05, 0x17, 0x03, 0x31, 0x39, 0x37, 0x8C},
  {0xAA, 0x05, 0x17, 0x03, 0x31, 0x35, 0x37, 0x8C},
  {0xAA, 0x05, 0x17, 0x03, 0x31, 0x39, 0x33, 0x8C},
  {0xAA, 0x05, 0x17, 0x03, 0x34, 0x39, 0x36, 0x8C},
  {0xAA, 0x05, 0x17, 0x03, 0x31, 0x39, 0x37, 0x8C},
  {0xAA, 0x05, 0x17, 0x03, 0x31, 0x38, 0x37, 0x8C},
  {0xAA, 0x05, 0x17, 0x03, 0x32, 0x35, 0x37, 0x8C},
  {0xAA, 0x05, 0x17, 0x03, 0x35, 0x39, 0x33, 0x8C},
  {0xAA, 0x05, 0x17, 0x03, 0x34, 0x39, 0x38, 0x8C},
  {0xAA, 0x05, 0x17, 0x03, 0x31, 0x39, 0x33, 0x8C}
};

// Define the number of data packets
#define NUM_PACKETS 10

// Define RS485 pin connections
#define RS485_RX 3
#define RS485_TX 2

// Initialize SoftwareSerial for RS485 communication
SoftwareSerial RS485Serial(RS485_RX, RS485_TX);

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  
  // Initialize RS485 communication
  RS485Serial.begin(9600);
}

void loop() {
  // Loop through the data packets and send them individually
  for (int i = 0; i < NUM_PACKETS; i++) {
    // Send the data packet
    for (int j = 0; j < 8; j++) {
      RS485Serial.write(data_packets[i][j]);
      Serial.print("0x");
      if (data_packets[i][j] < 0x10) {
        Serial.print("0");
      }
      Serial.print(data_packets[i][j], HEX);
      Serial.print(" ");
    }
    Serial.println(); // Print a new line after each packet is sent
    // Delay for 2 seconds between sending packets
    delay(2000);
  }
}
*/
//Example-2 send the request bytes and capture the response
#include <SoftwareSerial.h>

// Define the data packets
byte data_packets[][8] = {
  {0xAA, 0x05, 0x17, 0x03, 0x31, 0x39, 0x37, 0x8C},
  {0xAA, 0x05, 0x17, 0x03, 0x31, 0x35, 0x37, 0x8C},
  {0xAA, 0x05, 0x17, 0x03, 0x31, 0x39, 0x33, 0x8C},
  {0xAA, 0x05, 0x17, 0x03, 0x34, 0x39, 0x36, 0x8C},
  {0xAA, 0x05, 0x17, 0x03, 0x31, 0x39, 0x37, 0x8C},
  {0xAA, 0x05, 0x17, 0x03, 0x31, 0x38, 0x37, 0x8C},
  {0xAA, 0x05, 0x17, 0x03, 0x32, 0x35, 0x37, 0x8C},
  {0xAA, 0x05, 0x17, 0x03, 0x35, 0x39, 0x33, 0x8C},
  {0xAA, 0x05, 0x17, 0x03, 0x34, 0x39, 0x38, 0x8C},
  {0xAA, 0x05, 0x17, 0x03, 0x31, 0x39, 0x33, 0x8C}
};

// Define the number of data packets
#define NUM_PACKETS 10

// Define RS485 pin connections
#define RS485_RX 3
#define RS485_TX 2

// Initialize SoftwareSerial for RS485 communication
SoftwareSerial RS485Serial(RS485_RX, RS485_TX);

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  
  // Initialize RS485 communication
  RS485Serial.begin(9600);
}

void loop() {
  // Loop through the data packets and send them individually
  for (int i = 0; i < NUM_PACKETS; i++) {
    // Send the data packet
    for (int j = 0; j < 8; j++) {
      RS485Serial.write(data_packets[i][j]);
      Serial.print("Sent: 0x");
      if (data_packets[i][j] < 0x10) {
        Serial.print("0");
      }
      Serial.print(data_packets[i][j], HEX);
      Serial.print(" ");
    }
    Serial.println(); // Print a new line after each packet is sent
    
    // Capture and print response
    delay(100); // Allow some time for response to arrive
    while (RS485Serial.available()) {
      byte responseByte = RS485Serial.read();
      Serial.print("Received: 0x");
      if (responseByte < 0x10) {
        Serial.print("0");
      }
      Serial.print(responseByte, HEX);
      Serial.print(" ");
    }
    Serial.println(); // Print a new line after capturing response
    
    // Delay for 2 seconds between sending packets
    delay(2000);
  }
}

