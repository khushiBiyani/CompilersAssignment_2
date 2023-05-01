import re

parsed_icg = []
variable = {}
def searchLine(str):
    ind=0
    print(str)
    for i in parsed_icg:
        if (i==str):
            return ind
        ind += 1
    return -1

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

    #variable assign
        #evaluate expression/value
        if(str[1]=='='):
            print("in assign")
          
            print(str)
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
                    print("+")
                    variable[str[0]]=val1+val2
                if(op == "-"):
                    print("-")
                    variable[str[0]]=val1-val2
                if(op == "*"):
                    print("*")
                    variable[str[0]]=val1*val2
                if(op == "/"):
                    print("/")
                    variable[str[0]]=val1/val2
                if(op == "%"):
                    print("%")
                    variable[str[0]]=val1%val2
                if(op == "=="):
                    print("==")
                    variable[str[0]]=val1==val2
                if(op == "<="):
                    print("<=")
                    variable[str[0]]=val1<=val2
                if(op == ">="):
                    print(">=")
                    variable[str[0]]=val1>=val2
                if(op == "!="):
                    print("!=")
                    variable[str[0]]=val1!=val2
                if(op == ">"):
                    print(">")
                    variable[str[0]]=val1>val2
                if(op == "<"):
                    print("<")
                    variable[str[0]]=val1<val2
                if(op == "&&"):
                    print("&&")
                    variable[str[0]]=val1 and val2

        #if 
            #check condition and decide GOTO or not
        elif(str[0]=="IF"):
            print("INSIDE IF")
            print(variable[str[2]])
            if(not variable[str[2]]):
                print("IF GOTO")
                label = str[4]
                if(label[-1]!=':'):
                    label = label+":"
                newIndex = searchLine(label)
                print(newIndex)
                index = newIndex
                


        #GOTO
        elif(str[0]=="GoTo"):
                #search label globally
            label = str[1]
            if(label[-1]!=':'):
                label = label+":"
            newIndex = searchLine(label)
            print(newIndex)
            index = newIndex

            

        #refparam
            #store in parameter list

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

print(parsed_icg)
start = searchLine('func begin main')
print(start)
if(start!=-1):
    print("valid start")
    executeFunction(start+1)
    print(variable)
else:
    print("no main function defined")



