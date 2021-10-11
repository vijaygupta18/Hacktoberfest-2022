const choice = document.querySelector('.choices');
const result_text = document.querySelector('.result');
const buttons = document.querySelectorAll('button');
const player_score = document.querySelector('.player .scoreboard');
const computer_score = document.querySelector('.computer .scoreboard');
const scores = [0, 0];

for (let i = 0; i < buttons.length; i++) {
  buttons[i].addEventListener('click', playGame);
}

function playGame(e) {
  let playerChoice = e.target.alt;
  let computerChoice = Math.random();

  if (computerChoice < 0.34) {
    computerChoice = 'Rock';
  } else if (computerChoice <= 0.67) {
    computerChoice = 'Paper';
  } else {
    computerChoice = 'Scissors';
  }
  let result = checkWinner(playerChoice, computerChoice);

  if (result === 'Player') {
    scores[0]++;
    result_text.innerHTML = 'Player Won!';
  }

  if (result === 'Computer') {
    scores[1]++;
    result_text.innerHTML = 'Computer Won!';
  }

  if (result === 'Draw') {
    result_text.innerHTML = "It's a tie!";
  }
  player_score.textContent = scores[0];
  computer_score.textContent = scores[1];
  showChoice(
    '<div><strong>Player: </strong>' +
      '<span>' +
      playerChoice +
      '</span>' +
      '</div>' +
      '<div><strong>Computer: </strong>' +
      '<span>' +
      computerChoice +
      '</span>' +
      '</div>'
  );
}

function showChoice(msg) {
  choice.innerHTML = msg;
}

function checkWinner(player, computer) {
  if (player === computer) {
    return 'Draw';
  }

  if (player === 'Rock') {
    if (computer === 'Paper') {
      return 'Computer';
    } else {
      return 'Player';
    }
  }

  if (player === 'Paper') {
    if (computer === 'Scissors') {
      return 'Computer';
    } else {
      return 'Player';
    }
  }

  if (player === 'Scissors') {
    if (computer === 'Rock') {
      return 'Computer';
    } else {
      return 'Player';
    }
  }
}
