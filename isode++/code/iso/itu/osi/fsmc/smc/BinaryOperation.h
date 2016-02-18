/*
 * BinaryOperation.h
 *
 *  Created on: 20 janv. 2016
 *      Author: FrancisANDRE
 */

#ifndef BINARYOPERATION_H_
#define BINARYOPERATION_H_

#include "fsmc/smc/Expression.h"
#include "fsmc/smc/Operation.h"

namespace ALS {
	namespace SMC {
		namespace MODEL {

			class BinaryOperation : public Operation {
			private:
				ExpressionPtr		_left;
				ExpressionPtr		_right;

			public:
				BinaryOperation(Operator op) : Operation(op) {
				}
				virtual ~BinaryOperation() {
				}
				ExpressionPtr&	left()				{ return _left; }
				ExpressionPtr&	right()				{ return _right; }
				const ExpressionPtr	left() const	{ return _left; }
				const ExpressionPtr	right()const	{ return _right; }
				virtual const string display() const;
			};

		}
	}
}

#endif
#if 0
conditional-expression:
    logical-or-expression
    logical-or-expression ? expression : conditional-expression
logical-or-expression:
    logical-and-expression
    logical-or-expression   ||   logical-and-expression
logical-and-expression:
    inclusive-or-expression
    logical-and-expression   &&   inclusive-or-expression
inclusive-or-expression:
    exclusive-or-expression
    inclusive-or-expression | exclusive-or-expression
exclusive-or-expression:
    and-expression
    exclusive-or-expression ^ and-expression
and-expression:
    equality-expression
    and-expression & equality-expression
equality-expression:
    relational-expression
    equality-expression == relational-expression
    equality-expression != relational-expression
relational-expression:
    shift-expression
    relational-expression < shift-expression
    relational-expression > shift-expression
    relational-expression <= shift-expression
    relational-expression => shift-expression
shift-expression:
    additive-expression
    shift-expression << additive-expression
    shift-expression >> additive-expression
additive-expression:
    multiplicative-expression
    additive-expression + multiplicative-expression
    additive-expression – multiplicative-expression
multiplicative-expression:
    segment-expression
    multiplicative-expression * segment-expression
    multiplicative-expression / segment-expression
    multiplicative-expression % segment-expression
segment-expression:
    pm-expression
    segment-expression :> pm-expression
pm-expression:
    cast-expression
    pm-expression .* cast-expression
    pm-expression –>* cast-expression
cast-expression:
    unary-expression
    ( type-name ) cast-expression 
unary-expression:
    postfix-expression
    ++ unary-expression
    –– unary-expression
    unary-operator cast-expression
    sizeof unary-expression
    sizeof ( type-name )
    allocation-expression
    deallocation-expression
unary-operator: one of
    * & + – ! ~
allocation-expression:
    ::opt new placementopt new-type-name new-initializeropt
    ::opt new placementopt ( type-name )   new-initializeropt
placement:
    ( expression-list )
new-type-name:
    type-specifier-list new-declaratoropt
new-declarator:
    ms-modifier-list opt   * cv-qualifier-list opt new-declaratoropt
    ms-modifier-list opt   complete-class-name :: *cv-qualifier-listopt
    new-declaratoropt
    new-declaratoropt [ expression ]
new-initializer:
    ( initializer-list )
deallocation-expression:
    ::opt delete cast-expression
    ::opt delete [ ] cast-expression
postfix-expression:
    primary-expression
    postfix-expression [ expression ]
    postfix-expression   ( expression-list )
    simple-type-name ( expression-list )
    postfix-expression . name
    postfix-expression –>   name
    postfix-expression ++
    postfix-expression ––
    dynamic_cast < type-id > ( expression )
    static_cast < type-id > ( expression )
    const_cast < type-id > ( expression )
    reinterpret_cast < type-id > ( expression )
    typeid( expression )
    typeid( type-id )
expression-list:
    assignment-expression
    expression-list , assignment-expression
primary-expression:
    literal
    this
    :: identifier
    :: operator-function-name
    :: qualified-name ( expression )
    name
name:
    identifier
    operator-function-name
    conversion-function-name
       ~ class-name
    qualified-name
qualified-name:
    ms-modifier-listopt qualified-class-name :: name
literal:
    integer-constant
    character-constant
    floating-constant
    string-literal
integer-constant:
    decimal-constant integer-suffixopt
    octal-constant integer-suffixopt
    hexadecimal-constant integer-suffixopt
    'c-char-sequence'
decimal-constant:
    nonzero-digit
    decimal-constant digit
octal-constant:
    0
    octal-constant octal-digit
hexadecimal-constant:
    0x hexadecimal-digit
    0X hexadecimal-digit
    hexadecimal-constant hexadecimal-digit
nonzero-digit: one of
    1 2 3 4 5 6 7 8 9
octal-digit: one of
    0 1 2 3 4 5 6 7
hexadecimal-digit: one of
    0 1 2 3 4 5 6 7 8 9
    a b c d e f
    A B C D E F
integer-suffix:
    unsigned-suffix long-suffixopt
    long-suffix unsigned-suffixopt
unsigned-suffix: one of
    u U
long-suffix: one of
    l L
character-constant:
    'c-char-sequence'
    L'c-char-sequence'
c-char-sequence:
    c-char
    c-char-sequence c-char
c-char:
    any member of the source character set except the single quote ('),
       backslash (\), or newline character
    escape-sequence
escape-sequence:
    simple-escape-sequence
    octal-escape-sequence
    hexadecimal-escape-sequence
simple-escape-sequence: one of
    \' \" \? \\
    \a \b \f \n \r \t \v
octal-escape-sequence:
    \ octal-digit
    \ octal-digit octal-digit
    \ octal-digit octal-digit octal-digit
hexadecimal-escape-sequence:
    \xhexadecimal-digit
    hexadecimal-escape-sequence hexadecimal-digit
floating-constant:
    fractional-constant exponent-partopt floating-suffixopt
    digit-sequence exponent-part floating-suffixopt
fractional-constant:
    digit-sequenceopt . digit-sequence
    digit-sequence .
exponent-part:
    e signopt digit-sequence
    E signopt digit-sequence
sign: one of
    + –
digit-sequence:
    digit
    digit-sequence digit
floating-suffix: one of
    f l F L
string literal:
    ''s-char-sequence opt''
    L ''s-char-sequence opt''
s-char-sequence:
    s-char
    s-char-sequence s-char
s-char:
    any member of the source character set except double quotation marks ("), backslash (\), or newline character
    escape-sequence
#endif