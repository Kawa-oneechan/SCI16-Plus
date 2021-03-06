//	mouse.h

//KAWA WAS HERE
//-------------
// > General cleanup
// > added #define MOUSE_H

#ifndef MOUSE_H
#define MOUSE_H

#ifndef GRTYPES_H
	#include "grtypes.h"
#endif

extern word haveMouse;
extern word mouseX;
extern word mouseY;
extern bool	mouseIsDebug;
extern RRect restrict;
extern RRect *restrictRecPtr;
extern word	buttonState;

word CurMouse(RPoint*);
void DisposeMouse(void);
void InstallMouse(void);
word RGetMouse(RPoint*);
void SetMouse(RPoint *pt);

#endif

