package com.vedworx.sastantflx.auth

import android.content.Intent
import android.os.Bundle
import android.util.Patterns
import androidx.appcompat.app.AppCompatActivity
import com.google.firebase.auth.FirebaseAuth
import com.vedworx.sastantflx.R
import com.vedworx.sastantflx.ui.informationenter
import com.vedworx.sastantflx.utils.login
import com.vedworx.sastantflx.utils.toast
import kotlinx.android.synthetic.main.registerlayout.*


class SignupFragment : AppCompatActivity() {

    private lateinit var mAuth: FirebaseAuth

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.registerlayout)

        mAuth = FirebaseAuth.getInstance()





        button_register.setOnClickListener {
            val email = text_email.text.toString().trim()
            val password = edit_text_password.text.toString().trim()
            if (email.isEmpty()) {
                text_email.error = "Email Required"
                text_email.requestFocus()
                return@setOnClickListener
            }
            if (password.isEmpty()) {
                edit_text_password.error = "Email Required"
                edit_text_password.requestFocus()
                return@setOnClickListener
            }
            if (!Patterns.EMAIL_ADDRESS.matcher(email).matches()) {
                text_email.error = "Enter a valid email"
                text_email.requestFocus()
                return@setOnClickListener
            }
            if (password.length < 6) {
                edit_text_password.error = "Min 6 digit password required"
                edit_text_password.requestFocus()
                return@setOnClickListener
            }
            registerUser(email, password)

        }


    }

    private fun registerUser(email: String, password: String) {
        mAuth.createUserWithEmailAndPassword(email, password).addOnCompleteListener(this) { task ->
            if (task.isSuccessful) {
                val intent = Intent(this, informationenter::class.java).apply {
                    flags = Intent.FLAG_ACTIVITY_NEW_TASK or Intent.FLAG_ACTIVITY_CLEAR_TASK
                }
                startActivity(intent)
            } else {
                toast("Error Occured")
            }
        }
    }

    override fun onStart() {
        super.onStart()
        mAuth.currentUser?.let {
            login()
        }
    }
}