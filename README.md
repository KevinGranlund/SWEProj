# SWEProj

SOFTWARE ENGINEERING 470 PROJECT 


This program monitors bandwidth usage, with automated reporting, once banddiwth exceeds allowed cap it sends 
email to the admin, it also restricts access to to blacklisted websites stored in text file


HOW TO USE:

  Dependecies and Libraries 
  
    - install NMAP: https://nmap.org/npcap 
    - PCAP libraries 
  Software and Program 
  
    - Windows 10 OS
    - Visual Studio 2019
    - In visual studio Configuration Manager is set to x64 architecture
    - File in VS -> Clone Repository ->https://github.com/kevingrandlund/SWEPROJ
![A2](https://github.com/KevinGranlund/SWEProj/blob/master/images/A2.png)
![A3](https://github.com/KevinGranlund/SWEProj/blob/master/images/A3.png)
![A4](https://github.com/KevinGranlund/SWEProj/blob/master/images/A4.png)

    - Solution Explorer -> Select Properties of the SWEProj




  Functionalities:
  
    - Program will list all current device and network interfaces
    - For the selected interface, incoming packets is analyzed to check for whitelisted IP's
    - When user exceeds 75% of cap limit admin and user gets a notification email. 
    - When reaches 100% cap allowance, the internet shuts down
    
  Contributors
  
    Kevin Granlund
    
    Steven Steinle
    
    Patrick Pashke
    
    Victor Balogun
