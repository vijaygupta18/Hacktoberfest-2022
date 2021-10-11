package com.vedworx.sastantflx.activities

import android.content.Intent
import android.os.Bundle
import android.util.Log

import android.view.View

import androidx.appcompat.app.AppCompatActivity

import androidx.lifecycle.Observer
import androidx.lifecycle.ViewModelProviders
import com.bumptech.glide.Glide
import com.google.firebase.database.FirebaseDatabase
import com.vedworx.sastantflx.R

import com.vedworx.sastantflx.adapters.seriesdetailedadapter
import com.vedworx.sastantflx.interfaces.ApiService
import com.vedworx.sastantflx.interfaces.seasonsclicklistener
import com.vedworx.sastantflx.interfaces.seriesclicklistener
import com.vedworx.sastantflx.models.Sitcom
import com.vedworx.sastantflx.models.seasons
import com.vedworx.sastantflx.models.series
import com.vedworx.sastantflx.utils.toast
import com.vedworx.sastantflx.viewmodel.seriesviewmodel
import kotlinx.android.synthetic.main.seriesdetailed.*
import retrofit2.Call
import retrofit2.Callback
import retrofit2.Response
import retrofit2.Retrofit
import retrofit2.converter.gson.GsonConverterFactory


class seriesdetailed : AppCompatActivity(),
        seasonsclicklistener {
    private var db: FirebaseDatabase? = null
    private lateinit var viewmodelsave: seriesviewmodel
    private var seasonslist = listOf<seasons>()
    private var adapter = seriesdetailedadapter(seasonslist)
    private var linkOfEpisodeFragment: String? = null


    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.seriesdetailed)
        viewmodelsave = ViewModelProviders.of(this).get(seriesviewmodel::class.java)

        val stringg = intent.getStringExtra("idd")
        val namee = intent.getStringExtra("name")

//        viewmodelsave.getSeriesDetailedRealitimeUpdates(stringg.toString())

        seriesname.text = namee

        linkOfEpisodeFragment = stringg

        val retrofit = Retrofit.Builder().baseUrl("https://api.themoviedb.org/")
                .addConverterFactory(GsonConverterFactory.create()).build()

        val api = retrofit.create(ApiService::class.java)

        api.fetchSeries(stringg).enqueue(object : Callback<Sitcom> {
            override fun onResponse(call: Call<Sitcom>, response: Response<Sitcom>) {
                val resp = response.body()

                if (resp != null) {
                    seriesummary.text = resp.overview
                    seriesrating.rating = (response.body()!!.vote_average / 2).toFloat()
                    Glide.with(this@seriesdetailed).load("https://image.tmdb.org/t/p/w342" + resp.poster_path).fitCenter().into(seriesposterpath)
                    Glide.with(this@seriesdetailed).load("https://image.tmdb.org/t/p/w780" + resp.backdrop_path).into(seriesbackdrop)
                    seasonslist = resp.seasons
                    insertdata(seasonslist)
//                    loaderseriesdetailed.stopShimmer()
//                    loaderseriesdetailed.visibility = View.INVISIBLE
                }


            }

            override fun onFailure(call: Call<Sitcom>, t: Throwable) {
            }


        })

//
//        viewmodelsave._listings.observe(this, Observer
//        {
//            adapter.addListing(it)
//        })


    }

    fun insertdata(seasonslist: List<seasons>) {
        adapter = seriesdetailedadapter(seasonslist)
        seriesdetailedrecycler.adapter = adapter
        adapter.listener = this
    }

    override fun onseasonitemclicked(view: View, seasonsmodel: seasons) {
        when (view.id) {
            R.id.seasonimageview -> {
                if (seasonsmodel.idd == null) {
                    toast(seasonsmodel.name.toString() + " is currently not present")
                } else {
                    val intent = Intent(this, episodesdetailed::class.java)
                    intent.putExtra("idd1", linkOfEpisodeFragment)
                    intent.putExtra("idd2", seasonsmodel.idd)
                    intent.putExtra("name", seasonsmodel.name)
                    startActivity(intent)
                }
            }
        }
    }
}



