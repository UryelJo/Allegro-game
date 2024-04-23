#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>

class Mapa {
	public:
		ALLEGRO_BITMAP *backgroundTela = NULL;

		const float fpsGame = 60.f;

		const int larguraTela = 1366;
		const int alturaTela = 768;

		Mapa(){};
};