import React from 'react'
import { useDispatch, useSelector } from 'react-redux';
import { removeItem } from '../actions';

const ListTodo = () => {
    const todos = useSelector((state) => state.todo);
    const dispatch = useDispatch()
    return (
        <div>
            {todos.map((todo, index) => (
                <div key={index}>
                    <h2 style={{ display: "inline-block" }}> {todo.title}</h2>
                    <button onClick={() => {
                        dispatch(removeItem(index));
                    }}>Delete</button>
                </div>
            ))}
        </div>
    )
}

export default ListTodo;
