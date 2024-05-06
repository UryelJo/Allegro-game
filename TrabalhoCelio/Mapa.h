#include "Cube.h"

#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>

#include <iostream>

class Mapa {

	public:
		ALLEGRO_BITMAP *backgroundTela = NULL;

		const float fpsGame = 60;

		const int larguraTela = 1366;
		const int alturaTela = 768;

		int representacaoMapa[24][43] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 10, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 10, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 10, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8,
		2, 1, 1, 1, 1, 1, 1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		7, 7, 7, 7, 7, 7, 7, 7, 9, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		7, 7, 7, 7, 7, 7, 7, 7, 7, 9, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 9, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 9, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 9, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 9, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 9, 1, 1, 1, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
		6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 1, 1, 1, 1, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
		2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 10, 7, 7, 7, 7, 7, 9, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 
		};

		Cube chao = Cube(0, 0, 32, 0);

		Mapa(){};

		void carregarBackground(ALLEGRO_BITMAP *backgroundTela);
		void construirMapa(int mapa[24][43], int larguraMapa, int alturaMapa);
};

void Mapa::carregarBackground(ALLEGRO_BITMAP* backgroundTela) {
	this->backgroundTela = backgroundTela;
}

void Mapa::construirMapa(int mapa[24][43], int larguraMapa, int alturaMapa) {
	for (int x = 0; x <= (larguraMapa/chao.tamanho); x++) 
	{
		for (int y = 0; y <= (alturaMapa/ chao.tamanho); y ++) 
		{
			if (mapa[y][x] == 1) 
			{
				al_draw_bitmap(chao.imagemChao, x*chao.tamanho, y*chao.tamanho, chao.flags);
			} else if (mapa[y][x] == 2)
			{
				this->chao.imagemChao = this->chao.imagemChao1;
				al_draw_bitmap(chao.imagemChao, x*chao.tamanho, y*chao.tamanho, chao.flags);
				this->chao.imagemChao = this->chao.imagemChao2;

			} else if (mapa[y][x] == 3)
			{
				this->chao.imagemChao = this->chao.imagemChao3;
				al_draw_bitmap(chao.imagemChao, x * chao.tamanho, y * chao.tamanho, chao.flags);
				this->chao.imagemChao = this->chao.imagemChao2;
			}
			else if (mapa[y][x] == 4) {
				this->chao.imagemChao = this->chao.imagemChao4;
				al_draw_bitmap(chao.imagemChao, x * chao.tamanho, y * chao.tamanho, chao.flags);
				this->chao.imagemChao = this->chao.imagemChao2;
			}
			else if (mapa[y][x] == 5) {
				this->chao.imagemChao = this->chao.imagemChao5;
				al_draw_bitmap(chao.imagemChao, x * chao.tamanho, y * chao.tamanho, chao.flags);
				this->chao.imagemChao = this->chao.imagemChao2;
			}
			else if (mapa[y][x] == 6) {
				this->chao.imagemChao = this->chao.imagemChao6;
				al_draw_bitmap(chao.imagemChao, x * chao.tamanho, y * chao.tamanho, chao.flags);
				this->chao.imagemChao = this->chao.imagemChao2;
			}
			else if (mapa[y][x] == 7) {
				this->chao.imagemChao = this->chao.imagemChao7;
				al_draw_bitmap(chao.imagemChao, x * chao.tamanho, y * chao.tamanho, chao.flags);
				this->chao.imagemChao = this->chao.imagemChao2;
			}
			else if (mapa[y][x] == 8) {
				this->chao.imagemChao = this->chao.imagemChao8;
				al_draw_bitmap(chao.imagemChao, x * chao.tamanho, y * chao.tamanho, chao.flags);
				this->chao.imagemChao = this->chao.imagemChao2;
			}
			else if (mapa[y][x] == 9) {
				this->chao.imagemChao = this->chao.imagemChao9;
				al_draw_bitmap(chao.imagemChao, x * chao.tamanho, y * chao.tamanho, chao.flags);
				this->chao.imagemChao = this->chao.imagemChao2;
			}
			else if (mapa[y][x] == 10) {
				this->chao.imagemChao = this->chao.imagemChao10;
				al_draw_bitmap(chao.imagemChao, x * chao.tamanho, y * chao.tamanho, chao.flags);
				this->chao.imagemChao = this->chao.imagemChao2;
			}

		}
	}
}

