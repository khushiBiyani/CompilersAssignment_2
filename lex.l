%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <vector>
    using namespace std;
    int pCount=0;
    int sCount=0;
    vector<int> invalidPrintfLine;
    vector<int> invalidScanfLine;
    int lineNum=1;
%}
%x COMMENT 
%x SLCOMMENT 
%x PRINT
%x PRINTFTEXT
%x SCAN
%x SCANFTEXT
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
 
printf/\(\".*\"(",".*)*");" {printf("\n%s - Printf keyword\n",yytext); pCount=0; BEGIN PRINT;}
"printf".*; {invalidPrintfLine.push_back(lineNum);}
<PRINT>"(" {printf("\n%s - Open Round Bracket\n", yytext);}
<PRINT>\" { yymore(); BEGIN PRINTFTEXT;}
<PRINTFTEXT>"%"[scfd] {yymore(); pCount++;}
<PRINTFTEXT>\" {printf("\n%s - Printf string\n", yytext);BEGIN PRINT;}
<PRINTFTEXT>[.\t\r\f\v] ;
<PRINTFTEXT>\n {lineNum++;}
<PRINT>","/(" "*).* {printf("\n%s - Comma\n", yytext);pCount--;}
<PRINT>[0-9]+([a-zA-Z]|_)+  {printf("Error: Illegal identifier format\n");pCount--;}
<PRINT>[a-zA-Z_][a-zA-Z_0-9]* {printf("\n%s - Identifier\n",yytext);}
<PRINT>[ \t\v\f\r] ;
<PRINT>")" {printf("\n%s - Close Round Bracket", yytext);}
<PRINT>";" {
    printf("\n%s - Semi Colon", yytext);
    if(pCount!=0)
        invalidPrintfLine.push_back(lineNum);
    BEGIN INITIAL;
    }
 
scanf/\(\".*\"(","" "*&.*)*");" {printf("\n%s - Scanf keyword\n",yytext); sCount=0; BEGIN SCAN;}
"scanf".*; {invalidScanfLine.push_back(lineNum);}
<SCAN>"(" {printf("\n%s - Open Round Bracket\n", yytext);}
<SCAN>\" { yymore(); BEGIN SCANFTEXT;}
<SCANFTEXT>"%"[scfd] {yymore(); sCount++;}
<SCANFTEXT>\" {printf("\n%s - Scanf string\n", yytext);BEGIN SCAN;}
<SCANFTEXT>[.\t\r\f\v] ;
<SCANFTEXT>\n {lineNum++;}
<SCAN>","/(" "*).* {printf("\n%s - Comma\n", yytext);sCount--;printf("\nsCount: %d\n",sCount);}
<SCAN>[0-9]+([a-zA-Z]|_)+  {printf("Error: Illegal identifier format\n");sCount--; printf("\nsCount: %d\n",sCount);}
<SCAN>"&"/.* {printf("\n%s - Ampersand\n", yytext);}
<SCAN>[a-zA-Z_][a-zA-Z_0-9]* {printf("\n%s - Identifier\n",yytext);}
<SCAN>[ \t\v\f\r] ;
<SCAN>")" {printf("\n%s - Close Round Bracket", yytext);}
<SCAN>";" {
    printf("\n%s - Semi Colon\n", yytext);
    if(sCount!=0)
        invalidScanfLine.push_back(lineNum);
    BEGIN INITIAL;
}
 
"/*"                                {BEGIN COMMENT;}
<COMMENT>.|[ \t\r\f\v\n]             ;
<COMMENT>"*/"                       {BEGIN INITIAL;}
<COMMENT>"/*"                       {printf("Error: Nested comments are invalid\n");yyterminate();}
<COMMENT><<EOF>>                    {printf("Error: Unterminated comments are invalid\n"); yyterminate();}
"//"                                {BEGIN SLCOMMENT;}
<SLCOMMENT>.                        ;
<SLCOMMENT>\n                       {lineNum++; BEGIN INITIAL;}
 
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
    yyin=fopen("./Test Cases/testCase3.c","r");
    yylex();
    if(invalidScanfLine.size()!=0){
        printf("\nInvalid Scanf Statements : \n");
        for(int i=0;i<invalidScanfLine.size();i++)
            printf("On line : %d\n",invalidScanfLine[i]);
    }
    else{
        printf("\nNo Scanf errors\n");
    }
    if(invalidPrintfLine.size()!=0){
        printf("\nInvalid Printf Statements : \n");
        for(int i=0;i<invalidPrintfLine.size();i++)
            printf("On line : %d\n",invalidPrintfLine[i]);
    }
    else{
        printf("\nNo Printf errors\n");
    }
    return 0;
}