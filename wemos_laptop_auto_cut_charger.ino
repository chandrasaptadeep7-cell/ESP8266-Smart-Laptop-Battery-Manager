//============================================================
// Smart Laptop Battery Manager - ESP8266 Firmware
// Author: Saptadeep Chandra
//
// Description:
// This program receives HTTP requests from a Python application
// running on a laptop. Based on the battery percentage, it
// controls a relay to switch the laptop charger ON or OFF.
//
// Endpoints:
//   /high -> Battery Full  -> Charger OFF
//   /low  -> Battery Low   -> Charger ON
//============================================================


//---------------------- Library Files ------------------------
#include <ESP8266WiFi.h>        // Wi-Fi functionality
#include <ESP8266WebServer.h>   // Creates an HTTP web server
#include <ESP8266mDNS.h>        // Allows access using esp8266.local


//---------------- Function Prototypes ------------------------
void handle_Full_Charge();
void handle_Low_Charge();


//---------------- Wi-Fi Credentials --------------------------
const char* ssid = "Saptadeep";
const char* password = "21032003";


// Create a web server object running on port 80 (HTTP)
ESP8266WebServer server(80);


//---------------- Hardware Configuration ---------------------
#define RELAY_PIN D7    // Relay module connected to GPIO D7


//============================================================
// Function: handle_Full_Charge()
// Description:
// Called when the Python program detects that the laptop battery
// has reached the upper charging threshold.
//
// Action:
//   - Turns OFF the relay
//   - Disconnects the charger
//   - Sends a confirmation message to the Python application
//============================================================
void handle_Full_Charge()
{
    digitalWrite(RELAY_PIN, LOW);      // Relay OFF (depends on relay logic)

    server.send(200, "text/plain", "D7 LOW");
}


//============================================================
// Function: handle_Low_Charge()
// Description:
// Called when the laptop battery falls below the lower threshold.
//
// Action:
//   - Turns ON the relay
//   - Connects the charger
//   - Sends confirmation back to the Python application
//============================================================
void handle_Low_Charge()
{
    digitalWrite(RELAY_PIN, HIGH);     // Relay ON

    server.send(200, "text/plain", "D7 HIGH");
}



//============================================================
// setup()
// Runs only once after the ESP8266 powers up or resets.
//============================================================
void setup()
{
    // Start Serial Monitor for debugging
    Serial.begin(115200);

    // Configure relay pin as output
    pinMode(RELAY_PIN, OUTPUT);

    // Built-in LED (D4) used as Wi-Fi connection indicator
    pinMode(D4, OUTPUT);

    // Keep charger ON initially
    // (Failsafe: laptop continues charging until commands arrive)
    digitalWrite(RELAY_PIN, HIGH);


    //---------------- Connect to Wi-Fi ----------------
    WiFi.begin(ssid, password);

    // Blink LED until Wi-Fi connection is established
    while (WiFi.status() != WL_CONNECTED)
    {
        digitalWrite(D4, HIGH);
        delay(250);

        digitalWrite(D4, LOW);
        delay(250);
    }

    Serial.println("\nConnected!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());


    //---------------- Start mDNS ----------------
    // Allows access using:
    // http://esp8266.local
    // instead of remembering the IP address.
    if (MDNS.begin("esp8266"))
    {
        Serial.println("mDNS started: http://esp8266.local");
    }


    //---------------- Register HTTP Endpoints ----------------
    // When browser/Python accesses:
    // http://esp8266.local/high
    // handle_Full_Charge() will execute.
    server.on("/high", handle_Full_Charge);

    // When browser/Python accesses:
    // http://esp8266.local/low
    // handle_Low_Charge() will execute.
    server.on("/low", handle_Low_Charge);


    // Start the HTTP server
    server.begin();
}



//============================================================
// loop()
// Runs continuously after setup() finishes.
//============================================================
void loop()
{
    // Listen for incoming HTTP requests
    server.handleClient();

    // Update mDNS service
    MDNS.update();


    //---------------- Wi-Fi Reconnection ----------------
    // If Wi-Fi disconnects, keep trying to reconnect
    // while blinking the onboard LED.
    while (WiFi.status() != WL_CONNECTED)
    {
        digitalWrite(D4, HIGH);
        delay(250);

        digitalWrite(D4, LOW);
        delay(250);
    }
}