%option noyywrap
%{
  #include "projet.y.hpp"
  #include <iostream>
%}
%%
[0-9]+(\.[0-9]*)?([Ee][0-9]+)?  { yylval.valeur = atof(yytext); return NUMBER;  }

VRAI|Vrai|vrai  { yylval.valeur = 1; return NUMBER; }
FAUX|Faux|faux  { yylval.valeur = 0; return NUMBER; }

POSITION|Position|position|POS|Pos|pos  { return POSITION;  }

\+                                { return OP_PLUS; }
-                                 { return OP_MINUS; }
\*                                { return OP_MULTIPLY; }
\/                                { return OP_DIVIDE; }
\|\|                              { return OP_OR; }
\&\&                              { return OP_AND; }
>                                 { return OP_GREATER; }
>=                                { return OP_GREATEREQUAL; }
==                                { return OP_EQUAL; }
\<=                               { return OP_LESSEREQUAL; }
\<                                { return OP_LESSER; }
!=                                { return OP_DIFFERENT; }

SI|Si|si                          { return IF; }
SINON|Sinon|sinon                 { return ELSE;  }
FINSI|Finsi|finsi                 { return ENDIF;  }
REPETE|Repete|repete              { return REPEAT;  }
FINREPETE|FinRepete|finrepete     { return ENDREPEAT; }

[a-zA-Z_]+                        { strcpy(yylval.nom,yytext); return IDENTIFIER; }

\n								{ return '\n'; }
\r								{ return '\n'; }
[ \t]							{ }
.                 { return yytext[0];}
%%
