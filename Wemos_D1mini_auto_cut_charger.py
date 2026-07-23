#============================================================
# Smart Laptop Battery Manager - Python Application
# Author: Saptadeep Chandra
#
# Description:
# This program continuously monitors the laptop battery status.
# When the battery reaches predefined charge limits, it sends
# HTTP requests to an ESP8266 over the local Wi-Fi network.
#
# Battery >= HIGH_THRESHOLD (while charging)
#        -> Stop charging
#
# Battery <= LOW_THRESHOLD (while not charging)
#        -> Start charging
#
# Communication Protocol: HTTP
#============================================================


#---------------------- Import Libraries --------------------

from psutil import sensors_battery    # Reads laptop battery information
from time import sleep                # Creates time delays
from requests import post             # Sends HTTP POST requests
import os                             # Used to clear the terminal screen


#---------------- Battery Thresholds ------------------------

# Charging will stop when battery reaches 90%
HIGH_THRESHOLD = 90

# Charging will start when battery falls to 35%
LOW_THRESHOLD = 35


#============================================================
# Main Program Loop
# Runs continuously until the user terminates the program.
#============================================================
while True:

    # Execute the battery check 11 times
    # (approximately every 10 seconds)
    for i in range(11):

        # Read current battery information
        battery = sensors_battery()

        # Current battery percentage
        percent = battery.percent

        # True if charger is connected
        plugged = battery.power_plugged


        # Display current battery status
        if plugged:
            print(f"Battery: {percent}% | Charging")
        else:
            print(f"Battery: {percent}% | Not Charging")


        try:

            #------------------------------------------------
            # Battery Fully Charged
            #
            # If battery reaches HIGH_THRESHOLD while charging,
            # send an HTTP request to ESP8266 so it disconnects
            # the charger by controlling the relay.
            #------------------------------------------------
            if percent >= HIGH_THRESHOLD and plugged:

                post("http://esp8266.local/high", timeout=3)

                print("Charge full, Charging is cut off.")


            #------------------------------------------------
            # Battery Low
            #
            # If battery falls below LOW_THRESHOLD and the
            # charger is disconnected, send an HTTP request
            # to reconnect the charger.
            #------------------------------------------------
            elif percent <= LOW_THRESHOLD and not plugged:

                post("http://esp8266.local/low", timeout=3)

                print("Low charge, Charging is started.")


        # Handle communication errors
        except Exception as e:

            print("Error:", e)


        # Wait 10 seconds before checking battery again
        sleep(10)


    #--------------------------------------------------------
    # Clear terminal screen after 11 battery checks
    #
    # Windows -> cls
    # Linux/macOS -> clear
    #--------------------------------------------------------
    os.system("cls" if os.name == "nt" else "clear")