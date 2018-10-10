from os import listdir
from os.path import isfile, join
import subprocess

tests_path = "./e3tests/"
incorrect = [ ]
onlyfiles = [f for f in listdir(tests_path) if isfile(join(tests_path, f))]
for f in onlyfiles:
    if f not in incorrect:
        p = subprocess.Popen("cat " + tests_path + f + " | ./etapa3", stdout=subprocess.PIPE, shell=True)
        message = p.communicate()[0] 
	msg_aux = message.split()
	with open(join(tests_path, f), 'r') as myfile:
		filedata=myfile.read().replace('\n', '')
		filedata_aux = message.split()
        if (message and (f not in incorrect) and (msg_aux != filedata_aux)):
            print(f + " incorrect output: - " + message)
	    #print("\n\n")
	    #print(msg_aux)
 	    #print(filedata_aux)


