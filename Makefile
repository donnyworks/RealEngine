TARGET	:= realengine.so
CC	:= g++
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
	$(CC) $(OBJS) -shared $(FLAGS) $(LIBS) -o $(TARGET)

.$(CLASSES)/%.o: .$(SOURCE)/%.cpp
	$(CC) -fPIC $(LIBS) -c $< -o $@

clean:
	rm -rf .$(CLASSES)
	mkdir .$(CLASSES)

test: clean build
	./$(TARGET)

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