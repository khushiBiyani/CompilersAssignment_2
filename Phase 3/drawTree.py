from nltk.tree import *

text = "#code#DL##DS##int@#DLI##Identifier#yup@@@@#;@@@#DL##DS##int@#Identifier#main@@#(@#PS##PC##P##type##int@@@#Identifier#u@@@@#,@#PC##P##type##char@@@#Identifier#t@@@@#,@#PC##P##type##float@@@#Identifier#p@@@@@@@@@@@@#)@#CS##{@#SL##BS##BS##DS##int@#DLI##Identifier#a@@#=@#ES##LE##Exp##RE##value##term##factor##9@@@@@#+@#value##term##factor##5@@@@@@@@@@@@@@@@@@@#;@@@@@@@#SL##printer##printf@#(@#String#\"%d\"@@#PrA##PrA##Epsilon@@@#,@#factor##Identifier#a@@@@@@#)@#;@@@#SL##printer##printf@#(@#String#\"\ndone\n\"@@#PrA##Epsilon@@@#)@#;@@@#SL##SS##for@#FL##FLMany##(@#ForA##int@#i@#=@#ES##LE##Exp##RE##value##term##factor##0@@@@@@@@@@@@@@@#;@@@#ForE##ES##LE##Exp##RE##value##term##factor##Identifier#i@@@@@@@@#<@#RE##value##term##factor##5@@@@@@@@@@@@@@@@@@@#;@#ForU#i@@#)@#{@#InL##SLS##BS##DS##int@#DLI##Identifier#y@@@@#;@@@@@@@#InL##Epsilon@@@@@#}@@@@@@@#SL##Epsilon@@@@@@@@@@@#}@@@@@@@@@@"

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