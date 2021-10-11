package com.vedworx.sastantflx.adapters

import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.recyclerview.widget.RecyclerView
import com.bumptech.glide.Glide
import com.vedworx.sastantflx.R
import com.vedworx.sastantflx.interfaces.seriesclicklistener
import com.vedworx.sastantflx.models.series
import kotlinx.android.synthetic.main.seriesview.view.*


class searchadapter :
    RecyclerView.Adapter<searchadapter.homescreenadapter>() {
    private var adapterListing = mutableListOf<series>()
    var listener: seriesclicklistener? = null

    class homescreenadapter(val view: View) : RecyclerView.ViewHolder(view)


    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int) =
        homescreenadapter(
            LayoutInflater.from(parent.context).inflate(
                R.layout.seriesview,
                parent,
                false
            )
        )

    override fun getItemCount(): Int {
        return adapterListing.size
    }

    override fun onBindViewHolder(holder: homescreenadapter, position: Int) {
        Glide.with(holder.view).load(adapterListing[position].image).centerCrop()
            .into(holder.view.seasonimageview)
        holder.view.seasonimageview.setOnClickListener {
            listener?.onseriesitemclicked(it, adapterListing[position])
        }

    }

    fun setSeries(lisiting: List<series>) {
        this.adapterListing = lisiting as MutableList<series>
        notifyDataSetChanged()
    }
}