from os import listdir
from os.path import isfile, join
import os
import subprocess


# TODO: Get all
tests = {
  'poi01': 'OK', 
  'poi02': 'OK',
  'poi03': 'OK',
  'poi04': 'ERR_UNDECLARED',
  'poi05': 'ERR_UNDECLARED',
  'poi06': 'ERR_UNDECLARED',
  'poi07': 'ERR_DECLARED',
  'poi08': 'ERR_DECLARED',
  'poi09': 'ERR_DECLARED',
  'poi10': 'ERR_DECLARED',
  'poi11': 'OK',
  'poi12': 'ERR_VARIABLE',
  'poi13': 'ERR_VECTOR',
  'poi14': 'ERR_FUNCTION',
  'poi15': 'OK',
  'poi16': 'OK',
  'poi17': 'ERR_STRING_TO_X',
  'poi18': 'ERR_CHAR_TO_X',
  'poi19': 'ERR_USER_TO_X',
  'poi20': 'ERR_USER',
  'poi21': 'ERR_CHAR_TO_X',
  'poi22': 'ERR_STRING_TO_X',
  'poi23': 'ERR_USER_TO_X',
  'poi24': 'OK',
  'poi25': 'ERR_MISSING_ARGS',
  'poi26': 'ERR_EXCESS_ARGS',
  'poi27': 'ERR_WRONG_TYPE_ARGS',
  'poi28': 'ERR_DECLARED',
  'poi29': 'OK',
  'poi30': 'OK',
  'poi31': 'OK',
  'poi32': 'OK',
  'poi33': 'OK',
  'poi34': 'OK',
  'poi35': 'ERR_WRONG_PAR_INPUT',
  'poi36': 'ERR_WRONG_PAR_INPUT',
  'poi37': 'ERR_WRONG_PAR_INPUT',
  'poi38': 'ERR_WRONG_PAR_INPUT',
  'poi39': 'ERR_WRONG_PAR_INPUT',
  'poi40': 'ERR_WRONG_PAR_INPUT',
  'poi41': 'OK',
  'poi42': 'ERR_WRONG_PAR_OUTPUT',
  'poi43': 'OK',
  'poi44': 'OK',
  'poi45': 'OK',
  'poi46': 'ERR_FUNCTION',
  'poi47': 'OK',
  'poi48': 'OK',
  'poi49': 'OK',
  'poi50': 'ERR_WRONG_PAR_RETURN',
  'poi51': 'OK',
  'poi52': 'ERR_WRONG_PAR_RETURN',
}
  
error_name_to_code = {
  'OK': 0,

  'ERR_UNDECLARED': 10,
  'ERR_DECLARED':   11,
  
  'ERR_VARIABLE':   20,
  'ERR_VECTOR':     21,
  'ERR_FUNCTION':   22,
  'ERR_USER':       23,
  
  'ERR_WRONG_TYPE':  30,
  'ERR_STRING_TO_X': 31,
  'ERR_CHAR_TO_X':   32,
  'ERR_USER_TO_X':   33,
  
  'ERR_MISSING_ARGS':    40,
  'ERR_EXCESS_ARGS':     41,
  'ERR_WRONG_TYPE_ARGS': 42,
  
  'ERR_WRONG_PAR_INPUT':  50,
  'ERR_WRONG_PAR_OUTPUT': 51,
  'ERR_WRONG_PAR_RETURN': 52
}

succ = 0.0
total = 0.0
error_code_to_name = {v: k for k, v in error_name_to_code.items()}
  
for file_name, correct_output in tests.items():
  result = subprocess.Popen("cat ./e4tests/" + file_name + " | ./etapa4", stdout=subprocess.PIPE, shell=True)
  result.wait()
  return_code = result.returncode
  total = total + 1.0
  if return_code == error_name_to_code[correct_output]:
	  succ = succ + 1.0
	  print(file_name + " OK")
  elif return_code in error_code_to_name:
    print(file_name + " Failed: returned " + error_code_to_name[return_code] + " instead of " + correct_output)
  else:
    print(file_name + " Unknown error")
percent = repr(succ / total * 100)
print("Success rate: " + percent[0:4] + "%")



