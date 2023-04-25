%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <vector>
    int pCount=0;
    int sCount=0;
    std::vector<int> invalidPrintfLine;
    std::vector<int> invalidScanfLine;
    int line_count=1;
%}
%x COMMENT 
%x SLCOMMENT 
%x PRINT
%x PRINTFTEXT
%x SCAN
%x SCANFTEXT
%% 
\n {line_count=line_count+1;}
[-]?[0-9]+([eE][+-]?[1-9][0-9]*)? {printf("%d\t\t%s\t\tInteger\n",line_count,yytext);}
[-]?[0-9]*\.[0-9]+([eE][+-]?[1-9][0-9]*)? {printf("%d\t\t%s\t\tFloat\n",line_count,yytext);}
int {printf("%d\t\t%s\t\tInteger Keyword\n",line_count,yytext);}
else {printf("%d\t\t%s\t\tElse Keyword\n",line_count,yytext);}
char {printf("%d\t\t%s\t\tChar Keyword\n",line_count,yytext);}
float {printf("%d\t\t%s\t\tFloat Keyword\n",line_count,yytext);}
break {printf("%d\t\t%s\t\tBreak Keyword\n",line_count,yytext);}
continue {printf("%d\t\t%s\t\tContinue Keyword\n",line_count,yytext);}
if {printf("%d\t\t%s\t\tIf Keyword\n",line_count,yytext);}
while {printf("%d\t\t%s\t\tWhile Keyword\n",line_count,yytext);}
for {printf("%d\t\t%s\t\tFor Keyword\n",line_count,yytext);}
switch {printf("%d\t\t%s\t\tSwitch Keyword\n",line_count,yytext);}
case {printf("%d\t\t%s\t\tCase Keyword\n",line_count,yytext);}
return {printf("%d\t\t%s\t\tReturn Keyword\n",line_count,yytext);}
default {printf("%d\t\t%s\t\tDefault Keyword\n",line_count,yytext);}
main {printf("%d\t\t%s\t\tMain Keyword\n",line_count,yytext);}

printf/\(\".*\"(",".*)*");" {printf("%d\t\t%s\t\tPrintf keyword\n",line_count,yytext); pCount=0; BEGIN PRINT;}
"printf".*; {invalidPrintfLine.push_back(line_count);}
<PRINT>"(" {printf("%d\t\t%s\t\tOpen Round Bracket\n",line_count, yytext);}
<PRINT>\" { yymore(); BEGIN PRINTFTEXT;}
<PRINTFTEXT>"%"[scfd] {yymore(); pCount++;}
<PRINTFTEXT>\" {printf("%d\t\t%s\t\tPrintf string\n",line_count, yytext);BEGIN PRINT;}
<PRINTFTEXT>[.\t\r\f\v] ;
<PRINTFTEXT>\n {line_count++;}
<PRINT>","/(" "*).* {printf("%d\t\t%s\t\tComma\n",line_count, yytext);pCount--;}
<PRINT>[0-9]+([a-zA-Z]|_)+  {printf("Error: Illegal identifier format\n");pCount--;}
<PRINT>[a-zA-Z_][a-zA-Z_0-9]* {printf("%d\t\t%s\t\tIdentifier\n",line_count,yytext);}
<PRINT>[ \t\v\f\r] ;
<PRINT>")" {printf("%d\t\t%s\t\tClose Round Bracket\n",line_count, yytext);}
<PRINT>";" {
    printf("%d\t\t%s\t\tSemi Colon\n",line_count, yytext);
    if(pCount!=0)
        invalidPrintfLine.push_back(line_count);
    BEGIN INITIAL;
    }

scanf/\(\".*\"(","" "*&.*)*");" {printf("%d\t\t%s\t\tScanf keyword\n",line_count,yytext); sCount=0; BEGIN SCAN;}
"scanf".*; {invalidScanfLine.push_back(line_count);}
<SCAN>"(" {printf("%d\t\t%s\t\tOpen Round Bracket\n",line_count, yytext);}
<SCAN>\" { yymore(); BEGIN SCANFTEXT;}
<SCANFTEXT>"%"[scfd] {yymore(); sCount++;}
<SCANFTEXT>\" {printf("%d\t\t%s\t\tScanf string\n",line_count, yytext);BEGIN SCAN;}
<SCANFTEXT>[.\t\r\f\v] ;
<SCANFTEXT>\n {line_count++;}
<SCAN>","/(" "*).* {printf("%d\t\t%s\t\tComma\n",line_count, yytext);sCount--;}
<SCAN>[0-9]+([a-zA-Z]|_)+  {printf("Error: Illegal identifier format\n");sCount--;}
<SCAN>"&"/.* {printf("%d\t\t%s\t\tAmpersand\n",line_count, yytext);}
<SCAN>[a-zA-Z_][a-zA-Z_0-9]* {printf("%d\t\t%s\t\tIdentifier\n",line_count,yytext);}
<SCAN>[ \t\v\f\r] ;
<SCAN>")" {printf("%d\t\t%s\t\tClose Round Bracket\n",line_count, yytext);}
<SCAN>";" {
    printf("%d\t\t%s\t\tSemi Colon\n",line_count, yytext);
    if(sCount!=0)
        invalidScanfLine.push_back(line_count);
    BEGIN INITIAL;
}

"/*"                                {BEGIN COMMENT;}
<COMMENT>.|[ \t\r\f\v\n]             ;
<COMMENT>"*/"                       {BEGIN INITIAL;}
<COMMENT>"/*"                       {printf("Error: Nested comments are invalid\n");yyterminate();}
<COMMENT><<EOF>>                    {printf("Error: Unterminated comments are invalid\n"); yyterminate();}
"//"                                {BEGIN SLCOMMENT;}
<SLCOMMENT>.                        ;
<SLCOMMENT>\n                       {line_count++; BEGIN INITIAL;}

"+" {printf("%d\t\t%s\t\tAddition Operator\n",line_count,yytext);}
"-" {printf("%d\t\t%s\t\tSubtraction Operator\n",line_count,yytext);}
"*" {printf("%d\t\t%s\t\tMultiplication Operator\n",line_count,yytext);}
"=" {printf("%d\t\t%s\t\tAssignment Operator\n",line_count,yytext);}
"%" {printf("%d\t\t%s\t\tModulus Operator\n",line_count,yytext);}
"/" {printf("%d\t\t%s\t\tDivision Operator\n",line_count,yytext);}
"==" {printf("%d\t\t%s\t\tEqual To Operator\n",line_count,yytext);}
">=" {printf("%d\t\t%s\t\tGreater Than or Equal To Operator\n",line_count,yytext);}
"<=" {printf("%d\t\t%s\t\tLess Than or Equal To\n",line_count,yytext);}
"<" {printf("%d\t\t%s\t\tGreater Than Operator\n",line_count,yytext);}
">" {printf("%d\t\t%s\t\tLess Than Operator\n",line_count,yytext);}
"!=" {printf("%d\t\t%s\t\tNot Equal to Operator\n",line_count,yytext);}
"&&" {printf("%d\t\t%s\t\tLogical AND Operator\n",line_count,yytext);}
"||" {printf("%d\t\t%s\t\tLogical OR Operator\n",line_count,yytext);}
"!" {printf("%d\t\t%s\t\tLogical NOT Operator\n",line_count,yytext);}
"scanf"    {printf("%d\t\t%s\t\tScanf encountered.\n",line_count,yytext);}
[a-zA-Z_][a-zA-Z0-9_]* {printf("%d\t\t%s\t\tIdentifier\n",line_count,yytext);}
[0-9]+([a-zA-Z]|_)+  {printf("%d\t\t%s\t\tError: Illegal identifier format\n",line_count,yytext);}
"["   {printf("%d\t\t%s\t\tOpen Square Bracket\n",line_count, yytext);}
"]"   {printf("%d\t\t%s\t\tClosed Square Bracket\n",line_count, yytext);}
"{"   {printf("%d\t\t%s\t\tOpen Curly Bracket\n",line_count, yytext);}
"}"   {printf("%d\t\t%s\t\tClosed Curly Bracket\n",line_count, yytext);}
"("   {printf("%d\t\t%s\t\tOpen Round Bracket\n",line_count, yytext);}
")"   {printf("%d\t\t%s\t\tClosed Round Bracket\n",line_count, yytext);}
","   {printf("%d\t\t%s\t\tComma\n",line_count, yytext);}
";"   {printf("%d\t\t%s\t\tDelimiter\n",line_count, yytext);}
"&"   {printf("%d\t\t%s\t\tAmpersand\n",line_count,yytext);}

\"[^\"\n]*\" {printf("%d\t\t%s\t\tString\n",line_count, yytext);}
\'[^\'\n]\' {printf("%d\t\t%s\t\tCharacter\n",line_count, yytext);}
[ \t\r\n\f\v] ;
. {printf("%d\t\t%s\t\tIllegal Character\n",line_count,yytext);}    


%%

int main() {
    yyin=fopen("./Test Cases/testCase4.c","r");
    printf("----------------------------------------------------------\n");
    printf("line number\t\tlexeme\t\ttoken type\n");
    printf("----------------------------------------------------------\n");
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
