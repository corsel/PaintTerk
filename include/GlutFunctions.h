#ifndef GLUTFUNCTIONS_H_INCLUDED
#define GLUTFUNCTIONS_H_INCLUDED

#include <iostream> //Debug
#include "Buffer.h"
#include "Cursor.h"
#include "MouseZone.h"
#include "Renderable.h"
#include "Widget.h"

void init(int *argc, char **argv);
void display(void);
void mouseClick(int argButton, int argState, int argX, int argY);
void mouseMove(int argX, int argY);
void idle(void);

#endif //GLUTFUNCTIONS_H_INCLUDED
