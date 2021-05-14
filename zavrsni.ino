int stupac[16]={A2,A3,A4,A5,1,0,A0,A1,5,4,3,2,9,8,7,6};
int red[4]={10,11,12,13};
int t=500;
int i,krv=10;

int niz1[16]={A2,A3,A4,A5,A1,A0,0,1,5,4,3,2,6,7,8,9};
int niz2[16]={3,4,0,A0,A1,2,6,7,8,9,5,1,A2,A3,A4,A5};
int niz3[4]={A2,0,3,6};
int niz4[4]={6,7,8,9};
int niz5[4]={9,8,7,6};
int niz6[4]={6,3,0,A2};
int niz7[4]={A5,A0,5,6};

struct duh
{
  int red=0, dioda;
} test[40];

/* A2 -1-1
 * A3 -2-1
 * A4 -3-1
 * A5 -4-1
 * 1  -1-2
 * 0  -2-2
 * A0 -3-2
 * A1 -4-2
 * 5  -1-3
 * 4  -2-3
 * 3  -3-3
 * 2  -4-3
 * 9  -1-4
 * 8  -2-4
 * 7  -3-4
 * 6  -4-4
 * 
 * 
 * 10-4. red
 * 11-3. red
 * 12-2. red
 * 13-1. red
 */
void setup() {
  
for(int i=0;i<16;i++)
{
  pinMode(stupac[i],OUTPUT);  
}

for(int i=0;i<4;i++)
{
  pinMode(red[i],OUTPUT);
}
for(i=0;i<40;i++)
{
  test[i].dioda=200;
}
}



void loop() 
{
  dijagonala();
  iskljucisve();
  delay(200);
  gore_dole();
  delay(200);
  blinkanje();
  zmija();
  vrtlog();
  ghost();
}



//**************************************************
  void iskljucisve()
  {
      for(int i=0;i<16;i++)
      {
        digitalWrite(stupac[i],0);
      }  
    for(int i=0;i<4;i++)
      {
        digitalWrite(red[i],0);
      }
  }
//**************************************************
  void ukljucisve()
  {
    for(i=0;i<16;i++)
      {
        digitalWrite(stupac[i],1);
      }  
    for(i=0;i<4;i++)
      {
        digitalWrite(red[i],1);
      }
  }
//**************************************************
void ukljucired()
{
  for(i=0;i<4;i++)
  {
    digitalWrite(red[i],1);
  }
}
//**************************************************
void iskljucired()
{
  for(i=0;i<4;i++)
  {
    digitalWrite(red[i],0);
  }
}
//**************************************************
void ukljucistupac()
{
  for(i=0;i<16;i++)
  {
    digitalWrite(stupac[i],1);
  }
}
//**************************************************
void iskljucistupac()
{
  for(i=0;i<16;i++)
  {
    digitalWrite(stupac[i],0);
  }
}
//**************************************************
  void blinkanje()
  {
    int i=50;
    while(i!=0)
    {
       ukljucisve();
       delay(t);
       iskljucisve();
       delay(t);
       i-=10; 
    }
  }
//**************************************************
void zmija()
{
  iskljucisve();
 
    digitalWrite(red[0],1);
    for(int j=0;j<16;j++)
      {
        digitalWrite(niz1[j],1);
        if(j>2)
        digitalWrite(niz1[j-3],0);
        delay(100);
        
      }
    digitalWrite(7,0);
    delay(100);
    digitalWrite(8,0);
    delay(100);

    digitalWrite(red[1],1);
    delay(100);
     for(int j=15;j>=0;j--)
      {
        digitalWrite(niz1[j],1);
        if(j==14)
        digitalWrite(red[0],0);

        digitalWrite(niz1[j+3],0);
        delay(100);
        
      }

     digitalWrite(A4,0);
    delay(100);
    digitalWrite(A3,0);
    delay(100);
    digitalWrite(red[2],1);
    delay(100);

    for(int j=0;j<16;j++)
      {
        digitalWrite(niz1[j],1);
        if(j==1)
        digitalWrite(red[1],0);
        digitalWrite(niz1[j-3],0);
        delay(100);
        
      }

    digitalWrite(7,0);
    delay(100);
    digitalWrite(8,0);
    delay(100);

    digitalWrite(red[3],1);
    delay(100);
     for(int j=15;j>=0;j--)
      {
        digitalWrite(niz1[j],1);
        if(j==14)
        digitalWrite(red[2],0);

        digitalWrite(niz1[j+3],0);
        delay(100);
        
      }
    digitalWrite(A4,0);
    delay(100);
    digitalWrite(A3,0);
    delay(100);
}
//**************************************************
void vrtlog()
{
  iskljucisve();
  ukljucired();
  for(i=0;i<16;i++)
  {
    digitalWrite(niz2[i],1);
    delay(100);
  }
  for(i=0;i<16;i++)
  {
    digitalWrite(niz2[i],0);
    delay(100);
  }
}
//**************************************************
void gore_dole()
{
  iskljucisve();
  ukljucistupac();
  for(i=3;i>=0;i--)
  {
    digitalWrite(red[i],1);
    delay(200);
  }
  for(i=3;i>=0;i--)
  {
    digitalWrite(red[i],0);
    delay(200);
  }  
}
//**************************************************
void dijagonala()
{
  iskljucisve();
  for(i=0;i<4;i++)
  {
    digitalWrite(red[i-1],0);
    digitalWrite(niz3[i-1],0);
    digitalWrite(niz3[i],1);
    digitalWrite(red[i],1);
    delay(75);
  }
  for(i=1;i<4;i++)
  {
    
    digitalWrite(niz4[i-1],0);
    digitalWrite(niz4[i],1);
    delay(75);
  }
  for(i=1;i<4;i++)
  {
    digitalWrite(niz5[i-1],0);
    digitalWrite(red[4-i],0);
    digitalWrite(niz5[i],1);
    digitalWrite(red[3-i],1);
    delay(75);
  }
  for(i=1;i<4;i++)
  {
    digitalWrite(niz6[i-1],0);
    digitalWrite(niz6[i],1);
    delay(75);
  }
  for(i=1;i<4;i++)
  {
    digitalWrite(niz1[i],1);
    delay(75);
  }
  for(i=0;i<3;i++)
  {
    digitalWrite(red[i],0);
    digitalWrite(red[i+1],1);
    for(int j=0;j<4;j++)
    {
     digitalWrite(niz1[j+4*i],0);
     digitalWrite(niz1[4+j+4*i],1); 
    }
    
    delay(125);
  }
  for(i=2;i>=0;i--)
  {
    digitalWrite(red[i],1);
    delay(75);  
  }
  delay(200);
  for(i=3;i>=0;i--)
  {
    for(int j=0;j<4;j++)
    {
      digitalWrite(niz1[j+4*i],1);
    }
    delay(75);  
  }
  delay(2000);
  for(i=0;i<3;i++)
  {
    digitalWrite(red[i],0);
    delay(75);  
  }
}
//*************************************************
void matrix(int pz)
{
   for(i=0;i<4;i++)
  {
    digitalWrite(red[i],1);
    for(int j=0;j<16;j++)
    {
      if(test[j].red==i)
      {
        digitalWrite(test[j].dioda,1);
        delay(pz);
        digitalWrite(test[j].dioda,0);
      } 
    }
    digitalWrite(red[i],0);
  }
}
//**************************************************
void ghost()
{
  test[0].dioda=5;
  test[1].dioda=6;
  test[2].dioda=A0;
  test[3].dioda=A5;

  test[0].red=3;
  test[1].red=3;
  test[2].red=0;
  test[3].red=0;
   
  
  iskljucisve();
  for(int k=0;k<200;k++){
    if(k==6)
    {
     test[3].red=1;
    }
    else if(k==12)
    {
     test[3].red=2;
    }
    else if(k==18)
    {
     test[3].red=3; 
    }
    else if(k==85)
    {
      test[1].red=2;
    }
    else if(k==91)
    {
      test[1].red=1;
    }
    else if(k==97)
    {
      test[1].red=0;
    }
    else if(k==130)
    {
      test[2].red=1;
    }
    else if(k==136)
    {
      test[2].red=2;
    }
    else if(k==142)
    {
      test[2].red=3;
    }
    else if(k==173)
    {
      test[0].red=2;
    }
    else if(k==179)
    {
      test[0].red=1;
    }
    else if(k==185)
    {
      test[0].red=0;
    }
    matrix(1);
}
}
//**************************************************
