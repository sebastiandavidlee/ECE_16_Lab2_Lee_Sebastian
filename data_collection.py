import serial

ser = serial.Serial('COM4', 115200)
user_input = input("Sensor? ");     # user_input type is str

ard_input = user_input.encode('ascii');
ser.write(ard_input);

if user_input == "1":
    my_file = open('accel_output.txt','w');
    my_file.write("ms\t\t" + "ax \t\t" + "ay\t\t" + "az (g's) \n")
elif user_input == "2":
    my_file = open('gyro_output.txt','w');
    my_file.write("ms\t\t" + "gx\t\t" + "gy\t\t" + "gz (°/second)\n")
elif user_input == "3":
    my_file = open('analog_output.txt','w');
    my_file.write("ms\t" + "Voltage (0-3.3 V)\n")

data_list = [];
i = 0;
n = 5000;

while i < n:
    while(not ser.inWaiting):
        pass
    
    data_to_append = ser.readline().decode();
    data_list.append(data_to_append);
    i = i + 1;

for item in data_list:
    item = item.rstrip("\n")
    my_file.write(item);
    
my_file.close();
