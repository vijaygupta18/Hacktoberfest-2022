package com.vedworx.sastantflx.interfaces

import android.view.View
import com.vedworx.sastantflx.models.series

interface seriesclicklistener {
    fun onseriesitemclicked(view: View, seriesmodel: series)
}
