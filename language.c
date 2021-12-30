//
// Created by luisnegrao on 12/16/21.
//
#include <stdio.h>
#include "language.h"
#include <stdlib.h>
#include <string.h>

struct CommandList *programList;

struct Expression *buildVariable(char *name) {
    struct Expression *expression = (struct Expression *) malloc(sizeof(struct Expression));
    expression->kind = E_VAR;
    expression->nome = name;
    return expression;
}

struct Expression *buildInteger(int value) {
    struct Expression *expression = (struct Expression *) malloc(sizeof(struct Expression));
    expression->kind = E_INTEGER;
    expression->value = value;
    return expression;
}

struct Expression *buildOperation(int operator, struct Expression *left, struct Expression *right) {
    struct Expression *expression = (struct Expression *) malloc(sizeof(struct Expression));
    expression->kind = E_OPERATION;
    expression->op.operator = operator;
    expression->op.left = left;
    expression->op.right = right;
    return expression;
}

struct BooleanOperation *buildBoolean(char *value) {
    struct BooleanOperation *operation = (struct BooleanOperation *) malloc(sizeof(struct BooleanOperation));
    operation->kind = E_BOOLEAN;
    operation->value = strcmp(value, "true") ? 1 : 0;
    return operation;
}

struct BooleanOperation *buildBooleanVariable(char *name) {
    struct BooleanOperation *operation = (struct BooleanOperation *) malloc(sizeof(struct BooleanOperation));
    operation->kind = E_VAR;
    operation->name = name;
    return operation;
}

struct BooleanOperation *buildBooleanOperation(int operator, struct Expression *left, struct Expression *right) {
    struct BooleanOperation *operation = (struct BooleanOperation *) malloc(sizeof(struct BooleanOperation));
    operation->kind = E_BOOLEANEXPRESSION;
    operation->op.operator = operator;
    operation->op.left = left;
    operation->op.right = right;
    return operation;
}

struct BooleanOperation *
buildAndOrOperation(int operator, struct BooleanOperation *left, struct BooleanOperation *right) {
    struct BooleanOperation *operation = (struct BooleanOperation *) malloc(sizeof(struct BooleanOperation));
    operation->kind = E_AND_OR;
    operation->and_or_op.operator = operator;
    operation->and_or_op.left = left;
    operation->and_or_op.right = right;
    return operation;
}

struct Command *buildAttrib(char *name, struct Expression *expression) {
    struct Command *command = (struct Command *) malloc(sizeof(struct Command));
    command->kind = VAR_ATTRIB;
    command->type.attrib.name = name;
    command->type.attrib.expression = expression;
    return command;
}

struct Command *buildBooleanAttrib(char *name, struct BooleanOperation *operation) {
    struct Command *command = (struct Command *) malloc(sizeof(struct Command));
    command->kind = BOOL_ATTRIB;
    command->type.attrib.name = name;
    command->type.attrib.operation = operation;
    return command;
}

struct Command *buildIf(struct BooleanOperation *operation, struct CommandList *list) {
    struct Command *command = (struct Command *) malloc(sizeof(struct Command));
    command->kind = E_IF;
    command->type.e_if.booleanOperation = operation;
    command->type.e_if.commandList = list;
    return command;
}

struct Command *
buildIfElse(struct BooleanOperation *operation, struct CommandList *ifList, struct CommandList *elseList) {
    struct Command *command = (struct Command *) malloc(sizeof(struct Command));
    command->kind = IF_ELSE;
    command->type.if_else.booleanOperation = operation;
    command->type.if_else.if_list = ifList;
    command->type.if_else.else_list = elseList;
    return command;
}

struct Command *buildWhile(struct BooleanOperation *operation, struct CommandList *list) {
    struct Command *command = (struct Command *) malloc(sizeof(struct Command));
    command->kind = E_WHILE;
    command->type.e_while.booleanOperation = operation;
    command->type.e_while.commandList = list;
    return command;
}

struct Command *buildSkip() {
    struct Command *command = (struct Command*) malloc(sizeof(struct Command));
    command->kind = E_SKIP;
    return command;
}

struct CommandList *buildCommandList(struct Command *first, struct CommandList *second) {
    struct CommandList *commandList = (struct CommandList *) malloc(sizeof(struct CommandList));
    commandList->command = first;
    commandList->next = second;
    return commandList;
}

void buildProgram(struct CommandList *list) {

    programList = (struct CommandList *) malloc(sizeof(struct CommandList));
    programList = list;

}