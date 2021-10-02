import Vue from 'vue';
import Vuex from 'vuex';

Vue.use(Vuex);

export default new Vuex.Store({
  state: {
    totalPlayer: 0,
    players: {
      player1: 'Player 1',
      player2: 'Player 2',
    },
  },
  mutations: {
    SET_TOTAL_PLAYER(state, payload) {
      state.totalPlayer = payload;
    },
    SET_PLAYER_NAME(state, payload) {
      state.players = payload;
    },
  },
  actions: {},
  modules: {},
});
