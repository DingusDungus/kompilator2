// A Bison parser, made by GNU Bison 3.7.6.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.tab.hh"


// Unqualified %code blocks.
#line 11 "parser.yy"

  #define YY_DECL yy::parser::symbol_type yylex()

  YY_DECL;

  Node* root;


#line 55 "parser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 128 "parser.tab.cc"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_goal: // goal
      case symbol_kind::S_mainClass: // mainClass
      case symbol_kind::S_typeIdentifier: // typeIdentifier
      case symbol_kind::S_typeIdentifiers: // typeIdentifiers
      case symbol_kind::S_typeIdentifierList: // typeIdentifierList
      case symbol_kind::S_expressions: // expressions
      case symbol_kind::S_expressionList: // expressionList
      case symbol_kind::S_classDeclaration: // classDeclaration
      case symbol_kind::S_classDeclarationList: // classDeclarationList
      case symbol_kind::S_classDeclarations: // classDeclarations
      case symbol_kind::S_methodDeclaration: // methodDeclaration
      case symbol_kind::S_methodDeclarationList: // methodDeclarationList
      case symbol_kind::S_methodDeclarations: // methodDeclarations
      case symbol_kind::S_extendsIdentifier: // extendsIdentifier
      case symbol_kind::S_varDeclarations: // varDeclarations
      case symbol_kind::S_varDeclaration: // varDeclaration
      case symbol_kind::S_type: // type
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_statementList: // statementList
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_end: // end
        value.YY_MOVE_OR_COPY< Node * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_RBRACE: // RBRACE
      case symbol_kind::S_RBRACKET: // RBRACKET
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_STRINGVAL: // STRINGVAL
      case symbol_kind::S_INTEGER: // INTEGER
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_EXTENDS: // EXTENDS
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_SOP: // SOP
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_SEMI_C: // SEMI_C
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_LESSER: // LESSER
      case symbol_kind::S_EQUAL: // EQUAL
      case symbol_kind::S_GREATER: // GREATER
      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUS: // MINUS
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_DIVOP: // DIVOP
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_LBRACE: // LBRACE
      case symbol_kind::S_LBRACKET: // LBRACKET
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_goal: // goal
      case symbol_kind::S_mainClass: // mainClass
      case symbol_kind::S_typeIdentifier: // typeIdentifier
      case symbol_kind::S_typeIdentifiers: // typeIdentifiers
      case symbol_kind::S_typeIdentifierList: // typeIdentifierList
      case symbol_kind::S_expressions: // expressions
      case symbol_kind::S_expressionList: // expressionList
      case symbol_kind::S_classDeclaration: // classDeclaration
      case symbol_kind::S_classDeclarationList: // classDeclarationList
      case symbol_kind::S_classDeclarations: // classDeclarations
      case symbol_kind::S_methodDeclaration: // methodDeclaration
      case symbol_kind::S_methodDeclarationList: // methodDeclarationList
      case symbol_kind::S_methodDeclarations: // methodDeclarations
      case symbol_kind::S_extendsIdentifier: // extendsIdentifier
      case symbol_kind::S_varDeclarations: // varDeclarations
      case symbol_kind::S_varDeclaration: // varDeclaration
      case symbol_kind::S_type: // type
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_statementList: // statementList
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_end: // end
        value.move< Node * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_RBRACE: // RBRACE
      case symbol_kind::S_RBRACKET: // RBRACKET
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_STRINGVAL: // STRINGVAL
      case symbol_kind::S_INTEGER: // INTEGER
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_EXTENDS: // EXTENDS
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_SOP: // SOP
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_SEMI_C: // SEMI_C
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_LESSER: // LESSER
      case symbol_kind::S_EQUAL: // EQUAL
      case symbol_kind::S_GREATER: // GREATER
      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUS: // MINUS
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_DIVOP: // DIVOP
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_LBRACE: // LBRACE
      case symbol_kind::S_LBRACKET: // LBRACKET
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_goal: // goal
      case symbol_kind::S_mainClass: // mainClass
      case symbol_kind::S_typeIdentifier: // typeIdentifier
      case symbol_kind::S_typeIdentifiers: // typeIdentifiers
      case symbol_kind::S_typeIdentifierList: // typeIdentifierList
      case symbol_kind::S_expressions: // expressions
      case symbol_kind::S_expressionList: // expressionList
      case symbol_kind::S_classDeclaration: // classDeclaration
      case symbol_kind::S_classDeclarationList: // classDeclarationList
      case symbol_kind::S_classDeclarations: // classDeclarations
      case symbol_kind::S_methodDeclaration: // methodDeclaration
      case symbol_kind::S_methodDeclarationList: // methodDeclarationList
      case symbol_kind::S_methodDeclarations: // methodDeclarations
      case symbol_kind::S_extendsIdentifier: // extendsIdentifier
      case symbol_kind::S_varDeclarations: // varDeclarations
      case symbol_kind::S_varDeclaration: // varDeclaration
      case symbol_kind::S_type: // type
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_statementList: // statementList
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_end: // end
        value.copy< Node * > (that.value);
        break;

      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_RBRACE: // RBRACE
      case symbol_kind::S_RBRACKET: // RBRACKET
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_STRINGVAL: // STRINGVAL
      case symbol_kind::S_INTEGER: // INTEGER
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_EXTENDS: // EXTENDS
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_SOP: // SOP
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_SEMI_C: // SEMI_C
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_LESSER: // LESSER
      case symbol_kind::S_EQUAL: // EQUAL
      case symbol_kind::S_GREATER: // GREATER
      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUS: // MINUS
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_DIVOP: // DIVOP
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_LBRACE: // LBRACE
      case symbol_kind::S_LBRACKET: // LBRACKET
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_goal: // goal
      case symbol_kind::S_mainClass: // mainClass
      case symbol_kind::S_typeIdentifier: // typeIdentifier
      case symbol_kind::S_typeIdentifiers: // typeIdentifiers
      case symbol_kind::S_typeIdentifierList: // typeIdentifierList
      case symbol_kind::S_expressions: // expressions
      case symbol_kind::S_expressionList: // expressionList
      case symbol_kind::S_classDeclaration: // classDeclaration
      case symbol_kind::S_classDeclarationList: // classDeclarationList
      case symbol_kind::S_classDeclarations: // classDeclarations
      case symbol_kind::S_methodDeclaration: // methodDeclaration
      case symbol_kind::S_methodDeclarationList: // methodDeclarationList
      case symbol_kind::S_methodDeclarations: // methodDeclarations
      case symbol_kind::S_extendsIdentifier: // extendsIdentifier
      case symbol_kind::S_varDeclarations: // varDeclarations
      case symbol_kind::S_varDeclaration: // varDeclaration
      case symbol_kind::S_type: // type
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_statementList: // statementList
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_end: // end
        value.move< Node * > (that.value);
        break;

      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_RBRACE: // RBRACE
      case symbol_kind::S_RBRACKET: // RBRACKET
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_STRINGVAL: // STRINGVAL
      case symbol_kind::S_INTEGER: // INTEGER
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_EXTENDS: // EXTENDS
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_SOP: // SOP
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_SEMI_C: // SEMI_C
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_LESSER: // LESSER
      case symbol_kind::S_EQUAL: // EQUAL
      case symbol_kind::S_GREATER: // GREATER
      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUS: // MINUS
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_DIVOP: // DIVOP
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_LBRACE: // LBRACE
      case symbol_kind::S_LBRACKET: // LBRACKET
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_goal: // goal
      case symbol_kind::S_mainClass: // mainClass
      case symbol_kind::S_typeIdentifier: // typeIdentifier
      case symbol_kind::S_typeIdentifiers: // typeIdentifiers
      case symbol_kind::S_typeIdentifierList: // typeIdentifierList
      case symbol_kind::S_expressions: // expressions
      case symbol_kind::S_expressionList: // expressionList
      case symbol_kind::S_classDeclaration: // classDeclaration
      case symbol_kind::S_classDeclarationList: // classDeclarationList
      case symbol_kind::S_classDeclarations: // classDeclarations
      case symbol_kind::S_methodDeclaration: // methodDeclaration
      case symbol_kind::S_methodDeclarationList: // methodDeclarationList
      case symbol_kind::S_methodDeclarations: // methodDeclarations
      case symbol_kind::S_extendsIdentifier: // extendsIdentifier
      case symbol_kind::S_varDeclarations: // varDeclarations
      case symbol_kind::S_varDeclaration: // varDeclaration
      case symbol_kind::S_type: // type
      case symbol_kind::S_statements: // statements
      case symbol_kind::S_statementList: // statementList
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_identifier: // identifier
      case symbol_kind::S_end: // end
        yylhs.value.emplace< Node * > ();
        break;

      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_RBRACE: // RBRACE
      case symbol_kind::S_RBRACKET: // RBRACKET
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_STRINGVAL: // STRINGVAL
      case symbol_kind::S_INTEGER: // INTEGER
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_EXTENDS: // EXTENDS
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_SOP: // SOP
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_SEMI_C: // SEMI_C
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_LESSER: // LESSER
      case symbol_kind::S_EQUAL: // EQUAL
      case symbol_kind::S_GREATER: // GREATER
      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUS: // MINUS
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_DIVOP: // DIVOP
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_LBRACE: // LBRACE
      case symbol_kind::S_LBRACKET: // LBRACKET
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // goal: mainClass classDeclarations end
#line 49 "parser.yy"
{
  /*
    Here we create the root node (named goal), then we add the content of addExpression (accessed through $1) as a child of the root node.
    The "root" is a reference to the root node.
  */
  yylhs.value.as < Node * > () = new Node("Goal", "");
  yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
  yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
  root = yylhs.value.as < Node * > ();
}
#line 879 "parser.tab.cc"
    break;

  case 3: // mainClass: CLASS identifier LBRACE PUBLIC STATIC VOID MAIN LP STRING LBRACKET RBRACKET identifier RP LBRACE statement RBRACE RBRACE
#line 62 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("MainClass", "");
              yylhs.value.as < Node * > ()->children.push_back(yystack_[15].value.as < Node * > ());
              /* mainMethod node */
              Node* mainMethod = new Node("PublicMainMethod","");
              yylhs.value.as < Node * > ()->children.push_back(mainMethod);
              mainMethod->children.push_back(yystack_[5].value.as < Node * > ());
              mainMethod->children.push_back(yystack_[2].value.as < Node * > ());
            }
#line 893 "parser.tab.cc"
    break;

  case 4: // typeIdentifier: type identifier
#line 73 "parser.yy"
                {
                  yylhs.value.as < Node * > () = new Node("TypeIdentifier", "");
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                }
#line 903 "parser.tab.cc"
    break;

  case 5: // typeIdentifiers: %empty
#line 81 "parser.yy"
                {
                 yylhs.value.as < Node * > () = new Node("","");
                }
#line 911 "parser.tab.cc"
    break;

  case 6: // typeIdentifiers: typeIdentifierList
#line 85 "parser.yy"
                {
                  yylhs.value.as < Node * > () = new Node("", "");
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                }
#line 920 "parser.tab.cc"
    break;

  case 7: // typeIdentifierList: typeIdentifier
#line 92 "parser.yy"
                  {
                    yylhs.value.as < Node * > () = new Node("", "");
                    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                  }
#line 929 "parser.tab.cc"
    break;

  case 8: // typeIdentifierList: typeIdentifierList COMMA typeIdentifier
#line 97 "parser.yy"
                  {
                    yylhs.value.as < Node * > () = new Node("", "");
                    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                  }
#line 939 "parser.tab.cc"
    break;

  case 9: // expressions: %empty
#line 105 "parser.yy"
                {
                  yylhs.value.as < Node * > () = new Node("","");
                }
#line 947 "parser.tab.cc"
    break;

  case 10: // expressions: expressionList
#line 109 "parser.yy"
                {
                yylhs.value.as < Node * > () = new Node("", "");
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
              }
#line 956 "parser.tab.cc"
    break;

  case 11: // expressionList: expression
#line 117 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("", "");
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
              }
#line 965 "parser.tab.cc"
    break;

  case 12: // expressionList: expressionList COMMA expression
#line 122 "parser.yy"
              {
                yylhs.value.as < Node * > () = new Node("", "");
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
              }
#line 975 "parser.tab.cc"
    break;

  case 13: // classDeclaration: CLASS identifier extendsIdentifier LBRACE varDeclarations methodDeclarations RBRACE
#line 129 "parser.yy"
                  {
                    yylhs.value.as < Node * > () = new Node("ClassDeclaration", "");
                    yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
                    yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                    yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                  }
#line 987 "parser.tab.cc"
    break;

  case 14: // classDeclarationList: classDeclaration
#line 139 "parser.yy"
                    {
                      yylhs.value.as < Node * > () = new Node("", "");
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                    }
#line 996 "parser.tab.cc"
    break;

  case 15: // classDeclarationList: classDeclarationList classDeclaration
#line 144 "parser.yy"
                    {
                      yylhs.value.as < Node * > () = new Node("", "");
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                    }
#line 1006 "parser.tab.cc"
    break;

  case 16: // classDeclarations: %empty
#line 152 "parser.yy"
                  {
                    yylhs.value.as < Node * > () = new Node("","");
                  }
#line 1014 "parser.tab.cc"
    break;

  case 17: // classDeclarations: classDeclarationList
#line 156 "parser.yy"
                  {
                    yylhs.value.as < Node * > () = new Node("", "");
                    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                  }
#line 1023 "parser.tab.cc"
    break;

  case 18: // methodDeclaration: PUBLIC type identifier LP typeIdentifiers RP LBRACE varDeclarations statements RETURN expression SEMI_C RBRACE
#line 162 "parser.yy"
                    {
                      yylhs.value.as < Node * > () = new Node("MethodDeclaration", "");
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[11].value.as < Node * > ());
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[10].value.as < Node * > ());
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[8].value.as < Node * > ());
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
                      yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                      /* return node */
                      Node* ret = new Node(yystack_[3].value.as < std::string > (),"");
                      yylhs.value.as < Node * > ()->children.push_back(ret);
                      ret->children.push_back(yystack_[2].value.as < Node * > ());
                    }
#line 1040 "parser.tab.cc"
    break;

  case 19: // methodDeclarationList: methodDeclaration
#line 176 "parser.yy"
                        {
                          yylhs.value.as < Node * > () = new Node("", "");
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                        }
#line 1049 "parser.tab.cc"
    break;

  case 20: // methodDeclarationList: methodDeclarationList methodDeclaration
#line 181 "parser.yy"
                        {
                          yylhs.value.as < Node * > () = new Node("", "");
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                        }
#line 1059 "parser.tab.cc"
    break;

  case 21: // methodDeclarations: %empty
#line 189 "parser.yy"
                  {
                    yylhs.value.as < Node * > () = new Node("","");
                  }
#line 1067 "parser.tab.cc"
    break;

  case 22: // methodDeclarations: methodDeclarationList
#line 193 "parser.yy"
                  {
                    yylhs.value.as < Node * > () = new Node("", "");
                    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                  }
#line 1076 "parser.tab.cc"
    break;

  case 23: // extendsIdentifier: %empty
#line 201 "parser.yy"
                  {
                    yylhs.value.as < Node * > () = new Node("","");
                  }
#line 1084 "parser.tab.cc"
    break;

  case 24: // extendsIdentifier: EXTENDS identifier
#line 205 "parser.yy"
                  {
                    yylhs.value.as < Node * > () = new Node("ExtendsIdentifier", "");
                    yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                  }
#line 1093 "parser.tab.cc"
    break;

  case 25: // varDeclarations: %empty
#line 212 "parser.yy"
                {
                  yylhs.value.as < Node * > () = new Node("","");
                }
#line 1101 "parser.tab.cc"
    break;

  case 26: // varDeclarations: varDeclarations varDeclaration
#line 216 "parser.yy"
                {
                  yylhs.value.as < Node * > () = new Node("", "");
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                }
#line 1111 "parser.tab.cc"
    break;

  case 27: // varDeclaration: type identifier SEMI_C
#line 225 "parser.yy"
                {
                  yylhs.value.as < Node * > () = new Node("VarDeclaration", "");
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                }
#line 1121 "parser.tab.cc"
    break;

  case 28: // type: INT LBRACKET RBRACKET
#line 232 "parser.yy"
      {
        yylhs.value.as < Node * > () = new Node("IntegerArrayType", "intArray");
      }
#line 1129 "parser.tab.cc"
    break;

  case 29: // type: BOOLEAN
#line 236 "parser.yy"
      {
        yylhs.value.as < Node * > () = new Node("BooleanType", yystack_[0].value.as < std::string > ());
      }
#line 1137 "parser.tab.cc"
    break;

  case 30: // type: INT
#line 240 "parser.yy"
      {
        yylhs.value.as < Node * > () = new Node("IntegerType", yystack_[0].value.as < std::string > ());
      }
#line 1145 "parser.tab.cc"
    break;

  case 31: // type: identifier
#line 244 "parser.yy"
      {
        yylhs.value.as < Node * > () = new Node("identifierType", "");
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
      }
#line 1154 "parser.tab.cc"
    break;

  case 32: // statements: %empty
#line 252 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("","");
            }
#line 1162 "parser.tab.cc"
    break;

  case 33: // statements: statementList
#line 256 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("", "");
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1171 "parser.tab.cc"
    break;

  case 34: // statementList: statement
#line 262 "parser.yy"
                {
                  yylhs.value.as < Node * > () = new Node("", "");
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                }
#line 1180 "parser.tab.cc"
    break;

  case 35: // statementList: statementList statement
#line 267 "parser.yy"
                {
                  yylhs.value.as < Node * > () = new Node("", "");
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                  yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
                }
#line 1190 "parser.tab.cc"
    break;

  case 36: // statement: LBRACE statements RBRACE
#line 274 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Statement", "");
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1199 "parser.tab.cc"
    break;

  case 37: // statement: IF LP expression RP statement ELSE statement
#line 279 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("IF_ElseStatement", "");
              yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1210 "parser.tab.cc"
    break;

  case 38: // statement: WHILE LP expression RP statement
#line 286 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("WhileStatement", "");
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1220 "parser.tab.cc"
    break;

  case 39: // statement: SOP LP expression RP SEMI_C
#line 292 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("SystemOutPrintStatement", "");
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
            }
#line 1229 "parser.tab.cc"
    break;

  case 40: // statement: identifier ASSIGN expression SEMI_C
#line 297 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("AssignStatement", "");
              yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1239 "parser.tab.cc"
    break;

  case 41: // statement: identifier LBRACKET expression RBRACKET ASSIGN expression SEMI_C
#line 303 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("ArrayIndexAssignStatement", "");
              yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1250 "parser.tab.cc"
    break;

  case 42: // expression: expression AND expression
#line 311 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "AndOP");
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1260 "parser.tab.cc"
    break;

  case 43: // expression: expression OR expression
#line 317 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "OrOP");
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1270 "parser.tab.cc"
    break;

  case 44: // expression: expression LESSER expression
#line 323 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "LesserOP");
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1280 "parser.tab.cc"
    break;

  case 45: // expression: expression GREATER expression
#line 329 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "GreaterOP");
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1290 "parser.tab.cc"
    break;

  case 46: // expression: expression EQUAL expression
#line 335 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "EqualsOP");
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1300 "parser.tab.cc"
    break;

  case 47: // expression: expression PLUSOP expression
#line 341 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "AddOP");
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1310 "parser.tab.cc"
    break;

  case 48: // expression: expression MINUS expression
#line 347 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "SubOP");
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1320 "parser.tab.cc"
    break;

  case 49: // expression: expression MULTOP expression
#line 353 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "Multop");
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1330 "parser.tab.cc"
    break;

  case 50: // expression: expression DIVOP expression
#line 359 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "DivOP");
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1340 "parser.tab.cc"
    break;

  case 51: // expression: expression LBRACKET expression RBRACKET
#line 365 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "ArrayIndexAccessExpression");
              yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1350 "parser.tab.cc"
    break;

  case 52: // expression: expression DOT LENGTH
#line 371 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "dotlength");
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
            }
#line 1359 "parser.tab.cc"
    break;

  case 53: // expression: expression DOT identifier LP expressions RP
#line 376 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "methodCall");
              yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1370 "parser.tab.cc"
    break;

  case 54: // expression: INTEGER
#line 383 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("IntegerLiteral", yystack_[0].value.as < std::string > ());
            }
#line 1378 "parser.tab.cc"
    break;

  case 55: // expression: TRUE
#line 387 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("BooleanExpression", yystack_[0].value.as < std::string > ());
            }
#line 1386 "parser.tab.cc"
    break;

  case 56: // expression: FALSE
#line 391 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("BooleanExpression", yystack_[0].value.as < std::string > ());
            }
#line 1394 "parser.tab.cc"
    break;

  case 57: // expression: identifier
#line 395 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("IdentifierExpression", "");
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1403 "parser.tab.cc"
    break;

  case 58: // expression: THIS
#line 400 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("ThisExpression", yystack_[0].value.as < std::string > ());
            }
#line 1411 "parser.tab.cc"
    break;

  case 59: // expression: NEW INT LBRACKET expression RBRACKET
#line 404 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "newIntArray");
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1420 "parser.tab.cc"
    break;

  case 60: // expression: NEW identifier LP RP
#line 409 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "newIdentifier");
              yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
            }
#line 1429 "parser.tab.cc"
    break;

  case 61: // expression: NOT expression
#line 414 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "NotOP");
              yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1438 "parser.tab.cc"
    break;

  case 62: // expression: LP expression RP
#line 419 "parser.yy"
            {
              yylhs.value.as < Node * > () = new Node("Expression", "");
              yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
            }
#line 1447 "parser.tab.cc"
    break;

  case 63: // identifier: IDENTIFIER
#line 425 "parser.yy"
            {
             yylhs.value.as < Node * > () = new Node("Identifier", yystack_[0].value.as < std::string > ());
            }
#line 1455 "parser.tab.cc"
    break;

  case 64: // end: "end of file"
#line 430 "parser.yy"
   {
    yylhs.value.as < Node * > () = new Node("End", "");
   }
#line 1463 "parser.tab.cc"
    break;


#line 1467 "parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        int yychecklim = yylast_ - yyn + 1;
        int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }



  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -58;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
     -23,     0,    18,     6,   -58,   -17,   -58,     0,   -58,     6,
      34,    12,    23,   -58,   -58,   -58,    14,     0,    -3,    22,
     -58,   -58,    28,    29,    48,   -58,    26,    94,   -58,    41,
      62,   -58,     0,   -58,    67,    69,     0,   -58,   -58,    37,
      35,   -58,    79,   -58,    77,    94,     0,   -58,    95,    75,
       0,   102,    63,    94,   -58,    73,   -58,   -58,    -4,     4,
     108,   117,   129,    -4,   116,   -24,   110,    -4,   -58,   -24,
      61,    61,    61,   156,   157,    61,    61,    61,   -58,    61,
      20,   -58,   -58,   -58,   -58,    61,   105,   -58,   118,   131,
     -58,   -58,   207,   168,   220,   144,   104,   172,   246,    -4,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    -6,
      61,    -4,   159,   -58,   145,   186,   -58,    61,   188,   173,
      89,    89,    74,    74,    74,    55,    55,   -34,   -34,   -58,
     191,   181,   -58,   -58,    61,   -58,   194,   -58,    -4,    61,
     -58,   233,   -58,   -58,   192,   165,   246,   -58,   -58,    61,
     246
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,    16,    63,     0,     1,     0,    14,    17,
       0,     0,    23,    15,    64,     2,     0,     0,     0,     0,
      24,    25,     0,    21,     0,    29,    30,     0,    19,    22,
       0,    26,     0,    31,     0,     0,     0,    20,    13,     0,
       0,    28,     0,    27,     0,     5,     0,     7,     0,     6,
       0,     0,     0,     0,     4,     0,    25,     8,     0,    32,
       0,     0,     0,    32,     0,     0,     0,    33,    34,    31,
       0,     0,     0,     0,     0,     0,     0,     0,    35,     0,
       0,    58,    54,    55,    56,     0,     0,    57,     0,     0,
      36,     3,     0,     0,     0,     0,     0,     0,    61,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    40,     0,     0,    62,     0,     0,     0,
      42,    43,    44,    46,    45,    47,    48,    49,    50,    52,
       0,     0,    38,    39,     0,    18,     0,    60,     0,     9,
      51,     0,    59,    37,     0,    10,    11,    41,    53,     0,
      12
  };

  const short
  parser::yypgoto_[] =
  {
     -58,   -58,   -58,   146,   -58,   -58,   -58,   -58,   189,   -58,
     -58,   182,   -58,   -58,   -58,   141,   -58,   -25,   149,   -58,
     -57,   -16,    -1,   -58
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     2,     3,    47,    48,    49,   144,   145,     8,     9,
      10,    28,    29,    30,    18,    23,    31,    32,    66,    67,
      68,    86,    87,    15
  };

  const unsigned char
  parser::yytable_[] =
  {
       5,    64,    36,     4,     1,     4,    12,   129,   109,     4,
      78,   110,    25,     4,    26,    60,    20,    61,     6,    75,
      50,    76,    33,    60,    62,    61,    33,    11,    50,     4,
      96,    39,    62,     7,    14,    42,    16,    25,     4,    26,
      63,    21,   119,    19,    33,    51,    17,    22,    63,    54,
      24,    34,    33,    27,   132,    88,    89,    65,    69,    92,
      93,    94,    65,    95,    79,    27,    65,    38,    43,    98,
       4,    35,    80,    81,    40,    41,    82,    83,    84,    97,
      44,   143,    45,    46,   120,   121,   122,   123,   124,   125,
     126,   127,   128,    85,   131,   107,   108,   109,    65,    52,
     110,   136,    25,     4,    26,    53,    55,    56,   130,    99,
      65,    70,   105,   106,   107,   108,   109,    58,   141,   110,
      71,    74,   111,   146,   102,   103,   104,   105,   106,   107,
     108,   109,    72,   150,   110,   112,    77,    65,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   116,   117,
     110,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,    90,    91,   110,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   114,   118,   110,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   140,   134,   110,
     133,   135,   137,   138,   139,   149,   148,    59,    13,    57,
     142,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,    37,    73,   110,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,     0,     0,   110,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,     0,   113,   110,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
       0,   115,   110,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,     0,   147,   110,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,     0,     0,   110,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,     0,
       0,   110
  };

  const short
  parser::yycheck_[] =
  {
       1,    58,    27,     9,    27,     9,     7,    13,    42,     9,
      67,    45,     8,     9,    10,    19,    17,    21,     0,    43,
      45,    45,    23,    19,    28,    21,    27,    44,    53,     9,
      10,    32,    28,    27,     0,    36,    24,     8,     9,    10,
      44,    44,    99,    29,    45,    46,    23,    25,    44,    50,
      22,     3,    53,    24,   111,    71,    72,    58,    59,    75,
      76,    77,    63,    79,     3,    24,    67,     5,    31,    85,
       9,    45,    11,    12,     7,     6,    15,    16,    17,    80,
      45,   138,     3,     6,   100,   101,   102,   103,   104,   105,
     106,   107,   108,    32,   110,    40,    41,    42,    99,     4,
      45,   117,     8,     9,    10,    30,     4,    44,   109,     4,
     111,     3,    38,    39,    40,    41,    42,    44,   134,    45,
       3,     5,     4,   139,    35,    36,    37,    38,    39,    40,
      41,    42,     3,   149,    45,     4,    26,   138,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,     4,    45,
      45,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,     5,     5,    45,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,     6,     3,    45,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,     6,    43,    45,
      31,     5,     4,    20,     3,    30,     4,    56,     9,    53,
       6,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    29,    63,    45,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    -1,    -1,    45,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    -1,    31,    45,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    31,    45,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    -1,    31,    45,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    -1,    -1,    45,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    -1,
      -1,    45
  };

  const signed char
  parser::yystos_[] =
  {
       0,    27,    47,    48,     9,    68,     0,    27,    54,    55,
      56,    44,    68,    54,     0,    69,    24,    23,    60,    29,
      68,    44,    25,    61,    22,     8,    10,    24,    57,    58,
      59,    62,    63,    68,     3,    45,    63,    57,     5,    68,
       7,     6,    68,    31,    45,     3,     6,    49,    50,    51,
      63,    68,     4,    30,    68,     4,    44,    49,    44,    61,
      19,    21,    28,    44,    66,    68,    64,    65,    66,    68,
       3,     3,     3,    64,     5,    43,    45,    26,    66,     3,
      11,    12,    15,    16,    17,    32,    67,    68,    67,    67,
       5,     5,    67,    67,    67,    67,    10,    68,    67,     4,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      45,     4,     4,    31,     6,    31,     4,    45,     3,    66,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    13,
      68,    67,    66,    31,    43,     5,    67,     4,    20,     3,
       6,    67,     6,    66,    52,    53,    67,    31,     4,    30,
      67
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    46,    47,    48,    49,    50,    50,    51,    51,    52,
      52,    53,    53,    54,    55,    55,    56,    56,    57,    58,
      58,    59,    59,    60,    60,    61,    61,    62,    63,    63,
      63,    63,    64,    64,    65,    65,    66,    66,    66,    66,
      66,    66,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    68,    69
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     3,    17,     2,     0,     1,     1,     3,     0,
       1,     1,     3,     7,     1,     2,     0,     1,    13,     1,
       2,     0,     1,     0,     2,     0,     2,     3,     3,     1,
       1,     1,     0,     1,     1,     2,     3,     7,     5,     5,
       4,     7,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     4,     3,     6,     1,     1,     1,     1,     1,     5,
       4,     2,     3,     1,     1
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "LP", "RP", "RBRACE",
  "RBRACKET", "STRING", "BOOLEAN", "IDENTIFIER", "INT", "NEW", "THIS",
  "LENGTH", "STRINGVAL", "INTEGER", "TRUE", "FALSE", "FOR", "IF", "ELSE",
  "WHILE", "MAIN", "EXTENDS", "PUBLIC", "VOID", "RETURN", "CLASS", "SOP",
  "STATIC", "COMMA", "SEMI_C", "NOT", "AND", "OR", "LESSER", "EQUAL",
  "GREATER", "PLUSOP", "MINUS", "MULTOP", "DIVOP", "DOT", "ASSIGN",
  "LBRACE", "LBRACKET", "$accept", "goal", "mainClass", "typeIdentifier",
  "typeIdentifiers", "typeIdentifierList", "expressions", "expressionList",
  "classDeclaration", "classDeclarationList", "classDeclarations",
  "methodDeclaration", "methodDeclarationList", "methodDeclarations",
  "extendsIdentifier", "varDeclarations", "varDeclaration", "type",
  "statements", "statementList", "statement", "expression", "identifier",
  "end", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    48,    48,    61,    72,    81,    84,    91,    96,   105,
     108,   116,   121,   128,   138,   143,   152,   155,   161,   175,
     180,   189,   192,   201,   204,   212,   215,   224,   231,   235,
     239,   243,   252,   255,   261,   266,   273,   278,   285,   291,
     296,   302,   310,   316,   322,   328,   334,   340,   346,   352,
     358,   364,   370,   375,   382,   386,   390,   394,   399,   403,
     408,   413,   418,   424,   429
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 2055 "parser.tab.cc"

