#include "HBB_DrawStage.c"
void HBB_reinitAllStage();
void HBB_drawVoxelLeft(Uint32 *pix,int w,int h,int cubeSize,int map[],int mapW,int mapH,int mapX,int mapY);
void HBB_drawVoxelRight(Uint32 * pix,int w,int h,int cubeSize,int map[],int mapW,int mapH,int mapX,int mapY);
void HBB_drawVoxelTop(Uint32 *pix,int w,int h,int cubeSize,Uint32 * map,int mapW,int mapH,int mapX,int mapY);
void HBB_drawMenu(Uint32 *texture,int texW,int texh,int page,int horloge);
void HBB_drawStageTerre(Uint32 *texture,int texW,int texh,int cubeSize);
void HBB_drawStageVolcan(Uint32 *texture,int textureWidth,int textureHeight,int cubeSize);
void HBB_drawStage3D(Uint32 *texture,int textureW,int textureH,int *topMap,int topW,int topH,
		     int *leftMap,int leftW,int leftH,int *rightMap,int rightW,int rightH);
void HBB_drawStageRainbow(Uint32* pix,int w,int h);
void HBB_drawScoreBoard(Uint32* pixels,int w,int h,int score,int x,int y);
void CHARLIE_drawStagerand(Uint32 *texture,int texW,int texh,int cubeSize);
