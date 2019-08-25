#include<iostream>
#include<stack>
#include<cstdlib>
#include<ctime>
using namespace std;
class MazeCell
{
	friend class maze;
   public:
   	MazeCell()
   	{
   		x=y=0;
   		for(int i=0;i<4;i++)
   		wall[i]=1;
   		isVisit=false;
   	}
   private:
   	bool isVisit;
   	int x,y;
	int wall[4]; 	
};
class Point
{
	friend class maze;
   private:
   	int direction;
   	int x;
   	int y;
};
class maze
{
	public:
		maze(int m=11,int n=11);
		void generator();
		void printMaze();
		bool judgeCell(int,int);
		void breakWall(MazeCell*);
		void travel();
		~maze();
	private:
		int startPoint;
		int endPoint;
		int row;
		int column;
		stack<MazeCell>mazeStack;
		MazeCell**matrix;
		int total;
		int visit;
		int**graph;
		int graphRow;
		int graphColumn;
		MazeCell*currentCell;
		Point goPoint;
};
const int shang=0;
const int xia=1;
const int zuo=2;
const int you=3;
maze::maze(int m,int n)
{
	while(m%2==0||n%2==0)
	{
		cout<<"输入错误请从新输入：";
		cin>>m>>n;
	}
	visit=0;
	row=(m-1)/2;
	column=(n-1)/2;
	total=row*column;
	srand(time(0));
	matrix=new MazeCell*[row];
	for(int i=0;i<row;i++)
	{
	   matrix[i]=new MazeCell[column];	
	}
	for(int i=0;i<row;i++)
	for(int j=0;j<column;j++)
	{
	   matrix[i][j].x=i;
	   matrix[i][j].y=j;	
	}
	graphRow=m;
	graphColumn=n;
	graph=new int*[graphRow];
	for(int i=0;i<graphRow;i++)
	graph[i]=new int[graphColumn];
	for(int i=0;i<graphRow;i++)
	for(int j=0;j<graphColumn;j++)
	graph[i][j]=1;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		graph[2*i+1][2*j+1]=0;
	}
}
maze::~maze()
{
	for(int i=0;i<row;i++)
	delete[]matrix[i];
	delete[]matrix;
	for(int i=0;i<graphRow;i++)
	delete[]graph[i];
	delete[]graph;
}
void maze::printMaze()
{
	for(int i=0;i<row;i++)
	{
	  for(int j=0;j<graphColumn;j++)
	  {
	     if(graph[i][j]==0)
		 cout<<' ';
		 else if(graph[i][j]==1)
		 cout<<'#';
		 else if(graph[i][j]==2)
		 cout<<'o';
		 else
		 cout<<'x';	
	  }
	  cout<<endl;	
	}
}
void maze::breakWall(MazeCell*tempCell)
{
	int relation;
	if(tempCell->x!=currentCell->x)
	{
	   relation=tempCell->x-currentCell->x;
	   if(relation==1)
	   currentCell->wall[1]=tempCell->wall[0]=0;
	   else
	   currentCell->wall[0]=tempCell->wall[1]=0;
	}
	else
	{
	   relation=tempCell->y-currentCell->y;
	   if(relation==1)
	   currentCell->wall[3]=tempCell->wall[2]=0;
	   else
	   currentCell->wall[2]=tempCell->wall[3]=0;
	}
}
bool maze::judgeCell(int x,int y)
{
	if(x<0||x>row-1)
	return false;
	if(y<0||y>column-1)
	return false;
	if(matrix[x][y].isVisit)
	return false;
	return true;
}
void maze::generator()
{
	int count1=0,count2=0;
	currentCell=&matrix[0][0];
	currentCell->isVisit=true;visit+=1;
	int currentX=currentCell->x;
	int currentY=currentCell->y;
	MazeCell*tempCell;
	while(total>visit)
	{
		int i=0;
		MazeCell*temp[4];
		if(judgeCell(currentX+1,currentY))
		{
			temp[i]=&matrix[currentX+1][currentY];
			i++;
		}
		if(judgeCell(currentX-1,currentY))
		{
			temp[i]=&matrix[currentX-1][currentY];
			i++;
		}
			if(judgeCell(currentX,currentY+1))
		{
			temp[i]=&matrix[currentX][currentY+1];
			i++;
		}
		if(judgeCell(currentX,currentY-1))
		{
			temp[i]=&matrix[currentX][currentY-1];
			i++;
		}
		if(visit==0)
		count2=i;
		else
		{
			int tempp;
			tempp=count2;
			count2=i;
			count1=tempp;
		}
		if(i>0)
		{
			int s=rand()%i;
			tempCell=temp[s];
			breakWall(tempCell);
			mazeStack.push(*currentCell);
			currentCell=tempCell;
			currentCell->isVisit=true;
			visit++;
			currentX=currentCell->x;
			currentY=currentCell->y;
		}
		else
		{
			if(!mazeStack.empty()&&count1>1)
			{
			   currentCell->isVisit=false;
			   visit--;
			   currentCell=&mazeStack.top();
			   mazeStack.pop();	
			}
			else
			{
			  mazeStack.push(*currentCell);
			  int a1=rand()%row,a2=rand()%column;
			  while(!matrix[a1][a2].isVisit)
			  {
			  	a1=rand()%row;
			  	a2=rand()%column;
			  }
			  currentCell=&matrix[a1][a2];
			  currentX=currentCell->x;
			  currentY=currentCell->y;	
			}
		}
	}
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
		  graph[2*i][2*j+1]=*matrix[i][j].wall;
		  if(i==row-1)
	      {
			  graph[2*i+2][2*j+1]=*(matrix[i][j].wall+1);
		  }
	    }
	}
	for(int j=0;j<column;j++)
	{
		for(int i=0;i<row;i++)
		{
		  graph[2*i+1][2*j]=*(matrix[i][j].wall+2);
		  if(i==column-1)
	      {
			  graph[2*i+1][2*j+2]=*(matrix[i][j].wall+3);
		  }
	    }
	}
	startPoint=2*(rand()%row)+1;
	endPoint=2*(rand()%row)+1;
	graph[startPoint][0]=graph[endPoint][graphColumn-1]=0;
	cout<<"现在生成迷宫！！"<<endl;
	printMaze(); 
}
void maze::travel()
{
	goPoint.x=startPoint;
	goPoint.direction=you;
	goPoint.y=0;
	graph[startPoint][0]=2;
//	cout<<"说明：o表示第一次经过，x表示第二次经过";
//	cout<<"现在最左边的那个o是起点"<<endl;
	printMaze();
	while(goPoint.y!=graphColumn-1)
	{
		switch(goPoint.direction)
		{
			case you:
				if(graph[goPoint.x+1][goPoint.y==1])
				{
					if(graph[goPoint.x][goPoint.y+1]!=1)
					{
						goPoint.y=goPoint.y+1;
					}
					else
					{
					     if(graph[goPoint.x-1][goPoint.y]!=1)
						 {
						 	goPoint.x-=1;
						 	goPoint.direction=shang;
						 }
						 else
						 {
						 	goPoint.y-=1;
						 	goPoint.direction=zuo;
						 }	
					}
				}
				else 
				{
					goPoint.x+=1;
					goPoint.direction=xia;
			
				}
				break;
			case shang:
				if(graph[goPoint.x][goPoint.y+1==1])
				{
					if(graph[goPoint.x-1][goPoint.y]!=1)
					{
						goPoint.x-=1;
					}
					else
					{
					     if(graph[goPoint.x][goPoint.y-1]!=1)
						 {
						 	goPoint.y-=1;
						 	goPoint.direction=zuo;
						 }
						 else
						 {
						 	goPoint.x+=1;
						 	goPoint.direction=xia;
						 }	
					}
				}
				else 
				{
					goPoint.y+=1;
					goPoint.direction=you;
			
				}
				break;
			case xia:
				if(graph[goPoint.x][goPoint.y-1==1])
				{
					if(graph[goPoint.x+1][goPoint.y]!=1)
					{
						goPoint.x+=1;
					}
					else
					{
					     if(graph[goPoint.x][goPoint.y+1]!=1)
						 {
						 	goPoint.y+=1;
						 	goPoint.direction=you;
						 }
						 else
						 {
						 	goPoint.x-=1;
						 	goPoint.direction=shang;
						 }	
					}
				}
				else 
				{
					goPoint.y-=1;
					goPoint.direction=zuo;
			
				}
				break;
			case zuo:
				if(graph[goPoint.x-1][goPoint.y==1])
				{
					if(graph[goPoint.x][goPoint.y-1]!=1)
					{
						goPoint.y-=1;
					}
					else
					{
					     if(graph[goPoint.x+1][goPoint.y]!=1)
						 {
						 	goPoint.x+=1;
						 	goPoint.direction=xia;
						 }
						 else
						 {
						 	goPoint.y+=1;
						 	goPoint.direction=you;
						 }	
					}
				}
				else 
				{
					goPoint.x-=1;
					goPoint.direction=shang;
			
				}
				break;
				
		}
		if(graph[goPoint.x][goPoint.y]==0)
		graph[goPoint.x][goPoint.y]==2;
		else
		graph[goPoint.x][goPoint.y]==3;
//		cout<<"要走下一步咯，";
		system("pause");
		printMaze();
		if(goPoint.y==0)
		{
			cout<<"迷宫没有通路！回到入口"<<endl;
			break; 
		}
		if(goPoint.y==graphColumn-1)
		cout<<"嘿嘿，走迷宫咯！！"<<endl; 
	}
}
int main()
{
	int m,n;
	cout<<"请输入迷宫长度：（奇数）";
	cin>>m>>n;
	maze maze1(m,n);
	maze1.generator();
	maze1.travel();
	system("pause");
	return 0; 
}
