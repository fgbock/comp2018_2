from os import listdir
from os.path import isfile, join
import os
import subprocess


tests_path = "./e2tests/"
incorrect = [ "asl11", "asl12", "asl14", "asl15", "asl17", "asl21", "asl22", "asl23", "asl26", "asl29", "asl34", "asl40", "asl45", "asl68", "asl69", "asl71", "asl82", "asl83", "asl84", "asl85", "asl86", "asl87", "asl88", "asl89", "asl90", "asl91", "asl92", "asl93", "asl94", "asl95", "asl98", "asl99", "asl100", "asl101", "asl102", "asl103", "asl104", "asl105", "asl106", "asl107", "asl108", "asl109", "asl110", "asl111", "asl112", "asl113", "asl115", "asl116", "asl118", "asl119", "asl120", "asl121", "asl122", "asl123", "asl124", "asl125", "asl127", "asl128", "asl129", "asl130", "asl131", "asl132", "asl133", "asl134", "asl135", "asl136", "asl137"]
onlyfiles = [f for f in listdir(tests_path) if isfile(join(tests_path, f))]
count1 = 0;
count2 = 0;
for f in onlyfiles:
    if f not in incorrect:
        p = subprocess.Popen("cat " + tests_path + f + " | ./etapa3 > temp1", stdout=subprocess.PIPE, shell=True)
        p.wait()
        p2 = subprocess.Popen("cat temp1 | ./etapa3 > temp2", stdout=subprocess.PIPE, shell=True)
        p2.wait()
        result2 = p2.communicate()[0]
        
        # Diff
	diff = subprocess.Popen("    grep -v \"^/\" " + tests_path + f + " | while read LINE \n\t do echo $LINE >> original \n\t done", stdout=subprocess.PIPE, shell=True)
        diff = subprocess.Popen("diff -wbBEZ ./original ./temp2", stdout=subprocess.PIPE, shell=True)
	diff = subprocess.Popen("rm original", stdout=subprocess.PIPE, shell=True)
        diff.wait()
        diff_message = diff.communicate()[0]
        print(f + ":" + diff_message)
        
