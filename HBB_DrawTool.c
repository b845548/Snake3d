#include<SDL2/SDL.h>

enum{
  BLUE=0,
  GREEN=8,
  RED=16,
  ALPHA=24	
};

struct RGBA{
  Uint32 r;
  Uint32 g;
  Uint32 b;
  Uint32 a;
};
typedef struct RGBA RGBA;


RGBA HBB_convertRGBA(const Uint32 unPixel){
  int color;
  Uint32 colorTmp;
  RGBA colorFormat;
  for(color=0;color<4;color++){
    colorTmp=unPixel;
    colorTmp<<=color*8;
    colorTmp>>=24;
    if(RED==24-color*8)colorFormat.r=colorTmp;
    if(GREEN==24-color*8)colorFormat.g=colorTmp;
    if(BLUE==24-color*8)colorFormat.b=colorTmp;
    if(ALPHA==24-color*8)colorFormat.a=colorTmp;
	}
  	return colorFormat;
}


void HBB_cube3D(int posy,int posx,int cubeSize,Uint32 * ecran, int w,int h,Uint32 *color){
  int colonne,ligne;
  float decalage;
  for(ligne=0;ligne<cubeSize/2+1;ligne++)
    for(colonne=0,decalage=0;colonne<cubeSize+1;colonne++,decalage+=0.5)
      if(posx+colonne+2*ligne>=0
	  	&&posx+colonne<w
	  	&&(posy-ligne+(int)decalage)>=0
	  	&&(posy-ligne+(int)decalage)<h
		&&(posy-ligne-1+(int)decalage)<h){
		ecran[posx+colonne+2*ligne+(posy-ligne+(int)decalage)*w]=color[0];
		ecran[posx+colonne+2*ligne+(posy-ligne-1+(int)decalage)*w]=color[0];		
      	}
for(colonne=0,decalage=0;colonne<cubeSize;colonne++,decalage+=0.5)
   	for(ligne=0;ligne<=cubeSize;ligne++)
   		if(posx+colonne>=0
		   	&&posx+colonne<w
		  	&&(posy+ligne+(int)decalage)>=0
			&&(posy+ligne+(int)decalage)<h)
			ecran[posx+colonne+(posy+ligne+(int)decalage)*w]=color[2];
  
  for(colonne=0,decalage=0.5;colonne<cubeSize;colonne++,decalage+=0.5)
    for(ligne=0;ligne<=cubeSize;ligne++)
      if(posx+cubeSize+colonne>=0
	  	&&posx+cubeSize+colonne<w
		&&(posy+cubeSize+cubeSize/2-(ligne+(int)decalage))>=0
		&&(posy+cubeSize+cubeSize/2-(ligne+(int)decalage))<h)
	  	ecran[posx+cubeSize+colonne+(posy+cubeSize+cubeSize/2-(ligne+(int)decalage))*w]=color[1];
  
}

void HBB_flip(Uint32 tab[],int tabW,int tabH){
  Uint32 tmp;
  int colonne,ligne;
  for(ligne=0;ligne<tabH/2;ligne++)
    for(colonne=0;colonne<tabW;colonne++){
      tmp=tab[colonne+ligne*tabW];
      tab[colonne+ligne*tabW]=tab[colonne+(tabH-ligne-1)*tabW];
      tab[colonne+(tabH-ligne-1)*tabW]=tmp;
    }
}

void HBB_drawRainbowCube(Uint32 * pix, int w,int h,int posx,int posy){
	int colonne,ligne,inverse;
	float decalage=0.0;
	for(colonne=0;colonne<256;colonne++,decalage+=0.5)
	for(ligne=0;ligne<256;ligne++)
	if(posx+colonne>=0&&posx+colonne<w&&(posy+ligne+(int)decalage)>=0&&(posy+ligne+(int)decalage)<h)	
	pix[posx+colonne+(posy+ligne+(int)decalage)*w]=(255<<ALPHA)|(255-ligne<<RED)|(colonne<<GREEN)|(255<<BLUE);
	for(colonne=255,inverse=0,decalage=0;colonne>=0;colonne--,decalage+=0.5,inverse++)
		for(ligne=0;ligne<256;ligne++)
   			if(posx+colonne+256>=0&&posx+colonne<w&&(posy+ligne+(int)decalage)>=0&&(posy+ligne+(int)decalage)<h)
	   			pix[posx+(256+colonne)+(posy+ligne+(int)decalage)*w]=(255<<ALPHA)|(255-ligne<<RED)|(255<<GREEN)|(inverse<<BLUE);
	for(ligne=0;ligne<128;ligne++)
		for(colonne=0,decalage=0;colonne<256;colonne++,decalage+=0.5){
   	if(posx+colonne+2*ligne>=0&&posx+colonne<w&&(posy-ligne+(int)decalage)>=0&&(posy-ligne+(int)decalage)<h&&ligne+(posy-ligne-1+(int)decalage)<h)
	pix[posx+1+colonne+2*ligne+(posy-ligne+(int)decalage)*w]=(255<<ALPHA)|(255<<RED)|(colonne<<GREEN)|(255-ligne*2<<BLUE);	
	pix[posx+1+colonne+2*ligne+(posy-ligne-1+(int)decalage)*w]=(255<<ALPHA)|(255<<RED)|(colonne<<GREEN)|(255-ligne*2<<BLUE);		
	}
	
}

void HBB_mapping(Uint32 *texture,int w,int h,Uint32 * imgPix,int imgW,int imgH,int x0,int y0,Uint32 background){
  int colonne,ligne,posImg;
  for(ligne=0,posImg=0;ligne<h;ligne++)
    for(colonne=0;colonne<w;colonne++)
      if(x0<=colonne&&y0<=ligne&&colonne>=0&&ligne>=0&&ligne<y0+imgH&&colonne<x0+imgW)
	if(background==imgPix[posImg])posImg++;
	else texture[colonne+ligne*w]=imgPix[posImg++];
}

void HBB_drawImgGameover(Uint32 *texture,int w,int h,Uint32 * imgPix,int imgW,int imgH,int x0,int y0,Uint32 background){
  int colonne,ligne,posImg;RGBA col;
  for(ligne=0,posImg=0;ligne<h;ligne++)
    for(colonne=0;colonne<w;colonne++)
      if(x0<=colonne&&y0<=ligne&&colonne>=0&&ligne>=0&&ligne<y0+imgH&&colonne<x0+imgW){
	col=HBB_convertRGBA(imgPix[posImg]);
	if((col.r<100 && col.g<100 && col.b<100)||(imgPix[posImg]==background))posImg++;
	else texture[colonne+ligne*w]=imgPix[posImg++];
    }
}	
void HBB_drawImgLogo(Uint32 *texture,int w,int h,Uint32 * imgPix,int imgW,int imgH,int x0,int y0,Uint32 background){
 int colonne,ligne,posImg;RGBA col;
  for(ligne=0,posImg=0;ligne<h;ligne++)
    for(colonne=0;colonne<w;colonne++)
      if(x0<=colonne&&y0<=ligne&&colonne>=0&&ligne>=0&&ligne<y0+imgH&&colonne<x0+imgW){
	col=HBB_convertRGBA(imgPix[posImg]);
	if((imgPix[posImg]==background))posImg++;
	else{
		texture[colonne+ligne*w]=(col.b<<GREEN)|(col.g<<BLUE)|(col.r<<RED);
		posImg++;
		}
    }
}			
