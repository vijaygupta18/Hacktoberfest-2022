import todoReducer from "./todoReducer";
import { combineReducers } from 'redux';

const rootReducer = combineReducers({
    todo: todoReducer,
});

export default rootReducer;