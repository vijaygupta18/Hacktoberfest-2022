package logic;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Rectangle;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import javax.swing.JPanel;
import javax.swing.Timer;

public class Play extends JPanel implements KeyListener, ActionListener {
    private boolean playing = false;
    private int score = 0;
    private int totalBricks = 21;
    private Timer timer;
    private int delay = 8;
    private int playerx = 310;
    private int ballx = 120;
    private int bally = 350;
    private int ballxdir = -1;
    private int ballydir = -2; 
    private MapGenerator map1;
    
    public Play() {
    	addKeyListener(this);
    	setFocusable(true);
    	setFocusTraversalKeysEnabled(false);
    	timer = new Timer(delay,this);
    	map1 = new MapGenerator(3,7);
    	timer.start();  	 	
    }
    public void paint(Graphics g) {
    	//background
    	g.setColor(Color.orange);
    	g.fillRect(1, 1, 692, 592);
    	
    	 //bricks
    	map1.draw((Graphics2D)g);
    	
    	//borders
    	g.setColor(Color.black);
    	g.fillRect(0,0,10,592);
    	g.fillRect(0,0,692,10);
    	g.fillRect(674,0,10,592);
    	
    	//paddle
        g.setColor(Color.white);
        //g.fillRect(playerx,550,150,20);
        g.fillRoundRect(playerx, 550, 150,20,10,10);
        
    	//ball
        g.setColor(Color.black);
        g.fillOval(ballx,bally,20,20);
        
        //score
        g.setColor(Color.black);
        g.setFont(new Font("serif",Font.BOLD,25));
        g.drawString("Score : "+score,560,40);
        
        if(bally>570) {
        	playing = false;
        	ballxdir = ballydir =0;
        	g.setColor(Color.black);
            g.setFont(new Font("serif",Font.BOLD,25));
            g.drawString("Game Over!",250,300);
            g.drawString("Score : "+score,260,350);
            g.drawString("Press Enter to replay ",200,400);
        }
        if(totalBricks == 0) {
        	playing = false;
        	ballxdir = ballydir =0;
        	g.setColor(Color.black);
            g.setFont(new Font("serif",Font.BOLD,25));
            g.drawString("You Won!",250,300);
            g.drawString("Score : "+score,260,350);
            g.drawString("Press Enter to replay ",200,400);
        }
        g.dispose();
    }
    
	@Override
	public void actionPerformed(ActionEvent e) {
		timer.start();
		if(playing) {
			if(new Rectangle(ballx,bally,20,20).intersects(new Rectangle(playerx,550,150,20))) {
				ballydir = -ballydir;
			}
			A:for(int i=0;i<map1.map.length;i++) {
				for(int j=0 ; j< map1.map[0].length;j++) {
					if(map1.map[i][j]!=0) {
						int brickx = j*map1.brickwidth + 80;
						int bricky = i*map1.brickheight + 50;
						int brickw = map1.brickwidth;
						int brickh = map1.brickheight;
						Rectangle rect = new Rectangle(brickx,bricky,brickw,brickh);
						Rectangle ball = new Rectangle(ballx,bally,20,20);
						if(ball.intersects(rect)) {
							map1.setbrick(i,j);
							totalBricks--;
							score++;
							if(ballx+19 <= rect.x || ballx + 1 >= rect.x + rect.width ) {
								ballxdir = - ballxdir;
							}
							else {
								ballydir = -ballydir;
							}
							break A;
						}
					}
				}
			}
			ballx+= ballxdir;
			bally+= ballydir;
			if(ballx<0) {
				ballxdir = -ballxdir;
			}
			if(bally<0) {
				ballydir = -ballydir;
			}
			if(ballx>670) {
				ballxdir = -ballxdir;
			}
		}
		repaint();
		
	}

	@Override
	public void keyPressed(KeyEvent e) {
	   if(e.getKeyCode() == KeyEvent.VK_RIGHT) {
		   if(playerx >= 524) {
			   playerx = 524;
		   }
		   else {
			   moveRight();
		   }
		   
	   }
       if(e.getKeyCode() == KeyEvent.VK_LEFT) {
		   if(playerx < 10) {
			   playerx = 10;
		   }
		   else {
			   moveLeft();
		   }
	   }
       if(e.getKeyCode() == KeyEvent.VK_ENTER) {
    	   if(!playing) {
    		   playing = true;
    		   ballx = 120;
    		   bally = 350;
    		   ballxdir = -1;
    		   ballydir = -2;
    		   playerx = 310;
    		   score = 0;
    		   totalBricks = 21;
    		   map1 = new MapGenerator(3,7);
    		   repaint();
    	   }
       }
		
	}
	public void moveRight() {
		playing = true;
		playerx+= 20;
	}
	public void moveLeft() {
		playing = true;
		playerx-= 20;
	}
	@Override
	public void keyReleased(KeyEvent e) {}
	@Override
	public void keyTyped(KeyEvent e) {}

}
