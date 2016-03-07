struct play_args {
    int row; 
    int column;
    int player;
};

struct simbolo_args{
	char simbolo1;
	char simbolo2;
};

program TTT {
    version V1 {
        string CURRENTBOARD(void)=1;
        int PLAY(play_args)=2;
        int CHECKWINNER(void)=3;
		int TROCARSIMBOLOS(simbolo_args)=4;
    } = 1;
} = 0x31479112;
