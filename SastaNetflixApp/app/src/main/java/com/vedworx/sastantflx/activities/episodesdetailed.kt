package com.vedworx.sastantflx.activities


import android.content.Intent
import android.os.Bundle
import android.view.View
import androidx.appcompat.app.AppCompatActivity
import androidx.lifecycle.Observer
import androidx.lifecycle.ViewModelProviders

import com.vedworx.sastantflx.R
import com.vedworx.sastantflx.exoplayer
import com.vedworx.sastantflx.adapters.episodedetailedadapter
import com.vedworx.sastantflx.interfaces.episodelistener
import com.vedworx.sastantflx.viewmodel.episodes
import com.vedworx.sastantflx.viewmodel.seriesviewmodel
import kotlinx.android.synthetic.main.episodesdetailed.*

class episodesdetailed : AppCompatActivity(), episodelistener {

    private lateinit var viewmodelsave: seriesviewmodel
    private var adapter =
        episodedetailedadapter()


    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        viewmodelsave = ViewModelProviders.of(this).get(seriesviewmodel::class.java)
        setContentView(R.layout.episodesdetailed)

        val stringg1 = intent.getStringExtra("idd1")
        val stringg2 = intent.getStringExtra("idd2")
        val namee = intent.getStringExtra("name")
        viewmodelsave.getSEpisodesDetailedRealitimeUpdates(stringg1.toString(), stringg2.toString())
        seriesseason.text = namee
        adapter.listener = this
        episodesdetailed.adapter = adapter
        viewmodelsave._episodeslisiting.observe(this, Observer {
            adapter.addListing(it)
            loader.visibility = View.INVISIBLE
        })

    }

    override fun onepisodeitemclicked(view: View, episodesmodel: episodes) {
        when (view.id) {
            R.id.episodename -> {
                val intent = Intent(this, exoplayer::class.java)
                intent.putExtra("link", episodesmodel.link.toString())
                startActivity(intent)
            }
        }
    }

}
