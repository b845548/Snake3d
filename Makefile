#  Makefile 

SHELL = /bin/sh
CC = gcc
ECHO = echo
RM = rm -f
TAR = tar
MKDIR = mkdir
CHMOD = chmod
CP = rsync -R
PG_FLAGS =
SDL_CFLAGS = $(shell sdl2-config --cflags)
SDL_LDFLAGS = $(shell sdl2-config --libs)
CPPFLAGS = -I. $(SDL_CFLAGS)
CFLAGS =    
LDFLAGS = -lm -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer

PROGNAME = SNAKE3D
PACKAGE=$(PROGNAME)
distdir = $(PACKAGE)-$(VERSION)
HEADERS =
SOURCES = snake.c
OBJ = $(SOURCES:.c=.o)
DISTFILES = $(SOURCES) Makefile $(HEADERS) $(EXTRAFILES)

all: $(PROGNAME)

$(PROGNAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(PROGNAME)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

dist: distdir
	$(CHMOD) -R a+r $(distdir)
	$(TAR) zcvf $(distdir).tgz $(distdir)
	$(RM) -r $(distdir)

distdir: $(DISTFILES)
	$(RM) -r $(distdir)
	$(MKDIR) $(distdir)
	$(CHMOD) 777 $(distdir)
	$(CP) $(DISTFILES) $(distdir)

clean:
	@$(RM) -r $(PROGNAME) $(OBJ) *~ $(distdir).tgz gmon.out core.* documentation/*~ shaders/*~ GL4D/*~ documentation/html
