/* -HEADER----------------------------------------------------------------------
UniCC LALR(1) Parser Generator
Copyright (C) 2006-2013 by Phorward Software Technologies, Jan Max Meyer
http://unicc.phorward-software.com/ ++ unicc<<AT>>phorward-software<<DOT>>com

File:	p_proto.h (created on 30.01.2007)
Author:	Jan Max Meyer
Usage:	Prototype declarations

You may use, modify and distribute this software under the terms and conditions
of the Artistic License, version 2. Please see LICENSE for more information.
----------------------------------------------------------------------------- */

#ifndef P_PROTO_H
#define P_PROTO_H

/* p_first.c */
void p_first( LIST* symbols );
int p_rhs_first( LIST** first, LIST* rhs );

/* p_lalr_gen.c */
void p_generate_tables( PARSER* parser );
void p_detect_default_productions( PARSER* parser );

/* p_error.c */
void p_error( PARSER* parser, int err_id, int err_style, ... );

/* p_mem.c */
SYMBOL* p_get_symbol( PARSER* p, void* dfn, int type, BOOLEAN create );
void p_free_symbol( SYMBOL* sym );
PROD* p_create_production( PARSER* p, SYMBOL* lhs );
void p_append_to_production( PROD* p, SYMBOL* sym, char* name );
void p_free_production( PROD* prod );
ITEM* p_create_item( STATE* st, PROD* p, LIST* lookahead );
void p_free_item( ITEM* it );
STATE* p_create_state( PARSER* p );
void p_free_state( STATE* st );
TABCOL* p_create_tabcol( SYMBOL* sym, short action, int index, ITEM* item );
void p_free_tabcol( TABCOL* act );
TABCOL* p_find_tabcol( LIST* row, SYMBOL* sym );
OPT* p_create_opt( HASHTAB* ht, char* opt, char* def );
void p_free_opt( OPT* option );
PARSER* p_create_parser( void );
void p_free_parser( PARSER* parser );
VTYPE* p_find_vtype( PARSER* p, char* name );
VTYPE* p_create_vtype( PARSER* p, char* name );
void p_free_vtype( VTYPE* vt );

/* p_integrity.c */
BOOLEAN p_undef_or_unused( PARSER* parser );
BOOLEAN p_regex_anomalies( PARSER* parser );
BOOLEAN p_stupid_productions( PARSER* parser );

/* p_string.c */
char* p_int_to_str( int val );
char* p_long_to_str( long val );
char* p_str_no_whitespace( char* str );

/* p_util.c */
char* p_derivation_name( char* name, char append_char );
int p_unescape_char( char* str, char** strfix );
SYMBOL* p_find_base_symbol( SYMBOL* sym );
char* p_gen_c_identifier( char* str, BOOLEAN to_upper );

/* p_rewrite.c */
void p_rewrite_grammar( PARSER* parser );
void p_unique_charsets( PARSER* parser );
void p_fix_precedences( PARSER* parser );
void p_inherit_fixiations( PARSER* parser );
void p_inherit_vtypes( PARSER* parser );
void p_setup_single_goal( PARSER* parser );
void p_symbol_order( PARSER* parser );
void p_charsets_to_ptn( PARSER* parser );

/* p_virtual.c */
SYMBOL* p_positive_closure( PARSER* parser, SYMBOL* base );
SYMBOL* p_kleene_closure( PARSER* parser, SYMBOL* base );
SYMBOL* p_optional_closure( PARSER* parser, SYMBOL* base );

/* p_main.c */
char* p_version( BOOLEAN long_version );

/* p_debug.c */
void p_print_symbol( FILE* stream, SYMBOL* sym );
void p_dump_grammar( FILE* stream, PARSER* parser );
void p_dump_symbols( FILE* stream, PARSER* parser );
void p_dump_item_set( FILE* stream, char* title, LIST* list );
void p_dump_lalr_states( FILE* stream, PARSER* parser );
void p_dump_productions( FILE* stream, PARSER* parser );
void p_dump_production( FILE* stream, PROD* prod,
		BOOLEAN with_lhs, BOOLEAN semantics );

/* p_parse.c / p_parse.syn */
int p_parse( PARSER* p, char* src );

/* p_keywords.c */
void p_keywords_to_dfa( PARSER* parser );
void p_single_lexer( PARSER* parser );
pregex_dfa* p_find_equal_dfa( PARSER* parser, pregex_dfa* ndfa );
void p_symbol_to_nfa( PARSER* parser, pregex_nfa* nfa, SYMBOL* sym );

/* p_build.c */
void p_build_code( PARSER* parser );
char* p_build_action( PARSER* parser, GENERATOR* g,
			PROD* p, char* base, BOOLEAN def_code );
char* p_build_scan_action( PARSER* parser, GENERATOR* g, SYMBOL* s,
			char* base );
char* p_escape_for_target( GENERATOR* g, char* str, BOOLEAN clear );
char* p_mkproduction_str( PROD* p );
BOOLEAN p_load_generator( PARSER* parser, GENERATOR* g, char* genfile );

/* p_xml.c */
void p_build_xml( PARSER* parser, BOOLEAN finished );

#endif
