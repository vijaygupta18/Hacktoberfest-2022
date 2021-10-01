/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package chatclientinterface;

import java.awt.Dimension;
import java.awt.List;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *La classe è la principale del package e istanzia staticamente gli oggetti necessari alla
 * comunicazione con il server, le liste contenenti informazioni del server, e i frame. Gli oggetti
 * sono tutti statici in modo che siano facilmente manipolabili dalle altre classe del package.
 * @author gabrielefedi
 */
public class ChatClientInterface {
    public static String name;
    public static Socket conSocket;
    public static OutputStream os;
    public static InputStream is;
    public static PrintWriter pw;
    public static BufferedReader br;
    public static Receive r;
    public static ChatInterface ChatFrame;
    public static ArrayList ChatRooms;
    public static ArrayList UsersNames;
    public static ArrayList UsersRoomNames;
    public static ArrayList UsersNamesOff;
    public static int nRooms;
    public static int nClient;
    public static Initialize InitFrame;
    public static ChoiseFrame choiseFrame;
    public static CreateRoomForm createRoomFrame;
    public static SetColorFrame setColorFrame;  
    
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {  
        
        InitFrame= new Initialize();
        InitFrame.setVisible(true);       
        UsersNames= new ArrayList();
        UsersNamesOff= new ArrayList();
        choiseFrame=new ChoiseFrame();
        ChatFrame=new ChatInterface();
        createRoomFrame= new CreateRoomForm();
        setColorFrame= new SetColorFrame();
    }
    
    /**
     * Una volta passato al metodo una stringa con il formato adatto al protocollo, esso
     * inizializzerà la lista dei nomi delle stanze con le informazioni ottenute dalla 
     * stringa passata
     * @param S Stringa contenente i nomi delle stanze del server
     */
    
    public static void initializeChatRooms(String S){
        
            int i=0;
            for(int j=0;j<S.length();j++){
                if(S.charAt(j)=='⧫'){
                    ChatRooms.add(S.substring(i,j));
                    nRooms++;
                    i=j+1;
                }
                
            }
        
    }
    
       /**
     * Una volta passato al metodo una stringa con il formato adatto al protocollo, esso
     * inizializzerà la lista dei nomi degli utenti connessi al server (Online) con le informazioni 
     * ottenute dalla stringa passata
     * @param S Stringa contenente i nomi degli utenti connessi al server (Online)
     */
        
    public static void initializeUsersNames(String S){      
            int i=0;
            for(int j=0;j<S.length();j++){
                if(S.charAt(j)=='⧫'){
                    UsersNames.add(S.substring(i,j));
                    i=j+1;
                }
                
            }        
    }

     /**
     * Una volta passato al metodo una stringa con il formato adatto al protocollo, esso
     * inizializzerà la lista dei nomi degli utenti connessi al server (Offline) con le informazioni 
     * ottenute dalla stringa passata
     * @param S Stringa contenente i nomi degli utenti connessi al server (Offline)
     */
    
    public static void initializeUsersNamesOff(String S){      
            int i=0;
            for(int j=0;j<S.length();j++){
                if(S.charAt(j)=='⧫'){
                    UsersNamesOff.add(S.substring(i,j));
                    i=j+1;
                }
                
            }        
    }
    
     /**
     * Una volta passato al metodo una stringa con il formato adatto al protocollo, esso
     * inizializzerà la lista dei nomi degli utenti  presenti nella stessa stanza 
     * dell'utente corrente, con le informazioni ottenute dalla stringa passata.
     * @param S Stringa contenente i nomi degli utenti connessi alla stessa stanza
     */
    
    public static void initializeUsersRoomNames(String S){      
            int i=0;
            for(int j=0;j<S.length();j++){
                if(S.charAt(j)=='⧫'){
                    UsersRoomNames.add(S.substring(i,j));
                    i=j+1;
                }
                
            }        
    }
    
    /**
     * Invia un messaggio al server
     * @param msg messaggio
     */
    public static void sendToServer(String msg){
        pw.println(msg);
    }
    
}

