import React, { useState } from "react";

const TextArea = ({ mode, showAlert }) => {
  const [text, setText] = useState("");
  const [modal, setModal] = useState(false);

  const [findText, setFindText] = useState("");
  const [replaceText, setReplaceText] = useState("");

  let btnText;
  if (mode === "dark") {
    btnText = "light";
  } else if (mode === "light") {
    btnText = "dark";
  } else if (mode === "danger") {
    btnText = "light";
  } else if (mode === "warning") {
    btnText = "light";
  } else if (mode === "primary") {
    btnText = "dark";
  } else if (mode === "success") {
    btnText = "dark";
  }
  const UpperCase = () => {
    setText(text.toUpperCase());
    showAlert("Converted to UpperCase", "success");
  };
  const LowerCase = () => {
    setText(text.toLowerCase());
    showAlert("Converted to LowerCase", "success");
  };
  const ClearText = () => {
    setText("");
    showAlert("Text Area Cleared", "success");
  };
  const CopyText = () => {
    var copyText = document.getElementById("exampleFormControlTextarea1");
    showAlert("Text Copied To ClipBoard", "success");
    copyText.select();

    navigator.clipboard.writeText(copyText.value);
    document.getSelection().removeAllRanges();
  };
  const RemoveExtraSpaces = () => {
    let newText = text.split(/\s+/);
    setText(newText.join(" "));
    showAlert("Extra Spaces Removed", "success");
  };

  const toggleFindAndReplace = () => {
    if (modal === false) {
      setModal(true);
    } else {
      setModal(false);
    }
  };
  const replaceTheText = () => {
    let str = text.replace(findText, replaceText);

    setText(str);
    showAlert("Replaced", "success");
    setModal(false);
  };
  return (
    <div className={`container my-4 text-${btnText}`}>
      <div className="mb-3">
        <h3 className="mb-3">Enter your text</h3>
        <textarea
          className={`form-control text-${btnText} bg-${mode}`}
          id="exampleFormControlTextarea1"
          rows="8"
          placeholder="Enter the text"
          value={text}
          onChange={(e) => setText(e.target.value)}
        ></textarea>
        <div className="my-4 ">
          <button
            className={`btn btn-sm btn-${btnText} mr-2 my-1`}
            onClick={UpperCase}
            disabled={text.length === 0}
          >
            Convert to UpperCase
          </button>
          <button
            className={`btn btn-sm btn-${btnText} mx-2 my-1`}
            onClick={LowerCase}
            disabled={text.length === 0}
          >
            Convert to LowerCase
          </button>
          <button
            className={`btn btn-sm btn-${btnText} mx-2`}
            onClick={ClearText}
            disabled={text.length === 0}
          >
            Clear Text
          </button>
          <button
            className={`btn btn-sm btn-${btnText} mx-2 my-1`}
            onClick={CopyText}
            disabled={text.length === 0}
          >
            Copy Text
          </button>
          <button
            className={`btn btn-sm btn-${btnText} mx-2 my-1`}
            onClick={RemoveExtraSpaces}
            disabled={text.length === 0}
          >
            Remove Extra Spaces
          </button>
          <div className="d-grid gap-2 ">
            <button
              className={`btn  btn-${btnText}  my-1 `}
              type="button"
              onClick={toggleFindAndReplace}
              disabled={text.length === 0}
            >
              Find and Replace
            </button>
            {modal && (
              <div>
                <h4>Find</h4>
                <input
                  type="text"
                  className="form-control mb-3"
                  value={findText}
                  onChange={(e) => setFindText(e.target.value)}
                />
                <h4>Replace</h4>
                <input
                  type="text"
                  className="form-control mb-2"
                  value={replaceText}
                  onChange={(e) => setReplaceText(e.target.value)}
                />
                <button
                  className={`btn  btn-${
                    mode === "light" ? "dark" : "light"
                  }  my-1 `}
                  onClick={replaceTheText}
                >
                  Replace
                </button>
              </div>
            )}
          </div>
        </div>

        <div className="text-break">
          <span>
            <strong>{text.length}</strong> characters
          </span>
          <span> • </span>
          <span>
            <strong>
              {
                text.split(/\s+/).filter((element) => {
                  return element.length !== 0;
                }).length
              }
            </strong>{" "}
            words
          </span>
          <span> • </span>
          <span>
            <strong> {~~(text.split(" ").length * 0.008)}</strong> Minutes read
          </span>

          <h3>Preview</h3>
          <p>{text.length > 0 ? text : "Nothing to preview"}</p>
        </div>
      </div>
    </div>
  );
};

export default TextArea;
