import React from "react";

const About = ({ mode }) => {
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
  console.log(mode);
  return (
    <h5 className={`container text-${btnText}`}>
      This About Us page generator will help you write the words to introduce
      yourself to potential customers. This is vital if you want to build
      friendly relationships with your site’s visitors. This tool will let you
      generate about us pages with ease. It doesn’t do you any good to hide
      behind a cloak of a website because today’s customers are curious, and
      rightly so. This is even more true if you have an online shop. People want
      to know who they are doing business with. While a clever handle on social
      media or an avatar game is fun and cool, not letting people know who you
      are on your own site can cost you real money. This about us page generator
      was designed so you can get a nice quick professional writing of who you
      are and will let you make a great introduction of yourself in a
      professional manner. Use this amazing about generator for website content
      that you can copy and paste on your site. It only takes about 5 minutes to
      complete a page!
    </h5>
  );
};

export default About;
