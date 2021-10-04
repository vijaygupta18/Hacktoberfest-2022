package com.vedworx.sastantflx.interfaces

import com.vedworx.sastantflx.models.Sitcom
import retrofit2.Call
import retrofit2.http.GET
import retrofit2.http.Path

interface ApiService {

    @GET("/3/tv/{id}?api_key=eca907ec039ee65992e3aea8d14c0dd3&language=en-US")
    fun fetchSeries(@Path("id") id: String): Call<Sitcom>

}