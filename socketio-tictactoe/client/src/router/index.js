import Vue from 'vue'
import VueRouter from 'vue-router'
import Home from '../views/Home.vue'
import BoardComponent from '../views/Game.vue'
import { io } from "socket.io-client";
const socket = io("http://localhost:3000");

Vue.use(VueRouter)

const routes = [
  {
    path: '/',
    name: 'Home',
    component: Home
  },
  {
    path: '/play',
    name: 'Play',
    component: BoardComponent,
    meta: { requireAuth: true }
  }
]

const router = new VueRouter({
  mode: 'history',
  base: process.env.BASE_URL,
  routes
})

router.beforeEach((to, from, next) => {
  if (to.matched.some(record => record.meta.requireAuth)) {
    if (!localStorage.getItem('player_id')) {
      next({ name: 'Home' })
    } else {
      next()
    }
  } else {
    next()
  }
})

export default router
