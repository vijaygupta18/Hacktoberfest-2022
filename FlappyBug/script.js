const game = document.getElementById('game');
const block = document.getElementById('block');
const hole = document.getElementById('hole');
const character = document.getElementById('character');
const score = document.getElementById('score');
const record = document.querySelector('.best');
let jumping = 0;
score.innerHTML = 0;
let through = true;

const welcome = window.alert('Flappy Bug\nPress any key/tab any where to jump');

hole.addEventListener('animationiteration', function () {
  let random = -(Math.random() * 300 + 150);
  hole.style.top = random + 'px';
  if (!through) {
    score.innerHTML = 0;
  } else {
    score.innerHTML++;
  }
});

setInterval(function () {
  const best = bestScore();
  if (!best.name) record.innerHTML = `best score:`;
  else record.innerHTML = `best score: ${best.score} (${best.name})`;

  const characterTop = parseInt(
    window.getComputedStyle(character).getPropertyValue('top')
  );
  if (jumping == 0) {
    character.style.top = characterTop + 3 + 'px';
  }
  const blockLeft = parseInt(
    window.getComputedStyle(block).getPropertyValue('left')
  );
  const holeTop = parseInt(
    window.getComputedStyle(hole).getPropertyValue('top')
  );
  let cTop = -(500 - characterTop);
  if (
    characterTop > 480 ||
    (blockLeft < 20 &&
      blockLeft > -50 &&
      (cTop < holeTop || cTop > holeTop + 130))
  ) {
    const best = bestScore();
    if (score.innerHTML > +best.score) {
      const name = prompt(
        'New record, congratulation! Please input your name!'
      );
      updateBest(score.innerHTML, name);
    }
    const c = confirm(
      'Game over. Score: ' +
        score.innerHTML +
        '\nClick OK to play again!\nClick Cancel to quit :('
    );
    if (!c) window.close();
    character.style.top = 100 + 'px';
    block.style.left = 400 + 'px';
    score.innerHTML = 0;
    through = false;
  } else {
    through = true;
  }
}, 12);

function jump() {
  jumping = 1;
  let jumpCount = 0;
  const jumpInterval = setInterval(function () {
    const characterTop = parseInt(
      window.getComputedStyle(character).getPropertyValue('top')
    );
    if (characterTop > 6 && jumpCount < 15) {
      character.style.top = characterTop - 5 + 'px';
    }
    if (jumpCount > 20) {
      clearInterval(jumpInterval);
      jumping = 0;
      jumpCount = 0;
    }
    jumpCount++;
  }, 12);
}

function bestScore() {
  let name;
  let score;

  firebase
    .database()
    .ref('best-score')
    .on('value', successHandler, errorHandler);

  function successHandler(items) {
    name = items.val().name;
    score = items.val().score;
  }

  function errorHandler(err) {
    console.log(err);
  }

  return { name, score };
}

function updateBest(newBest, newName) {
  if (!newName) newName = 'anonymous';
  firebase
    .database()
    .ref('best-score')
    .update({ score: +newBest, name: newName });
}
