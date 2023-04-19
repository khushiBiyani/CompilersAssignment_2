    %{
        #include <stdio.h>
        #include <stdlib.h>
        #include <vector>
        using namespace std;
        int count=0;
        vector<int> invalidPrintfLine;
        int lineNum=1;
    %}
    %x COMMENT 
    %x SLCOMMENT 
    %x PRINT
    %x PRINTFTEXT
    %% 
    [-]?[0-9]+([eE][+-]?[1-9][0-9]*)? {printf("%s - INTEGER\n",yytext);}
    [-]?[0-9]*\.[0-9]+([eE][+-]?[1-9][0-9]*)? {printf("\tFLOAT\n",yytext);}
    int {printf("%s - Integer Keyword\n",yytext);}
    else {printf("%s - Else Keyword\n",yytext);}
    char {printf("%s - Char Keyword\n",yytext);}
    float {printf("%s - Float Keyword\n",yytext);}
    break {printf("%s - Break Keyword\n",yytext);}
    continue {printf("%s - Continue Keyword\n",yytext);}
    if {printf("%s - If Keyword\n",yytext);}
    while {printf("%s - While Keyword\n",yytext);}
    for {printf("%s - For Keyword\n",yytext);}
    switch {printf("%s - Switch Keyword\n",yytext);}
    case {printf("%s - Case Keyword\n",yytext);}
    return {printf("%s - Return Keyword\n",yytext);}
    default {printf("%s - Default Keyword\n",yytext);}
    main {printf("%s - Main Keyword\n",yytext);}
     
    printf/\(\".*\"(","[a-zA-Z_][a-zA-Z_0-9]*)*");" {printf("%s - Printf keyword\n",yytext); count=0; BEGIN PRINT;}
    <PRINT>"(" {printf("%s - Open Round Bracket\n", yytext);}
    <PRINT>\" { yymore(); BEGIN PRINTFTEXT;}
    <PRINTFTEXT>"%"[scfd] {yymore(); count++;}
    <PRINTFTEXT>\" {printf("%s - Printf string\n", yytext);BEGIN PRINT;}
    <PRINTFTEXT>[.\n\t\r\f\v]* {yymore();}
    <PRINT>","/[a-zA-Z_][a-zA-Z_0-9]* {printf("%s - Comma\n", yytext);count--;}
    <PRINT>[a-zA-Z_][a-zA-Z_0-9]* {printf("%s - Identifier\n",yytext);}
    <PRINT>")" {printf("%s - Close Round Bracket\n", yytext);}
    <PRINT>";" {
        printf("%s - Semi Colon\n", yytext);
        if(count!=0)
            invalidPrintfLine.push_back(lineNum);
        BEGIN INITIAL;
        }
     
    "/*"                                {BEGIN COMMENT;}
    <COMMENT>.|[ \t\r\f\v\n]             ;
    <COMMENT>"*/"                       {BEGIN INITIAL;}
    <COMMENT>"/*"                       {printf("Error: Nested comments are invalid\n");yyterminate();}
    <COMMENT><<EOF>>                    {printf("Error: Unterminated comments are invalid\n"); yyterminate();}
    "//"                                {BEGIN SLCOMMENT;}
    <SLCOMMENT>.                        ;
    <SLCOMMENT>\n                       {yylineno++; BEGIN INITIAL;}
     
    "+" {printf("%s - Addition Operator\n",yytext);}
    "-" {printf("%s - Subtraction Operator\n",yytext);}
    "*" {printf("%s - Multiplication Operator\n",yytext);}
    "=" {printf("%s - Assignment Operator\n",yytext);}
    "%" {printf("%s - Modulus Operator\n",yytext);}
    "/" {printf("%s - Division Operator\n",yytext);}
    "==" {printf("%s - Equal to Operator\n",yytext);}
    ">=" {printf("%s - Greater Than or Equal To Operator\n",yytext);}
    "<=" {printf("%s - Less Than or Equal To\n",yytext);}
    "<" {printf("%s - Greater Than Operator\n",yytext);}
    ">" {printf("%s - Less Than Operator\n",yytext);}
    "!=" {printf("%s - Not Equal to Operator\n",yytext);}
    "&&" {printf("%s - Logical AND Operator\n",yytext);}
    "||" {printf("%s - Logical OR Operator\n",yytext);}
    "!" {printf("%s - Logical NOT Operator\n",yytext);}
    [a-zA-Z_][a-zA-Z0-9_]* {printf("%s - Identifier\n",yytext);}
    [0-9]+([a-zA-Z]|_)+  {printf("Error: Illegal identifier format\n");}
    "["   {printf("%s - Open Square Bracket\n", yytext);}
    "]"   {printf("%s - Closed Square Bracket\n", yytext);}
    "{"   {printf("%s - Open Curly Bracket\n", yytext);}
    "}"   {printf("%s - Closed Curly Bracket\n", yytext);}
    "("   {printf("%s - Open Round Bracket\n", yytext);}
    ")"   {printf("%s - Closed Round Bracket\n", yytext);}
    ","   {printf("%s - Comma\n", yytext);}
    ";"   {printf("%s - Delimiter\n", yytext);}
    "&"   {printf("%s - Ampersand\n",yytext);}
    ":"   {printf("%s - Colon\n",yytext);}
    \"[^\"\n]*\" {printf("%s - String\n", yytext);}
    \'[^\'\n]\' {printf("%s - Character\n", yytext);}
    [ \t\r\f\v] ;
    \n {lineNum++;}
    . {printf("%s - Illegal Character\n",yytext);}	
     
    %%
     
    int main() {
        yyin=fopen("./TestCases/testCase3.c","r");
        yylex();
        printf("Invalid Printf Statements : \n");
        for(int i=0;i<invalidPrintfLine.size();i++)
            printf("On line : %d\n",invalidPrintfLine[i]);
        return 0;
    }