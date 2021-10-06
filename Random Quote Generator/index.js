var url="https://gist.githubusercontent.com/camperbot/5a022b72e96c4c9585c32bf6a75f62d9/raw/e3c6895ce42069f0ee7e991229064f167fe8ccdc/quotes.json";

async function getQuote() {
    var q, a;
    const response = await fetch(url);
    var json = await response.json();
    json = json.quotes;
    var r=Math.floor(Math.random()*(Object.keys(json).length));
    console.log(json[r]['quote']);

    document.getElementById('text').innerHTML = json[r]['quote'];
    console.log(document.getElementById('text'));
    document.getElementById('author').innerHTML = json[r]['author'];
}

getQuote();

const newQuote = document.getElementById('new-quote');
newQuote.addEventListener('click',getQuote);

const tweet = document.getElementById('tweet-quote');
tweet.setAttribute('href');
