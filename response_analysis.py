
import numpy as np

filename = ["accel_response_time.txt", "gyro_response_time.txt"]
file_write = ['accel_response_analysis.txt','gyro_response_analysis.txt']

for k in range(2):
    my_file = open(filename[k],'r')
    
    i = 0; j = 0;
    time_list = []
    
    while True:
        a_line = my_file.readline()
        if not a_line:
            break
        a_line = a_line.strip("\n")
        time_list.append(0);
        time_list[j] = a_line
        j = j + 1;
    
    
    time_list.remove('ms')
    time_diff = []
    
    
    for x in range(len(time_list)):
        time_diff.append(0);
        time_diff[x] = int(time_list[x]);
    
    
    a = np.array(time_diff).astype(np.float)
    mean_val = np.mean(a)
    std_dev = np.std(a)
    max_val = np.amax(a)
    min_val = np.amin(a)
#    
#    print(mean_val)
#    print(std_dev)
#    print(max_val)
#    print(min_val)

    my_file = open(file_write[k],'w');
    my_file.write("mean value: {}\n".format(mean_val))
    my_file.write("standard deviation: {}\n".format(std_dev))
    my_file.write("maximum value: {}\n".format(max_val))
    my_file.write("minimum value: {}\n".format(min_val))
    my_file.close()
        

    







