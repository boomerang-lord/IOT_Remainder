# Self-Learning_IOT_Remainder Project

# Description
This project involved creating a system which sends remainders to the user whenever 
they missed a task. Amazon Web Service will be used with an IOT device to send emails or text messages to the user whenever a task is approaching or missed.   

# Table of Contents

# How to Install and Run the Project

# How to Use the Project
Buy the product, which will use a microcontroller. You will need an AWS account to connect to your micro controller. As for the microcontroller, we will be using an ES32 C3. You will ne

# Credits

# Testing Something
## testing something new

What to write about
- talk about power saving
- sensors
- 

# Use Case
The IOT remainder is a general purpose remainder device where a user action need to be reminded based on a time schedule. The unique feature of this remainder system is that it has the algorithm to learn the activation schedule based on the usage.
The device record user events and sends the time stamp to the server. The device also has ability to recieve messages from the server.  The events are stored in a time series database. Both the server and the device has the algorithm to learn the event schedule based on the usage pattern. 

Image testing
![alt text](<Screenshot 2024-03-27 at 7.11.48 PM.png>)

# Design Goals
1. Secure low coast IoT Module 
2. Ultra low power operation for years of batery life
3. Self-Learning Event Pattern inside the device and in th server
4. Machine Learning based Analysis of the event patterns

# Hardware Design
ESP32 C3 is selected as the target microprocessor. It is a Wi-Fi and Bluetooth microcontroller System on Chip(SoC). It is derived from RISC-V architecture.

I decided to use ESP32 devkit M1 as a prototyping board. 

# Prototyping Schematic

//Insert Image Here

I found out that even after putting the ESP32C3 in deep sleep, it was still consuming way more than the sleep currentspecified by the datasheet.

# Final Schematic (FUSION 360)
![alt text](Final_Schematic.png)

In this schematic, the usb chip for serial communication is excluded to minimize the sleep current. Instead, the J tag pins are extended through the 6 pin connector. 

# PCB Assembly
After completing the layout , I created a home made PCB using copper clad board available from Amazon along with etching chemicals. 

// Insert Image

# Programming and debugg interface 
Since the main board doesn't have the CP2102 USB chip for programming interface and debugging, I used the Dev Kit and removed the ESP32 chip from it and interfaced as shown below. 

![alt text](debugg_interface.png)

