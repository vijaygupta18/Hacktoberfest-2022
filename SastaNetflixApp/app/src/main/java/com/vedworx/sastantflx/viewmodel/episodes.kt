package com.vedworx.sastantflx.viewmodel

import com.google.firebase.database.Exclude

data class episodes(
    @get:Exclude
    var id: String? = null,
    var image: String? = null,
    var name: String? = null,
    var link: String? = null
)