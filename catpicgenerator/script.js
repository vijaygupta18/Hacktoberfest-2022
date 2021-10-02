let generate_btn = document.querySelector(".generate_btn")
let catsImgDiv = document.querySelector(".catsImgDiv")
generate_btn.addEventListener('click', fetchPics)

function fetchPics(){
    fetch('https://api.thecatapi.com/v1/images/search')
    .then(response => response.json())
    .then((data)=>{
catsImgDiv.textContent = ''
        let catsImg = data[0].url
        console.log(catsImg);
        let catImgEl = document.createElement("img")
        catImgEl.setAttribute("src", `${catsImg}`)
        catsImgDiv.appendChild(catImgEl)

    })
    .catch(err=>console.log(err))
}


