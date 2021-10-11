<template>
  <v-app>
    <v-navigation-drawer
      v-model="drawer"
      color="black"
      dark
      app
      >
      <v-list dense>
        <v-list-item>
           <v-switch
              v-model="activeMyLocationLayer"
              label="My Location"
              color="blue darken-1"
              v-on:click="triggerMyLocationLayer();addMyLocationLocations()"
              hide-details
            ></v-switch>
        </v-list-item>
        <v-list-item>
           <v-switch
              v-model="activeDebrisLayer"
              label="Debris"
              color="blue draken-1"
              v-on:click="triggerDebrisLayer()"
              hide-details
            ></v-switch>
        </v-list-item>
        <v-list-item></v-list-item>
        <v-divider></v-divider>
        <v-list-item></v-list-item>
        <v-list-item>
          <v-btn-toggle
            tile
            group
            >
  
          </v-btn-toggle>
        </v-list-item>
      </v-list>
    </v-navigation-drawer>

    <v-app-bar app color="black" dark>
      <v-app-bar-nav-icon @click.stop="drawer = !drawer"></v-app-bar-nav-icon>
      <div class="d-flex align-center">
        <a
          href="https://github.com/sudhanshupatel-dev/Debris-Tracking"
        >
        <v-img
          alt="Manji Logo"
          class="shrink mr-2"
          contain
          src="@/assets/Manji logo.png"
          transition="scale-transition"
          width="160"
        />

        </a>
      </div>

      <v-spacer></v-spacer>

        <a
          href="https://worldwind.arc.nasa.gov/"
        >
        <v-img
          alt="NASA Logo"
          class="shrink mr-2 nasa-logo"
          contain
          src="@/assets/1200px-NASA_logo.png"
          transition="scale-transition"
          width="70"
        />
        </a>
        <div>NASA WorldWind </div>
    </v-app-bar>

    <v-main>
          <div id="app">
        <p>Latitude = {{ lat }} Longitude = {{ lon }}</p>

        <v-flex class = "mt-4 mb-3">
                  <v-btn v-on:click="NearestDebris();nullIncrease()">Nearest Debris</v-btn>   
        </v-flex>
        <p>Nearest Debris: Latitude = {{nearlat}} Longitude = {{nearlon}}</p>
        <p>Click on 1. "Debris" toggle 2. "Nearest Debris" button 3. "My location" toggle | (Only for demo simulation)</p>
        <p>{{ error }}</p>
      </div>
       <v-dialog
      dark
      v-model="showEditAnnotationDialog"
      max-width="290"
    >
      <v-card>
        <v-card-title class="headline">Edit Marker</v-card-title>

          <v-text-field
          v-model="annotationText"
          value="Edit Annotation Text"
          class="pl-6 pr-12"
        ></v-text-field>

        <v-card-actions>
          <v-spacer></v-spacer>
          <v-btn
            color="blue darken-1"
            text
            @click="pickedObject.text = annotationText; showEditAnnotationDialog = false; wwd.redraw()"
          >
            Submit
          </v-btn>
          <v-btn
            color="blue darken-1"
            text
            @click="showEditAnnotationDialog = false"
          >
            Cancel
          </v-btn>
        </v-card-actions>
      </v-card>
    </v-dialog>
      <v-container class="flex-grow-1">
        <canvas id="canvasOne" class="flex-grow-1">
          Your browser does not support HTML5 Canvas.
        </canvas>
      </v-container>
    </v-main>
  </v-app>
</template>

<script>
import WorldWind from "@nasaworldwind/worldwind";
import DebrisLocationsJson from "../target.json";



export default {    
  name: "WorldWiind",

  data: () => ({
    lat:'',
    lon:'',
    nearlat:'',
    nearlon:'',
    count: null,
    drawer: null,
    wwd: null,
    DebrisLocationsPlacemarkLayer: null,
    MyLocationLocationsPlacemarkLayer: null,
    userPlacemarkLayer: null,
    activeDebrisLayer: true,
    activeMyLocationLayer: true,
    canPlaceMarker: false, // If set to true, click on wwd will add placemarker
    canMoveMarker: false,
    showEditAnnotationDialog: false,
    pickedObject: null, // Store a reference to the last pickedObject
    annotationText: "",
    customMarkerCounter: 0,
    objectToMove: null
  }),

  methods: {
  myFunction: function () {
   if(navigator.geolocation){
   navigator.geolocation.getCurrentPosition(this.showPosition);
   }else{
   this.error = "Geolocation is not supported.";

    }
    },
  nullIncrease: function (){
  if (this.count != null){
  this.addMyLocationLocations()
  }
  },
  showPosition:function (position) {
    this.lat = position.coords.latitude;
    this.lon = position.coords.longitude;
    console.log(this.lat,this.lon);
    },

    NearestDebris (){
        var LAT = this.lat;
    var LON = this.lon;
    var R = 6371;
    var minimum = 10000000000;
    var arr = new Array(2);
      DebrisLocationsJson.forEach(function(store) {
      var dLat = (store.["lat"]-LAT) * Math.PI / 180;
      var dLon = (store.["lng"]-LON) * Math.PI / 180; 
      var dlat1 = (LAT) * Math.PI / 180;
      var dlat2 = (store.["lat"]) * Math.PI / 180;
      var a = Math.sin(dLat/2) * Math.sin(dLat/2) +
        Math.sin(dLon/2) * Math.sin(dLon/2) * Math.cos(dlat1) * Math.cos(dlat2); 
      var c = 2 * Math.atan2(Math.sqrt(a), Math.sqrt(1-a)); 
      var d = R * c;
        if (Math.abs(d) < minimum){
        minimum = d;
        arr[0] = store.["lat"];
        arr[1] = store.["lng"];
        }
      });
      this.nearlat = arr[0];
      this.nearlon = arr[1];
        console.log(this.nearlat);
    },
    triggerMyLocationLayer () {
    this.myFunction();
      //this.addMyLocationLocations()
      this.MyLocationLocationsPlacemarkLayer.enabled = !this.MyLocationLocationsPlacemarkLayer.enabled;
      this.wwd.redraw();
      this.activeMyLocationLayer = this.MyLocationLocationsPlacemarkLayer.enabled;
      
    },

    triggerDebrisLayer () {
      
      this.DebrisLocationsPlacemarkLayer.enabled = !this.DebrisLocationsPlacemarkLayer.enabled;
      this.wwd.redraw();
      this.activeDebrisLayer = this.DebrisLocationsPlacemarkLayer.enabled;
      this.$forceUpdate();
    },

    setAnnotationAttributes () {
       // Set default annotation attributes.
        const annotationAttributes = new WorldWind.AnnotationAttributes(null);
        annotationAttributes.cornerRadius = 14;
        annotationAttributes.backgroundColor = WorldWind.Color.MEDIUM_GRAY;
        annotationAttributes.drawLeader = true;
        annotationAttributes.leaderGapWidth = 40;
        annotationAttributes.leaderGapHeight = 30;
        annotationAttributes.opacity = 1;
        annotationAttributes.scale = 1;
        annotationAttributes.width = 150;
        annotationAttributes.height = 100;
        annotationAttributes.textAttributes.color = WorldWind.Color.BLACK;
        annotationAttributes.insets = new WorldWind.Insets(10, 10, 10, 10);

        return annotationAttributes;
    },

    defineLocationPlacemarkAttributes (store) {
      const placemarkAttributes = new WorldWind.PlacemarkAttributes(null);

      placemarkAttributes.imageOffset = new WorldWind.Offset(
        WorldWind.OFFSET_FRACTION, 0.3,
        WorldWind.OFFSET_FRACTION, 0.0);

      if (store === "Debris") {
        placemarkAttributes.labelAttributes.color = WorldWind.Color.RED;
        placemarkAttributes.imageSource = "https://i.ibb.co/TL4Zhjd/debris-2.png"
        //placemarkAttributes.imageSource = WorldWind.WWUtil.currentUrlSansFilePart() + "./assets/pushpins/plain-red.png"
      } else if (store === "MyLocation") {
        placemarkAttributes.labelAttributes.color = WorldWind.Color.BLUE;
        placemarkAttributes.imageSource = "https://files.worldwind.arc.nasa.gov/artifactory/web/0.9.0/images/pushpins/plain-blue.png"
      } else if (store === "NearestDebris") {
        placemarkAttributes.labelAttributes.color = WorldWind.Color.BLUE;
        placemarkAttributes.imageSource = "https://i.ibb.co/NWBsgwW/debris-2-1.png"
      }
      else if (store === "user") {
        placemarkAttributes.labelAttributes.color = WorldWind.Color.WHITE;
      }

      placemarkAttributes.labelAttributes.offset = new WorldWind.Offset(
        WorldWind.OFFSET_FRACTION, 0.5,
        WorldWind.OFFSET_FRACTION, 1.0);

      placemarkAttributes.imageScale = .4; //Fixme

      return placemarkAttributes;
    },

    addDebrisLocations () {
      let placemarkAttributes = this.defineLocationPlacemarkAttributes("Debris")
      let self = this;
      DebrisLocationsJson.forEach(function(store) {
        var position = new WorldWind.Position(store.["lat"], store["lng"], 500000.0);
        var placemark = new WorldWind.Placemark(position, false, placemarkAttributes);
        placemark.alwaysOnTop = true;
        self.DebrisLocationsPlacemarkLayer.addRenderable(placemark);
      });

    },


    addMyLocationLocations () {
      const placemarkAttributes = this.defineLocationPlacemarkAttributes("MyLocation")
      const self = this;
      
      //console.log(this.lat); work on this, mounted issue
      var position = new WorldWind.Position(this.lat,this.lon,100.0);
      var position2 = new WorldWind.Position(this.nearlat,this.nearlon,500500.0);
      var placemark = new WorldWind.Placemark(position,false,placemarkAttributes);
      placemark.alwaysOnTop = true;
      //console.log(this.nearlat);    
      self.MyLocationLocationsPlacemarkLayer.addRenderable(placemark);
      if (this.nearlat != null){
      var placemark2 = new WorldWind.Placemark(position2,false,this.defineLocationPlacemarkAttributes("NearestDebris"));
      placemark.alwaysOnTop = true;
      self.MyLocationLocationsPlacemarkLayer.addRenderable(placemark2);
      }
      this.count++;
    }
  },
  

  mounted () {
    // Add Layers
    this.wwd = new WorldWind.WorldWindow("canvasOne");
    //this.wwd.addLayer(new WorldWind.BMNGOneImageLayer());
    this.wwd.addLayer(new WorldWind.BMNGLandsatLayer());

    //Debris Stores Placemark Layer
    this.DebrisLocationsPlacemarkLayer = new WorldWind.RenderableLayer();
    this.wwd.addLayer(this.DebrisLocationsPlacemarkLayer);
    this.triggerDebrisLayer(); // start with layer off

    //MyLocation Stores Placemark Layer
    this.MyLocationLocationsPlacemarkLayer = new WorldWind.RenderableLayer();
    this.wwd.addLayer(this.MyLocationLocationsPlacemarkLayer);
    this.triggerMyLocationLayer(); // start with layer off

    //this.NearestDebrisPlacemarkLayer = new WorldWind.RenderableLayer();
    //this.wwd.addLayer(this.NearestDebrisPlacemarkLayer);
    

    //User Placemark Layer
    this.userPlacemarkLayer = new WorldWind.RenderableLayer();
    this.wwd.addLayer(this.userPlacemarkLayer);



    this.addDebrisLocations();
    //this.addMyLocationLocations();
    this.NearestDebris();
    // Set mouse event listener to handle dynamic user placemarks
    // Borrowed from GoToLocation.js -> https://github.com/NASAWorldWind/WebWorldWind/blob/develop/examples/GoToLocation.js
    const self = this;
    new WorldWind.ClickRecognizer(this.wwd, function(e) {
      // Obtain the event location.
      const x = e.clientX,
        y = e.clientY;

      if (self.canMoveMarker && !self.canPlaceMarker) {
        const pickList = self.wwd.pick(self.wwd.canvasCoordinates(x, y));

        if (!self.objectToMove) { // pick up object on first click
          if (!pickList.hasNonTerrainObjects()) return;
          self.objectToMove = pickList.topPickedObject().userObject;

        // If only one thing is picked and it is the terrain, change the object location to that terrain position
        } else if (pickList.objects.length === 1 && pickList.objects[0].isTerrain && self.objectToMove) {
          self.objectToMove.position = pickList.objects[0].position;
          self.objectToMove = null; // reset objectToMove
          self.wwd.redraw()
        }
      }

      // Place custom annotation marker on map
      if (self.canPlaceMarker && !self.canMoveMarker) {
        // Perform the pick. Must first convert from window coordinates to canvas coordinates, which are
        // relative to the upper left corner of the canvas rather than the upper left corner of the page.
        const pickList = self.wwd.pick(self.wwd.canvasCoordinates(x, y));

        // If only one thing is picked and it is the terrain, tell the WorldWindow to go to the picked location.
        if (pickList.objects.length === 1 && pickList.objects[0].isTerrain) {
          const position = pickList.objects[0].position;

          const annotationAttributes = self.setAnnotationAttributes();
          const annotation = new WorldWind.Annotation(position, annotationAttributes);
          annotation.displayName = "My Placemark";
          annotation.text = "Marker " + self.customMarkerCounter++;
          self.userPlacemarkLayer.addRenderable(annotation);
          self.wwd.redraw()
        }
      }

      // Edit custom annotation marker
      if (!self.canPlaceMarker && !self.canMoveMarker) {
        // see what the user is picking
        var pickList = self.wwd.pick(self.wwd.canvasCoordinates(x, y));
        if (!pickList.hasNonTerrainObjects()) return;
        const topPickedObject = pickList.topPickedObject().userObject;
        if (topPickedObject.text !== undefined) {  //FIXME: hacky solution to ignore placemarkers
          self.showEditAnnotationDialog = true;
          self.pickedObject = topPickedObject;
          self.annotationText = topPickedObject.text;
        }
      }

    });
  }
};
</script>
<style scoped>
/* Avoid overlap of nav drawer and app-bar.  Source: https://codepen.io/hamedbaatour/pen/gOpwwjJ */
header {
  postion: absolute !important;
  top: 0 !important;
  left: 0 !important;
  z-index: 99999 !important;
}

nav, main{
  margin-top: 4rem !important;
}

main {
  padding: 2rem;
}

div.container {
  postion: absolute !important;
  height: 100%;
  width: 100%;
  margin: 0px 0px 0px 0px !important;
  padding: 0px 0px 0px 0px !important;
  max-width: none !important;
}

#canvasOne {
  position: absolute;
  background-color: black;
  width: 100%;
  max-height: 100%;
  min-height: 100%;
}

#app {
  background-color:black; 
  color:white;
  box-shadow: rgba(0, 0, 0, 0.25) 0px 54px 55px, rgba(0, 0, 0, 0.12) 0px -12px 30px, rgba(0, 0, 0, 0.12) 0px 4px 6px, rgba(0, 0, 0, 0.17) 0px 12px 13px, rgba(0, 0, 0, 0.09) 0px -3px 5px;
}
.v-main {
  padding-top: 0px !important;
  padding-right: 0px !important;
}
.btn-active {
  color: white !important;
}
</style>
