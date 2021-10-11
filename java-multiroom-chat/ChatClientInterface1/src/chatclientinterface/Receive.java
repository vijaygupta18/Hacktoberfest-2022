/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package chatclientinterface;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * La classe implementa le funzionalità per tenere il client in ascolto ai messaggi del Server e risponderne di conseguenza. I messaggi
 * arriveranno con un formato contenente nei primi 3 caratteri un codice che informerà il client come comportarsi.
 * @author gabrielefedi
 */
public class Receive extends Thread{
    String messaggio;
    BufferedReader br;
    boolean life;
    
    /**
     * Costruttore, inizializza il BufferedReader 
     */
    Receive(){
        br=new BufferedReader(new InputStreamReader(ChatClientInterface.is));
        life=true;
    }
    
    /**
     * Si mette in ascolto di nuovi messaggi del server e si comporterà in modo diverso a seconda del codice di controllo presente a inizio messaggio.
     */
    @Override
    public void run(){
        
            try {
                while((messaggio=br.readLine())!=null){
                    //ChatClientInterface.ChatFrame.updateChat(messaggio);
                    String control=messaggio.substring(0,3);
                    String msg=messaggio.substring(3);
                    //System.out.println(messaggio);
                    /*
                    MTV= Message To View
                    ICR= Initialize Chat Rooms
                    IUN= Initialize Users Names
                    */
                    switch(control){
                        case "MTV": 
                            ChatClientInterface.ChatFrame.updateChat(msg);
                            break;
                        case "ICR":
                            ChatClientInterface.ChatRooms=new ArrayList();
                            ChatClientInterface.initializeChatRooms(msg);
                            ChatClientInterface.choiseFrame.initializeRoomsComboBox();
                            ChatClientInterface.createRoomFrame.initRoomsList();
                            break;                      
                        case "IFN":
                            ChatClientInterface.UsersNamesOff=new ArrayList();
                            ChatClientInterface.initializeUsersNamesOff(msg);
                            ChatClientInterface.choiseFrame.initializeUsersOffList();
                         break;
                         case "ION":
                            ChatClientInterface.UsersNames=new ArrayList();
                            ChatClientInterface.initializeUsersNames(msg);
                            ChatClientInterface.choiseFrame.initializeUsersList();
                            break;
                        case "INC":
                            ChatClientInterface.nClient=Integer.parseInt(msg);
                            break;
                        case "URN": 
                            System.out.println(msg);
                            ChatClientInterface.UsersRoomNames=new ArrayList();
                            ChatClientInterface.initializeUsersRoomNames(msg);
                            ChatClientInterface.ChatFrame.initializeUserNameArea();
                    }
                    
                }
            } catch (IOException ex) {
                Logger.getLogger(Receive.class.getName()).log(Level.SEVERE, null, ex);
            }
        
    }
}
