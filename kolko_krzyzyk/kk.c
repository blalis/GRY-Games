#include <stdio.h>
#include <stdlib.h>
char gra[3][3];
int game=0;
int sprawdz(int pole);
void print_game();
void graj(int pole,char znak);
void koniec_gry(char znak);
int main()
{
  int i,num;
  char znak;
  for(i=0;i<9;i++)
  {
    print_game();
    do{
      if(i%2==0)
      {
        printf("Podaj pole w ktorym chcesz ustawic kolko: ");
        znak='K';
      }
      else
      {
        printf("Podaj pole w ktorym chcesz ustawic krzyzyk: ");
        znak='X';
      }
      scanf("%d",&num);
      if(num<1 || num>9)
      {
        printf("\nPole nie miesci sie w zakresie od 1 do 9.\n");
      }
      else if(sprawdz(num)==1)
      {
        printf("Pole jest juz zajete.\n");
      }
    }while(num<1 || num>9 || sprawdz(num)==1);
    graj(num,znak);
    if(game==1)
    {
      printf("\n");
      return 0;
    }
    else if(i==8)
    {
      system("clear");
      print_game();
      printf("Remis\n");
      printf("Koniec gry\n");
      return 0;
    }
    system("clear");
  }
}
int sprawdz(int pole)
{
  int modx=pole%3;
  int mody=pole/3;
  if(modx==0)
  {
    modx=2;
    mody=mody-1;
  }
  else
  {
    modx=modx-1;
  }
  if(gra[mody][modx]=='X' || gra[mody][modx]=='K')
    return 1;
  else
    return 0;
}
void print_game()
{
  int i,j,count=0;
  for(i=0;i<3;i++)
  {
    for(j=0;j<13;j++)
    {
      printf("-");
    }
    printf("\n");
    for(j=0;j<3;j++)
    {
      count++;
      printf("| ");
      if(gra[i][j]=='X' || gra[i][j]=='K')
        printf("%c",gra[i][j]);
      else
        printf("%d",count);
      printf(" ");
    }
    printf("|\n");
  }
  for(i=0;i<13;i++)
  {
    printf("-");
  }
  printf("\n");
}
void graj(int pole,char znak)
{
  int i,j,testy,testx;
  int modx=pole%3;
  int mody=pole/3;
  if(modx==0)
  {
    modx=2;
    mody=mody-1;
  }
  else
  {
    modx=modx-1;
  }
  if(gra[mody][modx]!='X' && gra[mody][modx]!='K')
    gra[mody][modx]=znak;

  if(gra[0][0]==znak && gra[1][1]==znak && gra[2][2]==znak)
    koniec_gry(znak);
  if(gra[0][2]==znak && gra[1][1]==znak && gra[2][0]==znak)
    koniec_gry(znak);
  for(i=0;i<3;i++)
  {
    testx=0;
    testy=0;
    for(j=0;j<3;j++)
    {
      if(gra[i][j]==znak)
      {
        testy++;
      }
      if(gra[j][i]==znak)
      {
        testx++;
      }
    }
    if(testx==3 || testy==3)
    {
      koniec_gry(znak);
      break;
    }
  }

}
void koniec_gry(char znak)
{
  system("clear");
  print_game();
  printf("\nGratulacje!\n");
  if(znak=='K')
    printf("Wygrana dla kolko\n");
  else
    printf("Wygrana dla krzyzyk\n");
  printf("Koniec gry");
  game=1;
}
