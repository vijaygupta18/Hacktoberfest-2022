// Read and Write an Image in Java.

import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;
 
public class ImageRead {   
    public static void main(String[] args) {   
        File file = new File("I:/input.jpg");
        BufferedImage image = null;
        try {
            image = ImageIO.read(file);
            ImageIO.write(image, "jpg", new File("I:/output.jpg"));
            // ImageIO.write(image, "png", new File("I:/output.png"));
            // ImageIO.write(image, "gif", new File("I:/output.gif"));   
            // ImageIO.write(image, "bmp", new File("I:/output.bmp"));
        } 
        catch (IOException e) {
            e.printStackTrace();
        }
       System.out.println("Done");
    }
}





// https://javaconceptoftheday.com/read-and-write-images-in-java/


