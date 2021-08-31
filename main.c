#include <stdio.h>
#include "turing_automata.h"

int main() {
    struct Engine engine;
    scanf("%s", engine.input);
    engine_init(&engine);
    while(engine.index != 255 && engine.state != State_Complete && engine.state != State_Error) {
        engine_tick(&engine);
    }
    printf("%s", engine.output);
}