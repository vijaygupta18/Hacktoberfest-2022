package com.vedworx.sastantflx.models

import com.google.firebase.database.Exclude


data class seasons(
        @Exclude
        var id: Int? = null,
        var name: String? = null,
        var poster_path: String? = null,
        val overview: String? = null,
        val episode_count: Int? = null,
        val air_date: String? = null,
        var idd: String? = null
)