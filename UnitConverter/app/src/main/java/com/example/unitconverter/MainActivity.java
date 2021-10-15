package com.example.unitconverter;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    private Button button;
    private TextView txtView;
    private EditText editText;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        EditText ed = (EditText) findViewById(R.id.edt1);
        TextView tv = (TextView) findViewById(R.id.txt2);
        Button bb1 = (Button) findViewById(R.id.b1);
        bb1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String s = ed.getText().toString();
                int kg = Integer.parseInt(s);
                double pound = 2.205 * kg;
                tv.setText("The corresponding value of pound is:" + pound);
            }
        });

    }
}