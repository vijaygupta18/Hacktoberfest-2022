package com.vedworx.sastantflx.interfaces

import android.view.View
import com.vedworx.sastantflx.models.seasons
import com.vedworx.sastantflx.models.series

interface seasonsclicklistener {
    fun onseasonitemclicked(view: View, seasonsmodel: seasons)
}
