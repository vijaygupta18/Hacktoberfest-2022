package com.vedworx.sastantflx


import android.graphics.Color
import android.os.Bundle
import android.view.View
import androidx.appcompat.app.AppCompatActivity
import tcking.github.com.giraffeplayer2.VideoView


class exoplayer : AppCompatActivity() {


    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_video_player2)

        val url=intent.getStringExtra("link")


        val videoView: VideoView = findViewById<View>(R.id.video_view) as VideoView
        videoView.setVideoPath(url).getPlayer().start()
        videoView.videoInfo.apply {
            bgColor=Color.BLACK
            setFullScreenAnimation(true)
            isFullScreenOnly=true
        }
    }




    companion object {
        const val STREAM_URL = "http://clips.vorwaerts-gmbh.de/big_buck_bunny.mp4"
    }
}