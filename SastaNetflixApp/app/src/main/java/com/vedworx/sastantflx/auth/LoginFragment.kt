package com.vedworx.sastantflx.auth

import android.content.Intent
import android.os.Bundle
import android.util.Patterns
import androidx.appcompat.app.AppCompatActivity

import com.google.firebase.auth.FirebaseAuth

import com.vedworx.sastantflx.R
import com.vedworx.sastantflx.utils.login
import com.vedworx.sastantflx.utils.toast
import kotlinx.android.synthetic.main.loginlayout.*


class LoginFragment : AppCompatActivity() {
    private lateinit var mAuthLogin: FirebaseAuth
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.loginlayout)

        mAuthLogin = FirebaseAuth.getInstance()


        text_view_register.setOnClickListener {
            val intent = Intent(this, SignupFragment::class.java)
            startActivity(intent)
        }

        button_sign_in.setOnClickListener {
            val email = text_email_login.text.toString().trim()
            val password = edit_text_password_login.text.toString().trim()
            if (email.isEmpty()) {
                text_email_login.error = "Email Required"
                text_email_login.requestFocus()
                return@setOnClickListener
            }
            if (password.isEmpty()) {
                edit_text_password_login.error = "Email Required"
                edit_text_password_login.requestFocus()
                return@setOnClickListener
            }
            if (!Patterns.EMAIL_ADDRESS.matcher(email).matches()) {
                text_email_login.error = "Enter a valid email"
                text_email_login.requestFocus()
                return@setOnClickListener
            }
            if (password.length < 6) {
                edit_text_password_login.error = "Min 6 digit password required"
                edit_text_password_login.requestFocus()
                return@setOnClickListener
            }
            loginUser(email, password)

        }


    }

    private fun loginUser(email: String, password: String) {
        //Insert Animation here it will run and then activity will switch means the animation doesn't need to be interefered just need to be run nahi we need to chnage its visible properties
        mAuthLogin.signInWithEmailAndPassword(email, password).addOnCompleteListener(this) { task ->
            if (task.isSuccessful) {
                login()
            } else {
                toast("Error Occured")
            }
        }
    }


    override fun onStart() {
        super.onStart()
        mAuthLogin.currentUser?.let {
            login()
        }
    }
}



