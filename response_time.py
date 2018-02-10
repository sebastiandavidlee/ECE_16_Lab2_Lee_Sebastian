import serial

ser = serial.Serial('COM4', 115200)

user_input = input("Sensor? ");

if user_input == "Accelerometer":
    my_file = open('accel_response_time.txt','w');
    my_file.write("ms\n")
elif user_input == "Gyroscope":
    my_file = open('gyro_response_time.txt','w');
    my_file.write("ms\n")

data_list = [];
i = 0;
n = 20;

while i < n:
    
    ard_input = user_input.encode('ascii');
    ser.write(ard_input);

    while(not ser.inWaiting):
        pass
    
    data_to_append = ser.readline().decode();
    data_list.append(data_to_append);
    i = i + 1;

for item in data_list:
    item = item.rstrip("\n")
    my_file.write(item);
    
my_file.close();
