#include "TXlib.h";

void chelovek (int x, int y, double size,double ruki,double nogi, double glaza, double rot );
void fon (int x,int y);
void tank_go (int *x, int *y,int *vx,int *vy,int dt);
void upravlenie (int *x, int *y, int dt, int *vx, int *vy);
void tankdrawright (int x,int y);
void tankdrawleft (int x,int y);
void tankdrawup (int x,int y);
void tankdrawdown (int x,int y);
void pula (int x, int y);void vzriv (int x,int y);
int main ()
    {
    HDC vzriv1 = txLoadImage ("vzriv 1.bmp");
    HDC vzriv2 = txLoadImage ("G:\\images\\vzriv 2.bmp");
    HDC vzriv3 = txLoadImage ("G:\\images\\vzriv 3.bmp");

    int x = 200;
    int y = 500;
    int vx = 2;
    int vy = 2;
    int dt = 1;

    txCreateWindow (1440,1000);

    tank_go (&x, &y, &vx, &vy, dt);

    chelovek (200, 500,3,1,2,5,1);
    pula (800 , 600);

    txBitBlt (txDC (), x , y, x + 100, y + 100, vzriv1, 0, 0);

    txDeleteDC (vzriv1);
    return 0;
    }

//-----------------------------------------------------------------------------
void chelovek (int x, int y, double size,double ruki,double nogi, double glaza, double rot )
    {
    txSetFillColor (RGB (252, 218, 191));
    txCircle (x, y - 20, 20);

    txSetFillColor (TX_BLACK);
    txSetColor (TX_BLACK, 2);
    txLine (x, y, x, y + 50);   //x 1300 620
    txLine (x, y + 50, x - 10/size*nogi, y + 80);
    txLine (x, y + 50, x + 10/size*nogi, y + 80);

    txLine (x, y + 30/size*ruki, x - 20, y + 30);
    txLine (x, y + 30/size*ruki, x + 20, y + 30);

    txSetFillColor (TX_WHITE);
    txSetColor (TX_BLACK, 2);
    txCircle (x - 10, y - 20, 1*glaza);
    txCircle (x + 10, y - 20, 1*glaza);
    txLine   (x - 10, y - 10,    x,      y - 5*rot);
    txLine   (x,      y - 5*rot, x + 10, y -10);

    txSetFillColor (TX_BLACK);
    txSetColor (TX_BLACK, 2);
    txCircle (x + 10, y - 20, 0.5);
    txCircle (x - 10, y - 20, 0.5);
    }

//-----------------------------------------------------------------------------
void fon (int x, int y)
  {
  txSetFillColor (TX_WHITE);
  txRectangle(x, y, x + 1440, y + 1000);
  }

//-----------------------------------------------------------------------------
void tank_go (int *x, int *y, int *vx, int *vy, int dt)
    {
    while (!txGetAsyncKeyState (VK_SPACE))
        {
        txClear ();
        fon (0,0);

        upravlenie (x, y, dt, vx, vy );
                             /*chelovek (*x, *y, 3 , 1 ,t%6 ,5,1);*/

        if (*x < 40)   {*x = 41;}

        if (*x > 1350) {*x = 1349;}

        if (*y > 990)  {*y = 989;}

        if (*y < 10)   {*y = 11;}

        txSleep (10);

        }
    }

//-----------------------------------------------------------------------------
void upravlenie (int *x, int *y,int dt,int *vx,int *vy )
    {

    if (txGetAsyncKeyState ('A'))    {*x = *x - *vx * dt; txClear(); fon (0,0); tankdrawleft  (*x, *y);}

    if (txGetAsyncKeyState ('D'))    {*x = *x + *vx * dt; txClear(); fon (0,0); tankdrawright (*x, *y);}

    if (txGetAsyncKeyState ('W'))    {*y = *y - *vy * dt; txClear(); fon (0,0); tankdrawup    (*x,*y);}

    if (txGetAsyncKeyState ('S'))    {*y = *y + *vy * dt; txClear(); fon (0,0); tankdrawdown  (*x,*y);}
    }


 //-----------------------------------------------------------------------------
 void tankdrawright (int x,int y)
     {
     txSetColor (TX_BLACK,1 );
     txSetFillColor(TX_GREEN);
     txRectangle (x, y, x + 80, y + 40);

     txSetColor (TX_BLACK,1);
     txSetFillColor (TX_GREY);
     txRectangle (x - 10 , y ,x, y + 15);
     txRectangle (x - 10 , y + 25 ,x , y + 40);
     txRectangle (x + 80, y, x + 90, y + 15);
     txRectangle (x + 80,y + 25,x + 90, y + 40);

     txSetColor (TX_BLACK,1);
     txSetFillColor(TX_GREEN);
     txRectangle (x + 50 , y + 10, x + 70, y + 30);
     txSetColor (TX_BLACK, 2);
     txLine (x + 70, y + 20, x + 100, y + 20);

      pula (x + 70, y + 20);
     }

 //-----------------------------------------------------------------------------
void tankdrawleft (int x,int y)
    {
    txSetColor (TX_BLACK,1 );
    txSetFillColor(TX_GREEN);
    txRectangle (x, y, x + 80, y + 40);

    txSetColor (TX_BLACK,1);
    txSetFillColor (TX_GREY);
    txRectangle (x - 10 , y ,x, y + 15);
    txRectangle (x - 10 , y + 25 ,x , y + 40);
    txRectangle (x + 80, y, x + 90, y + 15);
    txRectangle (x + 80,y + 25,x + 90, y + 40);

    txSetColor (TX_BLACK,1);
    txSetFillColor(TX_GREEN);
    txRectangle (x + 10, y + 10, x + 30, y + 30);
    txSetColor (TX_BLACK, 2);
    txLine (x + 10, y + 20, x - 20, y + 20);

      pula (x + 7, y + 20);
      }

//-----------------------------------------------------------------------------
 void tankdrawup (int x,int y)
     {
     txSetColor (TX_BLACK,1 );
     txSetFillColor(TX_GREEN);
     txRectangle (x, y, x + 40, y + 80);

     txSetColor (TX_BLACK,1);
     txSetFillColor (TX_GREY);
     txRectangle (x , y - 10,x + 15, y);
     txRectangle (x + 25 , y - 10 ,x + 40, y);
     txRectangle (x, y + 80, x + 15, y + 90);
     txRectangle (x + 25,y + 80,x + 40, y + 90);

     txSetColor (TX_BLACK,1);
     txSetFillColor(TX_GREEN);
     txRectangle (x + 10, y + 10, x + 30, y + 30);
     txSetColor (TX_BLACK, 2);
     txLine (x + 20, y + 10, x + 20, y - 20);

     pula (x + 20, y + 7);
     }

//-----------------------------------------------------------------------------
 void tankdrawdown (int x,int y)
     {
     txSetColor (TX_BLACK,1);
     txSetFillColor(TX_GREEN);
     txRectangle (x, y , x + 40, y + 80);

     txSetColor (TX_BLACK,1);
     txSetFillColor (TX_GREY);
     txRectangle (x , y - 10,x + 15, y);
     txRectangle (x + 25 , y - 10 ,x + 40, y);
     txRectangle (x, y + 80, x + 15, y + 90);
     txRectangle (x + 25,y + 80,x + 40, y + 90);

     txSetColor (TX_BLACK,1);
     txSetFillColor(TX_GREEN);
     txRectangle (x + 10, y + 50, x + 30, y + 70);
     txSetColor (TX_BLACK, 2);
     txLine (x + 20, y + 70, x + 20, y + 100);

     pula (x + 17, y + 70);
     }


//-----------------------------------------------------------------------------
void pula (int x, int y)
    {
    txSetColor (TX_BLACK);
    txSetFillColor (TX_BLACK);
    txRectangle (x, y, x + 3, y + 3);
    }


//-----------------------------------------------------------------------------
/*void strelba_polet (int *x , int *y, int *vpx, int *vpy, int dt)
    {
    while (!txGetAsyncKeyState ('M'))
        {
        *x = *x + *vpx * dt;
        *y = *y + *vpy * dt;

        if (x < 0)    {vzriv (x, y);}
        if (x > 1440) {vzriv (x, y);}
        if (y > 1000) {vzriv (x, y);}
        if (y < 0)    {vzriv (x, y);}
        }
    } */


//-----------------------------------------------------------------------------
void vzriv (double x,double y)
    {
    HDC vzriv1 = txLoadImage ("..\images\\vzriv 1.bmp, 100, 100");
    HDC vzriv2 = txLoadImage ("images\\vzriv 2.bmp");
    HDC vzriv3 = txLoadImage ("images\\vzriv 3.bmp");

    txBitBlt (txDC (), x , y, x + 100, y + 100, vzriv1, 0, 0);

    }































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































