//
// Created by luisnegrao on 12/17/21.
//

#ifndef LINGUAGEM_RUNNER_H
#define LINGUAGEM_RUNNER_H

#include "language.h"

typedef struct HashMap {

    int locations[10000];
    struct LinkedList *variables;
} HashMap;

/**
 * Stores every variable name in order to print the final state. This avoids the need to iterate the hole map
 */
typedef struct LinkedList {
    char* name;
    struct LinkedList *next;
} *LinkedList;

void solve(struct CommandList* list);

/**
 * Hashmap that represents variable states
 */
extern struct HashMap *state;

/**
 * Initializes every global variable needed to execute the code
 */
void initState();

/**
 * Generated the index in witch the value of the variable will be stored in the hashmaps
 * @param name
 * @return
 */
int hashValue(char *name);

/**
 * Adds a given variable to the hashmap
 * @param name
 * @param value
 */
void addVariable(char *name, int value);

/**
 * Fetches the value of a given variable from the hashmap
 * @param name
 * @return value of the variable passed
 */
int getValue(char *name);

/**
 * Executes the program passed in the commandList
 * @param commandList
 */
void runProgram(struct CommandList *commandList);

/**
 *
 */
void printFinalState();

/**
 * Runs the while operation updating the state accordingly
 * @param command - while command
 */
void executeWhile(struct BooleanOperation *operation, struct CommandList* list);

/**
 * Runs the if operation updating the state accordingly
 * @param command - if command
 */
void executeIf(struct BooleanOperation *operation, struct CommandList *command);

/**
 * Runs the if_else operation updating the state accordingly
 * @param command - if_else
 */
void executeIfElse(struct BooleanOperation *operation, struct CommandList *ifList, struct CommandList *elseList);

/**
 * Runs the attrib operation updating the state accordingly
 * @param command - attrib
 */
void executeAttrib(struct Command *command);

int solveExpression (struct Expression *expression);

#endif //LINGUAGEM_RUNNER_H
