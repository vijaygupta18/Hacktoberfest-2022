const image = document.querySelector('img');
const title = document.getElementById('title');
const artist = document.getElementById('artist');
const music = document.querySelector('audio');
const progressContainer = document.getElementById('progress-container');
const progress = document.getElementById('progress');
const currentTimeElement = document.getElementById('current-time');
const durationElement = document.getElementById('duration');
const prevBtn = document.getElementById('prev');
const nextBtn = document.getElementById('next');
const playBtn = document.getElementById('play');

// Music Folder
const musicFolder = [
    {
        musicSource: 'Disarm',
        displayName: 'Disarm',
        artistName: 'AllttA (20syl & Mr. J. Medeiros​ )'
    },
    {
        musicSource: 'Delta',
        displayName: 'Delta',
        artistName: 'C2C'
    },
    {
        musicSource: 'Under-The-Water',
        displayName: 'Under The Water',
        artistName: 'AllttA (20syl & Mr. J. Medeiros​ )'
    },
]

// Check if Playing
let isPlaying = false;

// Play
function playMusic() {
    isPlaying = true;
    music.play();
    playBtn.classList.replace('fa-play', 'fa-pause');
    playBtn.setAttribute('title', 'Pause');
}

// Pause
function pauseMusic() {
    isPlaying = false;
    music.pause();
    playBtn.classList.replace('fa-pause','fa-play');
    playBtn.setAttribute('title', 'Play');
}

// Event Lister for Play / Pause
playBtn.addEventListener('click',() => (isPlaying ? pauseMusic() : playMusic()));

// Update DOM
function loadSong(song) {
    title.textContent = song.displayName;
    artist.textContent = song.artistName;
    music.src = `music/${song.musicSource}.mp3`;
    image.src = `img/${song.musicSource}.jpg`;
}

// Current Song
let songIndex = 0;

// To Play Next Song
function nextSong() {
    songIndex++;
    if (songIndex > musicFolder.length - 1) {
        songIndex = 0;
    }
    loadSong(musicFolder[songIndex]);
    playMusic();
}

// To Play Prev Song
function prevSong() {
    songIndex--;
    if (songIndex < 0) {
        songIndex = musicFolder.length - 1;
    }
    loadSong(musicFolder[songIndex]);
    playMusic();
}

// Update Progress Bar and Time
function updateProgressDuration(e) {
    const { duration, currentTime } = e.srcElement;
    // Update Progress Bar
    const progressPercent = currentTime/duration *100;
    progress.style.width = `${progressPercent}%`;
    // Update Duration of the Song
    const durationMinutes = Math.floor(duration / 60);
    let durationSeconds = Math.floor(duration % 60);
    if (durationSeconds < 10) {
        durationSeconds = `0${durationSeconds}`;
    }

    // Delay Switching Duration Element to avoid NaN
    if (durationSeconds) {
        durationElement.textContent = `${durationMinutes}:${durationSeconds}`;
    }

    // Update Current Time of the Song
    const currentMinutes = Math.floor(currentTime / 60);
    let currentSeconds = Math.floor(currentTime % 60);
    if (currentSeconds < 10) {
        currentSeconds = `0${currentSeconds}`;
    }
    currentTimeElement.textContent = `${currentMinutes}:${currentSeconds}`;
}

// On Load Select First Song
loadSong(musicFolder[songIndex]);

// Set Progress Bar on Click
function setProgressBar(e) {
    const width = this.clientWidth;
    const clickX = e.offsetX;
    const { duration } = music;
    music.currentTime = (clickX / width) * duration;
} 

// Event Listeners
prevBtn.addEventListener('click', prevSong);
nextBtn.addEventListener('click', nextSong);
music.addEventListener('ended', nextSong);
music.addEventListener('timeupdate', updateProgressDuration);
progressContainer.addEventListener('click', setProgressBar);