// AUDIO.H

//KAWA WAS HERE
//-------------
// > General cleanup

#ifndef AUDIO_H
#define AUDIO_H

#ifndef TYPES_H
	#include "types.h"
#endif

#define AUDMODNUM	65535U
#define MAXQ		10

extern int audVolFd;
extern int sfxVolFd;

//Codes to be sent to the audio driver.
#define A_INIT		0
#define A_STAT		1
#define A_TERMINATE	2
#define A_MEMPLAY	3
#define A_MEMCHECK	4
#define A_MEMSTOP	5
#define A_RATE		6
#define A_PAUSE		7
#define A_RESUME	8
#define A_SELECT	9
#define A_WPLAY		10
#define A_PLAY		11
#define A_STOP		12
#define A_LOC		13
#define A_VOLUME	14
#define A_FILLBUFF	15
#define A_QUEUE		16

enum audioFuncs
{
	WPLAY = 1,
	PLAY,
	STOP,
	PAUSE,
	RESUME,
	LOC,
	RATE,
	VOLUME,
	DACFOUND,
	CDREDBOOK,
	QUEUE
};

KERNEL(DoAudio);
void SetAudParms(word*);
uint GetAudQCnt(int);

bool InitAudioDriver(void);
void EndAudio(void);
bool SelectAudio(char);
ulong FindAudEntry(uint);
ulong FindAud36Entry(uint, byte, byte, byte, byte);
void AudioWPlay(void);
void AudioPlay(void);
void AudioStop(void);
void AudioPause(byte resType, uint resId);
void AudioResume(void);
int AudioLoc(void);
uint AudioRate(uint hertz);
void AudioVol(int vol);
void AudioFill(void);

KERNEL(CDAudio);
bool CDAudioPlay(word*);
int CDAudioLoc(void);
bool InitCDAudioDriver(void);
void EndCDAudio(void);

bool AudARMInit(void);
void AudARMTerm(void);
bool AudARMRead(uint len, void far *buff);
bool AudARMWrite(int fd, ulong flen);

extern Handle audioDrv;
extern bool audNone;

#endif

