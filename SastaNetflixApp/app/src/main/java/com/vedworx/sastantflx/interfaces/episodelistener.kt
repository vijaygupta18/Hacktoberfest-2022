package com.vedworx.sastantflx.interfaces

import android.view.View
import com.vedworx.sastantflx.viewmodel.episodes

interface episodelistener {
    fun onepisodeitemclicked(view: View, episodesmodel: episodes)
}