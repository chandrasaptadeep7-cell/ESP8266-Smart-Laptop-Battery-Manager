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

## Software Components

| Software / Library | Purpose |
| :--- | :--- |
| **Python** | Main application for battery monitoring and automation logic. |
| **psutil** | Retrieves the laptop's battery percentage and charging status. |
| **requests** | Sends HTTP POST requests to the ESP8266. |
| **Arduino IDE** | Used to develop and upload firmware to the ESP8266. |
| **VS Code** | To write and run the python script |
| **ESP8266WiFi** | Connects the ESP8266 to the local Wi-Fi network. |
| **ESP8266WebServer** | Implements the embedded HTTP server that receives control commands. |
| **ESP8266mDNS** | Enables hostname-based access (`esp8266.local`) without using a fixed IP address. |
| **Embedded C++** | Programming language used for developing the ESP8266 firmware. |

## Hardware Components

| Component | Purpose |
| :--- | :--- |
| **ESP8266 NodeMCU** | Acts as the IoT controller by hosting an HTTP server, processing incoming commands, and controlling the relay module. |
| **Relay Module (1-Channel)** | Connects or disconnects the laptop charger based on commands received from the ESP8266. |
| **Laptop** | Runs the Python application that monitors battery status and communicates with the ESP8266 over Wi-Fi. |
| **Wi-Fi Router / Local Network** | Provides wireless communication between the laptop and the ESP8266 using HTTP requests. |

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
  

