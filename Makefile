TARGET	:= realengine.so
WINTARGET	:= realengine.dll
BINPATH	:= ./bin/
LAUNCHER	:= realengine
WINLAUNCHER	:= realengine.exe
CC	:= g++
C	:= gcc
EMCC	:= emcc
LIBS	:= -lSDL2 -lGL -lGLEW -lGLU

CLASSES := /classes

SOURCE := /source

EMXPORT	:= emscripten

CPPFILES := $(wildcard .$(SOURCE)/*.cpp)

OBJS	:=  $(CPPFILES:.$(SOURCE)/%.cpp=.$(CLASSES)/%.o)

EMOBJS	:=  $(CPPFILES:.$(SOURCE)/%.cpp=.$(CLASSES)/%.wasm)

FLAGS	:= -g

build: $(OBJS)
	$(CC) $(OBJS) -shared $(FLAGS) $(LIBS) -o $(BINPATH)$(TARGET)

launcherbuild:
	$(C) -DLINUX .$(SOURCE)/launcher/main.c -o $(BINPATH)$(LAUNCHER)

winbuild: $(OBJS)
	$(CC) $(OBJS) -shared $(FLAGS) -Llib -L./lib -L.\lib -Ilib $(LIBS) -o $(BINPATH)$(WINTARGET)

winlauncherbuild:
	$(C) -DWINDOWS .$(SOURCE)/launcher/main.c -o $(BINPATH)$(WINLAUNCHER)

.$(CLASSES)/%.o: .$(SOURCE)/%.cpp
	$(CC) -fPIC $(LIBS) -Iinclude -c $< -o $@

clean:
	rm -rf .$(CLASSES)
	rm -rf $(BINPATH)
	mkdir $(BINPATH)
	mkdir .$(CLASSES)

test: clean build launcherbuild
	$(BINPATH)$(LAUNCHER)

emclean:
	rm -rf .$(EMXPORT)
	mkdir .$(EMXPORT)

.$(CLASSES)/%.wasm: .$(SOURCE)/%.cpp
	$(EMCC) $(LIBS) -DEMSCRIPTEN -sLEGACY_GL_EMULATION -s USE_SDL=2 -c $< -o $@

emscripten:
	embuilder build --verbose sdl2 sdl2_image
	make embuild

embuild: $(EMOBJS)
	$(EMCC) $(EMOBJS) $(FLAGS) -sLEGACY_GL_EMULATION -s USE_SDL=2 $(LIBS) -o .$(EMXPORT)/$(TARGET).html

emtest: clean emclean embuild
	emrun .$(EMXPORT)/engine.html
