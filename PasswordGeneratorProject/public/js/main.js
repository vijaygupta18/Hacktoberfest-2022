let input = document.getElementById('password');
let button = document.getElementById('btn');
let icon = document.getElementById('icon');
let para = document.getElementById('para');
icon.addEventListener('click', getCopied);
button.addEventListener('click', getPassword);

function getPassword() {
    let chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()<>?{}[]+:_";
    let passwordLength = 8;
    let password = "";
    for (let i = 0; i < passwordLength; i++) {
        let randomIndex = Math.floor(Math.random() * chars.length);
        password = password + chars.substring(randomIndex, randomIndex + 1);
    }
    input.value = password;
}

function getCopied() {
    input.select();
    input.setSelectionRange(0, 99999); /* For mobile devices */

    /* Copy the text inside the text field */
    document.execCommand("copy");

    /* Alert the copied text */
    para.innerText = "Copied The Password : " + input.value;
}





