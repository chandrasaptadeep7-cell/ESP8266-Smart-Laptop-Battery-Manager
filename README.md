# ESP8266-Smart-Laptop-Battery-Manager
   IoT-based laptop battery charging cutoff system using Python and ESP8266. Automatically controls charger state over Wi-Fi based on battery percentage to improve battery longevity.
   An IoT-based battery management system that automatically controls a laptop charger using Python and an ESP8266 over Wi-Fi based on real-time battery percentage.
   This project demonstrates Python-to-Hardware communication, embedded firmware development, and IoT networking.

# Project Overview
   An automated battery management system that utilizes an ESP8266-controlled relay to regulate charging based on laptop battery thresholds. The system achieves autonomous power control via a     Python-based agent, effectively minimizing thermal and electrical stress on the battery to improve overall hardware lifespan.
   
# Key Features
      Automatic battery monitoring
      Relay-based charging control
      Wi-Fi communication
      HTTP server on ESP8266
      mDNS support
      Configurable charging thresholds
      Real-time automation

# Hardware Used
      | Component | Purpose |
      | :--- | :--- |
      | ESP8266 NodeMCU | IoT Controller |
      | Relay Module | Charger ON/OFF |
      | Laptop | Battery Monitoring |
      | Wi-Fi Router | Communication |

# Software Used
    Python libraries: 
     * Python.   
     * psutil.
     * requests.
        
    Libreries used for the Embedded Firmware: 
     * ESP8266WiFi.
     * ESP8266WebServer.
     * ESP8266mDNS.

# Documents
      The repository includes:
      1) Circuit Diagram
      2) Block Diagram
      3) Source Code
      4) Working Manual


# Communication Flow
      Step-by-step explanation:
      Python reads battery percentage of the laptop.
      Sends HTTP request to Esp8266.
      ESP8266 receives request.
      Relay switches charger.
      System repeats in infinite loop.

# Working Principle
   * Connectivity: The ESP8266 and the laptop are synchronized via a local Wi-Fi network.
   
   * Monitoring: A Python script tracks battery percentage in real-time.
   
   * Automation: At ≥95%: The script sends an HTTP request to the ESP8266 to trip the relay and stop charging.
               At ≤35%: The script instructs the ESP8266 to release the relay, enabling the charging circuit.
     
# Technical Highlights
      Python Automation
      Embedded C/C++
      HTTP Client-Server Communication
      REST API
      Embedded Networking
      IoT
      mDNS
      GPIO Programming
      Relay Interfacing
      Error Handling
      Wi-Fi Communication

# Challenges Faced
      Network timeout handling
      Reliable Wi-Fi reconnection
      While communication through IP address
  

