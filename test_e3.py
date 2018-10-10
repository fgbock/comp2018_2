from os import listdir
from os.path import isfile, join
import os
import subprocess


tests_path = "./e3tests/"
incorrect = [ ]
onlyfiles = [f for f in listdir(tests_path) if isfile(join(tests_path, f))]
count1 = 0;
count2 = 0;
for f in onlyfiles:
    if f not in incorrect:
        p = subprocess.Popen("cat " + tests_path + f + " | ./etapa3", stdout=subprocess.PIPE, shell=True)
        message = p.communicate()[0] 
	with open('2ndtest', 'w') as file:
    		file.write(message)
	r = subprocess.Popen("cat 2ndtest | ./etapa3", stdout=subprocess.PIPE, shell=True)
	message2 = r.communicate()[0] 
	msg_aux = message.split()
	msg_aux2 = message.split()
	with open(join(tests_path, f), 'r') as myfile:
		filedata=myfile.read().replace('\n', '')
		filedata_aux = message.split()
        if (message and (f not in incorrect) and (msg_aux != filedata_aux)):
        	print(f + " incorrect output: - " + message)
		count1 += 1
	else : print(f + " had no error on descompila")
	if (message and (f not in incorrect) and (msg_aux2 != msg_aux)):
        	print(f + " incorrect 2nd descompila: - " + message2)
		count2 += 1
	else : print(f + " had no error on 2nd descompila")
	print("Original: ")
 	print(filedata_aux)
	print("\nDescompila 1: ")
	print(msg_aux)
	print("\nDescompila 2: ")
	print(msg_aux2)
	print("\n\n")
	os.remove("2ndtest") 
print("Total errors in Descompila: ")
print(count1)
print("\nTotal errors in 2nd Descompila: ")
print(count2)

