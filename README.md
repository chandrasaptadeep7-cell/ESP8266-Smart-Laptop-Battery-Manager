# ESP8266-Smart-Laptop-Battery-Manager
   IoT-based laptop battery charging cutoff system using Python and ESP8266. Automatically controls charger state over Wi-Fi based on battery percentage to improve battery longevity.
   An IoT-based battery management system that automatically controls a laptop charger using Python and an ESP8266 over Wi-Fi based on real-time battery percentage.
   This project demonstrates Python-to-Hardware communication, embedded firmware development, and IoT networking.

# Project Overview
   The Smart-Charge Manager is an IoT-based power management solution designed to extend the lifespan of legacy lithium-ion battery cells by enforcing precise, user-defined charging thresholds. While modern operating systems often lack granular control over charge termination, this system provides a hardware-level override to prevent the accelerated chemical degradation caused by maintaining batteries at full capacity for extended periods. The system architecture is divided into three distinct layers: a monitoring layer, where a Python-based background service utilizes the psutil library for real-time telemetry polling; a communication layer, which transmits state-change commands via a RESTful API over a local Wi-Fi network; and a control layer, where an ESP8266 (Wemos D1 Mini) acts as the edge controller to physically actuate a relay module. By adopting this hardware-in-the-loop approach, the project demonstrates a robust implementation of cross-platform integration and distributed system control. Ultimately, the system serves as both a practical tool for hardware preservation and a technical showcase of proficiency in bridging high-level software logic with low-level embedded firmware, highlighting an ability to design modular, reliable, and purpose-driven IoT solutions.
   
# Key Features
      Automatic battery monitoring
      Relay-based charging control
      Wi-Fi communication
      HTTP server on ESP8266
      mDNS support
      Configurable charging thresholds
      Real-time automation

# Hardware Used
      ESP8266 NodeMCU for IoT Controller.
      Relay Module for Charger ON/OFF.
      Laptop for Battery Monitoring.
      Wi-Fi Router for  Communication.
      220v AC to 5v converter (Old mobile charging board).

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
  

