import React from "react";

const Navbar = ({ setMode, mode, toggleMode }) => {
  let btnText;
  if (mode === "dark") {
    btnText = "dark";
  } else if (mode === "light") {
    btnText = "light";
  } else if (mode === "danger") {
    btnText = "dark";
  } else if (mode === "warning") {
    btnText = "dark";
  } else if (mode === "primary") {
    btnText = "light";
  } else if (mode === "success") {
    btnText = "light";
  }
  return (
    <nav className={`navbar navbar-expand-lg navbar-${btnText} bg-${mode}`}>
      <div className="container-fluid ">
        <a className="navbar-brand" href="/">
          Text Utils
        </a>
        <button
          className="navbar-toggler"
          type="button"
          data-bs-toggle="collapse"
          data-bs-target="#navbarSupportedContent"
          aria-controls="navbarSupportedContent"
          aria-expanded="false"
          aria-label="Toggle navigation"
        >
          <span className="navbar-toggler-icon"></span>
        </button>
        <div className="collapse navbar-collapse" id="navbarSupportedContent">
          <ul className="navbar-nav me-auto mb-2 mb-lg-0">
            <li className="nav-item">
              <a className="nav-link active" aria-current="page" href="/">
                Home
              </a>
            </li>
            <li className="nav-item">
              <a className="nav-link " href="/about">
                About Us
              </a>
            </li>
          </ul>
          <div className="badg_container">
            <div
              class="badg bg-light text-dark"
              onClick={() => toggleMode("light")}
            ></div>

            <div
              className="badg bg-dark"
              onClick={() => toggleMode("dark")}
            ></div>
            <div
              className="badg bg-danger"
              onClick={() => toggleMode("danger")}
            ></div>
            <div
              className="badg bg-warning text-dark"
              onClick={() => toggleMode("warning")}
            ></div>
            <div
              className="badg bg-success"
              onClick={() => toggleMode("success")}
            ></div>
            <div
              className="badg bg-primary"
              onClick={() => toggleMode("primary")}
            ></div>
          </div>
        </div>
      </div>
    </nav>
  );
};

export default Navbar;
