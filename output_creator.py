

##############
## Script listens to serial port and writes contents into a file
##############
## requires pySerial to be installed 
try:
    ser.close()
except:
    pass

import serial  # sudo pip install pyserial should work
import datetime


now = datetime.datetime.now()
dt_string = now.strftime("_%d_%m_%Y__%H_%M_%S")


serial_port = 'COM4'
baud_rate = 4000000 #In arduino, Serial.begin(baud_rate)
write_to_file_path = "output\\output"+dt_string+".txt"


ser = serial.Serial(serial_port, baud_rate)
output_file = open(write_to_file_path, "w+")
last = open("last.txt", "r+")
last.truncate(0)
last.close()
last = open("last.txt", "w+")
c=True
while c:
    line = ser.readline()
    line = line.decode("utf-8") #ser.readline returns a binary, convert to string
    #print(line)


    output_file.write(line)
    last.write(line)

    if "END" in line:
        c=False
ser.close()
last.close()
output_file.close()