//imports
import axios from "axios";
import { useEffect, useState } from "react";

//Components
import Navbar from "./Components/Navbar/Navbar";
import Main from "./Components/Main/Main";

function App() {
  // getList of breeds of dogs to add in select option
  const [breed, setBreed] = useState([]);

  // get data on page laod
  useEffect(() => {
    const breedList = [];
    //fetch data function
    const fetchData = async () => {
      const response = await axios
        .get("https://dog.ceo/api/breeds/list/all")
        .then((res) => {
          //get one one breed and convert into string
          for (var name in res.data.message) {
            name.toString();
            breedList.push(name);
          }
        });
      setBreed(breedList);
    };
    fetchData();
  }, []);

  return (
    <>
      <Navbar />
      <Main breed={breed} />
    </>
  );
}

export default App;
