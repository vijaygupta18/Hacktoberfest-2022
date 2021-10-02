const daysDom = document.getElementById("c-days");
const hoursDom = document.getElementById("c-hours");
const minsDom = document.getElementById("c-mins");
const secsDom = document.getElementById("c-secs");

const birthday = "9 Nov 2021"
setInterval(() => {
    const birthDate = new Date(birthday);
    const nowDate = new Date();

    const countSec = Math.floor((birthDate - nowDate) / 1000 );

    const days = Math.floor(countSec / 3600 / 24);
    const hours = Math.floor((countSec / 3600) % 24);
    const mins = Math.floor((countSec / 60) % 60);
    const secs = Math.floor(countSec % 60);

    daysDom.innerHTML = days;
    hoursDom.innerHTML = formater(hours);
    minsDom.innerHTML = formater(mins);
    secsDom.innerHTML = formater(secs);
}, 1000);


const formater = (number) => {
    if (number < 10) {
        number = '0' + number
    }
    return number
}
