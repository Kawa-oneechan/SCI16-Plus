//KAWA WAS HERE
//-------------
// > General cleanup

#ifndef MENU_H
#define	MENU_H

#ifndef KERNEL_H
	#include "kernel.h"
#endif
#ifndef PMACHINE_H
	#include "pmachine.h"
#endif
#ifndef TYPES_H
	#include "types.h"
#endif
#ifndef GRTYPES_H
	#include "grtypes.h"
#endif

#define	MARKWIDE	8
#define	BARSIZE		10
#define	MAXMENUS	10		//maximum titles in menu bar
#define	CHECKMARK	0x10	//select menu character
#define	FIRST		1		//start index for pointer arrays

typedef struct
{
	RRect bar;
	strptr text;
	word value;
	word state;
	word key;
	memptr said;
} RMenuItem;

typedef struct
{
	RRect bar;
	strptr text;
	RRect pageRect;
	word items;
	Handle ubits;
	RMenuItem *item[1];
} MenuPage;

typedef struct
{
	RRect bar;
	word hidden;
	word pages;
	MenuPage *page[1];
} MenuBar;

extern MenuBar *theMenuBar;
extern RGrafPort menuPortStruc;
extern RGrafPort *menuPort;

void InitMenu(void);
void RDrawMenuBar(bool);
word RMenuSelect(Obj*, word);
void DrawStatus(strptr, word, word);
KERNEL(DrawStatus);
KERNEL(DrawMenuBar);
KERNEL(MenuSelect);
KERNEL(AddMenu);
KERNEL(SetMenu);
KERNEL(GetMenu);

#endif

