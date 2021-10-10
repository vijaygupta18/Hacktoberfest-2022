package com.vedworx.sastantflx.viewmodel

import androidx.lifecycle.LiveData
import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel
import com.google.firebase.database.*
import com.vedworx.sastantflx.models.series
import java.lang.Exception

class seriesviewmodel : ViewModel() {

    var seriesReference = FirebaseDatabase.getInstance().getReference("series")


    private val result = MutableLiveData<Exception?>()
    private val listings = MutableLiveData<series>()
    private val episodeslisiting = MutableLiveData<episodes>()
    private val _serieslisiting = MutableLiveData<List<series>>()

    val _listings: LiveData<series>
        get() = listings

    val _episodeslisiting: LiveData<episodes>
        get() = episodeslisiting

    val serieslisiting: LiveData<List<series>>
        get() = _serieslisiting


    val _result: LiveData<Exception?>
        get() = result


    fun getRealitimeUpdates() {
        seriesReference.addChildEventListener(childEventListener)
    }


    fun getSeriesDetailedRealitimeUpdates(id: String) {
        var seriesDetailedReference =
            FirebaseDatabase.getInstance().getReference("series").child(id).child("content")
        seriesDetailedReference.addChildEventListener(childEventListener)
    }


    fun getSEpisodesDetailedRealitimeUpdates(id1: String, id2: String) {
        var seriesDetailedReference =
            FirebaseDatabase.getInstance().getReference("series").child(id1).child("content")
                .child(id2).child("content")
        seriesDetailedReference.addChildEventListener(EpisodeEventListener)
    }


    private val childEventListener = object : ChildEventListener {
        override fun onCancelled(p0: DatabaseError) {
            TODO("not implemented") //To change body of created functions use File | Settings | File Templates.
        }

        override fun onChildMoved(p0: DataSnapshot, p1: String?) {
            TODO("not implemented") //To change body of created functions use File | Settings | File Templates.
        }

        override fun onChildChanged(p0: DataSnapshot, p1: String?) {
            TODO("not implemented") //To change body of created functions use File | Settings | File Templates.
        }

        override fun onChildAdded(p0: DataSnapshot, p1: String?) {
            val listing = p0.getValue(series::class.java)
            listing?.id = p0.key
            listings.value = listing
        }

        override fun onChildRemoved(p0: DataSnapshot) {
            TODO("not implemented") //To change body of created functions use File | Settings | File Templates.
        }

    }


    private val EpisodeEventListener = object : ChildEventListener {
        override fun onCancelled(p0: DatabaseError) {
            TODO("not implemented") //To change body of created functions use File | Settings | File Templates.
        }

        override fun onChildMoved(p0: DataSnapshot, p1: String?) {
            TODO("not implemented") //To change body of created functions use File | Settings | File Templates.
        }

        override fun onChildChanged(p0: DataSnapshot, p1: String?) {
            TODO("not implemented") //To change body of created functions use File | Settings | File Templates.
        }

        override fun onChildAdded(p0: DataSnapshot, p1: String?) {
            val listing = p0.getValue(episodes::class.java)
            listing?.id = p0.key
            episodeslisiting.value = listing
        }

        override fun onChildRemoved(p0: DataSnapshot) {
            TODO("not implemented") //To change body of created functions use File | Settings | File Templates.
        }
    }


    fun fetchSeries() {
        FirebaseDatabase.getInstance().getReference("series")
            .addListenerForSingleValueEvent(object :
                ValueEventListener {
                override fun onCancelled(p0: DatabaseError) {
                    TODO("not implemented") //To change body of created functions use File | Settings | File Templates.
                }

                override fun onDataChange(p0: DataSnapshot) {
                    if (p0.exists()) {
                        val serlisting = mutableListOf<series>()
                        for (datasnapShot in p0.children) {
                            val listing = datasnapShot.getValue(series::class.java)
                            listing?.id = datasnapShot.key
                            listing?.let { serlisting.add(it) }
                        }
                        _serieslisiting.value = serlisting
                    }
                }

            })
    }

    fun fetchSeriesResults(seriesName: String) {
        FirebaseDatabase.getInstance().getReference("series")
            .addListenerForSingleValueEvent(object :
                ValueEventListener {
                override fun onCancelled(p0: DatabaseError) {
                    TODO("not implemented") //To change body of created functions use File | Settings | File Templates.
                }

                override fun onDataChange(p0: DataSnapshot) {
                    if (p0.exists()) {
                        val serlisting = mutableListOf<series>()
                        for (datasnapShot in p0.children) {
                        if (datasnapShot.child("name").getValue().toString().contains(seriesName)) {
                                val listing = datasnapShot.getValue(series::class.java)
                                listing?.id = datasnapShot.key
                                listing?.let { serlisting.add(it) }
                            }
                      }
                        _serieslisiting.value = serlisting

                    }
                }

            })
    }


    override fun onCleared() {
        super.onCleared()
        seriesReference.removeEventListener(childEventListener)
    }


}

