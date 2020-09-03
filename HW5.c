#define GRIDSIZE 4
int cell;
void initGrid(cell grid[][GRIDSIZE])
{
    int i,j;
/*Hepsini closed empty yapt�m */
for(j=0;j<4;j++)
{
for(i=0;i<4;i++)
{
	grid[j][i]=closedEmpty;
}
/*Burda rastgele 4 yer mmined yapt�m */
grid[0][2]=closedMined;
grid[1][3]=closedMined;
grid[1][2]=closedMined;
grid[0][1]=closedMined;

}	
printGrid(grid);

}
int main()
{

	int c,r;
	char flag_;

	cell grid[4][GRIDSIZE];
	/*se�im yeri fonksiyon cag�rmalar*/
	initGrid(grid);
	printf("O num num/F num num\n");
	scanf(" %c %d %d", &flag_,&c,&r);
	if(flag_=='F' || flag_== 'f'){
			flagCell(grid,c,r);
		}
	else
		openCell(grid,c,r);
		while(isCellEmpty(grid,c,r)!=0 && isLocationLegal(c,r)!=0)
		{
		printf("O num num/F num num\n");
		scanf(" %c %d %d", &flag_,&c,&r);
		if(flag_=='F' || flag_== 'f'){
			flagCell(grid,c,r);
		}
		else
			openCell(grid,c,r);	
	}
	return 0;
	
}
void printGrid (cell grid[][GRIDSIZE]){
	/*ekran da print etme*/
	int j,i;
	
	for(j=0;j<4;j++)
{

	for(i=0;i<4;i++)
{
		if(grid[j][i]==empty){
				printf("E ");
	}
		else if(grid[j][i]==flaggedMined || grid[j][i]==flaggedEmpty)
				printf("F ");
		else{
			printf(". ");
		}
}
printf("\n");
}

}

int openCell(cell grid[][GRIDSIZE], int x, int y){
    int j;
	isCellEmpty(grid,x,y);

	if(grid[x][y]==closedEmpty)
	{
		grid[x][y]=empty;
		if(y-1>= 0 && grid[x][y-1]==closedEmpty)	{
			grid[x][y-1]=empty;
		}
			/*Bi yer de may�n yoksa komsular�n� a�t�g�m yer*/
		if(x-1>=0 && y-1>= 0 && grid[x-1][y-1]==closedEmpty){
			grid[x-1][y-1]=empty;
		}if(x-1>=0 && grid[x-1][y]==closedEmpty){
			grid[x-1][y]=empty;			
		}if(x-1>=0 && y+1<=3 && grid[x-1][y+1]==closedEmpty)	{
			grid[x-1][y+1]=empty;
		}if(y+1<=3 && grid[x][y+1]==closedEmpty)	{
			grid[x][y+1]=empty;
		}if(x+1<=3 && y+1<=3 && grid[x+1][y+1]==closedEmpty)	{
			grid[x+1][y+1]=empty;
		}if(x+1<=3 && grid[x+1][y]==closedEmpty)	{
			grid[x+1][y]=empty;
		}if(y-1>=0 && grid[x+1][y-1]==closedEmpty)	{
			grid[x+1][y-1]=empty;
		}
	}
	if(grid[x][y]==flaggedMined || grid[x][y]==flaggedEmpty){
		grid[x][y]=closedEmpty;
	}
	for(j=0;j<4;j++){
		printf("\n");
	}



	printGrid(grid);
return -2;
}


void flagCell(cell grid[][GRIDSIZE], int x, int y)
{
	/*kapal� bossa yada kapal� may�nl�ysa */
	if(grid[x][y]==closedMined){
		grid[x][y]=flaggedMined;
	}	


	if(grid[x][y]==closedEmpty){
	grid[x][y]=flaggedEmpty;
}		
	
	printGrid(grid);
	return;	
}

int isCellEmpty(cell grid[][GRIDSIZE], int x, int y)
{
    	/*Bos olup olmad�g�n� kontrol etme yeri*/
        int i,j;
	int isWin;
	isWin=1;
    
	if(grid[x][y]==closedMined)
	{

	printf("Game over");
	return 0;
}

	

	for(j=0; j<4;++j){
		for(i=0; i<4;++i){
			if(grid[j][i]==closedEmpty){ 
				isWin=0;
			}
		}
	}	

	
	
	if(isWin){
		printf("Win\n");
		return 0;
	}
return 1;
}

int isLocationLegal(int x, int y)
{
    	/*column row degerlerinin oyunu saglay�p saglamad�g�n� kontrol ettigimiz yer*/
	if(x<0||x>3||y<0||y>3)
	{
	
	printf("Invalid numbers");
			return 0;
		}
			else 
		return 1;	
		
}


