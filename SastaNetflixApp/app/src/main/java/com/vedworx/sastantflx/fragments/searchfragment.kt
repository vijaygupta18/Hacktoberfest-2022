package com.vedworx.sastantflx.fragments
import android.content.Intent
import android.os.Bundle
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import androidx.fragment.app.Fragment
import androidx.lifecycle.Observer
import androidx.lifecycle.ViewModelProviders
import com.vedworx.sastantflx.R
import com.vedworx.sastantflx.activities.seriesdetailed
import com.vedworx.sastantflx.adapters.searchadapter
import com.vedworx.sastantflx.interfaces.seriesclicklistener
import com.vedworx.sastantflx.models.series
import com.vedworx.sastantflx.viewmodel.seriesviewmodel
import kotlinx.android.synthetic.main.searchlayout.*
import kotlinx.android.synthetic.main.searchlayout.loaderofLanding


class searchfragment : Fragment(),
        seriesclicklistener {

    private lateinit var viewmodelsave: seriesviewmodel
    private var adapter = searchadapter()

    override fun onCreateView(
        inflater: LayoutInflater, container: ViewGroup?,
        savedInstanceState: Bundle?
    ): View? {
        val view = inflater.inflate(
            R.layout.searchlayout,
            container,
            false
        )
        viewmodelsave = ViewModelProviders.of(this).get(seriesviewmodel::class.java)

//        view.search_edittext.addTextChangedListener{
//                    if (!it.toString().isEmpty()) {
//                        viewmodelsave.fetchSeriesResults(it.toString())
//                    }
//        }

        return view

    }

    override fun onActivityCreated(savedInstanceState: Bundle?) {
        super.onActivityCreated(savedInstanceState)



        adapter.listener = this
        search_recyclerview.adapter = adapter
        viewmodelsave.serieslisiting.observe(viewLifecycleOwner, Observer {
            adapter.setSeries(it)
            loaderofLanding.visibility = View.INVISIBLE
        })

    }

    override fun onseriesitemclicked(view: View, seriesmodel: series) {
        when (view.id) {
            R.id.seasonimageview -> {
                val intent = Intent(context, seriesdetailed::class.java)
                intent.putExtra("idd", seriesmodel.id)
                intent.putExtra("name", seriesmodel.name)
                startActivity(intent)
            }
        }
    }


}