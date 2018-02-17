import serial

ser = serial.Serial('COM4', 115200)

my_file = open('EMG_scaled_data.txt','w');

data_list = [];
i = 0;
t = 5;
n = t*200;



while i < n:
    while(not ser.inWaiting):
        pass
    
    data_to_append = ser.readline().decode();
    data_list.append(data_to_append);
    i = i + 1;

for item in data_list:
    my_file.write(item);
    
my_file.close();