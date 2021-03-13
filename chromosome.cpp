#include "population.h"
#include "chromosome.h"

Chromosome::Chromosome(const int state[ROW][COL], bool flag)
{
	copyBoard(state);
   
    //  Flag is true when the board needs filling (aka; when given an intitial state)
    //if(flag)
	    fillBoard();
	cout << endl;
    printState();

	fitness_score = fitnessEval();
}

void Chromosome::printState()
{
	for(int i = 0; i < COL; ++i)
	{
		for(int j = 0; j < ROW; ++j)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
}

void Chromosome::copyBoard(const int state[COL][ROW])
{
	for(int i = 0; i < COL; ++i)
	{
		for(int j = 0; j < ROW; ++j)
		{
			board[i][j] = state[i][j];
		}
	}
}

void Chromosome::fillBoard()
{
	for(int i = 0; i < COL ; ++i)//this is to go through each row
	{	
		//this section is to see what number is already in the row 
		int number[9] = {1,2,3,4,5,6,7,8,9};
		for(int j = 0; j < ROW; ++j)
		{
			//this is to mark what is already in the row
			if(board[i][j] != 0)
			{
				number[board[i][j]-1] = 0; 
			}
		}
		//this is where we start filling in the row
		for(int j = 0; j < ROW; ++j)
		{
			//if the board is 0 that means that it is not a fix number
			if(board[i][j] == 0)
			{
				//this is to choose a number that is not in the row
				int x = rand() % 9;
				//this is where we keep finding a number that hasnt been used
				while(number[x] == 0)
				{
					x = rand() % 9; 
				}
				//this is to add the number into the row
				board[i][j] = number[x];
				//this is showing that we used a number 
				number[x] = 0;
			}
		}
	}

	return;

}

int Chromosome::fitnessEval()
{
	int cdouble = 648;
	// int cdouble = 972;//I comment this because the row will always be correct cuz we made that our contrasaint
    // for (int i = 0; i < 9; ++i)
    // {
    //     for (int k = 0; k < 9; ++k)
    //     {

    //         for (int j = k; j < 9; ++j)
    //         {
    //             if (board[i][k] == board[i][j])
    //             {
    //                 --cdouble;
    //             }
    //         }
    //         ++cdouble;
    //     }
    // }
    for (int i = 0; i < 9; ++i)
    {
        for (int k = 0; k < 9; ++k)
        {
            for (int j = k; j < 9; ++j)
            {
                if (board[k][j] == board[i][j])
                {
                    --cdouble;
                }
            }
            ++cdouble;
        }
    }
    //this is top left
    for (int i = 0; i < 3; ++i)
    {
        for (int k = i; k < 3; ++k)
        {
            for (int l = 0; l < 3; ++l)
            {
                for (int j = l; j < 3; ++j)
                {
                    if (board[k][l] == board[i][j])
                        --cdouble;
                }
            }
        }
    }
    //this is top middle
    for (int i = 0; i < 3; ++i)
    {
        for (int k = i; k < 3; ++k)
        {
            for (int l = 3; l < 6; ++l)
            {
                for (int j = l; j < 6; ++j)
                {
                    if (board[k][l] == board[i][j])
                        --cdouble;
                }
            }
        }
    }
    //this is top right
     for (int i = 0; i < 3; ++i)
    {
        for (int k = i; k < 3; ++k)
        {
            for (int l = 6; l < 9; ++l)
            {
                for (int j = l; j < 9; ++j)
                {
                    if (board[k][l] == board[i][j])
                        --cdouble;
                }
            }
        }
    }
    //this is mid right
       for (int i = 3; i < 6; ++i)
    {
        for (int k = i; k < 6; ++k)
        {
            for (int l = 0; l < 3; ++l)
            {
                for (int j = l; j < 3; ++j)
                {
                    if (board[k][l] == board[i][j])
                        --cdouble;
                }
            }
        }
    }
    //this is middle middle
        for (int i = 3; i < 6; ++i)
    {
        for (int k = i; k < 6; ++k)
        {
            for (int l = 3; l < 6; ++l)
            {
                for (int j = l; j < 6; ++j)
                {
                    if (board[k][l] == board[i][j])
                        --cdouble;
                }
            }
        }
    }
    //this is middle right
         for (int i = 3; i < 6; ++i)
    {
        for (int k = i; k < 6; ++k)
        {
            for (int l = 6; l < 9; ++l)
            {
                for (int j = l; j < 9; ++j)
                {
                    if (board[k][l] == board[i][j])
                        --cdouble;
                }
            }
        }
    }
    //this is bot right
        for (int i = 6; i < 9; ++i)
    {
        for (int k = i; k < 9; ++k)
        {
            for (int l = 0; l < 3; ++l)
            {
                for (int j = l; j < 3; ++j)
                {
                    if (board[k][l] == board[i][j])
                        --cdouble;
                }
            }
        }
    }

    //this is bot middle
    for (int i = 6; i < 9; ++i)
    {
        for (int k = i; k < 9; ++k)
        {
            for (int l = 3; l < 6; ++l)
            {
                for (int j = l; j < 6; ++j)
                {
                    if (board[k][l] == board[i][j])
                        --cdouble;
                }
            }
        }
    }
 
    //this is bot right
for (int i = 6; i < 9; ++i)
    {
        for (int k = i; k < 9; ++k)
        {
            for (int l = 6; l < 9; ++l)
            {
                for (int j = l; j < 9; ++j)
                {
                    if (board[k][l] == board[i][j])
                        --cdouble;
                }
            }
        }
    }
    
    //cout << cdouble << endl;
	return cdouble;
/*
    cout << "start of fitnessEval" << endl;
	int fitness=216;
	int row [9] = {0,0,0,0,0,0,0,0,0};
	int column [9] = {0,0,0,0,0,0,0,0,0};
	int subGrid [9] = {0,0,0,0,0,0,0,0,0};

	//Loop nine times 
	for(int i=0;i<9;++i)
	{
		//original number	
		for(int j=0;j<8;++j)
		{
			//check for duplicate in row
			for(int r=1;r<9;++r)
			{
				if(checkedAlready(row,board[i][j]))
					break;
				if(board[i][j]==board[i][r])
					--fitness;
			}

			//check for duplicate in columns
			for(int c=1;c<9;++c)
			{
				if(checkedAlready(column,board[j][i]))
					break;
				if(board[j][i]==board[c][i])
					--fitness;
			}

		}
		//reset the already checked already to all zeros
		for(int p=0;p<9;++p)
		{
			row[p]=0;
			column[p]=0;
		}
	}

	for(int r=0;r<7;r+=3)
	{
		for(int c=0;c<7;c+=3)
		{
			for(int c1=0;c1<3;++c1)
			{

				for(int c2=1;c2<3;c2++)
				{
					if(checkedAlready(subGrid,board[r][c1]))
						break;
					if(board[r][c+c1]==board[r][c+c2])
						--fitness;
				}
				if(board[r][c+c1]==board[r+1][c+c1])
					--fitness;
				if(board[r][c+c1]==board[r+2][c+c1])
					--fitness;

			}
			for(int p;p<9;++p)
				subGrid[p]=0;

		}
		for(int p;p<9;++p)
			subGrid[p]=0;

	}

    cout << "end of fitness eval" << endl;
	return fitness;
*/


}

int Chromosome::checkedAlready(int array [],int num)
{	
	for(int i=0;i<9;++i)
	{
		if(num==array[i])
			return 1;
		if(array[i]==0)
		{
			array[i]=num;
			return 0;
		}
	}
	return 0;

}
