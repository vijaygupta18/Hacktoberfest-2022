import React from "react";
import ReactDOM from "react-dom";

import Board from "./Components/Board";

import "./index.css";
class App extends React.Component {
  render() {
    return (
      <div className="app">
        <Board />
      </div>
    );
  }
}

// Render the App component into DOM
ReactDOM.render(<App />, document.getElementById("root"));
