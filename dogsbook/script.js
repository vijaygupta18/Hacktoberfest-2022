// variable queries
var econ = document.getElementById("econtainer");
var ser = document.getElementById("search");
var serbtn = document.getElementById("serbtn");
var dog = document.getElementById("searchtxt");
var form = document.getElementById("form");
//navigation functions

serbtn.addEventListener("click", () => {
  //search navigation function
  if (ser.style.display === "none" && econ.style.display === "block") {
    if (form.childNodes.length > 2) {
      while (form.childNodes.length > 2) {
        form.removeChild(form.lastChild);
      }
    }
    econ.style.display = "none";
    ser.style.display = "block";
  } else {
    if (form.childNodes.length > 2) {
      while (form.childNodes.length > 2) {
        form.removeChild(form.lastChild);
      }
    }
    econ.style.display = "none";
    ser.style.display = "block";
  }
});

function showecon(input) {
  //generalized navigation function
  parent = document.getElementById(input);
  if (ser.style.display === "block" && econ.style.display === "none") {
    econ.style.display = "block";
    ser.style.display = "none";
    parent.scrollIntoView();
  } else {
    parent.scrollIntoView();
  }
}

async function getimg(str, ref) {
  let url = `https://api.thedogapi.com/v1/images/${ref}`;
  let response = await fetch(url);
  let dimg = await response.json();
  str = dimg.url;
  return str;
}

function fillarr(obj, arr) {
  var keys = Object.keys(obj);
  var objectLen = keys.length;
  for (let i = 0; i <= objectLen; i++) {
    arr.push(obj[keys[i]]);
  }
}

async function randdog() {
  var dogyarr = [];
  url = `https://api.thedogapi.com/v1/breeds?limit=3&page=${Math.floor(
    Math.random() * 56
  )}`;
  let response = await fetch(url);
  let drs = await response.json();
  fillarr(drs, dogyarr);

  let d1 = document.getElementById("d1");
  let d2 = document.getElementById("d2");
  let d3 = document.getElementById("d3");
  let dh1 = document.getElementById("dh1");
  let dh2 = document.getElementById("dh2");
  let dh3 = document.getElementById("dh3");
  let ph11 = document.getElementById("ph1.1");
  let ph12 = document.getElementById("ph1.2");
  let ph13 = document.getElementById("ph1.3");
  let ph21 = document.getElementById("ph2.1");
  let ph22 = document.getElementById("ph2.2");
  let ph23 = document.getElementById("ph2.3");
  let ph31 = document.getElementById("ph3.1");
  let ph32 = document.getElementById("ph3.2");
  let ph33 = document.getElementById("ph3.3");

  d1.src = dogyarr[0].image.url;
  d2.src = dogyarr[1].image.url;
  d3.src = dogyarr[2].image.url;

  dh1.textContent = dogyarr[0].name;
  dh2.textContent = dogyarr[1].name;
  dh3.textContent = dogyarr[2].name;

  ph11.textContent = "Breed for : " + dogyarr[0].bred_for;
  ph12.textContent = "Temperament : " + dogyarr[0].temperament;
  ph13.textContent = "Life Span : " + dogyarr[0].life_span;

  ph21.textContent = "Breed for : " + dogyarr[1].bred_for;
  ph22.textContent = "Temperament : " + dogyarr[1].temperament;
  ph23.textContent = "Life Span : " + dogyarr[1].life_span;

  ph31.textContent = "Breed for : " + dogyarr[2].bred_for;
  ph32.textContent = "Temperament : " + dogyarr[2].temperament;
  ph33.textContent = "Life Span : " + dogyarr[2].life_span;
}

async function getBreeds() {
  //getting the breed information
  var myHeaders = new Headers();
  let dogarr = [];
  let str = "";
  myHeaders.append("Content-Type", "application/json");
  myHeaders.append("x-api-key", "83ab2b1b-19ba-4ad0-ac08-6a99e7502a18");
  var formdata = new FormData();
  url = `https://api.thedogapi.com/v1/breeds/search?q=${dog.value}`;
  var requestOptions = {
    method: "GET",
    headers: myHeaders,
    redirect: "follow",
  };
  let response = await fetch(url, requestOptions);
  let dres = await response.json();
  fillarr(dres, dogarr);

  if (form.childNodes.length > 2) {
    //checking if form has more than two childs and removing them before appending
    while (form.childNodes.length > 2) {
      form.removeChild(form.lastChild);
    }
  }

  if (dogarr.length == 1) {
    let noele = document.createElement("p");
    noele.setAttribute(
      "style",
      "font-family: Montserrat;font-size:2rem; color:white;margin-left:13rem;margin-top:5rem;"
    );
    noele.textContent = "Oop!!! No dogs found :(";
    form.append(noele);
  }

  for (let i = 0; i < dres.length; i++) {
    //fetching image url using reference id from dogarr
    var ref = dogarr[i].reference_image_id;
    let url2 = `https://api.thedogapi.com/v1/images/${ref}`;
    let response2 = await fetch(url2);
    let dimg = await response2.json();
    str = dimg.url;

    //Creating Elements which are to be appended
    let dogcont = document.createElement("div");
    dogcont.classList.add("dogcont");
    let img = document.createElement("img");
    img.setAttribute("id", "container__text_img");
    img.src = str;
    let context = document.createElement("div");
    context.classList.add("container__text");
    let hi = document.createElement("h1");
    hi.setAttribute("id", "container__text_h1");
    hi.textContent = dogarr[i].name;
    let pi = document.createElement("p");
    let pi1 = document.createElement("p");
    let pi2 = document.createElement("p");
    let pi3 = document.createElement("p");
    pi.setAttribute("id", "container__text_p");
    pi.textContent = "Breed For : " + dogarr[i].bred_for;
    pi1.setAttribute("id", "container__text_p1");
    pi1.textContent = "Breed Group : " + dogarr[i].breed_group;
    pi2.setAttribute("id", "container__text_p2");
    pi2.textContent = "Temperament : " + dogarr[i].temperament;
    pi3.setAttribute("id", "container__text_p3");
    pi3.textContent = "Life Span : " + dogarr[i].life_span;

    //Appending Created Elements
    form.appendChild(dogcont);
    dogcont.appendChild(img);
    dogcont.appendChild(context);
    context.appendChild(hi);
    context.appendChild(pi);
    context.appendChild(pi1);
    context.appendChild(pi2);
    context.appendChild(pi3);
  }
}
