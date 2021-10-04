package com.vedworx.sastantflx.activities


import android.content.Intent
import android.os.Bundle
import android.view.Menu
import android.view.MenuItem
import androidx.appcompat.app.AppCompatActivity

import com.vedworx.sastantflx.R
import com.vedworx.sastantflx.adapters.fragmentholderadapter
import com.vedworx.sastantflx.fragments.animepage
import com.vedworx.sastantflx.fragments.documentarypage
import com.vedworx.sastantflx.fragments.landingPage
import com.vedworx.sastantflx.fragments.searchfragment
import com.vedworx.sastantflx.ui.profile
import kotlinx.android.synthetic.main.fragmentholder.*


class fragmentholder : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.fragmentholder)
        setSupportActionBar(toolbar)
        toolbar.title = "Sasta Netflix"
        val adapter = fragmentholderadapter(
            supportFragmentManager
        )
        adapter.addFragment(landingPage(), "Series")
        adapter.addFragment(searchfragment(), "Search")
        viewPager.adapter = adapter
        tabs.setupWithViewPager(viewPager)
    }

    override fun onCreateOptionsMenu(menu: Menu?): Boolean {
        menuInflater.inflate(R.menu.navigation, menu)
        return true
    }

 override fun onOptionsItemSelected(item: MenuItem): Boolean {
        when (item.itemId) {
            R.id.profile_navigation -> {
                val intent = Intent(this, profile::class.java)
                this.startActivity(intent)
        }

            else -> return super.onOptionsItemSelected(item)
        }
        return true
    }
}






