let fs = require("fs")
var jsonfile = require('jsonfile');

const { getLatLngObj } = require("tle.js/dist/tlejs.cjs");
// Intitializing the readFileLines with the file
const readFileLines = filename =>
   fs.readFileSync(filename)
   .toString('UTF8')
   .split('\r\n');

// Calling the readFiles function with file name
let arr = readFileLines('target.txt');
let final_arr = [];
for (let i = 0; i < arr.length - 2; i=i+3) {
   let ans = arr.slice(i, i+3);
   let latLonObj = getLatLngObj(ans.join('\n'))
   let ele = {
      lat: latLonObj["lat"],
      lng: latLonObj["lng"]
   };
   // let jsonString = JSON.stringify(ele);
      final_arr.push(ele);
};
fs.writeFileSync('target.json', JSON.stringify(final_arr));
