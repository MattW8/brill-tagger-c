#include <stdbool.h>
#include <stdlib.h>
#ifndef rule_checker_h
#define rule_checker_h
#include "rule_parser.h"
/* type passed into contextual rules for checking */
typedef struct contextual_info_t{
    int prev_tags[3]; // previous tags in order (0 is immediately previous)
    int next_tags[3]; // next tags in order (0 is immediately next)
    char *corpus; //pointer to the memory map
}contextual_info_t;

typedef enum{
    PREV_TAG_IS=0,
    NEXT_TAG_IS=1,
    PREV_2_TAG_IS=2,
    NEXT_2_TAG_IS=3,
    PREV_1_OR_2_TAG_IS=4, 
    NEXT_1_OR_2_TAG_IS=5,
    PREV_1_OR_2_OR_3_TAG_IS=6,
    NEXT_1_OR_2_OR_3_TAG_IS=7,
    PREV_TAG_IS_X_AND_NEXT_TAG_IS_Y=8,
    PREV_TAG_IS_X_AND_NEXT_2_TAG_IS_Y=9,
    NEXT_TAG_IS_X_AND_PREV_2_TAG_IS_Y=10,
    NEXT_TAG_IS_X_AND_NEXT_2_TAG_IS_Y=11,
    PREV_TAG_IS_X_AND_PREV_2_TAG_IS_Y=12
}known_word_rules_t;

typedef enum{
    REM_PREFIX=11, 
    REM_SUFFIX=12,
    PREFIX_EQUALS=13, 
    SUFFIX_EQUALS=14, 
    ADD_PREFIX=15,
    ADD_SUFFIX=16,
    PREV_WD_IS=17, 
    NEXT_WD_IS=18,
    CONTAINS_CHAR=19 
}unknown_word_rules_t;

/*known word rules rely on contextual info (tags of previous and next words) */
bool prev_tag_is(contextual_info_t, int, int);
bool next_tag_is(contextual_info_t, int, int);
bool prev_2_tag_is(contextual_info_t, int, int);
bool next_2_tag_is(contextual_info_t, int, int);
bool prev_1_or_2_tag_is(contextual_info_t, int, int);
bool next_1_or_2_tag_is(contextual_info_t, int, int);
bool prev_1_or_2_or_3_tag_is(contextual_info_t, int, int);
bool next_1_or_2_or_3_tag_is(contextual_info_t, int, int);
bool prev_tag_is_x_and_next_tag_is_y(contextual_info_t, int, int);
bool prev_tag_is_x_and_next_2_tag_is_y(contextual_info_t, int, int);
bool next_tag_is_x_and_prev_2_tag_is_y(contextual_info_t, int, int);
bool next_tag_is_x_and_next_2_tag_is_y(contextual_info_t, int, int);
bool prev_tag_is_x_and_prev_2_tag_is_y(contextual_info_t, int, int);

/* rules for known words */
bool (*known_word_rules[13]) (contextual_info_t, int, int) = {
    prev_tag_is,
    next_tag_is,
    prev_2_tag_is, //word two before is tagged X
    next_2_tag_is,
    prev_1_or_2_tag_is, //word one before or two before is tagged X
    next_1_or_2_tag_is,
    prev_1_or_2_or_3_tag_is,
    next_1_or_2_or_3_tag_is,
    prev_tag_is_x_and_next_tag_is_y,
    prev_tag_is_x_and_next_2_tag_is_y, //word 2 before is tagged Y and word 1 before is tagged X
    next_tag_is_x_and_prev_2_tag_is_y,
    next_tag_is_x_and_next_2_tag_is_y,
    prev_tag_is_x_and_prev_2_tag_is_y
};
/*unknown word rules take a char* because it allows for processing of 
word itself rather than surrounding words */
bool rem_prefix(char*);
bool rem_suffix(char*);
bool prefix_equals(char*);
bool suffix_equals(char*);
bool add_prefix(char*);
bool add_suffix(char*);
bool prev_wd_is(char*);
bool next_wd_is(char*);
bool contains_char(char*);

void store_contextual_info(contextual_info_t *, size_t, char *, size_t);
bool check_contextual_rule(contextual_rule_t, contextual_info_t);
int get_next_tag_hash(size_t *, char *, size_t, bool);
/* rules for unknown words */
bool (*unknown_word_rules[9]) (char*) = {
    rem_prefix, //removing prefix creates a known word
    rem_suffix,
    prefix_equals, //prefix is X
    suffix_equals, 
    add_prefix, //adding prefix X creates a known word
    add_suffix,
    prev_wd_is, //previous word is X
    next_wd_is,
    contains_char //word contains character X
};
#endif