/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package multiroomserver;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * La classe serve a rappresentare un Utente, identificato da un id. La classe si occuperà
 * di contenere la socket del client dell'utente e i suoi corrispettivi Stream
 * @author gabrielefedi
 */
public class User {
     
     private String name;
     private Socket  socket;
     private int  port;
     private InputStream is;
     private OutputStream os;
     private PrintWriter pw;
     private BufferedReader br;
     private int id;
     private boolean online;
     
     /**
      * Questo costruttore chiede come parametri una socket un nome e un id, che saranno rispettivamente
      * la socket del client su cui è connesso l'utente, il nome e l'id di quest'ultimo
      * @param s Socket
      * @param name Nome
      * @param id ID
      * @throws IOException 
      */
     public User(Socket s, String name, int id) throws IOException{
         socket = s;
         port = socket.getPort();
         is = socket.getInputStream();
         os = socket.getOutputStream();        
         pw = new PrintWriter(os,true);
         br= new BufferedReader(new InputStreamReader(is));
         this.name=name;
         this.id=id;
         online=true;
     }
     
     /**
      * Questo costruttore richiederà solo la socket e l'id del client dell'utente; Utile per 
      * collegare il client al server prima di conoscere il nome che l'utente vorrà
      * utilizzare
      * @param s Socket
      * @param id ID
      * @throws IOException 
      */
     public User(Socket s, int id) throws IOException{
         socket = s;
         port = socket.getPort();
         is = socket.getInputStream();
         os = socket.getOutputStream();        
         pw = new PrintWriter(os,true);
         br= new BufferedReader(new InputStreamReader(is));
         this.id=id;
         online=true;
     }
     
     /**
      * Restituisce un riferimento all'oggetto socket dell'istanza
      * @return 
      */
     public Socket getSocket(){
         return socket;
     }
     
     /**
      * Inizializza il nome dell'utente con la stringa passatogli
      * @param name 
      */
     public void  initName(String name){
         this.name=name;
     }
     
     /**
      * Restituisce l'id dell'utente
      * @return 
      */
    public int getId(){
        return id;
    }
     
    /**
      * Restituisce il nome dell'utente
      * @return 
      */
    
     public String getName(){
         return name;
     }
     
     /**
      * Restituisce un riferimento all'oggetto PrintWriter dell'istanza
      * @return 
      */
     
     public PrintWriter getPrintWriter(){
         return pw;
     }
     
     /**
      * Restituisce un riferimento all'oggetto BufferedReader dell'istanza
      * @return 
      */
     
     public BufferedReader getBufferedReader(){
         return br;
     }
     
     /**
      * Restituisce il numero di porta del Client
      * @return 
      */
     public int getPort(){
         return port;
     }
     
     /**
      * Restituisce true se l'utente è Online e false se Offline
      * @return 
      */
     
     public boolean isOnline(){
         return online;
     }
     
     /**
      * Invia un messaggio all'utente
      * @param s messaggio
      */
     public void sendMessage(String s){
         pw.println(s);
     }
     
     /**
      * Setta offline l'utente
      */
     public void setOffline(){
         online=false;
     }
}
