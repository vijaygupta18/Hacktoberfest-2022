import React from "react";

import { BoardBox } from "./BoardBox";

import * as utils from "../utils/functions";

export class Board extends React.Component {
  constructor(props) {
    super(props);

    // Initialize component state
    this.state = {
      boxes: Array(9).fill(null),
      xIsNext: true,
    };
  }

  // Handle click on boxes on the board.
  handleBoxClick(index) {
    // get current state of boxes
    const boxes = this.state.boxes.slice();

    // Get current state of history

    // Stop the game if board contains winning combination
    if (utils.findWinner(boxes) || boxes[index]) {
      return;
    }

    // Stop the game if all boxes are clicked (filled)
    if (utils.areAllBoxesClicked(boxes) === true) {
      return;
    }

    // Mark the box either as 'x' or 'o'
    boxes[index] = this.state.xIsNext ? "X" : "O";

    // Add move to game history

    // Update component state with new data
    this.setState({
      boxes: boxes,
      xIsNext: !this.state.xIsNext,
    });
  }

  // Handle board restart - set component state to initial state
  handleBoardRestart = () => {
    this.setState({
      boxes: Array(9).fill(null),

      xIsNext: true,
    });
  };
  refreshPage() {
    window.location.reload();
  }
  render() {
    // Get winner (if there is any)
    const winner = utils.findWinner(this.state.boxes);

    // Are all boxes checked?
    const isFilled = utils.areAllBoxesClicked(this.state.boxes);

    // Status message
    let status;

    if (winner) {
      // If winner exists, create status message
      status = `The winner is: ${winner}!`;
    } else if (!winner && isFilled) {
      // If game is drawn, create status message
      status = "Game drawn!";
    } else {
      // If there is no winner and game is not drawn, ask the next player to make a move
      status = `It is ${this.state.xIsNext ? "X" : "O"}'s turn`;
    }

    return (
      <>
        <div
          className="
        bg-gray-900
        h-screen          
        flex
        items-center
        font-sans
        flex-col
        justify-center

      "
        >
          <h1 className="text-5xl my-4 font-bold text-gray-100">Tic Tac Toe</h1>

          {/* Button to start new game */}

          <div
            className="
          w-4/6
          h-3/4
          bg-gray-800
          flex
          items-center
          flex-col
          text-white
        "
          >
            <h2 className="text-xl font-bold m-3">{status}</h2>
            <div
              className="
           lg:w-4/6
           w-full
           lg:h-5/6
           h-4/6
           bg-yellow-600
           grid
           grid-flow-col
           grid-cols-3
           grid-rows-3
           text-white
           "
            >
              <BoardBox
                className="border-grey-400 border-4 bg-gray-900 text-8xl "
                value={this.state.boxes[0]}
                onClick={() => this.handleBoxClick(0)}
              />

              <BoardBox
                className="border-grey-400 border-4 bg-gray-900 text-8xl"
                value={this.state.boxes[1]}
                onClick={() => this.handleBoxClick(1)}
              />

              <BoardBox
                className="border-grey-400 border-4 bg-gray-900 text-8xl"
                value={this.state.boxes[2]}
                onClick={() => this.handleBoxClick(2)}
              />

              <BoardBox
                className="border-grey-400 border-4 bg-gray-900 text-8xl"
                value={this.state.boxes[3]}
                onClick={() => this.handleBoxClick(3)}
              />

              <BoardBox
                className="border-grey-400 border-4 bg-gray-900 text-8xl"
                value={this.state.boxes[4]}
                onClick={() => this.handleBoxClick(4)}
              />

              <BoardBox
                className="border-grey-400 border-4 bg-gray-900 text-8xl"
                value={this.state.boxes[5]}
                onClick={() => this.handleBoxClick(5)}
              />

              <BoardBox
                className="border-grey-400 border-4 bg-gray-900 text-8xl"
                value={this.state.boxes[6]}
                onClick={() => this.handleBoxClick(6)}
              />

              <BoardBox
                className="border-grey-400 border-4 bg-gray-900 text-8xl"
                value={this.state.boxes[7]}
                onClick={() => this.handleBoxClick(7)}
              />

              <BoardBox
                className="border-grey-400 border-4 bg-gray-900 text-8xl"
                value={this.state.boxes[8]}
                onClick={() => this.handleBoxClick(8)}
              />
            </div>
          </div>
          {utils.areAllBoxesClicked && (
            <button
              className="bg-gray-100 font-bold text-lg py-2 px-5 m-2 rounded-full"
              onClick={this.refreshPage}
            >
              {" "}
              <span>Replay</span>{" "}
            </button>
          )}
        </div>
      </>
    );
  }
}

export default Board;
