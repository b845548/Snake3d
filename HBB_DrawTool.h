#include<SDL2/SDL.h>
#include"HBB_DrawTool.c"

RGBA HBB_convertRGBA(const Uint32 pix);
void HBB_flip(Uint32 tab[],int tabW,int tabH);
void HBB_cube3D(int posy,int posx,int t,Uint32 * pix, int w,int h,Uint32 *color);
void HBB_drawRainbowCube(Uint32 * pix, int w,int h,int posx,int posy);
void HBB_mapping(Uint32 *texture,int w,int h,Uint32 * imgPix,int imgW,int imgH,int x0,int y0,Uint32 background);
void HBB_drawImgGameover(Uint32 *texture,int w,int h,Uint32 * imgPix,int imgW,int imgH,int x0,int y0,Uint32 background);
void HBB_drawImgLogo(Uint32 *texture,int w,int h,Uint32 * imgPix,int imgW,int imgH,int x0,int y0,Uint32 background);

Uint32 ice[3]={
	(0<<RED)|(180<<GREEN)|(255<<BLUE),
	(0<<RED)|(210<<GREEN)|(255<<BLUE),
	(0<<RED)|(255<<GREEN)|(255<<BLUE)};
Uint32 gold[3]={
	(255<<RED)|(170<<GREEN)|(0<<BLUE),
	(255<<RED)|(190<<GREEN)|(0<<BLUE),
	(255<<RED)|(220<<GREEN)|(0<<BLUE)};
Uint32 bl[3]={
	(0<<RED)|(0<<GREEN)|(150<<BLUE),
	(0<<RED)|(0<<GREEN)|(255<<BLUE),
	(0<<RED)|(0<<GREEN)|(255<<BLUE)};
Uint32 mgnt[3]={
	(255<<RED)|(0<<GREEN)|(100<<BLUE),
	(200<<RED)|(0<<GREEN)|(160<<BLUE),
	(150<<RED)|(0<<GREEN)|(255<<BLUE)};
Uint32 c[3]={
	(0<<RED)|(250<<GREEN)|(150<<BLUE),
	(0<<RED)|(200<<GREEN)|(200<<BLUE),
	(0<<RED)|(150<<GREEN)|(255<<BLUE)};
Uint32 c2[3]={
	(150<<RED)|(50<<GREEN)|(250<<BLUE),
	(150<<RED)|(100<<GREEN)|(200<<BLUE),
	(150<<RED)|(150<<GREEN)|(150<<BLUE)};
Uint32 c3[3]={
	(200<<RED)|(150<<GREEN)|(200<<BLUE),
	(255<<RED)|(150<<GREEN)|(150<<BLUE),
	(150<<RED)|(150<<GREEN)|(60<<BLUE)};
Uint32 blncN3[3]={
	(150<<RED)|(250<<GREEN)|(50<<BLUE),
	(200<<RED)|(200<<GREEN)|(150<<BLUE),
	(255<<RED)|(155<<GREEN)|(200<<BLUE)};
Uint32 gN4[3]={
	(0<<RED)|(100<<GREEN)|(0<<BLUE),
	(0<<RED)|(150<<GREEN)|(0<<BLUE),
	(0<<RED)|(255<<GREEN)|(0<<BLUE)};
Uint32 rN4[3]={
	(150<<RED)|(0<<GREEN)|(0<<BLUE),
	(200<<RED)|(0<<GREEN)|(0<<BLUE),
	(255<<RED)|(0<<GREEN)|(0<<BLUE)};
Uint32 Gre[3]={
	(100<<RED)|(100<<GREEN)|(100<<BLUE),
	(150<<RED)|(150<<GREEN)|(150<<BLUE),
	(200<<RED)|(200<<GREEN)|(200<<BLUE)};
Uint32 HBB_water[3]={
	(0<<RED)|(127<<GREEN)|(240<<BLUE),
	(0<<RED)|(111<<GREEN)|(164<<BLUE),
	(0<<RED)|(111<<GREEN)|(190<<BLUE)};
Uint32 HBB_terre[3]={
  	(113<<RED)|(64<<GREEN)|(0<<BLUE),
  	(130<<RED)|(70<<GREEN)|(0<<BLUE),
  	(145<<RED)|(79<<GREEN)|(0<<BLUE)};
Uint32 HBB_green[3]={
  	(0<<RED)|(190<<GREEN)|(40<<BLUE),
  	(0<<RED)|(120<<GREEN)|(40<<BLUE),
  	(0<<RED)|(150<<GREEN)|(40<<BLUE)};
Uint32 NH_red[3]={
  	(190<<RED)|(0<<GREEN)|(0<<BLUE),
  	(120<<RED)|(0<<GREEN)|(0<<BLUE),
  	(150<<RED)|(0<<GREEN)|(0<<BLUE)};
Uint32 HBB_pastel[3]={
  	(255<<RED)|(255<<GREEN)|(255<<BLUE),
  	(255<<RED)|(232<<GREEN)|(44<<BLUE),
  	(119<<RED)|(180<<GREEN)|(225<<BLUE)};
Uint32 HBB_blnc[3]={
  	(255<<RED)|(255<<GREEN)|(255<<BLUE),
  	(255<<RED)|(255<<GREEN)|(255<<BLUE),
	(255<<RED)|(255<<GREEN)|(255<<BLUE)};
Uint32 HBB_dyellow[3]={
	(255<<RED)|(140<<GREEN)|(0<<BLUE),
    (255<<RED)|(160<<GREEN)|(0<<BLUE),
    (255<<RED)|(180<<GREEN)|(0<<BLUE)};
Uint32 HBB_blk[3]={0,0,0,};
Uint32 HBB_blnc2[3]={
  	(230<<RED)|(230<<GREEN)|(230<<BLUE),
  	(230<<RED)|(230<<GREEN)|(230<<BLUE),
  	(230<<RED)|(230<<GREEN)|(230<<BLUE)};
Uint32 HBB_org[3]={
  	(240<<RED)|(80<<GREEN)|(0<<BLUE),
	(235<<RED)|(90<<GREEN)|(0<<BLUE),
	(240<<RED)|(100<<GREEN)|(0<<BLUE)};


Uint32 CHARLIE_col[3]={
	(255<<RED)|(0<<GREEN)|(100<<BLUE),
	(255<<RED)|(0<<GREEN)|(150<<BLUE),
	(255<<RED)|(0<<GREEN)|(200<<BLUE)};

Uint32 CHARLIE_c[3]={
	(100<<RED)|(100<<GREEN)|(100<<BLUE),
	(0<<RED)|(10<<GREEN)|(120<<BLUE),
	(125<<RED)|(125<<GREEN)|(125<<BLUE)};

Uint32 CHARLIE_co[3]={
	(150<<RED)|(50<<GREEN)|(100<<BLUE),
	(55<<RED)|(100<<GREEN)|(150<<BLUE),
	(50<<RED)|(150<<GREEN)|(200<<BLUE)};


