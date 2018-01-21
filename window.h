#pragma once
#define SDL_MAIN_HANDLED
#define _SDL_
#include<sdl.h>

#define Print(x)                  std::cout << x << std::endl
#define GetRandom( min, max )     ((rand() % (int)(((max) + 1) - (min))) + (min))  
#define RANDOM(x)                 ((rand() * (1.0 / (1.0 + RAND_MAX))) * x)
#ifdef RGB
#undef RGB
#endif
#define RGB(r,g,b)              ((int)b + ((int)g<< 8) + ((int)r << 16))
//#define RGB(r, g, b)              (((int)r) << 16 | ((int)g) << 8 | ((int)b))
#define RADIANS(angle)            (angle * .0174532925199444)

#define LOOP(x)                   for(int count = 0; count < (x); count++)

#define SCREENWIDTH         680 
#define SCREENHEIGHT        460 

#define _LOOP_GAME  LOOP_GAME()        // This is being done for future compatibility with various Graphics Libraries
#define _CLS              CLS()        //
#define _SYNC            SYNC()        //



class WINDOW{

public:
	WINDOW();~WINDOW();
	WINDOW(int,int,int,int,char*);

	 int       X,
	       	   Y,
		       WIDTH,
		       HEIGHT;

	 char     *TITLE;

     SDL_Window             *HWND;
	 SDL_Texture            *BACK_BUFFER;
     SDL_Renderer           *RENDER;

	 Uint32                  *WINDOW_PIXELS;

	 Uint32                  WINDOW_FORMAT; 
	 SDL_Event               EVENT;
	 SDL_Surface            *WINDOW_SURFACE;
	 SDL_PixelFormat        *MAPPING_FORMAT;
	 SDL_Point               MOUSE_POSITION;

	 struct{
		 bool LEFT,
		      RIGHT;
	 }MOUSE_BUTTONS;
	 int  FPS;
};






extern int KEYBOARD_HANDLER(SDL_Keycode sym);

extern bool LOOP_GAME        ();
extern bool SET_ACTIVE_WINDOW(WINDOW *active);
extern bool SEDITS_LIB_INIT();

extern float NEWX(float x,float dist,float angle);
extern float NEWY(float y,float dist,float angle);

extern void SYNC         ();
extern void CLS          ();
extern void PRINT_SCREEN (char *text);
extern void SET_PIXEL    (int, int, Uint32);
extern void SET_PIXELII  (int, int, Uint32);


extern WINDOW *SCREEN; 

extern int WINDOW_OFFSET;
extern int LEFT_BOUNDS;
extern int TOP_BOUNDS;
extern int RIGHT_BOUNDS;
extern int BOTTOM_BOUNDS;

struct stack_array{
	int ITERATOR;
	int SIZE;
	int *ARRAY;
	int ADD();
	int REMOVE();
	int GETLAST();
};
