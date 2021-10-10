/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package multiroomserver;

import java.util.ArrayList;
import java.util.List;
import static multiroomserver.MultiRoomServer.Users;

/**
 *La classe implementa le funzionalità di una ChatRoom, ovvero un gruppo di utenti
 * che ricevono i messaggi solo da utenti della stessa stanza
 * @author gabrielefedi
 */
public class Room {
    
    private ArrayList Users;
    private String name;
    
    /**
     * Costruttore
     * @param name nome stanza
     */
    public Room(String name){
        Users=new ArrayList();
        this.name=name;
    }
    
    /**
     * Aggiunge un utente alla stanza
     * @param u User
     */
    public void addUser(User u){
        Users.add(u);
    }
    
    /**
     * Rimuove un utente dalla stanza con un id passato al metodo
     * @param id id utente
     */
    public void removeUser(int id){
        for(int i=0;i<Users.size();i++)
           if(((User)(Users.get(i))).getId()==id)
              Users.remove(i);
    }
    
    /**
     * Retituisce il nome della stanza
     * @return
     */
    public String getName(){
        return name;
    }
    
    /**
     * Dopo aver passato un oggetto User al metodo, esso restituisce true,
     * se questo Utente è nella stanza e false se non.
     * @param u
     * @return 
     */
    boolean inRoom(User u){
        for(int i=0;i<Users.size();i++)
            if(((((User)(Users.get(i))).getName())).equals(u.getName()))
                return true;
        return false;
    }
    
    /**
     * Il metodo restituisce una stringa in formato messaggio per Client, con i nomi
     * degli utenti presenti nella stanza
     * @return 
     */
    public String getRoomUserNames(){
        String str="";
        for(int i=0;i<Users.size();i++){
            if(((User)(Users.get(i))).getName()!=null && ((User)(Users.get(i))).isOnline())
               str+=((User)(Users.get(i))).getName() + "⧫";
        }
        return str;
    }
    
    /**
     * Stampa a video i nomi degli utenti nella stanza
     */
    
    public void printUsers(){
        for(int i=0;i<Users.size();i++)
            System.out.println(((User)(Users).get(i)).getName());
    }
    
    /**
     * Invia il messaggio passato al metodo a tutti gli utenti connessi alla ChatRoom
     * @param msg 
     */
    public void send(String msg){
        for(int i =0;i<Users.size();i++){
            (((User)(Users.get(i)))).sendMessage(msg);
        }
    }
}
