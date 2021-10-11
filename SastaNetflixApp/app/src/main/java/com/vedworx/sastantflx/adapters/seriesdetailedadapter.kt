package com.vedworx.sastantflx.adapters

import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.recyclerview.widget.RecyclerView
import com.bumptech.glide.Glide
import com.bumptech.glide.load.engine.DiskCacheStrategy
import com.bumptech.glide.load.resource.drawable.DrawableTransitionOptions
import com.bumptech.glide.request.RequestOptions
import com.vedworx.sastantflx.R
import com.vedworx.sastantflx.interfaces.seasonsclicklistener
import com.vedworx.sastantflx.interfaces.seriesclicklistener
import com.vedworx.sastantflx.models.seasons
import com.vedworx.sastantflx.models.series
import kotlinx.android.synthetic.main.seasonsview.view.*
import kotlinx.android.synthetic.main.seriesview.view.seasonimageview
import kotlin.math.acos


class seriesdetailedadapter(val seasonsList: List<seasons>) : RecyclerView.Adapter<seriesdetailedadapter.homescreenadapter>() {
    private val adapterListing = mutableListOf<series>()
    var listener: seasonsclicklistener? = null

    class homescreenadapter(val view: View) : RecyclerView.ViewHolder(view)


    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int) =
            homescreenadapter(
                    LayoutInflater.from(parent.context).inflate(
                            R.layout.seasonsview,
                            parent,
                            false
                    )
            )

    override fun getItemCount(): Int {
        return seasonsList.size
    }

    override fun onBindViewHolder(holder: homescreenadapter, position: Int) {

        val requestOptions = RequestOptions().diskCacheStrategy(DiskCacheStrategy.ALL)

        Glide.with(holder.view).load("https://image.tmdb.org/t/p/w780" + seasonsList[position].poster_path)
                .placeholder(R.drawable.gradientseriesdetailed).transition(DrawableTransitionOptions.withCrossFade())
                .apply(requestOptions)
                .into(holder.view.seasonimageview)

        for (i in 1..position) {
            seasonsList[i].idd = "s0" + i.toString()
        }
        val seasons = seasonsList[position]


        holder.view.seasonname.text = "Season " + (position)
        holder.view.seasonairingyear.text = seasons.air_date
        holder.view.seasonepisodescount.text = seasons.episode_count.toString() + " Episodes"
        holder.view.seasonsummary.text = seasons.overview
        holder.view.seasonimageview.setOnClickListener {
            listener?.onseasonitemclicked(it, seasonsList[position])
        }


    }


//    fun addListing(lisiting: series) {
//        adapterListing.add(lisiting)
//        notifyDataSetChanged()
//    }

}