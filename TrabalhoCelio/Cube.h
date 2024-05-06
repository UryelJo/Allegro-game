#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>

class Cube
{
	public:
		ALLEGRO_BITMAP* imagemChao = NULL;

		ALLEGRO_BITMAP* imagemChao1 = NULL;
		ALLEGRO_BITMAP* imagemChao2 = NULL;
		ALLEGRO_BITMAP* imagemChao3 = NULL;
		ALLEGRO_BITMAP* imagemChao4 = NULL;
		ALLEGRO_BITMAP* imagemChao5 = NULL;
		ALLEGRO_BITMAP* imagemChao6 = NULL;
		ALLEGRO_BITMAP* imagemChao7 = NULL;
		ALLEGRO_BITMAP* imagemChao8 = NULL;
		ALLEGRO_BITMAP* imagemChao9 = NULL;
		ALLEGRO_BITMAP* imagemChao10 = NULL;

		int posicao_x_inicial = 0;
		int posicao_y_inicial = 0;

		int tamanho = 0;

		int flags = 0;

		Cube() {};
		Cube(int px, int py, int l, int flags) {
			this->posicao_x_inicial = px;
			this->posicao_y_inicial = py;
			this->tamanho = l;
			this->flags = flags;
		}

		void carregarImagemChao(ALLEGRO_BITMAP* imagemChao);
		void carregarImagemChao1(ALLEGRO_BITMAP* imagemChao1);
		void carregarImagemChao2(ALLEGRO_BITMAP* imagemChao2);
		void carregarImagemChao3(ALLEGRO_BITMAP* imagemChao3);
		void carregarImagemChao4(ALLEGRO_BITMAP* imagemChao4);
		void carregarImagemChao5(ALLEGRO_BITMAP* imagemChao5);
		void carregarImagemChao6(ALLEGRO_BITMAP* imagemChao6);
		void carregarImagemChao7(ALLEGRO_BITMAP* imagemChao7);
		void carregarImagemChao8(ALLEGRO_BITMAP* imagemChao8);
		void carregarImagemChao9(ALLEGRO_BITMAP* imagemChao9);
		void carregarImagemChao10(ALLEGRO_BITMAP* imagemChao10);

};

void Cube::carregarImagemChao(ALLEGRO_BITMAP* imagemChao) {
	this->imagemChao = imagemChao;
}

void Cube::carregarImagemChao1(ALLEGRO_BITMAP* imagemChao1) {
	this->imagemChao1 = imagemChao1;
}

void Cube::carregarImagemChao2(ALLEGRO_BITMAP* imagemChao2) {
	this->imagemChao2 = imagemChao2;
}

void Cube::carregarImagemChao3(ALLEGRO_BITMAP* imagemChao3) {
	this->imagemChao3 = imagemChao3;
}

void Cube::carregarImagemChao4(ALLEGRO_BITMAP* imagemChao4) {
	this->imagemChao4 = imagemChao4;
}

void Cube::carregarImagemChao5(ALLEGRO_BITMAP* imagemChao5) {
	this->imagemChao5 = imagemChao5;
}

void Cube::carregarImagemChao6(ALLEGRO_BITMAP* imagemChao6) {
	this->imagemChao6 = imagemChao6;
}

void Cube::carregarImagemChao7(ALLEGRO_BITMAP* imagemChao7) {
	this->imagemChao7 = imagemChao7;
}

void Cube::carregarImagemChao8(ALLEGRO_BITMAP* imagemChao8) {
	this->imagemChao8 = imagemChao8;
}

void Cube::carregarImagemChao9(ALLEGRO_BITMAP* imagemChao9) {
	this->imagemChao9 = imagemChao9;
}

void Cube::carregarImagemChao10(ALLEGRO_BITMAP* imagemChao10) {
	this->imagemChao10 = imagemChao10;
}


