package com.example.notesop;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.inputmethod.InputMethodManager;
import android.widget.EditText;

import java.io.IOException;

public class EnterText extends AppCompatActivity {
    EditText editText;
    SharedPreferences sharedPreferences;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_enter_text);
        sharedPreferences = getApplicationContext().getSharedPreferences("com.example.notesop", Context.MODE_PRIVATE);
        editText = findViewById(R.id.editText);

        Intent intent = getIntent();
        int pos=intent.getIntExtra("pos",-1);
        if(pos!=-1){
            editText.setText(MainActivity.notesList.get(pos));
            editText.setSelection(editText.getText().length());
            InputMethodManager imm = (InputMethodManager) getSystemService(Context.INPUT_METHOD_SERVICE);
            imm.toggleSoftInput(InputMethodManager.SHOW_FORCED,0);
        }
        editText.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {

            }

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {
                MainActivity.notesList.set(pos,String.valueOf(s));
                try {
                    sharedPreferences.edit().putString("notesList",ObjectSerializer.serialize(MainActivity.notesList)).apply();
                } catch (Exception e) {
                    e.printStackTrace();
                }
                MainActivity.myAdapter.notifyDataSetChanged();
            }

            @Override
            public void afterTextChanged(Editable s) {

            }
        });

    }
}