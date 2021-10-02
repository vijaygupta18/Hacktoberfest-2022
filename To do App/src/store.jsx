import rootReducer from "./reducer";
import logger from "redux-logger";
import thunk from "redux-thunk";

import { applyMiddleware, createStore } from "redux";

const store = createStore(rootReducer, applyMiddleware(thunk, logger));

export default store;