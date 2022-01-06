//
// Created by luisnegrao on 12/16/21.
//

#ifndef LINGUAGEM_LANGUAGE_H
#define LINGUAGEM_LANGUAGE_H

//typedef struct Expression expression;
//typedef struct BooleanOperation booleanOperation;
//typedef struct Command command;
//typedef struct CommandList commandList;
//typedef struct Var var;
//typedef struct State state;

struct Expression {
    enum {
        E_INTEGER,
        E_OPERATION,
        E_ATTRIB,
        E_VAR
    }kind;
    int value;
    char *nome;
    struct operation {
        int operator;
        struct Expression *left;
        struct Expression *right;
    } op;
};

struct BooleanOperation {
    enum {
        E_BOOLVAR,
        E_BOOLEAN,  //ATTRIB
        E_BOOLEANEXPRESSION,
        E_AND_OR,
        E_NEG
    }kind;
    char* name;
    int value;
    struct boolOperation {
        int operator;
        struct Expression *left;
        struct Expression *right;
    } op;

    struct andOrOperation {
        int operator;
        struct BooleanOperation *left;
        struct BooleanOperation *right;
    } and_or_op;

    struct negOperatiob {
        struct BooleanOperation* operation;
    }negOp;

};

struct Command {
    enum {
        VAR_ATTRIB,
        BOOL_ATTRIB,
        E_IF,
        IF_ELSE,
        E_WHILE,
        E_SKIP,
    }kind;
    union {
        struct {
            char *name;
            struct Expression *expression;
            struct BooleanOperation *operation;
        } attrib;
        struct {
            struct BooleanOperation *booleanOperation;
            struct CommandList *commandList;
        } e_if;
        struct {
            struct BooleanOperation *booleanOperation;
            struct CommandList *if_list;
            struct CommandList *else_list;
        } if_else;
        struct {
            struct BooleanOperation *booleanOperation;
            struct CommandList *commandList;
        } e_while;
    }type   ;
};

struct CommandList {
    struct Command *command;
    struct CommandList *next;
};

extern struct CommandList* programList;

struct Expression* buildVariable (char* name);
struct Expression* buildInteger(int value);
struct Expression* buildOperation(int operator, struct Expression *left, struct Expression *right);
struct BooleanOperation* buildBooleanVariable(char* name);
struct BooleanOperation* buildBoolean(char* value);
struct BooleanOperation* buildBooleanOperation(int operator, struct Expression *left, struct Expression *right);
struct BooleanOperation* buildAndOrOperation(int operator, struct BooleanOperation *left, struct BooleanOperation *right);
struct BooleanOperation* buildNegOperation(struct BooleanOperation* operation);
struct Command* buildAttrib(char *name, struct Expression *expression);
struct Command* buildBooleanAttrib(char* name, struct BooleanOperation* operation);
struct Command* buildIf(struct BooleanOperation *operation, struct CommandList *list);
struct Command* buildIfElse(struct BooleanOperation *operation, struct CommandList *ifList, struct CommandList *elseList);
struct Command* buildWhile(struct BooleanOperation *operation, struct CommandList *list);
struct Command* buildSkip();
struct CommandList* buildCommandList(struct Command *first, struct CommandList *second);
void buildProgram(struct CommandList* list);


#endif //LINGUAGEM_LANGUAGE_H
