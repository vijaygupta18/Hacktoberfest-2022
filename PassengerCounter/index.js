// initialize the count as 0
//listen for clicks on the increment button
//change the count-el in the HTML to reflect the new count
// function increment()
// {
//     console.log("The button was clicked")
// }
//camelCase

//string can be '' or ""
// let message = "You have tree new notificaitons"
// console.log(message)
// let msgfolder = message + " hello" + "," + "bye"
// console.log(msgfolder)

let saveEl = document.getElementById("save-el")
let countEl = document.getElementById("count-el") 
console.log(saveEl)
console.log(countEl)

 let count = 0
function increment() { 
    count = count + 1
    countEl.innerText = count  
}
function decrement(){
    count = count -1
    countEl.innerText = count
}

function save(){ 
    let countstr = count + " - " 
    saveEl.innerText += countstr
    console.log(count)
    countEl.innerText = 0
}




 