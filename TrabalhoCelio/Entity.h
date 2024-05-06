#include "Moveset.h"

#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>

class Entity
{
	public:
		ALLEGRO_BITMAP* imagemPersonagem = NULL;

		int frame_x = 0;
		int frame_y = 0;

		int delayTrocaDeFrame = 0;

		int larguraPlayer = 0;
		int alturaPlayer = 0;

		float posicao_x_tela = 0.f;
		float posicao_y_tela = 0.f;

		int flags = 0;

		Moveset movesetPlayer;

		Entity() {};

		Entity(int fx, int fy, int lp, int ap, float px, float py, Moveset ms, int flags) {
			this->frame_x = fx;
			this->frame_y = fy;
			this->larguraPlayer = lp;
			this->alturaPlayer = ap;
			this->posicao_x_tela = px;
			this->posicao_y_tela = py;
			this->movesetPlayer = ms;
			this->flags = flags;
		}

		void carregarImagemPersonagem(ALLEGRO_BITMAP* imagemPersonagem);
		void movimentacao();
		void movimentacaoParado();
};

void Entity::carregarImagemPersonagem(ALLEGRO_BITMAP* imagemPersonagem) {
	this->imagemPersonagem = imagemPersonagem;
}

void Entity::movimentacao() {
	if (this->movesetPlayer.movendoEsquerda || this->movesetPlayer.movendoDireita) 
	{
		this->imagemPersonagem = al_load_bitmap("Assets/Images/Andando.png");
		if (this->movesetPlayer.movendoEsquerda) 
		{
			this->posicao_x_tela -= 3;
		}
		else 
		{
			this->posicao_x_tela += 3;
		}
		
		this->delayTrocaDeFrame++;
		if (this->delayTrocaDeFrame == 17) 
		{
			this->frame_x += 115;
			if (this->frame_x == 460) 
			{
				this->frame_x = 0;
			}
			this->delayTrocaDeFrame = 0;
		}
	}
}

void Entity::movimentacaoParado() {
	if (!this->movesetPlayer.movendoDireita && !this->movesetPlayer.movendoEsquerda && !this->movesetPlayer.pulando) 
	{
		this->delayTrocaDeFrame++;
		if (this->delayTrocaDeFrame == 15) 
		{
			if (this->frame_x < 575) 
			{
				this->frame_x += 115;
			}
			else 
			{
				this->frame_x = 0;
			}
			this->delayTrocaDeFrame = 0;
		}
	}
}

