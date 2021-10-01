import { useState } from "react";
import Navbar from "./Components/Navbar";
import TextArea from "./Components/TextArea";
import Alert from "./Components/Alert";
import About from './Components/About'
import { BrowserRouter as Router, Switch, Route,  } from "react-router-dom";

function App() {
  const [mode, setMode] = useState("light");
  const [alert, setAlert] = useState(null);
  // const [theme, setTheme] = useState("light");

  const showAlert = (message, type) => {
    setAlert({
      message: message,
      type: type,
    });

    setTimeout(() => {
      setAlert(null);
    }, 1000);
  };

  const toggleMode = (mode) => {
    if (mode === "danger") {
      document.body.style.background = "#DC3545";
      setMode(mode);
    } else if (mode === "dark") {
      document.body.style.background = "#212529";

      setMode(mode);
    } else if (mode === "warning") {
      document.body.style.background = "#FFC107";

      setMode(mode);
    } else if (mode === "success") {
      document.body.style.background = "#198754";

      setMode(mode);
    } else if (mode === "primary") {
      document.body.style.background = "#0D6EFD";

      setMode(mode);
    } else if (mode === "light") {
      document.body.style.background = "#F9FAFB";
      setMode(mode);
    }
  };

  return (
    <Router>
      <div>
        <Navbar mode={mode} setMode={setMode} toggleMode={toggleMode} />
        <Alert alert={alert} />
        <Switch>
          <Route path="/" exact>
            <TextArea mode={mode}  showAlert={showAlert} />
          </Route>
          <Route path="/about"  exact>
            <About mode={mode} />
          </Route>
        </Switch>
      </div>
    </Router>
  );
}

export default App;
