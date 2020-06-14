/*--------- Definiciones de FLEX----------*/
%option noyywrap
%option case-insensitive
%option yylineno
%option nounput
/*------------Definiciones de C ------------*/
%{
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "parser.h"

int SourceLine = 1;
%}

/*-----------Expresiones regulares ---------*/
comentarios [#]([^\n])*
numero [0-9]+
numero_negativo [-][0-9]+
string (\"(\\.|[^\\"])*\")
ruta "/"("/"|"-"|"_"|"."|[a-zA-Z0-9])+
id ([a-zA-Z])([a-zA-Z]|[0-9]|"_")*

%% // <<<<<<<<<<<<<<<<<<< [Reglas lexicas] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><
('\s'|'\r'|'\t')+ {};
"\n" {SourceLine++;}
{comentarios} {};
{numero} {yylval.NUM = strdup(yytext);return (numero);};
{numero_negativo}     {yylval.NUM = strdup(yytext);return (numero_negativo);};
"full" {yylval.STRING = strdup(yytext);return (full);};
"fast" {yylval.STRING = strdup(yytext);return (fast);};
"mbr" {yylval.STRING = strdup(yytext);return (mbr);};
"size" {yylval.STRING = strdup(yytext);return (size);};
"fit" {yylval.STRING = strdup(yytext);return (fit);};
"unit" {yylval.STRING = strdup(yytext);return (unit);};
"path" {yylval.STRING = strdup(yytext);return (path);};
"type" {yylval.STRING = strdup(yytext);return (type);};
"name" {yylval.STRING = strdup(yytext);return (name);};
"delete" {yylval.STRING = strdup(yytext);return (delete_o);};
"add" {yylval.STRING = strdup(yytext);return (add);};
"disk" {yylval.STRING = strdup(yytext);return(disk);};
"id" {yylval.STRING = strdup(yytext);return (id);};
"mkdisk" {yylval.STRING = strdup(yytext);return (mkdisk);};
"rmdisk" {yylval.STRING = strdup(yytext);return (rmdisk);};
"fdisk" {yylval.STRING = strdup(yytext);return (fdisk);};
"mount" {yylval.STRING = strdup(yytext);return (mount);};
"unmount" {yylval.STRING = strdup(yytext);return (unmount);};
"exec" {yylval.STRING = strdup(yytext);return (exec);};
"rep" {yylval.STRING = strdup(yytext);return (rep);};
"k" {yylval.STRING = strdup(yytext);return (k);};
"mkfs" {yylval.STRING = strdup(yytext); return (mkfs);}
"login" {yylval.STRING = strdup(yytext); return (login);}
"usr" {yylval.STRING = strdup(yytext); return (usr);}
"pwd" {yylval.STRING = strdup(yytext); return (pwd);}
"logout" {yylval.STRING = strdup(yytext); return (logout);}
"mkgrp" {yylval.STRING = strdup(yytext); return (mkgrp);}
"rmgrp" {yylval.STRING = strdup(yytext); return (rmgrp);}
"mkusr" {yylval.STRING = strdup(yytext); return (mkusr);}
"grp" {yylval.STRING = strdup(yytext); return (grp);}
"rmusr" {yylval.STRING = strdup(yytext); return (rmusr);}
"chmod" {yylval.STRING = strdup(yytext); return (chmod);}
"mkfile" {yylval.STRING = strdup(yytext); return (mkfile);}
"cont" {yylval.STRING = strdup(yytext); return (cont);}
"cat" {yylval.STRING = strdup(yytext); return (cat);}
"file" {yylval.STRING = strdup(yytext); return (file);}
"rem" {yylval.STRING = strdup(yytext); return (rem);}
"edit" {yylval.STRING = strdup(yytext); return (edit);}
"ren" {yylval.STRING = strdup(yytext); return (ren);}
"mkdir" {yylval.STRING = strdup(yytext); return (mkdir);}
"cp" {yylval.STRING = strdup(yytext); return (cp);}
"dest" {yylval.STRING = strdup(yytext); return (dest);}
"mv" {yylval.STRING = strdup(yytext); return (mv);}
"find" {yylval.STRING = strdup(yytext); return (find);}
"chown" {yylval.STRING = strdup(yytext); return (chown_);}
"r" {yylval.STRING = strdup(yytext); return (r);}
"chgrp" {yylval.STRING = strdup(yytext); return (chgrp);}
"pause" {yylval.STRING = strdup(yytext); return (pause_);}
"m"  {yylval.STRING = strdup(yytext);return (m);};
"bf" {yylval.STRING = strdup(yytext);return (bf);};
"ff" {yylval.STRING = strdup(yytext);return (ff);};
"wf" {yylval.STRING = strdup(yytext);return (wf);};
"b" {yylval.STRING = strdup(yytext);return (b);};
"p" {yylval.STRING = strdup(yytext);return (p);};
"e" {yylval.STRING = strdup(yytext);return (e);};
"l" {yylval.STRING = strdup(yytext);return (l);};
"=" {yylval.STRING = strdup(yytext);return (igual);};
{string} {yylval.STRING = strdup(yytext);return (cadena_esp);};
{ruta} {yylval.STRING = strdup(yytext);return(ruta);};
{id} {yylval.STRING = strdup(yytext);return(id);};
[-] {yylval.STRING = strdup(yytext);return(guion);};
. {}
%%//<<<<<<<<<<<<<<<<<<<<<<<<<<<< [Reglas léxicas] >>>>>>>>>>>>>>>>>>>>>>>>>>>>>


