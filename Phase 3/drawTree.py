from nltk.tree import *

text = "#code#DL##DS##int@#DLI##Identifier#b@@#=@#ES##LE##Exp##RE##value##term##factor##0@@@@@@@@@@@@@@@@@#;@@@#DL##DS##int@#Identifier#main@@#(@#)@#CS##{@#SL##BS##BS##DS##int@#DLI##Identifier#a@@#=@#ES##LE##Exp##RE##value##term##factor##0@@@@@@@@@@@@@@@@@#;@@@@@@@#SL##SS##SWS##switch@#(@#Identifier#b@@#(@#{@#CS##CSI##CI##case@#1@#:@#CC##STMTS##BS##DS##int@#DLI##Identifier#p@@#=@#ES##LE##Exp##RE##value##term##factor##23@@@@@@@@@@@@@@@@@#;@@@@@#Satements##Epsilon@@@@@#break@#;@@@@@#CSI##CI##case@#9@#:@#CC##STMTS##BS##DS##int@#DLI##Identifier#p@@#=@#ES##LE##Exp##RE##value##term##factor##0@@@@@@@@@@@@@@@@@#;@@@@@#Satements##Epsilon@@@@@@@@@#CSI##Epsilon@@@@@@@@@#DS##default@#:@#STMTS##BS##AS##Identifier#p@@#=@#ES#1@@#;@@@@@#Satements##Epsilon@@@@@@@#}@@@@@#SL##RD##return@#ES#1@@#;@@@@@@@@@#}@@@@@@@@@@"

text = text.replace("(", "OPBRAC")  # in the syntax tree, 'ob' will display in place of '('
text = text.replace(")", "CLBRAC")  # in the syntax tree, 'cb' will display in place of ')'
text = text.replace("[", "OPBOXBRAC")
text = text.replace("]", "CLBOXBRAC")
text = text.replace("{", "OPCURBRAC")
text = text.replace("}", "CLCURBRAC")
text = text.replace("#", "(")
text = text.replace("@", ")")

print(text)

tree = Tree.fromstring(text)
tree.pretty_print(unicodelines=True, nodedist=1)