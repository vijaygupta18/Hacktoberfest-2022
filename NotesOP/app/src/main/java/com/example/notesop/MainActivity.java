package com.example.notesop;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

import java.io.IOException;
import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    ListView myList;
    static ArrayList<String> notesList = new ArrayList<String>();;
    static ArrayAdapter<String> myAdapter;
    SharedPreferences sharedPreferences;

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        MenuInflater menuInflater = getMenuInflater();
        menuInflater.inflate(R.menu.main_menu,menu);
        return super.onCreateOptionsMenu(menu);
    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        super.onOptionsItemSelected(item);
        switch(item.getItemId()){
            case R.id.newNote:
                notesList.add("");
                int check = notesList.size()-1;
                Intent intent = new Intent(getApplicationContext(),EnterText.class);
                intent.putExtra("pos",check);
                startActivity(intent);
                return true;
            default:
                return false;
        }

    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
       sharedPreferences = this.getSharedPreferences("com.example.notesop", Context.MODE_PRIVATE);

        myList = findViewById(R.id.myList);
        try {
            notesList = (ArrayList<String>) ObjectSerializer.deserialize(sharedPreferences.getString("notesList",ObjectSerializer.serialize(new ArrayList<String>())));
        } catch (Exception e) {
            e.printStackTrace();
        }
        myAdapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1,notesList);
        myList.setAdapter(myAdapter);

        myList.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Intent intent = new Intent(getApplicationContext(),EnterText.class);
                intent.putExtra("pos",position);
                startActivity(intent);
            }
        });
        myList.setOnItemLongClickListener(new AdapterView.OnItemLongClickListener() {
            @Override
            public boolean onItemLongClick(AdapterView<?> parent, View view, int position, long id) {
               final AlertDialog.Builder b = new AlertDialog.Builder(MainActivity.this);
                       b.setIcon(android.R.drawable.ic_dialog_alert);
                               b.setMessage("Do u really wanna delete this Note");
                               b.setTitle("Delete Alert");
                               b.setPositiveButton("Yes", new DialogInterface.OnClickListener() {
                                   @Override
                                   public void onClick(DialogInterface dialog, int which) {
                                       notesList.remove(position);
                                       myAdapter.notifyDataSetChanged();

                                       try{
                                           sharedPreferences.edit().putString("notesList",ObjectSerializer.serialize(notesList)).apply();

                                       }
                                       catch(Exception e){
                                           e.printStackTrace();
                                       }
                                   }
                               });
                               b.setNegativeButton("No",null);
                               b.show();

                return true;
            }
        });
    }
}