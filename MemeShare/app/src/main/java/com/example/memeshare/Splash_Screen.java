package com.example.memeshare;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.WindowManager;

public class Splash_Screen extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_splash_screen);
        getSupportActionBar().hide();
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,WindowManager.LayoutParams.FLAG_FULLSCREEN);
        Thread thread=new Thread(){
            @Override
            public void run() {
                try{
                    sleep(2000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }finally {
                    Intent intent=new Intent(Splash_Screen.this,MainActivity.class);
                    startActivity(intent);
                }
            }
        };
        thread.start();
    }
}