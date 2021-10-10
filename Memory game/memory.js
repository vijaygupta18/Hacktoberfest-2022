document.addEventListener('DOMContentLoaded', () => {
  //card options
  alert("PLEASE MAXMIZE ZOOM OUT FOR PERFRCT ALIGNMENT");
  const cardArray = [
    {
      name: "bear",
      img: "Images/bear.png",
    },
    {
      name: "flamingo",
      img: "Images/flamingo.png",
    },
    {
      name: "giraffe",
      img: "Images/giraffe.png",
    },
    {
      name: "panda-bear",
      img: "Images/panda-bear.png",
    },
    {
      name: "raccoon",
      img: "Images/raccoon.png",
    },
    {
      name: "rhinoceros",
      img: "Images/rhinoceros.png",
    },
    {
      name: "bear",
      img: "Images/bear.png",
    },
    {
      name: "flamingo",
      img: "Images/flamingo.png",
    },
    {
      name: "giraffe",
      img: "Images/giraffe.png",
    },
    {
      name: "panda-bear",
      img: "Images/panda-bear.png",
    },
    {
      name: "raccoon",
      img: "Images/raccoon.png",
    },
    {
      name: "rhinoceros",
      img: "Images/rhinoceros.png",
    }
  ]
  cardArray.sort(() => 0.5 - Math.random())

  const grid = document.querySelector('.grid')
  let cardsChosen = []
  let cardsChosenId = []
  var cardsWon = []

  //create your board
  function createBoard() {
    for (let i = 0; i < cardArray.length; i++) {
      const card = document.createElement('img')
      card.setAttribute('src', 'images/hide.png')
      card.setAttribute('data-id', i)
      card.addEventListener('click', flipCard)
      grid.appendChild(card)
    }
  }

  //check for matches
  function checkForMatch() {
    const cards = document.querySelectorAll('img')
    const optionOneId = cardsChosenId[0]
    const optionTwoId = cardsChosenId[1]
    
    if(optionOneId == optionTwoId) {
      cards[optionOneId].setAttribute('src', 'images/hide.png')
      cards[optionTwoId].setAttribute('src', 'images/hide.png')
    }
    else if (cardsChosen[0] === cardsChosen[1]) {
      cards[optionOneId].setAttribute('src', 'images/checked.png')
      cards[optionTwoId].setAttribute('src', 'images/checked.png')
      cards[optionOneId].removeEventListener('click', flipCard)
      cards[optionTwoId].removeEventListener('click', flipCard)
      cardsWon.push(cardsChosen)
    } else {
      cards[optionOneId].setAttribute('src', 'images/hide.png')
      cards[optionTwoId].setAttribute('src', 'images/hide.png')
    }
    cardsChosen = []
    cardsChosenId = []
    if  (cardsWon.length == (cardArray.length)/2) {
      alert('Congratulations! You found them all!')
    }
  }

  //flip your card
  function flipCard() {
    let cardId = this.getAttribute('data-id')
    cardsChosen.push(cardArray[cardId].name)
    cardsChosenId.push(cardId)
    this.setAttribute('src', cardArray[cardId].img)
    if (cardsChosen.length === 2) {
      setTimeout(checkForMatch, 500)
    }
  }
  createBoard()
})
