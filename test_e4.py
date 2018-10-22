
# TODO: Get all
tests = {
  'poi01': 'OK', 
  'poi02': 'OK',
  'poi03': 'OK',
  'poi04': 'ERR_UNDECLARED',
  'poi05': 'ERR_UNDECLARED',
  'poi06': 'ERR_UNDECLARED'
}
  
error_codes = {
  'ERR_UNDECLARED': '10',
  'ERR_DECLARED':   '11',
  
  'ERR_VARIABLE':   '20',
  'ERR_VECTOR':     '21',
  'ERR_FUNCTION':   '22',
  'ERR_USER':       '23',
  
  'ERR_WRONG_TYPE':  '30',
  'ERR_STRING_TO_X': '31',
  'ERR_CHAR_TO_X':   '32',
  'ERR_USER_TO_X':   '33',
  
  'ERR_MISSING_ARGS':    '40',
  'ERR_EXCESS_ARGS':     '41',
  'ERR_WRONG_TYPE_ARGS': '42',
  
  'ERR_WRONG_PAR_INPUT':  '50',
  'ERR_WRONG_PAR_OUTPUT': '51',
  'ERR_WRONG_PAR_RETURN': '52'
}
  
for file_name, correct_output in tests.iteritems():
    p = subprocess.Popen("cat ./e4tests/" + file_name + " | ./etapa4 & echo $?", stdout=subprocess.PIPE, shell=True)
    actual_output = p.communicate()[0]
    
    if actual_output == correct_output:
        print(file_name + " OK")
    else:
        print(file_name + " Failed: " + actual_output + " instead of " + correct_output)

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
