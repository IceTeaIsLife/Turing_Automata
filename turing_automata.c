#include <stdio.h>
#include "turing_automata.h"

void engine_init(struct Engine *engine) {
    engine->state = State_Init;
    engine->index = -1;
    engine->zeros_counter = 0;
    engine->i = 0;
    int i = 0;
    for (i; i < 255; i++) {
        engine->output[i] = 0;
    }
}

void engine_tick(struct Engine *engine) {
    if (0 == engine)
        return;
    switch (engine->state) {
        case State_Init: {
            int i = 0;
            for (i; i < 255; i++) {
                if (engine->input[i] != 0) {
                    engine->output[i] = engine->input[i];
                    engine->index++;
                } else break;
            }
            if (engine->index != -1) {
                engine->state = State_1;
            } else {
                engine->state = State_Error;
            }
            break;
        }

        case State_1: {
            if (symbol_9 && engine->index != 0) {
                engine->state = State_1;
                engine->output[engine->index + engine->zeros_counter] = '0';
                engine->index -= 1;
            } else if (from_0_to_8) {
                engine->state = State_2;
            } else {
                engine->state = State_Error;
            }
            break;
        }

        case State_2: {
            engine->output[engine->index] += 1;
            while (engine->output[engine->i] == '0') {
                engine->output[engine->i] = '\b';
                engine->i++;
            }
            if (engine->output[0] != '0') { engine->state = State_Complete; }

            break;
        }

        case State_Error: {
            printf("%s", "Error");
            break;
        }

        case State_Complete:
            break;
    }
}