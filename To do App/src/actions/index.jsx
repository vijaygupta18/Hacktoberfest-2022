const addItem = (item) => {
    return {
        type: "ADD_ITEM",
        payload: item,
    };
};

const removeItem = (id) => {
    return {
        type: "REMOVE_ITEM",
        payload: id,
    };
};

const loadTodo = () => {
    return (dispatch) => {
        fetch("https://jsonplaceholder.typicode.com/todos")
            .then((res) => res.json())
            .then((todos) => {
                return dispatch({
                    type: "LOAD_TODO",
                    payload: todos,
                });
            });
    };

};

export { loadTodo, addItem, removeItem };