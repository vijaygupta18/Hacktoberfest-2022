package com.vedworx.sastantflx.ui

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import com.google.firebase.auth.FirebaseAuth
import com.google.firebase.database.DataSnapshot
import com.google.firebase.database.DatabaseError
import com.google.firebase.database.FirebaseDatabase
import com.google.firebase.database.ValueEventListener
import com.vedworx.sastantflx.R
import com.vedworx.sastantflx.utils.loginFragment

import kotlinx.android.synthetic.main.profile.*

class profile : AppCompatActivity() {

    private lateinit var db: FirebaseDatabase
    private lateinit var auth: FirebaseAuth
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.profile)



        db = FirebaseDatabase.getInstance()
        auth = FirebaseAuth.getInstance()
        db.getReference("users").child(auth.uid.toString())
            .addListenerForSingleValueEvent(object :
                ValueEventListener {
                override fun onCancelled(p0: DatabaseError) {
                    TODO("not implemented") //To change body of created functions use File | Settings | File Templates.
                }

                override fun onDataChange(p0: DataSnapshot) {
                var  profileName = p0.child("name").value.toString()
                 nameofUser.text = profileName
                }

            })



        logoutButton.setOnClickListener {
            auth.signOut()
            loginFragment()
        }
    }
}