import re

parsed_icg = []
variable = {}
param = []
def searchLine(str):
    ind=0
    for i in parsed_icg:
        if (i==str):
            return ind
        ind += 1
    return -1

def my_printf(fmt_str, *args):
    """
    Format a string using a format string and a list of arguments.

    fmt_str: the format string
    *args: a variable-length argument list containing the values to be formatted
    """
    try:
        return fmt_str % args
    except TypeError:
        return fmt_str


def executeFunction(index):
    while (1):
        str = [word for word in parsed_icg[index].split(' ')]
        #blank labels
            #simple go to next index
        if(len(str)==1):
            index=index+1
            continue
        # print(variable)
        #function call
        #pass refparam
        
        elif(str[0]=="call"):
            if(str[1]=="printf,"):
                print("PRINTF CALLED")
                pattern = r"%[dfcl]"
                param[0] = re.sub(pattern, "%s", param[0])
                ans=my_printf(param[0], *param[1:])
                print(ans[1:len(ans)-1])
                param.clear


            else:
                print("NORMAL FUNCTION CALLED")

    #variable assign
        #evaluate expression/value
        elif(str[1]=='='):
            if(len(str)==3):
                if(str[2] in variable):
                    variable[str[0]]=variable[str[2]]
                else:
                    variable[str[0]]=str[2]
            else:
                op = str[3]
                op1 = str[2]
                op2 = str[4]
                if(str[4] in variable):
                    op2 = variable[op2]
                if(str[2] in variable):
                    op1 = variable[op1]
                val1 = float(op1)
                val2 = float(op2)
                if(op == "+"):
                    variable[str[0]]=val1+val2
                if(op == "-"):
                    variable[str[0]]=val1-val2
                if(op == "*"):
                    variable[str[0]]=val1*val2
                if(op == "/"):
                    variable[str[0]]=val1/val2
                if(op == "%"):
                    variable[str[0]]=val1%val2
                if(op == "=="):
                    variable[str[0]]=val1==val2
                if(op == "<="):
                    variable[str[0]]=val1<=val2
                if(op == ">="):
                    variable[str[0]]=val1>=val2
                if(op == "!="):
                    variable[str[0]]=val1!=val2
                if(op == ">"):
                    variable[str[0]]=val1>val2
                if(op == "<"):
                    variable[str[0]]=val1<val2
                if(op == "&&"):
                    variable[str[0]]=val1 and val2

        #if 
            #check condition and decide GOTO or not
        elif(str[0]=="IF"):
            if(not variable[str[2]]):
                label = str[4]
                if(label[-1]!=':'):
                    label = label+":"
                newIndex = searchLine(label)
                index = newIndex
                


        #GOTO
        elif(str[0]=="GoTo"):
                #search label globally
            label = str[1]
            if(label[-1]!=':'):
                label = label+":"
            newIndex = searchLine(label)
            index = newIndex

            

        #refparam
        elif(str[0]=="refparam"):
            
            parameter = parsed_icg[index][9:]
            if(parameter=="result" and parameter not in variable):
                index+=1
                continue
            elif(parameter in variable):
                parameter = variable[parameter]
                if(type(parameter)!=int and type(parameter)!=float and type(parameter)!=bool and parameter[0]=='\''):
                    parameter=parameter[1:len(parameter)-1]
            param.append(parameter)
        #func end
            #do nothing
        elif(parsed_icg[index]=='func end'):
            return
        index+=1



with open('ICG.txt', 'r') as f:
    icg = f.read()

# parse the icg string

for line in icg.split('\n'):
    if(line!=''):
        parsed_icg.append(line)

start = searchLine('func begin main')
if(start!=-1):
    executeFunction(start+1)
    # print(variable)
else:
    print("no main function defined")



