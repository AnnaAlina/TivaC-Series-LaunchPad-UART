# TivaC-Series-LaunchPad-UART
In its simplest form, this lab is designed to teach the students how to utilize the UART to communicate with the LaunchPad. It will help familiarize the individuals with concepts involving UART and communicating through serial interfaces such as Putty.

UART, which stands for Universal Asynchronous Receiver/Transmitter, is a peripheral device on the Tiva LaunchPad. This hardware is basically a two wire system that has one transmitting data while the other receives data. The parallel data has to be converted to serial for the data to be able to be transferred over a cable with the communication standard of RS-232. It is universal due to the adjustability of the transmission speed in which the baud rate can be set to the user’s specification.   


Procedure

Initially, the student is required to download a program called Putty from www.putty.org.  Also, this program allows the user to input the specified baud rate and communication port that matches the device manager. In this case, a baud rate of 115200 and COMM 8 was utilized for this lab. Putty allows the user to communicate with a serial monitor. In this case, the code outputs to the serial monitor “Enter a Char:” and waits for the user input. Once a letter is entered, the serial monitor displays “You Entered: → n” before repeating the question. In the code, each character is outputted line by line. While computers can translate parallel data, it has to be converted into serial for transmission with the UART. 
