import AddTodo from './components/AddTodo';
import ListTodo from './components/ListTodo';
import './styles/App.css';


function App() {
    return (
        <div className="App">
            <h1>Todo List</h1>
            <AddTodo />
            <ListTodo />
        </div>
    );
}

export default App;