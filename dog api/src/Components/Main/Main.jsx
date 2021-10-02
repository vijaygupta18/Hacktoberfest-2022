import axios from "axios";
import React, { useState } from "react";
import "./Main.css";

import ImageContent from "../ImageContent/ImageContent";

const Main = ({ breed }) => {
  //set States
  const [subBreed, setSubBreed] = useState([]);
  const [images, setImages] = useState([]);
  const [selectedBreed, setselectedBreed] = useState("affenpinscher");

  //Runs when Breed Changes
  const handleBreedChange = (e) => {
    const breed_name = e.target.value;
    setselectedBreed(breed_name);

    // get SubBread If Exist
    const getSubBreed = async () => {
      const subBreedList = [];
      const response = await axios
        .get(`https://dog.ceo/api/breed/${breed_name}/list`)
        .then((res) => {
          res.data.message.map((name) => subBreedList.push(name));
        });
      setSubBreed(subBreedList);
    };

    getSubBreed();

    //get Images

    const getImages = async () => {
      const response = await axios
        .get(`https://dog.ceo/api/breed/${breed_name}/images`)
        .then((res) => {
          setImages(res.data.message);
        });
    };

    getImages();
  };

  //Runs when Sub-Breed Changes

  const handleSubBreedChange = (e) => {
    const subBreed_name = e.target.value;
    // get Images by SubBreed

    const getImages = async () => {
      const response = await axios
        .get(
          `https://dog.ceo/api/breed/${selectedBreed}/${subBreed_name}/images`
        )
        .then((res) => {
          console.log(res);
          setImages(res.data.message);
        });
    };

    getImages();
  };

  return (
    <>
      <div className="selection">
        <div className="selection_item">
          <label htmlFor="breed">Select Dog Breed:</label>
          <select name="breed" id="breed" onChange={handleBreedChange}>
            <option value="none">None</option>

            {breed?.map((name) => (
              <option value={`${name}`} key={`${name}`}>
                {name}
              </option>
            ))}
          </select>
        </div>
        {/* renders when sub breed exist */}

        {subBreed.length !== 0 && (
          <div className="selection_item">
            <label htmlFor="subbreed">Select Dog Sub Breed:</label>

            <select
              name="subbreed"
              id="subbreed"
              onChange={handleSubBreedChange}
            >
              {subBreed?.map((name) => (
                <option value={`${name}`} key={`${name}`}>
                  {name}
                </option>
              ))}
            </select>
          </div>
        )}
        {/* renders only when images are fetched */}
        {images.length !== 0 && (
          <div className="image_container">
            {images.map((src) => (
              <ImageContent src={src} key={`${src}`} />
            ))}
          </div>
        )}
      </div>
    </>
  );
};

export default Main;
