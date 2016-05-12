#include<SDL2/SDL_image.h>
#include<assert.h>

static int _Horloge;
static int _AnimationTimer;

static int _RapiditeLevel[5];
static int _GamePage;
static int _GameOver; 
static int _MouvementSnake;

SDL_Rect positionArrow;
SDL_Rect positionGameover;
SDL_Rect positionStart;
SDL_Rect positionLogo;
SDL_Rect positionLevel[5];

SDL_Surface *IMG_arrow= NULL;
SDL_Surface *IMG_gameover= NULL;
SDL_Surface *IMG_logo= NULL;
SDL_Surface *IMG_start = NULL;
SDL_Surface * IMG_level[5];

enum{
GAMEPAGE_MAINMENU = 1,
GAMEPAGE_STAGEMENU = 2,
GAMEPAGE_LEVEL1 = 3,
GAMEPAGE_LEVEL2 = 4,
GAMEPAGE_LEVEL3 = 5,
GAMEPAGE_LEVEL4 = 6,
GAMEPAGE_LEVEL5 = 7,
MOUVEMENT_CONTINUE = 0,
MOUVEMENT_STOP_TO_START = 1,
MOUVEMENT_GAMEOVER = 2,
GAMEOVER_OUI = 0,
GAMEOVER_NON = 1
};
void CHARLIE_init_GAMESTATE(){
_Horloge = 1;
_AnimationTimer = 0;
_RapiditeLevel[0] = 150;
_RapiditeLevel[1] = 110;
_RapiditeLevel[2] = 90;
_RapiditeLevel[3] = 80;
_RapiditeLevel[4] = 70;

_GamePage = GAMEPAGE_MAINMENU;
_GameOver = GAMEOVER_NON; 
_MouvementSnake = MOUVEMENT_STOP_TO_START;
}

void CHARLIE_init_IMAGE(){
  positionArrow.x=150;
  positionArrow.y=338;
  positionStart.x = 230;
  positionStart.y = 350;
  positionGameover.x = 160;
  positionGameover.y = 90;
  positionLogo.x = 50;
  positionLogo.y = 20;
  positionLevel[0].x = positionLogo.x+91;
  positionLevel[0].y = positionLogo.y+400;
  positionLevel[1].x = positionLevel[0].x+100;
  positionLevel[1].y = positionLevel[0].y;
  positionLevel[2].x = positionLevel[0].x+200;
  positionLevel[2].y = positionLevel[0].y;
  positionLevel[3].x = positionLevel[0].x+300;
  positionLevel[3].y = positionLevel[0].y;
  positionLevel[4].x = positionLevel[0].x+400;
  positionLevel[4].y = positionLevel[0].y;
  IMG_level[0] = SDL_ConvertSurfaceFormat(IMG_Load("source/level1.png"),SDL_PIXELFORMAT_ABGR8888, 0); 
  assert(IMG_level[0]);
  IMG_level[1] = SDL_ConvertSurfaceFormat(IMG_Load("source/level2.png"),SDL_PIXELFORMAT_ABGR8888, 0); 
  assert(IMG_level[1]);
  IMG_level[2] = SDL_ConvertSurfaceFormat(IMG_Load("source/level3.png"),SDL_PIXELFORMAT_ABGR8888, 0); 
  assert(IMG_level[2]);
  IMG_level[3] = SDL_ConvertSurfaceFormat(IMG_Load("source/level4.png"),SDL_PIXELFORMAT_ABGR8888, 0); 
  assert(IMG_level[3]);
  IMG_level[4] = SDL_ConvertSurfaceFormat(IMG_Load("source/level5.png"),SDL_PIXELFORMAT_ABGR8888, 0); 
  assert(IMG_level[4]);
  IMG_logo = SDL_ConvertSurfaceFormat(IMG_Load("source/logo5.png"),SDL_PIXELFORMAT_ABGR8888, 0); 
  assert(IMG_logo);
  IMG_gameover = SDL_ConvertSurfaceFormat(IMG_Load("source/gameover.jpg"),SDL_PIXELFORMAT_ABGR8888, 0); 
  assert(IMG_gameover);
  IMG_start =SDL_ConvertSurfaceFormat(IMG_Load("source/start2.png"),SDL_PIXELFORMAT_ABGR8888, 0); 
  assert(IMG_start);
  IMG_arrow =SDL_ConvertSurfaceFormat(IMG_Load("source/arrow5.png"),SDL_PIXELFORMAT_ARGB8888, 0);
  assert(IMG_arrow);
}
