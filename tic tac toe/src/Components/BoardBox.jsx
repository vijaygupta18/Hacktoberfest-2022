import React from "react";

export const BoardBox = (props) => {
  return (
    <button className={props.className} onClick={props.onClick}>
      {props.value}
    </button>
  );
};
