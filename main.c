#include <stdio.h>
#include <stdlib.h>
int head,tail;
char map[55][55];
int way1[5]={0,1,0,-1,0},way2[5]={0,0,1,0,-1};
struct go
{
    int x,y,d,p;
}way[1001];

int allow (int x,int y)
{
    if (x>0&&x<=20&&y>0&&y<=20)
        if (map[x][y]=='.')
            return 1;
    return 0;

}

void give_num(int x,int y)
{
    ++tail;
    way[tail].x=x;
    way[tail].y=y;
    way[tail].d=way[head].d+1;
    way[tail].p=head;
    return;
}
int main()
{
    int i,j,x,y;
    FILE *fp;
    fp=fopen("migong.txt","r");
    if (fp==NULL)
    {
        printf("无法打开文件\n");
        exit(0);
    }
    for (i=1;i<=20;i++)
    {
        for (j=1;j<=21;j++)
        {
            fscanf(fp,"%c",&map[i][j]);
            if(map[i][j]=='S')
            {
                x=i;
                y=j;
            }
        }
    }
    way[1].x=x;
    way[1].y=y;
    way[1].d=0;
    way[1].p=0;
    head=tail=1;
    do{
            if (map[way[head].x][way[head].y]=='E')
                    break;
            int k;
            for (k=1;k<=4;++k)
                if (allow(way[head].x+way1[k],way[head].y+way2[k]))
                    give_num(way[head].x+way1[k],way[head].y+way2[k]);
            map[way[tail].x][way[tail].y]=',';
            ++head;
    }while(tail>=head);
    x=tail;
    while (x)
    {
        map[way[x].x][way[x].y]='>';
        x=way[x].p;
    }
    for (i=1;i<=20;i++)
    {
        for (j=1;j<=21;j++)
        {
           if (map[i][j]=='>')
                map[i][j]='.';
        }
    }
     for (i=1;i<=20;i++)
    {
        for (j=1;j<=21;j++)
        {
            printf("%c",map[i][j]);
        }
    }

    return 0;
}

