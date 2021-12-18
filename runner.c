//
// Created by luisnegrao on 12/17/21.
//
#include <string.h>
#include <malloc.h>
#include "runner.h"

struct HashMap *state;

void initState() {
    state = (struct HashMap *) malloc(sizeof(struct HashMap));

}

int hashValue(char *name) {

    int total = 0;

    for (int i = 0; i < strlen(name); ++i) {
        total += (int) name[i];
    }
    //printf("%d\n", total);
    return total;
}

void addVariable(char *name, int value) {
    int index = hashValue(name);
    state->locations[index] = value;

    int alreadyIn = 0;

    if(state->variables == NULL) {
        state->variables = (struct LinkedList*) malloc(sizeof(struct LinkedList));
        state->variables->name = name;
    } else {
        struct LinkedList *list = state->variables;
        struct LinkedList *temp = state->variables;

        while (state->variables != NULL) {
            if (strcmp(state->variables->name,name) == 0) {
                alreadyIn = 1;
                state->variables = state->variables->next;
                break;
            }
            temp = state->variables;
            state->variables = state->variables->next;
        }
        if (!alreadyIn) {
            state->variables = (struct LinkedList*) malloc(sizeof(struct LinkedList));
            state->variables->name = name;
            temp->next = state->variables;
        }
    state->variables = list;
    }

}

int getValue(char *name) {

    int index = hashValue(name);
    return state->locations[index];

}

void printFinalState() {

    printf("Final State\n");
    while (state->variables->next != NULL) {
        printf("%s : %d\n", state->variables->name, getValue(state->variables->name));
        state->variables = state->variables->next;
    }
    printf("%s : %d\n", state->variables->name, getValue(state->variables->name));

}

int solveExpression(
        struct Expression *expression) { //DO IT BY CHECKING THE EXPRESSION TYPE SINCE IF IT IS E INTEGER IT ONLY HAS A NUMBER
    if (expression->kind == E_INTEGER) {
        return expression->value;
    } else if (expression->kind == E_VAR) {
        return getValue(expression->nome);
    } else {
        switch (expression->op.operator) {

            case 261: // PLUS
                return solveExpression(expression->op.left) + solveExpression(expression->op.right);
            case 262: // MULT
                return solveExpression(expression->op.left) * solveExpression(expression->op.right);
            case 263: // SUB
                return solveExpression(expression->op.left) - solveExpression(expression->op.right);
            default:
                break;

        }
    }
}

void executeAttrib(struct Command *command) {

    addVariable(command->type.attrib.name, solveExpression(command->type.attrib.expression));

}

int solveBooleanOperation(struct BooleanOperation *booleanOperation) {

    if (booleanOperation->kind == E_BOOLEAN) {
        return booleanOperation->value;
    } else if (booleanOperation->kind == E_BOOLVAR) {
        return getValue(booleanOperation->name);
    } else if (booleanOperation->kind == E_BOOLEANEXPRESSION) {
        switch (booleanOperation->op.operator) {
            case 264: //EQUALS
                return solveExpression(booleanOperation->op.left) == solveExpression(booleanOperation->op.right);
            case 265: // BIGGERTHAN
                return solveExpression(booleanOperation->op.left) > solveExpression(booleanOperation->op.right);
            case 266: //SMALLERTHAN
                return solveExpression(booleanOperation->op.left) < solveExpression(booleanOperation->op.right);
            case 267: //BIGGEREQUALS
                return solveExpression(booleanOperation->op.left) >= solveExpression(booleanOperation->op.right);
            case 268: //SMALLEREQUALS
                return solveExpression(booleanOperation->op.left) <= solveExpression(booleanOperation->op.right);
        }
    } else if (booleanOperation->kind == E_AND_OR) {
        switch (booleanOperation->and_or_op.operator) {
            case 269:
                return solveBooleanOperation(booleanOperation->and_or_op.left) &&
                       solveBooleanOperation(booleanOperation->and_or_op.right);
            case 270:
                return solveBooleanOperation(booleanOperation->and_or_op.left) ||
                       solveBooleanOperation(booleanOperation->and_or_op.right);
            default:
                printf("ARDEU\n");
        }
    }

}

void executeBoolAttrib(struct Command *command) {
    addVariable(command->type.attrib.name, solveBooleanOperation(command->type.attrib.operation));
}

void executeIf(struct BooleanOperation *operation, struct CommandList *list) {

    if (solveBooleanOperation(operation)) {
        runProgram(list);
    }

}

void executeIfElse(struct BooleanOperation *operation, struct CommandList *ifList, struct CommandList *elseList) {
    if (solveBooleanOperation(operation) == 1) {
        runProgram(ifList);
    } else {
        runProgram(elseList);
    }
}

void executeWhile(struct BooleanOperation *operation, struct CommandList *list) {

    if (solveBooleanOperation(operation)) {
        runProgram(list);
        executeWhile(operation, list);
    }

}

void solve(struct CommandList *list) {
    initState();
    runProgram(list);
    printFinalState();
};

void runProgram(struct CommandList *commandList) {

    while (commandList != NULL) {

        if (commandList->command->kind == VAR_ATTRIB) {

            executeAttrib(commandList->command);

        } else if (commandList->command->kind == BOOL_ATTRIB) {

            executeBoolAttrib(commandList->command);

        } else if (commandList->command->kind == E_WHILE) {

            executeWhile(commandList->command->type.e_while.booleanOperation,
                         commandList->command->type.e_while.commandList);

        } else if (commandList->command->kind == E_IF) {

            executeIf(commandList->command->type.e_if.booleanOperation,
                      commandList->command->type.e_if.commandList);

        } else if (commandList->command->kind == IF_ELSE) {

            executeIfElse(commandList->command->type.if_else.booleanOperation,
                          commandList->command->type.if_else.if_list,
                          commandList->command->type.if_else.else_list);

        } else {
            printf("ILLEGAL COMMAND EXCEPTION\n");
            return;
        }

        commandList = commandList->next;
    }

}