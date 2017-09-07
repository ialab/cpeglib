#include "cpeglib.h"

DECLARE_RULES(n_Compilation, 
              n_SUB, 
              n_EOT, 
              n_Spacing, 
              n_Identifier, 
              n_Letter, 
              n_LetterOrDigit, 
              n_Keyword, 
              n_ABSTRACT, 
              n_ASSERT, 
              n_BOOLEAN, 
              n_BREAK, 
              n_BYTE, 
              n_CASE, 
              n_CATCH, 
              n_CHAR, 
              n_CLASS, 
              n_CONTINUE, 
              n_DEFAULT, 
              n_DOUBLE, 
              n_DO, 
              n_ELSE, 
              n_ENUM, 
              n_EXTENDS, 
              n_FALSE, 
              n_FINALLY, 
              n_FINAL, 
              n_FLOAT, 
              n_FOR, 
              n_IF, 
              n_IMPLEMENTS, 
              n_IMPORT, 
              n_INTERFACE, 
              n_INT, 
              n_INSTANCEOF, 
              n_LONG, 
              n_NATIVE, 
              n_NEW, 
              n_NULL, 
              n_PACKAGE, 
              n_PRIVATE, 
              n_PROTECTED, 
              n_PUBLIC, 
              n_RETURN, 
              n_SHORT, 
              n_STATIC, 
              n_STRICTFP, 
              n_SUPER, 
              n_SWITCH, 
              n_SYNCHRONIZED, 
              n_THIS, 
              n_THROWS, 
              n_THROW, 
              n_TRANSIENT, 
              n_TRUE, 
              n_TRY, 
              n_VOID, 
              n_VOLATILE, 
              n_WHILE, 
              n_Literal, 
              n_IntegerLiteral, 
              n_DecimalNumeral, 
              n_HexNumeral, 
              n_OctalNumeral, 
              n_BinaryNumeral, 
              n_FloatLiteral, 
              n_DecimalFloatingPointLiteral, 
              n_Exponent, 
              n_HexadecimalFloatingPointLiteral, 
              n_HexSignificand, 
              n_HexDigits, 
              n_HexDigit, 
              n_BinaryExponent, 
              n_Digits, 
              n_BooleanLiteral, 
              n_CharLiteral, 
              n_StringLiteral, 
              n_Escape, 
              n_OctalEscape, 
              n_UnicodeEscape, 
              n_NullLiteral, 
              n_AT, 
              n_COLONCOLON, 
              n_COMMA, 
              n_DOT, 
              n_ELLIPSIS, 
              n_LPAR, 
              n_LBRK, 
              n_RBRK, 
              n_RPAR, 
              n_LWING, 
              n_RWING, 
              n_SEMI, 
              n_AND, 
              n_ANDAND, 
              n_ANDEQU, 
              n_ARROW, 
              n_BANG, 
              n_BSR, 
              n_BSREQU, 
              n_COLON, 
              n_DEC, 
              n_DIV, 
              n_DIVEQU, 
              n_EQU, 
              n_EQUAL, 
              n_GE, 
              n_GT, 
              n_HAT, 
              n_HATEQU, 
              n_INC, 
              n_LE, 
              n_LPOINT, 
              n_LT, 
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
              n_RPOINT, 
              n_SL, 
              n_SLEQU, 
              n_SR, 
              n_SREQU, 
              n_STAR, 
              n_STAREQU, 
              n_TILDE, 
              n_BasicType, 
              n_PrimitiveType, 
              n_ReferenceType, 
              n_ClassType, 
              n_Type, 
              n_ArrayType, 
              n_TypeVariable, 
              n_Dim, 
              n_TypeParameter, 
              n_TypeParameterModifier, 
              n_TypeBound, 
              n_AdditionalBound, 
              n_TypeArguments, 
              n_TypeArgumentList, 
              n_TypeArgument, 
              n_Wildcard, 
              n_WildcardBounds, 
              n_QualIdent, 
              n_CompilationUnit, 
              n_PackageDeclaration, 
              n_PackageModifier, 
              n_ImportDeclaration, 
              n_TypeDeclaration, 
              n_ClassDeclaration, 
              n_NormalClassDeclaration, 
              n_ClassModifier, 
              n_TypeParameters, 
              n_TypeParameterList, 
              n_Superclass, 
              n_Superinterfaces, 
              n_InterfaceTypeList, 
              n_ClassBody, 
              n_ClassBodyDeclaration, 
              n_ClassMemberDeclaration, 
              n_FieldDeclaration, 
              n_VariableDeclaratorList, 
              n_VariableDeclarator, 
              n_VariableDeclaratorId, 
              n_VariableInitializer, 
              n_UnannClassType, 
              n_UnannType, 
              n_FieldModifier, 
              n_MethodDeclaration, 
              n_MethodHeader, 
              n_MethodDeclarator, 
              n_FormalParameterList, 
              n_FormalParameter, 
              n_VariableModifier, 
              n_ReceiverParameter, 
              n_Result, 
              n_MethodModifier, 
              n_Throws, 
              n_ExceptionTypeList, 
              n_ExceptionType, 
              n_MethodBody, 
              n_InstanceInitializer, 
              n_StaticInitializer, 
              n_ConstructorDeclaration, 
              n_ConstructorDeclarator, 
              n_ConstructorModifier, 
              n_ConstructorBody, 
              n_ExplicitConstructorInvocation, 
              n_EnumDeclaration, 
              n_EnumBody, 
              n_EnumConstantList, 
              n_EnumConstant, 
              n_EnumConstantModifier, 
              n_EnumBodyDeclarations, 
              n_InterfaceDeclaration, 
              n_NormalInterfaceDeclaration, 
              n_InterfaceModifier, 
              n_ExtendsInterfaces, 
              n_InterfaceBody, 
              n_InterfaceMemberDeclaration, 
              n_ConstantDeclaration, 
              n_ConstantModifier, 
              n_InterfaceMethodDeclaration, 
              n_InterfaceMethodModifier, 
              n_AnnotationTypeDeclaration, 
              n_AnnotationTypeBody, 
              n_AnnotationTypeMemberDeclaration, 
              n_AnnotationTypeElementDeclaration, 
              n_AnnotationTypeElementModifier, 
              n_DefaultValue, 
              n_Annotation, 
              n_NormalAnnotation, 
              n_ElementValuePairList, 
              n_ElementValuePair, 
              n_ElementValue, 
              n_ElementValueArrayInitializer, 
              n_ElementValueList, 
              n_MarkerAnnotation, 
              n_SingleElementAnnotation, 
              n_ArrayInitializer, 
              n_VariableInitializerList, 
              n_Block, 
              n_BlockStatements, 
              n_BlockStatement, 
              n_LocalVariableDeclarationStatement, 
              n_LocalVariableDeclaration, 
              n_Statement, 
              n_StatementExpression, 
              n_SwitchBlock, 
              n_SwitchBlockStatementGroup, 
              n_SwitchLabels, 
              n_SwitchLabel, 
              n_EnumConstantName, 
              n_BasicForStatement, 
              n_ForInit, 
              n_ForUpdate, 
              n_StatementExpressionList, 
              n_EnhancedForStatement, 
              n_TryStatement, 
              n_CatchClause, 
              n_CatchFormalParameter, 
              n_CatchType, 
              n_Finally, 
              n_ResourceSpecification, 
              n_ResourceList, 
              n_Resource, 
              n_Expression, 
              n_Primary, 
              n_PrimaryBase, 
              n_PrimaryRest, 
              n_ParExpression, 
              n_ClassCreator, 
              n_ClassTypeWithDiamond, 
              n_TypeArgumentsOrDiamond, 
              n_ArrayCreator, 
              n_DimExpr, 
              n_Arguments, 
              n_ArgumentList, 
              n_UnaryExpression, 
              n_UnaryExpressionNotPlusMinus, 
              n_CastExpression, 
              n_InfixExpression, 
              n_InfixOperator, 
              n_ConditionalExpression, 
              n_AssignmentExpression, 
              n_Assignment, 
              n_LeftHandSide, 
              n_AssignmentOperator, 
              n_LambdaExpression, 
              n_LambdaParameters, 
              n_InferredFormalParameterList, 
              n_LambdaBody, 
              n_ConstantExpression);

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
cpeg_charset_t cs51;
cpeg_charset_t cs52;
cpeg_charset_t cs53;
cpeg_charset_t cs54;
cpeg_charset_t cs55;
cpeg_charset_t cs56;
cpeg_charset_t cs57;
cpeg_charset_t cs58;
cpeg_charset_t cs59;

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
/* cs14:[_] */
  cs_simple(cs14, '_');
/* cs15:[0-7] */
  cs_range(cs15, '0', '7');
/* cs16:[01] */
  cs_simple(cs16, '0');
  cs_simple(cs16, '1');
/* cs17:[_] */
  cs_simple(cs17, '_');
/* cs18:[01] */
  cs_simple(cs18, '0');
  cs_simple(cs18, '1');
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
/* cs26:[_] */
  cs_simple(cs26, '_');
/* cs27:[a-f] */
  cs_range(cs27, 'a', 'f');
/* cs28:[A-F] */
  cs_range(cs28, 'A', 'F');
/* cs29:[0-9] */
  cs_range(cs29, '0', '9');
/* cs30:[pP] */
  cs_simple(cs30, 'p');
  cs_simple(cs30, 'P');
/* cs31:[+-] */
  cs_simple(cs31, '+');
  cs_simple(cs31, '-');
/* cs32:[0-9] */
  cs_range(cs32, '0', '9');
/* cs33:[_] */
  cs_simple(cs33, '_');
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
/* cs45:[=] */
  cs_simple(cs45, '=');
/* cs46:[=] */
  cs_simple(cs46, '=');
/* cs47:[:] */
  cs_simple(cs47, ':');
/* cs48:[=] */
  cs_simple(cs48, '=');
/* cs49:[=] */
  cs_simple(cs49, '=');
/* cs50:[=>] */
  cs_simple(cs50, '=');
  cs_simple(cs50, '>');
/* cs51:[=] */
  cs_simple(cs51, '=');
/* cs52:[=<] */
  cs_simple(cs52, '=');
  cs_simple(cs52, '<');
/* cs53:[=->] */
  cs_simple(cs53, '=');
  cs_simple(cs53, '-');
  cs_simple(cs53, '>');
/* cs54:[=] */
  cs_simple(cs54, '=');
/* cs55:[=|] */
  cs_simple(cs55, '=');
  cs_simple(cs55, '|');
/* cs56:[=+] */
  cs_simple(cs56, '=');
  cs_simple(cs56, '+');
/* cs57:[=] */
  cs_simple(cs57, '=');
/* cs58:[=>] */
  cs_simple(cs58, '=');
  cs_simple(cs58, '>');
/* cs59:[=] */
  cs_simple(cs59, '=');
  n_Compilation();
}
END_RULE

BEGIN_RULE(n_Compilation) {
  SEQ(n_Spacing(), 
      n_CompilationUnit(), 
      OPTION(n_SUB()), 
      n_EOT());
}
END_RULE

BEGIN_RULE(n_SUB) {
  STR("\n");
}
END_RULE

BEGIN_RULE(n_EOT) {
  NOTPRE(ANY());
}
END_RULE

BEGIN_RULE(n_Spacing) {
  REPEAT0(ALT(REPEAT1(CHARSET(cs0)), 
              SEQ(STR("/*"), 
                  SEQ(REPEAT0(SEQ(NOTPRE(STR("*/")), 
                                  ANY())), 
                      STR("*/"))), 
              SEQ(STR("//"), 
                  SEQ(REPEAT0(SEQ(NOTPRE(CHARSET(cs1)), 
                                  ANY())), 
                      CHARSET(cs1)))));
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

BEGIN_RULE(n_ABSTRACT) {
  SEQ(STR("abstract"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_ASSERT) {
  SEQ(STR("assert"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_BOOLEAN) {
  SEQ(STR("boolean"), 
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

BEGIN_RULE(n_BYTE) {
  SEQ(STR("byte"), 
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

BEGIN_RULE(n_CHAR) {
  SEQ(STR("char"), 
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

BEGIN_RULE(n_DOUBLE) {
  SEQ(STR("double"), 
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

BEGIN_RULE(n_FALSE) {
  SEQ(STR("false"), 
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

BEGIN_RULE(n_FLOAT) {
  SEQ(STR("float"), 
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

BEGIN_RULE(n_INT) {
  SEQ(STR("int"), 
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

BEGIN_RULE(n_LONG) {
  SEQ(STR("long"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_NATIVE) {
  SEQ(STR("native"), 
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

BEGIN_RULE(n_NULL) {
  SEQ(STR("null"), 
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

BEGIN_RULE(n_PRIVATE) {
  SEQ(STR("private"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_PROTECTED) {
  SEQ(STR("protected"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_PUBLIC) {
  SEQ(STR("public"), 
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

BEGIN_RULE(n_SHORT) {
  SEQ(STR("short"), 
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

BEGIN_RULE(n_STRICTFP) {
  SEQ(STR("strictfp"), 
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

BEGIN_RULE(n_TRANSIENT) {
  SEQ(STR("transient"), 
      NOTPRE(n_LetterOrDigit()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_TRUE) {
  SEQ(STR("true"), 
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

BEGIN_RULE(n_VOLATILE) {
  SEQ(STR("volatile"), 
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
  ALT(n_FloatLiteral(), 
      n_IntegerLiteral(), 
      n_BooleanLiteral(), 
      n_CharLiteral(), 
      n_StringLiteral(), 
      n_NullLiteral());
}
END_RULE

BEGIN_RULE(n_IntegerLiteral) {
  SEQ(ALT(n_HexNumeral(), 
          n_BinaryNumeral(), 
          n_OctalNumeral(), 
          n_DecimalNumeral()), 
      OPTION(CHARSET(cs10)), 
      n_Spacing());
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

BEGIN_RULE(n_OctalNumeral) {
  SEQ(STR("0"), 
      REPEAT1(SEQ(REPEAT0(CHARSET(cs14)), 
                  CHARSET(cs15))));
}
END_RULE

BEGIN_RULE(n_BinaryNumeral) {
  SEQ(ALT(STR("0b"), 
          STR("0B")), 
      CHARSET(cs16), 
      REPEAT0(SEQ(REPEAT0(CHARSET(cs17)), 
                  CHARSET(cs18))));
}
END_RULE

BEGIN_RULE(n_FloatLiteral) {
  SEQ(ALT(n_HexadecimalFloatingPointLiteral(), 
          n_DecimalFloatingPointLiteral()), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_DecimalFloatingPointLiteral) {
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

BEGIN_RULE(n_HexadecimalFloatingPointLiteral) {
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

BEGIN_RULE(n_HexDigits) {
  SEQ(n_HexDigit(), 
      REPEAT0(SEQ(REPEAT0(CHARSET(cs26)), 
                  n_HexDigit())));
}
END_RULE

BEGIN_RULE(n_HexDigit) {
  ALT(CHARSET(cs27), 
      CHARSET(cs28), 
      CHARSET(cs29));
}
END_RULE

BEGIN_RULE(n_BinaryExponent) {
  SEQ(CHARSET(cs30), 
      OPTION(CHARSET(cs31)), 
      n_Digits());
}
END_RULE

BEGIN_RULE(n_Digits) {
  SEQ(CHARSET(cs32), 
      REPEAT0(SEQ(REPEAT0(CHARSET(cs33)), 
                  CHARSET(cs34))));
}
END_RULE

BEGIN_RULE(n_BooleanLiteral) {
  ALT(n_TRUE(), 
      n_FALSE());
}
END_RULE

BEGIN_RULE(n_CharLiteral) {
  SEQ(STR("\'"), 
      ALT(n_Escape(), 
          SEQ(NOTPRE(CHARSET(cs35)), 
              ANY())), 
      STR("\'"), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_StringLiteral) {
  SEQ(STR("\""), 
      REPEAT0(ALT(n_Escape(), 
                  SEQ(NOTPRE(CHARSET(cs36)), 
                      ANY()))), 
      STR("\""), 
      n_Spacing());
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

BEGIN_RULE(n_NullLiteral) {
  n_NULL();
}
END_RULE

BEGIN_RULE(n_AT) {
  SEQ(STR("@"), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_COLONCOLON) {
  SEQ(STR("::"), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_COMMA) {
  SEQ(STR(","), 
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

BEGIN_RULE(n_LPAR) {
  SEQ(STR("("), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_LBRK) {
  SEQ(STR("["), 
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

BEGIN_RULE(n_LWING) {
  SEQ(STR("{"), 
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

BEGIN_RULE(n_ARROW) {
  SEQ(STR("->"), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_BANG) {
  SEQ(STR("!"), 
      NOTPRE(CHARSET(cs45)), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_BSR) {
  SEQ(STR(">>>"), 
      NOTPRE(CHARSET(cs46)), 
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
      NOTPRE(CHARSET(cs47)), 
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
      NOTPRE(CHARSET(cs48)), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_DIVEQU) {
  SEQ(STR("/="), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_EQU) {
  SEQ(STR("="), 
      NOTPRE(CHARSET(cs49)), 
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
      NOTPRE(CHARSET(cs50)), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_HAT) {
  SEQ(STR("^"), 
      NOTPRE(CHARSET(cs51)), 
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

BEGIN_RULE(n_LE) {
  SEQ(STR("<="), 
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
      NOTPRE(CHARSET(cs52)), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_MINUS) {
  SEQ(STR("-"), 
      NOTPRE(CHARSET(cs53)), 
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
      NOTPRE(CHARSET(cs54)), 
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
      NOTPRE(CHARSET(cs55)), 
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
      NOTPRE(CHARSET(cs56)), 
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

BEGIN_RULE(n_RPOINT) {
  SEQ(STR(">"), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_SL) {
  SEQ(STR("<<"), 
      NOTPRE(CHARSET(cs57)), 
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
      NOTPRE(CHARSET(cs58)), 
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
      NOTPRE(CHARSET(cs59)), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_STAREQU) {
  SEQ(STR("*="), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_TILDE) {
  SEQ(STR("~"), 
      n_Spacing());
}
END_RULE

BEGIN_RULE(n_BasicType) {
  ALT(n_BYTE(), 
      n_SHORT(), 
      n_INT(), 
      n_LONG(), 
      n_CHAR(), 
      n_FLOAT(), 
      n_DOUBLE(), 
      n_BOOLEAN());
}
END_RULE

BEGIN_RULE(n_PrimitiveType) {
  SEQ(REPEAT0(n_Annotation()), 
      n_BasicType());
}
END_RULE

BEGIN_RULE(n_ReferenceType) {
  ALT(SEQ(n_PrimitiveType(), 
          REPEAT1(n_Dim())), 
      SEQ(n_ClassType(), 
          REPEAT0(n_Dim())));
}
END_RULE

BEGIN_RULE(n_ClassType) {
  SEQ(REPEAT0(n_Annotation()), 
      n_Identifier(), 
      OPTION(n_TypeArguments()), 
      REPEAT0(SEQ(n_DOT(), 
                  REPEAT0(n_Annotation()), 
                  n_Identifier(), 
                  OPTION(n_TypeArguments()))));
}
END_RULE

BEGIN_RULE(n_Type) {
  ALT(n_PrimitiveType(), 
      n_ClassType());
}
END_RULE

BEGIN_RULE(n_ArrayType) {
  ALT(SEQ(n_PrimitiveType(), 
          REPEAT1(n_Dim())), 
      SEQ(n_ClassType(), 
          REPEAT1(n_Dim())));
}
END_RULE

BEGIN_RULE(n_TypeVariable) {
  SEQ(REPEAT0(n_Annotation()), 
      n_Identifier());
}
END_RULE

BEGIN_RULE(n_Dim) {
  SEQ(REPEAT0(n_Annotation()), 
      n_LBRK(), 
      n_RBRK());
}
END_RULE

BEGIN_RULE(n_TypeParameter) {
  SEQ(REPEAT0(n_TypeParameterModifier()), 
      n_Identifier(), 
      OPTION(n_TypeBound()));
}
END_RULE

BEGIN_RULE(n_TypeParameterModifier) {
  n_Annotation();
}
END_RULE

BEGIN_RULE(n_TypeBound) {
  SEQ(n_EXTENDS(), 
      ALT(SEQ(n_ClassType(), 
              REPEAT0(n_AdditionalBound())), 
          n_TypeVariable()));
}
END_RULE

BEGIN_RULE(n_AdditionalBound) {
  SEQ(n_AND(), 
      n_ClassType());
}
END_RULE

BEGIN_RULE(n_TypeArguments) {
  SEQ(n_LPOINT(), 
      n_TypeArgumentList(), 
      n_RPOINT());
}
END_RULE

BEGIN_RULE(n_TypeArgumentList) {
  SEQ(n_TypeArgument(), 
      REPEAT0(SEQ(n_COMMA(), 
                  n_TypeArgument())));
}
END_RULE

BEGIN_RULE(n_TypeArgument) {
  ALT(n_ReferenceType(), 
      n_Wildcard());
}
END_RULE

BEGIN_RULE(n_Wildcard) {
  SEQ(REPEAT0(n_Annotation()), 
      n_QUERY(), 
      OPTION(n_WildcardBounds()));
}
END_RULE

BEGIN_RULE(n_WildcardBounds) {
  ALT(SEQ(n_EXTENDS(), 
          n_ReferenceType()), 
      SEQ(n_SUPER(), 
          n_ReferenceType()));
}
END_RULE

BEGIN_RULE(n_QualIdent) {
  SEQ(n_Identifier(), 
      REPEAT0(SEQ(n_DOT(), 
                  n_Identifier())));
}
END_RULE

BEGIN_RULE(n_CompilationUnit) {
  SEQ(OPTION(n_PackageDeclaration()), 
      REPEAT0(n_ImportDeclaration()), 
      REPEAT0(n_TypeDeclaration()));
}
END_RULE

BEGIN_RULE(n_PackageDeclaration) {
  SEQ(REPEAT0(n_PackageModifier()), 
      n_PACKAGE(), 
      n_Identifier(), 
      REPEAT0(SEQ(n_DOT(), 
                  n_Identifier())), 
      n_SEMI());
}
END_RULE

BEGIN_RULE(n_PackageModifier) {
  n_Annotation();
}
END_RULE

BEGIN_RULE(n_ImportDeclaration) {
  ALT(SEQ(n_IMPORT(), 
          OPTION(n_STATIC()), 
          n_QualIdent(), 
          OPTION(SEQ(n_DOT(), 
                     n_STAR())), 
          n_SEMI()), 
      n_SEMI());
}
END_RULE

BEGIN_RULE(n_TypeDeclaration) {
  ALT(n_ClassDeclaration(), 
      n_InterfaceDeclaration(), 
      n_SEMI());
}
END_RULE

BEGIN_RULE(n_ClassDeclaration) {
  ALT(n_NormalClassDeclaration(), 
      n_EnumDeclaration());
}
END_RULE

BEGIN_RULE(n_NormalClassDeclaration) {
  SEQ(REPEAT0(n_ClassModifier()), 
      n_CLASS(), 
      n_Identifier(), 
      OPTION(n_TypeParameters()), 
      OPTION(n_Superclass()), 
      OPTION(n_Superinterfaces()), 
      n_ClassBody());
}
END_RULE

BEGIN_RULE(n_ClassModifier) {
  ALT(n_Annotation(), 
      n_PUBLIC(), 
      n_PROTECTED(), 
      n_PRIVATE(), 
      n_ABSTRACT(), 
      n_STATIC(), 
      n_FINAL(), 
      n_STRICTFP());
}
END_RULE

BEGIN_RULE(n_TypeParameters) {
  SEQ(n_LPOINT(), 
      n_TypeParameterList(), 
      n_RPOINT());
}
END_RULE

BEGIN_RULE(n_TypeParameterList) {
  SEQ(n_TypeParameter(), 
      REPEAT0(SEQ(n_COMMA(), 
                  n_TypeParameter())));
}
END_RULE

BEGIN_RULE(n_Superclass) {
  SEQ(n_EXTENDS(), 
      n_ClassType());
}
END_RULE

BEGIN_RULE(n_Superinterfaces) {
  SEQ(n_IMPLEMENTS(), 
      n_InterfaceTypeList());
}
END_RULE

BEGIN_RULE(n_InterfaceTypeList) {
  SEQ(n_ClassType(), 
      REPEAT0(SEQ(n_COMMA(), 
                  n_ClassType())));
}
END_RULE

BEGIN_RULE(n_ClassBody) {
  SEQ(n_LWING(), 
      REPEAT0(n_ClassBodyDeclaration()), 
      n_RWING());
}
END_RULE

BEGIN_RULE(n_ClassBodyDeclaration) {
  ALT(n_ClassMemberDeclaration(), 
      n_InstanceInitializer(), 
      n_StaticInitializer(), 
      n_ConstructorDeclaration());
}
END_RULE

BEGIN_RULE(n_ClassMemberDeclaration) {
  ALT(n_FieldDeclaration(), 
      n_MethodDeclaration(), 
      n_ClassDeclaration(), 
      n_InterfaceDeclaration(), 
      n_SEMI());
}
END_RULE

BEGIN_RULE(n_FieldDeclaration) {
  SEQ(REPEAT0(n_FieldModifier()), 
      n_UnannType(), 
      n_VariableDeclaratorList(), 
      n_SEMI());
}
END_RULE

BEGIN_RULE(n_VariableDeclaratorList) {
  SEQ(n_VariableDeclarator(), 
      REPEAT0(SEQ(n_COMMA(), 
                  n_VariableDeclarator())));
}
END_RULE

BEGIN_RULE(n_VariableDeclarator) {
  SEQ(n_VariableDeclaratorId(), 
      OPTION(SEQ(n_EQU(), 
                 n_VariableInitializer())));
}
END_RULE

BEGIN_RULE(n_VariableDeclaratorId) {
  SEQ(n_Identifier(), 
      REPEAT0(n_Dim()));
}
END_RULE

BEGIN_RULE(n_VariableInitializer) {
  ALT(n_Expression(), 
      n_ArrayInitializer());
}
END_RULE

BEGIN_RULE(n_UnannClassType) {
  SEQ(n_Identifier(), 
      OPTION(n_TypeArguments()), 
      REPEAT0(SEQ(n_DOT(), 
                  REPEAT0(n_Annotation()), 
                  n_Identifier(), 
                  OPTION(n_TypeArguments()))));
}
END_RULE

BEGIN_RULE(n_UnannType) {
  ALT(SEQ(n_BasicType(), 
          REPEAT0(n_Dim())), 
      SEQ(n_UnannClassType(), 
          REPEAT0(n_Dim())));
}
END_RULE

BEGIN_RULE(n_FieldModifier) {
  ALT(n_Annotation(), 
      n_PUBLIC(), 
      n_PROTECTED(), 
      n_PRIVATE(), 
      n_STATIC(), 
      n_FINAL(), 
      n_TRANSIENT(), 
      n_VOLATILE());
}
END_RULE

BEGIN_RULE(n_MethodDeclaration) {
  SEQ(REPEAT0(n_MethodModifier()), 
      n_MethodHeader(), 
      n_MethodBody());
}
END_RULE

BEGIN_RULE(n_MethodHeader) {
  ALT(SEQ(n_Result(), 
          n_MethodDeclarator(), 
          OPTION(n_Throws())), 
      SEQ(n_TypeParameters(), 
          REPEAT0(n_Annotation()), 
          n_Result(), 
          n_MethodDeclarator(), 
          OPTION(n_Throws())));
}
END_RULE

BEGIN_RULE(n_MethodDeclarator) {
  SEQ(n_Identifier(), 
      n_LPAR(), 
      OPTION(n_FormalParameterList()), 
      n_RPAR(), 
      REPEAT0(n_Dim()));
}
END_RULE

BEGIN_RULE(n_FormalParameterList) {
  SEQ(ALT(n_ReceiverParameter(), 
          n_FormalParameter()), 
      REPEAT0(SEQ(n_COMMA(), 
                  n_FormalParameter())));
}
END_RULE

BEGIN_RULE(n_FormalParameter) {
  ALT(SEQ(REPEAT0(n_VariableModifier()), 
          n_UnannType(), 
          n_VariableDeclaratorId()), 
      SEQ(REPEAT0(n_VariableModifier()), 
          n_UnannType(), 
          REPEAT0(n_Annotation()), 
          n_ELLIPSIS(), 
          n_VariableDeclaratorId(), 
          NOTPRE(n_COMMA())));
}
END_RULE

BEGIN_RULE(n_VariableModifier) {
  ALT(n_Annotation(), 
      n_FINAL());
}
END_RULE

BEGIN_RULE(n_ReceiverParameter) {
  SEQ(REPEAT0(n_VariableModifier()), 
      n_UnannType(), 
      OPTION(SEQ(n_Identifier(), 
                 n_DOT())), 
      n_THIS());
}
END_RULE

BEGIN_RULE(n_Result) {
  ALT(n_UnannType(), 
      n_VOID());
}
END_RULE

BEGIN_RULE(n_MethodModifier) {
  ALT(n_Annotation(), 
      n_PUBLIC(), 
      n_PROTECTED(), 
      n_PRIVATE(), 
      n_ABSTRACT(), 
      n_STATIC(), 
      n_FINAL(), 
      n_SYNCHRONIZED(), 
      n_NATIVE(), 
      n_STRICTFP());
}
END_RULE

BEGIN_RULE(n_Throws) {
  SEQ(n_THROWS(), 
      n_ExceptionTypeList());
}
END_RULE

BEGIN_RULE(n_ExceptionTypeList) {
  SEQ(n_ExceptionType(), 
      REPEAT0(SEQ(n_COMMA(), 
                  n_ExceptionType())));
}
END_RULE

BEGIN_RULE(n_ExceptionType) {
  ALT(n_ClassType(), 
      n_TypeVariable());
}
END_RULE

BEGIN_RULE(n_MethodBody) {
  ALT(n_Block(), 
      n_SEMI());
}
END_RULE

BEGIN_RULE(n_InstanceInitializer) {
  n_Block();
}
END_RULE

BEGIN_RULE(n_StaticInitializer) {
  SEQ(n_STATIC(), 
      n_Block());
}
END_RULE

BEGIN_RULE(n_ConstructorDeclaration) {
  SEQ(REPEAT0(n_ConstructorModifier()), 
      n_ConstructorDeclarator(), 
      OPTION(n_Throws()), 
      n_ConstructorBody());
}
END_RULE

BEGIN_RULE(n_ConstructorDeclarator) {
  SEQ(OPTION(n_TypeParameters()), 
      n_Identifier(), 
      n_LPAR(), 
      OPTION(n_FormalParameterList()), 
      n_RPAR());
}
END_RULE

BEGIN_RULE(n_ConstructorModifier) {
  ALT(n_Annotation(), 
      n_PUBLIC(), 
      n_PROTECTED(), 
      n_PRIVATE());
}
END_RULE

BEGIN_RULE(n_ConstructorBody) {
  SEQ(n_LWING(), 
      OPTION(n_ExplicitConstructorInvocation()), 
      OPTION(n_BlockStatements()), 
      n_RWING());
}
END_RULE

BEGIN_RULE(n_ExplicitConstructorInvocation) {
  ALT(SEQ(OPTION(n_TypeArguments()), 
          n_THIS(), 
          n_Arguments(), 
          n_SEMI()), 
      SEQ(OPTION(n_TypeArguments()), 
          n_SUPER(), 
          n_Arguments(), 
          n_SEMI()), 
      SEQ(n_Primary(), 
          n_DOT(), 
          OPTION(n_TypeArguments()), 
          n_SUPER(), 
          n_Arguments(), 
          n_SEMI()), 
      SEQ(n_QualIdent(), 
          n_DOT(), 
          OPTION(n_TypeArguments()), 
          n_SUPER(), 
          n_Arguments(), 
          n_SEMI()));
}
END_RULE

BEGIN_RULE(n_EnumDeclaration) {
  SEQ(REPEAT0(n_ClassModifier()), 
      n_ENUM(), 
      n_Identifier(), 
      OPTION(n_Superinterfaces()), 
      n_EnumBody());
}
END_RULE

BEGIN_RULE(n_EnumBody) {
  SEQ(n_LWING(), 
      OPTION(n_EnumConstantList()), 
      OPTION(n_COMMA()), 
      OPTION(n_EnumBodyDeclarations()), 
      n_RWING());
}
END_RULE

BEGIN_RULE(n_EnumConstantList) {
  SEQ(n_EnumConstant(), 
      REPEAT0(SEQ(n_COMMA(), 
                  n_EnumConstant())));
}
END_RULE

BEGIN_RULE(n_EnumConstant) {
  SEQ(REPEAT0(n_EnumConstantModifier()), 
      n_Identifier(), 
      OPTION(n_Arguments()), 
      OPTION(n_ClassBody()));
}
END_RULE

BEGIN_RULE(n_EnumConstantModifier) {
  n_Annotation();
}
END_RULE

BEGIN_RULE(n_EnumBodyDeclarations) {
  SEQ(n_SEMI(), 
      REPEAT0(n_ClassBodyDeclaration()));
}
END_RULE

BEGIN_RULE(n_InterfaceDeclaration) {
  ALT(n_NormalInterfaceDeclaration(), 
      n_AnnotationTypeDeclaration());
}
END_RULE

BEGIN_RULE(n_NormalInterfaceDeclaration) {
  SEQ(REPEAT0(n_InterfaceModifier()), 
      n_INTERFACE(), 
      n_Identifier(), 
      OPTION(n_TypeParameters()), 
      OPTION(n_ExtendsInterfaces()), 
      n_InterfaceBody());
}
END_RULE

BEGIN_RULE(n_InterfaceModifier) {
  ALT(n_Annotation(), 
      n_PUBLIC(), 
      n_PROTECTED(), 
      n_PRIVATE(), 
      n_ABSTRACT(), 
      n_STATIC(), 
      n_STRICTFP());
}
END_RULE

BEGIN_RULE(n_ExtendsInterfaces) {
  SEQ(n_EXTENDS(), 
      n_InterfaceTypeList());
}
END_RULE

BEGIN_RULE(n_InterfaceBody) {
  SEQ(n_LWING(), 
      REPEAT0(n_InterfaceMemberDeclaration()), 
      n_RWING());
}
END_RULE

BEGIN_RULE(n_InterfaceMemberDeclaration) {
  ALT(n_ConstantDeclaration(), 
      n_InterfaceMethodDeclaration(), 
      n_ClassDeclaration(), 
      n_InterfaceDeclaration(), 
      n_SEMI());
}
END_RULE

BEGIN_RULE(n_ConstantDeclaration) {
  SEQ(REPEAT0(n_ConstantModifier()), 
      n_UnannType(), 
      n_VariableDeclaratorList(), 
      n_SEMI());
}
END_RULE

BEGIN_RULE(n_ConstantModifier) {
  ALT(n_Annotation(), 
      n_PUBLIC(), 
      n_STATIC(), 
      n_FINAL());
}
END_RULE

BEGIN_RULE(n_InterfaceMethodDeclaration) {
  SEQ(REPEAT0(n_InterfaceMethodModifier()), 
      n_MethodHeader(), 
      n_MethodBody());
}
END_RULE

BEGIN_RULE(n_InterfaceMethodModifier) {
  ALT(n_Annotation(), 
      n_PUBLIC(), 
      n_ABSTRACT(), 
      n_DEFAULT(), 
      n_STATIC(), 
      n_STRICTFP());
}
END_RULE

BEGIN_RULE(n_AnnotationTypeDeclaration) {
  SEQ(REPEAT0(n_InterfaceModifier()), 
      n_AT(), 
      n_INTERFACE(), 
      n_Identifier(), 
      n_AnnotationTypeBody());
}
END_RULE

BEGIN_RULE(n_AnnotationTypeBody) {
  SEQ(n_LWING(), 
      REPEAT0(n_AnnotationTypeMemberDeclaration()), 
      n_RWING());
}
END_RULE

BEGIN_RULE(n_AnnotationTypeMemberDeclaration) {
  ALT(n_AnnotationTypeElementDeclaration(), 
      n_ConstantDeclaration(), 
      n_ClassDeclaration(), 
      n_InterfaceDeclaration(), 
      n_SEMI());
}
END_RULE

BEGIN_RULE(n_AnnotationTypeElementDeclaration) {
  SEQ(REPEAT0(n_AnnotationTypeElementModifier()), 
      n_UnannType(), 
      n_Identifier(), 
      n_LPAR(), 
      n_RPAR(), 
      REPEAT0(n_Dim()), 
      OPTION(n_DefaultValue()), 
      n_SEMI());
}
END_RULE

BEGIN_RULE(n_AnnotationTypeElementModifier) {
  ALT(n_Annotation(), 
      n_PUBLIC(), 
      n_ABSTRACT());
}
END_RULE

BEGIN_RULE(n_DefaultValue) {
  SEQ(n_DEFAULT(), 
      n_ElementValue());
}
END_RULE

BEGIN_RULE(n_Annotation) {
  SEQ(n_AT(), 
      ALT(n_NormalAnnotation(), 
          n_SingleElementAnnotation(), 
          n_MarkerAnnotation()));
}
END_RULE

BEGIN_RULE(n_NormalAnnotation) {
  SEQ(n_QualIdent(), 
      n_LPAR(), 
      REPEAT0(n_ElementValuePairList()), 
      n_RPAR());
}
END_RULE

BEGIN_RULE(n_ElementValuePairList) {
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
      n_ElementValueArrayInitializer(), 
      n_Annotation());
}
END_RULE

BEGIN_RULE(n_ElementValueArrayInitializer) {
  SEQ(n_LWING(), 
      OPTION(n_ElementValueList()), 
      OPTION(n_COMMA()), 
      n_RWING());
}
END_RULE

BEGIN_RULE(n_ElementValueList) {
  SEQ(n_ElementValue(), 
      REPEAT0(SEQ(n_COMMA(), 
                  n_ElementValue())));
}
END_RULE

BEGIN_RULE(n_MarkerAnnotation) {
  n_QualIdent();
}
END_RULE

BEGIN_RULE(n_SingleElementAnnotation) {
  SEQ(n_QualIdent(), 
      n_LPAR(), 
      n_ElementValue(), 
      n_RPAR());
}
END_RULE

BEGIN_RULE(n_ArrayInitializer) {
  SEQ(n_LWING(), 
      OPTION(n_VariableInitializerList()), 
      OPTION(n_COMMA()), 
      n_RWING());
}
END_RULE

BEGIN_RULE(n_VariableInitializerList) {
  SEQ(n_VariableInitializer(), 
      REPEAT0(SEQ(n_COMMA(), 
                  n_VariableInitializer())));
}
END_RULE

BEGIN_RULE(n_Block) {
  SEQ(n_LWING(), 
      OPTION(n_BlockStatements()), 
      n_RWING());
}
END_RULE

BEGIN_RULE(n_BlockStatements) {
  SEQ(n_BlockStatement(), 
      REPEAT0(n_BlockStatement()));
}
END_RULE

BEGIN_RULE(n_BlockStatement) {
  ALT(n_LocalVariableDeclarationStatement(), 
      n_ClassDeclaration(), 
      n_Statement());
}
END_RULE

BEGIN_RULE(n_LocalVariableDeclarationStatement) {
  SEQ(n_LocalVariableDeclaration(), 
      n_SEMI());
}
END_RULE

BEGIN_RULE(n_LocalVariableDeclaration) {
  SEQ(REPEAT0(n_VariableModifier()), 
      n_UnannType(), 
      n_VariableDeclaratorList());
}
END_RULE

BEGIN_RULE(n_Statement) {
  ALT(ALT(n_Block(), 
          SEQ(n_IF(), 
              n_ParExpression(), 
              n_Statement(), 
              OPTION(SEQ(n_ELSE(), 
                         n_Statement()))), 
          n_BasicForStatement(), 
          n_EnhancedForStatement(), 
          SEQ(n_WHILE(), 
              n_ParExpression(), 
              n_Statement()), 
          SEQ(n_DO(), 
              n_Statement(), 
              n_WHILE(), 
              n_ParExpression(), 
              n_SEMI()), 
          n_TryStatement(), 
          SEQ(n_SWITCH(), 
              n_ParExpression(), 
              n_SwitchBlock()), 
          SEQ(n_SYNCHRONIZED(), 
              n_ParExpression(), 
              n_Block()), 
          SEQ(n_RETURN(), 
              OPTION(n_Expression()), 
              n_SEMI())), 
      ALT(SEQ(n_THROW(), 
              n_Expression(), 
              n_SEMI()), 
          SEQ(n_BREAK(), 
              OPTION(n_Identifier()), 
              n_SEMI()), 
          SEQ(n_CONTINUE(), 
              OPTION(n_Identifier()), 
              n_SEMI()), 
          SEQ(n_ASSERT(), 
              n_Expression(), 
              OPTION(SEQ(n_COLON(), 
                         n_Expression())), 
              n_SEMI()), 
          n_SEMI(), 
          SEQ(n_StatementExpression(), 
              n_SEMI()), 
          SEQ(n_Identifier(), 
              n_COLON(), 
              n_Statement())));
}
END_RULE

BEGIN_RULE(n_StatementExpression) {
  ALT(n_Assignment(), 
      SEQ(ALT(n_INC(), 
              n_DEC()), 
          ALT(n_Primary(), 
              n_QualIdent())), 
      SEQ(ALT(n_Primary(), 
              n_QualIdent()), 
          ALT(n_INC(), 
              n_DEC())), 
      n_Primary());
}
END_RULE

BEGIN_RULE(n_SwitchBlock) {
  SEQ(n_LWING(), 
      REPEAT0(n_SwitchBlockStatementGroup()), 
      REPEAT0(n_SwitchLabel()), 
      n_RWING());
}
END_RULE

BEGIN_RULE(n_SwitchBlockStatementGroup) {
  SEQ(n_SwitchLabels(), 
      n_BlockStatements());
}
END_RULE

BEGIN_RULE(n_SwitchLabels) {
  SEQ(n_SwitchLabel(), 
      REPEAT0(n_SwitchLabel()));
}
END_RULE

BEGIN_RULE(n_SwitchLabel) {
  ALT(SEQ(n_CASE(), 
          ALT(n_ConstantExpression(), 
              n_EnumConstantName()), 
          n_COLON()), 
      SEQ(n_DEFAULT(), 
          n_COLON()));
}
END_RULE

BEGIN_RULE(n_EnumConstantName) {
  n_Identifier();
}
END_RULE

BEGIN_RULE(n_BasicForStatement) {
  SEQ(n_FOR(), 
      n_LPAR(), 
      OPTION(n_ForInit()), 
      n_SEMI(), 
      OPTION(n_Expression()), 
      n_SEMI(), 
      OPTION(n_ForUpdate()), 
      n_RPAR(), 
      n_Statement());
}
END_RULE

BEGIN_RULE(n_ForInit) {
  ALT(n_LocalVariableDeclaration(), 
      n_StatementExpressionList());
}
END_RULE

BEGIN_RULE(n_ForUpdate) {
  n_StatementExpressionList();
}
END_RULE

BEGIN_RULE(n_StatementExpressionList) {
  SEQ(n_StatementExpression(), 
      REPEAT0(SEQ(n_COMMA(), 
                  n_StatementExpression())));
}
END_RULE

BEGIN_RULE(n_EnhancedForStatement) {
  SEQ(n_FOR(), 
      n_LPAR(), 
      REPEAT0(n_VariableModifier()), 
      n_UnannType(), 
      n_VariableDeclaratorId(), 
      n_COLON(), 
      n_Expression(), 
      n_RPAR(), 
      n_Statement());
}
END_RULE

BEGIN_RULE(n_TryStatement) {
  SEQ(n_TRY(), 
      ALT(SEQ(n_Block(), 
              ALT(SEQ(REPEAT0(n_CatchClause()), 
                      n_Finally()), 
                  REPEAT1(n_CatchClause()))), 
          SEQ(n_ResourceSpecification(), 
              n_Block(), 
              REPEAT0(n_CatchClause()), 
              OPTION(n_Finally()))));
}
END_RULE

BEGIN_RULE(n_CatchClause) {
  SEQ(n_CATCH(), 
      n_LPAR(), 
      n_CatchFormalParameter(), 
      n_RPAR(), 
      n_Block());
}
END_RULE

BEGIN_RULE(n_CatchFormalParameter) {
  SEQ(REPEAT0(n_VariableModifier()), 
      n_CatchType(), 
      n_VariableDeclaratorId());
}
END_RULE

BEGIN_RULE(n_CatchType) {
  SEQ(n_UnannClassType(), 
      REPEAT0(SEQ(n_OR(), 
                  n_ClassType())));
}
END_RULE

BEGIN_RULE(n_Finally) {
  SEQ(n_FINALLY(), 
      n_Block());
}
END_RULE

BEGIN_RULE(n_ResourceSpecification) {
  SEQ(n_LPAR(), 
      n_ResourceList(), 
      OPTION(n_SEMI()), 
      n_RPAR());
}
END_RULE

BEGIN_RULE(n_ResourceList) {
  SEQ(n_Resource(), 
      REPEAT0(SEQ(n_SEMI(), 
                  n_Resource())));
}
END_RULE

BEGIN_RULE(n_Resource) {
  SEQ(REPEAT0(n_VariableModifier()), 
      n_UnannType(), 
      n_VariableDeclaratorId(), 
      n_EQU(), 
      n_Expression());
}
END_RULE

BEGIN_RULE(n_Expression) {
  ALT(n_LambdaExpression(), 
      n_AssignmentExpression());
}
END_RULE

BEGIN_RULE(n_Primary) {
  SEQ(n_PrimaryBase(), 
      REPEAT0(n_PrimaryRest()));
}
END_RULE

BEGIN_RULE(n_PrimaryBase) {
  ALT(ALT(n_THIS(), 
          n_Literal(), 
          n_ParExpression(), 
          SEQ(n_SUPER(), 
              ALT(SEQ(n_DOT(), 
                      OPTION(n_TypeArguments()), 
                      n_Identifier(), 
                      n_Arguments()), 
                  SEQ(n_DOT(), 
                      n_Identifier()), 
                  SEQ(n_COLONCOLON(), 
                      OPTION(n_TypeArguments()), 
                      n_Identifier()))), 
          SEQ(n_NEW(), 
              ALT(n_ClassCreator(), 
                  n_ArrayCreator())), 
          SEQ(n_QualIdent(), 
              ALT(SEQ(n_LBRK(), 
                      n_Expression(), 
                      n_RBRK()), 
                  n_Arguments(), 
                  SEQ(n_DOT(), 
                      ALT(n_THIS(), 
                          SEQ(n_NEW(), 
                              n_ClassCreator()), 
                          SEQ(n_TypeArguments(), 
                              n_Identifier(), 
                              n_Arguments()), 
                          SEQ(n_SUPER(), 
                              n_DOT(), 
                              OPTION(n_TypeArguments()), 
                              n_Identifier(), 
                              n_Arguments()), 
                          SEQ(n_SUPER(), 
                              n_DOT(), 
                              n_Identifier()), 
                          SEQ(n_SUPER(), 
                              n_COLONCOLON(), 
                              OPTION(n_TypeArguments()), 
                              n_Identifier()))), 
                  SEQ(REPEAT0(SEQ(n_LBRK(), 
                                  n_RBRK())), 
                      n_DOT(), 
                      n_CLASS()), 
                  SEQ(n_COLONCOLON(), 
                      OPTION(n_TypeArguments()), 
                      n_Identifier()))), 
          SEQ(n_VOID(), 
              n_DOT(), 
              n_CLASS()), 
          SEQ(n_BasicType(), 
              REPEAT0(SEQ(n_LBRK(), 
                          n_RBRK())), 
              n_DOT(), 
              n_CLASS()), 
          SEQ(n_ReferenceType(), 
              n_COLONCOLON(), 
              OPTION(n_TypeArguments()), 
              n_Identifier()), 
          SEQ(n_ClassType(), 
              n_COLONCOLON(), 
              OPTION(n_TypeArguments()), 
              n_NEW())), 
      SEQ(n_ArrayType(), 
          n_COLONCOLON(), 
          n_NEW()));
}
END_RULE

BEGIN_RULE(n_PrimaryRest) {
  ALT(SEQ(n_DOT(), 
          ALT(SEQ(OPTION(n_TypeArguments()), 
                  n_Identifier(), 
                  n_Arguments()), 
              n_Identifier(), 
              SEQ(n_NEW(), 
                  n_ClassCreator()))), 
      SEQ(n_LBRK(), 
          n_Expression(), 
          n_RBRK()), 
      SEQ(n_COLONCOLON(), 
          OPTION(n_TypeArguments()), 
          n_Identifier()));
}
END_RULE

BEGIN_RULE(n_ParExpression) {
  SEQ(n_LPAR(), 
      n_Expression(), 
      n_RPAR());
}
END_RULE

BEGIN_RULE(n_ClassCreator) {
  SEQ(OPTION(n_TypeArguments()), 
      REPEAT0(n_Annotation()), 
      n_ClassTypeWithDiamond(), 
      n_Arguments(), 
      OPTION(n_ClassBody()));
}
END_RULE

BEGIN_RULE(n_ClassTypeWithDiamond) {
  SEQ(REPEAT0(n_Annotation()), 
      n_Identifier(), 
      OPTION(n_TypeArgumentsOrDiamond()), 
      REPEAT0(SEQ(n_DOT(), 
                  REPEAT0(n_Annotation()), 
                  n_Identifier(), 
                  OPTION(n_TypeArgumentsOrDiamond()))));
}
END_RULE

BEGIN_RULE(n_TypeArgumentsOrDiamond) {
  ALT(n_TypeArguments(), 
      SEQ(n_LPOINT(), 
          n_RPOINT(), 
          NOTPRE(n_DOT())));
}
END_RULE

BEGIN_RULE(n_ArrayCreator) {
  ALT(SEQ(n_Type(), 
          REPEAT1(n_DimExpr()), 
          REPEAT0(n_Dim())), 
      SEQ(n_Type(), 
          REPEAT1(n_Dim()), 
          n_ArrayInitializer()));
}
END_RULE

BEGIN_RULE(n_DimExpr) {
  SEQ(REPEAT0(n_Annotation()), 
      n_LBRK(), 
      n_Expression(), 
      n_RBRK());
}
END_RULE

BEGIN_RULE(n_Arguments) {
  SEQ(n_LPAR(), 
      OPTION(n_ArgumentList()), 
      n_RPAR());
}
END_RULE

BEGIN_RULE(n_ArgumentList) {
  SEQ(n_Expression(), 
      REPEAT0(SEQ(n_COMMA(), 
                  n_Expression())));
}
END_RULE

BEGIN_RULE(n_UnaryExpression) {
  ALT(SEQ(ALT(n_INC(), 
              n_DEC()), 
          ALT(n_Primary(), 
              n_QualIdent())), 
      SEQ(n_PLUS(), 
          n_UnaryExpression()), 
      SEQ(n_MINUS(), 
          n_UnaryExpression()), 
      n_UnaryExpressionNotPlusMinus());
}
END_RULE

BEGIN_RULE(n_UnaryExpressionNotPlusMinus) {
  ALT(SEQ(n_TILDE(), 
          n_UnaryExpression()), 
      SEQ(n_BANG(), 
          n_UnaryExpression()), 
      n_CastExpression(), 
      SEQ(ALT(n_Primary(), 
              n_QualIdent()), 
          OPTION(ALT(n_INC(), 
                     n_DEC()))));
}
END_RULE

BEGIN_RULE(n_CastExpression) {
  ALT(SEQ(n_LPAR(), 
          n_PrimitiveType(), 
          n_RPAR(), 
          n_UnaryExpression()), 
      SEQ(n_LPAR(), 
          n_ReferenceType(), 
          REPEAT0(n_AdditionalBound()), 
          n_RPAR(), 
          n_LambdaExpression()), 
      SEQ(n_LPAR(), 
          n_ReferenceType(), 
          REPEAT0(n_AdditionalBound()), 
          n_RPAR(), 
          n_UnaryExpressionNotPlusMinus()));
}
END_RULE

BEGIN_RULE(n_InfixExpression) {
  SEQ(n_UnaryExpression(), 
      REPEAT0(ALT(SEQ(n_InfixOperator(), 
                      n_UnaryExpression()), 
                  SEQ(n_INSTANCEOF(), 
                      n_ReferenceType()))));
}
END_RULE

BEGIN_RULE(n_InfixOperator) {
  ALT(ALT(n_OROR(), 
          n_ANDAND(), 
          n_OR(), 
          n_HAT(), 
          n_AND(), 
          n_EQUAL(), 
          n_NOTEQUAL(), 
          n_LT(), 
          n_GT(), 
          n_LE()), 
      ALT(n_GE(), 
          n_SL(), 
          n_SR(), 
          n_BSR(), 
          n_PLUS(), 
          n_MINUS(), 
          n_STAR(), 
          n_DIV(), 
          n_MOD()));
}
END_RULE

BEGIN_RULE(n_ConditionalExpression) {
  SEQ(n_InfixExpression(), 
      REPEAT0(SEQ(n_QUERY(), 
                  n_Expression(), 
                  n_COLON(), 
                  n_Expression())));
}
END_RULE

BEGIN_RULE(n_AssignmentExpression) {
  ALT(n_Assignment(), 
      n_ConditionalExpression());
}
END_RULE

BEGIN_RULE(n_Assignment) {
  SEQ(n_LeftHandSide(), 
      n_AssignmentOperator(), 
      n_Expression());
}
END_RULE

BEGIN_RULE(n_LeftHandSide) {
  ALT(n_Primary(), 
      n_QualIdent());
}
END_RULE

BEGIN_RULE(n_AssignmentOperator) {
  ALT(ALT(n_EQU(), 
          n_STAREQU(), 
          n_DIVEQU(), 
          n_MODEQU(), 
          n_PLUSEQU(), 
          n_MINUSEQU(), 
          n_SLEQU(), 
          n_SREQU(), 
          n_BSREQU(), 
          n_ANDEQU()), 
      ALT(n_HATEQU(), 
          n_OREQU()));
}
END_RULE

BEGIN_RULE(n_LambdaExpression) {
  SEQ(n_LambdaParameters(), 
      n_ARROW(), 
      n_LambdaBody());
}
END_RULE

BEGIN_RULE(n_LambdaParameters) {
  ALT(n_Identifier(), 
      SEQ(n_LPAR(), 
          OPTION(n_FormalParameterList()), 
          n_RPAR()), 
      SEQ(n_LPAR(), 
          n_InferredFormalParameterList(), 
          n_RPAR()));
}
END_RULE

BEGIN_RULE(n_InferredFormalParameterList) {
  SEQ(n_Identifier(), 
      REPEAT0(SEQ(n_COMMA(), 
                  n_Identifier())));
}
END_RULE

BEGIN_RULE(n_LambdaBody) {
  ALT(n_Expression(), 
      n_Block());
}
END_RULE

BEGIN_RULE(n_ConstantExpression) {
  n_Expression();
}
END_RULE

int main(int argc, char *argv[]) {
  return cpeg_main(argc, argv);
}
