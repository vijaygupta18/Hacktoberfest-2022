#include <LiquidCrystal.h>
#include <avr/interrupt.h>

#define D4 6
#define D5 7
#define D6 8
#define D7 9
#define RS 12
#define EN 11

#define Player_1_moveUpButton 5     
#define Player_1_moveDownButton 10   
#define Player_2_moveUpButton 3   
#define Player_2_moveDownButton 2   

#define Player_1 1
#define Player_2 2

#define DiagonalballUpdateTime 21
#define HorizontalballUpdateTime 15

#define Start_X 35
#define Start_Y 7

#define Button_Pressed (p1_UpButState | p1_DownButState | p2_UpButState | p2_DownButState)

void(* resetFunc) (void) = 0;       

volatile boolean x_Up = true;
volatile boolean x_Down = true;

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);    

class Paddle
{
  public:
  uint8_t PaddleColArray[16] = {0,0,0,0,0,4,4,4,0,0,0,0,0,0,0,0};
  
  uint8_t PaddlePos = 6;     
  uint8_t Score = 0;           
  void MovePaddleUp()
  {
    if(PaddlePos != 1)
    {
      PaddlePos--;
      PaddleColArray[PaddlePos+2]=0;
      PaddleColArray[PaddlePos-1]=4;
    }
  }

  void MovePaddleDown()
  {
    if(PaddlePos != 14)
    {
      PaddlePos++;
      PaddleColArray[PaddlePos-2]=0;
      PaddleColArray[PaddlePos+1]=4;
    }
  }

  void PrintPaddles(uint8_t Player_Num)
  {
    if(Player_Num == 2)
    {
      lcd.createChar(0, PaddleColArray);
      lcd.createChar(1, PaddleColArray+8);

      lcd.setCursor(14, 0);
      lcd.write(byte(0));

      lcd.setCursor(14, 1);
      lcd.write(byte(1));
    }
  
    else
    {
      lcd.createChar(2, PaddleColArray);
      lcd.createChar(3, PaddleColArray+8);
  
      lcd.setCursor(1, 0);
      lcd.write(byte(2));

      lcd.setCursor(1, 1);
      lcd.write(byte(3));
    }
  }
};

Paddle p1, p2;


class Print_Game
{
  public:

  void Start_Game()
  {
    lcd.print(F("    FUN PONG   "));
    
    lcd.setCursor(0, 1);
    lcd.print(F(" PRESS A BUTTON "));

    uint8_t p1_UpButState = 0;
    uint8_t p1_DownButState = 0;
    uint8_t p2_UpButState = 0;
    uint8_t p2_DownButState = 0;
    
    while(!(Button_Pressed))
    {
      p1_UpButState = ((PIND & (1 << Player_1_moveUpButton)) );
      p1_DownButState = ((PINB & (1 << (Player_1_moveDownButton-8))) );
      p2_UpButState = ((PIND & (1 << Player_2_moveUpButton)) );
      p2_DownButState = ((PIND & (1 << Player_2_moveDownButton)) );
    }
    lcd.clear();
  }

  void Print_Score()
  {
    lcd.clear();
    lcd.print(F("PLAYER1  PLAYER2"));
    lcd.setCursor(3 ,1);
    lcd.print(p1.Score);
    lcd.setCursor(12 ,1);
    lcd.print(p2.Score);

    delay(2000);

    lcd.clear();
  }

  void Print_Winner(int Player_Num)
  {
    lcd.setCursor(0 ,0);
    lcd.print(F("   GAME  OVER   "));
    lcd.setCursor(1, 1);
    lcd.print(F("PLAYER "));
    lcd.print(Player_Num);
    lcd.setCursor(11 ,1);
    lcd.print(F("WINS"));

    delay(5000);

    resetFunc();
  }
};

Print_Game g;

class Ball
{
  private:

  uint8_t Point_Scored = 0;
  
  uint8_t ballYDir = 0;       
  uint8_t ballXDir = -1;        
  uint8_t ballY = Start_Y;
  uint8_t ballX = Start_X;

  uint8_t ballCharArray[8] = {0, 0, 0, 0, 0, 0, 0, 16};

  public:

  void GenerateBallArray();

  void PrintBall();

  void UpdateBall(uint8_t , uint8_t);

  void AwardAPoint();
};

void Ball :: GenerateBallArray()
{
  for(uint8_t i=0; i<8; i++)
    {
    if(i == (ballY % 8))
    {
      ballCharArray[i] = 2 << (4 - (ballX % 5));
    }
    else
    {
      ballCharArray[i] = 0;
    }
  }
}

void Ball :: PrintBall()
{
  uint8_t LCDCol = ballX / 5;

  uint8_t LCDRow = (ballY <= 7) ? 0 : 1;

  lcd.createChar(4, ballCharArray);

  lcd.setCursor(LCDCol,LCDRow);

  lcd.write(byte(4));
}

void Ball :: UpdateBall(uint8_t P1_PaddlePos, uint8_t P2_PaddlePos)
{
  if(ballYDir)          
  {
    delay(DiagonalballUpdateTime);
  }
  else                  
  {
    delay(HorizontalballUpdateTime);
  }

  if((ballX <= 6) || (ballX >= 73))
  {
    AwardAPoint();
  }

  else if(ballX == 72)
  {
    if(ballY == P2_PaddlePos)
    {
      ballXDir = -1;
    }

    else if(ballY == (P2_PaddlePos + 1))
    {
      ballXDir = -1;
      if(ballY == 15)    
      {
        ballYDir = -1;
      }
      else
      {
        ballYDir = 1;
      }
    }

    else if(ballY == (P2_PaddlePos - 1)){
      ballXDir = -1;
      if(ballY == 0)    
      {
        ballYDir = 1;
      }
      else
      {
        ballYDir = -1;
      }
    }
  }

  else if(ballX == 7)
  {
    if(ballY == P1_PaddlePos)
    {
      ballXDir = 1;
    }

    else if(ballY == (P1_PaddlePos + 1)){
      ballXDir = 1;
      if(ballY == 15)    
      {
        ballYDir = -1;
      }
      else
      {
        ballYDir = 1;
      }
    }

    else if(ballY == (P1_PaddlePos - 1))
    { 
      ballXDir = 1;
      if(ballY == 0)    
      {
        ballYDir = 1;
      }
      else
      {
        ballYDir = -1;
      }
    }
  }

  else if((ballY == 0) || (ballY == 15))
  {
    ballYDir *= -1;
  }
    
  if(Point_Scored == 1)
  {
    ballX = Start_X;
    ballY = Start_Y;
    ballXDir *= -1;
    ballYDir = 0;

    p1.PaddlePos = 6;
    p2.PaddlePos = 6;
    
    for(uint8_t i=0; i<16; i++)
    {
      if((i==5) || (i==6) || (i==7))
      {
        p1.PaddleColArray[i] = 4;
        p2.PaddleColArray[i] = 4;
      }
      else
      {
        p1.PaddleColArray[i] = 0;
        p2.PaddleColArray[i] = 0;
      }
    }
    
    Point_Scored = 0;         
}

  uint8_t LCDCol = ballX / 5;
  uint8_t LCDRow = (ballY <= 7) ? 0 : 1;
  lcd.setCursor(LCDCol, LCDRow);
  lcd.print(" ");
  
  ballX += ballXDir;
  ballY += ballYDir;

  GenerateBallArray();

  PrintBall();
}

void Ball :: AwardAPoint()
{
  if(ballX <= 8)   
  {
    p2.Score++;
  }
    
  else              
  {
    p1.Score++;
  }
  
  
  if(p1.Score == 5)            
  {
    g.Print_Winner(Player_1);   
  }

  else if(p2.Score == 5)      
  {
    g.Print_Winner(Player_2);  
  }

  g.Print_Score();
    
  Point_Scored = 1;        
}

Ball b;


void setup()
{
  lcd.begin(16, 2);
  
  DDRD &= ~(1<<Player_1_moveUpButton);

  DDRD &= ~(1<<Player_1_moveDownButton);
  DDRD &= ~(1<<Player_2_moveUpButton);
  DDRD &= ~(1<<Player_2_moveDownButton);
  
  g.Start_Game();
  
  p1.PrintPaddles(Player_1);
  p2.PrintPaddles(Player_2);
  
  b.PrintBall();

  PCMSK2 |= (1 << PCINT21);
  PCICR |= (1 << PCIE2);

  PCMSK0 |= (1 << PCINT2);
  PCICR |= (1 << PCIE0);

  sei();
  
  attachInterrupt(digitalPinToInterrupt(Player_2_moveDownButton), P2_Move_Down, RISING);
  attachInterrupt(digitalPinToInterrupt(Player_2_moveUpButton), P2_Move_Up, RISING);
}

void loop()
{
  p1.PrintPaddles(Player_1);
  p2.PrintPaddles(Player_2);
  
  b.UpdateBall(p1.PaddlePos, p2.PaddlePos);
}

void P2_Move_Down()
{
  p2.MovePaddleDown();
}

void P2_Move_Up()
{
  p2.MovePaddleUp();
}

ISR(PCINT2_vect)
{
  if(x_Up)
  {
    p1.MovePaddleUp();
    x_Up = false;
  }
  else
  {
    x_Up = true;
  }
}

ISR(PCINT0_vect)
{
  if(x_Down)
  {
    p1.MovePaddleDown();
    x_Down = false;
  }
  else
  {
    x_Down = true;
  }
}
