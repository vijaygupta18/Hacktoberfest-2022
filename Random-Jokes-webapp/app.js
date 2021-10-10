const btnGetJoke = document.querySelector("#btn-get-joke")
const showJoke = document.querySelector("#show-joke")

btnGetJoke.addEventListener('click', getJokeHandler)

function errorHandler(){
    showJoke.innerText = 'Something wrong with the server! please try again later';
}

function getJokeHandler(e){
    fetch('https://icanhazdadjoke.com/slack')
    .then(response => response.json())
    .then(data => {
        var joke = data.attachments[0].text;
        showJoke.innerText = joke;
    })
    .catch(errorHandler)
}