#include "cpeglib.h"

DECLARE_RULES(n_CompilationUnit, 
              n_PackageDeclaration, 
              n_ImportDeclaration, 
              n_TypeDeclaration, 
              n_ClassDeclaration, 
              n_ClassBody, 
              n_ClassBodyDeclaration, 
              n_MemberDecl, 
              n_GenericMethodOrConstructorRest, 
              n_MethodDeclaratorRest, 
              n_VoidMethodDeclaratorRest, 
              n_ConstructorDeclaratorRest, 
              n_MethodBody, 
              n_InterfaceDeclaration, 
              n_InterfaceBody, 
              n_InterfaceBodyDeclaration, 
              n_InterfaceMemberDecl, 
              n_InterfaceMethodOrFieldDecl, 
              n_InterfaceMethodOrFieldRest, 
              n_InterfaceMethodDeclaratorRest, 
              n_InterfaceGenericMethodDecl, 
              n_VoidInterfaceMethodDeclaratorRest, 
              n_ConstantDeclaratorsRest, 
              n_ConstantDeclarator, 
              n_ConstantDeclaratorRest, 
              n_EnumDeclaration, 
              n_EnumBody, 
              n_EnumConstants, 
              n_EnumConstant, 
              n_EnumBodyDeclarations, 
              n_LocalVariableDeclarationStatement, 
              n_VariableDeclarators, 
              n_VariableDeclarator, 
              n_FormalParameters, 
              n_FormalParameter, 
              n_LastFormalParameter, 
              n_FormalParameterList, 
              n_VariableDeclaratorId, 
              n_Block, 
              n_BlockStatements, 
              n_BlockStatement, 
              n_Statement, 
              n_Resource, 
              n_Catch, 
              n_Finally, 
              n_SwitchBlockStatementGroups, 
              n_SwitchBlockStatementGroup, 
              n_SwitchLabel, 
              n_ForInit, 
              n_ForUpdate, 
              n_EnumConstantName, 
              n_StatementExpression, 
              n_ConstantExpression, 
              n_Expression, 
              n_AssignmentOperator, 
              n_ConditionalExpression, 
              n_ConditionalOrExpression, 
              n_ConditionalAndExpression, 
              n_InclusiveOrExpression, 
              n_ExclusiveOrExpression, 
              n_AndExpression, 
              n_EqualityExpression, 
              n_RelationalExpression, 
              n_ShiftExpression, 
              n_AdditiveExpression, 
              n_MultiplicativeExpression, 
              n_UnaryExpression, 
              n_Primary, 
              n_IdentifierSuffix, 
              n_ExplicitGenericInvocation, 
              n_NonWildcardTypeArguments, 
              n_TypeArgumentsOrDiamond, 
              n_NonWildcardTypeArgumentsOrDiamond, 
              n_ExplicitGenericInvocationSuffix, 
              n_PrefixOp, 
              n_PostfixOp, 
              n_Selector, 
              n_SuperSuffix, 
              n_BasicType, 
              n_Arguments, 
              n_Creator, 
              n_CreatedName, 
              n_InnerCreator, 
              n_ClassCreatorRest, 
              n_ArrayCreatorRest, 
              n_ArrayInitializer, 
              n_VariableInitializer, 
              n_ParExpression, 
              n_QualifiedIdentifier, 
              n_Dim, 
              n_DimExpr, 
              n_Type, 
              n_ReferenceType, 
              n_ClassType, 
              n_ClassTypeList, 
              n_TypeArguments, 
              n_TypeArgument, 
              n_TypeParameters, 
              n_TypeParameter, 
              n_Bound, 
              n_Modifier, 
              n_AnnotationTypeDeclaration, 
              n_AnnotationTypeBody, 
              n_AnnotationTypeElementDeclaration, 
              n_AnnotationTypeElementRest, 
              n_AnnotationMethodOrConstantRest, 
              n_AnnotationMethodRest, 
              n_AnnotationConstantRest, 
              n_DefaultValue, 
              n_Annotation, 
              n_NormalAnnotation, 
              n_SingleElementAnnotation, 
              n_MarkerAnnotation, 
              n_ElementValuePairs, 
              n_ElementValuePair, 
              n_ElementValue, 
              n_ElementValueArrayInitializer, 
              n_ElementValues, 
              n_Spacing, 
              n_Identifier, 
              n_Letter, 
              n_LetterOrDigit, 
              n_Keyword, 
              n_ASSERT, 
              n_BREAK, 
              n_CASE, 
              n_CATCH, 
              n_CLASS, 
              n_CONTINUE, 
              n_DEFAULT, 
              n_DO, 
              n_ELSE, 
              n_ENUM, 
              n_EXTENDS, 
              n_FINALLY, 
              n_FINAL, 
              n_FOR, 
              n_IF, 
              n_IMPLEMENTS, 
              n_IMPORT, 
              n_INTERFACE, 
              n_INSTANCEOF, 
              n_NEW, 
              n_PACKAGE, 
              n_RETURN, 
              n_STATIC, 
              n_SUPER, 
              n_SWITCH, 
              n_SYNCHRONIZED, 
              n_THIS, 
              n_THROWS, 
              n_THROW, 
              n_TRY, 
              n_VOID, 
              n_WHILE, 
              n_Literal, 
              n_IntegerLiteral, 
              n_DecimalNumeral, 
              n_HexNumeral, 
              n_BinaryNumeral, 
              n_OctalNumeral, 
              n_FloatLiteral, 
              n_DecimalFloat, 
              n_Exponent, 
              n_HexFloat, 
              n_HexSignificand, 
              n_BinaryExponent, 
              n_Digits, 
              n_HexDigits, 
              n_HexDigit, 
              n_CharLiteral, 
              n_StringLiteral, 
              n_Escape, 
              n_OctalEscape, 
              n_UnicodeEscape, 
              n_AT, 
              n_AND, 
              n_ANDAND, 
              n_ANDEQU, 
              n_BANG, 
              n_BSR, 
              n_BSREQU, 
              n_COLON, 
              n_COMMA, 
              n_DEC, 
              n_DIV, 
              n_DIVEQU, 
              n_DOT, 
              n_ELLIPSIS, 
              n_EQU, 
              n_EQUAL, 
              n_GE, 
              n_GT, 
              n_HAT, 
              n_HATEQU, 
              n_INC, 
              n_LBRK, 
              n_LE, 
              n_LPAR, 
              n_LPOINT, 
              n_LT, 
              n_LWING, 
              n_MINUS, 
              n_MINUSEQU, 
              n_MOD, 
              n_MODEQU, 
              n_NOTEQUAL, 
              n_OR, 
              n_OREQU, 
              n_OROR, 
              n_PLUS, 
              n_PLUSEQU, 
              n_QUERY, 
              n_RBRK, 
              n_RPAR, 
              n_RPOINT, 
              n_RWING, 
              n_SEMI, 
              n_SL, 
              n_SLEQU, 
              n_SR, 
              n_SREQU, 
              n_STAR, 
              n_STAREQU, 
              n_TILDA, 
              n_EOT);

cpeg_charset_t cs0;
cpeg_charset_t cs1;
cpeg_charset_t cs2;
cpeg_charset_t cs3;
cpeg_charset_t cs4;
cpeg_charset_t cs5;
cpeg_charset_t cs6;
cpeg_charset_t cs7;
cpeg_charset_t cs8;
cpeg_charset_t cs9;
cpeg_charset_t cs10;
cpeg_charset_t cs11;
cpeg_charset_t cs12;
cpeg_charset_t cs13;
cpeg_charset_t cs14;
cpeg_charset_t cs15;
cpeg_charset_t cs16;
cpeg_charset_t cs17;
cpeg_charset_t cs18;
cpeg_charset_t cs19;
cpeg_charset_t cs20;
cpeg_charset_t cs21;
cpeg_charset_t cs22;
cpeg_charset_t cs23;
cpeg_charset_t cs24;
cpeg_charset_t cs25;
cpeg_charset_t cs26;
cpeg_charset_t cs27;
cpeg_charset_t cs28;
cpeg_charset_t cs29;
cpeg_charset_t cs30;
cpeg_charset_t cs31;
cpeg_charset_t cs32;
cpeg_charset_t cs33;
cpeg_charset_t cs34;
cpeg_charset_t cs35;
cpeg_charset_t cs36;
cpeg_charset_t cs37;
cpeg_charset_t cs38;
cpeg_charset_t cs39;
cpeg_charset_t cs40;
cpeg_charset_t cs41;
cpeg_charset_t cs42;
cpeg_charset_t cs43;
cpeg_charset_t cs44;
cpeg_charset_t cs45;
cpeg_charset_t cs46;
cpeg_charset_t cs47;
cpeg_charset_t cs48;
cpeg_charset_t cs49;
cpeg_charset_t cs50;

BEGIN_RULE(START) {
  
/* cs0:[ \t\r\n\f] */
  cs_simple(cs0, ' ');
  cs_simple(cs0, '\t');
  cs_simple(cs0, '\r');
  cs_simple(cs0, '\n');
  cs_simple(cs0, '\f');
/* cs1:[\r\n] */
  cs_simple(cs1, '\r');
  cs_simple(cs1, '\n');
/* cs2:[\r\n] */
  cs_simple(cs2, '\r');
  cs_simple(cs2, '\n');
/* cs3:[a-z] */
  cs_range(cs3, 'a', 'z');
/* cs4:[A-Z] */
  cs_range(cs4, 'A', 'Z');
/* cs5:[_$] */
  cs_simple(cs5, '_');
  cs_simple(cs5, '$');
/* cs6:[a-z] */
  cs_range(cs6, 'a', 'z');
/* cs7:[A-Z] */
  cs_range(cs7, 'A', 'Z');
/* cs8:[0-9] */
  cs_range(cs8, '0', '9');
/* cs9:[_$] */
  cs_simple(cs9, '_');
  cs_simple(cs9, '$');
/* cs10:[lL] */
  cs_simple(cs10, 'l');
  cs_simple(cs10, 'L');
/* cs11:[1-9] */
  cs_range(cs11, '1', '9');
/* cs12:[_] */
  cs_simple(cs12, '_');
/* cs13:[0-9] */
  cs_range(cs13, '0', '9');
/* cs14:[01] */
  cs_simple(cs14, '0');
  cs_simple(cs14, '1');
/* cs15:[_] */
  cs_simple(cs15, '_');
/* cs16:[01] */
  cs_simple(cs16, '0');
  cs_simple(cs16, '1');
/* cs17:[_] */
  cs_simple(cs17, '_');
/* cs18:[0-7] */
  cs_range(cs18, '0', '7');
/* cs19:[fFdD] */
  cs_simple(cs19, 'f');
  cs_simple(cs19, 'F');
  cs_simple(cs19, 'd');
  cs_simple(cs19, 'D');
/* cs20:[fFdD] */
  cs_simple(cs20, 'f');
  cs_simple(cs20, 'F');
  cs_simple(cs20, 'd');
  cs_simple(cs20, 'D');
/* cs21:[fFdD] */
  cs_simple(cs21, 'f');
  cs_simple(cs21, 'F');
  cs_simple(cs21, 'd');
  cs_simple(cs21, 'D');
/* cs22:[fFdD] */
  cs_simple(cs22, 'f');
  cs_simple(cs22, 'F');
  cs_simple(cs22, 'd');
  cs_simple(cs22, 'D');
/* cs23:[eE] */
  cs_simple(cs23, 'e');
  cs_simple(cs23, 'E');
/* cs24:[+-] */
  cs_simple(cs24, '+');
  cs_simple(cs24, '-');
/* cs25:[fFdD] */
  cs_simple(cs25, 'f');
  cs_simple(cs25, 'F');
  cs_simple(cs25, 'd');
  cs_simple(cs25, 'D');
/* cs26:[pP] */
  cs_simple(cs26, 'p');
  cs_simple(cs26, 'P');
/* cs27:[+-] */
  cs_simple(cs27, '+');
  cs_simple(cs27, '-');
/* cs28:[0-9] */
  cs_range(cs28, '0', '9');
/* cs29:[_] */
  cs_simple(cs29, '_');
/* cs30:[0-9] */
  cs_range(cs30, '0', '9');
/* cs31:[_] */
  cs_simple(cs31, '_');
/* cs32:[a-f] */
  cs_range(cs32, 'a', 'f');
/* cs33:[A-F] */
  cs_range(cs33, 'A', 'F');
/* cs34:[0-9] */
  cs_range(cs34, '0', '9');
/* cs35:[\'\\\n\r] */
  cs_simple(cs35, '\'');
  cs_simple(cs35, '\\');
  cs_simple(cs35, '\n');
  cs_simple(cs35, '\r');
/* cs36:[\"\\\n\r] */
  cs_simple(cs36, '\"');
  cs_simple(cs36, '\\');
  cs_simple(cs36, '\n');
  cs_simple(cs36, '\r');
/* cs37:[btnfr\"\'\\] */
  cs_simple(cs37, 'b');
  cs_simple(cs37, 't');
  cs_simple(cs37, 'n');
  cs_simple(cs37, 'f');
  cs_simple(cs37, 'r');
  cs_simple(cs37, '\"');
  cs_simple(cs37, '\'');
  cs_simple(cs37, '\\');
/* cs38:[0-3] */
  cs_range(cs38, '0', '3');
/* cs39:[0-7] */
  cs_range(cs39, '0', '7');
/* cs40:[0-7] */
  cs_range(cs40, '0', '7');
/* cs41:[0-7] */
  cs_range(cs41, '0', '7');
/* cs42:[0-7] */
  cs_range(cs42, '0', '7');
/* cs43:[0-7] */
  cs_range(cs43, '0', '7');
/* cs44:[=&] */
  cs_simple(cs44, '=');
  cs_simple(cs44, '&');
/* cs45:[=>] */
  cs_simple(cs45, '=');
  cs_simple(cs45, '>');
/* cs46:[=<] */
  cs_simple(cs46, '=');
  cs_simple(cs46, '<');
/* cs47:[=-] */
  cs_simple(cs47, '=');
  cs_simple(cs47, '-');
/* cs48:[=|] */
  cs_simple(cs48, '=');
  cs_simple(cs48, '|');
/* cs49:[=+] */
  cs_simple(cs49, '=');
  cs_simple(cs49, '+');
/* cs50:[=>] */
  cs_simple(cs50, '=');
  cs_simple(cs50, '>');
  n_CompilationUnit();
}
END_RULE

BEGIN_RULE(n_CompilationUnit) {
  SEQ(n_Spacing(), 
      OPTION(n_PackageDeclaration()), 
      REPEAT0(n_ImportDeclaration()), 
      REPEAT0(n_TypeDeclaration()), 
      n_EOT());
}
END_RULE

BEGIN_RULE(n_PackageDeclaration) {
  SEQ(REPEAT0(n_Annotation()), 
      n_PACKAGE(), 
      n_QualifiedIdentifier(), 
      n_SEMI());
}
END_RULE

BEGIN_RULE(n_ImportDeclaration) {
  ALT(SEQ(n_IMPORT(), 
          OPTION(n_STATIC()), 
          n_QualifiedIdentifier(), 
          OPTION(SEQ(n_DOT(), 
                     n_STAR())), 
          n_SEMI()), 
      n_SEMI());
}
END_RULE

BEGIN_RULE(n_TypeDeclaration) {
  ALT(SEQ(REPEAT0(n_Modifier()), 
          ALT(n_ClassDeclaration(), 
              n_EnumDeclaration(), 
              n_InterfaceDeclaration(), 
              n_AnnotationTypeDeclaration())), 
      n_SEMI());
}
END_RULE

BEGIN_RULE(n_ClassDeclaration) {
  SEQ(n_CLASS(), 
      n_Identifier(), 
      OPTION(n_TypeParameters()), 
      OPTION(SEQ(n_EXTENDS(), 
                 n_ClassType())), 
      OPTION(SEQ(n_IMPLEMENTS(), 
                 n_ClassTypeList())), 
      n_ClassBody());
}
END_RULE

BEGIN_RULE(n_ClassBody) {
  SEQ(n_LWING(), 
      REPEAT0(n_ClassBodyDeclaration()), 
      n_RWING());
}
END_RULE

BEGIN_RULE(n_ClassBodyDeclaration) {
  ALT(n_SEMI(), 
      SEQ(OPTION(n_STATIC()), 
          n_Block()), 
      SEQ(REPEAT0(n_Modifier()), 
          n_MemberDecl()));
}
END_RULE

BEGIN_RULE(n_MemberDecl) {
  ALT(SEQ(n_TypeParameters(), 
          n_GenericMethodOrConstructorRest()), 
      SEQ(n_Type(), 
          n_Identifier(), 
          n_MethodDeclaratorRest()), 
      SEQ(n_Type(), 
          n_VariableDeclarators(), 
          n_SEMI()), 
      SEQ(n_VOID(), 
          n_Identifier(), 
          n_VoidMethodDeclaratorRest()), 
      SEQ(n_Identifier(), 
          n_ConstructorDeclaratorRest()), 
      n_InterfaceDeclaration(), 
      n_ClassDeclaration(), 
      n_EnumDeclaration(), 
      n_AnnotationTypeDeclaration());
}
END_RULE

BEGIN_RULE(n_GenericMethodOrConstructorRest) {
  ALT(SEQ(ALT(n_Type(), 
              n_VOID()), 
          n_Identifier(), 
          n_MethodDeclaratorRest()), 
      SEQ(n_Identifier(), 
          n_ConstructorDeclaratorRest()));
}
END_RULE

BEGIN_RULE(n_MethodDeclaratorRest) {
  SEQ(n_FormalParameters(), 
      REPEAT0(n_Dim()), 
      OPTION(SEQ(n_THROWS(), 
                 n_ClassTypeList())), 
      ALT(n_MethodBody(), 
          n_SEMI()));
}
END_RULE

BEGIN_RULE(n_VoidMethodDeclaratorRest) {
  SEQ(n_FormalParameters(), 
      OPTION(SEQ(n_THROWS(), 
                 n_ClassTypeList())), 
      ALT(n_MethodBody(), 
          n_SEMI()));
}
END_RULE

BEGIN_RULE(n_ConstructorDeclaratorRest) {
  SEQ(n_FormalParameters(), 
      OPTION(SEQ(n_THROWS(), 
                 n_ClassTypeList())), 
      n_MethodBody());
}
END_RULE

BEGIN_RULE(n_MethodBody) {
  n_Block();
}
END_RULE

BEGIN_RULE(n_InterfaceDeclaration) {
  SEQ(n_INTERFACE(), 
      n_Identifier(), 
      OPTION(n_TypeParameters()), 
      OPTION(SEQ(n_EXTENDS(), 
                 n_ClassTypeList())), 
      n_InterfaceBody());
}
END_RULE

BEGIN_RULE(n_InterfaceBody) {
  SEQ(n_LWING(), 
      REPEAT0(n_InterfaceBodyDeclaration()), 
      n_RWING());
}
END_RULE

BEGIN_RULE(n_InterfaceBodyDeclaration) {
  ALT(SEQ(REPEAT0(n_Modifier()), 
          n_InterfaceMemberDecl()), 
      n_SEMI());
}
END_RULE

BEGIN_RULE(n_InterfaceMemberDecl) {
  ALT(n_InterfaceMethodOrFieldDecl(), 
      n_InterfaceGenericMethodDecl(), 
      SEQ(n_VOID(), 
          n_Identifier(), 
          n_VoidInterfaceMethodDeclaratorRest()), 
      n_InterfaceDeclaration(), 
      n_AnnotationTypeDeclaration(), 
      n_ClassDeclaration(), 
      n_EnumDeclaration());
}
END_RULE

BEGIN_RULE(n_InterfaceMethodOrFieldDecl) {
  SEQ(n_Type(), 
      n_Identifier(), 
      n_InterfaceMethodOrFieldRest());
}
END_RULE

BEGIN_RULE(n_InterfaceMethodOrFieldRest) {
  ALT(SEQ(n_ConstantDeclaratorsRest(), 
          n_SEMI()), 
      n_InterfaceMethodDeclaratorRest());
}
END_RULE

BEGIN_RULE(n_InterfaceMethodDeclaratorRest) {
  SEQ(n_FormalParameters(), 
      REPEAT0(n_Dim()), 
      OPTION(SEQ(n_THROWS(), 
                 n_ClassTypeList())), 
      n_SEMI());
}
END_RULE

BEGIN_RULE(n_InterfaceGenericMethodDecl) {
  SEQ(n_TypeParameters(), 
      ALT(n_Type(), 
          n_VOID()), 
      n_Identifier(), 
      n_InterfaceMethodDeclaratorRest());
}
END_RULE

BEGIN_RULE(n_VoidInterfaceMethodDeclaratorRest) {
  SEQ(n_FormalParameters(), 
      OPTION(SEQ(n_THROWS(), 
                 n_ClassTypeList())), 
      n_SEMI());
}
END_RULE

BEGIN_RULE(n_ConstantDeclaratorsRest) {
  SEQ(n_ConstantDeclaratorRest(), 
      REPEAT0(SEQ(n_COMMA(), 
                  n_ConstantDeclarator())));
}
END_RULE

BEGIN_RULE(n_ConstantDeclarator) {
  SEQ(n_Identifier(), 
      n_ConstantDeclaratorRest());
}
END_RULE

BEGIN_RULE(n_ConstantDeclaratorRest) {
  SEQ(REPEAT0(n_Dim()), 
      n_EQU(), 
      n_VariableInitializer());
}
END_RULE

BEGIN_RULE(n_EnumDeclaration) {
  SEQ(n_ENUM(), 
      n_Identifier(), 
      OPTION(SEQ(n_IMPLEMENTS(), 
                 n_ClassTypeList())), 
      n_EnumBody());
}
END_RULE

BEGIN_RULE(n_EnumBody) {
  SEQ(n_LWING(), 
      OPTION(n_EnumConstants()), 
      OPTION(n_COMMA()), 
      OPTION(n_EnumBodyDeclarations()), 
      n_RWING());
}
END_RULE

BEGIN_RULE(n_EnumConstants) {
  SEQ(n_EnumConstant(), 
      REPEAT0(SEQ(n_COMMA(), 
                  n_EnumConstant())));
}
END_RULE

BEGIN_RULE(n_EnumConstant) {
  SEQ(REPEAT0(n_Annotation()), 
      n_Identifier(), 
      OPTION(n_Arguments()), 
      OPTION(n_ClassBody()));
}
END_RULE

BEGIN_RULE(n_EnumBodyDeclarations) {
  SEQ(n_SEMI(), 
      REPEAT0(n_ClassBodyDeclaration()));
}
END_RULE

BEGIN_RULE(n_LocalVariableDeclarationStatement) {
  SEQ(REPEAT0(ALT(n_FINAL(), 
                  n_Annotation())), 
      n_Type(), 
      n_VariableDeclarators(), 
      n_SEMI());
}
END_RULE

BEGIN_RULE(n_VariableDeclarators) {
  SEQ(n_VariableDeclarator(), 
      REPEAT0(SEQ(n_COMMA(), 
                  n_VariableDeclarator())));
}
END_RULE

BEGIN_RULE(n_VariableDeclarator) {
  SEQ(n_Identifier(), 
      REPEAT0(n_Dim()), 
      OPTION(SEQ(n_EQU(), 
                 n_VariableInitializer())));
}
END_RULE

BEGIN_RULE(n_FormalParameters) {
  SEQ(n_LPAR(), 
      OPTION(n_FormalParameterList()), 
      n_RPAR());
}
END_RULE

BEGIN_RULE(n_FormalParameter) {
  SEQ(REPEAT0(ALT(n_FINAL(), 
                  n_Annotation())), 
      n_Type(), 
      n_VariableDeclaratorId());
}
END_RULE

BEGIN_RULE(n_LastFormalParameter) {
  SEQ(REPEAT0(ALT(n_FINAL(), 
                  n_Annotation())), 
      n_Type(), 
      n_ELLIPSIS(), 
      n_VariableDeclaratorId());
}
END_RULE

BEGIN_RULE(n_FormalParameterList) {
  ALT(SEQ(n_FormalParameter(), 
          REPEAT0(SEQ(n_COMMA(), 
                      n_FormalParameter())), 
          OPTION(SEQ(n_COMMA(), 
                     n_LastFormalParameter()))), 
      n_LastFormalParameter());
}
END_RULE

BEGIN_RULE(n_VariableDeclaratorId) {
  SEQ(n_Identifier(), 
      REPEAT0(n_Dim()));
}
END_RULE

BEGIN_RULE(n_Block) {
  SEQ(n_LWING(), 
      n_BlockStatements(), 
      n_RWING());
}
END_RULE

BEGIN_RULE(n_BlockStatements) {
  REPEAT0(n_BlockStatement());
}
END_RULE

BEGIN_RULE(n_BlockStatement) {
  ALT(n_LocalVariableDeclarationStatement(), 
      SEQ(REPEAT0(n_Modifier()), 
          ALT(n_ClassDeclaration(), 
              n_EnumDeclaration())), 
      n_Statement());
}
END_RULE

BEGIN_RULE(n_Statement) {
  ALT(ALT(n_Block(), 
          SEQ(n_ASSERT(), 
              n_Expression(), 
              OPTION(SEQ(n_COLON(), 
                         n_Expression())), 
              n_SEMI()), 
          SEQ(n_IF(), 
              n_ParExpression(), 
              n_Statement(), 
              OPTION(SEQ(n_ELSE(), 
                         n_Statement()))), 
          SEQ(n_FOR(), 
              n_LPAR(), 
              OPTION(n_ForInit()), 
              n_SEMI(), 
              OPTION(n_Expression()), 
              n_SEMI(), 
              OPTION(n_ForUpdate()), 
              n_RPAR(), 
              n_Statement()), 
          SEQ(n_FOR(), 
              n_LPAR(), 
              n_FormalParameter(), 
              n_COLON(), 
              n_Expression(), 
              n_RPAR(), 
              n_Statement()), 
          SEQ(n_WHILE(), 
              n_ParExpression(), 
              n_Statement()), 
          SEQ(n_DO(), 
              n_Statement(), 
              n_WHILE(), 
              n_ParExpression(), 
              n_SEMI()), 
          SEQ(n_TRY(), 
              n_LPAR(), 
              n_Resource(), 
              REPEAT0(SEQ(n_SEMI(), 
                          n_Resource())), 
              OPTION(n_SEMI()), 
              n_RPAR(), 
              n_Block(), 
              REPEAT0(n_Catch()), 
              OPTION(n_Finally())), 
          SEQ(n_TRY(), 
              n_Block(), 
              ALT(SEQ(REPEAT1(n_Catch()), 
                      OPTION(n_Finally())), 
                  n_Finally())), 
          SEQ(n_SWITCH(), 
              n_ParExpression(), 
              n_LWING(), 
              n_SwitchBlockStatementGroups(), 
              n_RWING())), 
      ALT(SEQ(n_SYNCHRONIZED(), 
              n_ParExpression(), 
              n_Block()), 
          SEQ(n_RETURN(), 
              OPTION(n_Expression()), 
              n_SEMI()), 
          SEQ(n_THROW(), 
              n_Expression(), 
              n_SEMI()), 
          SEQ(n_BREAK(), 
              OPTION(n_Identifier()), 
              n_SEMI()), 
          SEQ(n_CONTINUE(), 
              OPTION(n_Identifier()), 
              n_SEMI()), 
          n_SEMI(), 
          SEQ(n_StatementExpression(), 
              n_SEMI()), 
          SEQ(n_Identifier(), 
              n_COLON(), 
              n_Statement())));
}
END_RULE

BEGIN_RULE(n_Resource) {
  SEQ(REPEAT0(ALT(n_FINAL(), 
                  n_Annotation())), 
      n_Type(), 
      n_VariableDeclaratorId(), 
      n_EQU(), 
      n_Expression());
}
END_RULE

BEGIN_RULE(n_Catch) {
  SEQ(n_CATCH(), 
      n_LPAR(), 
      REPEAT0(ALT(n_FINAL(), 
                  n_Annotation())), 
      n_Type(), 
      REPEAT0(SEQ(n_OR(), 
                  n_Type())), 
      n_VariableDeclaratorId(), 
      n_RPAR(), 
      n_Block());
}
END_RULE

BEGIN_RULE(n_Finally) {
  SEQ(n_FINALLY(), 
      n_Block());
}
END_RULE

BEGIN_RULE(n_SwitchBlockStatementGroups) {
  REPEAT0(n_SwitchBlockStatementGroup());
}
END_RULE

BEGIN_RULE(n_SwitchBlockStatementGroup) {
  SEQ(n_SwitchLabel(), 
      n_BlockStatements());
}
END_RULE

BEGIN_RULE(n_SwitchLabel) {
  ALT(SEQ(n_CASE(), 
          n_ConstantExpression(), 
          n_COLON()), 
      SEQ(n_CASE(), 
          n_EnumConstantName(), 
          n_COLON()), 
      SEQ(n_DEFAULT(), 
          n_COLON()));
}
END_RULE

BEGIN_RULE(n_ForInit) {
  ALT(SEQ(REPEAT0(ALT(n_FINAL(), 
                      n_Annotation())), 
          n_Type(), 
          n_VariableDeclarators()), 
      SEQ(n_StatementExpression(), 
          REPEAT0(SEQ(n_COMMA(), 
                      n_StatementExpression()))));
}
END_RULE

BEGIN_RULE(n_ForUpdate) {
  SEQ(n_StatementExpression(), 
      REPEAT0(SEQ(n_COMMA(), 
                  n_StatementExpression())));
}
END_RULE

BEGIN_RULE(n_EnumConstantName) {
  n_Identifier();
}
END_RULE

BEGIN_RULE(n_StatementExpression) {
  n_Expression();
}
END_RULE

BEGIN_RULE(n_ConstantExpression) {
  n_Expression();
}
END_RULE

BEGIN_RULE(n_Expression) {
  SEQ(n_ConditionalExpression(), 
      REPEAT0(SEQ(n_AssignmentOperator(), 
                  n_ConditionalExpression())));
}
END_RULE

BEGIN_RULE(n_AssignmentOperator) {
  ALT(ALT(n_EQU(), 
          n_PLUSEQU(), 
          n_MINUSEQU(), 
          n_STAREQU(), 
          n_DIVEQU(), 
          n_ANDEQU(), 
          n_OREQU(), 
          n_HATEQU(), 
          n_MODEQU(), 
          n_SLEQU()), 
      ALT(n_SREQU(), 
          n_BSREQU()));
}
END_RULE

BEGIN_RULE(n_ConditionalExpression) {
  SEQ(n_ConditionalOrExpression(), 
      REPEAT0(SEQ(n_QUERY(), 
                  n_Expression(), 
                  n_COLON(), 
                  n_ConditionalOrExpression())));
}
END_RULE

BEGIN_RULE(n_ConditionalOrExpression) {
  SEQ(n_ConditionalAndExpression(), 
      REPEAT0(SEQ(n_OROR(), 
                  n_ConditionalAndExpression())));
}
END_RULE

BEGIN_RULE(n_ConditionalAndExpression) {
  SEQ(n_InclusiveOrExpression(), 
      REPEAT0(SEQ(n_ANDAND(), 
                  n_InclusiveOrExpression())));
}
END_RULE

BEGIN_RULE(n_InclusiveOrExpression) {
  SEQ(n_ExclusiveOrExpression(), 
      REPEAT0(SEQ(n_OR(), 
                  n_ExclusiveOrExpression())));
}
END_RULE

BEGIN_RULE(n_ExclusiveOrExpression) {
  SEQ(n_AndExpression(), 
      REPEAT0(SEQ(n_HAT(), 
                  n_AndExpression())));
}
END_RULE

BEGIN_RULE(n_AndExpression) {
  SEQ(n_EqualityExpression(), 
      REPEAT0(SEQ(n_AND(), 
                  n_EqualityExpression())));
}
END_RULE

BEGIN_RULE(n_EqualityExpression) {
  SEQ(n_RelationalExpression(), 
      REPEAT0(SEQ(ALT(n_EQUAL(), 
                      n_NOTEQUAL()), 
                  n_RelationalExpression())));
}
END_RULE

BEGIN_RULE(n_RelationalExpression) {
  SEQ(n_ShiftExpression(), 
      REPEAT0(ALT(SEQ(ALT(n_LE(), 
                          n_GE(), 
                          n_LT(), 
                          n_GT()), 
                      n_ShiftExpression()), 
                  SEQ(n_INSTANCEOF(), 
                      n_ReferenceType()))));
}
END_RULE

BEGIN_RULE(n_ShiftExpression) {
  SEQ(n_AdditiveExpression(), 
      REPEAT0(SEQ(ALT(n_SL(), 
                      n_SR(), 
                      n_BSR()), 
                  n_AdditiveExpression())));
}
END_RULE

BEGIN_RULE(n_AdditiveExpression) {
  SEQ(n_MultiplicativeExpression(), 
      REPEAT0(SEQ(ALT(n_PLUS(), 
                      n_MINUS()), 
                  n_MultiplicativeExpression())));
}
END_RULE

BEGIN_RULE(n_MultiplicativeExpression) {
  SEQ(n_UnaryExpression(), 
      REPEAT0(SEQ(ALT(n_STAR(), 
                      n_DIV(), 
                      n_MOD()), 
                  n_UnaryExpression())));
}
END_RULE

BEGIN_RULE(n_UnaryExpression) {
  ALT(SEQ(n_PrefixOp(), 
          n_UnaryExpression()), 
      SEQ(n_LPAR(), 
          n_Type(), 
          n_RPAR(), 
          n_UnaryExpression()), 
      SEQ(n_Primary(), 
          REPEAT0(n_Selector()), 
          REPEAT0(n_PostfixOp())));
}
END_RULE

BEGIN_RULE(n_Primary) {
  ALT(n_ParExpression(), 
      SEQ(n_NonWildcardTypeArguments(), 
          ALT(n_ExplicitGenericInvocationSuffix(), 
              SEQ(n_THIS(), 
                  n_Arguments()))), 
      SEQ(n_THIS(), 
          OPTION(n_Arguments())), 
      SEQ(n_SUPER(), 
          n_SuperSuffix()), 
      n_Literal(), 
      SEQ(n_NEW(), 
          n_Creator()), 
      SEQ(n_QualifiedIdentifier(), 
          OPTION(n_IdentifierSuffix())), 
      SEQ(n_BasicType(), 
          REPEAT0(n_Dim()), 
          n_DOT(), 
          n_CLASS()), 
      SEQ(n_VOID(), 
          n_DOT(), 
          n_CLASS()));
}
END_RULE

BEGIN_RULE(n_IdentifierSuffix) {
  ALT(SEQ(n_LBRK(), 
          ALT(SEQ(n_RBRK(), 
                  REPEAT0(n_Dim()), 
                  n_DOT(), 
                  n_CLASS()), 
              SEQ(n_Expression(), 
                  n_RBRK()))), 
      n_Arguments(), 
      SEQ(n_DOT(), 
          ALT(n_CLASS(), 
              n_ExplicitGenericInvocation(), 
              n_THIS(), 
              SEQ(n_SUPER(), 
                  n_Arguments()), 
              SEQ(n_NEW(), 
                  OPTION(n_NonWildcardTypeArguments()), 
                  n_InnerCreator()))));
}
END_RULE

BEGIN_RULE(n_ExplicitGenericInvocation) {
  SEQ(n_NonWildcardTypeArguments(), 
      n_ExplicitGenericInvocationSuffix());
}
END_RULE

BEGIN_RULE(n_NonWildcardTypeArguments) {
  SEQ(n_LPOINT(), 
      n_ReferenceType(), 
      REPEAT0(SEQ(n_COMMA(), 
                  n_ReferenceType())), 
      n_RPOINT());
}
END_RULE

BEGIN_RULE(n_TypeArgumentsOrDiamond) {
  ALT(SEQ(n_LPOINT(), 
          n_RPOINT()), 
      n_TypeArguments());
}
END_RULE

BEGIN_RULE(n_NonWildcardTypeArgumentsOrDiamond) {
  ALT(SEQ(n_LPOINT(), 
          n_RPOINT()), 
      n_NonWildcardTypeArguments());
}
END_RULE

BEGIN_RULE(n_ExplicitGenericInvocationSuffix) {
  ALT(SEQ(n_SUPER(), 
          n_SuperSuffix()), 
      SEQ(n_Identifier(), 
          n_Arguments()));
}
END_RULE

BEGIN_RULE(n_PrefixOp) {
  ALT(n_INC(), 
      n_DEC(), 
      n_BANG(), 
      n_TILDA(), 
      n_PLUS(), 
      n_MINUS());
}
END_RULE

BEGIN_RULE(n_PostfixOp) {
  ALT(n_INC(), 
      n_DEC());
}
END_RULE

BEGIN_RULE(n_Selector) {
  ALT(SEQ(n_DOT(), 
          n_Identifier(), 
          OPTION(n_Arguments())), 
      SEQ(n_DOT(), 
          n_ExplicitGenericInvocation()), 
      SEQ(n_DOT(), 
          n_THIS()), 
      SEQ(n_DOT(), 
          n_SUPER(), 
          n_SuperSuffix()), 
      SEQ(n_DOT(), 
          n_NEW(), 
          OPTION(n_NonWildcardTypeArguments()), 
          n_InnerCreator()), 
      n_DimExpr());
}
END_RULE

BEGIN_RULE(n_SuperSuffix) {
  ALT(n_Arguments(), 
      SEQ(n_DOT(), 
          OPTION(n_NonWildcardTypeArguments()), 
          n_Identifier(), 
          OPTION(n_Arguments())));
}
END_RULE

BEGIN_RULE(n_BasicType) {
  SEQ(ALT(STR("byte"), 
          STR("short"), 
          STR("char"), 
          STR("int"), 
          STR("long"), 
          STR("float"), 
          STR("double"), 
          STR("boolean")), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_Arguments) {
  SEQ(n_LPAR(), 
      OPTION(SEQ(n_Expression(), 
                 REPEAT0(SEQ(n_COMMA(), 
                             n_Expression())))), 
      n_RPAR());
}
END_RULE

BEGIN_RULE(n_Creator) {
  ALT(SEQ(ALT(n_BasicType(), 
              n_CreatedName()), 
          n_ArrayCreatorRest()), 
      SEQ(OPTION(n_NonWildcardTypeArguments()), 
          n_CreatedName(), 
          n_ClassCreatorRest()));
}
END_RULE

BEGIN_RULE(n_CreatedName) {
  SEQ(n_Identifier(), 
      OPTION(n_TypeArgumentsOrDiamond()), 
      REPEAT0(SEQ(n_DOT(), 
                  n_Identifier(), 
                  OPTION(n_TypeArgumentsOrDiamond()))));
}
END_RULE

BEGIN_RULE(n_InnerCreator) {
  SEQ(n_Identifier(), 
      OPTION(n_NonWildcardTypeArgumentsOrDiamond()), 
      n_ClassCreatorRest());
}
END_RULE

BEGIN_RULE(n_ClassCreatorRest) {
  SEQ(n_Arguments(), 
      OPTION(n_ClassBody()));
}
END_RULE

BEGIN_RULE(n_ArrayCreatorRest) {
  ALT(SEQ(REPEAT1(n_Dim()), 
          n_ArrayInitializer()), 
      SEQ(REPEAT1(n_DimExpr()), 
          REPEAT0(n_Dim())), 
      n_Dim());
}
END_RULE

BEGIN_RULE(n_ArrayInitializer) {
  SEQ(n_LWING(), 
      OPTION(SEQ(n_VariableInitializer(), 
                 REPEAT0(SEQ(n_COMMA(), 
                             n_VariableInitializer())))), 
      OPTION(n_COMMA()), 
      n_RWING());
}
END_RULE

BEGIN_RULE(n_VariableInitializer) {
  ALT(n_ArrayInitializer(), 
      n_Expression());
}
END_RULE

BEGIN_RULE(n_ParExpression) {
  SEQ(n_LPAR(), 
      n_Expression(), 
      n_RPAR());
}
END_RULE

BEGIN_RULE(n_QualifiedIdentifier) {
  SEQ(n_Identifier(), 
      REPEAT0(SEQ(n_DOT(), 
                  n_Identifier())));
}
END_RULE

BEGIN_RULE(n_Dim) {
  SEQ(n_LBRK(), 
      n_RBRK());
}
END_RULE

BEGIN_RULE(n_DimExpr) {
  SEQ(n_LBRK(), 
      n_Expression(), 
      n_RBRK());
}
END_RULE

BEGIN_RULE(n_Type) {
  SEQ(ALT(n_BasicType(), 
          n_ClassType()), 
      REPEAT0(n_Dim()));
}
END_RULE

BEGIN_RULE(n_ReferenceType) {
  ALT(SEQ(n_BasicType(), 
          REPEAT1(n_Dim())), 
      SEQ(n_ClassType(), 
          REPEAT0(n_Dim())));
}
END_RULE

BEGIN_RULE(n_ClassType) {
  SEQ(n_Identifier(), 
      OPTION(n_TypeArguments()), 
      REPEAT0(SEQ(n_DOT(), 
                  n_Identifier(), 
                  OPTION(n_TypeArguments()))));
}
END_RULE

BEGIN_RULE(n_ClassTypeList) {
  SEQ(n_ClassType(), 
      REPEAT0(SEQ(n_COMMA(), 
                  n_ClassType())));
}
END_RULE

BEGIN_RULE(n_TypeArguments) {
  SEQ(n_LPOINT(), 
      n_TypeArgument(), 
      REPEAT0(SEQ(n_COMMA(), 
                  n_TypeArgument())), 
      n_RPOINT());
}
END_RULE

BEGIN_RULE(n_TypeArgument) {
  ALT(n_ReferenceType(), 
      SEQ(n_QUERY(), 
          OPTION(SEQ(ALT(n_EXTENDS(), 
                         n_SUPER()), 
                     n_ReferenceType()))));
}
END_RULE

BEGIN_RULE(n_TypeParameters) {
  SEQ(n_LPOINT(), 
      n_TypeParameter(), 
      REPEAT0(SEQ(n_COMMA(), 
                  n_TypeParameter())), 
      n_RPOINT());
}
END_RULE

BEGIN_RULE(n_TypeParameter) {
  SEQ(n_Identifier(), 
      OPTION(SEQ(n_EXTENDS(), 
                 n_Bound())));
}
END_RULE

BEGIN_RULE(n_Bound) {
  SEQ(n_ClassType(), 
      REPEAT0(SEQ(n_AND(), 
                  n_ClassType())));
}
END_RULE

BEGIN_RULE(n_Modifier) {
  ALT(n_Annotation(), 
      SEQ(ALT(ALT(STR("public"), 
                  STR("protected"), 
                  STR("private"), 
                  STR("static"), 
                  STR("abstract"), 
                  STR("final"), 
                  STR("native"), 
                  STR("synchronized"), 
                  STR("transient"), 
                  STR("volatile")), 
              STR("strictfp")), 
          NOTPRE(n_LetterOrDigit()), 
          n_Spacing()));
}
END_RULE

BEGIN_RULE(n_AnnotationTypeDeclaration) {
  SEQ(n_AT(), 
      n_INTERFACE(), 
      n_Identifier(), 
      n_AnnotationTypeBody());
}
END_RULE

BEGIN_RULE(n_AnnotationTypeBody) {
  SEQ(n_LWING(), 
      REPEAT0(n_AnnotationTypeElementDeclaration()), 
      n_RWING());
}
END_RULE

BEGIN_RULE(n_AnnotationTypeElementDeclaration) {
  ALT(SEQ(REPEAT0(n_Modifier()), 
          n_AnnotationTypeElementRest()), 
      n_SEMI());
}
END_RULE

BEGIN_RULE(n_AnnotationTypeElementRest) {
  ALT(SEQ(n_Type(), 
          n_AnnotationMethodOrConstantRest(), 
          n_SEMI()), 
      n_ClassDeclaration(), 
      n_EnumDeclaration(), 
      n_InterfaceDeclaration(), 
      n_AnnotationTypeDeclaration());
}
END_RULE

BEGIN_RULE(n_AnnotationMethodOrConstantRest) {
  ALT(n_AnnotationMethodRest(), 
      n_AnnotationConstantRest());
}
END_RULE

BEGIN_RULE(n_AnnotationMethodRest) {
  SEQ(n_Identifier(), 
      n_LPAR(), 
      n_RPAR(), 
      OPTION(n_DefaultValue()));
}
END_RULE

BEGIN_RULE(n_AnnotationConstantRest) {
  n_VariableDeclarators();
}
END_RULE

BEGIN_RULE(n_DefaultValue) {
  SEQ(n_DEFAULT(), 
      n_ElementValue());
}
END_RULE

BEGIN_RULE(n_Annotation) {
  ALT(n_NormalAnnotation(), 
      n_SingleElementAnnotation(), 
      n_MarkerAnnotation());
}
END_RULE

BEGIN_RULE(n_NormalAnnotation) {
  SEQ(n_AT(), 
      n_QualifiedIdentifier(), 
      n_LPAR(), 
      OPTION(n_ElementValuePairs()), 
      n_RPAR());
}
END_RULE

BEGIN_RULE(n_SingleElementAnnotation) {
  SEQ(n_AT(), 
      n_QualifiedIdentifier(), 
      n_LPAR(), 
      n_ElementValue(), 
      n_RPAR());
}
END_RULE

BEGIN_RULE(n_MarkerAnnotation) {
  SEQ(n_AT(), 
      n_QualifiedIdentifier());
}
END_RULE

BEGIN_RULE(n_ElementValuePairs) {
  SEQ(n_ElementValuePair(), 
      REPEAT0(SEQ(n_COMMA(), 
                  n_ElementValuePair())));
}
END_RULE

BEGIN_RULE(n_ElementValuePair) {
  SEQ(n_Identifier(), 
      n_EQU(), 
      n_ElementValue());
}
END_RULE

BEGIN_RULE(n_ElementValue) {
  ALT(n_ConditionalExpression(), 
      n_Annotation(), 
      n_ElementValueArrayInitializer());
}
END_RULE

BEGIN_RULE(n_ElementValueArrayInitializer) {
  SEQ(n_LWING(), 
      OPTION(n_ElementValues()), 
      OPTION(n_COMMA()), 
      n_RWING());
}
END_RULE

BEGIN_RULE(n_ElementValues) {
  SEQ(n_ElementValue(), 
      REPEAT0(SEQ(n_COMMA(), 
                  n_ElementValue())));
}
END_RULE

BEGIN_RULE(n_Spacing) {
  REPEAT0(ALT(REPEAT1(CHARSET(cs0)), 
              SEQ(STR("/*"), 
                  REPEAT0(SEQ(NOTPRE(STR("*/")), 
                              ANY())), 
                  STR("*/")), 
              SEQ(STR("//"), 
                  REPEAT0(SEQ(NOTPRE(CHARSET(cs1)), 
                              ANY())), 
                  CHARSET(cs2))));
}
END_RULE

BEGIN_RULE(n_Identifier) {
  SEQ(NOTPRE(n_Keyword()), 
      n_Letter(), 
      REPEAT0(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_Letter) {
  ALT(CHARSET(cs3), 
      CHARSET(cs4), 
      CHARSET(cs5));
}
END_RULE

BEGIN_RULE(n_LetterOrDigit) {
  ALT(CHARSET(cs6), 
      CHARSET(cs7), 
      CHARSET(cs8), 
      CHARSET(cs9));
}
END_RULE

BEGIN_RULE(n_Keyword) {
  SEQ(ALT(ALT(STR("abstract"), 
              STR("assert"), 
              STR("boolean"), 
              STR("break"), 
              STR("byte"), 
              STR("case"), 
              STR("catch"), 
              STR("char"), 
              STR("class"), 
              STR("const")), 
          ALT(STR("continue"), 
              STR("default"), 
              STR("double"), 
              STR("do"), 
              STR("else"), 
              STR("enum"), 
              STR("extends"), 
              STR("false"), 
              STR("finally"), 
              STR("final")), 
          ALT(STR("float"), 
              STR("for"), 
              STR("goto"), 
              STR("if"), 
              STR("implements"), 
              STR("import"), 
              STR("interface"), 
              STR("int"), 
              STR("instanceof"), 
              STR("long")), 
          ALT(STR("native"), 
              STR("new"), 
              STR("null"), 
              STR("package"), 
              STR("private"), 
              STR("protected"), 
              STR("public"), 
              STR("return"), 
              STR("short"), 
              STR("static")), 
          ALT(STR("strictfp"), 
              STR("super"), 
              STR("switch"), 
              STR("synchronized"), 
              STR("this"), 
              STR("throws"), 
              STR("throw"), 
              STR("transient"), 
              STR("true"), 
              STR("try")), 
          ALT(STR("void"), 
              STR("volatile"), 
              STR("while"))), 
      NOTPRE(n_LetterOrDigit()));
}
END_RULE

BEGIN_RULE(n_ASSERT) {
  SEQ(STR("assert"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_BREAK) {
  SEQ(STR("break"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_CASE) {
  SEQ(STR("case"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_CATCH) {
  SEQ(STR("catch"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_CLASS) {
  SEQ(STR("class"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_CONTINUE) {
  SEQ(STR("continue"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_DEFAULT) {
  SEQ(STR("default"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_DO) {
  SEQ(STR("do"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_ELSE) {
  SEQ(STR("else"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_ENUM) {
  SEQ(STR("enum"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_EXTENDS) {
  SEQ(STR("extends"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_FINALLY) {
  SEQ(STR("finally"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_FINAL) {
  SEQ(STR("final"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_FOR) {
  SEQ(STR("for"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_IF) {
  SEQ(STR("if"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_IMPLEMENTS) {
  SEQ(STR("implements"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_IMPORT) {
  SEQ(STR("import"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_INTERFACE) {
  SEQ(STR("interface"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_INSTANCEOF) {
  SEQ(STR("instanceof"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_NEW) {
  SEQ(STR("new"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_PACKAGE) {
  SEQ(STR("package"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_RETURN) {
  SEQ(STR("return"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_STATIC) {
  SEQ(STR("static"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_SUPER) {
  SEQ(STR("super"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_SWITCH) {
  SEQ(STR("switch"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_SYNCHRONIZED) {
  SEQ(STR("synchronized"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_THIS) {
  SEQ(STR("this"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_THROWS) {
  SEQ(STR("throws"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_THROW) {
  SEQ(STR("throw"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_TRY) {
  SEQ(STR("try"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_VOID) {
  SEQ(STR("void"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_WHILE) {
  SEQ(STR("while"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_Literal) {
  SEQ(ALT(n_FloatLiteral(), 
          n_IntegerLiteral(), 
          n_CharLiteral(), 
          n_StringLiteral(), 
          SEQ(STR("true"), 
              NOTPRE(n_LetterOrDigit())), 
          SEQ(STR("false"), 
              NOTPRE(n_LetterOrDigit())), 
          SEQ(STR("null"), 
              NOTPRE(n_LetterOrDigit()))), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_IntegerLiteral) {
  SEQ(ALT(n_HexNumeral(), 
          n_BinaryNumeral(), 
          n_OctalNumeral(), 
          n_DecimalNumeral()), 
      OPTION(CHARSET(cs10)));
}
END_RULE

BEGIN_RULE(n_DecimalNumeral) {
  ALT(STR("0"), 
      SEQ(CHARSET(cs11), 
          REPEAT0(SEQ(REPEAT0(CHARSET(cs12)), 
                      CHARSET(cs13)))));
}
END_RULE

BEGIN_RULE(n_HexNumeral) {
  SEQ(ALT(STR("0x"), 
          STR("0X")), 
      n_HexDigits());
}
END_RULE

BEGIN_RULE(n_BinaryNumeral) {
  SEQ(ALT(STR("0b"), 
          STR("0B")), 
      CHARSET(cs14), 
      REPEAT0(SEQ(REPEAT0(CHARSET(cs15)), 
                  CHARSET(cs16))));
}
END_RULE

BEGIN_RULE(n_OctalNumeral) {
  SEQ(STR("0"), 
      REPEAT1(SEQ(REPEAT0(CHARSET(cs17)), 
                  CHARSET(cs18))));
}
END_RULE

BEGIN_RULE(n_FloatLiteral) {
  ALT(n_HexFloat(), 
      n_DecimalFloat());
}
END_RULE

BEGIN_RULE(n_DecimalFloat) {
  ALT(SEQ(n_Digits(), 
          STR("."), 
          OPTION(n_Digits()), 
          OPTION(n_Exponent()), 
          OPTION(CHARSET(cs19))), 
      SEQ(STR("."), 
          n_Digits(), 
          OPTION(n_Exponent()), 
          OPTION(CHARSET(cs20))), 
      SEQ(n_Digits(), 
          n_Exponent(), 
          OPTION(CHARSET(cs21))), 
      SEQ(n_Digits(), 
          OPTION(n_Exponent()), 
          CHARSET(cs22)));
}
END_RULE

BEGIN_RULE(n_Exponent) {
  SEQ(CHARSET(cs23), 
      OPTION(CHARSET(cs24)), 
      n_Digits());
}
END_RULE

BEGIN_RULE(n_HexFloat) {
  SEQ(n_HexSignificand(), 
      n_BinaryExponent(), 
      OPTION(CHARSET(cs25)));
}
END_RULE

BEGIN_RULE(n_HexSignificand) {
  ALT(SEQ(ALT(STR("0x"), 
              STR("0X")), 
          OPTION(n_HexDigits()), 
          STR("."), 
          n_HexDigits()), 
      SEQ(n_HexNumeral(), 
          OPTION(STR("."))));
}
END_RULE

BEGIN_RULE(n_BinaryExponent) {
  SEQ(CHARSET(cs26), 
      OPTION(CHARSET(cs27)), 
      n_Digits());
}
END_RULE

BEGIN_RULE(n_Digits) {
  SEQ(CHARSET(cs28), 
      REPEAT0(SEQ(REPEAT0(CHARSET(cs29)), 
                  CHARSET(cs30))));
}
END_RULE

BEGIN_RULE(n_HexDigits) {
  SEQ(n_HexDigit(), 
      REPEAT0(SEQ(REPEAT0(CHARSET(cs31)), 
                  n_HexDigit())));
}
END_RULE

BEGIN_RULE(n_HexDigit) {
  ALT(CHARSET(cs32), 
      CHARSET(cs33), 
      CHARSET(cs34));
}
END_RULE

BEGIN_RULE(n_CharLiteral) {
  SEQ(STR("\'"), 
      ALT(n_Escape(), 
          SEQ(NOTPRE(CHARSET(cs35)), 
              ANY())), 
      STR("\'"));
}
END_RULE

BEGIN_RULE(n_StringLiteral) {
  SEQ(STR("\""), 
      REPEAT0(ALT(n_Escape(), 
                  SEQ(NOTPRE(CHARSET(cs36)), 
                      ANY()))), 
      STR("\""));
}
END_RULE

BEGIN_RULE(n_Escape) {
  SEQ(STR("\\"), 
      ALT(CHARSET(cs37), 
          n_OctalEscape(), 
          n_UnicodeEscape()));
}
END_RULE

BEGIN_RULE(n_OctalEscape) {
  ALT(SEQ(CHARSET(cs38), 
          CHARSET(cs39), 
          CHARSET(cs40)), 
      SEQ(CHARSET(cs41), 
          CHARSET(cs42)), 
      CHARSET(cs43));
}
END_RULE

BEGIN_RULE(n_UnicodeEscape) {
  SEQ(REPEAT1(STR("u")), 
      n_HexDigit(), 
      n_HexDigit(), 
      n_HexDigit(), 
      n_HexDigit());
}
END_RULE

BEGIN_RULE(n_AT) {
  SEQ(STR("@"), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_AND) {
  SEQ(STR("&"), 
      NOTPRE(CHARSET(cs44)), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_ANDAND) {
  SEQ(STR("&&"), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_ANDEQU) {
  SEQ(STR("&="), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_BANG) {
  SEQ(STR("!"), 
      NOTPRE(STR("=")), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_BSR) {
  SEQ(STR(">>>"), 
      NOTPRE(STR("=")), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_BSREQU) {
  SEQ(STR(">>>="), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_COLON) {
  SEQ(STR(":"), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_COMMA) {
  SEQ(STR(","), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_DEC) {
  SEQ(STR("--"), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_DIV) {
  SEQ(STR("/"), 
      NOTPRE(STR("=")), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_DIVEQU) {
  SEQ(STR("/="), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_DOT) {
  SEQ(STR("."), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_ELLIPSIS) {
  SEQ(STR("..."), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_EQU) {
  SEQ(STR("="), 
      NOTPRE(STR("=")), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_EQUAL) {
  SEQ(STR("=="), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_GE) {
  SEQ(STR(">="), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_GT) {
  SEQ(STR(">"), 
      NOTPRE(CHARSET(cs45)), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_HAT) {
  SEQ(STR("^"), 
      NOTPRE(STR("=")), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_HATEQU) {
  SEQ(STR("^="), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_INC) {
  SEQ(STR("++"), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_LBRK) {
  SEQ(STR("["), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_LE) {
  SEQ(STR("<="), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_LPAR) {
  SEQ(STR("("), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_LPOINT) {
  SEQ(STR("<"), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_LT) {
  SEQ(STR("<"), 
      NOTPRE(CHARSET(cs46)), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_LWING) {
  SEQ(STR("{"), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_MINUS) {
  SEQ(STR("-"), 
      NOTPRE(CHARSET(cs47)), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_MINUSEQU) {
  SEQ(STR("-="), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_MOD) {
  SEQ(STR("%"), 
      NOTPRE(STR("=")), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_MODEQU) {
  SEQ(STR("%="), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_NOTEQUAL) {
  SEQ(STR("!="), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_OR) {
  SEQ(STR("|"), 
      NOTPRE(CHARSET(cs48)), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_OREQU) {
  SEQ(STR("|="), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_OROR) {
  SEQ(STR("||"), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_PLUS) {
  SEQ(STR("+"), 
      NOTPRE(CHARSET(cs49)), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_PLUSEQU) {
  SEQ(STR("+="), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_QUERY) {
  SEQ(STR("?"), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_RBRK) {
  SEQ(STR("]"), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_RPAR) {
  SEQ(STR(")"), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_RPOINT) {
  SEQ(STR(">"), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_RWING) {
  SEQ(STR("}"), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_SEMI) {
  SEQ(STR(";"), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_SL) {
  SEQ(STR("<<"), 
      NOTPRE(STR("=")), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_SLEQU) {
  SEQ(STR("<<="), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_SR) {
  SEQ(STR(">>"), 
      NOTPRE(CHARSET(cs50)), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_SREQU) {
  SEQ(STR(">>="), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_STAR) {
  SEQ(STR("*"), 
      NOTPRE(STR("=")), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_STAREQU) {
  SEQ(STR("*="), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_TILDA) {
  SEQ(STR("~"), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_EOT) {
  NOTPRE(ANY());
}
END_RULE

int main(int argc, char *argv[]) {
  return cpeg_main(argc, argv);
}
