package com.vedworx.sastantflx.utils

import android.content.Context
import android.content.Intent
import android.view.View
import android.widget.Toast
import com.google.android.material.snackbar.Snackbar

import com.vedworx.sastantflx.activities.fragmentholder
import com.vedworx.sastantflx.auth.LoginFragment
import com.vedworx.sastantflx.ui.informationenter

fun Context.toast(message: String) {
    Toast.makeText(this, message, Toast.LENGTH_SHORT).show()
}



fun Context.login() {
    val intent = Intent(this, fragmentholder::class.java).apply {
        flags = Intent.FLAG_ACTIVITY_NEW_TASK or Intent.FLAG_ACTIVITY_CLEAR_TASK
    }
    startActivity(intent)
}

fun Context.profileEnter() {
    val intent = Intent(this, informationenter::class.java).apply {
        flags = Intent.FLAG_ACTIVITY_NEW_TASK or Intent.FLAG_ACTIVITY_CLEAR_TASK
    }
    startActivity(intent)
}

fun Context.loginFragment() {
    val intent = Intent(this, LoginFragment::class.java).apply {
        flags = Intent.FLAG_ACTIVITY_NEW_TASK or Intent.FLAG_ACTIVITY_CLEAR_TASK
    }
    startActivity(intent)
}