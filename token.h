#ifndef TOKEN_H
#define TOKEN_H

#include "list.h"

#define NR_TOKEN_STR 105

enum token_struct_type {
        NUMBER = 256,
        IDENTIFIER,
        OPERATOR,
        WHITESPACE,
        OTHER
};

struct token_struct {
        char str[NR_TOKEN_STR];
        int tok_type;

        struct list_node tok_list;
};

static inline int is_operator(struct token_struct *tok)
{
        return (tok->tok_type == OPERATOR);
}

static inline int is_value(struct token_struct *tok)
{
        return (tok->tok_type == NUMBER
                || tok->tok_type == IDENTIFIER);
}

static inline int is_number(struct token_struct *tok)
{
        return (tok->tok_type == NUMBER);
}

static inline int is_whtspc(struct token_struct *tok)
{
        return (tok->tok_type == WHITESPACE);
}

struct list_node *infix_to_postfix(struct list_node *);
void chg_minoper_neg(struct list_node *);
void rmv_whtspc(struct list_node *);

#endif // TOKEN_H
