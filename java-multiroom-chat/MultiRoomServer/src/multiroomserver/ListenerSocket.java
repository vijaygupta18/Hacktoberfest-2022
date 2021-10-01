/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package multiroomserver;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;


/**
 * La classe implementa le funzionalità della socket ascoltatrice del server per i nuovi client.
 * Essa, una volta collegatosi un client, richiamerà i metodi statici della classe principale,
 * per aggiungere il nuovo utente alla Lista di utenti.
 * @author gabrielefedi
 */
public class ListenerSocket extends Thread{
    boolean life;
    Socket conSocket;
    ServerSocket ss;
    int listenerPort;
    
    /**
     * Istanzia la socket ascoltatrice sulla porta passata al costruttore.
     */
    public ListenerSocket(int listenerPort){
       super("ListenerSocket");
       life=true;
       this.listenerPort=listenerPort;
        try {
            ss = new ServerSocket(listenerPort);
        } catch (IOException ex) {
            Logger.getLogger(ListenerSocket.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    /**
     * Il metodo si mette in ascolto per i nuovi client, e ogni volta che se ne collega uno
     * esso si occupa di aggiungerlo alla lista sulla classe principale, e di inviargli le 
     * informazioni del server (es Utenti connessi, Stanze ecc..)
     */
    @Override
    public void run(){
        while(life){
            try {
                //System.out.println("Connessi: "+ ChatServer.nClient + " In Attesa Client Numero "+ (ChatServer.nClient+1));
                conSocket=ss.accept();
                
                MultiRoomServer.addSocket(conSocket);
               
                //Spedisco al Client lista chat + assegno id
                PrintWriter temporary=new PrintWriter(conSocket.getOutputStream(),true);
                temporary.println("ICR"+MultiRoomServer.getRoomsNames());
                temporary.println("INC"+MultiRoomServer.nClients);
                String users;
               if(!((users=MultiRoomServer.getUsersNamesOnline()).equals("")))
                    temporary.println("ION"+MultiRoomServer.getUsersNamesOnline());              
               if(!((users=MultiRoomServer.getUsersNamesOffline()).equals("")))
                    temporary.println("IFN"+MultiRoomServer.getUsersNamesOffline());
               
                
                
                MultiRoomServer.nClients++;
            } catch (IOException ex) {
                Logger.getLogger(ListenerSocket.class.getName()).log(Level.SEVERE, null, ex);
            }
            
        }
    }
            

}