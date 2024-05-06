class Moveset 
{
	public:
		bool paradaEsquerda = false;
		bool paradaDireita = false;

		bool movendoEsquerda = false;
		bool movendoDireita = false;

		bool agachando = false;
		bool agachandoEsquerda = false;
		bool agachandoDireita = false;

		bool puloEsquerda = false;
		bool puloDireita = false;

		bool morteEsquerda = false;
		bool morteDireita = false;

		bool pulando = false;
		bool caindo = false;

		float acelaracaoPuloY = 0.5f;

		Moveset() {};
};