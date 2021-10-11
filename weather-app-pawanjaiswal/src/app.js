const chalk = require( "chalk" );
const path = require("path");
const http = require("http");
const hbs = require('hbs');
const express = require("express");
const app = express();
const requests = require("requests");


const port = process.env.PORT || 8000;

// Public Static Path
const staticpath = path.join(__dirname , "../public");
app.use(express.static(staticpath));

// Templates Path
const temppath = path.join(__dirname , "/../templates");
app.set("views" , temppath);

// Set View Engine
app.set("view engine", "hbs");

// Partial Path
const partialpath = path.join(__dirname,'/../templates/partials');
hbs.registerPartials(partialpath);

// Routes
app.get('/' , (req,res)=>{
    // console.log(chalk.white.inverse(" Home "));
    res.render("index");
})

app.get('/about' , (req,res)=>{
    console.log(chalk.white.inverse(" about "));
    res.send("about Page");
})

app.get('/weather' , (req,res)=>{
    // console.log(chalk.white.inverse(" weather "));
    res.render("weather");
})

app.get("*" , (req,res) => {
    res.send("404 not found");
});

app.listen(port,()=>{
    console.log(chalk.white.inverse(` Server is listening at port ${port} `));
})





// Pawankumar Jaiswal