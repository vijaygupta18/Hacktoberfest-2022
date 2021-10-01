/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package multiroomserver;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * La classe implementa un ascoltatore di un client, che riceverà tutti i messaggi
 * di quest'ultimo e si comporterà di conseguenza
 * @author gabrielefedi
 */
public class Transfer extends Thread{
    String message;
    boolean life;
    BufferedReader br;
    //PrintWriter pw;
    int numberClient;
    DateFormat dateFormat;
    Calendar cal;
    /**
     * Costruttore
     * @param n numero del client (Codice identificativo)
     */
    public  Transfer(int n){
       numberClient=n;
       life=true;
       //System.out.println(MultiRoomServer.getUserById(n).getId());
       dateFormat = new SimpleDateFormat("HH:mm");
       
       br=MultiRoomServer.getUserById(n).getBufferedReader();
      
       //pw=(PrintWriter) ChatServer.PW.get(n-1);
    }
    
    /**
     * Ferma il thread
     */
    public void kill(){
        life=false;
    }
    
    /**
     * Il metodo run viene implementato in modo che stia in ascolto dei messaggi del client,
     * i quali arriveranno con una stringa di controllo che occuperà i primi tre caratteri
     * del messaggio e diranno al metodo come comportarsi
     */
    
    @Override
    public void run(){
        while(life){
            try {
                while((message=br.readLine())!=null){
                  String control=message.substring(0,3);
                  String msg=message.substring(3);
                  /*
                  ATR= Add To Room
                  STR= Send To Room
                  CNR= Create New Room
                  IUN= Init User Name
                  RTR=Remove To Room
                  RFL= Remove From List
                  ION = Initialize Online Names
                  IFN = Initialize Offline Names
                  */
                  switch(control){
                      case "ATR": 
                          
                          String username="";
                          String Room="";
                          int id = 0;
                          int i=0;
                          for(int j=0;j<msg.length();j++){
                              if(msg.charAt(j)=='⧫'){
                                  Room=msg.substring(i,j);
                                  i=j+1;    
                              }
                          }
                          id=Integer.parseInt(msg.substring(i));                      
                          User u=MultiRoomServer.getUserById(id);                        
                          Room r=(MultiRoomServer.getRoomByname(Room));
                          r.addUser(u);
                          r.send("URN"+r.getRoomUserNames());
                          r.send("MTV"+"------->"+u.getName()+" si è connesso<-------");
                      break;
                        
                      case "STR":
                          cal = Calendar.getInstance();
                          String time=dateFormat.format(cal.getTime());
                          username="";
                          String textMessage="";
                          id=0;
                          int cont=0;
                          i=0;
                          for(int j=0;j<msg.length();j++){
                              if(msg.charAt(j)=='⧫'){
                                  if(cont==0){
                                    id=Integer.parseInt(msg.substring(i,j));
                                    cont++;
                                  }
                                  else{
                                      if(cont==1){
                                          textMessage=msg.substring(i,j);
                                          cont++;
                                      }
                                  }   
                                  i=j+1;
                              }
                          }
                          u=MultiRoomServer.getUserById(id);
                          r=MultiRoomServer.getRoomByUser(u);
                          r.send("MTV"+"["+time+"] "+textMessage);
                          break;
                        
                      case "CNR":
                          MultiRoomServer.addNewRoom(msg);
                          MultiRoomServer.sendToAll("ICR"+MultiRoomServer.getRoomsNames());
                          break;
                      
                      case "IUN":
                            i=0;
                            String name="";
                            id=0;
                            for(int j=0;j<msg.length();j++){
                              if(msg.charAt(j)=='⧫'){
                                 name=(msg.substring(i,j));
                                 i=j+1;
                              }
                            }
                            id=Integer.parseInt(msg.substring(i));
                            ((User)(MultiRoomServer.getUserById(id))).initName(name);
                            MultiRoomServer.sendToAll("ION"+MultiRoomServer.getUsersNamesOnline());
                            break;
                      case "RTR":
                            id=Integer.parseInt(msg);
                            u=MultiRoomServer.getUserById(id);                           
                            r=MultiRoomServer.getRoomByUser(u);
                            r.send("MTV"+ u.getName()+ " si è disconnesso");
                            r.removeUser(id);
                            r.send("URN"+r.getRoomUserNames());
                            break;
                      case "RFL":
                          id=Integer.parseInt(msg);
                          u=MultiRoomServer.getUserById(id);
                          r=MultiRoomServer.getRoomByUser(u);
                          r.send("MTV"+"------->"+u.getName()+" si è disconnesso<-------");
                          MultiRoomServer.setUserOffline(id);
                          MultiRoomServer.sendToAll("ION"+MultiRoomServer.getUsersNamesOnline());
                          MultiRoomServer.sendToAll("IFN"+MultiRoomServer.getUsersNamesOffline());
                          
                          
                  }
                }   
            } catch (IOException ex) {
                Logger.getLogger(Transfer.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
}
    
    

