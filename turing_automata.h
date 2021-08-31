#ifndef TURING_AUTOMATE_TUR_AUTOMATE_H
#define TURING_AUTOMATE_TUR_AUTOMATE_H

#include "stdbool.h"

#if defined(__cplusplus)
extern "C" {
#endif

#define from_1_to_9 engine->input[engine->index] >= 49 && engine->input[engine->index] <= 57
#define symbol_0 engine->input[engine->index] == '0'
#define symbol_9 engine->input[engine->index] == '9'
#define from_0_to_8 engine->input[engine->index] >= 48 && engine->input[engine->index] <= 56

enum AutomateState {
    State_Init = 0,
    State_1, State_2,
    State_Complete, State_Error
};

struct Engine {
    enum AutomateState state;
    char input[255];
    char output[255];
    int zeros_counter;
    int index;
    int i;
};

void engine_init(struct Engine *engine);
void engine_tick(struct Engine *engine);

#endif //TURING_AUTOMATE_TUR_AUTOMATE_H
