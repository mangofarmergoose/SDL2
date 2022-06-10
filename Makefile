IncludeGlad = -I./glad/include
IncludeSDL = -I/Library/Frameworks/SDL2.framework/Headers
Framework = -F/Library/Frameworks

glad.o: ./glad/src/glad.c ./glad/include/glad/glad.h
	clang -c $< $(IncludeGlad)

ResManager.o: ResManager.cpp ResManager.hpp
	clang++ -c $< $(IncludeSDL)

SDLApp.o: SDLApp.cpp SDLApp.hpp
	clang++ -c $< $(IncludeSDL)

AnimatedSprite.o: AnimatedSprite.cpp AnimatedSprite.hpp ResManager.hpp
	clang++ -c $< $(IncludeSDL)

TexturedRect.o: TexturedRect.cpp TexturedRect.hpp ResManager.hpp
	clang++ -c $< $(IncludeSDL)

Collider2D.o: Collider2D.cpp Collider2D.hpp
	clang++ -c $< $(IncludeSDL)

GameEntity.o: GameEntity.cpp TexturedRect.hpp GameEntity.hpp
	clang++ -c $< $(IncludeSDL)

main.o: main.cpp ./glad/include/glad/glad.h /Library/Frameworks/SDL2.framework/Headers/SDL.h
	clang++ -c $< $(IncludeGlad) $(IncludeSDL)

prog: glad.o main.o TexturedRect.o ResManager.o AnimatedSprite.o SDLApp.o GameEntity.o Collider2D.o
	clang++ -g *.o -o prog -F/Library/Frameworks -framework SDL2

clean:
	rm -f main.o prog TexturedRect.o ResManager.o AnimatedSprite.o SDLApp.o GameEntity.o Collider2D.o

.PHONY: clean