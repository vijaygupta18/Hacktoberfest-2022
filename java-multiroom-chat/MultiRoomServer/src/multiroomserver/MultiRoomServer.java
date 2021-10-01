/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package multiroomserver;

/**
 * 
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *Classe principale dove vengono istanziati array di "Room" "SocketListeners" e "Users"
 * in modo statico e pubblico in modo che siano facilmente accedibili da altre classi del package
 * @author gabrielefedi
 */
public class MultiRoomServer {
    
   public static ArrayList Rooms;
   public static ArrayList SocketListeners;
   public static ArrayList Users;
   public static int nClients;
   public static InitFrame initFrame;
   public static ListenerSocket ear;
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        initFrame=new InitFrame();
        initFrame.setVisible(true);
        
    }
    
    /**
     * Aggiunge una nuova stanza con nome passatogli tramite stringa
     * @param RoomName nome che assumerà la stanza aggiunta
     */
    
    public static synchronized void addNewRoom(String RoomName){
        Rooms.add(new Room(RoomName));
    }
    
    /**
     * Aggiunge un utente ad una stanza 
     * @param RoomName Nome della stanza dove sarà inserito l'utente
     * @param u Oggetto User che rappresenta l'utente da aggiungere alla stanza
     */
    
    public static synchronized void addToRoom(String RoomName,User u){
        getRoom(RoomName).addUser(u);
    }
    
    /**
     * passatogli il nome di una stanza, il metodo ritorna il riferimento alla stanza
     * con quel nome
     * @param RoomName nome stanza
     * @return 
     */
    public static Room getRoom (String RoomName){
         for(int i=0;i<Rooms.size();i++){
            if((((Room)(Rooms.get(i))).getName()).equals(RoomName)){
                return ((Room)(Rooms.get(i)));
            }           
        }
         return null;
    }
    
    /**
     * questa funzione viene richiamata ogni volta che un Client si collega al server,
     * essa aggiunge un Utene alla lista degli utenti, e fa partire un thread di ascolto 
     * per quel client
     * @param conSocket 
     */
    static synchronized void addSocket(Socket conSocket){
        try {
            Users.add(new User(conSocket,Users.size()));
            SocketListeners.add(new Transfer(Users.size()-1));
            ((Thread) SocketListeners.get(Users.size()-1)).start();
        } catch (IOException ex) {
            
        }
    }
    
    /**
     * Tramite un id il metodo setterà l'Utente associato a quell'id offline
     * @param id id dell'utente
     */
    static void setUserOffline(int id){
        for(int i=0;i<Users.size();i++){
            if(id==((User)Users.get(i)).getId()){
                ((User)Users.get(i)).setOffline();
            }
        }
    }
    
    /**
     * Tramite un id il metodo restituisce il riferimento all'Utente associato
     * a quell'id
     * @param id id Utente
     * @return 
     */
    static User getUserById(int id){
        for(int i=0;i<Users.size();i++)
            if(((User)Users.get(i)).getId()==id)
                return ((User)Users.get(i));
       return null;
    }
    
    /**
     * Tramite un nome il metodo restituirà il riferimento all'oggetto
     * Room con quel nome
     * @param name nome Stanza
     * @return 
     */
    static Room getRoomByname(String name){
        for(int i=0;i<Rooms.size();i++)
            if(((Room)Rooms.get(i)).getName().equals(name))
                return ((Room)Rooms.get(i));
       return null;
    }
    
    /**
     * Passatogli un oggetto User, il metodo ritornerà il riferimento all0oggetto Room al
     * quale appartiente quell'utente
     * @param u utente
     * @return 
     */
    
    static Room getRoomByUser(User u){
        for(int i=0;i<Rooms.size();i++){
            if(((Room)(Rooms.get(i))).inRoom(u))
                return ((Room)(Rooms.get(i)));
        }
        return null;
    }
    
    /**
     * Il metodo preparerà una stringa da inviare al client con i nomi delle Stanze
     * @return 
     */
 
    public static String getRoomsNames(){
        String str="";
        for(int i=0;i<Rooms.size();i++){
            str+=((Room)(Rooms.get(i))).getName() + "⧫";
        }
        return str;
    }
    
    /**
     * Il metodo preparerà una stringa da inviare al client con i nomi degli utenti Offline
     * @return 
     */
    
    public static String getUsersNamesOffline(){
        String str="";
        for(int i=0;i<Users.size();i++){
            if(((User)(Users.get(i))).getName()!=null && !((User)(Users.get(i))).isOnline())
               str+=((User)(Users.get(i))).getName() + "⧫";
        }
        return str;
    }
    
    /**
     * Il metodo preparerà una stringa da inviare al client con i nomi degli utenti Online
     * @return 
     */
    
    public static String getUsersNamesOnline(){
        String str="";
        for(int i=0;i<Users.size();i++){
            if(((User)(Users.get(i))).getName()!=null && ((User)(Users.get(i))).isOnline())
               str+=((User)(Users.get(i))).getName() + "⧫";
        }
        return str;
    }
    
    /**
     * Passatogli una stringa contenente un messaggio, il metodo invierà quest'ultimo a tutti i client
     * connessi al server
     * @param msg Stringa contenente il messaggio
     */
    
    public static void sendToAll(String msg){
        for(int i =0;i<Users.size();i++){
            (((User)(Users.get(i)))).sendMessage(msg);

        }
    }
    
    
}

