package logic;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Graphics2D;

public class MapGenerator {
	public int map[][];
	public int brickwidth;
	public int brickheight;
	public MapGenerator(int row,int col) {
		map = new int[row][col];
		for(int i =0; i<map.length;i++) {
			for(int j=0;j<map[0].length;j++) {
				map[i][j] = 1; 
			}
		}
		brickwidth = 500/col;
		brickheight = 150/row;
	}
	public void draw(Graphics2D g) {
		for(int i =0; i<map.length;i++) {
			for(int j=0;j<map[0].length;j++) {
				if(map[i][j] != 0) {
					g.setColor(Color.white);
					g.fillRect(j*brickwidth+80,i*brickheight+50,brickwidth,brickheight);
					
					g.setStroke(new BasicStroke(3));
					g.setColor(Color.orange);
					g.drawRect(j*brickwidth+80,i*brickheight+50,brickwidth,brickheight);
					
				}
			}
		
	     }
     }
	public void setbrick(int row,int col) {
		map[row][col] = 0;
	}
  }
