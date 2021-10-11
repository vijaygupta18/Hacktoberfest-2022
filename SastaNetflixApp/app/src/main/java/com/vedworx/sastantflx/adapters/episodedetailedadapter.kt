package com.vedworx.sastantflx.adapters


import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.recyclerview.widget.RecyclerView
import com.bumptech.glide.Glide
import com.vedworx.sastantflx.R
import com.vedworx.sastantflx.interfaces.episodelistener
import com.vedworx.sastantflx.viewmodel.episodes
import kotlinx.android.synthetic.main.episodelayout.view.*
import kotlinx.android.synthetic.main.episodesdetailed.view.*
import kotlinx.android.synthetic.main.seriesview.view.*


class episodedetailedadapter : RecyclerView.Adapter<episodedetailedadapter.homescreenadapter>() {
    private val adapterListing = mutableListOf<episodes>()
    var listener: episodelistener? = null

    class homescreenadapter(val view: View) : RecyclerView.ViewHolder(view)


    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int) =
        homescreenadapter(
            LayoutInflater.from(parent.context).inflate(
                R.layout.episodelayout,
                parent,
                false
            )
        )

    override fun getItemCount(): Int {
        return adapterListing.size
    }

    override fun onBindViewHolder(holder: homescreenadapter, position: Int) {
        holder.view.episodename.text = "Episode" + (position+1).toString()

        holder.view.episodename.setOnClickListener {
            listener?.onepisodeitemclicked(it, adapterListing[position])
        }

    }

    fun addListing(lisiting: episodes) {
        adapterListing.add(lisiting)
        notifyDataSetChanged()
    }
}