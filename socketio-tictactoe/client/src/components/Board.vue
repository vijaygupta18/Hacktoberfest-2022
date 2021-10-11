<template>
  <div class="play-ground">
    <!-- <div class="players">
      <table>
        <tbody>
          <tr>
            <td>
              <div :class="{ activePlayer: activePlayer == 'x' }">
                <i class="fas fa-times"></i>
                <span style="float: right;">-</span>
              </div>
            </td>
            <td>
              <div :class="{ activePlayer: activePlayer == 'o' }">
                <i class="far fa-circle"></i>
                <span style="float: right;">-</span>
              </div>
            </td>
          </tr>
        </tbody>
      </table>
    </div> -->

    <div class="mt-2 text-center text-2xl font-light tracking-wider uppercase text-gray-100 antialiased">
      <div v-if="totalPlayer > 1">
        It is <span class="mt-2 text-center text-2xl font-bold text-yellow-500 uppercase">{{ playerName }}</span> turn!
      </div>
      <div v-else>
        Waiting for other player
      </div>
    </div>

    <!-- <p style="text-align: center;font-size: 20px;margin: 10px 0px;">
      It is <span style="text-transform: uppercase;color: #14bdac;font-weight: bold;">{{ activePlayer }}</span> turn!
    </p> -->
    <div class="play">
      <div class="result-overlay" id="result-overlay">
        <p id="p-overlay">
          <span class="winner">
            <i class="fas fa-times" v-if="winner == 'x'"></i>
            <i class="far fa-circle" v-if="winner == 'o'"></i>
          </span>
          WON!
        </p>
      </div>
      <!-- <table>
        <tbody>
          <tr>
            <td style="border-top: 0px;border-left: 0px;" @click="fillInCell(0)" id="cell_0"></td>
            <td style="border-top: 0px;" @click="fillInCell(1)" id="cell_1"></td>
            <td style="border-top: 0px;border-right: 0px;" @click="fillInCell(2)" id="cell_2"></td>
          </tr>
          <tr>
            <td style="border-left: 0px;" @click="fillInCell(3)" id="cell_3"></td>
            <td @click="fillInCell(4)" id="cell_4"></td>
            <td style="border-right: 0px;" @click="fillInCell(5)" id="cell_5"></td>
          </tr>
          <tr>
            <td style="border-bottom: 0px;border-left: 0px;" @click="fillInCell(6)" id="cell_6"></td>
            <td style="border-bottom: 0px;" @click="fillInCell(7)" id="cell_7"></td>
            <td style="border-bottom: 0px;border-right: 0px;" @click="fillInCell(8)" id="cell_8"></td>
          </tr>
        </tbody>
      </table> -->

      <!-- <div class="board-game"> -->

      <div class="board" :class="activePlayer" id="board">
        <div class="cell" data-cell @click="fillInCell(0)" id="cell_0"></div>
        <div class="cell" data-cell @click="fillInCell(1)" id="cell_1"></div>
        <div class="cell" data-cell @click="fillInCell(2)" id="cell_2"></div>
        <div class="cell" data-cell @click="fillInCell(3)" id="cell_3"></div>
        <div class="cell" data-cell @click="fillInCell(4)" id="cell_4"></div>
        <div class="cell" data-cell @click="fillInCell(5)" id="cell_5"></div>
        <div class="cell" data-cell @click="fillInCell(6)" id="cell_6"></div>
        <div class="cell" data-cell @click="fillInCell(7)" id="cell_7"></div>
        <div class="cell" data-cell @click="fillInCell(8)" id="cell_8"></div>
      </div>

      <!-- <div class="winning-message" id="winningMessage">
        <div data-winning-message-text>O Menang!</div>
        <button id="restartButton">Main lagi</button>
      </div> -->
      <!-- </div> -->
    </div>
    <!-- <div style="text-align: center;">
      <span
        class="mt-2
        text-center
        text-2xl
        font-extrabold
        tracking-wider
        uppercase
        text-yellow-500
        antialiased
        cursor-pointer"
        @click.prevent="replay()"
        >REPLAY</span
      >
    </div>
    <div style="text-align: center;">
      <span
        class="mt-2
        text-center
        text-2xl
        font-extrabold
        tracking-wider
        uppercase
        text-yellow-500
        antialiased
        cursor-pointer"
        @click.prevent="exit()"
        >EXIT</span
      >
    </div> -->

    <div style="text-align: center;" class="mt-3 mb-3">
      <div class="inline-flex rounded-md shadow">
        <a
          href="#"
          @click.prevent="replay()"
          class="inline-flex items-center transition duration-150 justify-center px-5 py-2 text-xl font-mono tracking-wider rounded-md text-white bg-indigo-600 hover:bg-indigo-700"
        >
          REPLAY
        </a>
      </div>

      <div class="ml-4 inline-flex rounded-md shadow">
        <a
          href="#"
          @click.prevent="exit()"
          class="inline-flex items-center transition duration-150 justify-center px-5 py-2 text-xl font-mono tracking-wider rounded-md text-white bg-yellow-500 hover:bg-yellow-400"
        >
          EXIT
        </a>
      </div>
    </div>
  </div>
</template>

<script>
import { io } from 'socket.io-client';
const socket = io('http://localhost:3000');
export default {
  name: 'Game',
  data() {
    return {
      activePlayer: 'x',
      player: '',
      // playerName: players.player1,
      cells: [null, null, null, null, null, null, null, null, null],
      countClicks: 0,
      winningConditions: [
        [0, 1, 2],
        [3, 4, 5],
        [6, 7, 8],
        [0, 3, 6],
        [1, 4, 7],
        [2, 5, 8],
        [0, 4, 8],
        [2, 4, 6],
      ],
      winner: null,
    };
  },
  computed: {
    totalPlayer: {
      get() {
        return this.$store.state.totalPlayer;
      },
      set(value) {
        this.$store.commit('SET_TOTAL_PLAYER', value);
      },
    },
    players: {
      get() {
        return this.$store.state.players;
      },
      set(value) {
        this.$store.commit('SET_PLAYER_NAME', value);
      },
    },
    playerName: {
      get() {
        let name = this.players.player1;
        if (this.activePlayer == 'x') {
          name = this.players.player1;
        } else {
          name = this.players.player2;
        }
        return name;
      },
    },
    room: {
      get() {
        return this.$store.state.room;
      },
      set(value) {
        this.$store.commit('SET_ROOM', value);
      },
    },
  },
  watch: {
    totalPlayer(value) {
      if (value == 0) {
        this.$router.push('/');
      }
    },
  },
  methods: {
    fillInCell(id) {
      let cellName = 'cell_' + id;
      let cell = document.getElementById(cellName);
      if (this.cells[id] == null) {
        this.countClicks += 1;
        if (this.activePlayer == 'x') cell.classList.add('x');
        else cell.classList.add('o');

        this.cells[id] = this.activePlayer;
        this.activePlayer = this.activePlayer == 'x' ? 'o' : 'x';

        // if (this.activePlayer == 'x') {
        //   this.playerName = this.players.player1
        // } else {
        //   this.playerName = this.players.player2
        // }

        if (this.countClicks >= 5) this.checkGame();

        socket.emit('fill', id, this.room);
      }
    },
    exit() {
      const name = this.player;
      // this.totalPlayer -= 1;
      socket.emit('exitGame', name);
      this.$router.push('/');
    },
    checkGame() {
      for (let i = 0; i <= 7; i++) {
        let winningCondition = this.winningConditions[i];
        let a = this.cells[winningCondition[0]];
        let b = this.cells[winningCondition[1]];
        let c = this.cells[winningCondition[2]];

        if (a == null || b == null || c == null) continue;
        if (a == b && b == c) {
          this.winner = a;
          break;
        }
      }
      if (this.winner) {
        let el = document.getElementById('result-overlay');
        el.style.display = 'block';
      } else {
        if (this.countClicks == 9) {
          let el = document.getElementById('result-overlay');
          let p = document.getElementById('p-overlay');
          p.innerHTML = 'DRAW';
          el.style.display = 'block';
        }
      }

      return;
    },
    replay() {
      socket.emit('replay');
      location.reload();
    },
  },
  created() {
    this.player = localStorage.player_name;
  },
  mounted() {
    socket.on('fillBack', (id) => {
      console.log(id);
      this.fillInCell(id);
    });

    socket.on('replayBack', () => {
      this.replay();
    });

    socket.on('totalPlayer', (totalPlayer, player, name) => {
      this.totalPlayer = totalPlayer;
      // console.log(this.player, name);
      // if (this.player == name) {
      //   this.$router.push('/');
      // }
      // this.players = player;
    });
  },
};
</script>

<style>
.activePlayer {
  border-bottom: 3px solid rgba(224, 231, 255) !important;
  box-shadow: 0 4px 5px rgba(187, 178, 178, 0.16) !important;
}
.players div {
  width: 200px;
  border-bottom: 3px solid transparent;
  color: rgba(79, 70, 229);
  font-size: 24px;
  margin: 0;
  transition: all 0.25s;
  -webkit-transition: all 0.25s;
  background-color: rgba(199, 210, 254);
  border-radius: 8px;
  box-shadow: 0 1px 1px rgba(189, 189, 189);
  line-height: 16px;
  text-transform: uppercase;
  padding: 10px 8px;
  overflow: hidden;
}
.players div i {
  font-size: 20px;
  font-weight: 100;
}
.players table {
  margin: auto;
}
/* .play tr td {
  height: 110px;
  padding: 8px;
  position: relative;
  width: 125px;
  text-align: center;
  vertical-align: middle;
}
.play tr td i {
  width: 50px;
  height: 50px;
  font-size: 50px;
  font-weight: 100;
} */
.play {
  background-color: rgba(17, 24, 39);
  padding: 20px 0px;
  position: relative;
}
/* .play td {
  border: 5px solid #0da192;
} */
.play .board {
  width: 370px;
  height: 300px;
  margin: auto;
}
.play-ground {
  margin: 50px 0px;
  left: 0;
  right: 0;
  padding: 20px 0px;
  border: 1px solid #dfe1e5;
  border-radius: 8px;
}
.result-overlay {
  position: absolute;
  background: rgba(79, 70, 229, 0.9);
  width: 100%;
  height: 100%;
  top: 0;
  z-index: 10;
  display: none;
}
.result-overlay > p {
  font-size: 50px;
  font-weight: 100;
  text-align: center;
  color: rgba(245, 158, 11);
  vertical-align: middle;
  height: 100%;
  justify-content: center;
  align-items: center;
  display: flex;
  font-weight: bold;
}
.result-overlay > p > span {
  color: #d3f2dd;
  font-size: 100px;
  margin-right: 20px;
}
.result-overlay > p > span > i {
  font-weight: 100;
}

/* style dari mba karen */
*,
*::after,
*::before {
  box-sizing: border-box;
}

/* Buat template formula ukuran di styling bawah */
:root {
  --cell-size: 100px;
  --mark-size: calc(var(--cell-size) * 0.9);
}

/* .board-game {
  margin: 0;
} */

/* START - Styling main boardnya */
.board {
  width: 100vw;
  height: 100vh;
  display: grid;
  justify-content: center;
  align-content: center;
  justify-items: center;
  align-items: center;
  grid-template-columns: repeat(3, auto);
}

.cell {
  width: var(--cell-size);
  height: var(--cell-size);
  border: 2px solid rgba(17, 24, 39);
  background-color: rgba(31, 41, 55);
  border-radius: 0.3rem;
  display: flex;
  justify-content: center;
  align-items: center;
  position: relative;
  cursor: pointer;
}
/* END - Styling main boardnya */

/* START - Ngilangin garis border kanan kiri atas bawah */
.cell:first-child,
.cell:nth-child(2),
.cell:nth-child(3) {
  border-top: none;
}

.cell:nth-child(3n + 1) {
  border-left: none;
}

.cell:nth-child(3n + 3) {
  border-right: none;
}

.cell:last-child,
.cell:nth-child(8),
.cell:nth-child(7) {
  border-bottom: none;
}
/* END - Ngilangin garis border kanan kiri atas bawah */

/* Buat mastiin gak bisa klik kotak yg udah ada isi X atau O */
.cell.x,
.cell.o {
  cursor: not-allowed;
}

.cell.x::before,
.cell.x::after {
  background-color: rgba(245, 158, 11);
}

.cell.o::before {
  background-color: rgba(79, 70, 229);
}

/* Buat efek hover di kotak yg masih kosong dan bisa diklik */
.board.x .cell:not(.x):not(.o):hover::before,
.board.x .cell:not(.x):not(.o):hover::after,
.board.o .cell:not(.x):not(.o):hover::before {
  background-color: rgba(165, 180, 252);
}

.cell.x::before,
.cell.x::after,
.board.x .cell:not(.x):not(.o):hover::before,
.board.x .cell:not(.x):not(.o):hover::after {
  content: '';
  position: absolute;
  width: calc(var(--mark-size) * 0.15);
  height: var(--mark-size);
}

/* START - styling garis untuk membentuk X */
.cell.x::before,
.board.x .cell:not(.x):not(.o):hover::before {
  transform: rotate(45deg);
}

.cell.x::after,
.board.x .cell:not(.x):not(.o):hover::after {
  transform: rotate(-45deg);
}
/* END - styling garis untuk membentuk X */

.cell.o::before,
.cell.o::after,
.board.o .cell:not(.x):not(.o):hover::before,
.board.o .cell:not(.x):not(.o):hover::after {
  content: '';
  position: absolute;
  border-radius: 50%;
}

.cell.o::before,
.board.o .cell:not(.x):not(.o):hover::before {
  width: var(--mark-size);
  height: var(--mark-size);
}

.cell.o::after,
.board.o .cell:not(.x):not(.o):hover::after {
  width: calc(var(--mark-size) * 0.7);
  height: calc(var(--mark-size) * 0.7);
  background-color: rgba(31, 41, 55);
}

/* Pesan yg muncul pas menang (harus pakai class .show di bawah) */
/* .winning-message {
  display: none;
  position: fixed;
  top: 0;
  left: 0;
  right: 0;
  bottom: 0;
  background-color: rgba(0, 0, 0, 0.8);
  justify-content: center;
  align-items: center;
  color: white;
  font-size: 5rem;
  flex-direction: column;
} */

/* Efek non-hover button RESTART GAME */
/* .winning-message button {
  font-size: 3rem;
  color: black;
  background-color: white;
  border: 1px solid black;
  padding: 0.25em 0.5em;
  cursor: pointer;
} */

/* Efek hover button RESTART GAME */
/* .winning-message button:hover {
  background-color: black;
  color: white;
  border-color: white;
} */

/* Class .show dipasang pas udah ada yg menang */
/* .winning-message.show {
  display: flex;
} */
</style>
