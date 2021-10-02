const express = require('express');
const app = express();
const PORT = process.env.PORT || 3000;

const http = require('http').createServer(app);
const io = require('socket.io')(http, {
  cors: {
    origin: '*',
  },
});

const cors = require('cors');
app.use(cors());
let totalPlayer = 0;
let player = {
  player1: '',
  player2: '',
};

io.on('connect', (socket) => {
  console.log('connected');

  io.emit('totalPlayerStart', totalPlayer, player);

  socket.on('startGame', (playerName) => {
    totalPlayer++;
    if (totalPlayer == 1) {
      player.player1 = playerName;
    } else if (totalPlayer > 1) {
      player.player2 = playerName;
    }
    io.emit('totalPlayerStart', totalPlayer, player);
  });

  socket.on('exitGame', (name) => {
    totalPlayer = 0;
    console.log(name);
    // for (const p in player) {
    //   if (player[p] == name) {
    //     player[p] = '';
    //   }
    // }
    io.emit('totalPlayer', totalPlayer, player, name);
  });

  socket.on('fill', (id, room) => {
    console.log(room);
    if (!room) socket.broadcast.emit('fillBack', id);
    else socket.to(room).emit('fillBack', id);
  });

  socket.on('replay', () => {
    socket.broadcast.emit('replayBack');
  });

  socket.on('joinRoom', (room) => {
    console.log(room);
    socket.join(room);
  });
});

app.get('/', (req, res) => res.send('OK'));
http.listen(PORT, () => console.log(`listening on port ${PORT}`));
