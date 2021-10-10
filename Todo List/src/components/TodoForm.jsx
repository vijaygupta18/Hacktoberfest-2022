import React, { useState, useEffect, useRef } from "react";

function TodoForm(props) {
  const [input, setInput] = useState(props.edit ? props.edit.value : "");
  const handleChange = (e) => {
    setInput(e.target.value);
  };

  const inputRef = useRef(null);

  useEffect(() => {
    inputRef.current.focus();
  });

  const handleSubmit = (e) => {
    e.preventDefault();

    props.onSumbit({
      id: Date.now(),
      text: input,
    });

    setInput("");
  };

  return (
    <form className="todo-form" onSubmit={handleSubmit}>
      {props.edit ? (
        <>
          <input
            type="text"
            placeholder="Update Todo"
            name="text"
            value={input}
            className="todo-input edit"
            onChange={handleChange}
            ref={inputRef}
          />
          <button className="todo-button edit" onClick={handleSubmit}>
            Update
          </button>
        </>
      ) : (
        <>
          <input
            type="text"
            placeholder="Add Todo"
            name="text"
            value={input}
            className="todo-input"
            onChange={handleChange}
            ref={inputRef}
          />
          <button className="todo-button" onClick={handleSubmit}>
            Add Todo
          </button>
        </>
      )}
    </form>
  );
}

export default TodoForm;
